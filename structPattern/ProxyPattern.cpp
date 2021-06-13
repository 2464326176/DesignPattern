//********************
// Author:  yh 
// Time:    2021/6/6.
// 
//********************
//
#include <string>
#include <iostream>

using namespace std;


class Interface {
public:
    virtual void Request() = 0;
};

class RealClass : public Interface {
public:
    virtual void Request() {
        cout << "real request" << endl;
    }
};

class ProxyClass : public Interface {
private:
    RealClass *m_realClass;
public:
    virtual void Request() {
        m_realClass = new RealClass();
        m_realClass->Request();
        delete m_realClass;
    }
};

int main() {
    ProxyClass *pTest = new ProxyClass();
    pTest->Request();
    return 0;
}
