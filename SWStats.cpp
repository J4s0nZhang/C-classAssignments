#include <iostream>
#include <cstdlib>

using namespace std;

int main(const int argc, const char* argv[]){
	int rc = 0;
	int count = 2;

	if (argc < 3 or atof(argv[count]) < 0){
		cerr << "Error: Expected 3 or more arguments; received " << argc-1 << "; exiting" << endl;
		return -1;
	}

	int windowsize = atoi(argv[1]);
	float volt = atof(argv[count]);

	if(windowsize < 1){
		cerr << "Error: Invalid window size; exiting" << endl;
		return -1;
	}
	float voltemp = 0.0;
	float max = 0.0;
	float min = 150.0;

	cout << "Window Size: " << windowsize << endl;
	cout << "Sample" << "\t\t" << "Value" << "\t" << "SWMinimum" << "\t" << "SWMaximum" << endl;

	while (volt >= 0){
		if (volt == 0 or volt >= 150){
			cout << "Warning: invalid voltage reading " << volt << " ignored in calculation" << endl;
			rc = 1;
		}
		else {
			voltemp = atof(argv[count]);
			for(int step = 0; step < windowsize; step++){
				if (not(count - step < 2) ){
					voltemp = atof(argv[count-step]);
					if (not(voltemp == 0 or voltemp >= 150)){
						if (voltemp > max)
							max = voltemp;
						
						if (voltemp < min)
							min = voltemp;
						
					}
				}
			}

			cout << count-1 << "\t\t" << volt << "\t" << min << "\t" << max << endl;
			max = 0.0;
			min = 150.0;
		}
		


		if(count == argc - 1){
			cerr << "Error: missing terminator" << endl;
			return -1;
		}

		volt = atof(argv[++count]);
		
	}
	return rc;
}