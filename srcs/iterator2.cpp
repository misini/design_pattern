#include <iostream>  
#include <vector>  
using namespace std;  
  
/* object可以是任意类型的变量 */  
typedef int object;  
  
class Iterator  
{  
public:  
    virtual object begin() = 0;  
    virtual void   next() = 0;  
    virtual object end() = 0;  
    virtual object current() = 0;  
    virtual bool   IsDone() = 0;  
};  
  
class ConcreteAggregate  
{  
private:  
    vector<object> _objects;  
  
public:  
    void AddObject(object obj)  
    {  
        _objects.push_back(obj);  
    }  
      
    object& operator[](int index)  
    {  
        return _objects[index];  
    }  
    int size()  
    {  
        return _objects.size();  
    }  
};  
  
class ConcreteIterator:public Iterator  
{  
public:  
    ConcreteAggregate *agg;   
    int _index;  
public:  
    ConcreteIterator(ConcreteAggregate *agg)  
    {  
        this->agg = agg;  
        _index = 0;  
    }  
    virtual object begin()  
    {  
        return (*agg)[0];  
    }  
    virtual void next()  
    {  
        _index++;  
    }  
  
    virtual object end()  
    {  
        _index = agg->size();  
        return (*agg)[_index];  
    }  
  
    virtual object current()  
    {  
        return (*agg)[_index];  
    }  
  
    virtual bool IsDone()  
    {  
        return (_index == agg->size());  
    }  
};  
  
int main()  
{  
    ConcreteAggregate *objects =new ConcreteAggregate();  
    object a = 1;  
    object b = 2;     
    object c = 3;  
  
    objects->AddObject(a);  
    objects->AddObject(b);  
    objects->AddObject(c);  
  
    ConcreteIterator *iter = new ConcreteIterator(objects);  
      
    object tmp_begin = iter->begin();  
    while(!iter->IsDone())  
    {  
        cout<<iter->current()<<" ";  
        iter->next();  
    }  
    cout<<endl;  
  
    delete objects;  
    delete iter;  
  
    return 0;  
}  
