#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->pushButton->setText("Close");
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->progressBar,SLOT(setValue(int)));
    /*disconnect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
               ui->progressBar,SLOT(setValue(int)));*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
