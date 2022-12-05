#ifndef LIBRARY_H
#define LIBRARY_H
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
        // overload << operator to print library
        void operator << (Library& lib);
        DataCarrier& operator[](size_t index);
};
#endif