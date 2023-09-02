#include <iostream>
#include "stdio.h"
#include <conio.h>
#include "cstdio"
#include <cstring>
#include "windows.h"
#include <tuple>
#include <direct.h>
#include <experimental/filesystem>

static const int NUM_OF_CATEGORIES = 4;
static const wchar_t* cats[NUM_OF_CATEGORIES] = {L"Художественная литература", L"Научная литература",
                                                 L"Учебник", L"Комикс"};

void anyKey();

void warningPrint(const wchar_t*);

wchar_t * char2wchar(const char* cchar);

int CurrentYear(const char date[12]);

char* add_sep(char*);

enum categories {
    nonfiction = 0,
    fiction = 1,
    textbook = 2,
    comics = 3
};

struct BOOK{
    char author[100];
    char title[100];
    int year;
    int price;
    categories category;
    void inp(
            const char* inpAuthor,
            const char* inpTitle,
            int inpYear,
            int inpPrice,
            int inpCategory
    );
    bool StrFill(const char* inpStr, char* finalStr, int size);
    void printReqs();
    void formReqs();
};

struct myLib{
    int numOfBooks;
    int sizeOfBooks;
    char current[255];
    BOOK* books;
    bool rFile();
    bool wFile();
    bool printLib();
    bool newBook();
    bool is_correct_dia(int, int);
    bool delBook(int, int);
    bool Sort(int, bool);
    void popularCategory();
    void assurance(int);
    void assurance(int, int);
};