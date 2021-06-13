//********************
// Author:  yh 
// Time:    2021/6/6.
// 
//********************
//
#include <iostream>


//懒汉式
class SingletonPattern {
private:
    SingletonPattern() {
        std::cout << "construct function" << std::endl;
    }

public:
    static SingletonPattern *getInstance() {
        if (m_instance == nullptr) {
            m_instance = new SingletonPattern();
        }
        ++m_num;
        return m_instance;
    }
    static void freeInstance() {
        if (m_instance != nullptr) {
            delete m_instance;
            m_instance = nullptr;
        }
    }

    void showMessage() {
        std::cout << "num: " << m_num << std::endl;
    }

private:
    static SingletonPattern *m_instance;
    static int m_num;
};
