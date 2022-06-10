#include<iostream>
#include<string>
#include"IOInterface.h"
using namespace std;

IOInterface::IOInterface(){//����Ʈ ������
    m_name = " ";
	m_data = 0;
	cout << "IOInterface�� ����Ʈ ������ ȣ���\n\n";
}

IOInterface::IOInterface(string m_name) { //�����ִ� ������
	this->m_name = m_name;
	cout << "IOInterface�� �����ִ� ������ ȣ���\n\n";
}

IOInterface::~IOInterface() { // �Ҹ���
		cout << "IOInterface�� �Ҹ��� ȣ���\n\n";
}

void IOInterface::InputValue(string& str) // ���ڿ� �Է��� ���� �Լ�
{
   getline(cin, str);
}

void IOInterface::InputValue(int& i) // ���� �Է��� ���� �Լ�
{
   cin >> i;
   cin.ignore(); // ���� ����
}

void IOInterface::InputData(string &m_name,int &m_data) { //�̸��� data�� �Է��ϴ� �Լ�
	printf("�̸� �Է� : ");
	InputValue(m_name);
	printf("Data �Է� : ");
	InputValue(m_name);
}

void IOInterface::PrintData(){ //�̸��� data�� ����ϴ� �Լ�
	printf("�̸� : ");
	InputValue(m_name);
	printf("Data : ");
	InputValue(m_name);
}

void IOInterface::Modify(string &m_name,int &m_data) { //�Է� �Ǿ��ִ� �̸��� data�� �����ϴ� �Լ�
	printf("���� �� �̸��� �Է��ϼ��� : ");
	getline(cin,m_name);
	printf("���� �� �����͸� �Է��ϼ��� : ");
	cin >> m_data;
}

string IOInterface::GetName() const {
	return m_name;
}
int IOInterface::GetData() const {
	return m_data;
}


