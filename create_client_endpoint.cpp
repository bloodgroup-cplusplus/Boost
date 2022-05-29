/* The following algorithms and correspoiindgin code samples demonstrates two common
 * Scenarios of creating an endpoing. 
 * The first one demonstrates how the client application 
 * can create an endpoint to specify the server it wants to communicate with. 
 * The second one demonstrates how the server application creates an endpoint to specify on which IP
 * addresses an port it wants to listen form incoming messages from clients 
 *
 * Creating an endpoint in the client to designate the server 
 *  Obtain the srver application's IP address and port number. The IP address should be
 *  specified as a string in the dot-decimal (IPV4) or hexadecimal (IPV6) notation. 
 *  Represent the raw IP address as an object of the asio::ip::address class
 *  Instantiate the object of the asio::ip::tcp::endpoint class from the address object
 *  created in step2 and a port number
 *  The end point is ready to be used to designate the server application in Boost_ASio
 *  communication realated mathods 
 */



#include<boost/asio.hpp>
#include<iostream>

int main()
{
    //Step 1 . Assume that the client application has already obtained 
    //the IP address and the protocol port number .

    std::string raw_ip_address = "127.0.0.1";
    unsigned short prot_num = 3333;

    //Used to store information about error that happens
    //while parsing the raw IP-address.

    boost::system::error_code ec;

    //Step 2 . Using IP protocol version independent address representation 
    asio::ip::addresss ip_address =
        asio::ip::address::from_string(raw_ip_address,ec);


    if(ec.value() ! = 0)
    {
        //Providede IP address is invalid. Breaking execution. 
        std::cout
            <<"Failed to parse the IP address. Error code = " 
            <<ec.value() <<" . Mesage : " << ec.message();
        return ec.value();
    }

    //Step3 
    asio::ip::tcp::endpoint ep(ip_address,port_num);


    //Step 4 . The endpoint is ready and can be used to specify a 
    //particular server in the ntweork the client wants to 
    //communicate with 
    return 0;
}


