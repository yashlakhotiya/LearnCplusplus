#include "Mandelbrot.h"
#include<complex>
using namespace std;

namespace yash{
	Mandelbrot::Mandelbrot(){

	}
	Mandelbrot::~Mandelbrot(){

	}
	int Mandelbrot::getIterations(double x,double y){
		//the static keyword should only be there in header Mandelbrot.h, not in this Mandelbrot.cpp file at the start of function
		complex<double> z = 0;//overloaded = operator sets both parts to zero
		complex<double> c(x,y);//using constructor of complex class

		int iterations = 0;

		while(iterations < MAX_ITERATIONS){
			z = z*z + c;//Mandelbrot equation
			//these numbers comprise of mandelbrot set
			//abs(z) gets magnitude of complex number z
			if(abs(z) > 2){//if it exceeds 2, and if we kept doing it, if will simply go to infinity
				break;
			}

			iterations++;
		}

		return iterations;
	}
}