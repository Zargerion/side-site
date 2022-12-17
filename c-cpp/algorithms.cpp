#include <iostream>
#include <fstream>

using namespace std;

int main() {
  setlocale(LC_ALL, "rus");
 
  int digitals[10]; // объявили массив на 10 ячеек
 
  cout << "Введите 10 чисел для заполнения массива: " << endl;
 
  for (int i = 0; i < 10; i++) {
    cin >> digitals[i]; // "читаем" элементы в массив
  }
 
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 9; j++) {
      if (digitals[j] > digitals[j + 1]) {
        int b = digitals[j]; // создали дополнительную переменную
        digitals[j] = digitals[j + 1]; // меняем местами
        digitals[j + 1] = b; // значения элементов
      }
    }
  }
 
  cout << "Массив в отсортированном виде: ";
 
  for (int i = 0; i < 10; i++) {
    cout << digitals[i] << " "; // выводим элементы массива
  }

  system("pause");
  return 0;



}


