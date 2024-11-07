#include "Book.hpp"

Book::Book(const std::string& title, const std::string& author, const int& id, const std::string& isbn)
    : title(title), author(author), isbn(isbn), id(id), available(true) {}
    
std::string Book::getTitle() const {return title;}
std::string Book::getAuthor() const {return author;}
std::string Book::getISBN() const {return isbn;}
int Book::getID() const {return id;}
bool Book::isAvailable() const {return available;}
void Book::lendBook() {available = false;}
void Book::returnBook() {available = true;}