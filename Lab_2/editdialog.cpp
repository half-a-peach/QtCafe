#include "editdialog.h"
#include "cafe.h"

EditDialog::EditDialog(QWidget* wgt): QDialog(wgt)
{
    lnEditName = new QLineEdit();
    lnEditAddress = new QLineEdit();
    lnEditCuisine = new QLineEdit();
    lnEditOpeningHours = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;

    mainLayout->addWidget(new QLabel("Название кафе"),1,1);
    mainLayout->addWidget(lnEditName,1,2);

    mainLayout->addWidget(new QLabel("Адрес"),2,1);
    mainLayout->addWidget(lnEditAddress,2,2);

    mainLayout->addWidget(new QLabel("Тип кухни"),3,1);
    mainLayout->addWidget(lnEditCuisine,3,2);

    mainLayout->addWidget(new QLabel("Время работы"),4,1);
    mainLayout->addWidget(lnEditOpeningHours,4,2);

    QPushButton* btnOk = new QPushButton("&ОК");

    mainLayout->addWidget(btnOk,5,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о кафе");
}

//считываем текст из полей ввода
QString EditDialog::name() const
{
    return lnEditName->text();
}

QString EditDialog::address() const
{
    return lnEditAddress->text();
}

QString EditDialog::cuisine() const
{
    return lnEditCuisine->text();
}

QString EditDialog::openingHours() const
{
    return lnEditOpeningHours->text();
}

//заполняем имеющимися значениями
void EditDialog::Dialog(QString name, QString address, QString cuisine, QString openingHours)
{
    lnEditAddress->setText(address);
    lnEditName->setText(name);
    lnEditCuisine->setText(cuisine);
    lnEditOpeningHours->setText(openingHours);
}
