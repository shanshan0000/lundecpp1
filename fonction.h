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
        Iterator(int _data[]) : j(0), data(_data) {}

        bool hasNext() const
        {
            return j < 200;
        }

        int& next()
        {
            return data[j++];
        }

    private:
        int j;
        int* data;
    };

    Iterator getIterator()
    {
        return Iterator(m_data);
    }
};


#endif //CPP_FONCTION_H
