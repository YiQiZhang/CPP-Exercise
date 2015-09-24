//
//  stack.h
//  stack-symmetry-check
//
//  Created by Jerry on 9/23/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#ifndef stack_symmetry_check_stack_h
#define stack_symmetry_check_stack_h

#include <memory>
#include "error.h"

#define MIN_STACK_SIZE (5)

using std::unique_ptr;

// 栈的数组实现
template <typename T>
class Stack
{
public:
    Stack(size_t size = MIN_STACK_SIZE) :
    topIndex(0) , maxSize(size){
        if (size <= MIN_STACK_SIZE) {
            error("stack size too small");
        }
        datas.reset(new T[size]);
    }
    void push(const T &ele) {
        if (topIndex >= maxSize) {
            error("stack is full");
        }
        datas[topIndex] = ele;
        ++topIndex;
    }
    void pop() {
        if (isEmpty()) {
            error("stack is empty");
        }
        --topIndex;
    }
    T top() const {
        if (isEmpty()) {
            error("stack is empty");
        }
        return datas[topIndex - 1];
    }
    T popAndTop() {
        if (isEmpty()) {
            error("stack is empty");
        }
        return datas[--topIndex];
    }
    bool isEmpty() const {
        return topIndex <= 0 ? true : false;
    }
    size_t size() const {
        return topIndex;
    }
private:
    size_t maxSize;
    size_t topIndex;
    unique_ptr<T[]> datas;
};
#endif
