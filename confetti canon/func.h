
#include<iostream>
#include<time.h>
#include<math.h>
#include<boost\timer.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>
boost::mt19937 gen(std::time(0));


float randa_b(int a,int b)
{
	boost::uniform_int<> dist(a, b);
    boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(gen, dist);
    return die();
}
