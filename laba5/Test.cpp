#include "test.h"  // Включение заголовочного файла для тестирования
#include "TextProcessor.h"  // Включение заголовочного файла для обработки текста
#include <cassert>  
#include <iostream> 

using namespace std;

// Функция для тестирования подсчета слов в предложении
bool testCountWordsInSentence() {
    string sentence1 = "This is test.";
    int wordCount1 = countWordsInSentence(sentence1);  // Вызов функции для подсчета слов
    assert(wordCount1 == 3);  // Проверка с использованием assert
    return true;  
}
