#include <iostream>
#include <string>
using namespace std;
class Player
{
protected:
    string name;
public:
    Player(string strName)
    {
        name = strName;
    }
    virtual void Attack() = 0;
    virtual void Defense() = 0;
};
class Forwards : public Player
{
public:
    Forwards(string strName): Player(strName) {}
public:
    virtual void Attack()
    {
        cout<<"Attack:"  << name << __FUNCTION__ << ":" << __LINE__ << endl;
    }
    virtual void Defense()
    {
        cout<<"Attack:"  << name << __FUNCTION__ << ":" << __LINE__ << endl;
    }
};
class Center : public Player
{
public:
    Center(string strName): Player(strName) {}
public:
    virtual void Attack()
    {
        cout <<"Center:" << name << __FUNCTION__ << ":" << __LINE__ << endl;
    }
    virtual void Defense()
    {
        cout<<"Center:"  << name << __FUNCTION__ << ":" << __LINE__ << endl;
    }
};
//为中场翻译
class TransLater: public Player
{
private:
    Center *player;
public:
    TransLater(string strName): Player(strName)
    {
        player = new Center(strName);
    }
    virtual void Attack()
    {
        player->Attack();
    }
    virtual void Defense()
    {
        player->Defense();
    }
};
//客户端
int main()
{
    Player *p = new TransLater("Mr Li");
    p->Attack();
    return 0;
}

