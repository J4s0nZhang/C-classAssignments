#include <iostream>
#include <cstdlib>

using namespace std;

int main(const int argc, const char* argv[]){
	int rc = 0;
	int sample = 2;
	int count = 1;

	if(argc < 3 or atof(argv[count]) < 0){
		cerr << "Error: Unable to compute statistics over data set because ..." << endl;
		return -1;
	}

	float alpha = atof(argv[1]);

	if (alpha > 1 or alpha < 0){
		cerr << "Error: invalid alpha input" << endl;
	}

	float volt = atof(argv[sample]);
	float EWMA_C = 0;
	bool first = 1;

	cout << "Sample" << "\t\t" << "Value" << "\t" << "EWMA" << endl;

	while (volt >= 0){

		if (volt <= 0 or volt >= 150){
			cout << "Warning: invalid voltage reading " << volt << " ignored in calculation" << endl;
			rc = 1;
		}
		else {
			
			if(first){
				EWMA_C = volt;
				first = 0;
			}

			EWMA_C = alpha*volt + (1-alpha)*EWMA_C; 
			cout << count << "\t\t" << volt << "\t" << EWMA_C << endl;
		}

		if(sample == argc - 1){
			cerr << "Error: missing terminator" << endl;
			return -1;
		}

		volt = atof(argv[++sample]);
		count++;

	}

	return rc;
}