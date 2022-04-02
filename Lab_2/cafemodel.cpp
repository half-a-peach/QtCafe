#include "cafemodel.h"

CafeModel::CafeModel(QObject *parent) : QAbstractTableModel(parent)
{
    Cafe* cf1 = new Cafe("Coffee Grace","Рабфаковская, 30","Русская", "С 9.00 до 21.00", this);
    Cafe* cf2 = new Cafe("Огонёк","Шереметьевский проспект, 1","Авторская","С 11.00 до 00.00",  this);
    Cafe* cf3 = new Cafe("Саюри","проспект Ленина, 21","Японская","С 10.00 до 23.00",  this);
    AddCafe(cf1);
    AddCafe(cf2);
    AddCafe(cf3);
}


int CafeModel::rowCount(const QModelIndex &) const   //количество строк
{
   return cafes.count();
}

int CafeModel::columnCount(const QModelIndex &) const   //количество столбцов
{
    return 4;
}


QVariant CafeModel::data(const QModelIndex &index, int role) const   //получение данных
{
    if (role == Qt::DisplayRole)  //отображение
    {
        QString Value = "";
        Cafe* cf = cafes.at(index.row());

        if (index.column() == 0)
        {
            Value = cf->Name();
        }

        else if (index.column() == 1)
        {
            Value = cf->Address();
        }

        else if (index.column() == 2)
        {
            Value = cf->Cuisine();
        }

        else if (index.column() == 3)
        {
            Value = cf->OpeningHours();}

        else
        {
            Value = "";
        };

        return Value;
    }

    return QVariant();
}


QVariant CafeModel::headerData(int section, Qt::Orientation orientation, int role) const    //установка заголовков таблицы
{
    if (role == Qt::DisplayRole)    //отображение
    {
        if (orientation == Qt::Horizontal)   //отображаем в горизонтальный ряд
        {
            switch (section)
            {
            case 0:
                return QString("Название");
            case 1:
                return QString("Адрес");
            case 2:
                return QString("Тип кухни");
            case 3:
                return QString("Время работы");
            }
        }
    }
    return QVariant();
}


bool CafeModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)   //данные для редактирования
    {
        Cafe* cf = cafes.at(index.row());

        if (index.column() == 0)
        {cf->SetName(value.toString());}

        else if (index.column() == 1)
        {cf->SetAddress(value.toString());}

        else if (index.column() == 2)
        {cf->SetCuisine(value.toString());}

        else if (index.column() == 3)
        {cf->SetOpeningHours(value.toString());}
    }

    return true;
}

Qt::ItemFlags CafeModel::flags(const QModelIndex &index) const  //флаги элемента
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void CafeModel::AddCafe(Cafe* cafe)
{
    beginInsertRows(QModelIndex(),cafes.size(),cafes.size());
    cafes.append(cafe);
    endInsertRows();
}

void CafeModel::DeleteCafe(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    cafes.removeAt(row);
    endRemoveRows();
}

