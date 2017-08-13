#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Company
{
protected:
    string m_strName;
public:
    Company(string strName)
    {
        m_strName = strName;
    }
    virtual void Add(Company *c) = 0;
    virtual void Display(int nDepth) = 0;
    virtual void LineOfDuty() = 0;
};
class ConcreteCompany: public Company
{
private:
    vector<Company *> m_company;
public:
    ConcreteCompany(string strName): Company(strName) {}
    virtual void Add(Company *c)
    {
        m_company.push_back(c);
    }
    virtual void Display(int nDepth)
    {
        string strtemp;
        for(int i = 0; i < nDepth; i++)
        {
            strtemp += "-";
        }
        strtemp += m_strName;
        cout << strtemp << endl;
        vector<Company *>::iterator p = m_company.begin();
        while (p != m_company.end())
        {
            (*p)->Display(nDepth + 1);
            p++;
        }
    }
	//???????????????????
    virtual void LineOfDuty()
    {
        vector<Company *>::iterator p = m_company.begin();
        while (p != m_company.end())
        {
            (*p)->LineOfDuty();
            p++;
        }
    }
};

class HrDepartment : public Company
{
public:
    HrDepartment(string strname) : Company(strname) {}
    virtual void Display(int nDepth)
    {
        string strtemp;
        for(int i = 0; i < nDepth; i++)
        {
            strtemp += "-";
        }
        strtemp += m_strName;
        cout << strtemp << endl;
    }
    virtual void Add(Company *c)
    {
        cout << "error" << endl;
    }
    virtual void LineOfDuty()
    {
        cout << m_strName << ":Recruiting people" << endl;
    }
};
//¿Í»§¶Ë£º
int main()
{
    ConcreteCompany *p = new ConcreteCompany("huawei");
    p->Add(new HrDepartment("hr department"));
    ConcreteCompany *p1 = new ConcreteCompany("development department");
    p1->Add(new HrDepartment("development  hr"));
    ConcreteCompany *p2 = new ConcreteCompany("sale department");
    p2->Add(new HrDepartment("sale hr"));
    p->Add(p1);
    p1->Add(p2);
    p->Display(1);
    p->LineOfDuty();
    return 0;
}

