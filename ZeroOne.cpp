#include <iostream> 
#include <stdlib.h>

using namespace std;

enum State { START, DONE, GOT_ZERO, GOT_ONE };
int countZerosAndOnes(const int zeroOneData[], const int numSamples,int& zeroCount, int& oneCount){
	State s = START; 
	int i = 0;
	int input = 0;
	zeroCount = 0;
	oneCount = 0;
	if(numSamples <= 0){
		return -1;
	}
	while(s != DONE){
		if (i >= numSamples){
			s = DONE;
		}
		else{
			input = zeroOneData[i];

			switch(s){ //transisitions 
				case START:
					if(input == 0){
						s = GOT_ZERO;
						zeroCount++;
						i++;
					
					}
					else if(input == 1){
						s = GOT_ONE;
						oneCount++;
						i++;
					
					}
					else
						return -1;
					break;

				case GOT_ZERO:
					if(input == 0)
						i++;
					else if (input == 1){
						s = GOT_ONE;
						oneCount++;
						i++;
						
					}
					else
						return -1;
					break;

				case GOT_ONE:
					if(input == 0){
						s = GOT_ZERO;
						zeroCount++;
						i++;
					
					}
					else if (input == 1)
						i++;
					else
						return -1;
					break;

				case DONE: 
					break;

				default: 
					return -1;
					break;

			}


			

		}
		

	}

	switch(s) { //states
		case GOT_ZERO:
			return -1;
			break;
								
		case GOT_ONE:
			return -1;
			break;
		
		case DONE:
			return 0;
			break;

		case START:
			return -1;
			break;
	}
	
	return 1;
}



