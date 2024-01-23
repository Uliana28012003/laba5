#include "FileHandler.h"  // ��������� ������������� ����� ��� ���������� �������
#include <iostream>  
#include <fstream>  // ��������� ������������� ����� ��� ������ � �������

using namespace std;

// ���������� ������� ��� ������ ����������� ����� �� ���������� ����
string readFromFile(const string& filePath) {
    ifstream file(filePath);  // �������� ����� ��� ������
    if (!file.is_open()) {
        cerr << "Unable to open the file." << endl;  // ����� ��������� �� ������, ���� ���� �� ������� �������
        return "";  
    }

    // ������ ����������� ����� � ������
    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close(); 
    return content;  
}
