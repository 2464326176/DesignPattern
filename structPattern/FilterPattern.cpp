//********************
// Author:  yh 
// Time:    2021/6/8.
// 
//********************
//
#include <iostream>
#include <string>
#include <list>


using namespace std;
class Person {
public:
    Person(string name, string gender, string maritalStatus) {
        m_name = name;
        m_gender = gender;
        m_maritalStatus = maritalStatus;
    }

    string getName() {
        return m_name;
    }

    string getGender() {
        return m_gender;
    }

    string getMaritalStatus() {
        return m_maritalStatus;
    };

private:
    string m_name;
    string m_gender;
    string m_maritalStatus;
};


class Criteria {
public:
    virtual list<Person *> meetCriteria(list<Person *> persons) = 0;
};

class CriteriaMale : public Criteria {
public:
    list<Person *> meetCriteria(list<Person *> persons) {
        list<Person *> malePersons;

        for (auto &person : persons) {
            if (person->getGender() == "MALE") {
                malePersons.push_back(person);
            }
        }
        return malePersons;
    }

};

class CriteriaFemale : public Criteria {
public:
    list<Person *> meetCriteria(list<Person *> persons) {
        list<Person *> femalePersons;

        for (auto &person : persons) {
            if (person->getGender() == "FEMALE") {
                femalePersons.push_back(person);
            }
        }
        return femalePersons;
    }

};

class CriteriaSingle : public Criteria {
public:
    list<Person *> meetCriteria(list<Person *> persons) {
        list<Person *> singlePersons;

        for (auto &person : persons) {
            if (person->getGender() == "SINGLE") {
                singlePersons.push_back(person);
            }
        }
        return singlePersons;
    }

};

class AndCriteria : public Criteria {
public:
    AndCriteria(Criteria *criteria, Criteria *otherCriteria) {
        m_criteria = criteria;
        m_otherCriteria = otherCriteria;
    }

    list<Person *> meetCriteria(list<Person *> persons) {
        list<Person *> firstPersons = m_criteria->meetCriteria(persons);
        return m_otherCriteria->meetCriteria(firstPersons);
    }

private:
    Criteria *m_criteria;
    Criteria *m_otherCriteria;
};

class OrCriteria : public Criteria {
public:
    OrCriteria(Criteria *criteria, Criteria *otherCriteria) {
        m_criteria = criteria;
        m_otherCriteria = otherCriteria;
    }

    list<Person *> meetCriteria(list<Person *> persons) {
        list<Person *> firstPersons = m_criteria->meetCriteria(persons);
        list<Person *> secondPersons = m_otherCriteria->meetCriteria(persons);

        for(auto secondP : secondPersons) {
            bool bFind = false;
            for (auto firstP : firstPersons) {
                if (firstP == secondP) {
                    bFind = true;
                    break;
                }
            }

            if(!bFind) {
                firstPersons.push_back(secondP);
            }
        }

        return firstPersons;
    }

private:
    Criteria *m_criteria;
    Criteria *m_otherCriteria;
};

void printPersons(list<Person *> persons) {
    for (auto person : persons) {
        cout << "name:" << person->getName()    \
        << "\tgender:" << person->getGender()         \
        << "\tmarital status:" << person->getMaritalStatus()         \
        << endl;
    }
}

int main() {
    list<Person *> persons;

    persons.push_back(new Person("Robert","MALE", "Single"));
    persons.push_back(new Person("John","MALE", "Married"));
    persons.push_back(new Person("Laura","FEMALE", "Married"));
    persons.push_back(new Person("Diana","FEMALE", "Single"));
    persons.push_back(new Person("Mike","MALE", "Single"));
    persons.push_back(new Person("Bobby","MALE", "Single"));

    Criteria *male = new CriteriaMale();
    Criteria *female = new CriteriaFemale();
    Criteria *single = new CriteriaSingle();

    Criteria *singleMale = new AndCriteria(single, male);
    Criteria *singleOrFemale = new OrCriteria(single, female);

    cout << "males" << endl;
    printPersons(male->meetCriteria(persons));

    cout << "\nfemales" << endl;
    printPersons(female->meetCriteria(persons));

    cout << "\nsingle males" << endl;
    printPersons(single->meetCriteria(persons));

    cout << "\nsingle females" << endl;
    printPersons(singleMale->meetCriteria(persons));

    cout << "\nsingle or females" << endl;
    printPersons(singleOrFemale->meetCriteria(persons));

   cout << "\nall" << endl;
    printPersons(persons);
    return 0;
}









