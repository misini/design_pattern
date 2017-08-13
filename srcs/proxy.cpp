#include <string>
#include <iostream>
using namespace std;
//����ӿ�
class Interface
{
public:
    virtual void Request() = 0;
};
//��ʵ��
class RealClass : public Interface
{
public:
    virtual void Request()
    {
        cout << "real request" << endl;
    }
};
//������
class ProxyClass : public Interface
{
private:
    RealClass *m_realClass;
public:
    virtual void Request()
    {
        m_realClass = new RealClass();
        m_realClass->Request();
        delete m_realClass;
    }
};


int main()
{
    ProxyClass *test = new ProxyClass();
    test->Request();
    return 0;
}
