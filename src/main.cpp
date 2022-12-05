#include <iostream>
#include <string>
#include <fstream>
#include "headers/base.h"
#include "headers/dataCarrier.h"
#include "headers/library.h"
#include "headers/manager.h"

int main()
{
    Library library;
    
    std::ifstream file("file.bin", std::ios::binary);
    if (file.is_open())
    {
        size_t size;
        file.read((char*)&size, sizeof(size_t));
        for(int i = 0; i < size; i++){
            DataCarrier dc;
            file.read((char*)&dc, sizeof(DataCarrier));
            library.Add(dc);
        }
        file.close();
    }
    

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
            Manager::findByAuthor(library);
            break;
        case 6:
            Manager::findByTitle(library);
            break;
        case 7:
            Manager::findByStatus(library);
            break;
        case 8:
            {
                size_t size = library.getSize();
                std::ofstream file("file.bin", std::ios::binary);
                file.write((char*)&size, sizeof(size_t));
                    for(int i = 0; i < library.getSize(); i++){
                        file.write((char*)&library[i], sizeof(DataCarrier));
                    }
                file.close();
                return 0;
            }
            break;
        default:
            return 0;
        }
    }
    return 0;
}