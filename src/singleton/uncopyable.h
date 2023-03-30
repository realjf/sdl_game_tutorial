#ifndef _UNCOPYABLE_H_
#define _UNCOPYABLE_H_

class UnCopyable {
private:
    UnCopyable(const UnCopyable &uc);

    const UnCopyable &operator=(const UnCopyable &uc);

protected:
    UnCopyable() {}
};

#endif /* _UNCOPYABLE_H_ */
