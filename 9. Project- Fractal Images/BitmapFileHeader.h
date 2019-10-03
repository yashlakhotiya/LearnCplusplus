#ifndef BITMAPFILEHEADER_H_
//ifndef is 'if not defined'
//meaning that if the header BITMAPFILEHEADER_H_ is not defined
//then execute the lines in that block.
//here we are defining the header if not defined
#define BITMAPFILEHEADER_H_

#include<cstdint> //To make sure that integer int is 32 bit

using namespace std;

#pragma pack(2)//preprocessor directivve
//To get rid of C++ padding, because we need to add this struct as it is without extra padding bytes
//So we dont want padding
//to say tell c++ that we dont want padding, we use the above preprocessor directive

namespace yash{
	struct BitmapFileHeader{
		char header[2]{'B','M'};//header initialized to "BM"
		//In C++ 11, we can directly initialize array inside struct
		int32_t fileSize;//we need to make sure that this is 32 bit int so to ensure code portability on difft platforms and difft compilers, its better to do #include<cstdint>
		int32_t reserved{0};//reserved field which is not used. Initialize to 0
		int32_t dataOffset;//Set this later, how long into the file the actual data actually begins
	};
//members of struct are public by default
//members of class are private by defult
//we want to acces the fields without problem
//so we are using struct
}

#endif /* BITMAPFILEHEADER_H_ */