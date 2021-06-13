//********************
// Author:  yh 
// Time:    2021/6/6.
// 
//********************
//

#include <iostream>

class Fruit
{
public:
    virtual void  getFruit()  = 0;
};


class  Banana : public Fruit
{
public:
    void  getFruit()
    {
        std::cout << "this is Banana" << std::endl;
    }
};


class  Apple : public Fruit
{
public:
    void  getFruit()
    {
        std::cout << "this is Apple" << std::endl;
    }
};


class  AbFactory
{
public:
    virtual Fruit *CreateProduct() = 0;
};



class BananaFactory :public AbFactory
{
public:
    virtual Fruit *CreateProduct()
    {
        return new Banana;
    }
};

class AppleFactory :public AbFactory
{
public:
    virtual Fruit *CreateProduct()
    {
        return new Apple;
    }
};


class Pear : public Fruit
{
public:
    virtual void getFruit()
    {
        std::cout << "this is pear" << std::endl;
    }

};

class PearFactory : public AbFactory
{
public:
    virtual Fruit *CreateProduct()
    {
        return new Pear;
    }
};




int main() {
    AbFactory		*pFactory = NULL;
    Fruit			*pFruit = NULL;

    //吃 香蕉
    pFactory = new BananaFactory;
    pFruit = pFactory->CreateProduct();
    pFruit->getFruit();

    delete pFruit;
    delete pFactory;

    //Pear
    pFactory = new PearFactory;
    pFruit = pFactory->CreateProduct();
    pFruit->getFruit();

    delete pFruit;
    delete pFactory;

    return 0;
}
