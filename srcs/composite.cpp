#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Component
{
public:
    string m_strName;
    Component(string strName)
    {
        m_strName = strName;
    }
    virtual void Add(Component *com) = 0;
    virtual void Display(int nDepth) = 0;
};
class Leaf : public Component
{
public:
    Leaf(string strName): Component(strName) {}
    virtual void Add(Component *com)
    {
        cout << "leaf can't add" << endl;
    }
    virtual void Display(int nDepth)
    {
        string strtemp;
        for(int i = 0; i < nDepth; i++)
        {
            strtemp += "-" ;
        }
        strtemp += m_strName;
        cout << strtemp << endl;
    }
};
class Composite : public Component
{
private:
    vector<Component *> m_component;
public:
    Composite(string strName) : Component(strName) {}
    virtual void Add(Component *com)
    {
        m_component.push_back(com);
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
		
	    {
			vector<Component *>::iterator p = m_component.begin();
			while (p != m_component.end())
			{
				(*p)->Display(nDepth +1);
				p++;
			}
		}
    }
};
//¿Í»§¶Ë
int main()
{
    Composite *p = new Composite("Mr wang");
    p->Add(new Leaf("Mr li"));
    p->Add(new Leaf("Mr zhao"));
    Composite *p1 = new Composite("Mr wu");
	
    Composite *p2 = new Composite("Mr liu");
	p2->Add(new Leaf("Mr shuan"));
    p1->Add(p2);
    p1->Add(new Leaf("Mr san"));
    p->Add(p1);
	
    p->Display(1);
    return 0;
}

