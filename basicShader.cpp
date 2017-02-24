#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Dot Product Function
float mydot(vector<float> a, vector<float> b){
	float un = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
	
}

// Intersect Function
vector<float> stdIntersect(vector<float> o, vector<float> d){
	float a  = mydot(d,d);
	float b = 2.0f * mydot(o,d);
	float c = mydot(o,o) - 1.0f;
	// Discriminant of quadratic equation... 
	float discrim = b*b - 4.0f*a*c;
	if(discrim >= 0.f){
		// Quadratic equation 
		float t = (-b +  sqrt(discrim) ) / (2.0f*a);
		return vector<float> {o[0] + t*d[0],o[1] + t*d[1],o[2] + t*d[2]}; //o + d * t;
	}
	else{
		return vector<float> {0.f,0.f,0.f}; //intersect failed
	}
}

// Shader Function
float stdShade(vector<float> a, vector<float>b){
	vector<float> n = stdIntersect(a,b);
	vector<float> v = {1.f, 1.f, 2.f};
	if (mydot(n, n)>0){
		return 0.2f + max(0.f,mydot(n, v));
	}
		else{ return 0.f;}
//	return 0.2f + max(0.f, mydot(n, v));
}

int main(){

// init image
vector<float> image(1023*1024 + 1023);

for (int i = 0; i < 1024; i++){
	for (int j = 0; j < 1024; j++){
		// Set X and Y
		float x = -1.2f + i*(1.2f/512.f);
		float y = -1.2f + j*(1.2f/512.f);
		// Image is a float now; but will later be turned into an int 
		image[i*1024 + j] = 90.f*stdShade( vector<float>{x,y,-1},vector<float>{0,0,1});

	}
}

// Print the file in PPM format... 
printf("P3\n 1024 1024 \n255\n");
    for (float v : image){
        printf("%i %i %i\n", (int) v, (int) v, (int) v);
    }


}


