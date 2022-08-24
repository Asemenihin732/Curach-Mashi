/*!
 *
 * \author Суя Мария
 * \version 1.0
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog1.h"
#include <QTranslator>
#include <ventil.h>
#include <QSettings>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTableWidgetItem;
class Ventil;
class TableModel;

/*!
 * \brief Класс главного окна MainWindow
 *
 * Данный класс описывает главное окно нашей программы
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow Конструктор главного окна
     * @param parent указатель на родителя
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
     * @brief lang переменная для установки языка приложения
     */
    QString lang,langTR;

public slots:
    /**
     * @brief sorting функция включения/отключения сортировки по столбцам
     */
    void sorting();
    /**
     * @brief filter функция для отображения данных из TableView, соответсвующих запросу
     */
    void filter();
    /**
     * @brief newFile функция открывающая новое окно для работы со вторым файлом
     */
    void newFile();
    /**
     * @brief on_actionSave_triggered функция сохраняет файл
     */
    void on_actionSave_triggered();
    /**
     * @brief on_actionOpen_triggered функция открывает файл
     */
    void on_actionOpen_triggered();
    /**
     * @brief on_actionChange_Language_triggered функция изменения языка программы
     *
     * Открывает окно с выбором языка
     */
    void on_actionChange_Language_triggered();
    /**
     * @brief on_actionAbout_triggered функция открывает messageBox в котором указано авторство
     */
    void on_actionAbout_triggered();
    /**
     * @brief on_actionadd_triggered функция открывает диалоговое окно для добавления нового элемента в tableView
     */
    void on_actionadd_triggered();
    /**
     * @brief on_actiondelete_triggered функция удаляет выбранный элемент из tableView
     */
    void on_actiondelete_triggered();
    /**
     * @brief on_actionclose_triggered функция закрывает файл
     */
    void on_actionclose_triggered();
    /**
     * @brief on_actionclear_table_triggered функция очищает tableModel
     */
    void on_actionclear_table_triggered();

    void on_tableView_clicked(const QModelIndex &index);
    /**
     * @brief on_actiondelete_last_triggered функция удаляет последний элемент tableModel
     */
    void on_actiondelete_last_triggered();
    /**
     * @brief on_actionchange_2_triggered функция открывает диалоговое окно с данными выбранной строки для их изменения
     */
    void on_actionchange_2_triggered();

private:
    /**
     * @brief ui указатель на текущее окно
     */
    Ui::MainWindow *ui;
    /**
     * @brief m_menu указатель на контекстное меню
     */
    QMenu *m_menu;
    /**
     * @brief sw указатель на диалоговое окно
     */
    Dialog1 *sw;
    /**
     * @brief qtLanguageTranslator создание объекта класса QTranslator
     */
    QTranslator qtLanguageTranslator;
   // QList<Ventil> *values;
    /**
     * @brief tableModel указатель на класс TableModel
     */
    TableModel *tableModel;
    /**
     * @brief proxy создание proxy модели для сортировки по столбцам
     */
    QSortFilterProxyModel proxy;
    /**
     * @brief readSettings  функция для чтения настроек
     */
    void readSettings();
    /**
     * @brief writeSettings  функция для записи настроек
     */
    void writeSettings();
    /**
     * @brief loadFile функция загрузки данных из файла в tableModel
     * @param filePathAndName название файла
     */
    void loadFile(const QString &filePathAndName);
    /**
     * @brief saveFile функция сохранения файла из tableModel в текстовый файл
     * @param filePathAndName название файла
     */
    void saveFile(const QString &filePathAndName);
    /**
     * @brief rowCount количество строк в tableModel
     */
    int rowCount;
    /**
     * @brief columnCount количество столбцов в tableModel
     */
    int columnCount;

protected:
    /**
     * @brief changeEvent функция для определения изменения языка
     * @param e указатель на событие
     */
    void changeEvent(QEvent *e) override;
    /**
     * @brief contextMenuEvent функция для появления контекстного меню
     * @param event
     */
    void contextMenuEvent(QContextMenuEvent *event) override;
private slots:
    /**
     * @brief on_actionExit_triggered закрывает окно MainWindow
     */
    void on_actionExit_triggered();

    void on_actionchange_triggered();
};
#endif // MAINWINDOW_H
