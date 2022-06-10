//2019038055조규찬
#include <iostream>
#include <string>
#include "Student.h"
#include "Subject.h"
#include "IOInterface.h"
using namespace std;

/*
void main() {
	student std;
	cout << std.GetData() << "\n"; // IOInterface Class에서 상속받은 멤버함수 호출
}
*/

// int main() {
// 	Subject sub("컴퓨터", 3, "C");
// 	cout << "-----------------------------\n";
// 	cout<<"m_data : "<<sub.GetData()<<"\n"; //IOInterface Class에서 상속받은 GetData() 호출
// 	cout<<"교과목 이름 : "<<sub.GetName() << "\n"; //subject Class에서 재정의된 GetName() 호츨
// 	cout << "부모 클래스 이름 : " << sub.IOInterface::GetName() << "\n"; //IOInterface Class의 GetName() 호출
// 	cout << "-----------------------------\n\n";
// 	Student std("홍길동", 2013909845, 1, &sub);
// 	cout << "-----------------------------\n";
// 	cout << "m_data : " << std.GetData() << "\n";//IOInterface Class에서 상속받은 GetData() 호출;
// 	cout << "학생 이름 : " << std.GetName() << "\n";//Student Class에서 재정의된 GetName() 호츨;
// 	cout << "부모 클래스 이름 : " << std.IOInterface::GetName() << "\n";//IOInterface Class의 GetName() 호출;
// 	cout << "-----------------------------\n\n";
// 	return 0;
// }


int main() {
	Subject sub("컴퓨터", 3, "C");
	Student std("홍길동", 20138342, 1, &sub);
	std.PrintData();
	std.Modify(); // Student Class의 멤버변수 값 수정
	std.PrintData();

	return 0;
}