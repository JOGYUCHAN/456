#include<iostream>
#include<string>
#include"IOInterface.h"
using namespace std;

IOInterface::IOInterface(){//디폴트 생성자
    m_name = " ";
	m_data = 0;
	cout << "IOInterface의 디폴트 생성자 호출됨\n\n";
}

IOInterface::IOInterface(string m_name) { //인자있는 생성자
	this->m_name = m_name;
	cout << "IOInterface의 인자있는 생성자 호출됨\n\n";
}

IOInterface::~IOInterface() { // 소멸자
		cout << "IOInterface의 소멸자 호출됨\n\n";
}

void IOInterface::InputValue(string& str) // 문자열 입력을 위한 함수
{
   getline(cin, str);
}

void IOInterface::InputValue(int& i) // 정수 입력을 위한 함수
{
   cin >> i;
   cin.ignore(); // 버퍼 비우기
}

void IOInterface::InputData(string &m_name,int &m_data) { //이름과 data를 입력하는 함수
	printf("이름 입력 : ");
	InputValue(m_name);
	printf("Data 입력 : ");
	InputValue(m_name);
}

void IOInterface::PrintData(){ //이름과 data를 출력하는 함수
	printf("이름 : ");
	InputValue(m_name);
	printf("Data : ");
	InputValue(m_name);
}

void IOInterface::Modify(string &m_name,int &m_data) { //입력 되어있는 이름과 data를 수정하는 함수
	printf("수정 할 이름을 입력하세요 : ");
	getline(cin,m_name);
	printf("수정 할 데이터를 입력하세요 : ");
	cin >> m_data;
}

string IOInterface::GetName() const {
	return m_name;
}
int IOInterface::GetData() const {
	return m_data;
}


