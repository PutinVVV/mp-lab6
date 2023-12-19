#include "PPolynom.h"
#include <iostream>

int main() {
	char a[]{ '3','+','2','*','5','/','(','1','+','9',')' };
	char* b = Stroka(a);
	for (int i = 0; i < 50; i++)
	{
		cout << b[i];
	}
}