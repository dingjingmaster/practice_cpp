#include <iostream>

using namespace std;

/**
 *  桥接模式
 *  1、小汽车在路上跑
 *  2、为了实现 小汽车 和 路 的解耦合，创建小汽车基类和路的基类
 *  3、路有多中路，小汽车有多种小汽车，两者可以各自变化
 *  4、解耦合的方式是，两者的组合可以通过赋值解决。
 *
 */

class AbstractCar {
public:
    virtual void run() = 0;
};

class Car:public AbstractCar {
public:
    virtual void run() {
        cout << "小汽车在";
    }

};

class Bus:public AbstractCar {
public:
    virtual void run() {
        cout << "公共汽车在";
    }
};


class AbstractRoad {
public:
    virtual void run() = 0;

public:
    AbstractCar* car;
};

class SpeedWay:public AbstractRoad {
public:
    virtual void run() {
        car->run();
        cout << "高速公路上跑" << endl;
    }
};

class Streat:public AbstractRoad {
public:
    virtual void run() {
        car->run();
        cout << "街道上行驶" << endl;
    }
};

int main()
{
    Car* car = new Car();
    car->run();
    Streat* streat = new Streat();
    streat->car = car;
    streat->run();

    cout << "Hello World!" << endl;
    return 0;
}


































