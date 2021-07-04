#ifndef DLL_H
#define DLL_H
#include <iostream>
#include "dlnode.h"
using namespace std;

template<class T>
class DLL
{
    private:
        DLNODE<T>*  head;
        int len;
        DLNODE<T>* getPosition(const T&);
    public:
        DLL  (); // default
        DLL  (const DLL<T>&); // copy
        ~DLL ();
        void pushFront(const T&);
        void pushBack(const T&);
        void insertAt(const T&,int);
        void insertSorted(const T&);
        T    front() const;
        T    find(const T&);
        T    getData(int key);
        void popFront();
        void popBack();
        void popAt(int);
        void popData(const T&);
        int  size() const;
        bool empty() const { return len == 0; }
        void show() const;
};

template<class T>
DLL<T>::DLL():len(0)
{
    head = new DLNODE<T>;
}

template<class T>
DLL<T>::DLL(const DLL<T>& copy) // copy
    :len(0)
{
//    head = new DLNODE<T>;
    DLNODE<T>* tmp = copy.head->prev;
    while (tmp)
    {
        pushBack(*(tmp->data));
        tmp = tmp->next;
    }
}

template<class T>
DLL<T>::~DLL()
{
    while (!empty())
    {
        popFront();
    }
    delete head;
}

template<class T>
void DLL<T>::pushFront(const T &data)
{
    DLNODE<T>* newNode = nullptr;
    try
    {
        newNode = new DLNODE<T>(data,nullptr,nullptr);
    }
    catch(std::bad_alloc&)
    {
        throw string("Insufficient Memory!");
    }
    if (empty())
    {
        head->prev = head->next = newNode;
    }
    else
    {
        newNode->next = head->prev;
        head->prev->prev = newNode;
        head->prev = newNode;
    }
    len++;
}

template<class T>
void DLL<T>::pushBack(const T& data)
{
    DLNODE<T>* newNode = nullptr;
    try
    {
        newNode = new DLNODE<T>(data,nullptr,nullptr);
    }
    catch(std::bad_alloc&)
    {
        throw string("Insufficient Memory!");
    }
    if (empty())
    {
        head->prev = head->next = newNode;
    }
    else
    {
        head->next->next = newNode;
        newNode->prev = head->next;
        head->next = newNode;
    }
    len++;
}

template<class T>
DLNODE<T>* DLL<T>::getPosition(const T& key)
{
     if (empty())
    {
        throw string("Empty!");
    }
    DLNODE<T>* tmp = head->prev;
    int count  = 0;
    while (tmp->next->data <= key && tmp->next)
    {//key > tmp->next->data && tmp->next
        tmp = tmp->next;
        count++;
    }
    return tmp;
}

template<class T>
void DLL<T>::insertAt(const T &data, int position)
{
    if (position < 0 || position >= head->data)
    {
        throw string("Invalid Position!");
    }
    DLNODE<T>* newNode = nullptr;
    try
    {
        newNode = new DLNODE<T>( data,nullptr,nullptr);
    }
    catch(const std::bad_alloc&)
    {
        throw string("Insufficient Memory!");
    }
    if (!position)
    {
        pushFront(data);
    }
    else if (position == head->data -1)
    {
        pushBack(data);
    }
    else
    {
        int count = 0;
        DLNODE<T>* tmp = head->prev;
        while (count < position -1)
        {
            tmp = tmp->next;
            count++;
        }
        newNode->next = tmp->next;
        tmp->next->prev = newNode;
        tmp->next = newNode;
        newNode->prev = tmp;
        len++;
    }    
}

template<class T>
void DLL<T>::insertSorted(const T& data)
{
    if (empty() ||  head->prev->data >= data)
    {// data < head->prev->data
        pushFront(data);
    }
    else if (head->next->data < data)
    {//data >= head->next->data
        pushBack(data);
    }
    else
    {
        DLNODE<T>* tmp = getPosition(data);
        DLNODE<T>* newNode = nullptr;
        try
        {
            newNode = new DLNODE<T>(data,nullptr,nullptr);
        }
        catch(std::bad_alloc&)
        {
            throw string("Insufficient Memory!");
        }
        newNode->next = tmp->next;
        tmp->next->prev = newNode;
        tmp->next = newNode;
        newNode->prev = tmp;
        len++;
    }
}

template<class T>
T DLL<T>::front() const
{
    if (empty())
    {
        throw string("Empty!");
    }
    return head->prev->data;
}

template<class T>
void DLL<T>::popFront()
{
    if (empty())
    {
        throw string("Empty!");
    }
    if (head->next == head->prev)
    {
        head->prev = head->next = nullptr;
    }
    else
    {
        DLNODE<T>* tmp = head->prev;
        head->prev = tmp->next;
        tmp->next->prev = nullptr;
        head->prev = tmp->next;
        delete tmp;
    }
    len--;
}

template<class T>
void DLL<T>::popBack()
{
    if (empty())
    {
        throw string("Empty!");
    }
    if (head->next == head->prev)
    {
        head->prev  = head->next = nullptr;
    }
    else
    {
        head->next = head->next->prev;
        head->next->next = nullptr;
    }
    len--;
    
}

template<class T>
void DLL<T>::popAt(int position)
{
    if (position < 0 || position >= head->data)
    {
        throw string("Empty!");
    }
    if (!position) // position == 0
    {
        popFront();
    }
    else if (position == head->data-1)
    {
        popBack();
    }
    else
    {
       DLNODE<T>* tmp = head->prev;
       int count = 0;
       while (count < position)
       {
           tmp = tmp->next;
           count++;
       }
       tmp->prev->next = tmp->next;
       tmp->next->prev = tmp->prev;
       delete tmp;
       len--;
    }   
}

template<class T>
void DLL<T>::popData(const T& data)
{
    if (empty())
    {
        throw string("Empty!");
    }
    if (head->next->data == data)
    {
        popFront();
    }
    else if (head->prev->data == data)
    {
        popBack();
    }
    else
    {
        int count = 0;
        DLNODE<T>* tmp = head->prev;
        while (count < head->data && tmp->data != data)
        {
            tmp = tmp->next;
            count++;
        }
        if (count == head->data)
        {
            throw string("Element not getPosition!");
        }
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
        len--;
    }
}

template<class T>
T DLL<T>::find(const T& key)
{
    if (empty())
    {
        throw string("Empty!");
    }
    for (DLNODE<T>* tmp = head->prev; tmp; tmp = tmp->next)
    {
        if (tmp->data == key)
        {
            return tmp->data;
        }
    }
    throw string("Element not find!");
}

template<class T>
T DLL<T>::getData(int key)
{
  if (head->next->data.getCod() < key || head->prev->data.getCod() > key) {
    throw string("Element not find!");
  }
  if (empty())
    {
        throw string("Empty!");
    }
    for (DLNODE<T>* tmp = head->prev; tmp; tmp = tmp->next)
    {
        if (tmp->data.getCod() == key)
        {
            return tmp->data;
        }
  }
  throw string("Element not find!");
}

template<class T>
int DLL<T>::size() const
{
    return len;
}

template<class T>
void DLL<T>::show() const
{
  if (empty()) {
      cout << "Empty";
  }
  else {
      DLNODE<T>* tmp = head->prev;
      while (tmp)
      {
          cout << *(tmp->data)<< " ";
          tmp = tmp->next;
      }
  }
  cout << endl;
}

#endif
