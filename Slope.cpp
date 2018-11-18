
#include <iostream>
#include <math.h>
#include <cstdlib> 


using namespace std; //using the standard namespace (like human lastnames) the compiler knows what name is from 

int main(const int argc, const char* const argv[]) { // argc: argument count argv: argument value
    int rc = 0; //use meaningful variable names 
    cout << "argc is: " << argc << endl;// command line arguments are an array
    cout << "argv[0] is: " << argv[0] << endl; // the first (0th) argument in the array is the name of the program
    
    if (argc < 5) {
        cerr << argv[0] << " usage error: expected 4 arguments; received " << argc -1 << "; exiting" << endl; //output error message
        return -1;
    }
    
    if (argc > 5) {
        cerr << argv[0] << " usage warning: expected 4 arguments; received " << argc -1 << " ignoring extra arguments;" << endl; //output warning message
        rc = 1;
    }
    
    float x1 = atof(argv[1]); //atof: ascii to float
    float y1 = atof(argv[2]);
    float x2 = atof(argv[3]);
    float y2 = atof(argv[4]);

    // what about if its the same point?
    // floats are infinitely long so you need to approximate 
    if ((fabs(x2-x1) < x1 * 0.01) and (fabs(y2-y1) < y1 * 0.01)){
        cerr << argv[0] << " usage error: The points (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") are within 0.001 of each other; no slope computed" << endl;
        return -1;
    }
    
    float slope = (y2-y1)/(x2-x1);


    cout << "The slope of (" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ") is " << slope << endl; // output string, output variable, output string .. etc
    //processor is much faster than the monitor, so it will output into a buffer and the monitor will check this and update later
    //the program is faster so using cout to output error messages might not show up, that is why cerr is used to output errors ALWAYS

    return rc;
}