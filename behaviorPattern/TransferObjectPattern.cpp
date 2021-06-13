//********************
// Author:  yh 
// Time:    2021/6/9.
// 
//********************
//
#include <iostream>
#include <string>
#include <list>

using namespace std;


class StudentVO {
public:
    StudentVO(string name, int no) {
        this->m_name = name;
        this->m_no = no;
    }

    string getName() {
        return m_name;
    }

    void setName(string name) {
        m_name = name;
    }
    int getNo() {
        return m_no;
    }

    void setNo(int no) {
        m_no = no;
    }

public:
    string m_name;
    int m_no;
};

class StudentBO {
public:


    void deleteStudent(StudentVO* student) {
        students.remove(student);
        cout << "Students: roll No: " << student->getNo()    \
                << " name: " << student->getName() << "deleted from database" << endl;
    }

    list<StudentVO *> getAllStudents() {
        return students;
    }

    void insertStudent(StudentVO* student) {
        students.push_back(student);
        cout << "Students: roll No: " << student->getNo()    \
                << " name: " << student->getName() << "  insert  database" << endl;
    }

    StudentVO* getStudent(int rollNo) {
        for (auto stu : students) {
            if(stu->getNo() == rollNo) {
                return stu;
            }
        }

        return NULL;
    }

    void printStud() {
        for (auto stu : students) {
            cout << "Students: roll No: " << stu->getNo()    \
                << " name: " << stu->getName() << endl;
        }
    }

    void printSignleStud(StudentVO* student) {
            cout << "Students: roll No: " << student->getNo()    \
                << " name: " << student->getName() << endl;
    }

    void updateStudent(StudentVO* student) {
        findStudent(student)->setName(student->getName());
        cout << "student no: " << student->getNo() << " student nama: "
                << student->getName() << " update in database" << endl;

    }

    StudentVO* findStudent(StudentVO *student) {
        for (auto stu : students) {
            if(stu == student) {
                return stu;
            }
        }
        return nullptr;
    }

public:
    list<StudentVO *> students;
};


int main() {

    StudentVO stu1("yuhang", 1);
    StudentVO stu2("joke", 2);
    StudentBO studentObject;
    studentObject.insertStudent(&stu1);
    studentObject.insertStudent(&stu2);

    studentObject.printStud();

    StudentVO *stu = studentObject.getStudent(1);
    stu->setName("jane");

    studentObject.updateStudent(stu);

    studentObject.printSignleStud(studentObject.getStudent(1));

    studentObject.printStud();

    return 0;
}
