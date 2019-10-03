/*
In Bitmap file, y is numbered from bottom to top
so 0 is at bottom and top is the maxm m_height of m_bitmap file
*/

#include<iostream>

//#include "Zoom.h"
#include "FractalCreator.h"
#include "RGB.h"

using namespace std;
using namespace yash;

int main(){
	/*int const m_width = 800;
	int const m_height = 600;*/
	//int height = 600;
	FractalCreator fractalCreator(800,600);

	fractalCreator.addRange(0.0,RGB(0,0,0));
	fractalCreator.addRange(0.3,RGB(255,0,0));
	fractalCreator.addRange(0.5,RGB(255,255,0));
	fractalCreator.addRange(1.0,RGB(255,255,255));
	
	//cout<<fractalCreator.getRange(200)<<endl;

	fractalCreator.addZoom(Zoom(295,202,0.1));
	fractalCreator.addZoom(Zoom(312,304,0.1));
	/*fractalCreator.addZoom(Zoom(295,height-202,0.1));
	fractalCreator.addZoom(Zoom(312,height-304,0.1));
	fractalCreator.calculateIteration();
	fractalCreator.calculateTotalIterations();
	fractalCreator.drawFractal();
	fractalCreator.writeBitmap("test.bmp");*/
	fractalCreator.run("test.bmp");
	cout<<"Finished."<<endl;
	return 0;

	//Bitmap m_bitmap(m_width,m_height);

	/*for(int y = 0; y < m_height; y++){
		for(int x = 0; x < m_width; x++){
			m_bitmap.setPixel(x,y,rand()%20,rand()%20,rand()%20);
		}SSS
	}*/
	/*double min = 999999;
	double max = -999999;*/

	//ZoomList m_zoomList(m_width,m_height);
	/*m_zoomList.add(Zoom(m_width/2,m_height/2,4.0/m_width));
	m_zoomList.add(Zoom(295,m_height-202,0.1));
	m_zoomList.add(Zoom(312,m_height-304,0.1));*/

	//unique_ptr<int[]> m_histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{0});//It will store the number of pixels that corresponds to each particular iteration
	/*unique_ptr<int[]> m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});//to get rid of last entry in m_histogram which can make image very pixelated
	unique_ptr<int[]> m_fractal(new int[m_width*m_height]{0});//to store no. of iterations per pixel*/

	/*for(int y = 0; y < m_height; y++){
		for(int x = 0; x < m_width; x++){
			//double xFractal = (x - m_width/2 - 200) * (2.0/m_width);
			//double yFractal = (y - m_height/2) * (2.0/m_height);

			pair<double,double> coords = m_zoomList.doZoom(x,y);



			//if(xFractal < min) min = xFractal;
			//if(xFractal > max) max = xFractal;

			int iterations = Mandelbrot::getIterations(coords.first,coords.second);
			
			m_fractal[y*m_width+x] = iterations;

			//HISTOGRAM COLORING
			if(iterations != Mandelbrot::MAX_ITERATIONS){
				m_histogram[iterations]++;
			}

			uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

			color = color * color * color;

			m_bitmap.setPixel(x,y,0,color,0);

			if(color < min) min = color;
			if(color > max) max = color;
		}
	}

	int total=0;
	for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++){
		total += m_histogram[i];
	}

	for(int y = 0; y < m_height; y++){
		for(int x = 0; x < m_width; x++){

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;
			
			int iterations = m_fractal[y*m_width+x];

			if(iterations != Mandelbrot::MAX_ITERATIONS){
				//uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

				double hue=0.0;
				
				for(int i=0; i <= iterations; i++){
					hue += ((double)m_histogram[i])/total;
				}

				green = hue * 255;// less than 255
			}
			m_bitmap.setPixel(x,y,red,green,blue);

			color = color * color * color;

			m_bitmap.setPixel(x,y,0,color,0);

			if(color < min) min = color;
			if(color > max) max = color;
		}
	}

	/*cout<<endl;

	int count = 0;
	for(int i=0; i< Mandelbrot::MAX_ITERATIONS; i++){
		cout<<m_histogram[i]<<" "<<flush;
		count += m_histogram[i];
	}

	cout<<count<<"; " << m_width*m_height << endl;

 
	cout<<endl;

	cout<<min<<","<<max<<endl;*/
}