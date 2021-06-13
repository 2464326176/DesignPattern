//********************
// Author:  yh
// Time:    2021/6/5.
//
//********************
//
#include <iostream>

using namespace std;

class Worker;

class State {
public:
    virtual void doSomeThing(Worker *w) = 0;
};

class Worker {
public:
    Worker();

    int getHour() {
        return m_hour;
    }

    void setHour(int hour) {
        m_hour = hour;
    }

    State *getCurrentState() {
        return m_currentStatus;
    }

    void setCurrentState(State *state) {
        m_currentStatus = state;
    }

    void doSomeThing() {
        m_currentStatus->doSomeThing(this);
    }

private:
    int m_hour;
    State *m_currentStatus;
};

class WriteCodeStatus : public State {
public:
    void doSomeThing(Worker *w);
};

class SleepStatus : public State {
public:
    void doSomeThing(Worker *w);
};

void WriteCodeStatus::doSomeThing(Worker *w) {
    if (w->getHour() == 7 || w->getHour() == 8) {
        cout << "write code" << endl;
    } else {
        delete w->getCurrentState();
        w->setCurrentState(new SleepStatus);
        w->getCurrentState()->doSomeThing(w);
    }
}


void SleepStatus::doSomeThing(Worker *w) {
    if (w->getHour() == 9 || w->getHour() == 10) {
        cout << "sleep" << endl;
    } else {
        delete w->getCurrentState();
        w->setCurrentState(new WriteCodeStatus);
        cout << "now time:" << w->getHour() << "unknow status̬" << endl;
    }
}

Worker::Worker() {
    m_currentStatus = new WriteCodeStatus;
}

int main() {
    Worker *pWork = new Worker;
    pWork->setHour(7);
    pWork->doSomeThing();

    pWork->setHour(9);
    pWork->doSomeThing();

    delete pWork;

    return 0;
}