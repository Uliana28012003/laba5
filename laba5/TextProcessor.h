#pragma once  
#include <string>  
#include <vector>  

using namespace std;

// ������� ��� ���������� ������ �� ���������
vector<string> splitString(const string& str);

// ������� ��� ��������� ����������� � �������� ����������� ����
void processSentence(const string& sentence, int targetWordCount);

// ������� ��� �������� ���� � �����������
int countWordsInSentence(const string& sentence);
