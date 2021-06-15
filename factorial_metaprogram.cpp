#include<iostream>
class FACTOR
{
	public:
		enum {RESULT = i* FACTOR <i-1> ::RESULT};
	
	
};


template<>
class FACTOR< 1>
{
	public:
		enum {RESULT= 1};
};

int main()
{
	std::cout<<FACTOR<10>::RESULT;
	return -1;
}
