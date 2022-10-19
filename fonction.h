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
    private:
        int j;
        int* m_ptr;
    public:
        Iterator(int* _data): j(0), m_ptr(_data){}

        bool isDone() const{
            return j >= 200;
        }

        void next() {
            j ++;
        }

        int& currentItem(){
            return m_ptr[j];
        }

    };

    Iterator getIterator(){
        return Iterator(m_data);
    }


};


#endif //CPP_FONCTION_H
