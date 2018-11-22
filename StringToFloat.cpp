#include <iostream> 
#include <stdlib.h> 
#include <cmath>
using namespace std; 

enum State {START, GOT_SIGN, GOT_INT, GOT_POINT, GOT_E, GOT_INTDEC, GOT_SIGNEXP, GOT_EXP, DONE};

float stringToFloat (const char input[]){
	State s = START; 
	float num = 0; 
	float sign = 1;
	float signexp = 1;
	int i = 0;
	int numTens = 1;
	int exponent = 0; 
	float final_num = 0;

	while(s != DONE){
		
		switch(s){
			case START:
				if(input[i] <= '9' && input[i] >= '0'){
					s = GOT_INT;
					num = num*10 + (input[i] - '0');
					i++;
					
				}
				else if(input[i] == '+' || input[i] == '-'){
					s = GOT_SIGN;
					if(input[i] == '-'){
						sign = -1;
					}
					i++;
				}
				else if(input[i] == '.'){
					s = GOT_POINT;
					i++;
				}
				else{
					return NAN;
				}
				

				break;

			case GOT_SIGN:
				if(input[i] <= '9' && input[i] >= '0'){
					s = GOT_INT;
					num = (num*10) + (input[i] - '0') ;
					i++;

				}
				else if(input[i] == '.'){
					s = GOT_POINT;
					i++;
				}
				else{
					return NAN;
				}
				break;

			case GOT_INT:
				if(input[i] <= '9' && input[i] >= '0'){
					num = (num*10) + (input[i] - '0');
					i++;
				}
				else if(input[i] == '.'){
					s = GOT_POINT;
					i++;
				}
				else if(input[i] == 'e' || input[i] == 'E'){
					s = GOT_E;
					numTens = 1;
					i++;
				}
				else if (input[i] == '\0'){
					s = DONE;
				}
				else{
					return NAN;
				}
				
				break;

			case GOT_POINT:
				if(input[i] <= '9' && input[i] >= '0'){
					s = GOT_INTDEC;
					num += (input[i]- '0')/pow(10,numTens);
					numTens++;
					i++;
				}
				else if (input[i] == '\0' && i > 1){
					s = DONE;
				}
				
				else{
					return NAN;
				}
				
				break;

			case GOT_INTDEC:
				if(input[i] <= '9' && input[i] >= '0'){
					num += (input[i]- '0')/pow(10,numTens);
					numTens++;
					i++;
				}
				else if(input[i] == 'e' || input[i] == 'E'){
					s = GOT_E;
					numTens = 1;
					i++;
				}
				else if (input[i] == '\0'){
					s = DONE;
				}
				else{
					return NAN;
				}
				break;


			case GOT_E:
				if(input[i] <= '9' && input[i] >= '0'){
					s = GOT_EXP;
					exponent = (exponent*10)+(input[i] - '0');
					i++;
				}
				else if (input[i] == '+' || input[i] == '-'){
					s = GOT_SIGNEXP;
					if(input[i] == '-'){
						signexp = -1;
					}
					i++;
				}
				else{
					return NAN;
				}
				
				break;

			case GOT_SIGNEXP:
				if(input[i] <= '9' && input[i] >= '0'){
					s = GOT_EXP;
					exponent = (exponent*10)+(input[i] - '0');
					i++;
				}

				else{
					return NAN;
				}
				
				break;

			case GOT_EXP:
				if(input[i] <= '9' && input[i] >= '0'){
					exponent = (exponent*10)+(input[i] - '0');
					numTens++;
					i++;
				}
				else if (input[i] == '\0'){
					s = DONE;
				}
				else{
					return NAN;
				}
				
				break;

			case DONE:
				break;

			default: 
				return NAN;
				break;

			
		}
	}

	switch(s) { //check states after
		case GOT_SIGN:
			return NAN;
			break;
								
		case GOT_INT:
			return NAN;
			break;

		case GOT_POINT:
			return NAN;
			break;

		case GOT_E:
			return NAN;
			break;

		case GOT_INTDEC:
			return NAN;
			break;

		case GOT_SIGNEXP:
			return NAN;
			break;

		case GOT_EXP:
			return NAN;
			break;

		case DONE:
			final_num = sign*num*pow(10,signexp*exponent);
			return final_num;
			break;

		case START:
			return NAN;
			break;

		default:
			return NAN;
			break;
	}
	
	return NAN;
}

/*
int main(){
	char input[12] = {'.','\0'};
	float num = stringToFloat(input);
	
	cout << num << endl;


	return 0;
}
*/