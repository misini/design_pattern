#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Person
{
public:
    virtual void CreateHead() = 0;
    virtual void CreateHand() = 0;
    virtual void CreateBody() = 0;
    virtual void CreateFoot() = 0;
};
class ThinPerson : public Person
{
public:
    virtual void CreateHead()
    {
		cout << __FUNCTION__ << ":" << __LINE__ << endl;
    }
    virtual void CreateHand()
    {
		cout << __FUNCTION__ << ":" << __LINE__ << endl;
    }
    virtual void CreateBody()
    {
		cout << __FUNCTION__ << ":" << __LINE__ << endl;
    }
    virtual void CreateFoot()
    {
		cout << __FUNCTION__ << ":" << __LINE__ << endl;
    }
};
class ThickPerson : public Person
{
public:
    virtual void CreateHead()
    {
		cout << __FUNCTION__ << ":" << __LINE__ << endl;
    }
    virtual void CreateHand()
    {
		cout << __FUNCTION__ << ":" << __LINE__ << endl;
    }
    virtual void CreateBody()
    {
		cout << __FUNCTION__ << ":" << __LINE__ << endl;
    }
    virtual void CreateFoot()
    {
		cout << __FUNCTION__ << ":" << __LINE__ << endl;
    }
};
//指挥者类
class Direct
{
private:
    Person *p;
public:
    Direct(Person *temp)
    {
        p = temp;
    }
    void Create()
    {
        p->CreateHead();
        p->CreateBody();
        p->CreateHand();
        p->CreateFoot();
    }
};
//客户端代码：
int main()
{
    Person *p = new ThickPerson();
    Direct *d = new Direct(p);
    d->Create();
    delete d;
    delete p;
    return 0;
}
