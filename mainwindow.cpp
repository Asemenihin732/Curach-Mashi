#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "ventil.h"

#include "tablemodel.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>
#include <QPixmap>
#include <QInputDialog>
#include <iostream>
#include <stdio.h>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include <QContextMenuEvent>
#define ROW_COUNT 3
#define COLUMN_COUNT 7
#define COLUMN_MANUFACTURER 0
#define COLUMN_MODEL 1



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tableModel(new TableModel(this))
    , rowCount(ROW_COUNT)
    ,columnCount(COLUMN_COUNT)


{
    sw=new Dialog1(this);
    rowCount = tableModel->list.count();
    ui->setupUi(this);
    ui->tableView->setModel(tableModel);
    ui->tableView->setSelectionBehavior(ui->tableView->SelectRows);
    m_menu=ui->menuchange;
    ui->tableView->hideColumn(0);
    readSettings();
    connect(ui->actionNew, &QAction::triggered,this, &MainWindow::newFile);
    ui->tableView->show();
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setDragEnabled(true);
    ui->tableView->setAcceptDrops(true);
    ui->tableView->setDropIndicatorShown(true);
    if(ui->tableView->model()->rowCount()==0)
    {
        ui->actiondelete->setEnabled(false);
        ui->actiondelete_last->setEnabled(false);
        ui->actionchange_2->setEnabled(false);
    }
    ui->spinBox->setMaximum(999999999);
    ui->spinBox_2->setMaximum(999999999);
    ui->tableView->setDragDropMode(QAbstractItemView::InternalMove);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::filter);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::filter);
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::filter);
    connect(ui->spinBox_2, &QSpinBox::valueChanged, this, &MainWindow::filter);
    connect(ui->lineEdit_3, &QLineEdit::textChanged, this, &MainWindow::filter);
    connect(ui->checkBox, &QCheckBox::clicked, this, &MainWindow::sorting);
    connect(ui->checkBox_2, &QCheckBox::clicked, this, &MainWindow::filter);
    connect(ui->checkBox, &QCheckBox::clicked, this, &MainWindow::filter);
    connect(ui->checkBox_2, &QCheckBox::clicked, this, &MainWindow::sorting);
/*
    QFile fl("country.txt");
     fl.open(QIODevice::ReadOnly);
      QTextStream in(&fl);
       while(!in.atEnd())
       {
           ui->comboBox->addItem(in.readLine());
       }
        fl.close();
        */
}

MainWindow::~MainWindow()
{
    delete tableModel;
    writeSettings();
    delete ui;
}

void MainWindow::filter()
{
    if(ui->checkBox_2->isChecked())
    {
        ui->checkBox->setEnabled(false);
        /*
//        ui->lineEdit->setEnabled(true);
//        ui->lineEdit_3->setEnabled(true);
//        ui->comboBox->setEnabled(true);
//        ui->spinBox->setEnabled(true);
//        ui->spinBox_2->setEnabled(true);
*/
        ui->spinBox_2->setMinimum(ui->spinBox->value());
        QString filterPost = ui->lineEdit->text();
        QString filterCountry = ui->comboBox->currentText();
        QString filterKind = ui->lineEdit_3->text();
        int filterMin=ui->spinBox->value();
        int filterMax=ui->spinBox_2->value();
        int count=ui->tableView->model()->rowCount();
        for (int i=0; i<count; i++) {
            QAbstractItemModel *M = ui->tableView->model();
            QString Post = M->data(M->index( i, 1, QModelIndex())).toString();
            QString Country = M->data(M->index( i, 2, QModelIndex())).toString();
            QString Kind = M->data(M->index( i, 4, QModelIndex())).toString();
            int cost = M->data(M->index( i, 6, QModelIndex())).toInt();

            bool flag = true;

            if(filterPost==""	|| Post.contains(filterPost)) flag&=true; else flag&=false;
            if(filterCountry==""	|| Country.contains(filterCountry)) flag&=true; else flag&=false;
            if(filterKind==""	|| Kind.contains(filterKind)) flag&=true; else flag&=false;
            if(filterMin==0	|| filterMin<=cost) flag&=true; else flag&=false;
            if(filterMax==0	|| filterMax>=cost) flag&=true; else flag&=false;

            if(flag)
                ui->tableView->showRow(i);
            else
                ui->tableView->hideRow(i);
        }
    }
    else
    {
        ui->checkBox->setEnabled(true);
        /*
//        ui->lineEdit->setEnabled(false);
//        ui->lineEdit_3->setEnabled(false);
//        ui->comboBox->setEnabled(false);
//        ui->spinBox->setEnabled(false);
//        ui->spinBox_2->setEnabled(false);
//        ui->lineEdit->clear();
//        ui->lineEdit_3->clear();
//        ui->comboBox->clear();
//        ui->spinBox->setValue(0);
//        ui->spinBox_2->setValue(0);
*/
        ui->spinBox_2->setMinimum(ui->spinBox->value());
        for(int i=0;i<ui->tableView->model()->rowCount();i++)
            ui->tableView->showRow(i);
    }
}

