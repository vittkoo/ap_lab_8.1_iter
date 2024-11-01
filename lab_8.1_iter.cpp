#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str) {
    int k = 0;
    char* pos = str;

    while ((pos = strstr(pos, "while")) != 0) {  // Заміна nullptr на 0
        k++;
        pos += 5;  // Зсув на довжину "while"
    }

    return k;
}

char* Change(char* str) {
    const char* pattern = "while";
    const char* replacement = "***";
    size_t len = strlen(str);

    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;

    while (str[i] != '\0') {
        if (strncmp(&str[i], pattern, strlen(pattern)) == 0) {
            strcat(t, replacement);
            t += strlen(replacement);
            i += strlen(pattern);
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    strcpy(str, tmp);
    return tmp;
}

int main() {
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of \"while\"" << endl;

    char* ModifiedStr = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << ModifiedStr << endl;

    delete[] ModifiedStr;
    return 0;
}
