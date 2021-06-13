//********************
// Author:  yh
// Time:    2021/6/4.
//
//********************
//
#include <iostream>
using namespace std;


class  Current110v
{
public:
	virtual void useCurrent110v() = 0;
};

class  Current220v
{
public:
	void useCurrent220v()
	{
		cout << "Current is 220v \n" << endl;
	}
};

class Adapter : public Current110v
{
public:
	Adapter(Current220v *current)
	{
		m_current = current;
	}
    void useCurrent110v()
	{
		cout << "adapter 220v \n" ;
		m_current->useCurrent220v();
	}
protected:
private:
	Current220v *m_current;
};


int main()
{
	Current220v		*current220v = NULL;
	Adapter			*adapter = NULL;

	current220v = new Current220v;
	adapter = new Adapter(current220v);
	adapter->useCurrent110v();

	delete current220v ;
	delete adapter;
	return 0;
}