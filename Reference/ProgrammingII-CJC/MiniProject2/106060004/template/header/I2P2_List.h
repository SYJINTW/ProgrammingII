#ifndef I2P2_LIST_H
#define I2P2_LIST_H

namespace I2P2
{
    template <class T>
    struct Node
    {
        Node *prev, *next;
        T data;
        Node(T d = 0) : prev(nullptr), next(nullptr), data(d) {}
    };

    template <class T>
    struct base_Listiterator
    {
        Node<T>* m_p_value;

        base_Listiterator(Node<T>* p) : m_p_value(p) {}

        base_Listiterator& operator++() {
            m_p_value = m_p_value->next;
            return *this;
        }
        base_Listiterator& operator--() {
            m_p_value = m_p_value->prev;
            return *this;
        }

        T& operator*() {
            return m_p_value->data;
        }
        T* operator->() {
            return &(m_p_value->data);
        }
        bool operator==(const base_Listiterator &rhs) const {
            return m_p_value == rhs.m_p_value;
        }

        Node<T>* node_ref(){
            return m_p_value;
        }
    };

    template <class T>
    class List
    {
    private:
        Node<T>* _head;
        size_t _size;
    public:
        typedef base_Listiterator<T> iterator;

        ~List();
        List();
        List(const List<T> &rhs);
        List<T> &operator=(const List<T> &rhs);
        iterator begin();
        iterator end();

        T& front();
        T& back();

        size_t size() const;

        void clear();
        bool empty() const;
        void erase(iterator pos);
        void insert(iterator pos, T& val);
        void pop_back();
        void pop_front();
        void push_back(T& val);
        void push_front(T& val);
    };

    template <class T>
    List<T>::~List() {
        clear();
        delete _head;
    }

    template <class T>
    List<T>::List() {
        _head = new Node<T>(0); // dummy node, which represents _tail
        _head->next = _head; // not nullptr
        _head->prev = _head; // not nullptr
        _size = 0;
    }

    template <class T>
    List<T>::List(const List &rhs) : List() { //靠邀阿忘記初始化
        Node<T>* temp = rhs._head->next;
        while(temp != rhs._head) {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    template <class T>
    List<T> &List<T>::operator=(const List<T> &rhs) {
        if(this != &rhs) {
            this->~List();
            new (this) List(rhs);
        }
        return *this;
    }

    template <class T>
    typename List<T>::iterator List<T>::begin() {
        iterator it(_head->next);
        return it;
    }

    template <class T>
    typename List<T>::iterator List<T>::end() {
        iterator it(_head);
        return it;
    }

    template <class T>
    T& List<T>::front() {
        return _head->next->data;
    }

    template <class T>
    T& List<T>::back() {
        return _head->prev->data;
    }

    template <class T>
    size_t List<T>::size() const {
        return _size;
    }

    template <class T>
    void List<T>::clear() {
        Node<T>* curNode = _head->next;
        while(curNode != _head) {
            Node<T>* temp = curNode;
            curNode = curNode->next;
            delete temp;
        }
        _head->next = _head;
        _head->prev = _head;
        _size = 0;
    }

    template <class T>
    bool List<T>::empty() const {
        return _size == 0;
    }

    template <class T>
    void List<T>::erase(iterator pos) {
        Node<T>* targetNode = pos.node_ref();
        targetNode->prev->next = targetNode->next;
        targetNode->next->prev = targetNode->prev;
        delete targetNode;
        _size--;
    }

    template <class T>
    void List<T>::insert(iterator pos, T& val) {
        Node<T>* targetNode = pos.node_ref();
        Node<T>* newNode = new Node<T>(val);
        newNode->prev = targetNode->prev;
        newNode->next = targetNode;
        targetNode->prev->next = newNode;
        targetNode->prev = newNode;
        _size++;
    }

    template <class T>
    void List<T>::pop_back() {
        Node<T>* curNode = _head->prev;
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        delete curNode;
        _size--;
    }

    template <class T>
    void List<T>::pop_front() {
        Node<T>* curNode = _head->next;
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        delete curNode;
        _size--;
    }

    template <class T>
    void List<T>::push_back(T& val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->prev = _head->prev;
        newNode->next = _head;
        _head->prev->next = newNode;
        _head->prev = newNode;
        _size++;
    }

    template <class T>
    void List<T>::push_front(T& val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->prev = _head;
        newNode->next = _head->next;
        _head->next->prev = newNode;
        _head->next = newNode;
        _size++;
    }
}

#endif