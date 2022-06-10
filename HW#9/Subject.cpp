#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
#include"Subject.h"
#include"IOInterface.h"
using namespace std;

Subject::Subject():IOInterface() // ����Ʈ ������ ������
{
   m_name = "";
   m_hakjum = 0;
   m_grade = "";
   m_GPA = 0.0;
   cout << "* Subject() ����Ʈ ������ ȣ�� *\n";
}

Subject::Subject(string name, int hakjum, string grade):IOInterface(name) // �����ִ� ������
{
   m_name = name;
   m_hakjum = hakjum;
   m_grade = grade;
   CalcGPA();
   cout << "* Subject �����ִ� ������ ȣ�� *\n";
}
Subject::Subject(const Subject& sub):IOInterface(sub)
{
   this->m_name = sub.m_name;
   this->m_hakjum = sub.m_hakjum;
   this->m_grade = sub.m_grade;
   this->m_GPA = sub.m_GPA;

   cout << "* Subject ��������� ȣ�� *\n";
}
Subject::~Subject()
{
   cout << "Subject �Ҹ��� ȣ��\n";
}

inline void Subject::InputValue(string& str) // ���ڿ� �Է½�
{
   getline(cin, str);
}

inline void Subject::InputValue(int& i) // ���� �Է½�
{
   cin >> i;
   cin.ignore(); // ���� ����ֱ�
}


void Subject::CalcGPA() // �� ������ ���� ����ϱ� ex)3���� * 4.5 = 13.5
{
   if (m_grade == "A+") // string  ��ü�� ���ڿ� �񱳸� ���� GPA�� ���� �� �Ҵ�
      m_GPA = 4.5;
   else if (m_grade == "A0")
      m_GPA = 4.0;
   else if (m_grade == "B+")
      m_GPA = 3.5;
   else if (m_grade == "B0")
      m_GPA = 3.0;
   else if (m_grade == "C+")
      m_GPA = 2.5;
   else if (m_grade == "C0")
      m_GPA = 2.0;
   else if (m_grade == "D+")
      m_GPA = 1.5;
   else if (m_grade == "D0")
      m_GPA = 1.0;
   else if (m_grade == "F")
      m_GPA = 0;

   m_GPA = m_GPA * m_hakjum; // ������ ��ȯ�� ����� ���Ͽ� ���� ���

}

void Subject::InputData()// ����ڿ��� ��������� ���� ���� �Է¹���.
{
   cout << "������ ��:";
   InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
   cout << "���� ������:";
   InputValue(m_hakjum); // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��
   cout << "������<A+ ~F>:";
   InputValue(m_grade); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
   cout << "\n";

}

void Subject::PrintTitle() // ��������� ���� title �ؽ�Ʈ�� ȭ�鿡 ���
{
   cout << "====================================================================\n";
   cout.width(15);
   cout << "�������" << "            ������" << "        ��� " << "         ���� " << "\n";
   cout << "====================================================================\n";

}

void Subject::PrintData() // ��� ������ ���� ȭ�鿡 ���
{
   cout.precision(2);
   cout << fixed;
   cout.width(15);
   cout << m_name; // �����̸�
   cout.width(15);
   cout << m_hakjum; // ��������
   cout.width(15);
   cout << m_grade; // ������
   cout.width(15);
   CalcGPA();
   cout << m_GPA << "\n"; // �������

}

void Subject::Modify()
{
   cout << "*< " << m_name << " >�� ������ �����ϼ���\n";
   cout << "�������: ";
   InputValue(m_name);
   cout << "�������� :";
   InputValue(m_hakjum);
   cout << "������ :";
   InputValue(m_grade);
   cout << "\n";
   CalcGPA();

}
string Subject::GetName()const // �������Լ� : m_name�� Ŭ���� �ۿ��� ���� �� �ְ���.
{
   return m_name;
}

int Subject::GetHakjum()const // �������Լ� : m_hakjum�� Ŭ���� �ۿ��� ���� �� �ְ���.
{
   return m_hakjum;
}

float Subject::GetGPA()const // �������Լ� : m_GPA�� Ŭ���� �ۿ��� ���� �� �ְ���.
{
   return m_GPA;
}

string Subject::GetGrade()const // �������Լ� : m_grade�� Ŭ���� �ۿ��� ���� �� �ְ���.
{
   return m_grade;
}

void Subject::SetName(string name)
{
   m_name = name;
}
void Subject::SetHakjum(int num)
{
   m_hakjum = num;
}
void Subject::SetGrade(string gra)
{
   m_grade = gra;
}
void Subject::SetGPA(float num)
{
   m_GPA = num;
}