#include "cafe.h"

Cafe::Cafe(QString Name, QString Address, QString Cuisine, QString OpeningHours, QObject *parent): QObject(parent)
{
    name = Name;
    address = Address;
    cuisine = Cuisine;
    openingHours = OpeningHours;
}

//меняем значение полей класса
void Cafe::SetName(QString Name)
{
    name = Name;
}

void Cafe::SetAddress(QString Address)
{
    address = Address;
}

void Cafe::SetCuisine(QString Cuisine)
{
    cuisine = Cuisine;
}

void Cafe::SetOpeningHours(QString OpeningHours)
{
    openingHours = OpeningHours;
}


//получаем данные из класса
QString Cafe::Name()
{
    return name;
}

QString Cafe::Address()
{
    return address;
}

QString Cafe::Cuisine()
{
    return cuisine;
}

QString Cafe::OpeningHours()
{
    return openingHours;
}


 Cafe::~Cafe()
{
}
