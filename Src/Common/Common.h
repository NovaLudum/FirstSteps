#ifndef COMMON_H
#define COMMON_H

#include <iostream>

class Common{
    public:
    template<typename Base, typename T>
    static inline bool instanceOf(const T*) 
    {
        return std::is_base_of<Base, T>::value;
    }
};

#endif