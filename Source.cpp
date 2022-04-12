#include "Set.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Set A, B, C, D, E;
	int a, b;

	A.Read();
	B.Read();

	C = Union(A, B);
	cout << " A and B union : " << endl;
	C.Display();
	cout << endl;

	D = Intersection(A, B);
	cout << " A and B intersection : " << endl;
	D.Display();
	cout << endl;

	E = Substraction(A, B);
	cout << " A and B substraction  : " << endl;
	E.Display();
	cout << endl;

	cout << "enter how much should be the shift to the left (A)" << endl;
	cin >> a;
	A.ShiftLeft(a);
	A.Display();
	cout << endl;


	cout << "enter how much should be the shift to the right (B)" << endl;
	cin >> b;
	B.ShiftRight(b);
	B.Display();
	cout << endl;


	cout << "enter on whick position bit in A should be included" << endl;
	cin >> a;
	A.Include(a);
	A.Display();
	cout << endl;


	cout << "enter on whick position bit in B should be excluded" << endl;
	cin >> b;
	B.Exclude(b);
	B.Display();
	cout << endl;


	cout << "and lets count sum of ones : " << endl;
	cout << "in A there are " << A.Count() << " ones" << endl;
	cout << "in B there are " << B.Count() << " ones" << endl;
	cout << endl;


	cout << "woow!... okay so now lets do NOT for A and B :" << endl;
	A.Not();
	cout << "A :" << endl;
	A.Display();
	cout << endl;

	B.Not();
	cout << "B :" << endl;
	B.Display();
	cout << endl;

	cout << "And finally lets test function ToString " << endl << endl;
	cout << A.toString() << endl;
	cout << B.toString() << endl;

}