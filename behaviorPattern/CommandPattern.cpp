//********************
// Author:  yh
// Time:    2021/6/5.
//
//********************
//

#include <iostream>
#include "list"
#include "string"
using namespace std;


class Doctor {
public:
    void treat_eye() {
        cout << "treat eye" << endl;
    }

    void treat_nose() {
        cout << "treat nose" << endl;
    }
};

class Command {
public:
    virtual void treat() = 0;
};

class CommandTreatEye : public Command {
public:
    CommandTreatEye(Doctor *doctor) {
        m_doctor = doctor;
    }

    void treat() {
        m_doctor->treat_eye();
    }

private:
    Doctor *m_doctor;
};


class CommandTreatNose : public Command {
public:
    CommandTreatNose(Doctor *doctor) {
        m_doctor = doctor;
    }

    void treat() {
        m_doctor->treat_nose();
    }

private:
    Doctor *m_doctor;
};


class OrdinaryNurse {
public:
    OrdinaryNurse(Command *command) {
        this->m_command = command;
    }

public:
    void SubmittedCase() {
        m_command->treat();
    }

protected:
private:
    Command *m_command;
};

class HeadNurse {
public:
    HeadNurse() {
        m_list.clear();
    }

public:
    void setCommand(Command *command) {
        m_list.push_back(command);
    }

    void SubmittedCase() {
        for (list<Command *>::iterator it = m_list.begin(); it != m_list.end(); it++) {
            (*it)->treat();
        }
    }

private:
    list<Command *> m_list;
};

void doctorTreatDiseaseInDirect() {
    Doctor *doctor = new Doctor;
    doctor->treat_eye();

    delete doctor;
    return ;
}

void doctorTreatDiseaseInCommand() {
    Doctor *doctor = new Doctor;
    Command *command = new CommandTreatEye(doctor);
    command->treat();

    delete command;
    delete doctor;
}



void doctorTreatDiseaseByNurse() {
    OrdinaryNurse *pOrdinaryNurse = NULL;
    Doctor *doctor = NULL;
    Command *command = NULL;

    doctor = new Doctor;

    //command = new CommandTreatEye(doctor);
    command = new CommandTreatNose(doctor);
    pOrdinaryNurse = new OrdinaryNurse(command);
    pOrdinaryNurse->SubmittedCase();

    delete doctor;
    delete command;
    delete pOrdinaryNurse;
    return;
}


void doctorTreatDiseaseByHeadNurse() {
    HeadNurse *pHeadnurse = NULL;
    Doctor *doctor = NULL;
    Command *command1 = NULL;
    Command *command2 = NULL;

    doctor = new Doctor;

    command1 = new CommandTreatEye(doctor);
    command2 = new CommandTreatNose(doctor);

    pHeadnurse = new HeadNurse();
    pHeadnurse->setCommand(command1);
    pHeadnurse->setCommand(command2);

    pHeadnurse->SubmittedCase();

    delete doctor;
    delete command1;
    delete command2;
    delete pHeadnurse;
    return;
}

void echoPrint(string str) {
    std::cout << str << std::endl;
}

int main() {
    echoPrint("doctor treat disease direct");
    doctorTreatDiseaseInDirect();

    echoPrint("doctor treat disease in command");
    doctorTreatDiseaseInCommand();

    echoPrint("doctor treat disease by nuser command");
    doctorTreatDiseaseByNurse();

    echoPrint("doctor treat disease by head nuser command");
    doctorTreatDiseaseByHeadNurse();
    return 0;
}