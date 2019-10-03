#ifndef BITMAP_H_
#define BITMAP_H_

#include<memory>
#include<string>
#include<cstdint>//to use uint8_t (it is same as char)
using namespace std;

namespace yash{
	class Bitmap{
	private:
		int m_width{0};//MEMBER WIDTH
		int m_height{0};//MEMBER HEIGHT
		unique_ptr<uint8_t[]> m_pPixels{nullptr};
		//initialized to null ptr
		//We are using unique_ptr to get rid of the deletion of memory pointed by the pointer in destructor
		//It will automaticll do the work for us
	public:
		Bitmap(int width,int height);
		bool write(string filename);
		//false if doesnt succedd and true if it successfully writes to file
		void setPixel(int x,int y,uint8_t red, uint8_t green, uint8_t blue);
		virtual ~Bitmap();
	};
}

#endif /* BITMAP_H_ */