#pragma once
#pragma once
#include <iostream>
using namespace std;

//���� Ŭ���� ����
class MyDivideByException
{
public:
	const void* sender;
	const char* description;
	int info;

public:
	MyDivideByException(const void* sender, const char* description, int info)
	{
		this->sender = sender; //���� ��ü�� �ּ�
		this->description = description; //���� �޽���
		this->info = info;  //���� ����(���� �ڵ�)
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
	//�⺻ ������(0/1�� ����)
	Fraction()
	{
		this->bunmo = 0;
		this->bunza = 1;
	}
	//�Ű����� ������
	Fraction(int bunza, int bunmo)
	{
		this->bunmo = bunmo;
		this->bunza = bunza;
		this->normalize();

	}
	~Fraction()
	{

	}
	//�м��� ���� ���� ������ ����ϸ� �м��� 1 �ö󰡴� ������ �����ε�
	Fraction& operator++()
	{
		bunza += bunmo * 1;
		this->normalize();
		return *this;
	}
	//�м��� �Է¹��� �� �ְ�, �м��� ����� �� �ְ� �ϴ� ������ �����ε�
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
	//�м��� ����ϴ� �Լ�
	void normalize()
	{
		if (bunmo == 0)
		{
			throw MyDivideByException(this, "0���� ���� �� �����ϴ�.���α׷��� �ߴ��մϴ�.", 4885);
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
	cout << "���� �Է�: ";
	cin >> right.bunza;
	cout << "�и� �Է�: ";
	cin >> right.bunmo;
	right.normalize();
	return left;
}


