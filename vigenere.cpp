#include <bits/stdc++.h>
using namespace std;

string vigenereEncrypt(string text, string key) {
    string res = "";
    int m = key.size();
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            int p = toupper(c) - 'A';
            int k = toupper(key[i % m]) - 'A';
            res += char('A' + (p + k) % 26);
        } else res += c;
    }
    return res;
}

int main() {
    string plaintext = "thisisaverysimplemessageforencryption";
    string key = "KEYWORD";
    string ciphertext = vigenereEncrypt(plaintext, key);

    cout << "Plaintext: " << plaintext << "\n\n";
    cout << "Ciphertext: " << ciphertext << "\n\n";

    map<char,int> freq;
    for (char c : ciphertext) if (isalpha(c)) freq[c]++;

    vector<pair<char,int>> v(freq.begin(), freq.end());
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });

    char freqWord[] = {'E', 'T', 'A', 'O', 'N'};
    map<char,char>charMap;

    for(int i = 0; i < 5; i++){
        charMap[freqWord[i]] = v[i].first;     
    }
    

    cout << "Letter Frequency:\n";
    for (auto &p : v) {
        cout << p.first << " : " << p.second << " ";
        cout << string(p.second, '*') << "\n";
    }
    cout<<"Mappings:\n";
    for(auto &p:charMap){
        cout<<p.first<<" -> "<<p.second<<"\n";
    }
    cout<<"Guessed Mapping:\n";
    string guessedMapping = "";
    for(char &i:plaintext){
        if(charMap.count(toupper(i))){
            guessedMapping += charMap[toupper(i)];
        } else {
            guessedMapping += i;
        }
    }
    transform(guessedMapping.begin(), guessedMapping.end(), guessedMapping.begin(), ::toupper);
    cout<<guessedMapping;
    cout<<endl;
    cout<<"Plaintext:\n";
    cout<<plaintext<<"\n";
    return 0;
    
}