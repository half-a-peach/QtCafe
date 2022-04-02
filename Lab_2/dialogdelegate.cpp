#include "dialogdelegate.h"
#include "QtWidgets"
#include "editdialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}

bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        EditDialog* editDialog = new EditDialog(dparentWidget);

        QString Name = model->data(model->index(index.row(),0,index)).toString();
        QString Address = model->data(model->index(index.row(),1,index)).toString();
        QString Cuisine = model->data(model->index(index.row(),2,index)).toString();
        QString OpeningHours = model->data(model->index(index.row(),3,index)).toString();


        editDialog->Dialog(Name, Address, Cuisine, OpeningHours);   //заполняем поля ввода
        if (editDialog->exec() == QDialog::Accepted)  //если ОК, редактируем данные
        {
            model->setData(model->index(index.row(),0,index),editDialog->name());
            model->setData(model->index(index.row(),1,index),editDialog->address());
            model->setData(model->index(index.row(),2,index),editDialog->cuisine());
            model->setData(model->index(index.row(),3,index),editDialog->openingHours());
        }

         editDialog->deleteLater();
    }
    return false;
}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
    return nullptr;
}
