#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here

// ---------- Complex op Complex (member) ----------
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(
		real*c.real - imag*c.imag,
		real*c.imag + imag*c.real
	);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double d = c.real*c.real + c.imag*c.imag;
	return ComplexNumber(
		(real*c.real + imag*c.imag)/d,
		(imag*c.real - real*c.imag)/d
	);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	return real == c.real && imag == c.imag;
}

// ---------- abs & angle ----------
double ComplexNumber::abs(){
	return sqrt(real*real + imag*imag);
}

double ComplexNumber::angle(){
	const double PI = acos(-1.0);
	return atan2(imag, real) * 180.0 / PI;   // องศา
}

// ---------- double on LEFT (non-member) ----------
ComplexNumber operator+(double x, const ComplexNumber &c){
	// x + (a+bi) = (x,0) + (a,bi)
	return ComplexNumber(x,0) + c;
}

ComplexNumber operator-(double x, const ComplexNumber &c){
	return ComplexNumber(x,0) - c;
}

ComplexNumber operator*(double x, const ComplexNumber &c){
	// scalar * complex = (x,0) * complex
	return ComplexNumber(x,0) * c;
}

ComplexNumber operator/(double x, const ComplexNumber &c){
	return ComplexNumber(x,0) / c;
}

bool operator==(double x, const ComplexNumber &c){
	return ComplexNumber(x,0) == c;
}

// ---------- operator<< ----------
ostream& operator<<(ostream& os, const ComplexNumber& c){
	if(c.real == 0 && c.imag == 0){
		os << 0;
	}
	else if(c.imag == 0){
		os << c.real;
	}
	else if(c.real == 0){
		os << c.imag << "i";
	}
	else{
		os << c.real;
		if(c.imag > 0) os << "+";
		os << c.imag << "i";
	}
	return os;
}