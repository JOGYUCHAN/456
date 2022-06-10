#include <iostream>
#include <string>

using namespace std;

#ifndef IOINTERFACE_H
#define IOINTERFACE_H

class IOInterface { //기본 클래스인 IOInterface 클래스
protected:
	string m_name;
	int m_data;
public:
	IOInterface();
	IOInterface(string m_name);
	~IOInterface();

	void InputValue(string&);
	void InputValue(int&);

	void InputData(string &m_name,int &m_data);
	void PrintData();
	void Modify(string &m_name,int &m_data);
	string GetName()const;
	int GetData()const;
};

#endif