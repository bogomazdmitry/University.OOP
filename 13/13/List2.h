#pragma once
#include <iostream>

using namespace std;

template <class T>
class List2
{
private:
    template <class T>
    class InsideList
    {
        T information;
        InsideList<T>* next;
        InsideList<T>* prev;

    public:
        InsideList(T information = T(), InsideList<T>* next = NULL, InsideList<T>* prev = NULL) :
            information(information),
            next(next),
            prev(prev)
        {}

        T& get_information()
        {
            return information;
        }

        T get_information() const
        {
            return information;
        }

        void set_informaion(T element)
        {
            information = element;
        }

        InsideList<T>* get_next()
        {
            return next;
        }

        void set_next(InsideList<T>* newNext)
        {
            if (newNext != NULL)
                newNext->prev = this;
            next = newNext;
        }

        InsideList<T>* get_prev()
        {
            return prev;
        }

        void set_prev(InsideList<T>* newPrev)
        {
            if (newPrev != NULL)
                newPrev->next = this;
            prev = newPrev;

        }
    };
    InsideList<T>* begin;
    InsideList<T>* end;

public:
    class IteratorList2
    {
    private:
        InsideList<T>* ptr;

    public:
        IteratorList2(InsideList<T>* ptr) :
            ptr(ptr){}

        virtual bool operator!=(const IteratorList2& it) const
        {
            return ptr != it.ptr;
        }

        virtual IteratorList2& operator++()
        {
            ptr = ptr->get_next();
            return *this;
        }

        virtual IteratorList2& operator--()
        {
            ptr = ptr->get_prev();
            return *this;
        }

        virtual IteratorList2 operator++(int)
        {
            IteratorList2 temp = *this;
            ptr = ptr->get_next();
            return temp;
        }
        
        virtual IteratorList2 operator--(int)
        {
            IteratorList2 temp = *this;
            ptr = ptr->get_prev();
            return temp;
        }

        virtual T& operator*() const
        {
            return ptr->get_information();
        }
    };

    List2();

    ~List2();

    bool empty() const;

    void push_back(T newInformation);

    void push_front(T newInformation);

    void pop_back();

    void pop_front();

    void delate();

    friend ostream& operator<< (ostream& is, const List2<T>& begin)
    {
        InsideList<T>* newBegin = begin.begin;
        while (newBegin)
        {
            is << newBegin->get_information() << ' ';
            newBegin = newBegin->get_next();
        }
        return is;
    }

    void random(int sizeOfList);

    IteratorList2 get_begin()
    {
        return begin;
    }
    
    IteratorList2 get_end()
    {
        return end;
    }
};

template<class T>
istream& operator>> (istream& is, List2<T>& begin)
{
    int sizeOfList;
    cout << "Введите размер листа" << endl;
    do {
        is >> sizeOfList;

        if (sizeOfList <= 0)
            cout << "Неправильный ввод данных" << endl;
    } while (sizeOfList <= 0);

    T chr;
    begin.delate();
    while (sizeOfList > 0)
    {
        is >> chr;
        begin.push_back(chr);
        sizeOfList--;
    }
    return is;
}

template<class T>
List2<T>::List2() :
    begin(NULL),
    end(NULL){}

template<class T>
List2<T>::~List2()
{
    this->delate();
}

template<class T>
bool List2<T>::empty() const
{
    return begin == NULL;
}

template<class T>
void List2<T>::push_back(T newInformation)
{
    if (begin)
    {
        end->set_next(new InsideList<T>(newInformation));
        end = end->get_next();
    }
    else
    {
        begin = new InsideList<T>(newInformation);
        end = begin;
    }
}

template<class T>
void List2<T>::push_front(T newInformation)
{
    if (begin)
    {
        begin->set_prev(new InsideList(newInformation));
        begin = begin->get_prev();
    }
    else
    {
        begin = new InsideList<T>(newInformation);
        end = begin;
    }
}

template<class T>
void List2<T>::pop_back()
{
    if (begin->get_next())
    {
        auto temp = end;
        end = end->get_prev();
        delete temp;
        end->set_next(NULL);
    }
    else
    {
        delete begin;
        end = begin = NULL;
    }
}

template<class T>
void List2<T>::pop_front()
{
    if (end->get_prev())
    {
        auto temp = begin;
        begin = begin->get_next();
        delete temp;
        begin->set_prev(NULL);
    }
    else
    {
        delete begin;
        end = begin = NULL;
    }
}


template<class T>
void List2<T>::delate()
{
    while (begin)
    {
        this->pop_back();
    }
}

template<class T>
void List2<T>::random(int sizeOfList)
{
    while (sizeOfList > 0)
    {
        this->push_back((char)(rand() % 26 + 97));
        sizeOfList--;
    }
}