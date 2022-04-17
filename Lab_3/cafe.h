#ifndef CAFE_H
#define CAFE_H

#include "QString"
//#include <QObject>

class Cafe
{

public:
    Cafe();
    virtual ~Cafe();
    void SetName(QString Name);
    void SetAddress(QString Address);
    void SetCuisine(QString Cusine);
    void SetOpeningHours(QString OpeningHours);

    QString Name() const;
    QString Address() const;
    QString Cuisine() const;
    QString OpeningHours() const;

private:
    QString name;
    QString address;
    QString cuisine;
    QString openingHours;
};


#endif // CAFE_H
