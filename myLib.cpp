#include "decl.h"

bool myLib::printLib(){
    setlocale(LC_ALL, "Russian");
    system("cls");
    for (int i = 0; i < numOfBooks; i++){
        std::wcout << L"\t ___________\n";
        std::wcout << L"\t/     " << i << "     \\\n";
        books[i].printReqs();
    }
    return true;
}

bool myLib::newBook() {
    int delta = 5;
    if (sizeOfBooks == numOfBooks) {
        sizeOfBooks += delta;
        numOfBooks += 1;
    }
    else
        numOfBooks += 1;
    BOOK* new_books = new BOOK[sizeOfBooks];
    for (int i = 0; i < numOfBooks; i++)
        new_books[i] = books[i];
    new_books[numOfBooks - 1].formReqs();
    delete[] books;
    books = new_books;
    return true;
}

bool myLib::is_correct_dia(int a, int b) {
    if (a < 0 || b > numOfBooks - 1 || a > b)
        return false;
    return true;
}

bool myLib::delBook(int a, int b) {
    if (a < 0 || b > numOfBooks - 1)
        return false;
    BOOK* new_ar = new BOOK[numOfBooks];
    if (a == b) {
        int i = 0;
        for (int j = 0; j < numOfBooks; j++) {
            if (j != a) {
                new_ar[i] = books[j];
                i++;
            }
        }
        numOfBooks--;
    }
    else {
        int i = 0;
        for (int j = 0; j < numOfBooks; j++) {
            if (j < a || j > b) {
                new_ar[i] = books[j];
                i++;
            }
        }
        numOfBooks -= (b - a) + 1;
    }
    delete[] books;
    books = new_ar;
    return true;
}

void myLib::popularCategory() {
    setlocale(LC_ALL, "Russian");
    std::wcout << L"Наиболее популярная категория:\n";
    int dict[NUM_OF_CATEGORIES] {0};
    for (int i = 0; i < numOfBooks; i++)
        dict[books[i].category] += 1;
    int imax = 0;
    int max = dict[imax];
    for (int i = 0; i < NUM_OF_CATEGORIES; i++)
        if (dict[imax] < dict[i]) {
            imax = i;
            max = dict[imax];
        }
    for (int i = 0; i < NUM_OF_CATEGORIES; i++)
        if (dict[i] == max)
            std::wcout << cats[i] << L". Книг такой категории: " << max << L"\n";
}

void myLib::assurance(int k) {
    // 1 - wFile()
    // 2 - rFile()
    // other k -> returning code (exit(k))
    int s;
    do {
        s = getch();
        if (s == 'y') {
            if (k == 1) {
                wFile();
                warningPrint(L"Картотека записана в файл!");
                anyKey();
            }
            else if (k == 2) {
                rFile();
                warningPrint(L"Данные из файла записаны в картотеку!");
                anyKey();
            }
            else exit(k);
            return;
        }
        else if (s == 110 || s == 226) {
            system("cls");
            return;
        }
    } while(true);
}
void myLib::assurance(int a, int b) {
    int s;
    do {
        s = getch();
        if (s == 'y') {
            delBook(a, b);
            anyKey();
            return;
        }
        else if (s == 110 || s == 226) {
            system("cls");
            return;
        }
    } while(true);
}
