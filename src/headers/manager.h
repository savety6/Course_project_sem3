#ifndef MANAGER_H
#define MANAGER_H
class Manager{
    public:
        static void printLibrary(Library& lib);
        static void addCarrier(Library& lib);
        static void changeCarrierStatus(Library& lib);
        static void deleteCarrier(Library& lib);
        static void findByAuthor(Library& lib);
        static void findByTitle(Library& lib);
        static void findByStatus(Library& lib);
        static void printMenu();
};
#endif