#include "test.h"  // ��������� ������������� ����� ��� ������������
#include "TextProcessor.h"  // ��������� ������������� ����� ��� ��������� ������
#include <cassert>  
#include <iostream> 

using namespace std;

// ������� ��� ������������ �������� ���� � �����������
bool testCountWordsInSentence() {
    string sentence1 = "This is test.";
    int wordCount1 = countWordsInSentence(sentence1);  // ����� ������� ��� �������� ����
    assert(wordCount1 == 3);  // �������� � �������������� assert
    return true;  
}
