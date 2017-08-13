#include <string>
#include <iostream>
#include <vector>
using namespace std;
//�û�����ӿ�
class IUser
{
public :
    virtual void GetUser() = 0;
    virtual void InsertUser() = 0;
};
//���ų���ӿ�
class IDepartment
{
public:
    virtual void GetDepartment() = 0;
    virtual void InsertDepartment() = 0;
};
//ACCESS �û�
class CAccessUser : public IUser
{
public:
    virtual void GetUser()
    {
        cout << "Access GetUser" << endl;
    }
    virtual void InsertUser()
    {
        cout << "Access InsertUser" << endl;
    }
};
//ACCESS ����
class CAccessDepartment : public IDepartment
{
public:
    virtual void GetDepartment()
    {
        cout << "Access GetDepartment" << endl;
    }
    virtual void InsertDepartment()
    {
        cout << "Access InsertDepartment" << endl;
    }
};
//SQL �û�
class CSqlUser : public IUser
{
public:
    virtual void GetUser()
    {
        cout << "Sql User" << endl;
    }
    virtual void InsertUser()
    {
        cout << "Sql User" << endl;
    }
};
//SQL ������
class CSqlDepartment: public IDepartment
{
public:
    virtual void GetDepartment()
    {
        cout << "sql getDepartment" << endl;
    }
    virtual void InsertDepartment()
    {
        cout << "sql insertdepartment" << endl;
    }
};
//���󹤳�
class IFactory
{
public:
    virtual IUser *CreateUser() = 0;
    virtual IDepartment *CreateDepartment() = 0;
};
//ACCESS ����
class AccessFactory : public IFactory
{
public:
    virtual IUser *CreateUser()
    {
        return new CAccessUser();
    }
    virtual IDepartment *CreateDepartment()
    {
        return new CAccessDepartment();
    }
};
//SQL ����
class SqlFactory : public IFactory
{
public:
    virtual IUser *CreateUser()
    {
        return new CSqlUser();
    }
    virtual IDepartment *CreateDepartment()
    {
        return new CSqlDepartment();
    }
};

int main()
{
    IFactory *factory = new SqlFactory();
    IUser *user = factory->CreateUser();
    IDepartment *depart = factory->CreateDepartment();
    user->GetUser();
    depart->GetDepartment();


	
    return 0;
}
