#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, int key) {
    string encrypted_message = "";

    // Шифрование каждой буквы сообщения
    for (int i = 0; i < message.length(); i++) {
        if (isalpha(message[i])) {
            char shifted_char = (toupper(message[i]) - 'A' + key) % 26 + 'A';
            encrypted_message += islower(message[i]) ? tolower(shifted_char) : shifted_char;
        } else {
            encrypted_message += message[i];
        }
    }

    return encrypted_message;
}

string decrypt(string message, int key) {
    // Используем отрицательный ключ для расшифровки сообщения
    return encrypt(message, 26 - key);
}

int main() {
    string message;
    int key;



    //char a = 'A';
    //
    //for (char i = a; i <= 'Z'; i++)
    //{
    //    char b = (char)i;
    //    cout << b << endl;
    //}
    

    cout << "Введите сообщение для шифрования: ";
    getline(cin, message);

    cout << "Введите ключ шифрования: ";
    cin >> key;

    string encrypted_message = encrypt(message, key);
    string decrypted_message = decrypt(encrypted_message, key);

    cout << "Зашифрованное сообщение: " << encrypted_message << endl;
    cout << "Расшифрованное сообщение: " << decrypted_message << endl;

    return 0;
}