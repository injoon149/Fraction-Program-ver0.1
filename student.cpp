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
		//cout << "++f3: " << f3 << endl; // 주석 풀면 11/4 출력
		(*s1).print();
		s1->print();
		//cout << s1; // 주석 풀면 error

		cin >> f4;
		cout << "f4: " << f4 << endl;

		cout << "=============\n";

		list<Fraction> li = { f1, f2, f3, f4 };
		//각 분수들을 내림차순으로 정렬하는 함수(리스트 사용)
		li.sort([](Fraction a, Fraction b) {
			return a.getbunza() / a.getbunmo() > b.getbunza() / b.getbunmo();
			});
		for_each(li.begin(), li.end(), [](const Fraction& n) { cout << n << " "; });
	}
	catch (const MyDivideByException& err) {
		cout << "\n=== 예외정보 ===\n";
		cout << "\n메모리 번지 주소 : " << err.sender;
		cout << "\n예외내용 : " << err.description;
		cout << "\n예외코드 : " << err.info;
		cout << '\n';
	}
	cout << "\n프로그램을 종료합니다\n";
	return 0;
}