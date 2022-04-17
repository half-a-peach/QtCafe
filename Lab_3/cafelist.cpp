#include "cafelist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

CafeList::CafeList(QObject* parent):QAbstractListModel(parent)
{
    add("Coffee Grace","Рабфаковская, 30","Русская", "С 9.00 до 21.00");
    add("Огонёк","Шереметьевский проспект, 1","Авторская","С 11.00 до 00.00");
    add("Саюри","проспект Ленина, 21","Японская","С 10.00 до 23.00");
}

CafeList::~CafeList()
{

}

int CafeList::rowCount(const QModelIndex&) const
{
    return listOfCafes.size();
}

QVariant CafeList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfCafes.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfCafes.at(index.row()).Name());
                case address:
                    return QVariant(listOfCafes.at(index.row()).Address());
                case cuisine:
                    return QVariant(listOfCafes.at(index.row()).Cuisine());
                case openingHours:
                    return QVariant(listOfCafes.at(index.row()).OpeningHours());

                default:
                    return QVariant();
            }
    }
}

QHash<int, QByteArray> CafeList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "cafeName";
    roles[address] = "cafeAddress";
    roles[cuisine] = "cafeCuisine";
    roles[openingHours] = "cafeOpeningHours";
       return roles;
}

void CafeList::add(const QString& cafeName, const QString& cafeAddress, const QString& cafeCuisine, const QString& cafeOpeningHours){
     Cafe cafe;
     cafe.SetName(cafeName);
     cafe.SetAddress(cafeAddress);
     cafe.SetCuisine(cafeCuisine);
     cafe.SetOpeningHours(cafeOpeningHours);

    beginInsertRows(QModelIndex(),listOfCafes.size(),listOfCafes.size());
    listOfCafes.append(cafe);  //добавление в конец списка
    endInsertRows();

}

QAbstractListModel* CafeList::getModel(){
    return this;
}

void CafeList::del(const int index){

     if (index >= 0 && index < listOfCafes.size())
     {
        beginRemoveRows(QModelIndex(), index, index);
        listOfCafes.removeAt(index);
              endRemoveRows();
     }
     else qDebug() << "Error index";

}

QString CafeList::count(const QString& textFind){
    int count = 0;

    for(int i = 0; i < listOfCafes.size(); i++)
        if(listOfCafes[i].Cuisine().toLower() == textFind.toLower())
            count++;

    QString c = QString::number(count);
    return c;
}

void CafeList::edit(const QString& cafeName, const QString& cafeAddress, const QString& cafeCuisine, const QString& cafeOpeningHours, const int index) {
     if(index >= 0 && index < listOfCafes.size() )
     {
        auto& currentStar = listOfCafes[index];
        if (currentStar.Name().compare(cafeName)!=0 || currentStar.Address() != cafeAddress || currentStar.Cuisine() != cafeCuisine || currentStar.OpeningHours() != cafeOpeningHours)
        {
            currentStar.SetName(cafeName);
            currentStar.SetAddress(cafeAddress);
            currentStar.SetCuisine(cafeCuisine);
            currentStar.SetOpeningHours(cafeOpeningHours);

            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
            qDebug() << listOfCafes[index].Cuisine();
        }

     }
      else qDebug() << "Error index";
}
