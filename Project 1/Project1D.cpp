//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 06-29-2023
//Program Description: 
#include <stdlib.h>
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

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

string maskWord(const string& word){
    string maskedString;
    for (char c : word){
        maskedString += '_';
    }
    return maskedString;
}

int getTries(const int& difficulty){
    if (difficulty == 0){
        return 9;
    } else if (difficulty == 1){
        return 7;
    }
    return 5;
}

void printAttempts(const int& tries, const int& difficulty){
    for (int i = 0; i < tries; i++){
        cout << 'O';
    } 
    for (int i = 0; i < getTries(difficulty) - tries; i++){
        cout << 'X';
    }
}

bool revealLetter(const string& word, const char& letter, string& current) {
    bool reveal = false;
    for (int i = 0; i < word.length(); i++){
        char currentChar = word[i];
        if (currentChar == toupper(letter)){
            current[i] = toupper(letter);
            reveal = true;
        }
        if (currentChar == letter){
            current[i] = letter;
            reveal = true;
        }
    }
    if (reveal == true){
        return true;
    }
    return false;
}

void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}

int main(){
    string filename;
    cout << "Enter Dictionary Name: ";
    cin >> filename;
    readWords(filename);
    gameLoop();
    return 0;
}