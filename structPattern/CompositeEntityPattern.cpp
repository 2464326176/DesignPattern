//********************
// Author:  yh
// Time:    2021/6/6.
//
//********************
//

#include <iostream>

using namespace std;

#include "string"
#include "list"
#include "vector"
//组合模式

class IFile {
public:
    virtual void display() = 0;

    virtual int add(IFile *ifile) = 0;

    virtual int remove(IFile *ifile) = 0;

    virtual int addDir(string DirStr)= 0;

    virtual int addFile(string FileStr) = 0;

    virtual list<IFile *> *getChild() = 0;
};

class File : public IFile {
public:
    File(string name) {
        m_name = name;
    }

    virtual void display() {
        cout << m_name << endl;
    }

    virtual int add(IFile *ifile) {
        return -1;
    }

    virtual int remove(IFile *ifile) {
        return -1;
    }

    virtual int addDir(string DirStr) {
        return -1;
    }

    virtual int addFile(string FileStr) {
        return -1;
    }
    virtual list<IFile *> *getChild() {
        return NULL;
    }

private:
    string m_name;
};

class Dir : public IFile {
public:
    Dir(string name) {
        m_name = name;
        m_list = new list<IFile *>;
        m_list->clear();
    }

    virtual void display() {
        cout << m_name << endl;
    }

    virtual int add(IFile *ifile) {
        m_list->push_back(ifile);
        return 0;
    }

    virtual int addDir(string DirStr) {
        Dir *Tmp = new Dir(DirStr);
        m_list->push_back(Tmp);
        return 0;
    }

    virtual int addFile(string FileStr) {
        File *Tmp = new File(FileStr);
        m_list->push_back(Tmp);
        return 0;
    }

    virtual int remove(IFile *ifile) {
        m_list->remove(ifile);
        return 0;
    }

    virtual list<IFile *> *getChild() {
        return m_list;
    }

private:
    string m_name;
    list<IFile *> *m_list;
};

void showTree(IFile *root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        if (i >= level -1) {
            printf("|____");
            break;
        }
        printf("|    ");
    }
    root->display();

    list<IFile *> *mylist = root->getChild();
    if (mylist != NULL)
    {
        for (list<IFile *>::iterator it = mylist->begin(); it != mylist->end(); it++) {

            if ((*it)->getChild() == NULL) {
                for (int i = -1; i <= level; i++) {
                    if (i >= level -1) {
                        printf("|____");
                        break;
                    }
                    printf("|    ");
                }
                (*it)->display();
            } else {
                showTree(*it, level + 1);
            }
        }
    }
}


/*
 * C:\Users\Administrator\Desktop\myGithubCode\DesignPattern
 */


int main() {

    vector<string> DirString;
    DirString.push_back("C");
    DirString.push_back("Users");
    DirString.push_back("Administrator");
    DirString.push_back("Desktop");
    DirString.push_back("myGithubCode");
    DirString.push_back("DesignPattern");

    Dir *root;
    for (int i = 0; i < DirString.size(); ++i) {
        if (i == 0) {
            root = new Dir("C:");
        }
        root->addDir(DirString[i]);
    }

    showTree(root, 0);

    return 0;
}
