//********************
// Author:  yh 
// Time:    2021/6/6.
// 
//********************
//

#include <iostream>
#include <cstring>

class Fruit {
public:
    virtual void getFruit() = 0;

};

class AppleFruit : public Fruit {
public:
    virtual void getFruit() {
        std::cout << "this is apple" << std::endl;
    }
};

class WatermelonFruit : public Fruit {
public:
    virtual void getFruit() {
        std::cout << "this is watermelon" << std::endl;
    }
};

class Factory {
public:
    Fruit *create(char *pFruit) {
        if(strcmp(pFruit, "apple")) {
            return new AppleFruit;
        } else if(strcmp(pFruit, "watermelon")) {
            return new WatermelonFruit;
        } else {
            std::cout << "not support" << std::endl;
            return nullptr;
        }
    }
};

