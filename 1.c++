#include <iostream>
#include <string>
using namespace std;
string encryptCaesar(const string& message, int shift) {
    string encryptedMessage = "";
    for (char c : message) {
        if (isalpha(c) && isupper(c)) {
            char encryptedChar = 'A' + (c - 'A' + shift) % 26;
            encryptedMessage += encryptedChar;
        }
        else if (isalpha(c) && islower(c)) {
            char encryptedChar = 'a' + (c - 'a' + shift) % 26;
            encryptedMessage += encryptedChar;
        }
        else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}
string decryptCaesar(const string& encryptedMessage, int shift) {
    int decryptionShift = 26 - shift;
    return encryptCaesar(encryptedMessage, decryptionShift);
}
int main() {
    string message;
    int shift;
    cout << "Enter the message to encrypt: ";
    cin >> message;
    cout << "Enter the shift value: ";
    cin >> shift;
    string encryptedMessage = encryptCaesar(message, shift);
    cout << "Encrypted message: " << encryptedMessage << endl;
    string decryptedMessage = decryptCaesar(encryptedMessage, shift);
    cout << "Decrypted message: " << decryptedMessage << endl;
    return 0;
}
