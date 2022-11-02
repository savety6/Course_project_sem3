#include <iostream>
#include <string>
#include <fstream>

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
        void DeleteAtIndex(size_t index){
            if(index < size){
                data[index].~DataCarrier();
                for(size_t i = index; i < size - 1; i++){
                    data[i] = std::move(data[i + 1]);
                }
                size--;
            }
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
        static void addCarrier(Library& lib){
            DataCarrier dc;
            str author, title, type;
            int year;
            log("Enter author: ");
            std::cin >> author;
            log("Enter title: ");
            std::cin >> title;
            log("Enter year: ");
            std::cin >> year;
            log("Enter type: ");
            std::cin >> type;
            dc.setAuthor(author);
            dc.setTitle(title);
            dc.setYear(year);
            dc.setType(type);
            dc.setStatus(true);
            lib.Add(dc);
        }
        static void changeCarrierStatus(Library& lib){
            log("Enter index: ");
            size_t index;
            std::cin >> index;
            if(index < lib.getSize()){
                lib[index].setStatus(!lib[index].getStatus());
            }
        }
        static void deleteCarrier(Library& lib){
            log("Enter index: ");
            size_t index;
            std::cin >> index;
            if(index < lib.getSize()){
                lib.DeleteAtIndex(index);
            }
        }
        static void printMenu(){
            log("1. Add carrier");
            log("2. Change carrier status");
            log("3. Delete carrier");
            log("4. Print library");
            log("5. Exit");
        }
};


int main()
{
    Library library;

    
    

    // std::ifstream file2("file.bin", std::ios::binary);
    // DataCarrier dc2;
    // file2.read((char*)&dc2, sizeof(DataCarrier));
    // file2.close();
    // dc2.print();

    while (true)
    {
        Manager::printMenu();
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Manager::addCarrier(library);
            break;
        case 2:
            Manager::changeCarrierStatus(library);
            break;
        case 3:
            Manager::deleteCarrier(library);
            break;
        case 4:
            Manager::printLibrary(library);
            break;
        case 5:
            {
                std::ofstream file("file.bin", std::ios::binary);
                file.write((char*)&library, sizeof(Library) * library.getSize());
                file.close();
                return 0;
            }
            break;
        case 6:
            {
                std::ifstream file("file.bin", std::ios::binary);
                Library lib;
                file.read((char*)&lib, sizeof(Library) * 1);
                file.close();
                Manager::printLibrary(lib);

            }
            break;
        default:
            break;
        }
    }
    // std::system("clear");
    return 0;
}
