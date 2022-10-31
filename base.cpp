#include <iostream>
#include <string>

typedef std::string str;
#define log(x) std::cout << x << std::endl;

class Base{
    private:
        str author;
        str title;
        int year;
    public:
        Base(){
            year = 0;
            // std::cout << "Base constructor" << std::endl;
        }
        ~Base(){
            // std::cout << "Base destructor" << std::endl;
        }
        virtual void print(){
            std::cout << "Author: " << author << std::endl;
            std::cout << "Title: " << title << std::endl;
            std::cout << "Year: " << year << std::endl;
        }
        //getters
        str getAuthor(){
            return author;
        }
        str getTitle(){
            return title;
        }
        int getYear(){
            return year;
        }
        //setters
        void setAuthor(str author){
            this->author = author;
        }
        void setTitle(str title){
            this->title = title;
        }
        void setYear(int year){
            this->year = year;
        }
};

class DataCarrier : public Base
{
    private:
        str type;
        bool status;
    public:

        DataCarrier(){
            // std::cout << "DataCarrier constructor" << std::endl;
        }
        ~DataCarrier(){
            // std::cout << "DataCarrier destructor" << std::endl;
        }
        void print()override{
            Base::print();
            std::cout << "Type: " << type << std::endl;
            std::cout << "Status: " << status << std::endl;
        }
        //getters
        str getType(){
            return type;
        }
        bool getStatus(){
            return status;
        }
        //setters
        void setType(str type){
            this->type = type;
        }
        void setStatus(bool status){
            this->status = status;
        }
};

class Library{
    private:
        DataCarrier* data = nullptr;
        size_t size = 0;
        size_t capacity = 0;

        void ReAllocate(size_t newCapacity){
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
    public:
        Library(){
            ReAllocate(2);
        }
        ~Library(){
            Clear();
            delete[] data;
        }
        void Add(const DataCarrier& value){
            if (size >= capacity)
                ReAllocate(capacity + capacity / 2); 
            
            
            data[size] = value;
            size++;
        }
        void Add(const DataCarrier&& value){
            if (size >= capacity)
                ReAllocate(capacity + capacity / 2); 
            
            
            data[size] = std::move(value);
            size++;
        }
        void Pop(){
            if(size > 0){
                size--;
                data[size].~DataCarrier();
            }
        }
        void Clear(){
            for(size_t i = 0; i < size; i++){
                data[i].~DataCarrier();
            }
            size = 0;
        }
        
        size_t getSize() const{return size;}
        
        const DataCarrier& operator[](size_t index) const{
            return data[index];
        } 
        DataCarrier& operator[](size_t index){
            return data[index];
        } 

};
class Manager{
    public:
        static void printLibrary(Library& lib){
            for(size_t i = 0; i < lib.getSize(); i++){
                lib[i].print();
                std::cout << std::endl;
            }
        }

};


int main()
{
    Library library;

    // while (true)
    // {

    // }
    
    DataCarrier dc;
    DataCarrier dc2;
    DataCarrier dc3;
    dc.setAuthor("Author");
    dc.setTitle("Title");
    dc2.setTitle("bible");
    dc3.setTitle("Tits");
    dc.setYear(2019);
    dc.setType("Book");
    dc.setStatus(true);
    // dc.print();

    library.Add(dc);
    library.Add(dc2);
    library.Add(dc3);
    Manager::printLibrary(library);
    // delete[] &library;
    // std::system("clear");
    return 0;
}
