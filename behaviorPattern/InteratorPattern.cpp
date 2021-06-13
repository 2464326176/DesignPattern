//********************
// Author:  yh 
// Time:    2021/6/13.
// 
//********************
//
#include <iostream>

using namespace std;

typedef int Object;
#define SIZE 5

class MyIterator {
public:
    virtual void First() = 0;

    virtual void Next() = 0;

    virtual bool isEnd() = 0;

    virtual Object CurrentItem() = 0;
};

class Aggregate {
public:
    virtual MyIterator *CreateIterator() = 0;

    virtual Object getItem(int index) = 0;

    virtual int getSize() = 0;
};

class ContreteIterator : public MyIterator {
public:
    ContreteIterator(Aggregate *ag) {
        m_ag = ag;
        m_current_index = 0;
    }

    void First() {
        m_current_index = 0;
    }

    void Next() {
        if (m_current_index < m_ag->getSize()) {
            m_current_index++;
        }
    }

    bool isEnd() {
        return (m_current_index == m_ag->getSize());
    }

    Object CurrentItem() {
        return m_ag->getItem(m_current_index);
    }

protected:
private:
    int m_current_index;
    Aggregate *m_ag;
};


class ConcreteAggregate : public Aggregate {
public:
    ConcreteAggregate() {
        for (int i = 0; i < SIZE; i++) {
            object[i] = i + 100;
        }
    }

    MyIterator *CreateIterator() {
        return new ContreteIterator(this);
    }

    Object getItem(int index) {
        return object[index];
    }

    int getSize() {
        return SIZE;
    }

private:
    Object object[SIZE];
};

int main() {
    Aggregate *ag = new ConcreteAggregate;

    MyIterator *it = ag->CreateIterator();

    for ( ; !(it->isEnd()); it->Next()) {
        cout << it->CurrentItem() << " ";
    }

    delete it;
    delete ag;
    return 0;
}