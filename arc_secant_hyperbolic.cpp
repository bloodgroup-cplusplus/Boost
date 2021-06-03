#include<boost/math/special_functions/acosh.hpp>
#include<iostream>
#include<vector>

int main()
{
	std::vector<double> v={1,0.832,0.213,0.9,0.1};
	for(auto x:v)
	{
		std::cout<<"The value of arc secant hyperbolic of " <<x<< " is" <<acosh(1/x)<< " " <<std::endl;
	}
	return 0;
}
