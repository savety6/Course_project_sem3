#ifndef LIBRARY_H
#define LIBRARY_H
#include "dataCarrier.h"
#include <iostream>
class Library{
    private:
        DataCarrier* data = nullptr;
        size_t size = 0;
        size_t capacity = 0;

        void ReAllocate(size_t newCapacity);
    public:
        Library();
        ~Library();
        void Add(const DataCarrier& value);
        void Add(const DataCarrier&& value);
        void Pop();
        void Clear();
        void DeleteAtIndex(size_t index);
        
        size_t getSize() const;
        
        const DataCarrier& operator[](size_t index) const;
        DataCarrier& operator[](size_t index);
        
        void operator << (Library& lib);
};
#endif