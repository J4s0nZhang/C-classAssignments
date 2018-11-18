#include <iostream>
#include <math.h>
#include <cstdlib> 

using namespace std;

int main(const int argc, const char* argv[]){
    int rc = 0;

    if (argc < 7) {
        cerr << "Error: Expected 6 arguments; received " << argc-1 << "; exiting" << endl; //output error message
        return -1;
    }
    
    if (argc > 7) {
        cerr << "Warning: Expected 6 arguments; received " << argc -1 << "; ignoring extraneous arguments" << endl; //output warning message
        rc = 1;
    }

    float x1 = atof(argv[1]); //atof: ascii to float
    float y1 = atof(argv[2]);
    float x2 = atof(argv[3]);
    float y2 = atof(argv[4]);
    float x3 = atof(argv[5]);
    float y3 = atof(argv[6]);

    float s1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    float s2 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    float s3 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    float s = 0.5 * (s1 + s2 + s3);


    if ((fabs(s1-0.0f) <  0.01) or (fabs(s2-0.0f) < 0.01) or (fabs(s3-0.0f) <  0.01)){
        if ((fabs(s1-0.0f) < 0.01) and (fabs(s2-0.0f) < 0.01) and (fabs(s3-0.0f) <  0.01)){
            cerr << "The points (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") overlap; they do not form a triangle" << endl;
            return -1;
        }
        else if ((fabs(x2-x1) < x2* 0.01) and (fabs(y2-y1) < y2*0.01)){
            float slope = ((y2-y1)/(x2-x1));
            cerr << "The points (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") form a line with slope: " << slope << endl;
            return -1;
        }   
        else{
            float slope = ((y3-y2)/(x3-x2));
            cerr << "The points (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") form a line with slope: " << slope << endl;
            return -1;
        }

    }

    float slopeAB = ((y2-y1)/(x2-x1));
    float slopeBC = ((y3-y2)/(x3-x2));

    if (fabs(slopeAB- slopeBC) < slopeAB*0.01){
        cerr << "The points (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") form a line with slope: " << slopeAB << endl;
        return -1;
    }

    float area = sqrt(s*(s - s1)*(s- s2)*(s-s3));


    cout << "The area of the triangle formed by points (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: "<< area << endl; 

    return rc;

}