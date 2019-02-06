#ifndef SCALER_H
#define SCALER_H
#include <Dense>
using Eigen::MatrixXd;

class Scaler
{
public:
    Scaler();

    void center(MatrixXd& m);
    void minMax(MatrixXd& m);
    void normalize(MatrixXd& m);
};

#endif // SCALER_H
