#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Secretary;
//看股票的同事类（观察对象，观察者）
class StockObserver
{
private:
    string name;
    Secretary *sub;
public:
    StockObserver(string strname, Secretary *strsub)
    {
        name = strname;
        sub = strsub;
    }
    void Update();
};
//秘书类（主题对象，通知者）
class Secretary
{
private:
    vector<StockObserver> observers;
public:
    string action;
    void Add(StockObserver ob)
    {
        observers.push_back(ob);
    }
    void Notify()
    {
        vector<StockObserver>::iterator p = observers.begin();
        while (p != observers.end())
        {
            (*p).Update();
            p++;
        }
    }
};
void StockObserver::Update()
{
    cout << name << ":" << sub->action << ",don't watching stock,it's time to working!" << endl;
}
//客户端
int main()
{
    Secretary *p = new Secretary(); //创建通知者
    //观察者
    StockObserver *s1 = new StockObserver("Mr Li", p);
    StockObserver *s2 = new StockObserver("Mr Zhao", p);
    //加入通知队列
    p->Add(*s1);
    p->Add(*s2);
    //事件
    p->action = "Boss coming!";
    //通知
    p->Notify();
    return 0;
}

