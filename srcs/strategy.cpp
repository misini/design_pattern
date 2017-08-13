#include <iostream>
#include <stdio.h>

using namespace std;

//策略基类
class COperation
{
public:
    int m_nFirst;
    int m_nSecond;
    virtual double GetResult()
    {
        double dResult = 0;
        return dResult;
    }
};
//策略具体类—加法类
class AddOperation : public COperation
{
public:
    AddOperation(int a, int b)
    {
        m_nFirst = a;
        m_nSecond = b;
    }
    virtual double GetResult()
    {
        return m_nFirst + m_nSecond;
    }
};
class Context
{
private:
    COperation *op;
public:
    Context(COperation *temp)
    {
        op = temp;
    }
    double GetResult()
    {
        return op->GetResult();
    }
};
//客户端
int main()
{
    int a, b;
    char c;
    cout << "input a and b ,please!" << endl;
    cin >> a >> b;
    cout << "input operation ,please!" << endl;
    cin >> c;
    switch(c)
    {
    case '+':
    {
        Context *context = new Context(new AddOperation(a, b));
        cout << context->GetResult() << endl;
        break;
    }
    default:
    {
        cout << "err!" << endl;
        break;
    }
    }
    return 0;
}

