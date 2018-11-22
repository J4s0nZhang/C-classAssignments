#include <iostream> 
#include <stdlib.h> 

using namespace std; 

enum State { START, DONE, GOT_ZERO, GOT_ONE, GOT_KTH_ZERO, GOT_KTH_ONE};

int countZerosAndOnes(const int zeroOneData[], const int numSamples,const int kMax,int& zeroCount, int& oneCount){
	State s = START;
	int i = 0; 
	zeroCount = 0;
	oneCount = 1;
	int k = 0;

	if(numSamples <= 0 || kMax < 0){
		return -1;
	}

	while (s != DONE){

		if( i >= numSamples){
			s = DONE; 
		}
		else{ 
			int input = zeroOneData[i];

			switch(s){ //transistions 
				case START:
					if(input == 1){
						s = GOT_ONE;
						i++;
					}
					else if(input == 0){
						s = GOT_KTH_ZERO;
						i++;
						k++;
					}
					else{
						return -1;
					}
					break;

				case GOT_ONE:
					if(input == 1){
						i++;
					}
					else if(input == 0){
						s = GOT_KTH_ZERO;
						k = 0; 
						
						
					}
					else{
						return -1;
					}
					break;

				case GOT_KTH_ZERO:
					if (k > kMax or i >= numSamples-1){
						s = GOT_ZERO;
						zeroCount++;
						
					}
					else if(input == 0){
						i++;
						k++;
					}
					else if(input == 1){
						s = GOT_ONE;
						k = 0;
						i++; 
					}
					else{
						return -1;
					}
					break;

				case GOT_ZERO:
					if(input == 0){
						i++;
					}
					else if(input == 1){
						s = GOT_KTH_ONE;
						k = 0;
						
					}
					else{
						return -1;
					}
					break;

				case GOT_KTH_ONE: 
					if(k > kMax or i >= numSamples-1){
						s = GOT_ONE; 
						oneCount++;
						k = 0; 
					}
					else if (input == 1){
						i++;
						k++; 
					}
					else if (input == 0){ 
						s = GOT_ZERO;
						i++;
					}
					else{
						return -1; 
					}
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

		case GOT_KTH_ONE:
			return -1;
			break;

		case GOT_KTH_ZERO:
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
/*
int main(){

	int zeroOneData[10] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
	int numSamples = 10;
	int kMax = 0;

	int zeroCount = 0;
	int oneCount = 0;

	countZerosAndOnes(zeroOneData, numSamples, kMax, zeroCount, oneCount);
	
	cout << zeroCount << endl;
	cout << oneCount << endl;

	return 0;
}
*/