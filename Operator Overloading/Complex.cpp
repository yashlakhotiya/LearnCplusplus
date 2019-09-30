#include"Complex.h"
namespace caveofprogramming{

	ostream &operator<<(ostream &out, const Complex& c){
		out<<"("<<c.getReal()<<","<<c.getImaginary()<<")";
		return out;
	}

	const Complex &Complex::operator=(const Complex &other){
		real = other.real;
		imaginary = other.imaginary;
		return *this;
	}

	Complex operator+(const Complex &c1,const Complex &c2){
		return Complex(c1.getReal()+c2.getReal(),c1.getImaginary()+c2.getImaginary());
	}
	
	Complex operator+(const Complex &c1,double d){
		/*double d1 = c1.getReal()+d;
		double d2 = c1.getImaginary();
		return Complex(d1,d2);*/
		return Complex(c1.getReal()+d,c1.getImaginary());
	}

	Complex operator+(double d,const Complex &c1){
		return Complex(c1.getReal()+d,c1.getImaginary());
	}

	Complex Complex::operator*() const{
		return Complex(real,-imaginary);
	}

	bool Complex::operator==(const Complex &other) const{
		if(other.getReal() == real && other.getImaginary() == imaginary) return 1;
		else return 0;
	}
	bool Complex::operator!=(const Complex &other) const{
		if(other.getReal() == real && other.getImaginary() == imaginary) return 0;
		else return 1;
	}

	Complex::Complex(): real(0), imaginary(0){

	}
	Complex::Complex(double real,double imaginary): real(real), imaginary(imaginary){

	}
	Complex::Complex(const Complex &other){
		cout<<"copy"<<endl;
		real = other.real;
		imaginary = other.imaginary;
	}

}