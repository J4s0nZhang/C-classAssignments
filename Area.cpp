#include <iostream>
#include <cstdlib>
using namespace std;

extern float f(float x);

int main(const int argc, const char* argv[]){
	int rc = 0;
	float sum = 0;

	if(argc < 3){
		cerr << "Error: Expected 2 arguments; received " << argc -1 << "; exiting" << endl; 
		return -1;
	}
	if(argc > 3){
		cerr << "Warning: Expected 2 arguments; received " << argc -1 << "; ignoring extraneous arguments" << endl; 
		rc = 1;
	}

	const float A = atof(argv[1]);
	const float B = atof(argv[2]);


	if ( B < A ){
		cerr << "Error: B is less than A, the area is negative" << endl;
		return -1;
	}

	float x = A; 
	float dx = 0.01;
	float area = 0;

	while (x < B){
		area = (dx/2)*(f(x+dx) + f(x));
		sum += area;
		x += dx;
	}

	if(sum == 0){
		cerr << "Warning: A and B are the same value" << endl;
		rc = 1;
	}

	cout << "The area under f(x) from " << A << " to " << B << " is " << sum << endl; 
	return rc;
}