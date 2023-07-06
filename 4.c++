#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string removeNonAlphabetic(const string& message) {
    string result = "";
    for (char c : message) {
        if (isalpha(c)) {
            result += toupper(c);
        }
    }
    return result;
}
string encryptVigenere(const string& message, const string& key) {
    string encryptedMessage = "";
    string cleanedMessage = removeNonAlphabetic(message);
    string cleanedKey = removeNonAlphabetic(key);
    int keyIndex = 0;
    for (char c : cleanedMessage) {
        char encryptedChar = (c - 'A' + cleanedKey[keyIndex] - 'A') % 26 + 'A';
        encryptedMessage += encryptedChar;
        keyIndex = (keyIndex + 1) % cleanedKey.length();
    }
    return encryptedMessage;
}
string decryptVigenere(const string& encryptedMessage, const string& key) {
    string decryptedMessage = "";
    string cleanedMessage = removeNonAlphabetic(encryptedMessage);
    string cleanedKey = removeNonAlphabetic(key);
    int keyIndex = 0;
    for (char c : cleanedMessage) {
        char decryptedChar = (c - 'A' - (cleanedKey[keyIndex] - 'A') + 26) % 26 + 'A';
        decryptedMessage += decryptedChar;
        keyIndex = (keyIndex + 1) % cleanedKey.length();
    }
    return decryptedMessage;
}
int main() {
    string message;
    string key;
    cout << "Enter the message to encrypt: ";
    cin >> message;
    cout << "Enter the encryption key: ";
    cin >> key;
    string encryptedMessage = encryptVigenere(message, key);
    cout << "Encrypted message: " << encryptedMessage << endl;
    string decryptedMessage = decryptVigenere(encryptedMessage, key);
    cout << "Decrypted message: " << decryptedMessage << endl;
    return 0;
}
