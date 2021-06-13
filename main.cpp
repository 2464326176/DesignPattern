//********************
// Author:  yh 
// Time:    2021/6/6.
// 
//********************
//
#include <iostream>
/*#include "SingletonPattern.cpp"*/
#include "SingletonPattern1.cpp"
/*#include "SimpleFactoryPattern.cpp"*/
#include "AbstructFactoryPattern.cpp"
//懒汉式
/*
SingletonPattern *SingletonPattern::m_instance = nullptr;
int SingletonPattern::m_num = 0;

int main() {

    SingletonPattern *p1 = SingletonPattern::getInstance();
    p1->showMessage();

    SingletonPattern *p2 = SingletonPattern::getInstance();
    p2->showMessage();
    if (p1 == p2) {
        std::cout << "not the same object" << std::endl;
    } else {
        std::cout << "the same object" << std::endl;

    }
    SingletonPattern::freeInstance();

    return 0;
}*/

//饿汉式
/*SingletonPattern *SingletonPattern::m_instance = new SingletonPattern();
int SingletonPattern::m_num = 0;

int main() {

    SingletonPattern *p1 = SingletonPattern::getInstance();
    p1->showMessage();

    SingletonPattern *p2 = SingletonPattern::getInstance();
    p2->showMessage();
    if (p1 == p2) {
        std::cout << "not the same object" << std::endl;
    } else {
        std::cout << "the same object" << std::endl;

    }
    SingletonPattern::freeInstance();

    return 0;
}*/
//simple factory
/*
int main() {
    Factory *pFactory = new Factory;

    Fruit *pFruit = nullptr;
    pFruit = pFactory->create("apple");
    pFruit->getFruit();
    delete pFruit;

    pFruit = nullptr;
    pFruit = pFactory->create("watermelon");
    pFruit->getFruit();
    delete pFruit;

    delete pFactory;

    return 0;
}*/

