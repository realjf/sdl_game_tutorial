#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include "uncopyable.h"

template <class T>
class Singleton {
public:
    static T *Pointer() {
        static T t;
        return &t;
    }
};

#endif /* _SINGLETON_H_ */
