#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QString>
#include <QVariant>
#include <QTableView>
#include "ventil.h"

/**
 * @brief Класс табличной модели TableModel
 */
class TableModel : public QAbstractTableModel
{
    /**
     * @brief Количество колонок таблицы
     */
    const int columns;

public:
    /**
     * @brief Список элементов класса Ventil
     */
    QList<Ventil *> list;
    /**
     * @brief Конструктор табличной модели
     * @param parent указатель на родителя
     */
    explicit TableModel(QObject *parent = nullptr);
    /**
     * @brief rowCount функция возвращает количество строк списка list
     * @param parent указатель на родителя
     * @return
     */
    int rowCount(const QModelIndex &parent) const;
    /**
     * @brief columnCount возвращает количество столбцов
     * @param parent указатель на родителя
     * @return
     */
    int columnCount(const QModelIndex &parent) const;
    /**
     * @brief data возвращает значения элемента из списка list
     * @param index
     * @param role
     * @return
     */
    QVariant data(const QModelIndex &index, int role) const;
    /**
     * @brief headerData функция устанавливает названия столбцов и строк
     * @param section
     * @param orientation
     * @param role
     * @return
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    /**
     * @brief flags возвращает активна ли ячейка, можно ли ее редактировать, выделять, перетаскивать.
     * @param index
     * @return
     */
    Qt::ItemFlags flags(const QModelIndex &index) const;

public slots:
    /**
     * @brief setData функция присваивает значения списку
     * @param index
     * @param value значения
     * @param role
     * @return
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    /**
     * @brief insertValue вставляет зачение в конец списка
     * @param vent указатель на объект
     */
    void insertValue(Ventil &vent);
    /**
     * @brief delValue удаляет значение из списка с определенной строки
     * @param Row строка, которая удалится
     */
    void delValue(int Row);
    /**
     * @brief insertValue вставит значение в определенную строку
     * @param vent объект который вставляется
     * @param row строка в которую вставляется объект
     */
    void insertValue(Ventil &vent, int row);
private:
    /**
     * @brief vt указатель на класс Ventil
     */
    Ventil *vt;
};

#endif // TABLEMODEL_H
