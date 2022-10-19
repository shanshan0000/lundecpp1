#ifndef CPP_FONCTION_H
#define CPP_FONCTION_H

// Reference: https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp

class Item
{
public:
    int value;
};

class Integers {
public:
    Item** m_data;

    Integers()
    {
        m_data = new Item*[200];
        for(int i = 0; i <= 200; i ++)
        {
            m_data[i] = new Item;
            m_data[i]->value = i;
        }
    }

    class Iterator {
    public:
        Iterator(Item** ptr) : m_ptr(ptr) {}

        Item& operator*() const
        {
            return **m_ptr;
        }

        Item* operator->() const { return *m_ptr; }

        // Prefix increment
        Iterator &operator++()
        {
            m_ptr++;
            return *this;
        }

        // Postfix increment
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;  // or, return Iterator(tmp);
        }

        bool operator!=(const Iterator &b) const
        {
            return m_ptr != b.m_ptr;
        }

    private:
        Item** m_ptr;
    };

    Iterator begin() const { return Iterator(&(m_data[0])); }
    Iterator end()   const { return Iterator(&(m_data[200])); } // 200 is out of bounds
};


#endif //CPP_FONCTION_H
