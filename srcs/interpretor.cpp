#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Context;
class AbstractExpression
{
public:
    virtual void Interpret(Context *context) = 0;
};
class Expression : public AbstractExpression
{
public:
    virtual void Interpret(Context *context)
    {
        cout << "Expression" << endl;
    };
};
class NonterminalExpression : public AbstractExpression
{
public:
    virtual void Interpret(Context *context)
    {
        cout << "NonterminalExpression" << endl;
    }
};
class Context
{
public:
    string input;
    string output;
};
//�ͻ���
int main()
{
    Context *context = new Context();
    vector<AbstractExpression *> express;
    express.push_back(new Expression());
    express.push_back(new NonterminalExpression());
    express.push_back(new NonterminalExpression());
    vector<AbstractExpression *>::iterator p = express.begin();
    while (p != express.end())
    {
        (*p)->Interpret(context);
        p++;
    }
    return 0;
}

