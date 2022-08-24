#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QTableView>
#include "tablemodel.h"
#include "ventil.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *mainWindow = new MainWindow;
    QTableView tableView;
    Ventil ventil;
    MainWindow w;
    w.show();
    return a.exec();
}
