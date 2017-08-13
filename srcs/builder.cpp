#include <string>
#include <iostream>
#include <vector>
using namespace std;
//���յĲ�Ʒ��
class Product
{
private:
    vector<string> m_product;
public:
    void Add(string strtemp)
    {
        m_product.push_back(strtemp);
    }
    void Show()
    {cout << __FUNCTION__ << ":" << __LINE__ << endl;
        vector<string>::iterator p = m_product.begin();
        while (p != m_product.end())
        {
            cout << *p << endl;
            p++;
        }
    }
};
//�����߻���
class Builder
{
public:
    virtual void BuilderA() = 0;
    virtual void BuilderB() = 0;
    virtual Product *GetResult() = 0;
};
//��һ�ֽ��췽ʽ
class ConcreteBuilder1 : public Builder
{
private:
    Product *m_product;
public:
    ConcreteBuilder1()
    {
        m_product = new Product();
    }
    virtual void BuilderA()
    {cout << __FUNCTION__ << ":" << __LINE__ << endl;
        m_product->Add("one");
    }
    virtual void BuilderB()
    {cout << __FUNCTION__ << ":" << __LINE__ << endl;
        m_product->Add("two");
    }
    virtual Product *GetResult()
    {
        return m_product;
    }
};
//�ڶ��ֽ��췽ʽ
class ConcreteBuilder2 : public Builder
{
private:
    Product *m_product;
public:
    ConcreteBuilder2()
    {cout << __FUNCTION__ << ":" << __LINE__ << endl;
        m_product = new Product();
    }
    virtual void BuilderA()
    {cout << __FUNCTION__ << ":" << __LINE__ << endl;
        m_product->Add("A");
    }
    virtual void BuilderB()
    {cout << __FUNCTION__ << ":" << __LINE__ << endl;
        m_product->Add("B");
    }
    virtual Product *GetResult()
    {
        return m_product;
    }
};
//ָ������
class Direct
{
public:
    void Construct(Builder *temp)
    {
        temp->BuilderA();
        temp->BuilderB();
    }
};
//�ͻ���
int main()
{
    Direct *p = new Direct();
    Builder *b1 = new ConcreteBuilder1();
    Builder *b2 = new ConcreteBuilder2();
    p->Construct(b1); //���õ�һ�ַ�ʽ
    Product *pb1 = b1->GetResult();
    pb1->Show();
    p->Construct(b2); //���õڶ��ַ�ʽ
    Product *pb2 = b2->GetResult();
    pb2->Show();
    return 0;
}

