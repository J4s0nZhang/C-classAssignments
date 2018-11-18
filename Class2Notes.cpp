#include <iostream> // system files (includes declaration of things.... eg cout cerr)
//#include "..." will be your own header file
#include <c.math> 
using namespace std;

//a function is a sub-routine

// the defined starting point of the program, it is a function that must return an int

//a simple statement (individual instruction) endds with ;
// a compound statment is a sequence of simple statemnts and begins and ends with {}

//variables are not mathematical variables, they are simply labels on memory spaces, a way to remember where something is
// a declaration says that something exists 
// a definition specifies what something is

//c philosophy: dont do what the programmer doesnt tell you to do, trust the programmer to do the right thing,  

//c++ does not initialize variables for you: 
int main(){ 

	int x;
	x = 15; //x is initialized here not the previous line

	//there are 14 basic types in c: eg char, int, float
	//in object oriented programming you can actually define new types on top of the basic 14
	// 1 byte is 8 bits
	// 1 bit is a binary digit (number in base 2)
	//ints: signed, unsigned, long unsigned long most size depends on the machine: processors int is 4 bytes, but never smaller than 1 byte
	//float: has defined size: 1 bit defines the sign, 8 is the exponent and the remaining 23 bits is the number 

	//when you mix types.. eg int and float, promotes the int to a float. 
	//you CAN compare a float to ITSELF

	//x++ returns the value of x before adding 1 then adds 1
	//++x add 1 then returns the value of x

	//anything thats not 0 is true
	//false is 0
	//not 0 is 1

	



}
