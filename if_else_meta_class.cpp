#include<iostream>

template<bool Condition>

class IF
{
        public:
                static inline void EXEC()
                {
                        std::cout<<"Statement is true";

                }
};


template<>

class IF < false>

{
        public:
                static inline void EXEC()
                {
                        std::cout<<"Statement is false";
                }

};


int main()
{
        IF<true>::EXEC();
        return 0;
}
