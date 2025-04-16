//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 06-27-2023
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

void readWords(string filename){
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
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    readWords(filename);

    // for (int i = 0; i < 50; i++){
    //     cout << g_words[i] << " " << g_pos[i] << " : " << g_definitions[i] <<  endl;
    // }

    return 0;
}

