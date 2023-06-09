#ifndef _RECTANGLE2D_H_
#define _RECTANGLE2D_H_

#include "size.h"
#include "vector2.h"

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
    operator RectangleT<T2>() {
        RectangleT<T2> res;
        res.X = (T2)X;
        res.Y = (T2)Y;
        res.Width = (T2)Width;
        res.Height = (T2)Height;
        return res;
    }

    template <class T2>
    RectangleT operator=(const RectangleT<T2> b) {
        X = (T)b.X;
        Y = (T)b.Y;
        Width = (T)b.Width;
        Height = (T)b.Height;
    }

    template <class T2>
    bool operator==(const RectangleT<T2> b) {
        return X == b.X && Y == b.Y && Width == b.Width && Height == b.Height;
    }

    template <class T2>
    bool operator!=(const RectangleT<T2> b) {
        return X != b.X && Y != b.Y && Width != b.Width && Height != b.Height;
    }

    template <class T2>
    RectangleT operator+(const RectangleT<T2> b) {

        RectangleT<T2> res = *this;
        res.X += (T2)X;
        res.Y += (T2)Y;
        res.Width += (T2)Width;
        res.Height += (T2)Height;

        return res;
    }

    template <class T2>
    void operator+=(const RectangleT<T2> b) {
        X += (T2)b.X;
        Y += (T2)b.Y;
        Width += (T2)b.Width;
        Height += (T2)b.Height;
    }

    template <class T2>
    RectangleT operator-(const RectangleT<T2> b) {
        RectangleT<T2> res = *this;
        res.X -= (T2)X;
        res.Y -= (T2)Y;
        res.Width -= (T2)Width;
        res.Height -= (T2)Height;
        return res;
    }

    Vector2T<T> Location() {
        Vector2T<T> res;
        res.X = X;
        res.Y = Y;
        return res;
    }

    Vector2T<T> LocationB() {
        Vector2T<T> res;
        res.X = X + Width;
        res.Y = Y + Height;
        return res;
    }

    template <class T2>
    void operator-=(const RectangleT<T2> b) {
        X -= (T2)b.X;
        Y -= (T2)b.Y;
        Width -= (T2)b.Width;
        Height -= (T2)b.Height;
    }

    void Inflate(SizeT<T> amount) {
        Width += (T)amount.Width;
        Height += (T)amount.Height;
    }

    void Offset(Vector2T<T> offsetAmount) {
        X += (T)offsetAmount.X;
        Y += (T)offsetAmount.Y;
    }

    T Left() const {
        return X;
    }

    T Right() const {
        return X + Width;
    }

    T Top() const {
        return Y;
    }

    T Bottom() const {
        return Y + Height;
    }

    bool Contains(Vector2T<T> location) const {
        return (Left() < location.X && location.X < Right() && Top() < location.Y && location.Y < Bottom());
    }

    bool Contains(RectangleT<T> rectB) const {
        bool a = Contains(rectB.Location());
        bool b = Contains(rectB.LocationB());

        return a && b;
    }

    bool IntersectsWidth(const RectangleT<T> rectB) const {
        return (Right() > rectB.Left() && rectB.Right() > Left() && Top() < rectB.Bottom() && rectB.Top() < Bottom());
    }
};

typedef RectangleT<int> Rectangle;
typedef RectangleT<float> RectangleF;

#endif /* _RECTANGLE2D_H_ */
