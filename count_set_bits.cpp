/*Template metaprogramming is a generic programming technique that uses extremely early binding.
* The compiler acts as an interpreter or "virtual computer" that emits the instructions that make the final program
* template metaprogramming can be used for static configuration,
* Adaptive programs, optimizations and much more.
*Lets' see two kinds on metatemplates- ones that calculate a constant value 
# the other that produce code.
The metaprograms that calculate constant value should never produce
Instructions that are executed at run time

Templates that calculate the number of bits set in a byte. 
At a run time the function looks like this

int bits_set(unsigned char byte)
{
	int count=0;
	for(int i=0;i<8;i++)
	{
		if((0X1L<<i)& byte)
		{
			count++;
		}
	}
	return count;
}

In the cases where the byte is known at compile time this can also be done by the compiler, suing TMP:
*/
#include<iostream>
template<unsigned char byte> class BITS_SET
{
	public:
		enum
		{
			B0=(byte &0X01)?1:0,
			B1=(byte &0x02)?1:0,
			B3=(byte &0x08)?1:0,
			B4=(byte &0x10)?1:0,
			B5=(byte &0X20)?1:0,
			B6=(byte &0x40)?1:0,
			B7=(byte &0x80)?1:0
		};
		
		
	public:
		enum{RESULT= B0+B1+B2+B3+B4+B5+B6+B7};
	};
	
int main()
{
	std::cout<<BITS_SET<15>::RESULT<<std::endl;
	return 0;
}
		
	/*enum for the temporary variables as well as for the result since they are easier to use and
	enumerators have the type of const int. Another way would be to use sstatic const ints int the class
	/
