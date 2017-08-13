#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Secretary;
//����Ʊ��ͬ���ࣨ�۲���󣬹۲��ߣ�
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
//�����ࣨ�������֪ͨ�ߣ�
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
//�ͻ���
int main()
{
    Secretary *p = new Secretary(); //����֪ͨ��
    //�۲���
    StockObserver *s1 = new StockObserver("Mr Li", p);
    StockObserver *s2 = new StockObserver("Mr Zhao", p);
    //����֪ͨ����
    p->Add(*s1);
    p->Add(*s2);
    //�¼�
    p->action = "Boss coming!";
    //֪ͨ
    p->Notify();
    return 0;
}

