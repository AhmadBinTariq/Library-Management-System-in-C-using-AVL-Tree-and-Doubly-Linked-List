/*
Ahmad Bin Tariq
23L-2510
BDS_3C
*/
#include <iostream>
#include <vector>
#include "Book.h"
#include "Lib_sys.h"

using namespace std;

int main() {
    Library library;
    vector<string> authors1 = { "Author1", "Author2" };
    library.add_book(12345, "Book Title 1", 5, 10, authors1);

    vector<string> authors2 = { "Author3", "Author4" };
    library.add_book(67890, "Book Title 2", 8, 5, authors2);

    vector<string> authors3 = { "Author5" };
    library.add_book(11111, "Book Title 3", 12, 6, authors3);

    cout << "Displaying books after adding:\n\n";
    library.display_books();
    cout << "-----------------------------------------------------------------------------\n";
    vector<string> new_authors = { "New Author1", "New Author2" };
    library.update_data(12345, "Updated Book Title 1", 6, 12, new_authors);
    cout << "\nDisplaying books after update:\n";
    library.display_books();

    cout << "-----------------------------------------------------------------------------\n";

    library.remove_book(67890);
    cout << "\nDisplaying books after removal:\n";
    library.display_books();

    return 0;
}
