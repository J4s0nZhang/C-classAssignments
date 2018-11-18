
#include <iostream>
#include <math.h>
#include <cstdlib> 


using namespace std; //using the standard namespace (like human lastnames) the compiler knows what name is from 

int main(const int argc, const char* const argv[]) { // argc: argument count argv: argument value
    int rc = 0; //use meaningful variable names 
    
    if (argc < 7) {
        cerr << argv[0] << "Error: expected 6 arguments; received " << argc -1 << "; exiting" << endl; //output error message
        return -1;
    }
    
    if (argc > 7) {
        cerr << argv[0] << "Warning: expected 6 arguments; received " << argc -1 << " ignoring extaneous arguments;" << endl; //output warning message
        rc = 1;
    }
    
    float x1 = atof(argv[1]); //atof: ascii to float
    float y1 = atof(argv[2]);
    float x2 = atof(argv[3]);
    float y2 = atof(argv[4]);
    float x3 = atof(argv[5]);
    float y3 = atof(argv[6]);

    // what about if its the same point?
    // floats are infinitely long so you need to approximate 
    if ((((fabs(x2-x1) < x1 * 0.01) and (fabs(y2-y1) < y1 * 0.01)) or ((fabs(x3-x1) < x3 * 0.01) and (fabs(y3-y1) < y3 *0.01)) or ((fabs(y3-y2) < y3 * 0.01) and (fabs(x3-x2)< x3 * 0.01)))){
        cerr << argv[0] << " usage error: The points (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") are within 0.01 of each other; no slope computed" << endl;
        return -1;
    }
    
    float s1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    float s2 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    float s3 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    float s = 0.5 * (s1 + s2 + s3);
    
    float area = sqrt(s*(s - s1)*(s- s2)*(s-s3));


    cout << "The area of the triangle formed by points (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: "<< area << endl; // output string, output variable, output string .. etc
    //processor is much faster than the monitor, so it will output into a buffer and the monitor will check this and update later
    //the program is faster so using cout to output error messages might not show up, that is why cerr is used to output errors ALWAYS

    return rc;
}