#include <iostream>
#include <cstdlib>

using namespace std;

int main(const int argc, const char* argv[]){
	int rc = 0;

	if (argc < 2){
		cerr << "Error: Expected 1 arguments; receieved " << argc -1 << "; exiting" << endl;
		return -1;
	}
	if (argc > 2){
		cerr << "Error: Expected 1 arguments; received "<< argc -1 << "; ignoring extraneous arguments" << endl;
		rc = 1;
	}


	float num = atof(argv[1]);

	if (num < 0){
		cerr << "Error: cannot compute square root of a negative number" << endl;
		return -1;
	}

	float prest = num/2;
	float bestest = 1.0;
	float check = 1.0;


	while(check >= 0.00001){

		bestest = (prest + num/prest)/2;
		prest = bestest;
		check = (num - bestest*bestest)/num;
		if( check < 0.0){
			check *= -1;
		}

	}
	cout << "The square root of " << num << " is " << bestest << endl;

	return rc;
}