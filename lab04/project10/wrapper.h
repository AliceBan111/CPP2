// wrapper.h

#ifndef WRAPPER_H
#define WRAPPER_H

template <class T>
class Wrapper
{
public:
    Wrapper()
    {
        DataPtr = 0;
    }

    Wrapper(const T &inner)
    {
        DataPtr = inner.clone(); // 不是直接赋值，而是调用clone()方法创建一个新的对象，并将其指针赋值给DataPtr。这是为了实现深复制，确保每个Wrapper对象都有自己独立的内存空间来存储数据。
    }

    ~Wrapper()
    {
        if (DataPtr != 0)
            delete DataPtr;
    }

    Wrapper(const Wrapper<T> &original)
    {
        if (original.DataPtr != 0)
            DataPtr = original.DataPtr->clone();
        else
            DataPtr = 0;
    } // 如果原始对象的DataPtr不为0，则调用clone()方法创建一个新的对象，并将其指针赋值给DataPtr；否则，将DataPtr设置为0。（deep copy）

    Wrapper &operator=(const Wrapper<T> &original)
    {
        if (this != &original) // 检查是否是自我赋值，如果是，则不进行任何操作，直接返回当前对象的引用。
        {
            if (DataPtr != 0)
                delete DataPtr; // 如果当前对象的DataPtr不为0，则先删除当前对象所持有的资源，以避免内存泄漏。

            DataPtr = (original.DataPtr != 0) ? original.DataPtr->clone() : 0;
        }

        return *this;
    }

    T &operator*()
    {
        return *DataPtr;
    }

    const T &operator*() const // 函数后面的const表示这个函数不会修改wrapper本身  *w只能调用const版本
    {
        return *DataPtr;   // const T& 表示不修改内部对象
    }

    const T *const operator->() const 
    {
        return DataPtr; 
    }

    T *operator->()
    {
        return DataPtr; // 允许 w->method();
    }

private:
    T *DataPtr;
};
#endif
