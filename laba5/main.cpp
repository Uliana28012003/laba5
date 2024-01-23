#include "FileHandler.h"
#include "TextProcessor.h"
#include "test.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace chrono;
using namespace std;


class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << "Время выполнения: " << duration_cast<milliseconds>(dur).count()
            << " мс" << endl;
    }
private:
    steady_clock::time_point start;
};

int main() {
    {
        LogDuration input;
        setlocale(LC_ALL, "Russian");

        if (testCountWordsInSentence()) {
            cout << "Юнит-тесты пройдены успешно!" << endl;
        }
        else {
            cerr << "Юнит-тесты не пройдены!" << endl;
        }

        string filePath = "D:/OOP/lab.txt";

        int targetWordCount;
        cout << "Введите желаемое количество слов в предложении: ";
        cin >> targetWordCount;

        // Чтение содержимого файла
        string fileContent = readFromFile(filePath);
        bool foundSuitableSentences = false;

        if (!fileContent.empty()) {
            // Разделение текста на предложения
            istringstream sentenceStream(fileContent);
            string sentence;
            while (getline(sentenceStream, sentence, '.')) {
                // Обработка каждого предложения
                processSentence(sentence, targetWordCount);
                foundSuitableSentences = true;
            }

            // Если не найдено подходящих предложений
            if (!foundSuitableSentences) {
                cout << "Не найдено предложений с указанным количеством слов." << endl;
            }
        }
        else {
            cout << "Файл пустой. Нет данных для обработки." << endl;
        }

        return 0;
    }
}
