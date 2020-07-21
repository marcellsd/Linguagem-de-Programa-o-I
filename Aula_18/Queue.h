#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template<typename X>
class Queue
{
private:
    int size;
    int lastPostition;
    

public:
    X* value;
    Queue(int size_)
    {
        size = size_;
        value = new X[size];
        lastPostition = -1;
    }
    ~Queue()
    {
        delete value;
    }

    void add(X customer)
    {
        if(lastPostition + 1 == size)
        {
            std::cout << "Full queue." << std::endl;
            return;
        } 
        else
        {
            value[++lastPostition] = customer;
        } 
    }

    bool Empty()
    {
        if (lastPostition > -1)
        {
            return false;
        }
        else
        {
            std::cout << "Empty queue" << std::endl;
            return true;
        }
    }

    void remove()
    {
        if (!Empty())
        {
            for (size_t i = 0; i < size - 1; i++)
            {
                value[i] = value[i+1];
            }
            lastPostition--;
        }
    }

    X first()
    {
        return value[0];
    }

    X last()
    {
        return value[lastPostition];
    }

    
};


#endif