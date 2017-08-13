#include <iostream>
#include <vector>
#include <string>

using namespace std;





class Iterator_C
{
public:
	//Iterator_C(){};
	//virtual  ~Iterator_C(){};
	virtual string First() = 0;
	virtual string Next() = 0;
	virtual bool IsDone() = 0;
	virtual string CurrentItem() = 0;
};


class Aggregate_C
{
public:
	virtual Iterator_C* CreateIterator() = 0;
	virtual int Count() = 0;
	virtual string &operator[](std::size_t index ) = 0;
};

class c_ConcreteIterator;

class c_ConcreteAggregate : public Aggregate_C
{
private:
	vector<string> v_items;
public:
	Iterator_C* CreateIterator()
	{
		return new c_ConcreteIterator(this);
	}
	
	int Count()
	{
		return v_items.size();
	}
	//llq,ÏÂ±êË÷Òý
	string &operator[](std::size_t index )
	{
		return v_items[index];
	}
};



class c_ConcreteIterator : public Iterator_C
{
private :
	c_ConcreteAggregate *aggregate;
	int current;
public:
	c_ConcreteIterator(c_ConcreteAggregate *aggregate)
	:Iterator_C(),aggregate(aggregate),current(0)
	{
	}

	string First()
	{
		return (*aggregate)[0];
	}
	string Next()
	{
		string ret = NULL;
		current ++;
		if(current < aggregate->Count())
		{
			ret = (*aggregate)[current];
		}

		return ret;
	}

	bool IsDone()
	{
		return current >= aggregate->Count() ? true : false;
	}
	string CurrentItem()
	{
		return (*aggregate)[current];

	}
};






int main()
{
	c_ConcreteAggregate *a = new c_ConcreteAggregate();

	(*a)[0] = "asdf";

	c_ConcreteIterator *i = new c_ConcreteIterator(a);

	string item = i->First();
	while(!i->IsDone())
	{
		cout<<i->CurrentItem()<< ",buy ticket,please!" << endl;
	}
	
	return 0;
}
