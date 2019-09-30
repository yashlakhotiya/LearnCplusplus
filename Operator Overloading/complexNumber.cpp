#include"Complex.h"
using namespace caveofprogramming;

int main(){
	Complex c1(2,3);
	Complex c2 = c1;

	c1 = c2;

	cout<<c2<<" "<<c1;
	return 0;
}