# c_p_p-Boost

This repo includes basic tutorials about the cpp boost library. 
to install boost in your machine use the following commands

1) FOR LINUX (ubuntu,arch,kali ..)
Install the boost library using the command

sudo apt-get install libboost-all-dev

remember while compiling the program do include the path if it doesn't simply compile with g++

as in if your program doesn't compile with g++ programname.cpp then you need to inlcude the header files in your path for compilation .
The command for linking to the required header file for linux is:

g++ -I/usr/include/boost/ programname.cpp -o programname
and run it using
./programname


2) FOR MAC USERS 

Install the boost library using the command

brew install boost or sudo port install boost

also remember the above cases when compiling on mac as well


3) Do refer the official boost website: https://www.boost.org/
