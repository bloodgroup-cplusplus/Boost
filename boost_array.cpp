#include<iostream>
#include<boost/array.hpp>
#include<string>

int main()
{
  //Definition of boost arry
  //boost::array<type, size>name_of_array;
  boost::array<std::string,3> arrayOfString;
  //Initialization
  arrayOfString={"Boost","C++","Array"};
  //Sort an array
  
  sort(arrayOfString.begin(),arrayOfString.end());
  
  //Acessing the values in the boost::array
  std::cout<<"Go throw this array:"<<std::endl;
  
  for(const std::string & str:arrayOfString)
  {
      std::cout<<str<<std::endl;
  }
  
  //Get the size of boost::array
  std::cout<<"Size:"<<arrayOfString.size()<<std::endl;
  //Get the first element of boost::array
  std::cout<<"First element is:"<<arrayOfString.front()<<std::endl;
  //get the last element of boost::array
  std::cout<<"Last element is:"<<arrayOfString.back()<<std::endl;
  return 0;
}
