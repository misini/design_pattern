#include <string>
#include <iostream>
using namespace std;
//ʵ�����࣬�൱�� Product(Ϊ�˷��㣬û�ó���)
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
//ѧ�׷�Ĵ�ѧ�����൱�� ConcreteProduct
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
//ѧ�׷��־Ը�ߣ��൱�� ConcreteProduct
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
//�������� Creator
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
//����������
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
//�ͻ���
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

