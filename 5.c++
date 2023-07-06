#include <iostream>
#include <string>

using namespace std;

int main() {
    int i, j, len, rails, count, code[100][1000];
    string str;

    cout << "Enter a Secret Message: ";
    getline(cin, str);
    len = str.length();

    cout << "Enter number of rails: ";
    cin >> rails;

    for (i = 0; i < rails; i++) {
        for (j = 0; j < len; j++) {
            code[i][j] = 0;
        }
    }
    count = 0;
    j = 0;
    while (j < len) {
        if (count % 2 == 0) {
            for (i = 0; i < rails; i++) {
                code[i][j] = (int)str[j];
                j++;
            }
        } else {
 for (i = rails - 2; i > 0; i--) {
                code[i][j] = (int)str[j];
                j++;
            }
        }

        count++;
    }
    string decryptedMsg;
    count = 0;
    j = 0;
    while (j < len) {
        if (count % 2 == 0) {
            for (i = 0; i < rails; i++) {
                if (code[i][j] != 0) {
                    decryptedMsg += (char)code[i][j];
                    j++;
                }
            }
        } else {
            for (i = rails - 2; i > 0; i--) {
                if (code[i][j] != 0) {
                    decryptedMsg += (char)code[i][j];
                    j++;
                }
            }
        }
     count++;
    }
    cout << "Original Message: " << str << endl;
    cout << "Encrypted Message: ";
    for (i = 0; i < rails; i++) {
        for (j = 0; j < len; j++) {
            if (code[i][j] != 0)
                cout << (char)code[i][j];
        }
    }
    cout << endl;
    cout << "Decrypted Message: " << decryptedMsg << endl;
    return 0;
}
