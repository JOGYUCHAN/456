#include <iostream>
#include <string>
#include"Student.h"
#include"Subject.h"
#include"IOInterface.h"
using namespace std;



Student::Student():IOInterface() //����Ʈ ������ 
{
   m_name = "";
   m_hakbun = 0;
   m_subnum = 0;
   m_sub = NULL;
   m_aveGPA = 0.0;
   cout << "* Student ����Ʈ ������ ȣ�� *\n";

}

Student::Student(string name, int hakbun, int subnum, Subject* sub):IOInterface(name) // �����ִ� ������_���� ���� �ؾ���
{
   m_name = name;
   m_hakbun = hakbun;
   m_subnum = subnum;

   m_sub = new Subject[m_subnum];

   for (int i = 0; i < m_subnum; i++)
   {
      (m_sub + i)->SetName((sub + i)->GetName());
      (m_sub + i)->SetHakjum((sub + i)->GetHakjum());
      (m_sub + i)->SetGrade((sub + i)->GetGrade());
      (m_sub + i)->SetGPA((sub + i)->GetGPA()); // 
   }


   cout << "* Student �����ִ� ������ ȣ�� *\n";
}

Student::~Student() // �Ҵ���� �޸� ���� ����
{
   cout << "Student �Ҹ��� ȣ��\n";
   delete[]m_sub;
   m_sub = NULL;
}

Student::Student(const Student& std):IOInterface(std) //���������
{
   this->m_name = std.m_name;
   this->m_hakbun = std.m_hakbun;
   this->m_subnum = std.m_subnum;

   this->m_sub = new Subject[m_subnum];
   //���񺹻簡 �Ͼ����.

   for (int i = 0; i < m_subnum; i++)
   {
      (this->m_sub + i)->SetName((std.m_sub + i)->GetName());
      (this->m_sub + i)->SetHakjum((std.m_sub + i)->GetHakjum());
      (this->m_sub + i)->SetGrade((std.m_sub + i)->GetGrade());
      (this->m_sub + i)->SetGPA((std.m_sub + i)->GetGPA());
   }

}
void Student::InputValue(string& str) // ���ڿ� �Է��� ���� �Լ�
{
   getline(cin, str);
}

void Student::InputValue(int& i) // ���� �Է��� ���� �Լ�
{
   cin >> i;
   cin.ignore(); // ���� ����
}

void Student::InputData() // ����ڷκ��� ������ �Է� �ޱ�
{
   cout << "*" << "�л� �̸��� �й��� �Է��ϼ���.\n";
   cout << "�̸� : ";
   InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
   cout << "�й� : ";
   InputValue(m_hakbun);
   cout << "\n"; // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��

   cout << "������ ���� �� �Է� :";
   InputValue(m_subnum);

   m_sub = new Subject[m_subnum]; // �Է¹��� ���� �� ��ŭ ���� ���� ������ �����Ҵ�


   for (int j = 0; j < (m_subnum); j++)
   {
      cout << "* ������ ������" << m_subnum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";
      (m_sub + j)->InputData(); // �Ѱ��� ���� ���� �Է�
   }

}

void Student::CalcAveGPA(float sum, float haksum) // ��ü ���� ����� ����ϴ� �Լ�
{
   m_aveGPA = sum / haksum; // �������� ��/ �� ���� ��
}

void Student::PrintData() // ���� ���
{
   float sum = 0; // ��� ������ ���ؼ� ���� ����
   float haksum = 0; // ��ü ���� ���� ���ؼ� ���� ����
   cout.width(10);
   cout << "�̸� : " << m_name; // �̸����
   cout.width(10);
   cout << "�й� : " << m_hakbun << "\n" << "\n"; // �й����
   cout.width(20);

   m_sub->PrintTitle(); //Subject Ŭ������ PrintTitle() ȣ��

   for (int p = 0; p < m_subnum; p++) // �Է¹��� ����� ��ŭ �ݺ����� ���鼭
   {
      (m_sub + p)->PrintData(); // �� ���� ���� ���
      haksum = haksum + (m_sub + p)->GetHakjum(); // �� ������ �������� ���Ͽ� ������ ���� �Ҵ�_������ �Լ��� ����Ͽ� ���ٰ���
      sum = sum + (m_sub + p)->GetGPA(); // �� ������ ������ ���Ͽ� ������ �Ҵ�_������ �Լ��� ����Ͽ� ���ٰ���
   }

   cout << "--------------------------------------------------------------------\n";
   cout.width(45);
   CalcAveGPA(sum, haksum); // ������� ���
   cout << "��� ���� :" << m_aveGPA << "\n" << "\n";

}

