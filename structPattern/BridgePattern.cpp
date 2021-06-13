//********************
// Author:  yh
// Time:    2021/6/6.
//
//********************
//
#include <iostream>
using namespace std;

class Engine
{
public:
    virtual void InstallEngine() = 0;
};

class Engine4400cc : public Engine
{
public:
    virtual void InstallEngine()
    {
        cout << "4400cc installed" << endl;
    }
};

class Engine4500cc : public Engine
{
public:
    virtual void InstallEngine()
    {
        cout << "4500cc installed" << endl;
    }
};

class Car
{
public:
    Car(Engine *engine)
    {
        this->m_engine = engine;
    }
    virtual void installEngine() = 0;

protected:
    Engine *m_engine;
};

class WBM5 : public Car
{
public:
    WBM5(Engine *engine) : Car(engine)
    {
        ;
    }

    virtual void installEngine()
    {
        m_engine->InstallEngine();
    }
};

class WBM6 : public Car
{
public:
    WBM6(Engine *engine) : Car(engine)
    {
        ;
    }

    virtual void installEngine()
    {
        cout << " WBM6 " << endl;
        m_engine->InstallEngine();
    }
};

int main()
{
    //
    Engine *engine = NULL;
    WBM6 *wbm6 = NULL;

    engine = new Engine4400cc;
    wbm6 = new WBM6(engine);
    wbm6->installEngine();

    delete wbm6;
    delete engine;
    return 0;
}