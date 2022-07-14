#pragma once
#include "fraction.h"

class Support
{
private:
	Fraction* fraction;

public:
	Support(Fraction* f) : fraction(f) {

	}
	const Support* operator->() const
	{
		return this;
	}
	const Support& operator*() const
	{
		return *this;
	}
	~Support()
	{
		delete fraction;
	}
	void print() const
	{
		cout << "s1: ";
		fraction->print2();
	}
};