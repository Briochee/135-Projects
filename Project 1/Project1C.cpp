//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 06-29-2023
//Program Description: 

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cctype>

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

bool addWord(const string& word, const string& definition, const string& pos){
    int index = getIndex(word);
    if (g_word_count == g_MAX_WORDS){
        return false;
    }
    if (index == (-1)){
        g_words[g_word_count] = word;
        g_definitions[g_word_count] = definition;
        g_pos[g_word_count] = pos;
        g_word_count++;
        return true;
    } 

    return false;
}

bool editWord(const string& word, const string& definition, const string& pos){
    int index = getIndex(word);
    if (index > (-1) && g_words[index] == word){
        g_definitions[index] = definition;
        g_pos[index] = pos;
        return true;
    }
    return false;
}

bool removeWord(const string& word){
    int index = getIndex(word);
    if (index > (-1) && g_words[index] == word){
        g_words[index] = g_words[g_word_count - 1];
        g_definitions[index] = g_definitions[g_word_count - 1];
        g_pos[index] = g_pos[g_word_count - 1];
        for (int i = g_word_count - 1; i < g_MAX_WORDS; i++){
            g_words[i] = "";
            g_definitions[i] = "";
            g_pos[i] = "";
        }
        g_word_count--;
        return true;
    }
    return false;
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

// int main(){
//     string filename, query, prefix, newWord, newDef, newPos;
//     string edtWord, edtDef, edtPos, rmvWord;
//     bool add, edit, remove;

//     cout << "Enter filename: ";
//     cin >> filename;

//     readWords(filename);

//     cout << "Enter word: ";
//     cin >> query;

//     cout << "Defintion: " << getDefinition(query) << "\n\n";

//     cout << "Enter preix: ";
//     cin >> prefix;

//     cout << "Words that start with prefix : " << countPrefix(prefix) << "\n\n";

//     int choice;
//     do { 
//         cout << "Enter 1 to add new word\nEnter 2 to edit word\nEnter 3 to remove a word\nEnter 4 to continue\nChoice: ";
//         cin >> choice;
//         cout << "\n\n";
//         if (choice == 1){
//             cout << "Enter new word: ";
//             cin >> newWord;
//             cout << "Enter the new word's pos: ";
//             cin >> newPos;
//             cout << "Enter the new word's definition: ";
//             cin.ignore();
//             getline(cin, newDef);

//             add = addWord(newWord, newDef, newPos);

//             if (add == true){
//                 cout << "New word added successfully\n\n";
//                 continue;
//             } else if (add == false){
//                 cout << "New word could not be added\n\n" << endl;
//             }
//         } else if (choice == 2){
//             cout << "Enter word you would like to edit: ";
//             cin >> edtWord;
//             cout << "Enter edited pos: ";
//             cin >> edtPos;
//             cout << "Enter edited definition: ";
//             cin.ignore();
//             getline(cin, edtDef);

//             edit = editWord(edtWord, edtDef, edtPos);

//             if (edit == true){
//                 cout << edtWord << " was successfully edited\n\n" << endl;
//             } else if (edit == false){
//                 cout << "Word could not be edited\n\n" << endl;
//             }

//         } else if (choice == 3){
//             cout << "Enter word you would like to remove: ";
//             cin >> rmvWord;

//             remove = removeWord(rmvWord);

//             if (remove == true){
//                 cout << rmvWord << " was successfully removed\n\n" << endl;
//             } else if (remove == false){
//                 cout << rmvWord << " could not be removed\n\n" << endl;
//             }
//         } else if (choice == 4){
//             for (int i = 0; i < g_word_count; i++){
//                 cout << i << " " << g_words[i] << " " << g_pos[i] << " : " << g_definitions[i] << endl;
//             }
//             break;
//         }
//     } while (choice !=4 || isalpha(choice));

//     return 0;
// }