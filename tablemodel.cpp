#include "tablemodel.h"
#include <QMimeData>
#include <QSplitter>


TableModel::TableModel(QObject *parent)
    : QAbstractTableModel{parent}
    , columns(7)

{
    vt=new Ventil();
}


int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return list.count();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return columns;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    if(index.isValid())
    {
    switch(role)
    {
        case Qt::DisplayRole :
        case Qt::EditRole:
            if(col==0)
                return list.at(row)->get_id();
            if(col==1)
                return list.at(row)->get_Post();
            if(col==2)
                return list.at(row)->get_country();
            if(col==3)
                return list.at(row)->get_tel();
            if(col==4)
                return list.at(row)->get_vid();
            if(col==5)
                return list.at(row)->get_articul();
            if(col==6)
                return list.at(row)->get_cost();
        return QVariant();
    default:
    return QVariant();
    }
    }
    else
        return QVariant();
    return QVariant();
}


bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
            return false;
        int col = index.column();
        int row = index.row();
        if (role == Qt::EditRole)
        {
            if(col == 0)
                list.at(index.row())->set_id(value.toInt());
            if(col==1)
                list.at(row)->set_Post(value.toString());
            if(col==2)
                list.at(row)->set_country(value.toString());
            if(col==3)
                list.at(row)->set_tel(value.toString());
            if(col==4)
                list.at(row)->set_vid(value.toString());
            if(col==5)
                list.at(row)->set_articul(value.toString());
            if(col==6)
                list.at(row)->set_cost(value.toInt());
            return true;
        }
        return false;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation==Qt::Horizontal && role==Qt::DisplayRole){
        switch(section)
        {
            case 0:
            return QString(tr("id"));
            case 1:
            return QString(tr("Provider/Поставщик"));
            case 2:
            return QString(tr("Country/Страна"));
            case 3:
            return QString(tr("Tel/Тел"));
            case 4:
            return QString(tr("Kind/Вид"));
            case 5:
            return QString(tr("Articul/Артикул"));
            case 6:
            return QString(tr("Cost/Цена"));
        }
    }
    if(orientation==Qt::Horizontal && role==Qt::DisplayRole)
    {
        return QString::number(section+1);
    }
    if(orientation==Qt::Vertical && role==Qt::DisplayRole)
        return QString::number(section+1);
    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
      if (index.isValid())
          return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsDragEnabled;
      else
          return Qt::ItemIsDropEnabled;
}

void TableModel::insertValue(Ventil &vent)
{
      Ventil *v=new Ventil(vent);
      list << v;
      emit layoutChanged();
}
void TableModel::insertValue(Ventil &vent, int Row)
{
     Ventil *v=new Ventil(vent);
        list << v;
        Ventil Temp;
        Ventil Temp1;
        int count = list.count() - 1;
        int Rowcount = list.count();
        for (int i = 0; i < Rowcount; i++ ){
            if(Row == i){
                Temp.set_Post(list.at(i)->get_Post());
                Temp.set_tel(list.at(i)->get_tel());
                Temp.set_articul(list.at(i)->get_articul());
                Temp.set_country(list.at(i)->get_country());
                Temp.set_vid(list.at(i)->get_vid());
                Temp.set_cost(list.at(i)->get_cost());


                list.at(i)->set_Post(list.at(count)->get_Post());
                list.at(i)->set_tel(list.at(count)->get_tel());
                list.at(i)->set_articul(list.at(count)->get_articul());
                list.at(i)->set_country(list.at(count)->get_country());
                list.at(i)->set_vid(list.at(count)->get_vid());
                list.at(i)->set_cost(list.at(count)->get_cost());

            }
            else if( i > Row){
                Temp1.set_Post(list.at(i)->get_Post());
                Temp1.set_tel(list.at(i)->get_tel());
                Temp1.set_articul(list.at(i)->get_articul());
                Temp1.set_country(list.at(i)->get_country());
                Temp1.set_vid(list.at(i)->get_vid());
                Temp1.set_cost(list.at(i)->get_cost());


                list.at(i)->set_Post(Temp.get_Post());
                list.at(i)->set_tel(Temp.get_tel());
                list.at(i)->set_articul(Temp.get_articul());
                list.at(i)->set_country(Temp.get_country());
                list.at(i)->set_vid(Temp.get_vid());
                list.at(i)->set_cost(Temp.get_cost());



                Temp.set_Post(Temp1.get_Post());
                Temp.set_tel(Temp1.get_tel());
                Temp.set_articul(Temp1.get_articul());
                Temp.set_country(Temp1.get_country());
                Temp.set_vid(Temp1.get_vid());
                Temp.set_cost(Temp1.get_cost());

            }
        }
        emit layoutChanged();
}
void TableModel::delValue(int Row)
{
    int countrow = list.count();
        if(Row == countrow){
           list.removeAt(countrow);
        }
        else
        for (int i=0;i<countrow;i++){
            if(Row == i){
                for(int j=0; j<countrow;j++){
                    if((list.at(j)->get_id()-1) > Row){
                        list.at(j)->set_id(list.at(j)->get_id()-1);
                    }
                }
                list.removeAt(i);
            }
        }
        emit layoutChanged();
}



