#include<boost/any.hpp>
#include<iostream>
#include<vector>
#include<string>
int main()
{
	std::vector<boost::any> some_values;
	some_values.push_back(10);
	const char * c_str="Hello there";;
	some_values.push_back(c_str);
//	for(auto x: some_values)
//	{
//		std::cout<<x<<std::endl;
//	}
	return 0;;
}

