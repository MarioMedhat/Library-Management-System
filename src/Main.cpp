#include "Library.hpp"
#include "Book.hpp"
#include "Member.hpp"
#include <iostream>
#include <vector>


int main()
{

    Library library;
    Book book1("1984", "George Orwell", 1, "1234567890");
    Book book2("1985", "George Orwell 1", 2, "1234567890");
    Book book3("1986", "George Orwell 2", 3, "1234567891");
    Book book4("1987", "George Orwell 3", 4, "1234567892");

    Member member1("Alice", 1);
    Member member2("Bob", 2);

    library.addBook(&book1);
    library.addBook(&book2);
    library.addBook(&book3);
    library.addBook(&book4);

    library.addMember(&member1);
    library.addMember(&member2);

    library.lendBook(1, 1);
    library.lendBook(1, 4);
    member1.displayBorrowedBooks();

    library.returnBook(1, 1);
    member1.displayBorrowedBooks();

    std::cout << "End!" << std::endl;
    return 0;
}