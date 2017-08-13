#include <string>
#include <iostream>
using namespace std;
//实例基类，相当于 Product(为了方便，没用抽象)
class LeiFeng
{
public:
	LeiFeng()
	{
		cout << __FUNCTION__ << endl;
	}
    virtual void Sweep()
    {
        cout << "LeiFeng:";
		cout << __FUNCTION__ << endl;
    }
};
//学雷锋的大学生，相当于 ConcreteProduct
class Student: public LeiFeng
{
public:
	Student()
	{
		cout << __FUNCTION__ << endl;
	}
    virtual void Sweep()
    {
        cout << "Student" << endl;
    }
};
//学雷锋的志愿者，相当于 ConcreteProduct
class Volenter: public LeiFeng
{
public :
	Volenter()
	{
		cout << __FUNCTION__ << endl;
	}
    virtual void Sweep()
    {
        cout << "Volenter" << endl;
    }
};
//工场基类 Creator
class LeiFengFactory
{
public:
	LeiFengFactory()
	{
		cout << __FUNCTION__ << endl;
	}
    virtual LeiFeng *CreateLeiFeng()
    {
        return new LeiFeng();
    }
};
//工场具体类
class StudentFactory : public LeiFengFactory
{
public :
	StudentFactory()
	{
		cout << __FUNCTION__ << endl;
	}
    virtual LeiFeng *CreateLeiFeng()
    {
        return new Student();
    }
};
class VolenterFactory : public LeiFengFactory
{
public:
	VolenterFactory()
	{
		cout << __FUNCTION__ << endl;
	}
    virtual LeiFeng *CreateLeiFeng()
    {
        return new Volenter();
    }
};
//客户端
int main()
{
    LeiFengFactory *sf = new LeiFengFactory();
	cout << "--------------------" << endl;
    LeiFeng *s = sf->CreateLeiFeng();
	cout << "--------------------" << endl;
    s->Sweep();

    delete s;
    delete sf;

    VolenterFactory *Volenter= new VolenterFactory();
	s = Volenter->CreateLeiFeng();
	
    s->Sweep();
    delete s;
    delete Volenter;
    return 0;
}

