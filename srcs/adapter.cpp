#include <iostream>
using namespace std;
class Target
{
public:
    virtual void Request()
    {
        cout<< __FUNCTION__ << ":" << __LINE__ << endl;
    }
};
class Adaptee
{
public:
    void SpecificalRequest()
    {
        cout  << __FUNCTION__ << ":" << __LINE__ << endl;
    }
};
class Adapter : public Target
{
private:
    Adaptee *ada;
public:
    virtual void Request()
    {
        ada->SpecificalRequest();
        Target::Request();
    }
    Adapter()
    {
        ada = new Adaptee();
    }
    ~Adapter()
    {
        delete ada;
    }
};
//¿Í»§¶Ë
int main()
{
    Adapter *ada = new Adapter();
    ada->Request();
    delete ada;
    return 0;
}

