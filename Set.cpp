#include "Set.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

void Set::setA(unsigned long l, unsigned long r)
{
	a.setFirst(l);
	a.setSecond(r);
}

void Set::Read()
{
	a.Read();
}

void Set::Display()
{
	a.Display();
}

void Set::Init(unsigned long l, unsigned long r)
{
	a.Init(l, r);
}

string Set::toString()
{
	return a.toString();
}

void Set::Exclude(int pos)
{

	if (pos <= 32 && pos >= 0) {
		a.setFirst(a.getFirst() & ~(~(~0 << 1) << pos));
	}

	if (pos > 32 && pos <= 64) {
		a.setSecond(a.getSecond() & ~(~(~0 << 1) << pos));
	}

	if (pos < 0 && pos > 62) {
		cout << "wrong argument" << endl;
	}

}

void Set::Include(int pos)
{
	if (pos <= 32 && pos >= 0) {
		a.setFirst(a.getFirst() | ~(~0 << 1) << pos);
	}

	if (pos > 32 && pos <= 64) {
		a.setSecond(a.getSecond() | ~(~0 << 1) << pos);
	}

	if (pos < 0 && pos > 62) {
		cout << "wrong argument" << endl;
	}
}

int Set::Count()
{
	int count = 0;
	unsigned long l = a.getFirst();
	unsigned long r = a.getSecond();

	while (l) {             //poky l ne stane 0
		count += l & 1;		//dodayemo do count kzhnu odynychku
		l >>= 1;			//rozglyadaemo nastypnyi bit
	}

	while (r) {				//poky r ne stane 0
		count += r & 1;		//dodayemo do count kzhnu odynychku
		r >>= 1;			//rozglyadaemo nastypnyi bit
	}

	return count;
}

void Set::ShiftLeft(int pos)
{
	a.ShiftLeft(pos);
}

void Set::ShiftRight(int pos)
{
	a.ShiftRight(pos);
}

void Set::Not()
{
	a.Not();
}

Set Union(Set l, Set r)
{
	Set A;
	A.a = Or(l.a, r.a);

	return A;
}

Set Intersection(Set l, Set r)
{
	Set A;
	A.a = And(l.a, r.a);

	return A;
}

Set Substraction(Set l, Set r)
{
	Set A;
	A.a = XOr(l.a, r.a);

	return A;

}

void Set::BitString::Read()
{
	unsigned long l, r;
	cout << "first part = " << endl;
	cin >> l;
	cout << "second part = " << endl;
	cin >> r;
	Init(l, r);
}

void Set::BitString::Display()
{
	cout << "first part = " << first << endl;
	cout << "second part = " << second << endl;
}

void Set::BitString::Init(unsigned long l, unsigned long r)
{
	setFirst(l);
	setSecond(r);
}

string Set::BitString::toString()
{
	stringstream sout;
	sout << "first part = " << first << " ; second part = " << second << " ;" << endl;
	return sout.str();
}

void Set::BitString::Not()
{
	~first;
	~second;
}

void Set::BitString::ShiftLeft(int pos)
{
	unsigned long mask;								//stvoryuemo masku
	mask = second & (~(~0 << pos) << (32 - pos));	//inicializaciya masky( 1 - zapovnyuemo odynycyamy  2 - sunemo na pos, stvoryuemo neobhidnu kilist nuliv  3 - robymo zaperechennya, shchob nuli stalu 1 i navpaky  4 - sunemo napochatok, shchob skopiyuvaty neobhidni bity
	mask >>= (32 - pos);								//sunemo vkinec, shchob mozhna bulo korectno vstavyty u first
	first <<= pos;									//sunemo first
	second <<= pos;									//sunemo second
	first |= mask;									//vstavlyaemo potribni bity v pochatok first
}

void Set::BitString::ShiftRight(int pos)
{
	unsigned long mask;
	mask = first & ~(~0 << pos);					//inicializaciya masky( 1 - zapovnyuemo odynycyamy  2 - sunemo na pos, stvoryuemo neobhidnu kilist nuliv  3 - robymo zaperechennya, shchob nuli stalu 1 i navpaky  4 - vony i tak vkinci
	mask <<= (32 - pos);								///sunemo napochatok, shchob mozhna bulo korectno vstavyty u second
	first >>= pos;									//sunemo first
	second >>= pos;									//sunemo second
	second |= mask;									//vstavlyaemo potribni bity v kinec second
}

Set::BitString And(Set::BitString l, Set::BitString r)
{
	Set::BitString A;
	A.first = l.first & r.first;
	A.second = l.second & r.second;

	return A;
}

Set::BitString Or(Set::BitString l, Set::BitString r)
{
	Set::BitString A;
	A.first = l.first | r.first;
	A.second = l.second | r.second;

	return A;
}

Set::BitString XOr(Set::BitString l, Set::BitString r)
{
	Set::BitString A;
	A.first = l.first ^ r.first;
	A.second = l.second ^ r.second;

	return A;
}

