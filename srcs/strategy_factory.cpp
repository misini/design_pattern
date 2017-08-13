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
    AddOperation(int a = 2, int b = 3)
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
    Context(char cType)
    {
        switch (cType)
        {
        case '+':
            op = new AddOperation(3, 8);
            break;
        default:
            op = new AddOperation();
            break;
        }
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
    cin >> a >> b;
    Context *test = new Context('+');
    cout << test->GetResult() << endl;
    return 0;
}


