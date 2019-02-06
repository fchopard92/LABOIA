#include "mainwindow.h"
#include "mainwidget.h"

#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
   setWindowTitle(tr("Labo IA"));


   QGridLayout *layout = new QGridLayout;
   this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
   layout->addWidget(new MainWidget(this));

   setLayout(layout);

}
