//********************
// Author:  yh
// Time:    2021/6/5.
//
//********************
//
#include <iostream>
#include "string"

using namespace std;


class MememTo {
public:
    MememTo(string name, int age) {
        m_name = name;
        m_age = age;
    }

    string getName() {
        return m_name;
    }

    int getAge() {
        return m_age;
    }

    void setName(string name) {
        this->m_name = name;
    }

    void setAge(int age) {
        this->m_age = age;
    }

private:
    string m_name;
    int m_age;
};

class Person {
public:
    Person(string name, int age) {
        m_name = name;
        m_age = age;
    }

    string getName() {
        return m_name;
    }

    int getAge() {
        return m_age;
    }

    void setName(string name) {
        this->m_name = name;
    }

    void setAge(int age) {
        this->m_age = age;
    }

    MememTo *createMememTo() {
        return new MememTo(m_name, m_age);
    }

    void setMememTo(MememTo *memto) {
        this->m_age = memto->getAge();
        this->m_name = memto->getName();
    }

    void printT() {
        cout << "m_name:" << m_name << " m_age:" << m_age << endl;
    }

private:
    string m_name;
    int m_age;
};

class Caretaker {
public:
    Caretaker(MememTo *memto) {
        this->memto = memto;
    }

    MememTo *getMememTo() {
        return memto;
    }

    void setMememTo(MememTo *memto) {
        this->memto = memto;
    }

private:
    MememTo *memto;
};

void operate1() {
    Caretaker *caretaker = NULL;
    Person *p = new Person("yuhang", 32);
    p->printT();

    caretaker = new Caretaker(p->createMememTo());
    p->setAge(42);
    p->printT();

    p->setMememTo(caretaker->getMememTo());
    p->printT();

    delete caretaker;
    delete p;
}

void operate2() {
    MememTo *memto = NULL;
    Person *p = new Person("yuhang", 32);
    p->printT();

    memto = p->createMememTo();
    p->setAge(42);
    p->printT();

    p->setMememTo(memto);
    p->printT();

    delete memto;
    delete p;
}

int main() {

    operate1();
    return 0;
}