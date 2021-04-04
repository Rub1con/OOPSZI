#include "header.h"
#include <complex>

double Complex::getReal() const

{

	return this->real;

}

double Complex::getImaginary() const

{

	return this->imaginary;

}

void Complex::setReal(double real)

{

	this->real = real;

}

void Complex::setImaginary(double imaginary)

{

	this->imaginary = imaginary;

}

Complex::Complex(double real, double imaginary)

	:real(real), imaginary(imaginary) { }

ostream& operator << (ostream& stream, const Complex& z)

{

	if (z.getImaginary() >= 0)

	{

		stream << z.getReal() << "+" << z.getImaginary() << "*i";

	}

	else

	{

		stream << z.getReal() << z.getImaginary() << "*i";

	}

	return stream;

}

Complex operator +(Complex a, Complex b)
{
	return Complex(a.getReal() + b.getReal(), a.getImaginary() + b.getImaginary());
}

Complex operator -(Complex a, Complex b)
{
	return Complex(a.getReal() - b.getReal(), a.getImaginary() - b.getImaginary());
}

Complex operator *(Complex a, Complex b)
{
	return Complex((a.getReal() * b.getReal() - a.getImaginary() * b.getImaginary()), (a.getReal() * b.getImaginary() + a.getImaginary() * b.getReal()));
}

Complex operator /(Complex a, Complex b)
{
	return Complex(((a.getReal() * b.getReal()) - (a.getImaginary() * b.getImaginary() * (-1))) / (pow(b.getReal(), 2) + pow(b.getImaginary(), 2)), ((a.getReal() * b.getImaginary() * (-1)) + (a.getImaginary() * b.getReal())) / (pow(b.getReal(), 2) + pow(b.getImaginary(), 2)));

}


Complex sin(const Complex& z)
{
	return Complex(sin(z.getReal()) * cosh(z.getImaginary()), cos(z.getReal()) * sinh(z.getImaginary()));
}

Complex cos(const Complex& z)
{
	return Complex(cos(z.getReal()) * cosh(z.getImaginary()), sin(z.getReal()) * sinh(z.getImaginary()));
}

Complex exp(const Complex& z)
{
	return Complex(z.getReal() * cos(z.getImaginary()), z.getReal() * sin(z.getImaginary()));
}

Complex cosh(const Complex& z)
{
	return Complex(cosh(z.getReal() * cos(z.getImaginary())), sinh(z.getReal() * sin(z.getImaginary())));
}

Complex sinh(const Complex& z)
{
	return Complex(sinh(z.getReal() * cos(z.getImaginary())), cosh(z.getReal() * sin(z.getImaginary())));
}

Complex pow(const Complex& z1, const Complex& z2) 
{
	double i, j, n;
	n = z2.getReal();
	i = pow(z1.getReal(), n) * cos(n * z1.getImaginary());
	j = pow(z1.getReal(), n) * sin(n * z1.getImaginary());
	Complex result(i, j);
	return result;
}

Complex y(const Complex& z)
{	
	return Complex(2,0) * z + sin(z - Complex(0, 1));
}