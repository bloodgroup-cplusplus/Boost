#include<iostream>
#include<boost/property_tree/ptree.hpp?
#iinclude<boost/property_tree/xml_parser.hpp>
#include<boost/foreach.hpp>
using boost::property_tree::ptree;
int main()
{
	try
	{
		ptree pt;
		read_json("path to your xml file",pt);
		//iterate on the xml using BOOST_FOREACH
		BOOST_FOREACH(ptree::value_type & child, pt.get_child("this portion will include the key of the xml file which is the first detail in the xml file"))
		{
			std::cout<<"Node Name:"<<child.first<<std::endl;
			std::cout<<"Value"<<child.second.get<std::string>("xmlattr>.name of the attribute")<<std::endl;
			
		}
		
		return EXIT_SUCCESS;
	}
	
	
	catch(std::exception const & e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	
	return EXIT_FAILURE;
	
}

