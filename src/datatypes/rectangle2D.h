#ifndef _RECTANGLE2D_H_
#define _RECTANGLE2D_H_

#include "size.h"

template <class T>
class RectangleT {
public:
    T X = 0;
    T Y = 0;
    T Width = 0;
    T Height = 0;

    RectangleT() {}
    RectangleT(T x, T y, T width, T height) : X(x), Y(y), Width(width), Height(height) {}
    RectangleT(Size size) : Width(size.Width), Height(size.Height) {}

    template <class T2>
    operator SizeT<T2>() {
        SizeT<T2> res;
        res.Width = (T2)Width;
        res.Height = (T2)Height;
        return res;
    }

    template <class T2>
    SizeT operator=(const SizeT<T2> b) {
        Width = (T)b.Width;
        Height = (T)b.Height;
    }

    template <class T2>
    bool operator==(const SizeT<T2> b) {
        return Width == (T)b.Width && Height == (T)b.Height;
    }

    template <class T2>
    bool operator!=(const SizeT<T2> b) {
        return Width != b.Width && Height != b.Height;
    }

    template <class T2>
    SizeT operator+(const SizeT<T2> b) {

        SizeT<T2> res = *this;
        res.Width += (T)b.Width;
        res.Height += (T)b.Height;

        return res;
    }

    template <class T2>
    void operator+=(const SizeT<T2> b) {
        Width += (T)b.Width;
        Height += (T)b.Height;
    }

    template <class T2>
    SizeT operator-(const SizeT<T2> b) {
        SizeT<T2> res = *this;
        res.Width -= (T)b.Width;
        res.Height -= (T)b.Height;
        return res;
    }

    template <class T2>
    void operator-=(const SizeT<T2> b) {
        Width -= (T)b.Width;
        Height -= (T)b.Height;
    }
};

#endif /* _RECTANGLE2D_H_ */
