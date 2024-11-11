#include "Library.hpp"
#include "Book.hpp"
#include "Member.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

// Function to test (prints multiple lines)
void printHello()
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Welcome to Google Test!" << std::endl;
    std::cout << "This is a multiline output test." << std::endl;
}

class GTestExample : public ::testing::Test {

};

TEST(GTestExample, EnsureGTestIsUpAndRunning)
{
    EXPECT_EQ(1, 1);
}

TEST(GTestExample, PrintsMultilineOutput)
{
    // Step 1: Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    // Step 2: Call the function that produces multiple lines of output
    printHello();

    // Step 3: Check the captured output
    std::string output = buffer.str();
    std::string expectedOutput = 
        "Hello, World!\n"
        "Welcome to Google Test!\n"
        "This is a multiline output test.\n";

    EXPECT_EQ(output, expectedOutput);

    // Step 4: Restore std::cout to its original state
    std::cout.rdbuf(oldCoutBuffer);
}

TEST(GTestExample, Test1)
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

    std::vector<Book> borrowedBooks;
    std::string borrowedBooksStr;

    borrowedBooks = member1.returnBorrowedBooks();

    for (const auto& book : borrowedBooks)
    {
        borrowedBooksStr = borrowedBooksStr + book.getTitle() + ",";
    }
    
    EXPECT_EQ(borrowedBooksStr, "1984,1987,");

    library.returnBook(1, 1);
    borrowedBooksStr = "";

    borrowedBooks = member1.returnBorrowedBooks();

    for (const auto& book : borrowedBooks)
    {
        borrowedBooksStr = borrowedBooksStr + book.getTitle() + ",";
    }
    EXPECT_EQ(borrowedBooksStr, "1987,");
}




// //library.returnBook(1, 1);
//member1.displayBorrowedBooks();

//std::cout << "End!" << std::endl;
//return 0;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}