#include <iostream>
#include <cstdlib>

using namespace std;

extern float f(float t);

int main(const int argc, const char* argv[]){
	int rc = 0;

	if (argc < 2){
		cerr << "Error: Expected 1 arguments; received " << argc-1 << "; exiting" << endl;
		return -1;
	}

	if (argc > 2){
		cerr << "Error: Expected 1 arguments; received " << argc -1 << "; ignoring extraneous arguments" << endl;
		rc = 1;
	}

	float t = atof(argv[1]);

	float y1 = f(t-0.0001);
	float y2 = f(t+0.0001);

	float slope = (y2-y1)/(0.0002);

	cout << "The slope of f(t) at t = " << t << " is " << slope << endl;

	return rc;
}