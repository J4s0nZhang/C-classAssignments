#include <iostream>
#include <math.h>
#include <cstdlib> 

using namespace std;

int main(const int argc, const char* argv[]){
    int rc = 0;

    if (argc < 7) {
        cerr << "Error: expected 6 arguments; received " << argc -1 << "; exiting" << endl; //output error message
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


    float ang1 = acos((s1*s1 + s2*s2 - s3*s3)/(2*s1*s2)); //cosine law to solve for angle
    float ang2 = acos((s2*s2 + s3*s3 - s1*s1)/(2*s2*s3));
    float ang3 = acos((s3*s3 + s1*s1 - s2*s2)/(2*s3*s1));

    float c = 0.0;
    float a = 0.0;
    float b = 0.0;

    char const *angleclass;
    char const *sideclass;

    if((s1 >= s2) && (s1 >= s3)){ //find the longest side
        c = pow(s1,2);
        a = pow(s2,2);
        b = pow(s3,2);
    }
    else if ((s2 >= s1) && (s2 >= s3)){
        c = pow(s2,2);
        a = pow(s1,2);
        b = pow(s3,2);
    }
    else{
        c = pow(s3,2);
        a = pow(s2,2);
        b = pow(s1,2);
    }



    if ((fabs(ang2 - ang1) < ang2 * 0.00001) && (fabs(ang3-ang1) < ang3 * 0.00001) && (fabs(ang3-ang2) < ang3 * 0.00001)){ //if all 3 are the same 
        sideclass = "equilateral"; 
    }
    else if ((fabs(ang2 - ang1) < ang1 * 0.00001) || (fabs(ang3-ang1) < ang3 * 0.0001) || (fabs(ang3-ang2) < ang2 * 0.00001)){ //if any 2 sides are the same 
        sideclass = "isosceles";
    }
    else{
        sideclass = "scalene";
    }


    if (fabs(c-(a+b)) < c *0.0001){
        angleclass = "right";
    }
    else if (c < a+b){
        angleclass = "acute";
    }
    else if (c > a+b){
        angleclass = "obtuse";
    }
    else{
        angleclass = "N/A";
    }

    cout << "The triangle formed by points (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: " << sideclass << " " << angleclass << endl;   

    return rc;
}