// void Student::Modify()
// {
//    string Type; // �л����� �Ǵ� �������� ���ڿ� ����� string
//    cout << "����<�л�����/��������/���>:"; // ������ ���� �Է�
//    InputValue(Type);

//    if (Type == "�л�����") // �л����� �����̸�
//    {
//       cout << "*< " << m_name << "  " << m_hakbun << " >�� ������ �����ϼ���\n";
//       cout << "�̸� : ";
//       InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
//       cout << "�й� : ";
//       InputValue(m_hakbun);
//       cout << "\n";
//    }
//    else if (Type == "��������") // �������� ����_� ������ ������ ������ ���� ã��
//    {
//       string subject; // string ���ڿ� ��ü
//       cout << "�˻��� ���� �̸� :"; // �������� �ִ��� �˻�
//       InputValue(subject);
//       int i;
//       for (i = 0; i < m_subnum; i++) // �����ϴ� ������ ����ŭ �ݺ�
//       {
//          if (subject == (m_sub + i)->GetName()) // �Է¹��� ����� ���� ������� ���ʴ�� ��
//          {
//             (m_sub + i)->Modify();
//             break;
//          }
//          else
//             continue; // ��ġ�ϴ� ������ ã�� ���ߴٸ�, ��� ���� �ݺ��� ����
//       }
//       if (i == m_subnum)
//       {
//          cout << "��ġ�ϴ� ������ �����ϴ�. \n"; // ��ġ�ϴ� ������ ���� ���, �޼��� ���
//       }

//    }
//    else if (Type == "���")
//    {
//       cout << "*< " << m_name << "  " << m_hakbun << " >�� ������ �����ϼ���\n";
//       cout << "�̸� : ";
//       InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
//       cout << "�й� : ";
//       InputValue(m_hakbun);
//       cout << "\n";

//       string subject; // string ���ڿ� ��ü
//       cout << "�˻��� ���� �̸� :"; // �������� �ִ��� �˻�
//       InputValue(subject);
//       int i;
//       for (i = 0; i < m_subnum; i++) // �����ϴ� ������ ����ŭ �ݺ�
//       {
//          if (subject == (m_sub + i)->GetName()) // �Է¹��� ����� ���� ������� ���ʴ�� ��
//          {
//             (m_sub + i)->Modify();
//             break;
//          }
//          else
//             continue; // ��ġ�ϴ� ������ ã�� ���ߴٸ�, ��� ���� �ݺ��� ����
//       }
//       if (i == m_subnum)
//       {
//          cout << "��ġ�ϴ� ������ �����ϴ�. \n"; // ��ġ�ϴ� ������ ���� ���, �޼��� ���
//       }


//    }

// }

void Student::Modify() { //�л��� ������ �����ϴ� �Լ�

	string Type; 
	string searchsub;
	cout << "����(�л�����/��������/���) : ";
	InputValue(Type);

	if (Type == "�л�����") {

		cout << "�̸� : ";
		InputValue(m_name);
		cout << "�й� : ";
		InputValue(m_hakbun);	

		} 
	else if (Type == "��������") {
		cout << "���� �� ������ �̸��� �Է��ϼ��� : ";
		InputValue(searchsub);
		Subject* findsub=SubSearch(searchsub); 
		findsub->Modify();
	}

	else if (Type == "���") {
		cout << "�̸� : ";
		InputValue(m_name);
		cout << "�й� : ";
		InputValue(m_hakbun);
		cin.ignore();
		cout << "���� �� ������ �̸��� �Է��ϼ��� : ";
		InputValue(searchsub);
		Subject* findsub = SubSearch(searchsub);
		findsub->Modify(); 
	}

}

string Student::GetName()const // �������Լ� : Ŭ���� �ۿ��� ��������� ���� �� �ְ���.
{
   return m_name;
}

int Student::GetHakbun()const
{
   return m_hakbun;
}

int Student::GetSubNum()const
{
   return m_subnum;
}

float Student::GetAveGPA()const
{
   return m_aveGPA;
}

Subject* Student::SubSearch(string subname) {
    cout <<"\n" << subname << " : Ž�����\n";

    for (int i = 0; i < m_subnum;i++) {
        if (this->m_sub[i].GetName() == subname)
            return &m_sub[i];
    }

    cout << "ã�� ������ �����ϴ�";
    return NULL;
};
