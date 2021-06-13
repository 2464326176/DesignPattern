
#include <iostream>
using namespace std;
#include "list"

class ParkElement;

class VisitSceneArea
{
public:
	virtual void visit(ParkElement *parkelement) = 0;
};

class ParkElement
{
public:
	virtual void accept(VisitSceneArea *visit) = 0;
};

class  ParkA : public ParkElement
{
public:
	virtual void accept(VisitSceneArea *v)
	{
        cout << "now start visit park A";
		v->visit(this);
	}
};


class  ParkB : public ParkElement
{
public:
	virtual void accept(VisitSceneArea *v)
	{
	    cout << "now start visit park B";
		v->visit(this);
	}

};

class Park : public ParkElement
{
public:
	Park()
	{
		m_list.clear();
	}
	void addParkElement(ParkElement *pe)
	{
		m_list.push_back(pe);
	}

public:
	virtual void accept(VisitSceneArea *v)
	{

		for (list<ParkElement *>::iterator it = m_list.begin(); it!=m_list.end(); it++ )
		{
            cout <<  *it << ":";
			(*it)->accept(v);
		}
	}

private:
	list<ParkElement *> m_list;
};

class ForestSceneArea : public VisitSceneArea
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << " forest" << endl;
	}
};

class LakeSceneArea : public VisitSceneArea
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << " lake" << endl;
	}
};

class AllScapesSceneArea : public VisitSceneArea

{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << " landscapes" << endl;
	}
};

void operate1()
{
	VisitSceneArea *vA = new  ForestSceneArea;
	VisitSceneArea *vB = new  LakeSceneArea;

	ParkA *parkA = new ParkA;
	ParkB *parkB = new ParkB;

	parkA->accept(vA);
	parkB->accept(vB);

	delete vA;
	delete vB;
	delete parkA;
	delete parkB;
}

void operate2()
{
    VisitSceneArea *vManager = new  AllScapesSceneArea;
    //VisitSceneArea *vManager = new  ForestSceneArea;
    //VisitSceneArea *vManager = new  LakeSceneArea;


	Park *park = new Park;

	ParkElement *parkA = new ParkA;
	ParkElement *parkB = new ParkB;

	park->addParkElement(parkA);
	park->addParkElement(parkB);
	
	park->accept(vManager);
	
	delete parkA;
	delete parkB;
	delete park;
	delete vManager;
}

int main()
{
    //operate1();
    operate2();
	return 0;
}