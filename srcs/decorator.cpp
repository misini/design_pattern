#include <string>
#include <iostream>
using namespace std;
//��
class Person
{
private:
    string m_strName;
public:
    Person(string strName)
    {
        m_strName = strName;
        cout << __FUNCTION__ << endl;
    }
    Person() {}
    virtual void Show()
    {
        cout << "decorated:" << m_strName << endl;
    }
};

//Ϊɶ����Ҫ�̳�
//componentֻ��һ����Ա������Ϲ�ϵ?
//װ����
class Finery: public Person
{
protected:
    Person *m_component;
public:
    Finery()
    {
        cout << __FUNCTION__ << endl;
    }
    void Decorate(Person *component)
    {
        m_component = component;
        cout << __FUNCTION__ << endl;
    }
    virtual void Show()
    {
        m_component->Show();
    }
};

//T ��
class TShirts: public Finery
{
public:
    TShirts()
    {
        cout << __FUNCTION__ << endl;
    }
    virtual void Show()
    {
        cout << "T Shirts" << endl;
        m_component->Show();
    }
};
//����
class BigTrouser : public Finery
{
public:
    BigTrouser()
    {
        cout << __FUNCTION__ << endl;
    }
    virtual void Show()
    {
        cout << "Big Trouser" << endl;
        m_component->Show();
    }
};

//�ͻ���
int main()
{
    Person *p = new Person("xiao_li");
    Finery *f = new Finery();

    BigTrouser *bt = new BigTrouser();
    TShirts *ts = new TShirts();

    bt->Decorate(p);
    //bt->Show();
    //ts->Decorate(p);
    ts->Decorate(bt);
    ts->Show();
    return 0;
}
