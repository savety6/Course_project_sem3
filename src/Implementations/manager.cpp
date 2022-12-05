
#include "../headers/manager.h"
#include "../headers/library.h"
#include "../headers/dataCarrier.h"
#include "../headers/base.h"
#include <iostream>
#include <string>

void Manager::printLibrary(Library& lib){
    lib << lib;
}
void Manager::addCarrier(Library& lib){
    DataCarrier dc;
    std::string author, title, type;
    int year;
    std::cout << "Enter the information in the following sequences\n";
    std::cout << "Author, Title, Year, type: \n";
    std::cin >> author;
    std::cin >> title;
    std::cin >> year;
    std::cin >> type;
    dc.setAuthor(author);
    dc.setTitle(title);
    dc.setYear(year);
    dc.setType(type);
    dc.setStatus(true);
    lib.Add(dc);
}
void Manager::changeCarrierStatus(Library& lib){
    std::cout << "Enter index: " << '\n';
    size_t index;
    std::cin >> index;
    if(index < lib.getSize()){
        lib[index].setStatus(!lib[index].getStatus());
    }
}
void Manager::deleteCarrier(Library& lib){
    std::cout << "Enter index: " << '\n';
    size_t index;
    std::cin >> index;
    if(index < lib.getSize()){
        lib.DeleteAtIndex(index);
    }
}
void Manager::findByAuthor(Library& lib){
    std::cout << "Enter author: ";
    std::string author;
    std::cin >> author;
    for(size_t i = 0; i < lib.getSize(); i++){
        if(lib[i].getAuthor() == author){
            lib[i].print();
            std::cout << std::endl;
        }
    }
}
void Manager::findByTitle(Library& lib){
    std::cout << "Enter title: ";
    std::string title;
    std::cin >> title;
    for(size_t i = 0; i < lib.getSize(); i++){
        if(lib[i].getTitle() == title){
            lib[i].print();
            std::cout << std::endl;
        }
    }
}
void Manager::findByStatus(Library& lib){
    std::cout << "Enter status: ";
    bool status;
    std::cin >> status;
    for(size_t i = 0; i < lib.getSize(); i++){
        if(lib[i].getStatus() == status){
            lib[i].print();
            std::cout << std::endl;
        }
    }
}

void Manager::printMenu(){
    std::cout << "1. Add carrier" << std::endl;
    std::cout << "2. Change carrier status" << std::endl;
    std::cout << "3. Delete carrier" << std::endl;
    std::cout << "4. Print library" << std::endl;
    std::cout << "5. Find by author" << std::endl;
    std::cout << "6. Find by title" << std::endl;
    std::cout << "7. Find by status" << std::endl;
    std::cout << "8. Exit" << std::endl;
}