//********************
// Author:  yh 
// Time:    2021/6/6.
// 
//********************
//
#include <iostream>
using namespace std;

class pFruit
{
public:
    virtual void getFruitName() = 0;
};

class AbstractFactory
{
public:
    virtual pFruit* CreateBanana() = 0;
    virtual pFruit* CreateApple() = 0;
};

class NorthBanana : public pFruit
{
public:
    virtual void getFruitName()
    {
        cout << "NorthBanana" << endl;
    }
};

class NorthApple : public pFruit
{
public:
    virtual void getFruitName()
    {
        cout << "NorthApple" << endl;
    }
};


class SourthBanana : public pFruit
{
public:
    virtual void getFruitName()
    {
        cout << "SourthBanana" << endl;
    }
};


class SourthApple : public pFruit
{
public:
    virtual void getFruitName()
    {
        cout << "SourthApple" << endl;
    }
};

class NorthFacorty : public AbstractFactory
{
    virtual pFruit * CreateBanana()
    {
        return new NorthBanana;
    }
    virtual pFruit * CreateApple()
    {
        return new NorthApple;
    }
};

class SourthFacorty : public AbstractFactory
{
    virtual pFruit * CreateBanana()
    {
        return new SourthBanana;
    }
    virtual pFruit * CreateApple()
    {
        return new SourthApple;
    }
};


int main()
{
    pFruit			*pFruit = NULL;
    AbstractFactory *pAbstructFactory = NULL;

    ///--------------
    pAbstructFactory = new SourthFacorty;
    pFruit = pAbstructFactory->CreateApple();
    pFruit->getFruitName();
    delete pFruit;
    pFruit = pAbstructFactory->CreateBanana();
    pFruit->getFruitName();
    delete pFruit;

    ///------
    pAbstructFactory = new NorthFacorty;
    pFruit = pAbstructFactory->CreateApple();
    pFruit->getFruitName();
    delete pFruit;
    pFruit = pAbstructFactory->CreateBanana();
    pFruit->getFruitName();
    delete pFruit;

    delete pAbstructFactory;
    return 0;
}