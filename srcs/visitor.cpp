#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Man;
class Woman;
//��Ϊ
class Action
{
public:
    virtual void GetManConclusion(Man *concreteElementA) = 0;
    virtual void GetWomanConclusion(Woman *concreteElementB) = 0;
};
//�ɹ�
class Success : public Action
{
public:
    virtual void GetManConclusion(Man *concreteElementA)
    {
        cout <<"Success:"<< __FUNCTION__ << endl;
    }
    virtual void GetWomanConclusion(Woman *concreteElementB)
    {
        cout <<"Success:"<< __FUNCTION__ << endl;
    }
};
//ʧ��
class Failure : public Action
{
public:
    virtual void GetManConclusion(Man *concreteElementA)
    {
        cout <<"Failure:"<< __FUNCTION__ << endl;
    }
    virtual void GetWomanConclusion(Woman *concreteElementB)
    {
        cout <<"Failure:"<< __FUNCTION__ << endl;
    }
};
//��������
class Person
{
public:
    virtual void Accept(Action *visitor) = 0;
};
//����
class Man : public Person
{
public:
    virtual void Accept(Action *visitor)
    {
        visitor->GetManConclusion(this);
    }
};
//Ů��
class Woman : public Person
{
public:
    virtual void Accept(Action *visitor)
    {
        visitor->GetWomanConclusion(this);
    }
};
//����ṹ��
class ObjectStructure
{
private:
    vector<Person *> m_personList;
public:
    void Add(Person *p)
    {
        m_personList.push_back(p);
    }
    void Display(Action *a)
    {
        vector<Person *>::iterator p = m_personList.begin();
        while (p != m_personList.end())
        {
            (*p)->Accept(a);
            p++;
        }
    }
};
//�ͻ���
int main()
{
    ObjectStructure *os = new ObjectStructure();
    os->Add(new Man());
    os->Add(new Woman());
    Success *success = new Success();
    os->Display(success);
    Failure *fl = new Failure();
    os->Display(fl);
    return 0;
}

