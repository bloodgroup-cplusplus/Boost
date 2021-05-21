//variant library can store any of the types specified at
//compile time
// it manages in-place construction/destruction and doesn't re
//require c++ standard
//this prints the value as well
// so we can see the value as well
// In case of C and C++ we have the concept of unions what a union does is
// when we declare a union 
// union {int i; float f;} u;
// and initialize the value to the respective datatypes
// u.i=34 and u.f=2.3
// u.i is overwritten as we know union stores the value of only the larger datatype
// boost variant allows us to create such multipile datatype store option in case of 
// variant
// boost::variant< int , string> u1, u2;
// u1=2// this is an int
// u2="hello"// this is a string as well
// so when you print out the value of u1 and u2 you get 2 and hello respectively
// below we create a vector of variant and push the defined datatypes as many times we want

#include<boost/variant.hpp> and
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
	//std::string&s=boost::get<std::string>(some_values.back());
	//s+="That is great!\n";
	//std::cout<<s<<std::endl;
	for (auto x:some_values)
	{
		std::cout<<x<<std::endl;
	}
	return 0;
}

