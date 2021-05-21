//list of functions available for converting string to different datatype
//atof->convert string to double
//atoi->convert string to integer
//atol->convert string to long integer
//atoll->convert string to long long integer
//strtod->convert string to double
//strtof->convert string to float
//strtol->convert string to long integer
//strtold->convert string to long double
//strtoll->connvert string to long long integer
//strtoul->convert string to unsigned long integer
//strtoull->convert string to unsigned long long integer

// Since there are too many functions so we have to remember all of them
//Besides the function names are not uniform
//Reversed operation requires creation of stream
//stringstream strm;
//strm<<int_val;
//str s=strm.str();
//To convert integer to text it is inconvinent
// functions like sscanf and sprintf are inconvinient and unsafe
//itoa is a non-standard function

//So there is a lexical cast library to do the conversion to a text format

#include<iostream>
#include<boost/lexical_cast.hpp>
#include<string>
int main()
{
    int s=23;
    std::string str=boost::lexical_cast<std::string>(s);
    std::cout<<str+"s which had value 23 stored in an int is now converted to a std::string and is concatenated with this string to give you a string output"<<std::endl;
    //you can lexical cast to string any datatype In the line below we assign new value to string str which is "Message"+the character 'A' converted to string+ a float 34.5 converted to string
    str="Message:"+boost::lexical_cast<std::string>('A')+"="+boost::lexical_cast<std::string>(34.5);
    std::cout<<str<<std::endl;
    // You can lexical cat any other datatype
    std::array<char,64> msg=boost::lexical_cast<std::array<char,64>>(23);
    s=boost::lexical_cast<int>("23423");
    // You cannot cast invalid datatype for example if you try to cast a float to int
    try
    {
        s=boost::lexical_cast<int>("56.78");//bad_lexical_cast the type specified is integer but the value given inside the parameter is a float.
    }
    catch(boost::bad_lexical_cast &e)
    {
        std::cout<<"Exception caught:"<<e.what()<<std::endl;
    }
    return 0;
}
  
