#include <iostream>
#include <Eigen/Dense>
#include <vector>


using namespace Eigen;
using namespace std;



Vector3f eigenIntersect(Vector3f o, Vector3f d){
	float a = d.dot(d);
	float b = 2.0f * o.dot(d);
	float c = o.dot(o) - 1.0f;

	// solve discriminant equation
	float discrim = b*b - 4.0f*a*c;
	if(discrim >= 0.f){
		float t = (-b + sqrt(discrim)) / (2.0f*a);
		return o + d * t;
	}
	else{
		return Vector3f(0.f,0.f,0.f);
	}

}


float eigenShade(Vector3f o, Vector3f d){
	Vector3f n = eigenIntersect(o,d);
	return 0.2f + 
		max(0.f, n.dot(Vector3f(-1.f,-1.f,2.f)));
	}



int main()

{



vector<float> image(1023*1024 + 1023);

for (int i = 0; i < 1024; i++){
	for (int j = 0; j < 1024; j++){
	
		
		float x = -1.2f + i*(1.2f/512.f);
		float y = -1.2f + j*(1.2f/512.f);

		image[i*1024 + j] =	90.f*eigenShade( Vector3f(x,y,-1),Vector3f(0,0,1));

	}
}




printf("P3\n 1024 1024 \n255\n");
    for (float v : image){
        printf("%i %i %i\n", (int) v, (int) v, (int) v);
    }


}


