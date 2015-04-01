#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paintwidget.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // This is one way to programatically add a custom widget
    QHBoxLayout * hbox = new QHBoxLayout();
    ui->centralWidget->setLayout(hbox);
    hbox->addWidget(new PaintWidget());

    // instead, you could use the UI Designer to "Promote" a widget to a specific type.
}

MainWindow::~MainWindow()
{
    delete ui;
}
