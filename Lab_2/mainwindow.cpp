#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "cafemodel.h"
#include "QGridLayout"
#include "linedelegate.h"
#include "editdialog.h"
#include "QPalette"
#include "QColor"
#include "dialogdelegate.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableView = new QTableView();
    myModel = new CafeModel(this);
    tableView->setModel( myModel );
    this->setWindowTitle("Каталог кафе");
    //setFixedSize(450, 300);

    int gx = 100;
        int gy = 100;
        if (parent!=nullptr)
        {
            gx = parent->geometry().x();
            gy = parent->geometry().y();

        }
        this->setGeometry(gx,gy,450,300);   //размеры окна

    //цвет окна
    QColor color;
    color.setNamedColor("#daffc4");

    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(), color);
    this->setPalette(palette);

    DialogDelegate* ddel = new DialogDelegate(nullptr,this);
    lineDelegate* ldel = new lineDelegate();

    tableView->setItemDelegateForColumn(0,ddel);
    tableView->setItemDelegateForColumn(1,ldel);
    tableView->setItemDelegateForColumn(2,ldel);
    tableView->setItemDelegateForColumn(3,ldel);
    tableView->viewport()->setAttribute(Qt::WA_Hover);

    QGridLayout* grdlayout= new QGridLayout();
    grdlayout->addWidget(tableView,1,1,1,2);

    QPushButton* pbtn1 = new QPushButton("Добавить запись");
    QPushButton* pbtn2 = new QPushButton("Удалить запись");

    grdlayout->addWidget(pbtn1,2,1);
    grdlayout->addWidget(pbtn2,2,2);

    QObject::connect(pbtn1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));  //добавить запись
    QObject::connect(pbtn2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));  //удалить запись

    QWidget* wdg=new QWidget();
    wdg->setLayout(grdlayout);

    this->setCentralWidget(wdg);

     tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditDialog* addDialog = new EditDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Cafe* std = new Cafe(addDialog->name(),addDialog->address(),addDialog->cuisine(), addDialog->openingHours(), this);
        myModel->AddCafe(std);
    }

    addDialog->deleteLater();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    myModel->DeleteCafe(selList.row());
}
