//********************
// Author:  yh 
// Time:    2021/6/6.
// 
//********************
//
#include <iostream>
#include <cstring>

using namespace std;

class Person {
public:
    virtual Person *Clone() = 0;

    virtual void printT() = 0;

};

class JavaProgrammer : public Person {
public:
    JavaProgrammer() {
        this->m_name = "";
        this->m_age = 0;
        m_resume = nullptr;
    }

    JavaProgrammer(string name, int age) {
        this->m_name = name;
        this->m_age = age;
        m_resume = NULL;
    }

    ~JavaProgrammer() {
        if (m_resume != NULL) {
            free(m_resume);
            m_resume = NULL;
        }
    }

    virtual Person *Clone() {
        JavaProgrammer *p = new JavaProgrammer;
        *p = *this;
        return p;
    }

    void setResume(char *resume) {
        m_resume = new char[strlen(resume) + 1];
        strcpy(m_resume, resume);
    }

    virtual void printT() {
        cout << "m_name:" << m_name << "\t" << "m_age:" << m_age << endl;
        if (m_resume != NULL) {
            cout << m_resume << endl;
        }
    }

protected:
private:
    string m_name;
    int m_age;
    char *m_resume;
};

int main() {
    JavaProgrammer pJavaProgramer("yh", 16);
    pJavaProgramer.setResume("I am a java programer");
    Person *p2 = pJavaProgramer.Clone();  //对象具有自我复制功能 深拷贝和浅拷贝问题
    p2->printT();

    delete p2;

    return 0;
}
