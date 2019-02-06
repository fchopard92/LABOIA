#include "random.h"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/uniform_int.hpp>
#include <ctime>


Random::Random()
{

}

void Random::uniform(MatrixXd& m,const int min, const int max)
{
    std::time_t result = std::time(nullptr);
    boost::mt19937 gen(static_cast<const unsigned int>(result));

    boost::uniform_int<> uni(min,max);
    for(unsigned i =0; i < m.rows () ; ++i)
        for(unsigned j =0; j < m.cols () ; ++j)
        {
            boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(gen,uni);
            m(i,j) = static_cast<double>(die());
        }
}
