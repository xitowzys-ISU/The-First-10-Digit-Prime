#include <cmath>
#include <iostream>
#include <fstream>

// Функция перехода на следующую строку
void goToTheNextLine(const char* buffer, int& pPosition);

int main()
{
    // Пространство имен
    using namespace std;

    // Положение указателя в файле
    int pPosition = 0;

    long primeNumber = 0;

    // Является ли число простым
    bool isPrime;

    // Открыть файла
    ifstream in;
    in.open("/Users/xitowzys/Documents/xitowzys/Programming/XcodeProjects/theFirstTenDigitPrime/resources/e2mil.txt", ios::binary);

    // Размер буфера
    int size = in.seekg(0, ios::end).tellg();
    // Перемещение указателя в начало файла
    in.seekg(0);
    // Буфер с данными файла
    char* buf = new char[size + 1];
    // Запись файла в буфер
    in.read(buf, size);
    // Терминирующий ноль в конец буфера
    buf[size] = '\0';

    // Перехода на следующую строку
    goToTheNextLine(buf, pPosition);

    // Пропускаем "2."
    pPosition+= 2;


    while (true)
    {
        // Число является простым
        isPrime = true;

        //Первый 10 чисел
        sscanf(buf + pPosition, "%10ld" ,&primeNumber);

        // Число имеет 10 символом
        if (primeNumber== 0 ? 1: int (log10 (primeNumber) + 1) < 9)
        {
            pPosition++;
            continue;
        }

        // Если число явялется не простым, то isPrime = false
        for(long i = 2; i<sqrt(primeNumber); i++) {
            if(primeNumber % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            cout << "Простое число: " << primeNumber << endl;
            break;
        }

        // Перемещение на 1 символ вперед
        pPosition++;
    }

    return 0;
}

// Функция перехода на следующую строку
void goToTheNextLine(const char* buffer, int& pPosition)
{
    for (; (buffer[pPosition] != '\n' && buffer[pPosition] != '\0'); pPosition++) {}

    if (buffer[pPosition] == '\n') {
        pPosition++;
    }
}
