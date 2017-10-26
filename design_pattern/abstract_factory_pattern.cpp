#include <iostream>

using namespace std;
/**
 *  设计模式之 抽象工厂模式
 *  1、抽象的工厂 + 抽象的产品
 *  2、产品要继承抽象产品
 *  3、工厂产生产品的方式是，new 出产品并返回 产品的基类指针
 *  4、用产品的基类指针接受工厂new出的产品，也可以用要创建产品的指针接受 new 出的产品。
 */

class AbstractProduct {
public:
    virtual ~AbstractProduct() {}
    virtual void operation() = 0;
};

class ProductA : public AbstractProduct {
public:
    void operation() {
        cout << "productA operation" << endl;
    }
};

class ProductB : public AbstractProduct {
public:
    void operation() {
        cout << "productB operation" << endl;
    }
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual AbstractProduct* CreateProductA() = 0;
    virtual AbstractProduct* CreateProductB() = 0;
};

class ConcerteFactory : public AbstractFactory {
public:
    AbstractProduct* CreateProductA() {
        return new ProductA();
    }

    AbstractProduct* CreateProductB() {
        return new ProductB();
    }
};

int main()
{
    AbstractFactory* factory = new ConcerteFactory();
    AbstractProduct* productA = factory->CreateProductA();
    AbstractProduct* productB = factory->CreateProductB();

    productA->operation();
    productB->operation();

    cout << "Hello World!" << endl;
    return 0;
}
