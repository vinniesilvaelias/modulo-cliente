#ifndef DLNODE_H
#define DLNODE_H

template<class T> class DLL;
template<class T>
class DLNODE
{
    friend class DLL<T>;
    private:
        T data;
        DLNODE<T>* next;
        DLNODE<T>* prev;
    public:
        DLNODE();
        DLNODE( const T &,DLNODE<T>*,DLNODE<T>*);
        ~DLNODE();
        T getData() const;
        void setData(const T&);
        DLNODE<T>* getNext();
        void setNext(DLNODE<T>*);
        DLNODE<T>* getPrev();
        void setPrev(DLNODE<T>*);
};
template<class T>
DLNODE<T>::DLNODE(): next(nullptr), prev(nullptr)
{
    
}
template<class T>
DLNODE<T>::DLNODE(const T &data,DLNODE<T>* prev,DLNODE<T>* next)
{
    setData(data);  setPrev(prev); setNext(next);
}

template<class T>
DLNODE<T>::~DLNODE()
{
    prev = nullptr;
    next = nullptr;
}

template<class T>
T DLNODE<T>::getData() const
{
    return this->data;
}

template<class T>
void DLNODE<T>::setData(const T& data)
{
    this->data = data;
}

template<class T>
DLNODE<T>* DLNODE<T>::getNext()
{
    return this->next;
}

template<class T>
void DLNODE<T>::setNext(DLNODE<T>* next)
{
    this->next = next;
}

template<class T>
DLNODE<T>* DLNODE<T>::getPrev()
{
    return this->prev;
}

template<class T>
void DLNODE<T>::setPrev(DLNODE<T>* prev)
{
    this->prev = prev;
}

#endif
