#include <iostream>
#include <stdio.h>

using namespace std;

//����
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
//�ӷ�
class AddOperation : public COperation
{
public:
    virtual double GetResult()
    {
        return m_nFirst + m_nSecond;
    }
};
//����
class SubOperation : public COperation
{
public:
    virtual double GetResult()
    {
        return m_nFirst - m_nSecond;
    }

};

//������
class CCalculatorFactory
{
public:
    static COperation *Create(char cOperator);
};

COperation *CCalculatorFactory::Create(char cOperator)
{
    COperation *oper;
    //�� C#�п����÷�����ȡ���ж�ʱ�õ� switch���� C++����ʲô�أ�RTTI����
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