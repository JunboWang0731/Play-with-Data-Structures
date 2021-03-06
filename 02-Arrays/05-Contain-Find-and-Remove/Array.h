//
// Created by hpf on 18-5-8.
//

#include <iostream>
#include <cassert>

class Array {
private:
    int *data;
    int size;
    int capacity;

public:
    Array(int capacity) {
        data = new int[capacity];
        size = 0;
        this->capacity = capacity;
    }

    Array() {
        data = new int[10];
        size = 0;
        capacity = 10;
    }

    int getCapacity() {
        return capacity;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void add(int index, int e) {
        assert(size < capacity && index >= 0 && index <= size);
        for (int i = size - 1; i >= index; --i) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size++;
    }

    void addFirst(int e) {
        add(0, e);
    }

    void addLast(int e) {
        add(size, e);
    }

    int get(int index) {
        assert(index >= 0 && index < size);
        return data[index];
    }

    void set(int index, int e) {
        assert(index >= 0 && index < size);
        data[index] = e;
    }

    bool contains(int e) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == e) {
                return true;
            }
        }
        return false;
    }

    int find(int e) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == e) {
                return i;
            }
        }
        return -1;
    }

    int remove(int index) {
        assert(index >= 0 && index < size);
        int ret = data[index];
        for (int i = index + 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        size --;
        return ret;
    }

    int removeFirst() {
        return remove(0);
    }

    int removeLast(){
        return remove(size - 1);
    }

    void removeElement(int e) {
        int index = find(e);
        if(index != -1) {
            remove(index);
        }
    }

    /**
     * 打印数组的所有元素
     */
    void print() {
        std::cout << "Array: size = " << size << ", capacity = " << getCapacity() << std::endl;
        toPrint();
	std::cout << std::endl;
    }

    void toPrint() {
        std::cout << "[";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i != size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }
};

