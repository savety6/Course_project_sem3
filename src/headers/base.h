#ifndef BASE_H
#define BASE_H
#include <string>
#include <iostream>
class Base{
    private:
        std::string author;
        std::string title;
        int year;
    public:
        Base();
        virtual void print();
        //getters
        std::string getAuthor();
        std::string getTitle();
        int getYear();
        //setters
        void setAuthor(std::string author);
        void setTitle(std::string title);
        void setYear(int year);
};
#endif