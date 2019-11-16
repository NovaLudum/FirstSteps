#ifndef COMMON_H
#define COMMON_H

#include <iostream>

class Common
{
public:
    template <typename Base, typename T>
    static inline bool instanceOf(const T *)
    {
        return std::is_base_of<Base, T>::value;
    }

    template <typename T>
    static inline T deg2rad(const T &degrees)
    {
        static const T pi_on_180 = 4.0 * atan(1.0) / 180.0;
        return degrees * pi_on_180;
    }
};

#endif