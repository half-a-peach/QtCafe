#include "cafe.h"

Cafe::Cafe()
{

}

//меняем значение полей класса
void Cafe::SetName(const QString Name)
{
    name = Name;
}

void Cafe::SetAddress(const QString Address)
{
    address = Address;
}

void Cafe::SetCuisine(const QString Cuisine)
{
    cuisine = Cuisine;
}

void Cafe::SetOpeningHours(const QString OpeningHours)
{
    openingHours = OpeningHours;
}

//получаем данные из класса
QString Cafe::Name() const
{
    return name;
}

QString Cafe::Address() const
{
    return address;
}

QString Cafe::Cuisine() const
{
    return cuisine;
}

QString Cafe::OpeningHours() const
{
    return openingHours;
}

 Cafe::~Cafe()
{
}
