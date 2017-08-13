#include<iostream>
#include <string>
using namespace std;
class SubSysOne
{
public:
    void MethodOne()
    {
        cout << __FUNCTION__ << endl;
    }
};
class SubSysTwo
{
public:
    void MethodTwo()
    {
        cout << __FUNCTION__ << endl;
    }
};
class SubSysThree
{
public:
    void MethodThree()
    {
        cout << __FUNCTION__ << endl;
    }
};
//外观类
class Facade
{
private:
    SubSysOne *sub1;
    SubSysTwo *sub2;
    SubSysThree *sub3;
public:
    Facade()
    {
        sub1 = new SubSysOne();
        sub2 = new SubSysTwo();
        sub3 = new SubSysThree();
    }
    ~Facade()
    {
        delete sub1;
        delete sub2;
        delete sub3;
    }
    void FacadeMethod()
    {
        sub1->MethodOne();
        sub2->MethodTwo();
        sub3->MethodThree();
    }
};
//客户端
int main()
{
    Facade *test = new Facade();
    test->FacadeMethod();
    return 0;
}