void MainWindow::newFile()
{
    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
}

void MainWindow::sorting()
{
    if(ui->checkBox->isChecked())
    {
        ui->checkBox_2->setEnabled(false);
        proxy.setSourceModel(tableModel);
        ui->tableView->setModel(&proxy);
        ui->tableView->setSortingEnabled(true);
        ui->tableView->sortByColumn(0, Qt::AscendingOrder);
        ui->tableView->horizontalHeader()->setSectionsClickable(1);
        ui->tableView->setCurrentIndex(ui->tableView->model()->index(0, 0));
        proxy.filterCaseSensitivity();
        proxy.isRecursiveFilteringEnabled();
        on_tableView_clicked(ui->tableView->model()->index(0, 0));
        ui->actiondelete->setEnabled(false);
        ui->actiondelete_last->setEnabled(false);
        ui->actionclear_table->setEnabled(false);
        ui->actionadd->setEnabled(false);
        ui->actionchange_2->setEnabled(false);
    }
    else
    {
        ui->checkBox_2->setEnabled(true);
        ui->tableView->setModel(tableModel);
        ui->tableView->show();
        ui->actiondelete->setEnabled(true);
        ui->actiondelete_last->setEnabled(true);
        ui->actionclear_table->setEnabled(true);
        ui->actionadd->setEnabled(true);
        ui->tableView->setSortingEnabled(false);
        ui->actionchange_2->setEnabled(true);
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString filePathAndName = QFileDialog::getSaveFileName(this);
       if (!filePathAndName.isEmpty())
           saveFile(filePathAndName);
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this);
    if (!file.isEmpty())
    loadFile(file);      
}

void MainWindow::changeEvent(QEvent *e)
{
    if(e->type()==QEvent::LanguageChange)
            ui->retranslateUi(this);
}

void MainWindow::on_actionChange_Language_triggered()
{
    bool ok;
    QStringList list;
    list<<"ru"<<"en"<<"ch";
    lang=QInputDialog::getItem(this, tr("Language"),tr("Set Language"), list,1,false,&ok);
    if(!ok||lang.isEmpty())
        QMessageBox::warning(this,tr("Warning"), tr("Language is not set"));
    else
    {
    QMessageBox::about(this,tr("Language"),tr("Set ")+lang+tr(" language"));
    if(lang!="en"){
    qtLanguageTranslator.load("QtLanguage_" + lang, ".");
    qApp->installTranslator(&qtLanguageTranslator);
    }
    else
    {
        qtLanguageTranslator.load("QtLanguage_en.");
        qApp->installTranslator(&qtLanguageTranslator);
    }
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QString nam,res;
    nam=tr("About");
    res=tr("ITCMS-2-8 Suya Maria Nikolaevna");
    QMessageBox::about(this,nam,res);
}

void MainWindow::readSettings()
{
    QSettings settings("MySoft", "MyProgram");
        settings.beginGroup("MainWindowGeometry");
        resize(settings.value("size", QSize(400, 400)).toSize());
        move(settings.value("position", QPoint(200, 200)).toPoint());
        settings.endGroup();
        settings.beginGroup("MainWindowLanguage");
        lang=settings.value("lang").toString();
        qtLanguageTranslator.load("QtLanguage_" + lang, ".");
        qApp->installTranslator(&qtLanguageTranslator);
        settings.endGroup();
}

void MainWindow::writeSettings()
{
    QSettings settings("MySoft", "MyProgram");
       settings.beginGroup("MainWindowGeometry");
       settings.setValue("size", size());
       settings.setValue("position", pos());
       settings.endGroup();
       settings.beginGroup("MainWindowLanguage");
       settings.setValue("lang",lang);
       settings.endGroup();
}

void MainWindow::loadFile(const QString &filePathAndName)
{
    int i=0;
    int b=0;
    int e=0;
    QFile file(filePathAndName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,
                             tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(filePathAndName)
                             .arg(file.errorString()));
        return;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    int c=ui->tableView->model()->rowCount();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QString Temp;
        QStringList local;
        if(i!=0)
        {
            QString filelock;
            filelock=line.mid(b,line.size());
            int j=0;
            Ventil vent;
            while(filelock.indexOf(";")!=-1)
            {
                e=filelock.indexOf(";");
                Temp=filelock.mid(b,e);
                switch(j)
                {
                case 0: vent.set_id(Temp.toInt()+1); break;
                    //                       case 0: vent.set_id(c); break;
                case 1: vent.set_Post(Temp);break;
                case 2: vent.set_tel(Temp);break;
                case 3: vent.set_country(Temp);break;
                case 4: vent.set_articul(Temp);break;
                case 5: vent.set_vid(Temp);break;
                case 6: vent.set_cost(Temp.toInt());break;
                }
                filelock.remove(b,e+1);
                j++;
            }
            qDebug()<<vent.get_id()<<vent.get_Post()<<vent.get_tel()<<vent.get_country()<<vent.get_articul()<<vent.get_vid()<<vent.get_cost();
            tableModel->insertValue(vent);

        }
        i++;
        c++;
    }
    file.close();
    QApplication::restoreOverrideCursor();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    if(ui->tableView->model()->rowCount()!=0){
        ui->actiondelete->setEnabled(true);
        ui->actiondelete_last->setEnabled(true);
        ui->actionchange_2->setEnabled(true);
    }
}

