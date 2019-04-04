// Proiect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
//using namespace std;

using namespace std;
int a[10], b[10];

int
conversiebz(int x[10])
{
	int i, z = 0;
	for (i = 0; i < 8; i++)
		z = z + x[i] * pow(2, 7 - i);
	return z;
}

void
conversiezb(int z, int q)
{
	int i;
	for (i = 7; i >= 0; i--)
	{
		a[i] = z % 2;
		z /= 2;
	}
	for (i = 7; i >= 0; i--)
	{
		b[i] = q % 2;
		q /= 2;
	}
	cout << "x in binar=" << endl;
	for (i = 0; i < 8; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "y in binar=" << endl;
	for (i = 0; i < 8; i++)
		cout << b[i] << " ";
	cout << endl;
}
void sumator(int x[10], int y[10])
{
	int carryi = 0, carryo = 0, result[10], i;
	for (i = 7; i >= 0; i--)
	{
		if (x[i] + y[i] + carryi == 0)
		{
			result[i] = 0;
			carryo = 0;
		}


		if (x[i] + y[i] + carryi == 1)
		{
			result[i] = 1;
			carryo = 0;
		}


		if (x[i] + y[i] + carryi == 2)
		{
			result[i] = 0;
			carryo = 1;
		}


		if (x[i] + y[i] + carryi > 2)
		{
			result[i] = 1;
			carryo = 1;
		}
		carryi = carryo;
	}
	for (i = 0; i < 8; i++)
		cout << result[i] << " ";
	cout << endl;

}
void scadere(int x[10], int y[10])
{
	int carryi = 0, carryo = 0, result[10], i;
	for (i = 7; i >= 0; i--)
	{

		if (x[i] - y[i] - carryi == 0)
		{
			result[i] = 0;
			carryo = 0;


		}

		if (x[i] - y[i] - carryi == 1)
		{
			result[i] = 1;
			carryo = 0;


		}


		if (x[i] - y[i] - carryi == -1)
		{
			result[i] = 1;
			carryo = 1;


		}
		if (x[i] - y[i] - carryi < -1)
		{
			result[i] = 0;
			carryo = 1;


		}
		carryi = carryo;

	}

	for (i = 0; i < 8; i++)
		cout << result[i] << " ";
	cout << endl;

}
void
band(int x[10], int y[10])
{
	int q[10], i;
	for (i = 0; i < 8; i++)
		if (x[i] == 1 && y[i] == 1)
			q[i] = 1;
		else
			q[i] = 0;
	for (i = 0; i < 8; i++)
		cout << q[i] << " ";
	cout << endl;
}

void
bor(int x[10], int y[10])
{
	int q[10], i;
	for (i = 0; i < 8; i++)
		if (x[i] == 0 && y[i] == 0)
			q[i] = 0;
		else
			q[i] = 1;
	for (i = 0; i < 8; i++)
		cout << q[i] << " ";
	cout << endl;
}

void
bxor(int x[10], int y[10])
{
	int q[10], i;
	for (i = 0; i < 8; i++)
		if (x[i] != y[i])
			q[i] = 1;
		else
			q[i] = 0;
	for (i = 0; i < 8; i++)
		cout << q[i] << " ";
	cout << endl;
}

void
bnot(int x[10])
{
	int q[10], i;
	for (i = 0; i < 8; i++)
		if (x[i] == 0)
			q[i] = 1;
		else
			q[i] = 0;
	for (i = 0; i < 8; i++)
		cout << q[i] << " ";
	cout << endl;
}

int
main()
{
	int x, y, z;
	char c, f;
	cout << "valoare x in zecimal:" << endl;
	cin >> x;
	cout << "valoare y in zecimal:" << endl;
	cin >> y;
	conversiezb(x, y);
	f = 'y';
	while (f == 'y')
	{
		cout << "Alegeti operatie:" << endl;
		cout << "+ - sumator" << endl;
		cout << "- - scadere" << endl;
		cout << "a - and" << endl;
		cout << "o - or" << endl;
		cout << "x - xor" << endl;
		cout << "n - not" << endl;
		cout << "r - reset valori x,y " << endl;
		cin >> c;


		switch (c)
		{
		case '+':
		{
			z = conversiebz(a) + conversiebz(b);
			if (z > 255)
				cout << "x+y=size overflow" << endl;
			else
			{
				sumator(a, b); cout << "valoare in zecimal:" << z << endl;
			}
			break;
		}
		case '-':
		{
			z = conversiebz(a) - conversiebz(b);
			if (z < 0)
				cout << "x-y=size underzero" << endl;
			else
			{
				scadere(a, b);
				cout << "valoare in zecimal:" << z << endl;
			}
			break;
		}
		case 'a':
		{
			cout << "x and y =" << endl;
			band(a, b);
			break;
		}
		case 'o':
		{
			cout << "x or y =" << endl;
			bor(a, b);
			break;
		}
		case 'x':
		{
			cout << "x xor y =" << endl;
			bxor(a, b);
			break;
		}
		case 'n':
		{
			cout << "not x =" << endl;
			bnot(a);
			cout << "not y =" << endl;
			bnot(b);
			break;
		}
		case 'r':
		{
			cout << "valoare x in zecimal:" << endl;
			cin >> x;
			cout << "valoare y in zecimal:" << endl;
			cin >> y;
			conversiezb(x, y);
			break;
		}
		}
		cout << "alta operatie? y/n" << endl;
		cin >> f;
	}
	return 0;
}
