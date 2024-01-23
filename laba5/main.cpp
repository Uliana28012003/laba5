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
        cerr << "����� ����������: " << duration_cast<milliseconds>(dur).count()
            << " ��" << endl;
    }
private:
    steady_clock::time_point start;
};

int main() {
    {
        LogDuration input;
        setlocale(LC_ALL, "Russian");

        if (testCountWordsInSentence()) {
            cout << "����-����� �������� �������!" << endl;
        }
        else {
            cerr << "����-����� �� ��������!" << endl;
        }

        string filePath = "D:/OOP/lab.txt";

        int targetWordCount;
        cout << "������� �������� ���������� ���� � �����������: ";
        cin >> targetWordCount;

        // ������ ����������� �����
        string fileContent = readFromFile(filePath);
        bool foundSuitableSentences = false;

        if (!fileContent.empty()) {
            // ���������� ������ �� �����������
            istringstream sentenceStream(fileContent);
            string sentence;
            while (getline(sentenceStream, sentence, '.')) {
                // ��������� ������� �����������
                processSentence(sentence, targetWordCount);
                foundSuitableSentences = true;
            }

            // ���� �� ������� ���������� �����������
            if (!foundSuitableSentences) {
                cout << "�� ������� ����������� � ��������� ����������� ����." << endl;
            }
        }
        else {
            cout << "���� ������. ��� ������ ��� ���������." << endl;
        }

        return 0;
    }
}
