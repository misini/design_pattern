#include<iostream>
#include <vector>
#include <string>
using namespace std;
class AbstractClass
{
public:
    void Show()
    {
        cout << __FUNCTION__ << ":" << __LINE__ << ":" << GetName() << endl;
    }
protected:
    virtual string GetName() = 0;
};
class Naruto : public AbstractClass
{
protected:
    virtual string GetName()
    {
    	cout << __FUNCTION__ << ":" << __LINE__ << endl;
        return __FUNCTION__;
    }
};
class OnePice : public AbstractClass
{
protected:
    virtual string GetName()
    {
    	cout << __FUNCTION__ << ":" << __LINE__ << endl;
        return __FUNCTION__;
    }
};
//¿Í»§¶Ë
int main()
{
    Naruto *man = new Naruto();
    man->Show();
    OnePice *man2 = new OnePice();
    man2->Show();
    return 0;
}

