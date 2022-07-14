#pragma once
#pragma once
#include <iostream>
using namespace std;

//예외 클래스 설계
class MyDivideByException
{
public:
	const void* sender;
	const char* description;
	int info;

public:
	MyDivideByException(const void* sender, const char* description, int info)
	{
		this->sender = sender; //예외 객체의 주소
		this->description = description; //예외 메시지
		this->info = info;  //예외 정보(예외 코드)
	}
};



class Fraction
{
private:
	int bunmo;
	int bunza;

public:
	int getbunmo() const
	{
		return bunmo;
	}
	int getbunza() const
	{
		return bunza;
	}
	//기본 생성자(0/1로 설정)
	Fraction()
	{
		this->bunmo = 0;
		this->bunza = 1;
	}
	//매개변수 생성자
	Fraction(int bunza, int bunmo)
	{
		this->bunmo = bunmo;
		this->bunza = bunza;
		this->normalize();

	}
	~Fraction()
	{

	}
	//분수에 전위 증가 연산자 사용하면 분수가 1 올라가는 연산자 오버로딩
	Fraction& operator++()
	{
		bunza += bunmo * 1;
		this->normalize();
		return *this;
	}
	//분수를 입력받을 수 있고, 분수를 출력할 수 있게 하는 연산자 오버로딩
	friend ostream& operator<<(ostream& left, const Fraction& right);
	friend istream& operator>>(istream& left, Fraction& right);
	int gcd(int n, int m)
	{
		int gcd = 1;
		for (int k = 1; k <= n && k <= m; k++)
		{
			if (n % k == 0 && m % k == 0)
			{
				gcd = k;
			}
		}
		return gcd;
	}
	//분수를 약분하는 함수
	void normalize()
	{
		if (bunmo == 0)
		{
			throw MyDivideByException(this, "0으로 나눌 수 없습니다.프로그램을 중단합니다.", 4885);
		}
		if (bunmo < 0)
		{
			bunmo = -bunmo;
			bunza = -bunza;
		}
		int divisor = gcd(abs(bunza), abs(bunmo));
		bunza = bunza / divisor;
		bunmo = bunmo / divisor;
	}
	void* operator new(size_t size)
	{
		size = 100;
		void* adr = new char[size];
		return adr;
	}
	void print2() const
	{
		cout << bunza << "/" << bunmo << endl;
	}

};

ostream& operator<<(ostream& left, const Fraction& right)
{
	left << right.bunza << "/" << right.bunmo;
	return left;
}

istream& operator>>(istream& left, Fraction& right)
{
	cout << "분자 입력: ";
	cin >> right.bunza;
	cout << "분모 입력: ";
	cin >> right.bunmo;
	right.normalize();
	return left;
}


