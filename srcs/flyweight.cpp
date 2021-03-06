#include <iostream>
#include <string>
#include <vector>
using namespace std;
//抽象的网站
class WebSite
{
public:
    virtual void Use() = 0;
};
//具体的共享网站
class ConcreteWebSite : public WebSite
{
private:
    string name;
public:
    ConcreteWebSite(string strName)
    {
        name = strName;
    }
    virtual void Use()
    {
        cout << __FUNCTION__ << name << endl;
    }
};
//不共享的网站
class UnShareWebSite : public WebSite
{
private:
    string name;
public:
    UnShareWebSite(string strName)
    {
        name = strName;
    }
    virtual void Use()
    {
        cout << __FUNCTION__ << name << endl;
    }
};
//网站工厂类，用于存放共享的 WebSite 对象
class WebFactory
{
private:
    vector<WebSite *> websites;
public:
    WebSite *GetWeb()
    {
        vector<WebSite *>::iterator p = websites.begin();
        return *p;
    }
    WebFactory()
    {
        websites.push_back(new ConcreteWebSite(":testing"));
    }
};
//客户端
int main()
{
    WebFactory *f = new WebFactory();
    WebSite *ws = f->GetWeb();
    ws->Use();
    WebSite *ws2 = f->GetWeb();
    ws2->Use();
    //不共享的类
    WebSite *ws3 = new UnShareWebSite(":testing:");
    ws3->Use();
    return 0;
}
