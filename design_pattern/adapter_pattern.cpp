#include <iostream>

using namespace std;

/**
 *  适配器模式
 *  1、目标接口(Target)、需要适配的类(Adaptee)、适配器(Adapter)
 *  2、适配器 同时继承 目标接口 和 需要适配的类(私有继承)
 *  3、适配器接受需要适配的类，调用需要适配的类的方法
 *  4、使用时，用目标接口指针类型接收适配器new出的指针，使用Targe就可以通过Adapter调用Adaptee的方法
 */

class Target {
public:
    virtual void Request() {
        cout << "Target::Request..." << endl;
    }
    virtual ~Target() {}
};

class Adaptee {
public:
    void SpecificRequest() {
        cout << "Adaptee::SpecificRequest..." << endl;
    }
};

class Adapter : public Target, private Adaptee {
public:
    Adapter (Adaptee* ad) {
        _ad = ad;
    }

    void Request() {
        _ad->SpecificRequest();
    }
private:
    Adaptee* _ad;
};

int main()
{
    Adaptee* adaptee = new Adaptee();
    Target* adapter = new Adapter(adaptee);

    adapter->Request();

    delete adapter;
    delete adaptee;

    cout << "Hello World!" << endl;
    return 0;
}
