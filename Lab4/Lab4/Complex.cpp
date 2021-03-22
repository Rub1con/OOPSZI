#include "header.h"

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


Complex sin(const Complex& z)
{
	return Complex(sin(z.getReal()) * cosh(z.getImaginary()), cos(z.getReal()) * sinh(z.getImaginary()));
}