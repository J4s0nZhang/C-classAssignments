#include <iostream> 
#include <math.h>

using namespace std;

float projectileDestinationWithDrag(const float initialHeight,const float initialVelocity,const float mass,const float initialAngle,const float k,const float deltaT){
	

	if (mass <= 0 or initialVelocity <=0 or initialHeight <=0 or initialAngle <= -90 or initialAngle >= 90){
		return NAN;
	}
	float angle = initialAngle*M_PI/180;
	float drag = -1*k*initialVelocity*initialVelocity;
	float fg = -9.8*mass;
	float fdx = drag*cos(angle);
	float fdy = drag*sin(angle);

	float xa = fdx/mass;
	float ya = (fg+fdy)/mass;
	float vx = initialVelocity*cos(angle);
	float vy = initialVelocity*sin(angle);
	float v = 0;

	float h = initialHeight + vy*deltaT + (ya/2)*deltaT;
	float dx = vx*deltaT + (xa/2)*deltaT*deltaT;

	while (!(h <= 0)){
		vx += xa*deltaT;
		vy += ya*deltaT;

		v = sqrt(vx*vx + vy*vy);
		drag = -1*k*v*v;

		angle = atan(vy/vx);

		fdx = drag*cos(angle);
		fdy = drag*sin(angle);

		xa = fdx/mass;
		ya = (fg+fdy)/mass;

		h += vy*deltaT + (ya/2)*deltaT*deltaT;
		dx += vx*deltaT + (xa/2)*deltaT*deltaT;

	}

	return dx;
}
