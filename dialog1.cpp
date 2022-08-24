#include "dialog1.h"
#include "ui_dialog1.h"
#include "mainwindow.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    tableModel(new TableModel(this)),
    ui(new Ui::Dialog1)
{    langTR;
     qtLanguageTranslator.load("QtLanguage_" + langTR, ".");
     qApp->installTranslator(&qtLanguageTranslator);
     ui->setupUi(this);
     ui->Articul->setInputMask("000 000");
     ui->Tel->setInputMask("+7(000)000-00-00");
    /*  QFile fl("country.txt");
       fl.open(QIODevice::ReadOnly);
        QTextStream in(&fl);
         while(!in.atEnd())
         {
             ui->coutry->addItem(in.readLine());
         }
          fl.close();*/
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::changeEvent(QEvent *e)
{
    if(e->type()==QEvent::LanguageChange)
            ui->retranslateUi(this);
}

void Dialog1::on_pushButton_clicked()
{
    if(tek==-1)
    {
        vent.set_id(rows);
        vent.set_Post(ui->Post->text());
        vent.set_tel(ui->Tel->text());
        vent.set_country(ui->coutry->currentText());
        vent.set_articul(ui->Articul->text());
        vent.set_vid(ui->Vid->text());
        vent.set_cost(ui->cost->value());
    }
    else
    {
        vent.set_id(h+1);
        vent.set_Post(ui->Post->text());
        vent.set_tel(ui->Tel->text());
        vent.set_country(ui->coutry->currentText());
        vent.set_articul(ui->Articul->text());
        vent.set_vid(ui->Vid->text());
        vent.set_cost(ui->cost->value());
        tableModel->insertValue(vent, h);
    }
    cur=1;
    tableModel-> emit layoutChanged();
    this->close();
}

void Dialog1::open_form()
{
    cur=0;
    if(tek==-1)
    {
        ui->Post->clear();
        ui->Tel->clear();
        ui->coutry->setCurrentText(0);
        ui->Articul->clear();
        ui->Vid->clear();
        ui->cost->setValue(0);
    }
    else
    {
        ui->Post->setText(vent.get_Post());
        ui->Tel->setText(vent.get_tel());
        ui->coutry->setCurrentText(vent.get_country());
        ui->Articul->setText(vent.get_articul());
        ui->Vid->setText(vent.get_vid());
        ui->cost->setValue(vent.get_cost());
    }
}

void Dialog1::on_pushButton_2_clicked()
{
    this->close();
}

