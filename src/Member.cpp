#include "Member.hpp"
#include <iostream>
#include <algorithm>

Member::Member(const std::string& name, int memberId)
    : name(name), memberId(memberId) {}
    
std::string Member::getName() const { return name; }
int Member::getID() const { return memberId; }

void Member::borrowBook(Book &book)
{
    if (book.isAvailable())
    {
        //std::cout << "Member::borrowBook is called" << std::endl;
        book.lendBook();
        borrowedBooks.push_back(book);
        //displayBorrowedBooks();
    }
}

void Member::returnBook(Book &book)
{
    book.returnBook();
    //borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), &book), borrowedBooks.end());

    std::vector<Book>::const_iterator itr;
    const std::vector<Book>::const_iterator last = borrowedBooks.end();

    itr = borrowedBooks.begin();

    int book_id = book.getID();

    while (itr <= last)
    {
        int itr_id = ((Book)(*(itr))).getID();
        
        if (itr_id == book_id)
        {
            break;
        }
        else
        {
            itr ++;
        }
    }
    // case book not found is not handled

    borrowedBooks.erase(itr);

}

void Member::displayBorrowedBooks() const
{
    //std::cout << "Member::displayBorrowedBooks is called" << std::endl;
    
    for (const auto& book : borrowedBooks)
    {
        std::cout << book.getTitle() << std::endl;
    }
}

std::vector<Book> Member::returnBorrowedBooks() const
{
   return borrowedBooks;
}