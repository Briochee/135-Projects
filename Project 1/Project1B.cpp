//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 06-29-2023
//Program Description: 

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;
    
string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

int getIndex(const string& word){
    for (int i = 0; i < g_word_count; i++){
        if (g_words[i] == word){
            return i;
        }
    }
    return -1;
}

string getDefinition(const string& word){
    int index = getIndex(word);
    if (index != -1 && !g_definitions[index].empty()){
        return g_definitions[index];
    }
    return "NOT_FOUND";
}

string getPOS(const string& word){
    int index = getIndex(word);
    if (index != -1 && !g_definitions[index].empty()){
        return g_pos[index];
    }
    return "NOT_FOUND";
}

int countPrefix(const string& prefix){
    int count = 0;
    for (int i = 0; i < g_word_count; i++){
        if (prefix == g_words[i].substr(0, prefix.length())){
            count++;
        }
    }
    return count;
}

void readWords(const string& filename){
    ifstream myFile(filename);
    if(!myFile){
        cerr << "Failed to open file" << endl;
        exit(1);
    }
    string word, pos, colon, def;
    while (myFile >> word >> pos >> colon){
        getline(myFile >> ws, def);
        // myFile.ignore(INT_MAX , '\n');
        
        g_words[g_word_count] = word;
        g_pos[g_word_count] = pos;
        
        // getline(cin.ignore(INT_MAX), def);
        g_definitions[g_word_count] = def;
        
        g_word_count++;
    }
    myFile.close();
}

int main(){
    string filename, query, prefix;
    cout << "Enter filename: ";
    cin >> filename;

    readWords(filename);

    cout << "Enter word: ";
    cin >> query;

    cout << "Defintion: " << getDefinition(query) << endl;

    cout << "Enter preix: ";
    cin >> prefix;

    cout << "Words that start with prefix : " << countPrefix(prefix) << endl;


    // for (int i = 0; i < 50; i++){
    //     cout << g_words[i] << " " << g_pos[i] << " : " << g_definitions[i] <<  endl;
    // }

    return 0;
}