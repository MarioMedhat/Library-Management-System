#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
    public:
        Book(const std::string& title, const std::string& author, const int& id, const std::string& isbn);
        std::string getTitle() const;
        std::string getAuthor() const;
        std::string getISBN() const;
        int getID() const;
        bool isAvailable() const;
        void lendBook();
        void returnBook();
    private:
        std::string title;
        std::string author;
        std::string isbn;
        int id;
        bool available;
};

#endif