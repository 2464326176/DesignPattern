//********************
// Author:  yh
// Time:    2021/6/5.
//
//********************
//
#include <iostream>
#include "string"
#include "list"

using namespace std;

class Secretary;

class PlayserObserver {
public:
    PlayserObserver(Secretary *secretary) {
        this->m_secretary = secretary;
    }

    void update(string action) {
        cout << "action:" << action << endl;
    }

private:
    Secretary *m_secretary;
};

//
class Secretary {
public:
    Secretary() {
        m_list.clear();
    }

    void Notify(string info) {
        //to send information to all observers
        for (list<PlayserObserver *>::iterator it = m_list.begin(); it != m_list.end(); it++) {
            std::cout << *it ;
            (*it)->update(info);
        }
    }

    void setPlayserObserver(PlayserObserver *object) {
        m_list.push_back(object);
    }

private:
    list<PlayserObserver *> m_list;
};





int main() {
    Secretary *secretary = NULL;
    PlayserObserver *po1 = NULL;
    PlayserObserver *po2 = NULL;

    secretary = new Secretary;

    po1 = new PlayserObserver(secretary);
    po2 = new PlayserObserver(secretary);

    secretary->setPlayserObserver(po1);
    secretary->setPlayserObserver(po2);

    secretary->Notify("coming");
    secretary->Notify("leaveing");


    delete secretary;
    delete po1;
    delete po2;
    return 0;
}