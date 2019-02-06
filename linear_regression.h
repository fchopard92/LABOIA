#ifndef REGRESSION_H
#define REGRESSION_H
#include <Dense>
using Eigen::MatrixXd;

class LinearRegression
{
private:
    double a,b;
public:
    LinearRegression();
    void fit(MatrixXd& m);
    double transform(double x);
    double get_a() const { return a;}
    double get_b() const { return b;}

};

#endif // REGRESSION_H
