#ifndef CAFELIST_H
#define CAFELIST_H

#include <QAbstractListModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "cafe.h"

class CafeList : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QAbstractListModel* cafeModel READ getModel CONSTANT)
private:
    QList<Cafe> listOfCafes;
    QAbstractListModel *getModel();

public:
    CafeList(QObject *parent = nullptr);
    ~CafeList() override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum ResentRoles {
            name = Qt::DisplayRole,
            address = Qt::DisplayRole + 1,
            cuisine = Qt::DisplayRole + 2,
            openingHours = Qt::DisplayRole + 3
       };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void add(const QString& cafeName, const QString& cafeAddress, const QString& cafeCuisine, const QString& cafeOpeningHours);
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE QString count(const QString& textFindSize);
    Q_INVOKABLE void edit(const QString& cafeName, const QString& cafeAddress, const QString& cafeCuisine, const QString& cafeOpeningHours, const int index);
};

#endif // CAFELIST_H
