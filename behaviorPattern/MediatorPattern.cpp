//********************
// Author:  yh
// Time:    2021/6/5.
//
//********************
//
#include <iostream>
using namespace std;
#include "string"

class Person
{
public:
	Person(string name, int sex, int condi)
	{
		m_name = name;
		m_sex = sex;
		m_condi = condi;
	}
	string getName()
	{
		return m_name;
	}
	int getSex()
	{
		return m_sex;
	}
	int getCondi()
	{
		return m_condi;
	}
	virtual void getParter(Person *p) = 0;

protected:
	string	m_name;
	int		m_sex;
	int		m_condi;
};


class Woman : public Person
{
public:
	Woman(string name, int sex, int condi) : Person(name, sex, condi)
	{

	}
	virtual void getParter(Person *p)
	{
		if (this->m_sex == p->getSex())
		{
			cout << "�Ҳ���ͬ����..." << endl;
		}
		if (this->getCondi() == p->getCondi() )
		{
			cout << this->getName() << " �� " << p->getName() << "���� " <<endl;
		}
		else
		{
			cout << this->getName() << " �� " << p->getName() << "���� " <<endl;
		}
	}
};


class Man : public Person
{
public:
	Man(string name, int sex, int condi) : Person(name, sex, condi)
	{

	}
	virtual void getParter(Person *p)
	{
		if (this->m_sex == p->getSex())
		{
			cout << "�Ҳ���ͬ����..." << endl;
		}
		if (this->getCondi() == p->getCondi() )
		{
			cout << this->getName() << " �� " << p->getName() << "���� " <<endl;
		}
		else
		{
			cout << this->getName() << " �� " << p->getName() << "���� " <<endl;
		}
	}
};

int main()
{
	//string name, int sex, int condi
	Person *xiaofang = new Woman("С��", 2, 5);

	Person *zhangsan = new Man("����", 1, 4);

	Person *lisi = new Man("����", 1, 5);
	xiaofang->getParter(zhangsan);

	xiaofang->getParter(lisi);



	cout<<"hello..."<<endl;
	system("pause");
	return 0;
}