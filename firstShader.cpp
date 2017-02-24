#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

// Dot Product Function
float mydot(vector<float> a, vector<float> b){
	float un = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
	return un;
}


// Intersect Function
float littleIntersect(vector<float> o, vector<float> d){
	float a  = mydot(d,d);
	float b = 2.0f * mydot(o,d);
	float c = mydot(o,o) - 1.0f;
	// Discriminant of quadratic equation... 
	float discrim = b*b - 4.0f*a*c;
	if(discrim >= 0.f){
		// Quadratic equation 
		return 1.f;
	}
	else{
		return 0.f;	
	}
}


int main(){

// init image
vector<float> image(1023*1024 + 1023);

function<float(int)> coord = [](int i){return -1.2f + i*(1.2f/512.f);};

for (int i = 0; i < 1024; i++){
	for (int j = 0; j < 1024; j++){
		// Set X and Y
		float x = coord(i);
		float y = coord(j);
		// Image is a float now; but will later be turned into an int 
		image[i*1024 + j] = 250.f*littleIntersect( vector<float>{x,y,-1},vector<float>{0,0,1});

	}
}

// Print the file in PPM format... 
printf("P3\n 1024 1024 \n255\n");
    for (float v : image){
        printf("%i %i %i\n", (int) v, (int) v, (int) v);
    }


}


