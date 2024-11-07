#include "Library.hpp"
#include <iostream>

void Library::addBook(Book* book)
{
    books.push_back(book);
}

void Library::addMember(Member* member)
{
    members.push_back(member);
}

void Library::lendBook(int memberId, const int& book_id)
{
    std::cout << "Library::lendBook is called" << std::endl;
    // std::vector<Book>::iterator book_itr;
    Book* m_foundBook = nullptr;
    for(auto& book : books)
    {
        if((*book).getID() == book_id)
        {
            m_foundBook = book;
            break;
        }
    }

    Member* m_foundMember = nullptr;
    for(auto& member : members)
    {
        if((*member).getID() == memberId)
        {
            m_foundMember = member;
            break;
        }
    }

    (*m_foundMember).borrowBook(*m_foundBook);
    // int book_num = 0;
    // const std::vector<Book>::const_iterator book_last = books.end();

    // book_itr = books.begin();

    // while (book_itr <= book_last)
    // {
    //     int itr_id = ((Book)(*(book_itr))).getID();
        
    //     if (itr_id == book_id)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         book_num ++;
    //         book_itr ++;
    //     }
    // }

    // std::vector<Member>::iterator mem_itr;
    // int mem_num = 0;
    // const std::vector<Member>::const_iterator mem_last = members.end();

    // mem_itr = members.begin();

    // while (mem_itr <= mem_last)
    // {
    //     int itr_id = ((Member)(*(mem_itr))).getId();
        
    //     if (itr_id == memberId)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         mem_num ++;
    //         mem_itr ++;
    //     }
    // }
    // case book not found is not handled

    //((Book)(*(book_itr))).getID();
    // compile but runtime error
    //((Member)(*(mem_itr))).borrowBook(books[book_num]);
    // members[mem_num].borrowBook(books[book_num]);

    //Book book = (Book)(*(book_itr));
    //((Member)(*(mem_itr))).borrowBook(book);
    //((Member)(*(mem_itr))).borrowBook((Book)(*(book_itr)));

}

void Library::returnBook(int memberId, const int& book_id)
{
    std::cout << "Library::lendBook is called" << std::endl;
    // std::vector<Book>::iterator book_itr;
    Book* m_foundBook = nullptr;
    for(auto& book : books)
    {
        if((*book).getID() == book_id)
        {
            m_foundBook = book;
            break;
        }
    }

    Member* m_foundMember = nullptr;
    for(auto& member : members)
    {
        if((*member).getID() == memberId)
        {
            m_foundMember = member;
            break;
        }
    }

    (*m_foundMember).returnBook(*m_foundBook);
}

void Library::listMembers()
{
    std::cout << "Library::listMembers is called" << std::endl;
    for (const auto& member : members)
    {
        std::cout << (*member).getName() << std::endl;
        std::cout << (*member).getID() << std::endl;
    }
}