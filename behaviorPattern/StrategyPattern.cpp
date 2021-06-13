//********************
// Author:  yh
// Time:    2021/6/5.
//
//********************
//
#include <iostream>

using namespace std;


class Strategy {
public:
    virtual void crypt() = 0;
};


class AES : public Strategy {
public:
    void crypt() {
        cout << "AES Encryption Algorithm" << endl;
    }
};

class DES : public Strategy {
public:
    void crypt() {
        cout << "DES Encryption Algorithm" << endl;
    }
};


class Context {
public:
    void setStrategy(Strategy *strategy) {
        this->strategy = strategy;
    }

    void myoperator() {
        strategy->crypt();
    }

protected:
private:
    Strategy *strategy;
};

int main() {

    Strategy *strategy = NULL;

    strategy = new AES;
    Context *context = new Context;
    context->setStrategy(strategy);
    context->myoperator();

    delete strategy;
    delete context;


    return 0;
}