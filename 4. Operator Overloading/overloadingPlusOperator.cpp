#include"Complex.h"

using namespace std;
using namespace caveofprogramming;

int main(){
	Complex c1(3,4);
	Complex c2(4,5);
	Complex c3 = c1+c2;
	cout<<c1+c2<<endl;
	cout<<c1+c2+c3<<endl;

	Complex c4(4,2);
	Complex c5 = c4+7.0;
	cout<<c5<<endl;
	Complex c6 = 8.0+c4;
	cout<<c6<<endl;
	cout<<8+c1+7+c4<<endl;
	return 0;
}