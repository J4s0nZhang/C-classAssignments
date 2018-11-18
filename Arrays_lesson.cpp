#include <iostream>
using namespace std;

int main(const int argc , const char* argv[]){
	int i = 1;
	float inputData[argc-1];
	while(i < argc) {
		inputData[i-1] =  atof(argv[i]);
		++i;
	}

	//find the min
	int dataQty = argc - 1;
	i = 0;
	float min = FLT_MAX;
	int minLoc = -1;
	while (i < dataQty){
		if (inputData[i] < min)
			min = inputData[i];
			minLoc = i; 
	}
	return 0; 
}