void MainWindow::saveFile(const QString &filePathAndName)
{
        Ventil vent;
       QFile file(filePathAndName);
       if (!file.open(QFile::WriteOnly | QFile::Text)) {
           QMessageBox::warning(this,
                                tr("Application"),
                                tr("Cannot write file %1:\n%2.")
                                .arg(filePathAndName).arg(file.errorString()));
           return;
       }
       QTextStream out(&file);
       QApplication::setOverrideCursor(Qt::WaitCursor);
        int count=ui->tableView->model()->rowCount();
        out<<"\n";
        for(int i=0;i<count;i++)
        {
            out<<QString::number(i);
            out<<";";
            out<<tableModel->list.at(i)->get_Post()+";";
            out<<tableModel->list.at(i)->get_tel()+";";
            out<<tableModel->list.at(i)->get_country()+";";
            out<<tableModel->list.at(i)->get_articul()+";";
            out<<tableModel->list.at(i)->get_vid()+";";
            out<<QString::number(tableModel->list.at(i)->get_cost());
            out<<";";
            out<<"\n";
        }
        QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionadd_triggered()
{
    sw->tek=-1;
    sw->rows = tableModel->list.count()+1;
    sw->open_form();
    sw->exec();
    if(sw->cur==1)
        tableModel->insertValue(sw->vent);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    if(ui->tableView->model()->rowCount()!=0)
    {
        ui->actiondelete->setEnabled(true);
        ui->actiondelete_last->setEnabled(true);
        ui->actionchange_2->setEnabled(true);
    }
}

void MainWindow::on_actiondelete_triggered()
{
    tableModel->delValue(ui->tableView->currentIndex().row());
    QModelIndex in = tableModel->index(tableModel->list.count()-1, 0);
    ui->tableView->setCurrentIndex(in);
    if(ui->tableView->model()->rowCount()==0){
        ui->actiondelete->setEnabled(false);
        ui->actiondelete_last->setEnabled(false);
        ui->actionchange_2->setEnabled(false);
    }
}

void MainWindow::contextMenuEvent( QContextMenuEvent* event )
{
    if( m_menu )
    {
        m_menu->exec(event->globalPos() );
    }
}

void MainWindow::on_actionclose_triggered()
{
    int cur=ui->tableView->model()->rowCount();
    for(int i=0;i<cur;i++)
    tableModel->list.removeLast();
    tableModel->emit layoutChanged();
    ui->actiondelete->setEnabled(false);
    ui->actionchange_2->setEnabled(false);
    ui->actiondelete_last->setEnabled(false);
}

void MainWindow::on_actionclear_table_triggered()
{
    on_actionclose_triggered();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

}

void MainWindow::on_actiondelete_last_triggered()
{
    if(ui->tableView->model()->rowCount()!=0)
    {
        tableModel->list.removeLast();
        tableModel->emit layoutChanged();
    }
    else if(ui->tableView->model()->rowCount()==0){
        ui->actiondelete->setEnabled(false);
        ui->actiondelete_last->setEnabled(false);
        ui->actionchange_2->setEnabled(false);
    }
}

void MainWindow::on_actionchange_2_triggered()
{
    if(ui->tableView->model()->rowCount()!=0)
    {
        sw->h=ui->tableView->currentIndex().row();
        sw->tek=sw->h;
        sw->vent=*tableModel->list.at(sw->h);
        sw->rows=ui->tableView->model()->rowCount();
        sw->tek=sw->h;
        sw->open_form();
        sw->exec();
    }
    if(sw->cur==1)
    {
    tableModel->insertValue(sw->vent,sw->h);
    tableModel->delValue(sw->h+1);
    }
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionchange_triggered()
{

}

