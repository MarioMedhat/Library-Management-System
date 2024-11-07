#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.hpp"
#include "Member.hpp"

class Library
{
    public:
        void addBook(Book* book);
        void addMember(Member* member);
        void lendBook(int memberId, const int& book_id);
        void returnBook(int memberId, const int& book_id);
        void listMembers();
    
    private:
        std::vector<Book*> books;
        std::vector<Member*> members;
};

#endif