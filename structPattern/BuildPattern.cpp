//********************
// Author:  yh 
// Time:    2021/6/6.
// 
//********************
//

#include <iostream>
using namespace std;
#include "string"


class House
{
public:
    void setFloor(string floor)
    {
        this->m_floor = floor;
    }
    void setWall(string wall)
    {
        this->m_wall = wall;
    }
    void setDoor(string door)
    {
        this->m_door = door;
    }

    //
    string getFloor()
    {
        return m_floor;
    }
    string getWall()
    {
        return  m_wall;
    }
    string getDoor()
    {
        return m_door;
    }

protected:
private:
    string	m_floor;
    string	m_wall;
    string	m_door;
};

class Builder
{
public:
    virtual void makeFloor() = 0;
    virtual void makeWall() =  0;
    virtual void makeDoor() = 0;
    virtual House *GetHouse() = 0;
};

//公寓
class FlatBuild : public Builder
{
public:
    FlatBuild()
    {
        pHouse = new House;
    }
    virtual void makeFloor()
    {
        pHouse->setFloor("flat Door");
    }
    virtual void makeWall()
    {
        pHouse->setWall("flat Wall");
    }
    virtual void makeDoor()
    {
        pHouse->setDoor("flat Door");
    }
    virtual House *GetHouse()
    {
        return pHouse;
    }

private:
    House *pHouse;
};

//别墅
class VillaBuild : public Builder
{
public:
    VillaBuild()
    {
        pHouse = new House;
    }
    virtual void makeFloor()
    {
        pHouse->setFloor("villa floor");
    }
    virtual void makeWall()
    {
        pHouse->setWall("villa Wall");
    }
    virtual void makeDoor()
    {
        pHouse->setDoor("villa Door");
    }
    virtual House *GetHouse()
    {
        return pHouse;
    }
private:
    House *pHouse;
};

class Director
{
public:
    void Construct(Builder *builder)
    {
        builder->makeFloor();
        builder->makeWall();
        builder->makeDoor();
    }
};

int main()
{
    //客户直接造房子
    House *pHose = new House;
    pHose->setDoor("wbm door");
    pHose->setFloor("wbm Floor");
    pHose->setWall("wbm Wall");
    delete pHose;


    /* //工程队直接造房子
    Builder *builder = new FlatBuild;
    builder->makeFloor();
    builder->makeWall();
    builder->makeDoor();
    */

    //指挥者（设计师）指挥 工程队 和 建房子
    Director *director = new Director;

    //建公寓
    Builder *builder = new FlatBuild;
    director->Construct(builder); //设计师 指挥 工程队干活
    House *house = builder->GetHouse();
    cout << house->getFloor() << endl;
    delete house;
    delete builder;

    //建别墅
    builder = new VillaBuild;
    director->Construct(builder); //设计师 指挥 工程队干活
    house = builder->GetHouse();
    cout << house->getFloor() << endl;
    delete house;
    delete builder;

    delete director;

    return 0;
}
