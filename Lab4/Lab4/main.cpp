#include "header.h"
#include <complex>

void main()

{

	setlocale(LC_ALL, "Rus");

	int real, imaginary;

	cout << "Введите \"Комплексное число\" в виде:\n-действительной\n-мнимой\nчастей комплексного числа:\nreal = ";

	cin >> real;

	cout << "imagine = ";

	cin >> imaginary;

	Complex z(real, imaginary);

	Complex z1(real, imaginary);

	real = 3;

	imaginary = 0;

	Complex z2(real, imaginary);

	cout << "z = " << z;
	
	cout << "\ny(z) = 2 * z + sin(z - i)\ny(z) = 2 * ("  << z << ") + (" << sin(z - Complex(0,1)) << ") = " << (Complex(2, 0) * z + sin(z - Complex(0, 1)));

	_getch();

}
