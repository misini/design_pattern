#include <string>
#include <iostream>
#include <vector>
using namespace std;
class SecretaryBase;
//抽象观察者
class CObserverBase
{
protected:
    string name;
    SecretaryBase *sub;
public:
    CObserverBase(string strname, SecretaryBase *strsub)
    {
        name = strname;
        sub = strsub;
    }
    virtual void Update() = 0;
};
//具体的观察者，看股票的
class StockObserver : public CObserverBase
{
public:
    StockObserver(string strname, SecretaryBase *strsub) : CObserverBase(strname, strsub)
    {
    }
    virtual void Update();
};
//具体观察者，看 NBA 的
class NBAObserver : public CObserverBase
{
public:
    NBAObserver(string strname, SecretaryBase *strsub) :
        CObserverBase(strname, strsub)
			{}
    virtual void Update();
};
//抽象通知者
class SecretaryBase
{
public:
    string action;
    vector<CObserverBase *> observers;
public:
    virtual void Attach(CObserverBase *observer) = 0;
    virtual void Detach(CObserverBase *observer) = 0;
    virtual void Notify() = 0;
};
//具体通知者
class Secretary : public SecretaryBase
{
public:
    void Attach(CObserverBase *ob)
    {
        observers.push_back(ob);
    }
	
    void Detach(CObserverBase *ob)
    {
    	vector<CObserverBase *>::iterator it = observers.begin();
		for(;it != observers.end();it ++)
		{
			if(*it == ob)
			{
				swap(*it,*(--observers.end()));
				it = observers.end();
				observers.erase(it);
			}
		}
        
    }
    void Notify()
    {
        vector<CObserverBase *>::iterator p = observers.begin();
        while (p != observers.end())
        {
            (*p)->Update();
            p++;
        }
    }
};
void StockObserver::Update()
{
    cout << name << ":" << sub->action << __FUNCTION__ << ":" << __LINE__ << endl;
}
void NBAObserver::Update()
{
    cout << name << ":" << sub->action << __FUNCTION__ << ":" << __LINE__ << endl;
}


int main()
{
    SecretaryBase *p = new Secretary(); //创建观察者
    //被观察的对象
    CObserverBase *s1 = new NBAObserver("Mr Li", p);
    CObserverBase *s2 = new StockObserver("Mr zhao", p);
    //加入观察队列
    p->Attach(s1);
    p->Attach(s2);
    //事件
    p->action = "Boss coming!";
    //通知
    p->Notify();

	p->Detach(s1);
	p->Notify();

	
    return 0;
}

