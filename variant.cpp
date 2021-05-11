//variant library can store any of the types specified at
//compile time
// it manages in-place construction/destruction and doesn't re
//require c++ standard
//this prints the value as well
// so we can see the value as well

#include<boost/variant.hpp>
#include<iostream>
#include<vector>
#include<string>
int main()
{
	typedef boost:: variant<int,const char*,std::string> my_var_t;
	std::vector<my_var_t> some_values;
	some_values.push_back(10);
	some_values.push_back("Hello there");
	some_values.push_back(std::string("wow!"));
	std::string&s=boost::get<std::string>(some_values.back());
	s+="That is great!\n";
	std::cout<<s<<std::endl;
	for (auto x:some_values)
	{
		std::cout<<x<<std::endl;
	}
	return 0;
}

