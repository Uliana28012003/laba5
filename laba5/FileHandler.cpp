#include "FileHandler.h"  // Включение заголовочного файла для объявления функции
#include <iostream>  
#include <fstream>  // Включение заголовочного файла для работы с файлами

using namespace std;

// Реализация функции для чтения содержимого файла по указанному пути
string readFromFile(const string& filePath) {
    ifstream file(filePath);  // Открытие файла для чтения
    if (!file.is_open()) {
        cerr << "Unable to open the file." << endl;  // Вывод сообщения об ошибке, если файл не удалось открыть
        return "";  
    }

    // Чтение содержимого файла в строку
    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close(); 
    return content;  
}
