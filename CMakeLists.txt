cmake_minimum_required(VERSION 3.13)


set(CMAKE_CXX_STANDARD 11)


#behaviorPattern/CommandPattern.cpp
#behaviorPattern/InteratorPattern.cpp
#behaviorPattern/InterpreterPattern.cpp
#behaviorPattern/IteratorPattern.cpp
#behaviorPattern/MediatorPattern.cpp
#behaviorPattern/MediatorPattern1.cpp
#behaviorPattern/MementoPattern.cpp
#behaviorPattern/ModelViewController.cpp
#behaviorPattern/ObserverPattern.cpp
#behaviorPattern/ServiceLocatorPattern.cpp
#behaviorPattern/StatePattern.cpp
#behaviorPattern/StrategyPattern.cpp
#behaviorPattern/TemplatePattern.cpp
#behaviorPattern/TransferObjectPattern.cpp
#behaviorPattern/VisitorPattern.cpp


#createPattern/AbstructFactoryPattern.cpp
#createPattern/AbstructFactoryPattern1.cpp
#createPattern/SimpleFactoryPattern.cpp
#createPattern/SingletonPattern.cpp
#createPattern/SingletonPattern1.cpp

#structPattern/AdapterPattern.cpp
#structPattern/BridgePattern.cpp
#structPattern/BuildPattern.cpp
#structPattern/CompositeEntityPattern.cpp
#structPattern/DecoratorPattern.cpp
#structPattern/FacadePattern.cpp
#structPattern/FilterPattern.cpp
#structPattern/FlyweightPattern.cpp
#structPattern/PrototypePattern.cpp
#structPattern/ProxyPattern.cpp

add_executable(opencv
        structPattern/FlyweightPattern.cpp
        )
#添加动态链接库


