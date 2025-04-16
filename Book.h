/*
Ahmad Bin Tariq
23L-2510
BDS_3C
*/
#include <iostream>
#include <string>
#include <vector>
#include "Double_Linked_List.h"
#pragma once

using namespace std;

class Book {
public:
	string title;
	int Copies_RB;
	int Copies_IB;
    vector<string> Authors;
	int ISSN;
	Book(int ISSN, string title, int Copies_RB, int Copies_IB, vector<string> auth) : ISSN(ISSN), title(title), Copies_RB(Copies_RB), Copies_IB(Copies_IB), Authors(auth) {}
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "ISSN: " << book.ISSN << endl;
        os << "Title: " << book.title << endl;
        os << "Copies in Reading Room: " << book.Copies_RB << endl;
        os << "Copies in Issue Books: " << book.Copies_IB << endl;
        os << "Authors: ";
        for (const string& author : book.Authors) {
            os << author << ", ";
        }
        os << endl;
        return os;
    }
};