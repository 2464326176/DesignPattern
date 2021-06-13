//********************
// Author:  yh 
// Time:    2021/6/10.
// 
//********************
//
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Service {
public:
    virtual string getName() = 0;
    virtual void execute() = 0;
};

class FirstService : public Service {
public:
    void execute () {
        cout << "first service" << endl;
    }

    string getName() {
        return "FirstService";
    }
};

class SecondService : public Service {
public:
    void execute () {
        cout << "second service" << endl;
    }

    string getName() {
        return "SecondService";
    }
};

class InitialContext {
public:
    Service* lookUp(string serviceName) {
        Service* tmpService;
        if ( serviceName == "FirstService" ) {
            tmpService = new FirstService();
            cout << "looking up and creating a new FirstService" << endl;
            return tmpService;
        } else if(serviceName == "SecondService") {
            tmpService = new SecondService();
            cout << "looking up and creating a new SecondService" << endl;
            return tmpService;
        }
        return nullptr;
    }
};

class Cache {
public:
    Service* getService(string serviceName) {
        for(auto service : services) {
            if(service->getName() == serviceName) {
                cout << "service->getName():" << service->getName() << endl;
                return service;
            }
        }
        return nullptr;
    }

    void addService(Service* newService) {
        bool exists = false;
        for (auto service : services) {
            if(service == newService) {
                exists = true;
            }
        }

        if(!exists) {
            services.push_back(newService);
        }
    }
public:
    list<Service *> services;
};

/* 服务定位器 */
class ServiceLocator {
public:
    static Service* getService(string serviceName) {
        Service* service = cache->getService(serviceName);

        if(service != nullptr) {
            return service;
        }

        InitialContext* context = new InitialContext();
        Service* firstService = context->lookUp(serviceName);
        cache->addService(firstService);
        return firstService;
    }
public:
    static Cache* cache;
};

Cache* ServiceLocator::cache = new Cache();


int main() {
    Service* service = ServiceLocator::getService("FirstService");
    service->execute();

    service = ServiceLocator::getService("SecondService");
    service->execute();

    service = ServiceLocator::getService("FirstService");
    service->execute();

    service = ServiceLocator::getService("SecondService");
    service->execute();


    return 0;
}
















