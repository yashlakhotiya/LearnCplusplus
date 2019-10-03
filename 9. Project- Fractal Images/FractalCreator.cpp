#include "FractalCreator.h"
#include<iostream>
//#include<assert>
using namespace std;

namespace yash{

		void FractalCreator::addRange(double rangeEnd, const RGB& rgb){
			m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
			m_colors.push_back(rgb);

			if(m_bGotFirstRange){
				m_rangeTotals.push_back(0);
			}
			m_bGotFirstRange = true;
		}

		int FractalCreator::getRange(int iterations) const{
			int range = 0;
			for(int i = 1; i < m_ranges.size(); i++){
				range = i;
				if(m_ranges[i] > iterations){
					break;
				}
			}
			range--;//to get 0 based indexing
			//assert(range > -1);
			//assert(range < m_ranges.size());
			return range;
		}

		void FractalCreator::addZoom(const Zoom& zoom){
			m_zoomList.add(zoom);
		}

		void FractalCreator::run(string name){
			calculateIteration();
			calculateTotalIterations();
			calculateRangeTotals();
			drawFractal();
			writeBitmap("test.bmp");
		}
		FractalCreator::FractalCreator(int width, int height): m_width(width), m_height(height), m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}), m_fractal(new int[m_width*m_height]{0}),m_bitmap(m_width,m_height),m_zoomList(m_width,m_height){
			m_zoomList.add(Zoom(m_width/2,m_height/2,4.0/m_width));
		}
		FractalCreator::~FractalCreator(){

		}

		void FractalCreator::calculateIteration(){
			for(int y = 0; y < m_height; y++){
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

					/*uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

					color = color * color * color;

					m_bitmap.setPixel(x,y,0,color,0);

					if(color < min) min = color;
					if(color > max) max = color;*/
				}
			}
		}
		void FractalCreator::calculateRangeTotals(){
			
			int rangeIndex = 0;
			for(int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++){
				int pixels = m_histogram[i];
				if(i >= m_ranges[rangeIndex+1]){
					rangeIndex++;
				}
				m_rangeTotals[rangeIndex] += pixels;
			}

			/*int overallTotal = 0;
			for(int value: m_rangeTotals){
				cout<<"Range total: "<<value<<endl;
				overallTotal += value;
			}

			cout<<"Overall total1: "<<m_total<<endl;*/
		}

		void FractalCreator::calculateTotalIterations(){
			for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++){
				m_total += m_histogram[i];
			}

			//cout<<"Overall total2: "<<m_total<<endl;
		}

		void FractalCreator::drawFractal(){

			RGB startColor(0,0,0);
			RGB endColor(0,0,255);
			RGB colorDiff = endColor - startColor;
			for(int y = 0; y < m_height; y++){
				for(int x = 0; x < m_width; x++){

					int iterations = m_fractal[y*m_width+x];
					int range = getRange(iterations);
					int rangeTotal = m_rangeTotals[range];
					int rangeStart = m_ranges[range];

					RGB& startColor = m_colors[range];
					RGB& endColor = m_colors[range+1];
					RGB colorDiff = endColor-startColor;

					uint8_t red = 0;
					uint8_t green = 0;
					uint8_t blue = 0;

					if(iterations != Mandelbrot::MAX_ITERATIONS){
						//uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);
						int totalPixels = 0;
						//double hue=0.0;
						
						for(int i = rangeStart; i <= iterations; i++){
							totalPixels += m_histogram[i];							//hue += ((double)m_histogram[i])/m_total;
						}

						red = startColor.r + colorDiff.r * (double)totalPixels/rangeTotal;
						green = startColor.g + colorDiff.g * (double)totalPixels/rangeTotal;
						blue = startColor.b + colorDiff.b * (double)totalPixels/rangeTotal;
						//green = hue * 255;// less than 255
						/*red = startColor.r+colorDiff.r * hue;
						green = startColor.g+colorDiff.g*hue;
						blue = startColor.b+colorDiff.b*hue;*/

					}
					m_bitmap.setPixel(x,y,red,green,blue);
				}
			}
		}

		void FractalCreator::writeBitmap(string name){
			m_bitmap.write(name);
		}
}