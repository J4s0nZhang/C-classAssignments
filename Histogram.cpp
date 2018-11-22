#include <iostream>
#include <cstdlib>

using namespace std; 

int main(const int argc, const char* argv[]){
	int rc = 0;
	int count = 1;
	int processed = 0;

	if (argc -1 < 2){
		cerr << "Error: Unable to compute histogram over data set because ..." << endl;
		return -1;
	}
	float volt = atof(argv[count]);
	int histogram[10] = {};

	while(volt >= 0){
		if(volt > 0 and volt < 150){
			processed++;
			if(volt < 106){
				histogram[0] += 1;
			}
			else if(volt >= 106 and volt < 109){
				histogram[1] += 1;
			}
			else if(volt >= 109 and volt < 112){
				histogram[2] += 1;
			}
			else if(volt >= 112 and volt < 115){
				histogram[3] += 1;
			}
			else if(volt >= 115 and volt < 118){
				histogram[4] += 1;
			}
			else if(volt >= 118 and volt < 121){
				histogram[5] += 1;
			}
			else if(volt >= 121 and volt < 124){
				histogram[6] += 1;
			}
			else if(volt >= 124 and volt <= 127){
				histogram[7] += 1;
			}
			else if(volt > 127){
				histogram[8] += 1;
			}
		}

		else{
			cout << "Warning: invalid voltage reading " << volt << " ignored in calculation" << endl;
			rc = 1;
			histogram[9] += 1;
		}
		if(++count == argc){
			cerr << "Error: missing terminator" << endl;
			return -1;
		}
		volt = atof(argv[count]);
	}

	if(processed == 0){
		cout << "Error: Unable to compute histogram over data set because ..." << endl;
		return -1;
	}

	cout << "Number of voltage readings: " << processed << endl;
	cout << "Voltage readings (0-106): " << histogram[0] << endl;
	cout << "Voltage readings [106-109): " << histogram[1] << endl;
	cout << "Voltage readings [109-112): " << histogram[2] << endl;
	cout << "Voltage readings [112-115): " << histogram[3] << endl;
	cout << "Voltage readings [115-118): " << histogram[4] << endl;
	cout << "Voltage readings [118-121): " << histogram[5] << endl;
	cout << "Voltage readings [121-124): " << histogram[6] << endl;
	cout << "Voltage readings [124-127]: " << histogram[7] << endl;
	cout << "Voltage readings (127-150): " << histogram[8] << endl;
	cout << "Invalid readings: " << count-processed-1 << endl;

	return rc;
	
}