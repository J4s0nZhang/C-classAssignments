#include <iostream> 
#include <cstdlib>
#include<math.h>

using namespace std;

float projectileDestination(const float initialHeight, const float initialVelocity, const float mass, const float initialAngle){
	float distance = 0;
	if (mass <= 0 or initialVelocity <=0 or initialHeight <=0 or initialAngle <= -90 or initialAngle >= 90){
		return NAN;
	}
	float Angle = (initialAngle*M_PI)/180;

	float vx = initialVelocity*cos(Angle);
	float vy = initialVelocity*sin(Angle);
	float g = -9.8;
	
	float discriminant = (vy)*(vy) - 4*(g/2)*(initialHeight);

	float root1 = (-1*(vy)+ sqrt(discriminant))/(g);
	float root2 = (-1*(vy)- sqrt(discriminant))/(g);
	float t = 0;

	if(root1 <= 0){
		t = root2;
	}
	else{
		t = root1;
	}
	distance = vx * t;

	return distance;
}
