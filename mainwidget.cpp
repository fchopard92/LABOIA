#include "mainwidget.h"
#include "linear_regression.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtDebug>
#include "random.h"
#include "scaler.h"
#include <Dense>
#include "math.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace::std;


MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m = new MatrixXd(1000,2);
    Random ran;
    ran.uniform(*m,0,600);

}
void MainWidget::paintEvent(QPaintEvent *)
  {
      QPainter painter(this);

      QPen linepen(Qt::black);
      linepen.setCapStyle(Qt::RoundCap);
      linepen.setWidth(2);
      painter.setRenderHint(QPainter::Antialiasing,true);
      painter.setPen(linepen);
      LinearRegression reg;
      reg.fit(*m);
      painter.drawLine(0,0,500,reg.transform(500));

      for(unsigned i =0; i < m->rows () ; ++i)
      {
        painter.drawPoint(QPoint((*m)(i,0),(*m)(i,1)));
      }

}

void MainWidget::mousePressEvent(QMouseEvent *f)
{

    m-> conservativeResize(m->rows() +1, 2);
    qDebug() << "size =" << m->rows() << endl;
    (*m)(m->rows() - 1  ,0) = f->x();
    (*m)(m->rows() - 1 , 1) = f->y();

    qDebug() << f->x() <<" , " << f->y();
    update();
}
