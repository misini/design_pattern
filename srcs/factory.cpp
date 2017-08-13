#include <iostream>
#include <stdio.h>

using namespace std;

//基类
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
//加法
class AddOperation : public COperation
{
public:
    virtual double GetResult()
    {
        return m_nFirst + m_nSecond;
    }
};
//减法
class SubOperation : public COperation
{
public:
    virtual double GetResult()
    {
        return m_nFirst - m_nSecond;
    }

};

//工厂类
class CCalculatorFactory
{
public:
    static COperation *Create(char cOperator);
};

COperation *CCalculatorFactory::Create(char cOperator)
{
    COperation *oper;
    //在 C#中可以用反射来取消判断时用的 switch，在 C++中用什么呢？RTTI？？
    switch (cOperator)
    {
    case '+':
        oper = new AddOperation();
        break;
    case '-':
        oper = new SubOperation();
        break;
    default:
        oper = new AddOperation();
        break;
    }
    return oper;
}


int main()
{
    int a = 10, b = 2;
    std::cin >> a >> b;
    COperation *op = CCalculatorFactory::Create('-')	;
    op->m_nFirst = a;
    op->m_nSecond = b;
    printf("%f\n", op->GetResult());
    cout << op->GetResult() << endl;
    return 0;
}