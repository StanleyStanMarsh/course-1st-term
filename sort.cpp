#include "decl.h"

bool myLib::Sort(int a, bool f) {
    if (f) {
        if (a == 1) {
            for (int i = 0; i < numOfBooks - 1; i++) {
                int min = i;
                for (int j = i + 1; j < numOfBooks; j++) {
                    if (strcmp(books[j].author, books[min].author) < 0)
                        min = j;
                }
                BOOK tmp = books[min];
                books[min] = books[i];
                books[i] = tmp;
            }
            return f;
        }
        else if (a == 2) {
            for (int i = 0; i < numOfBooks - 1; i++) {
                int min = i;
                for (int j = i + 1; j < numOfBooks; j++) {
                    if (strcmp(books[j].title, books[min].title) < 0)
                        min = j;
                }
                BOOK tmp = books[min];
                books[min] = books[i];
                books[i] = tmp;
            }
            return f;
        }
        else if (a == 3) {
            for (int i = 0; i < numOfBooks - 1; i++) {
                int min = i;
                for (int j = i + 1; j < numOfBooks; j++) {
                    if (books[j].year < books[min].year)
                        min = j;
                }
                BOOK tmp = books[min];
                books[min] = books[i];
                books[i] = tmp;
            }
            return f;
        }
        else if (a == 4) {
            for (int i = 0; i < numOfBooks - 1; i++) {
                int min = i;
                for (int j = i + 1; j < numOfBooks; j++) {
                    if (books[j].price < books[min].price)
                        min = j;
                }
                BOOK tmp = books[min];
                books[min] = books[i];
                books[i] = tmp;
            }
            return f;
        }
        else if (a == 5) {
            for (int i = 0; i < numOfBooks - 1; i++) {
                int min = i;
                for (int j = i + 1; j < numOfBooks; j++) {
                    if (books[j].category < books[min].category)
                        min = j;
                }
                BOOK tmp = books[min];
                books[min] = books[i];
                books[i] = tmp;
            }
            return f;
        }
    }
    if (a == 1) {
        for (int i = 0; i < numOfBooks - 1; i++) {
            int max = i;
            for (int j = i + 1; j < numOfBooks; j++) {
                if (strcmp(books[j].author, books[max].author) > 0)
                    max = j;
            }
            BOOK tmp = books[max];
            books[max] = books[i];
            books[i] = tmp;
        }
        return f;
    }
    else if (a == 2) {
        for (int i = 0; i < numOfBooks - 1; i++) {
            int max = i;
            for (int j = i + 1; j < numOfBooks; j++) {
                if (strcmp(books[j].title, books[max].title) > 0)
                    max = j;
            }
            BOOK tmp = books[max];
            books[max] = books[i];
            books[i] = tmp;
        }
        return f;
    }
    else if (a == 3) {
        for (int i = 0; i < numOfBooks - 1; i++) {
            int max = i;
            for (int j = i + 1; j < numOfBooks; j++) {
                if (books[j].year > books[max].year)
                    max = j;
            }
            BOOK tmp = books[max];
            books[max] = books[i];
            books[i] = tmp;
        }
        return f;
    }
    else if (a == 4) {
        for (int i = 0; i < numOfBooks - 1; i++) {
            int max = i;
            for (int j = i + 1; j < numOfBooks; j++) {
                if (books[j].price > books[max].price)
                    max = j;
            }
            BOOK tmp = books[max];
            books[max] = books[i];
            books[i] = tmp;
        }
        return f;
    }
    else if (a == 5) {
        for (int i = 0; i < numOfBooks - 1; i++) {
            int max = i;
            for (int j = i + 1; j < numOfBooks; j++) {
                if (books[j].category > books[j].category)
                    max = j;
            }
            BOOK tmp = books[max];
            books[max] = books[i];
            books[i] = tmp;
        }
        return f;
    }
    return f;
}