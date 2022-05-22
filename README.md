# DesignPattern



# 一、创建型设计模式

通常和对象的创建有关，涉及到对象实例化的方式。

## 1.1 [工厂方法模式](createPattern/factory/factoryPattern.md)（Factory Method Pattern）（将实例的生成交给子类）

定义一个创建产品对象的工厂接口，将实际创建工作推迟到子类中。

## 1.2 抽象工厂模式（Abstract Factory Pattern）（将关联零件做组装成产品）

提供一个创建一系列相关或者相互依赖的接口，而无需指定它们具体的类。

## 1.3 建造者模式（Builder Pattern）

将一个复杂的构建与其表示相分离，使得同样的构建过程可以创建不同的表示。

## 1.4 原型模式（Prototype Pattern）

用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。

## 1.5 单例模式（Singleton Pattern）

保证一个类仅有一个实例，并提供一个访问它的全局访问点。

# 二、结构型设计模式

​	结构型模式： 描述的是如何组合类和对象以获得更大的结构。(共7种模式)

## 2.1 代理模式（Proxy Pattern）

就是为其他对象提供一种代理以控制对这个对象的访问。

## 2.2 装饰者模式（Decorator Pattern）

动态的给一个对象添加一些额外的职责。就增加功能来说，此模式比生成子类更为灵活。 

## 2.3 适配器模式（Adapter Pattern）

将一个类的接口转换成客户希望的另外一个接口。使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。 

## 2.4 桥接模式（Bridge Pattern）

将抽象部分与实际部分分离，使它们都可以独立的变化。

## 2.5 组合模式（Composite Pattern）

将对象组合成树形结构以表示“部分--整体”的层次结构。使得用户对单个对象和组合对象的使用具有一致性。

## 2.6 外观模式（Facade Pattern）

为子系统中的一组接口提供一个一致的界面，此模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。

## 2.7 享元模式（Flyweight Pattern）

以共享的方式高效的支持大量的细粒度的对象。

# 三、行为型设计模式

行为型模式： 用来对类或对象怎样交互和怎样分配职责进行描述。

## 3.1 模板方法模式（Template Method Pattern）

使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。 

## 3.2 命令模式（Command Pattern）

将一个请求封装为一个对象，从而使你可用不同的请求对客户端进行参数化；对请求排队或记录请求日志，以及支持可撤销的操作。

## 3.3 责任链模式（Chain of Responsibility Pattern）

在该模式里，很多对象由每一个对象对其下家的引用而连接起来形成一条链。请求在这个链上传递，直到链上的某一个对象决定处理此请求，这使得系统可以在不影响客户端的情况下动态地重新组织链和分配责任。 

##  3.4 策略模式（Strategy Pattern）

准备一组算法，并将每一个算法封装起来，使得它们可以互换。

## 3.5 中介者模式（Mediator Pattern）

就是定义一个中介对象来封装系列对象之间的交互。终结者使各个对象不需要显示的相互调用 ，从而使其耦合性松散，而且可以独立的改变他们之间的交互。

## 3.6 观察者模式（Observer Pattern）

定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。

## 3.7 备忘录模式（Memento Pattern）

在不破坏封装的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。

## 3.8 访问者模式（Visitor Pattern）

表示一个作用于某对象结构中的各元素的操作，它使你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。

## 3.9 状态模式（State Pattern）

对象的行为，依赖于它所处的状态。

## 3.10 解释器模式（Interpreter Pattern）

描述了如何为简单的语言定义一个语法，如何在该语言中表示一个句子，以及如何解释这些句子。 

## 3.11 迭代器模式（Iterator Pattern）

提供了一种方法顺序来访问一个聚合对象中的各个元素，而又不需要暴露该对象的内部表示。

# c++ file

- 单例模式					SingletonPattern.cpp
- 工厂模式					FactoryPattern.cpp			
- 抽象工厂模式			AbstractFactory				
- 建造者模式				BuilderPattern.cpp			
- 原型模式					PrototypePattern.cpp		
- 适配器模式				AdapterPattern.cpp			
- 桥接模式					BridgePattern.cpp			
- 过滤器模式				FilterPattern.cpp			
- 过滤器模式				FilterPattern.cpp			
- 组合模式					CompositePattern.cpp		
- 装饰器模式				DecoratorPattern.cpp		
- 外观模式					FacadePattern.cpp			
- 享元模式					FlyweightPattern.cpp		
- 在代理模式				ProxyPattern.cpp			
- 责任链模式				ChainofResponsibilityPattern.cpp
- 命令模式					CommandPattern.cpp			
- 解释器模式				InterpreterPattern.cpp		
- 迭代器模式				IteratorPattern.cpp		
- 中介者模式				MediatorPattern.cpp		
- 备忘录模式				MementoPattern.cpp			
- 观察者模式				ObserverPattern.cpp		
- 在状态模式				StatePattern.cpp			
- 在空对象模式			NullObjectPattern.cpp		
- 在策略模式				StrategyPattern.cpp		
- 在模板模式				TemplatePattern.cpp		
- 在访问者模式			VisitorPattern.cpp			
- 业务代表模式			BusinessDelegatePattern.cpp
- 组合实体模式			CompositeEntityPattern.cpp
- 数据访问对象模式	DataAccessObjectPattern.cpp
- 前端控制器模式		FrontControllerPattern.cpp
- 拦截过滤器模式		InterceptingFilterPattern.cpp
- 服务定位器模式		ServiceLocatorPattern.cpp	
- 传输对象模式			TransferObjectPattern.cpp	

# UML类与类之间的关系：

泛化(空心三角箭头实线)

实现(空心三角箭头虚线)

依赖（虚线）：一个类是另外一个类的函数参数或者函数返回值

关联（实线）：关联 张三有车 一个类是另外一个类的成员变量

聚合（空心菱形实线）：整体和部分的关系 汽车和发动机 （汽车可以选择各个型号的发动机）

组合（实心型加实线）：生命体， 整体和部分的关系，汽车 发动机，人和五脏六肺

## 泛化(Generalization)

表示类与类之间的继承关系，接口与接口之间的继承关系，或类对接口的实现关系。一般化的关系是从子类指向父类的，与继承或实现的方法相反。

一般用带三角箭头的实线，箭头指向父类；

## 实现（Realization）

是一种类与接口的关系，表示类是接口所有特征和行为的实现；

带三角箭头的虚线，箭头指向接口；

## 关联(Association)

对于两个相对独立的对象，当一个对象的实例与另一个对象的一些特定实例存在固定的对应关系时，这两个对象之间为关联关系；

带普通箭头的实心线，指向被拥有者;

## 依赖(Dependency)

对于两个相对独立的对象，当一个对象负责构造另一个对象的实例，或者依赖另一个对象的服务时，这两个对象之间主要体现为依赖关系；

带箭头的虚线，指向被使用者;

## 聚合（Aggregation）

当对象A被加入到对象B中，成为对象B的组成部分时，对象B和对象A之间为聚集关系。聚合是关联关系的一种，是较强的关联关系，强调的是整体与部分之间的关系。

带空心菱形的实心线，菱形指向整体；

## 组合（Composition）

表整体的对象负责代表部分对象的生命周期。公司不存在，部门也没有意义了。

带实心菱形的实线，菱形指向整体;







































- 