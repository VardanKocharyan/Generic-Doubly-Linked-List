#pragma once 
#include <cstddef>

namespace DoubleLinkList {

template <typename T>
class List {
private:
        struct Node {
            Node* prev = nullptr;
            Node* next = nullptr;
            T val;
            Node(const T& v) : val(v) {}
        };

        Node* head = nullptr;
        Node* tail = nullptr;
        size_t msize = 0;

public:
        //ctors
        List(size_t count, const T& val = T());
        List(const List& other);
        List(List&& other);
        List(std::initializer_list<T> list);
        ~List();

        //operator=
        List& operator=(const List& other);
        List& operator=(List&& otehr);
        List& operator=(std::initializer_list<T> list);

        //assign
        void assign(size_t count, const T& value);
        void assign(std::initializer_list<T> list);

        //front
        T& front();
        const T& front() const;

        //back()
        T& back();
        const T& back() const;
/*
        //iterators (don't use. :) ) 
        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const;

        iterator end();
        const_iterator end() const;
        const_iterator cend() const

        reverce_iterator rend()
        const_reverce_iterator rend() const;
        const_reverce_iterator crend() const;
*/
        bool empty() const;
        size_t size() const;
        //size_t max_size() const;
        void clear();

       
        // push/pop back
        void push_back(const T& value);
        void push_back(T&& value);
        void pop_back();
        

};

//ctors
template <typename T>
List<T>::List(size_t count, const T& val) : head(new Node(val)), msize(count) {
        --count;
        Node* tmp = head;
        for(size_t i{}; i < count; ++i) {
                tmp->next = new Node(val);
                tmp->next->prev = tmp;
                tmp = tmp->next;
        }
        tail = tmp;
}
template <typename T>
List<T>::List(const List& other) :head(nullptr), tail(nullptr), msize(other.msize) {
        Node* tmp = other.head;
        while(tmp) {
                push_back(tmp->val);
                tmp = tmp->next;
        }
}
template<typename T>
List<T>::List(List&& other) : head(other.head), tail(other.tail), msize(other.msize) {
        other.head = other.tail =  nullptr;
        other.size = 0;
}
template<typename T>
List<T>::List(std::initializer_list<T> list) : head(nullptr), tail(nullptr), msize(0) {
        for(const T& x : list) {
                push_back(x);
        }
}


//dtor
template<typename T>
List<T>::~List() { clear(); }


//operator=
template<typename T>
List<T>& List<T>::operator=(const List& other) {
        if(this == &other) return *this;
        clear();
        msize = other.msize;
        Node* tmp = other.head;
        while(tmp) {
                push_back(tmp->val);
                tmp = tmp->next;
        }
        return *this;
}
template<typename T>
List<T>& List<T>::operator=(List&& other) {
        if(this == &other) return *this;
        clear();
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(msize, other.msize);
        return *this;
}
template<typename T>
List<T>& List<T>::operator=(std::initializer_list<T> list) {
        assign(list);
        return *this;
}


//assign
template<typename T>
void List<T>::assign(size_t count, const T& value) {
        clear();
        for(size_t i{}; i < count; ++i) {
                push_back(value);
        }
}
template<typename T>
void List<T>::assign(std::initializer_list<T> list) {
        clear();
        for(const T& x : list) {
                push_back(x);
        }
}

//front
template<typename T>
T& List<T>::front() { return head->val; }
template<typename T>
const T& List<T>::front() const { return head->val; }


//back
template<typename T>
T& List<T>::back() { return tail->val; }
template<typename T>
const T& List<T>::back() const { return tail->val; }


//empty
template<typename T>
bool List<T>::empty() const { return !head; }

//size
template<typename T>
size_t List<T>::size() const { return msize; }

//clear
template<typename T>
void List<T>::clear() {
        while(head) {
                Node* tmp = head;
                head = head->next;
                delete tmp;
        }
        tail = nullptr;
        msize = 0;
}


//pop/push back
template<typename T>
void List<T>::push_back(const T& value) {
        ++msize;
        if(!tail) {
                head = tail = new Node(value);
                return;
        }
        tail->next = new Node(value);
        tail->next->prev = tail;
        tail = tail->next;
}
template<typename T>
void List<T>::push_back(T&& value) {
        ++msize;
        if(!tail) {
                head = tail = new Node(value);
                return;
        }
        tail->next = new Node(value);
        tail->next->prev = tail;
        tail = tail->next;
}
template<typename T>
void List<T>::pop_back() {
        
}



}
