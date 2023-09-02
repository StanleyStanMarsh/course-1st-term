/*************************************************************
	Практическое занятие №5. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/

#include <conio.h>
#include "decl.h"
#include "vld.h"
//#define	  stop __asm nop


int main()
{
    //system("chcp 866");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    system("cls");
    std::wcout << L"x_______________________________________________________x\n"
                 L"|\tДобро пожаловать в менеджер картотеки\t\t|\n"
                 L"|\tLicense: free software for non-commercial use\t|\n"
                 L"x_______________________________________________________x\n";
    Sleep(2000);
    system("cls");

    myLib Library;

    Library.rFile();

    while (true) {
        const wchar_t* star = L"*************************************************";
        std::wcout << star << L"\n" <<
                      L"*\t\tВыберите пункт меню\t\t*\n"
                      L"*(Нажмите на цифру соответствующую пункту меню)\t*\n"
                      << star << L"\n" <<
                      L"*1. Вывести содержимое картотеки\t\t*\n"
                      L"*2. Добавить книгу в картотеку\t\t\t*\n"
                      L"*3. Удалить книгу(-и)\t\t\t\t*\n"
                      L"*4. Отсортировать книги\t\t\t\t*\n"
                      L"*5. Самая популярная категория\t\t\t*\n"
                      L"*6. Сохранить все внесенные изменения в файл\t*\n"
                      L"*7. Считать данные из файла\t\t\t*\n"
                      L"*8. Выход из программы\t\t\t\t*\n"
                      << star << L"\n";
        int i = getch();
        system("cls");

        if (i == 49) { // 1
            if (Library.numOfBooks == 0) {
                warningPrint(L"Картотека пуста!");
                anyKey();
                continue;
            }
            Library.printLib();
            anyKey();
        }

        else if (i == 50) { // 2
            Library.newBook();
            warningPrint(L"\nДанные занесены в картотеку");
            warningPrint(L"Чтобы увидеть изменения, нажмите в главном меню \"1\"");
            anyKey();
        }

        else if (i == 51) { // 3
            if (Library.numOfBooks == 0) {
                warningPrint(L"Картотека пуста!");
                anyKey();
                continue;
            }
            std::wcout
                    << L"Какие книги требуется удалить? Введите 2 числа - диапазон, через пробел (индексация с нуля)\n\n"
                       L"(например, введя \"2 6\", вы удалите книги в диапазоне [2; 6])\n\n"
                       L"Чтобы удалить одну книгу, 2 раза введите ее номер: \"N N\"\n\n\n";
            std::wcout << L"На данный момент в картотеке: " << Library.numOfBooks << L" книг\n\n";
            int a, b;
            while (true) {
                std::wcout << L"Диапазон: ";
                fflush(stdin);
                if (scanf("%d %d", &a, &b) != 2) {
                    warningPrint(L"Неверно введен диапазон (введите два числа через пробел)\n");
                }
                else if (!Library.is_correct_dia(a, b)) {
                    warningPrint(L"Неверно введен диапазон (введенные числа не удовлетворяют картотеке)");
                }
                else {
                    std::wcout << L"Вы уверены, что хотите продолжить? (y/n)\n";
                    Library.assurance(a, b);
                    break;
                }
            }
        }

        else if (i == 52) { // 4
            system("cls");
            if (Library.numOfBooks == 0) {
                warningPrint(L"Картотека пуста!");
                anyKey();
                continue;
            }
            int c;
            while (true) {
                std::wcout << L"Сортировка по:\n"
                              L"(Нажмите на цифру соответствующую пункту меню)\n"
                              L"1. Автору\n"
                              L"2. Названию\n"
                              L"3. Году публикации\n"
                              L"4. Цене\n"
                              L"5. Категории\n";
                c = getch();
                system("cls");
                if (c >= '1' && c <= '5')
                    break;
            }
            int s;
            while (true) {
                std::wcout << L"Сортировка по:\n"
                              L"1. Возрастанию\n"
                              L"2. Убыванию\n";
                s = getch();
                system("cls");
                if (s >= '1' && s <= '2')
                    break;
            }
            if (s == 49)
                Library.Sort(c - 48, true);
            else
                Library.Sort(c - 48, false);
            system("cls");
            warningPrint(L"Данные отсортированы\nЧтобы увидеть изменения, нажмите в главном меню \"1\"");
            anyKey();
        }

        else if (i == 53) { // 5
            system("cls");
            if (Library.numOfBooks == 0) {
                warningPrint(L"Картотека пуста!");
                anyKey();
                continue;
            }
            Library.popularCategory();
            anyKey();
        }

        else if (i == 54) { // 6
            warningPrint(L"Данные в файле, в который вы сохраните текущую картотеку");
            warningPrint(L"будут безвозвратно перезаписаны");
            std::wcout << L"Вы уверены, что хотите сохранить картотеку? (y/n)\n";
            Library.assurance(1);
        }

        else if (i == 55) { // 7
            warningPrint(L"Несохраненные изменения будут утеряны");
            std::wcout << L"Вы уверены, что хотите открыть файл? (y/n)\n";
            Library.assurance(2);
        }

        else if (i == 56) { // 8
            warningPrint(L"Несохраненные изменения будут утеряны");
            std::wcout << L"Вы уверены что хотите выйти? (y/n)\n";
            Library.assurance(0);
        }

        else {
            warningPrint(L"Неверный пункт меню");
            anyKey();
        }
    }
}