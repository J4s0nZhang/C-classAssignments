#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(const int argc, const char* argv[]){
	int rc = 0;
	int count = 1;
	int processed = 0;

	if (argc -1 < 2){
		cerr << "Error: Unable to compute standard deviations over data set because ..." << endl;
		return -1;
	}
	float volt = atof(argv[count]);
	float volts[argc-1];

	while(volt >= 0){
		if(volt > 0 and volt < 150){
			volts[processed] = volt;
			processed++;
		}
		else{
			cout << "Warning: invalid voltage reading " << volt << " ignored in calculation" << endl;
			rc = 1;
		}
		if(++count == argc){
			cerr << "Error: missing terminator" << endl;
			return -1;
		}
		volt = atof(argv[count]);
	}

	if(processed == 0){
		cerr << "Error: Unable to compute standard deviations over data set because ..." << endl;
		return -1;
	}

	float avg = 0;
	for(int i = 0; i < processed; i++){
		avg += volts[i];
	}

	avg = avg/processed;

	float sum = 0;
	for(int i = 0; i < processed; i++){
		sum +=pow((volts[i] - avg),2);
	}
	
	if(processed == 1){
		if(sum != 0){
			if(sum < 0){
				float popdev = sqrt(sum/processed);

				cout << "Number of voltage readings: " << count -1<< endl;
				cout << "Population standard deviation: " << popdev << endl;
				cout << "Sample standard deviation: " << "-infinity" << endl;
			}
			else{
				float popdev = sqrt(sum/processed);

				cout << "Number of voltage readings: " << count -1<< endl;
				cout << "Population standard deviation: " << popdev << endl;
				cout << "Sample standard deviation: " << "infinity" << endl;
			}
		}
		else{
			float popdev = sqrt(sum/processed);

			cout << "Number of voltage readings: " << count -1<< endl;
			cout << "Population standard deviation: " << popdev << endl;
			cout << "Sample standard deviation: " << "undefined" << endl;
		}
	}
	else{
		float popdev = sqrt(sum/processed);
		float sampdev = sqrt(sum/(processed-1));

		cout << "Number of voltage readings: " << processed<< endl;
		cout << "Population standard deviation: " << popdev << endl;
		cout << "Sample standard deviation: " << sampdev << endl;
	}
	

	return rc;
}