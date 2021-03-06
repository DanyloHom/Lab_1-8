#pragma once
#include <iostream>
#include <string>

using namespace std;

class Set
{
public:
	class BitString
	{
	private:

		unsigned long first;
		unsigned long second;

	public:

		unsigned long getFirst()const { return first; }
		unsigned long getSecond()const { return second; }

		void setFirst(unsigned long f) { first = f; }
		void setSecond(unsigned long s) { second = s; }

		void Read();
		void Display();
		void Init(unsigned long l, unsigned long r);
		string toString();

		void Not();
		friend BitString And(BitString l, BitString r);
		friend BitString Or(BitString l, BitString r);
		friend BitString XOr(BitString l, BitString r);

		void ShiftLeft(int pos);
		void ShiftRight(int pos);

	};
private:
	BitString a;

public:
	

	unsigned long getFirst()const { return a.getFirst(); }
	unsigned long getSecond()const { return a.getSecond(); }

	BitString getA()const { return a; }
	void setA(unsigned long l, unsigned long r);

	void Read();
	void Display();
	void Init(unsigned long l, unsigned long r);
	string toString();

	void Exclude(int pos);
	void Include(int pos);
	int Count();
	friend Set Union(Set l, Set r); //obyednannya
	friend Set Intersection(Set l, Set r); //peretyn
	friend Set Substraction(Set l, Set r); //riznycya

	void ShiftLeft(int pos);
	void ShiftRight(int pos);

	void Not();
};



