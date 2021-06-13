//********************
// Author:  yh
// Time:    2021/6/5.
//
//********************
//


#include <iostream>
#include <string>

using namespace std;

//mvc 模型-视图-控制器
class Student {
public:
    int getStuNo() {
        return this->m_stuNo;
    }

    string getStuName() {
        return this->m_StuName;
    }

    void setStuNo(int no) {
        this->m_stuNo = no;
    }

    void setStuName(string name) {
        this->m_StuName = name;
    }
public:
    int m_stuNo;
    string m_StuName;
};

class StudentView {
public:
    void printStudnetDetails(string StuName, int StuNo) {
        std::cout << "name:" << StuName << "  StuNo:" << StuNo << std::endl;
    }

};

class StudentController {
public:
    StudentController(Student tmpModel, StudentView tmpView) {
        this->m_model = tmpModel;
        this->m_view = tmpView;
    }
    void setStudentName(string name){
        m_model.setStuName(name);
    }

    string getStudentName(){
        return m_model.getStuName();
    }

    void setStudentRollNo(int rollNo){
        m_model.setStuNo(rollNo);
    }

    int getStudentRollNo(){
        return m_model.getStuNo();
    }

    void updateView(){
        m_view.printStudnetDetails(m_model.getStuName(), m_model.getStuNo());
    }

public:
    Student m_model;
    StudentView m_view;
};

Student retrieveStudentFromDatabase() {
    Student student;
    student.setStuName("yuhang");
    student.setStuNo(2021);
    return student;
}

int main() {
    Student model = retrieveStudentFromDatabase();
    StudentView view;
    StudentController controller(model, view);

    controller.updateView();

    controller.setStudentName("john");
    controller.updateView();
    return 0;
}