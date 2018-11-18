#include <iostream>
#include <cstdlib>

using namespace std;

int main(const int argc, const char* argv[]){
	int rc = 0;
	int count = 1;
	if(argc < 2 or atof(argv[count]) < 0){
		cerr << "Error: Unable to compute statistics over data set because ..." << endl;
		return -1;
	}

	int processed = 0;
	float maximum = 1;
	float minimum = 150;
	float sum = 0;
	float average = 0;
	float volt = atof(argv[count]);

	cout << "Sample" << "\t\t" << "Value" << "\t" <<"Minimum" << "\t" << "Average" << "\t" << "Maximum" << endl;

	while( volt >= 0){
		
		if (volt <= 0 or volt >= 150){
			cout << "Warning: invalid voltage reading " << volt << " ignored in calculation" << endl;
			rc = 1;
		}
		else{
			sum += volt;
			if (volt > maximum){
				maximum = volt;
			}
			if (volt < minimum){
				minimum = volt;
			}

			processed++;

			average = sum/processed; 
			cout << count << "\t\t" << volt << "\t" << minimum << "\t" <<  average << "\t" << maximum << endl;

		}
		++count;

		if (count == argc){
			cerr << "Error: missing terminator" << endl;
			return -1;
		}
		volt = atof(argv[count]);
	}
	if (processed == 0){
		cerr << "Error: Unable to compute statistics over data set because ..." << endl;
		return -1;
	}


}