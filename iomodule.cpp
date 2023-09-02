#include "decl.h"

bool myLib::rFile() {
    setlocale(LC_ALL, "Russian");
    system("cls");
    wchar_t star[67] = L"******************************************************************";
    std::wcout << star << L"\n" <<
                  L"*\tВыберите библиотеку, которую нужно открыть\t\t *\n"
                  L"*\t\t(Введите название файла)\t\t\t *\n"
                  << star << L"\n";
    char current_work_dir[FILENAME_MAX];
    _getcwd(current_work_dir, sizeof(current_work_dir));
    int k = 0;
    for (const auto& entry : std::experimental::filesystem::directory_iterator(current_work_dir)) {
        if (entry.path().extension() == ".txt") {
            k++;
            auto w = entry.path().stem();
            std::wcout << L"*\t" <<  entry.path().stem() << L"\n";
        }
    }
    std::wcout << star << L"\n";
    char filename[FILENAME_MAX];
    std::wcout << L"Название файла: ";
    fflush(stdin);
    fflush(stdout);
    scanf("%[^\n]", filename);
    strcat(filename, ".txt");
    strcpy(current, filename);
    system("cls");
    if (fopen(filename, "r") == nullptr) {
        warningPrint(L"Предупреждение: Файл не найден!");
        std::wcout << L"Файл создан!";
        FILE* file = fopen(filename, "w");
        fprintf(file, "%d", 0);
        fclose(file);
        numOfBooks = sizeOfBooks = 0;
        books = new BOOK[numOfBooks];
        anyKey();
        return false;
    }
    FILE* file = fopen(filename, "r");
    fscanf(file, "%d", &numOfBooks);
    sizeOfBooks = numOfBooks;
    books = new BOOK[numOfBooks];
    char inpAuthor[100];
    char inpTitle[100];
    int inpYear, inpPrice;
    categories inpCategory;
    for (int i = 0; i < numOfBooks; i++) {
        fscanf(file, "%s%s%d%d%d", inpAuthor, inpTitle, &inpYear, &inpPrice, &inpCategory);
        books[i].inp(inpAuthor, inpTitle, inpYear, inpPrice, inpCategory);
    }
    fclose(file);
    return true;
}

bool myLib::wFile() {
    bool f = true;
    setlocale(LC_ALL, "Russian");
    system("cls");
    wchar_t star[67] = L"******************************************************************";
    std::wcout << star << L"\n" <<
               L"*\tВыберите библиотеку, которую нужно открыть\t\t *\n"
               L"*\t(Нажмите на \"c\", чтобы записать в текущий файл,\t\t *\n"
               L"*\tили любую другую кнопку, чтобы ввести название вручную)\t *\n"
               << star << L"\n";
    char current_work_dir[FILENAME_MAX];
    _getcwd(current_work_dir, sizeof(current_work_dir));
    int k = 0;
    for (const auto& entry : std::experimental::filesystem::directory_iterator(current_work_dir)) {
        if (entry.path().extension() == ".txt") {
            k++;
            auto w = entry.path().stem();
            std::wcout << L"*\t" <<  entry.path().stem() << L"\n";
        }
    }
    std::wcout << L"Текущий файл: " << current << L"\n";
    std::wcout << star << L"\n";
    int s = getch();
    char filename[FILENAME_MAX];
    if (s == 99) {
        strcpy(filename, current);
    }
    else {
        std::wcout << L"Название файла: ";
        fflush(stdin);
        fflush(stdout);
        scanf("%[^\n]", filename);
        strcat(filename, ".txt");
    }
    system("cls");
    if (fopen(filename, "r") == nullptr) {
        warningPrint(L"Предупреждение: Файл не найден!");
        std::wcout << L"Файл создан!";
        FILE* file = fopen(filename, "w");
        fclose(file);
        f = false;
    }
    FILE* file = fopen(filename, "w");
    fprintf(file, "%d\n", numOfBooks);
    for (int i = 0; i < numOfBooks; i++) {
        char new_author[100] = {'\0'};
        memcpy(new_author, add_sep(books[i].author), strlen(add_sep(books[i].author)) + 1);
        char new_title[100] = {'\0'};
        memcpy(new_title, add_sep(books[i].title), strlen(add_sep(books[i].title)) + 1);
        fprintf(file, "%s %s %d %d %d\n", new_author,
                new_title, books[i].year, books[i].price, books[i].category);
    }
    fclose(file);
    return f;
}