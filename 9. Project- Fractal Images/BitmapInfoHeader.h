#ifndef BITMAPINFOHEADEH_H_

#define BITMAPINFOHEADEH_H_

#include<cstdint>

using namespace std;

#pragma pack(2)
namespace yash{
	struct BitmapInfoHeader{
		int32_t headerSize{40};
		//actual size of struct in bytes initialized to 40 bytes by adding up bytes of all the fields
		int32_t width;
		int32_t height;
		//width and height are set later as width and height of actual bitmap
		int16_t planes{1};
		//initialized to 1
		int16_t bitsPerPixel{24};
		//1 byte for each color R G B so 8*3=24
		int32_t compression{0};
		int32_t dataSize{0};
		//Size of data we are going to set to bitmap file
		int32_t horizontalResolution{2400};
		int32_t verticalResolution{2400};
		int32_t colors{0};
		int32_t importantColors{0};
	};
}

#endif