#include "linear_regression.h"

#include <QtDebug>
#include "scaler.h"
#include <Dense>
#include "math.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;
LinearRegression::LinearRegression()
{

}
void LinearRegression::fit(MatrixXd& m)
{
    VectorXd v0 =  m.block(0,0,m.rows(),1);
    double s = 0;
    double mean0 = v0.sum() / v0.rows();
    for(unsigned l =0; l < v0.rows(); ++l)
    {
        s += pow(v0(l) - mean0, 2);
    }
    double variance0 = s / v0.rows();

    VectorXd v1 =  m.block(0,1,m.rows(),1);
    s = 0;
    double mean1 = v1.sum() / v1.rows();
    for(unsigned l =0; l < v1.rows(); ++l)
    {
        s += pow(v1(l) - mean1, 2);
    }
    double variance1 = s / v1.rows();


    double sd = (v1.transpose() * v0) ;
    this->a = sd/variance0;
    this->b = mean1 - (this->a)*mean0;


}

  double LinearRegression::transform(double x)
  {
      return a * x + b;
  }
