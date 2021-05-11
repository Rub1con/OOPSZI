#pragma once

#include "iostream"

#include "conio.h"

using namespace std;

class Complex

{

	double real, imaginary;

public:

	double getReal() const;

	double getImaginary() const;

	void setReal(double real);

	void setImaginary(double imaginary);

	Complex(double real, double imaginary);

	friend Complex y(const Complex& z);

	friend ostream& operator << (ostream& stream, const Complex& z);

	friend Complex operator +(Complex a, Complex b);

	friend Complex operator -(Complex a, Complex b);

	friend Complex operator *(Complex a, Complex b);

	friend Complex operator /(Complex a, Complex b);

	friend Complex sin(const Complex& z);

	friend Complex sh(const Complex& z);

	friend Complex cos(const Complex& z);

	friend Complex ch(const Complex& z);

	friend Complex exp(const Complex& z);

	friend Complex pow(const Complex& z1, const Complex& z2);

};
