#ifndef CAFE_H
#define CAFE_H
#include "QString"
#include <QObject>

class Cafe: public QObject
{
    Q_OBJECT

public:
    Cafe(QString Name, QString Address, QString Cuisine, QString OpeningHours, QObject *parent = nullptr );
    virtual ~Cafe();
    void SetName(QString Name);
    void SetAddress(QString Address);
    void SetCuisine(QString Cusine);
    void SetOpeningHours(QString OpeningHours);

    QString Name();
    QString Address();
    QString Cuisine();
    QString OpeningHours();

private:
    QString name;
    QString address;
    QString cuisine;
    QString openingHours;
};

#endif
