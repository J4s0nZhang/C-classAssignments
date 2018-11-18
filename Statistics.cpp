#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(const int argc, const char* argv[] ){
	int rc = 0;

	if(argc < 2){
		cerr << "Error: Unable to compute statistics over data set because ..." << endl;
		return -1;
	}

	int count = 1;
	float maximum = 0;
	float minimum = 0;
	float sum = 0.0;
	int processed = 0;
	float volt = atof(argv[count]);

	while( volt >= 0 ){ //READ THE DOCUMENTS BEFORE STARTING TO CODE.. CAREFULLY
		
		if( volt <= 0 or volt >= 150){
			cout << "Warning: invalid voltage reading " << volt << " ignored in calculation" << endl;
			rc = 1;
		}
		else{

			if (volt > maximum or maximum == 0)
				maximum = volt;

			if (volt < minimum or minimum == 0)
				minimum = volt;

			sum += volt;
			processed++;

		}
		volt = atof(argv[++count]); //++count adds then increments, previous problem was that it added the first value twice, since count++ updates after
		
	}

	if(processed < 1){
		cerr << "Error: Unable to compute statistics over data set because ..." << endl;
		return -1;
	}

	float average = (sum)/(processed);

	cout << "Number of voltage readings: " << processed << endl;
	cout << "Minimum voltage: " << minimum << endl;
	cout << "Average voltage: " << average << endl;
	cout << "Maximum voltage: " << maximum << endl;

	return rc;
}