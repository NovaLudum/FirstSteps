#ifndef COMMON_H
#define COMMON_H

#include <iostream>

class Common
{
public:
    /**
     * C++ äquivalent für Java instanceOf
     * @example class A : public B{}; 
     *          A a = A();
     *          instanceOf<B>(a); // = true
     * */
    template <typename Base, typename T>
    static inline bool instanceOf(const T *)
    {
        return std::is_base_of<Base, T>::value;
    }

    /**
     * (DEG)Grad zu (RAD)Radiant Konvertierung - nicht type-safe
     * */
    template <typename T>
    static inline T deg2rad(const T &degrees)
    {
        static const T pi_on_180 = 4.0 * atan(1.0) / 180.0;
        return degrees * pi_on_180;
    }
};

#endif