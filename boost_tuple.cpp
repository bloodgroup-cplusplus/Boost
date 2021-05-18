#include<iostream>
#include<boost/tuple/tuple.hpp>
#include<boost/tuple/tuple_comparison.hpp>
#include<string>

int main()
{
	boost::tuple<int, std::string> almost_a_pair(10,"Hello");
	boost::tuple<int, float, double, int> quad(10,1.0f,10.0,1);
	int i=boost::get<0> (almost_a_pair);
	const std::string & str=boost::get<1>(almost_a_pair);
	double b=boost::get<2>(quad);
	std::cout<<str<<std::endl;
	std::cout<<i<<std::endl;
	std::cout<<b<<std::endl;
	return 0;
}
