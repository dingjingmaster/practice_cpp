#include <iostream>

using namespace std;

/**
 *  建造者模式
 *  Builder: 给出一个抽象接口，以规定产品对象的各个组成成分的构造。这个接口规定要实现复杂对象的哪些部分的构建，不涉及部件的构建
 *  ConcreteBuilder: 实现Builder接口，针对应用场景实现各个部分部件的创建
 *  Director: 调用具体构建者来创建复杂对象的各个部分，在指导中不涉及具体产品的信息，只负责保证各个产品各部件的创建顺序。
 *  Product: 要创建的复杂对象。
 */

class Product{
public:
    Product() {
        cout << "Product ..." << endl;
    }
};

class Builder {
public:
    virtual void BuilderPartA() = 0;
    virtual void BuilderPartB() = 0;
    virtual void BuilderPartC() = 0;
    virtual Product* GetProdect() = 0;
};

class ConcreteBuilder:public Builder {
public:
    virtual void BuilderPartA() {
        cout << "build A" << endl;
    }

    virtual void BuilderPartB() {
        cout << "build B" << endl;
    }

    virtual void BuilderPartC() {
        cout << "build C" << endl;
    }

    virtual Product* GetProdect() {
        return new Product();
    }

//private:
//    Product* product;
};

class Director {
public:
    Director(Builder* pbuilder) {
        builder = pbuilder;
    }

    void construct() {
        builder->BuilderPartA();
        builder->BuilderPartB();
        builder->BuilderPartC();
    }
private:
    Builder* builder;
};

int main()
{
    auto builder = new ConcreteBuilder();
    auto dir = new Director(builder);
    dir->construct();
    Product* pro = builder->GetProdect();

    return 0;
}