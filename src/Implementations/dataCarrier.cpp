#include "../headers/dataCarrier.h"
#include "../headers/base.h"
#include <iostream>
#include <string>
     
void DataCarrier::print(){
    Base::print();
    std::cout << "Type: " << type << std::endl;
    std::cout << "Status: " << status << std::endl;
}

//getters
std::string DataCarrier::getType(){
    return type;
}
bool DataCarrier::getStatus(){
    return status;
}
//setters
void DataCarrier::setType(std::string type){
    this->type = type;
}
void DataCarrier::setStatus(bool status){
    this->status = status;
}