#include<bits/stdc++.h>
using namespace std;

void longestword(string str) {
    string word = "";
    string longest = "";

    for (int i = 0; i < str.length(); i++) {

        if (str[i] != ' ') {
            word += str[i];
        }
        else {
            if (word.length() > longest.length()) {
                longest = word;
            }
            word = "";
        }
    }

    if (word.length() > longest.length()) {
        longest = word;
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length() << endl;
}

int main() {
    string str = "This is a sample string with some long words";
    longestword(str);
    return 0;
}