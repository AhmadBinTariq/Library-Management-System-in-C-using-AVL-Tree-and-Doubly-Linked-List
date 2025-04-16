/*
Ahmad Bin Tariq
23L-2510
BDS_3C
*/
#include <iostream>
#include <string>
#include "DLL_Node.h"
#include "AVL.h"
#include "Book.h"
#include "Double_Linked_List.h"

using namespace std;

class Library {
    AVL<int, DLL_Node<Book*>*> ISSNs;
    Double_Linked_List<int, Book*> Books;

public:

    void add_book(int ISSN, const string& title, int Copies_RB, int Copies_IB, vector<string> authors) {
        Book* new_book = new Book(ISSN, title, Copies_RB, Copies_IB, authors);
        Books.insert_sorted(ISSN, new_book);
        DLL_Node<Book*>* book_node = Books.find_node(ISSN);
        ISSNs.insert(ISSN, book_node);
    }

    void display_books() const {
        cout << "Books in the library:\n";
        Books.display();
    }

    void remove_book(int ISSN) {
        DLL_Node<Book*>* book = ISSNs.search(ISSN);
        if (!book)
        {
            cout << "No Book Found!\n";
            return;
        }
        Books.remove(ISSN);
        ISSNs.deleteNode(ISSN);
        delete book->data;
        cout << "Book with ISSN " << ISSN << " removed successfully.\n";
    }

	void update_data(int ISSN, const string& title, int Copies_RB, int Copies_IB, vector<string> authors) {
		DLL_Node<Book*>* book = ISSNs.search(ISSN);
		if (!book)
		{
			cout << "No Book Found!\n";
			return;
		}
		book->data->title = title;
		book->data->Copies_RB = Copies_RB;
		book->data->Copies_IB = Copies_IB;
		book->data->Authors = authors;
		cout << "Book with ISSN " << ISSN << " updated successfully.\n";
	}

	~Library() {
        DLL_Node<pair<int,Book*>>* temp = Books.get_head();
		while (temp) {
			delete temp->data.second;
			temp = temp->next;
		}
	}
};


