#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QTranslator>
#include "tablemodel.h"
#include "ventil.h"




namespace Ui {
class Dialog1;
}

/**
 * @brief Класс диалогового окна Dialog1
 *
 * Данный класс описывает диалоговое окно нашей программы
 */
class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Dialog1 Конструктор диалогового окна
     * @param parent указатель на родителя
     */
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();
    /**
     * @brief langTR переменная для изменения языка
     */
    QString langTR;
    /**
     * @brief vent объект класса Ventil
     */
    Ventil vent;
    /**
     * @brief tek переменная для определения того как открыть форму(заполненную или пустую)
     */
    int tek=-1;
    /**
     * @brief cur текущая строка
     */
    int cur=0;
    /**
     * @brief h текущая строка
     */
    int h=0;
    /**
     * @brief tableModel указатель на TableModel
     */
    TableModel *tableModel;
    /**
     * @brief rows кол-во строк
     */
    int rows;
    /**
     * @brief qtLanguageTranslator создание объекта класса QTranslator
     */
    QTranslator qtLanguageTranslator;

private slots:
    /**
     * @brief on_pushButton_clicked функция для отправки данных из формы в tableModel
     */
    void on_pushButton_clicked();
    /**
     * @brief on_pushButton_2_clicked функция закрытия формы
     */
    void on_pushButton_2_clicked();
public slots:
    /**
     * @brief open_form функция для открытия диалогового окна с данными выбранного элемента или пустого окна
     */
    void open_form();
private:
    Ui::Dialog1 *ui;
protected:
    /**
     * @brief changeEvent функция для определения изменения языка
     * @param e указатель на событие
     */
    void changeEvent(QEvent *e);
};

#endif // DIALOG1_H
