#include "TextProcessor.h"  // Включение заголовочного файла для обработки текста
#include <sstream>  // Включение заголовочного файла для работы с потоками строк
#include <algorithm>  
#include <iostream> 

using namespace std;

// Функция для разделения строки на подстроки
vector<string> splitString(const string& str) {
    vector<string> words;

    // Создаем поток строкового ввода из входной строки
    istringstream iss(str);

    // Копируем строки из потока в вектор 
    copy(istream_iterator<string>(iss),
        istream_iterator<string>(),
        back_inserter(words));

    // Возвращаем вектор, содержащий подстроки из исходной строки
    return words;
}

// Функция для обработки предложения с заданным количеством слов
void processSentence(const string& sentence, int targetWordCount) {
    // Разделяем предложение на слова с использованием функции splitString
    vector<string> words = splitString(sentence);

    // Проверяем, содержит ли предложение заданное количество слов
    if (words.size() == targetWordCount) {
        // Выводим предложение с точкой в конце
        cout << sentence << '.' << endl;
    }
}

// Функция для подсчета слов в предложении
int countWordsInSentence(const string& sentence) {
    // Создаем поток строкового ввода из входного предложения
    istringstream iss(sentence);

    int wordCount = 0;
    string word;

    // Итерируемся по потоку, считая каждое слово
    while (iss >> word) {
        wordCount++;
    }
    return wordCount;
}

