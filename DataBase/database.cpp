#include <iostream>
#include "personal.hpp"
#include "database.hpp"
template<class T>
Database<T>::Database() 
{
} // constructor 
template<class T>
void Database<T>::add(T& d) 
{
    database.open(fName,std::ios::in|std::ios::out|std::ios::app);
    database.seekp(0,std::ios::end);
    database.writeToFile(database);
    database.close();
}
template<class T>
void Database<T>::modify(const T& d) 
{   T tmp;
    database.open(fName,std::ios::in|std::ios::out|std::ios::app);
    while (!database.eof()) 
    {
        tmp.readFromFile(database);
        if (tmp == d) { // overloaded ==
        std::cin >> tmp; // overloaded >>
        database.seekp(-d.size(),std::ios::cur);
        tmp.writeToFile(database);
        database.close();
    return;
    }
 }
 database.close();
 std::cout << "The record to be modified is not in the database\n";
}
template<class T>
bool Database<T>::find(const T& d) {
 T tmp;
 database.open(fName,std::ios::in);
 while (!database.eof()) 
 {
 tmp.readFromFile(database);
    if (tmp == d) 
    { // overloaded ==
        database.close();
        return true;
    }
 }
 database.close();
 return false;
}
template<class T>
std::ostream& Database<T>::print(std::ostream& out) {
    T tmp;
    database.open(fName,std::ios::in|std::ios::binary);
    while (true) 
    {
    tmp.readFromFile(database);
    if (database.eof())
        break;
    out << tmp << std::endl; // overloaded <<
    }
    database.close();
    return out;
}

template<class T>
void Database<T>::run() {
    std::cout << "File name: ";
    std::cin >> fName;
    char option[5];
    T rec;
    std::cout << "1. Add 2. Find 3. Modify a record; 4. Exit\n";
    std::cout << "Enter an option: ";
    std::cin.getline(option,4); // get '\n';
    while (std::cin.getline(option,4)) 
    {
    if (*option == '1') 
    {
        std::cin >> rec; // overloaded >>
        add(rec);
    }
    else if (*option == '2') 
    {
        rec.readKey();
        std::cout << "The record is ";
        if (find(rec) == false)
            std::cout << "not ";
        std::cout << "in the database\n";
    }
    else if (*option == '3') {
    rec.readKey();
    modify(rec);
    }
    else if (*option != '4')
        std::cout << "Wrong option\n";
    else  return;
    std::cout << *this; // overloaded <<
    std::cout << "Enter an option: ";
    }
}
int main() {
 Database<Personal>().run();
// Database<Student>().run();
 return 0;
}