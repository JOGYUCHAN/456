//2019038055������
#include <iostream>
#include <string>
#include "Student.h"
#include "Subject.h"
#include "IOInterface.h"
using namespace std;

/*
void main() {
	student std;
	cout << std.GetData() << "\n"; // IOInterface Class���� ��ӹ��� ����Լ� ȣ��
}
*/

// int main() {
// 	Subject sub("��ǻ��", 3, "C");
// 	cout << "-----------------------------\n";
// 	cout<<"m_data : "<<sub.GetData()<<"\n"; //IOInterface Class���� ��ӹ��� GetData() ȣ��
// 	cout<<"������ �̸� : "<<sub.GetName() << "\n"; //subject Class���� �����ǵ� GetName() ȣ��
// 	cout << "�θ� Ŭ���� �̸� : " << sub.IOInterface::GetName() << "\n"; //IOInterface Class�� GetName() ȣ��
// 	cout << "-----------------------------\n\n";
// 	Student std("ȫ�浿", 2013909845, 1, &sub);
// 	cout << "-----------------------------\n";
// 	cout << "m_data : " << std.GetData() << "\n";//IOInterface Class���� ��ӹ��� GetData() ȣ��;
// 	cout << "�л� �̸� : " << std.GetName() << "\n";//Student Class���� �����ǵ� GetName() ȣ��;
// 	cout << "�θ� Ŭ���� �̸� : " << std.IOInterface::GetName() << "\n";//IOInterface Class�� GetName() ȣ��;
// 	cout << "-----------------------------\n\n";
// 	return 0;
// }


int main() {
	Subject sub("��ǻ��", 3, "C");
	Student std("ȫ�浿", 20138342, 1, &sub);
	std.PrintData();
	std.Modify(); // Student Class�� ������� �� ����
	std.PrintData();

	return 0;
}