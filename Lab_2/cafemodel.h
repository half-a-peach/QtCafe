#pragma once
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QString>
#include "cafe.h"

class CafeModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CafeModel(QObject *parent);

    int rowCount(const QModelIndex &parent = QModelIndex()) const ;  //количество строк таблицы
    int columnCount(const QModelIndex &parent = QModelIndex()) const;   //количество стобцов таблицы
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;  //получение данных
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;  //установка заголовков
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole); //изменение данных
    Qt::ItemFlags flags(const QModelIndex & index) const ; //флаги элемента

    //добавление и удаление данных
    void AddCafe(Cafe* cafe);
    void DeleteCafe(int row);

private:
    QList<Cafe*> cafes;
};
