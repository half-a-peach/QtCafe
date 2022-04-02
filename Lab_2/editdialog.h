#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "cafe.h"

class EditDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* lnEditName;
    QLineEdit* lnEditAddress;
    QLineEdit* lnEditCuisine;
    QLineEdit* lnEditOpeningHours;

public:
    EditDialog(QWidget* wgt = nullptr);

    QString name() const;
    QString address() const;
    QString cuisine() const;
    QString openingHours() const;

    void Dialog(QString name, QString address, QString cuisine, QString openingHours);  //заполнение
};

#endif
