#include "../headers/library.h"
#include "../headers/dataCarrier.h"
#include "../headers/base.h"
#include <iostream>
#include <string>

void Library::ReAllocate(size_t newCapacity){
    DataCarrier* newBlock = new DataCarrier[newCapacity];

    if(newCapacity < size){
        size = newCapacity;
    }

    for(size_t i = 0; i < size; i++){
        newBlock[i] = std::move(data[i]);
    }

    delete[] data;
    data = newBlock;
    capacity = newCapacity; 
}

Library::Library(){
    ReAllocate(2);
}
Library::~Library(){
    Clear();
    delete[] data;
}
void Library::Add(const DataCarrier& value){
    if (size >= capacity)
        ReAllocate(capacity + capacity / 2); 
    
    data[size] = value;
    size++;
}
void Library::Add(const DataCarrier&& value){
    if (size >= capacity)
        ReAllocate(capacity + capacity / 2); 

    data[size] = std::move(value);
    size++;
}
void Library::Pop(){
    if(size > 0){
        size--;
        data[size].~DataCarrier();
    }
}
void Library::Clear(){
    for(size_t i = 0; i < size; i++){
        data[i].~DataCarrier();
    }
    size = 0;
}
void Library::DeleteAtIndex(size_t index){
    if(index < size){
        data[index].~DataCarrier();
        for(size_t i = index; i < size - 1; i++){
            data[i] = std::move(data[i + 1]);
        }
        size--;
    }
}

size_t Library::getSize() const{return size;}

const DataCarrier& Library::operator[](size_t index) const{
    return data[index];
}
// overload << operator to print library
void Library::operator << (Library& lib){
    for(size_t i = 0; i < lib.getSize(); i++){
        lib[i].print();
        std::cout << std::endl;
    }
}
DataCarrier& Library::operator[](size_t index){
    return data[index];
}
