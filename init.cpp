#include "decl.h"

void anyKey() {
    setlocale(LC_ALL, "Russian");
    std::wcout << L"Чтобы продолжить, нажмите на любую кнопку\n";
    getch();
    system("cls");
}

void warningPrint(const wchar_t* s) {
    setlocale(LC_ALL, "Russian");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::wcout << s << L"\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

wchar_t * char2wchar(const char* cchar) {
    wchar_t *m_wchar;
    int len = MultiByteToWideChar( CP_ACP ,0,cchar ,strlen( cchar), NULL,0);
    m_wchar= new wchar_t[len+1];
    MultiByteToWideChar( CP_ACP ,0,cchar,strlen( cchar),m_wchar,len);
    m_wchar[len]= '\0' ;
    return m_wchar;
}

int CurrentYear(const char date[12]){
    int year = 0;
    int k = 1;

    for (int i = 10; i > 6; i--){
        if ('0' <= date[i] && date[i] <= '9')
            year += (date[i] - '0') * k;
        k *= 10;
    }
    return year;
}

void BOOK::inp(const char *inpAuthor, const char *inpTitle,  int inpYear, int inpPrice, int inpCategory) {
    if (!(StrFill(inpAuthor, author, 100))) {
        warningPrint(L"Предупреждение: Слишком длинное имя автора");
    }
    if (!(StrFill(inpTitle, title, 100))) {
        warningPrint(L"Предупреждение: Слишком длинное название");
    }
    if (inpYear < -1000 || inpYear > CurrentYear(__DATE__)) {
        warningPrint(L"Предупреждение: Неверный год");
        warningPrint(L"(значение обнулено)\n");
        year = 0;
    }
    else
        year = inpYear;
    if (inpPrice < 0){
        warningPrint(L"Предупреждение: Неверная цена");
        warningPrint(L"(значение обнулено)\n");
        price = 0;
    }
    else
        price = inpPrice;

    if (inpCategory >= 0 && inpCategory < 4)
        category = static_cast<categories>(inpCategory);
    else{
        warningPrint(L"Предупреждение: Неверная категория");
        warningPrint(L"(значение обнулено)\n");
        category = nonfiction;
    }
}

bool BOOK::StrFill(const char *inpStr, char *finalStr, int size) {
    int i = 0;
    while(i < size && inpStr[i] != '\0'){
        if (inpStr[i] == 0x1f)
            finalStr[i] = ' ';
        else
            finalStr[i] = inpStr[i];
        i++;
    }
    if (inpStr[i] != '\0') {
        finalStr[i - 1] = '\0';
        return false;
    }
    finalStr[i] = '\0';
    return true;
}

void BOOK::printReqs() {
    setlocale(LC_ALL, "Russian");
    std::wcout << L"=======================================================\n";
    std::wcout << L"Автор: " << char2wchar(author) << '\n';
    std::wcout << L"Название: " << char2wchar(title) << '\n';
    std::wcout << L"Год публикации: " << year << '\n';
    std::wcout << L"Цена: " << price << '\n';
    std::wcout << L"Категория литературы: " << cats[category] << '\n';
    std::wcout << L"=======================================================\n";
}

void BOOK::formReqs() {
    char inpAuthor[1000];
    char inpTitle[1000];
    int inpYear, inpPrice;
    categories inpCategory;

    std::wcout << L"Введите реквизиты книги\n"
                  L"(Автор и название должны содержать не более 100 символов)\n"
                  L"========================================================\n";

    std::wcout << L"Автор: ";
    fflush(stdin);
    scanf("%[^\n]", &inpAuthor);

    std::wcout << L"Название: ";
    fflush(stdin);
    scanf("%[^\n]", &inpTitle);

    while (true) {
        std::wcout << L"Год публикации: ";
        fflush(stdin);
        if (scanf("%d", &inpYear) == 0) {
            warningPrint(L"Неверно введен год (введите число)");
        }
        else if (inpYear < -1000 || inpYear > CurrentYear(__DATE__))
            warningPrint(L"Неверно введен год");
        else
            break;
    }

    while (true) {
        std::wcout << L"Цена: ";
        fflush(stdin);
        if (scanf("%d", &inpPrice) == 0) {
            warningPrint(L"Неверно введена цена (введите число)");
        }
        else if (inpPrice < 0)
            warningPrint(L"Неверная цена (не может быть <0)");
        else
            break;
    }

    while (true) {
        std::wcout << L"Категория литературы (Введите номер категории)\n";
        for (int i = 0; i < NUM_OF_CATEGORIES; i++)
            std::wcout << i << L" - " << cats[i] << L"\n";
        fflush(stdin);
        if (scanf("%d", &inpCategory) == 0) {
            warningPrint(L"Неверно введена категория (введите число)");
        }
        else if (inpCategory < 0 || inpCategory > 4)
            warningPrint(L"Неверно введена категория (неверно указан номер)");
        else
            break;
    }

    inp(inpAuthor, inpTitle, inpYear, inpPrice, inpCategory);
    std::cout << '\n';
}

char* add_sep(char* s) {
    static char new_s[100];
    memset(new_s, '\0', sizeof(new_s));
    int i = 0;
    while (i < 100 && s[i] != '\0') {
        if (s[i] == ' ')
            new_s[i] = 0x1f;
        else
            new_s[i] = s[i];
        i++;
    }
    return new_s;
}