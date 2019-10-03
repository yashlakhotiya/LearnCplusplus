#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Zoom.h"
#include "RGB.h"
#include<cstdint>
#include<memory>
#include<math.h>
#include<string>
#include<vector>

using namespace std;
namespace yash{
	class FractalCreator{
	private:
		int m_width;
		int m_height;
		unique_ptr<int[]> m_histogram;//to get rid of last entry in m_histogram which can make image very pixelated
		unique_ptr<int[]> m_fractal;//to store no. of iterations per pixel
		Bitmap m_bitmap;
		ZoomList m_zoomList;
		int m_total{0};

		vector<int> m_ranges;
		vector<RGB> m_colors;
		vector<int> m_rangeTotals;

		bool m_bGotFirstRange{false};
	private:
		void calculateIteration();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void drawFractal();
		void writeBitmap(string name);
		//int getRange(int iterations) const;

	public:
		void addRange(double rangeEnd, const RGB& rgb);
		int getRange(int iterations) const;
		void addZoom(const Zoom& zoom);
		FractalCreator(int width, int height);
		virtual ~FractalCreator();
		void run(string name);
	};
}

#endif