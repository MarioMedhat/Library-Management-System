#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Book.hpp"

class Member
{
    public: 
        Member(const std::string& name, int memberId);
        std::string getName() const;
        int getID() const;
        void borrowBook(Book& book);
        void returnBook(Book& book);
        void displayBorrowedBooks() const;
        
    private:
        std::string name;
        int memberId;
        std::vector<Book> borrowedBooks;
        
};

#endif