#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cafemodel.h"
#include "QTableView"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void AddRow();
    void DeleteRow();

private:
    Ui::MainWindow *ui;
    CafeModel* myModel;
    QTableView* tableView;
};

#endif
