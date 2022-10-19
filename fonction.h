#ifndef CPP_FONCTION_H
#define CPP_FONCTION_H

// Reference: https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp

class Integers {
public:
    int m_data[200];

    Integers()
    {
        for(int i = 0; i <= 200; i ++)
            m_data[i] = i;
    }

    class Iterator {
    public:
        Iterator(int* ptr) : m_ptr(ptr) {}

        int& operator*() const  // *it.m_ptr  equivalent to: *it
        {
            return *m_ptr;
        }

        // Prefix increment
        Iterator& operator++()
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

        bool operator!=(const Iterator &b)
        {
            return m_ptr != b.m_ptr;
        }

    private:
        int* m_ptr;
    };

    Iterator begin() { return Iterator(m_data); }
    Iterator end()   { return Iterator(m_data + 200); } // 200 is out of bounds
};


#endif //CPP_FONCTION_H
