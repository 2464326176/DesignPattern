//********************
// Author:  yh
// Time:    2021/6/6.
//
//********************
//

#include <iostream>
using namespace std;

class Car
{
public:
    virtual void show() = 0;
};

class RunCar : public Car
{
public:
    virtual void show()
    {
        cout << "run" << endl;
    }
};

class SwimCarDirector : public Car
{
public:
    SwimCarDirector(Car *car)
    {
        m_car = car;
    }
    void swim()
    {
        cout << "swim" << endl;
    }
    virtual void show()
    {
        m_car->show();
        swim();
    }
    Car *m_car;
};

class FlyCarDirector : public Car
{
public:
    FlyCarDirector(Car *car)
    {
        m_car = car;
    }
    void fly()
    {
        cout << "fly" << endl;
    }
    virtual void show()
    {
        m_car->show();
        fly();
    }

private:
    Car *m_car;
};

int main()
{
    Car *mycar = NULL;
    mycar = new RunCar;
    mycar->show();

    FlyCarDirector *flycar = new FlyCarDirector(mycar);
    flycar->show();

    SwimCarDirector *swimcar = new SwimCarDirector(flycar);
    swimcar->show();

    delete swimcar;
    delete flycar;
    delete mycar;

    return 0;
}
