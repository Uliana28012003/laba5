#pragma once  
#include <string>  
#include <vector>  

using namespace std;

// Функция для разделения строки на подстроки
vector<string> splitString(const string& str);

// Функция для обработки предложения с заданным количеством слов
void processSentence(const string& sentence, int targetWordCount);

// Функция для подсчета слов в предложении
int countWordsInSentence(const string& sentence);
