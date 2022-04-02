#ifndef DIALOGDELEGATE_H
#define DIALOGDELEGATE_H

#include "QtWidgets"

class DialogDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    DialogDelegate(QObject *parent = nullptr, QWidget* parentWidget = nullptr);

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);  //редактирование элемента при событии
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;  //виджет для редактирования элемента

    private:
    QWidget* dparentWidget;
};

#endif
