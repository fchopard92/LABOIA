#include "scaler.h"
#include <Dense>
#include <math.h>
using Eigen::MatrixXd;
using Eigen::VectorXd;

Scaler::Scaler()
{

}
 void Scaler::center(MatrixXd& m)
 {
     for(unsigned c =0; c < m.cols(); ++c)
     {
         VectorXd v =  m.block(0,c,m.rows(),1);
         double mean = v.sum() / v.rows();

         for(unsigned l =0; l < m.rows(); ++l)
         {
             // on retranche la moyenne
             m(l,c) =  m(l,c)  - mean ;

         }

     }

 }
