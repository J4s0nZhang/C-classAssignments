#include <iostream>
#include <stdlib.h> 

using namespace std;

int main(const int argc , const char* argv[]){
	int rc = 0;
	int i = 1;
	int sz = argc-1;
	int processed = 0;

	if (sz < 1){
		cerr << "Error: Unable to compute median over data set because ..." << endl;
		return -1;
	}
	float volts[sz];
	float volt = atof(argv[i]);

	while(volt >= 0 ){
		if (volt <= 0 or volt >= 150){
			cout << "Warning: invalid voltage reading " << volt << " ignored in calculation" << endl;
			rc = 1;
		}
		else{
			volts[processed] = volt;
			processed++;
		}

		if(i == sz){
			cerr << "Error: Missing terminator" << endl;
			return -1;
		}

		volt = atof(argv[++i]);
	}

	if (processed == 0){
		cerr << "Error: Unable to compute median over data set because ..." << endl;
		return -1;
	}

	int somethingChanged = 1;

	while (somethingChanged) {
		somethingChanged = 0;
		int i = 0;
		while (i < processed-1) { //looped for one extra cycle, since i is starting from 0
			if (volts[i] > volts[i+1]) {   
				int tmp;
				tmp = volts[i];
				volts[i] = volts[i+1];
				volts[i+1] = tmp;
				somethingChanged = 1;
			}
			++i;
		}
	}


	float median = 0;

	if (processed % 2 != 0){
		median = volts[processed/2];
	}
	else{
		median = (volts[(processed)/2-1] + volts[(processed/2)])/2;
	}

	cout << "Number of voltage readings: " << processed << endl;
	cout << "Median voltage: " << median << endl;

	return rc;
}