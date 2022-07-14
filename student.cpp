#include "fraction.h"
#include "support.h"
#include <list>
#include <algorithm>
int main() {
	try {
		Fraction f1(7, 9);
		Fraction f2(8, 2);
		Fraction f3(3, 4);
		Fraction f4;
		Support s1 = new Fraction(111, 37);
		cout << "f1: " << f1 << endl;
		cout << "f2: " << f2 << endl;
		cout << "f3: " << f3 << endl;
		++f3;
		cout << "++f3: " << f3 << endl;
		//++f3;
		//cout << "++f3: " << f3 << endl; // �ּ� Ǯ�� 11/4 ���
		(*s1).print();
		s1->print();
		//cout << s1; // �ּ� Ǯ�� error

		cin >> f4;
		cout << "f4: " << f4 << endl;

		cout << "=============\n";

		list<Fraction> li = { f1, f2, f3, f4 };
		//�� �м����� ������������ �����ϴ� �Լ�(����Ʈ ���)
		li.sort([](Fraction a, Fraction b) {
			return a.getbunza() / a.getbunmo() > b.getbunza() / b.getbunmo();
			});
		for_each(li.begin(), li.end(), [](const Fraction& n) { cout << n << " "; });
	}
	catch (const MyDivideByException& err) {
		cout << "\n=== �������� ===\n";
		cout << "\n�޸� ���� �ּ� : " << err.sender;
		cout << "\n���ܳ��� : " << err.description;
		cout << "\n�����ڵ� : " << err.info;
		cout << '\n';
	}
	cout << "\n���α׷��� �����մϴ�\n";
	return 0;
}