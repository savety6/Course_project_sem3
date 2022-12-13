#include <iostream>
#include <string>
#include "../headers/base.h"

Base::Base(){
    year = 0;
}

void Base::print(){
    std::cout << "Author: " << author << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Year: " << year << std::endl;
}
//getters
std::string Base::getAuthor(){
    return author;
}
std::string Base::getTitle(){
    return title;
}
int Base::getYear(){
    return year;
}
//setters
void Base::setAuthor(std::string author){
    this->author = author;
}
void Base::setTitle(std::string title){
    this->title = title;
}
void Base::setYear(int year){
    this->year = year;
}
