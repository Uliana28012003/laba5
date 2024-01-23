#include "TextProcessor.h"  // ��������� ������������� ����� ��� ��������� ������
#include <sstream>  // ��������� ������������� ����� ��� ������ � �������� �����
#include <algorithm>  
#include <iostream> 

using namespace std;

// ������� ��� ���������� ������ �� ���������
vector<string> splitString(const string& str) {
    vector<string> words;

    // ������� ����� ���������� ����� �� ������� ������
    istringstream iss(str);

    // �������� ������ �� ������ � ������ 
    copy(istream_iterator<string>(iss),
        istream_iterator<string>(),
        back_inserter(words));

    // ���������� ������, ���������� ��������� �� �������� ������
    return words;
}

// ������� ��� ��������� ����������� � �������� ����������� ����
void processSentence(const string& sentence, int targetWordCount) {
    // ��������� ����������� �� ����� � �������������� ������� splitString
    vector<string> words = splitString(sentence);

    // ���������, �������� �� ����������� �������� ���������� ����
    if (words.size() == targetWordCount) {
        // ������� ����������� � ������ � �����
        cout << sentence << '.' << endl;
    }
}

// ������� ��� �������� ���� � �����������
int countWordsInSentence(const string& sentence) {
    // ������� ����� ���������� ����� �� �������� �����������
    istringstream iss(sentence);

    int wordCount = 0;
    string word;

    // ����������� �� ������, ������ ������ �����
    while (iss >> word) {
        wordCount++;
    }
    return wordCount;
}

