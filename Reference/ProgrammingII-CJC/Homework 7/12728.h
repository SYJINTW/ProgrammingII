#include <cstdint>

namespace oj
{
    using size_type = uint64_t;
    using value_type = int32_t;
    using reference = value_type &;

    struct Node
    {
        size_type size;
        value_type *p_data;
        Node *lc;
        Node *rc;
        Node(value_type *pv) : size(1), p_data(pv), lc(nullptr), rc(nullptr) {}
        ~Node() { delete p_data; }
    };

    struct iterator_impl_base
    {
        virtual reference operator*() const = 0;
        virtual bool operator!=(const iterator_impl_base &) const = 0;
        virtual iterator_impl_base *clone() const = 0;
    };

    class set_iterator : public iterator_impl_base
    {
    protected:
        Node *_node;

    public:
        set_iterator();
        set_iterator(Node *u);
        reference operator*() const;
        iterator_impl_base *clone() const;
        bool operator!=(const iterator_impl_base &) const;
    };

    class iterator
    {
    protected:
        iterator_impl_base *_p;

    public:
        iterator(iterator_impl_base *);
        reference operator*() const;
        bool operator!=(const iterator &) const;
    };

    struct container_base
    {
        virtual size_type size() const = 0;
        virtual bool empty() const = 0;
        virtual void clear() = 0;
    };

    struct dynamic_size_container : container_base
    {
        virtual iterator begin() = 0;
        virtual iterator end() = 0;
    };

    struct associative_container : dynamic_size_container
    {
        virtual void insert(const value_type &) = 0;
    };

    struct sorted_container : associative_container
    {
        virtual iterator lower_bound(const value_type &) = 0;
    };

    class set : public sorted_container
    {
    protected: // you have two pointers to spare :) do anything you wish
        Node *root;
        Node *infy;

    public:
        set();
        ~set();
        void clear();
        size_type size() const;
        bool empty() const;
        iterator begin();
        iterator end();
        void insert(const value_type &);
        iterator lower_bound(const value_type &);
    };
}; // namespace oj
