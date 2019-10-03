#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace yash{
	class Mandelbrot{
	public:
		static const int MAX_ITERATIONS = 1000;//MORE ITERATIONS, MORE TIME BUT BETTER QUALITY OF IMAGE
	public:
		Mandelbrot();
		virtual ~Mandelbrot();

		static int getIterations(double x,double y);
	};
}

#endif /*MANDELBROT_H_*/