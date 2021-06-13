//********************
// Author:  yh 
// Time:    2021/6/6.
// 
//********************
//


#include <iostream>

using namespace std;


class SubSystemA {
public:
    void doThing() {
        cout << "SubSystemA run" << endl;
    }
};

class SubSystemB {
public:
    void doThing() {
        cout << "SubSystemB run" << endl;
    }
};

class SubSystemC {
public:
    void doThing() {
        cout << "SubSystemC run" << endl;
    }
};


class Facade {
public:
    Facade() {
        sysA = new SubSystemA;
        sysB = new SubSystemB;
        sysC = new SubSystemC;
    }

    ~Facade() {
        delete sysA;
        delete sysB;
        delete sysC;
    }

public:
    void doThing() {
        sysA->doThing();
        sysB->doThing();
        sysC->doThing();
    }

protected:
private:
    SubSystemA *sysA;
    SubSystemB *sysB;
    SubSystemC *sysC;
};


int main1() {
    SubSystemA *sysA = new SubSystemA;
    SubSystemB *sysB = new SubSystemB;
    SubSystemC *sysC = new SubSystemC;

    sysA->doThing();
    sysB->doThing();
    sysC->doThing();
    delete sysA;
    delete sysB;
    delete sysC;

    return 0;
}


int main() {
    Facade *f = new Facade;
    f->doThing();
    delete f;
    return 0;
}