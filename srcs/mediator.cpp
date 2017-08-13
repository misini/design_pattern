#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Colleague;
//中介者类
class Mediator
{
public:
    virtual void Send(string message, Colleague *col) = 0;
};
//抽象同事类
class Colleague
{
protected:
    Mediator *mediator;
public:
    Colleague(Mediator *temp)
    {
        mediator = temp;
    }
};
//同事一
class Colleague1 : public Colleague
{
public:
    Colleague1(Mediator *media) : Colleague(media) {}
    void Send(string strMessage)
    {
        mediator->Send(strMessage, this);
    }
    void Notify(string strMessage)
    {
        cout << "Colleague1:" << strMessage << endl;
    }
};
//同事二
class Colleague2 : public Colleague
{
public:
    Colleague2(Mediator *media) : Colleague(media) {}
    void Send(string strMessage)
    {
        mediator->Send(strMessage, this);
    }
    void Notify(string strMessage)
    {
        cout << "Colleague2:" << strMessage << endl;
    }
};
//具体中介者类
class ConcreteMediator : public Mediator
{
public:
    Colleague1 *col1;
    Colleague2 *col2;
    virtual void Send(string message, Colleague *col)
    {
        if(col == col1)
            col2->Notify(message);
        else
            col1->Notify(message);
    }
};
//客户端：
int main()
{
    ConcreteMediator *m = new ConcreteMediator();
    //让同事认识中介
    Colleague1 *col1 = new Colleague1(m);
    Colleague2 *col2 = new Colleague2(m);
    //让中介认识具体的同事类
    m->col1 = col1;
    m->col2 = col2;
    col1->Send("Did you have a meal?");
    col2->Send("No,do you having a meal with me?");
    return 0;
}


