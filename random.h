#ifndef RANDOM_H
#define RANDOM_H
#include <Dense>
using Eigen::MatrixXd;

class Random
{
public:
    Random();
    // Initialisation de la matrice suivant une loi uniforme
    void uniform(MatrixXd& m,const int min, const int max);

};

#endif // RANDOM_H
