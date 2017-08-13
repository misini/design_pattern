#include <iostream>
using namespace std;
class Work;
class ForenoonState;
class NoonState;
class State
{
public:
    virtual void WriteProgram(Work *w) = 0;
};
class Work
{
private:
    State *current;
public:
    double hour;
public:
	Work();
	~Work();
    void SetState(State *temp)
    {
		if(	NULL != current)
		{
			delete current; //内存泄漏 ?
		}
        current = temp;
    }
    void Writeprogram()
    {
        current->WriteProgram(this);
    }
};
class NoonState : public State
{
public:
    virtual void WriteProgram(Work *w)
    {
        cout << "execute" << endl;
        if((w->hour) < 13)
            cout << "it so good!" << endl;
        else
            cout << "I'm tired,it's time to sleeping!" << endl;
    }
};
class ForenoonState : public State
{
public:
    virtual void WriteProgram(Work *w)
    {
        if((w->hour) < 12)
            cout << "I am feeling so good!" << endl;
        else
        {
        	
            w->SetState(new NoonState());
            w->Writeprogram(); //注意加上这句
        }
    }
};
Work::Work()
{
    current = new ForenoonState();
}
Work::~Work()
{
	if( NULL != current)
	{
		delete current; //内存泄漏 ?
	}
}

int main()
{
    Work *mywork = new Work();
    mywork->hour = 9;
    mywork->Writeprogram();
    mywork->hour = 14;
    mywork->Writeprogram();

	delete mywork;
	
    return 0;
}

