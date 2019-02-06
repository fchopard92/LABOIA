#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <Dense>
using Eigen::MatrixXd;
using Eigen::VectorXd;
class MainWidget : public QWidget
{
public:
    MainWidget(QWidget *parent = nullptr);

   protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *f);
    QPoint point;
    MatrixXd* m;

};

#endif // MAINWIDGET_H
