//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 07-24-2023
//Program Description: project 2 task B -- trainer

//header files
#include "trainer.hpp"

#include<vector>
#include<string>
#include<iostream>

using namespace std;

// data members
// vector<Profemon> profedex;
// Profemon team[3];
// Profemon* currentProfemon;


Trainer::Trainer(){
    currentProfemon = nullptr;
}

Trainer::Trainer(std::vector<Profemon> profemons) {
    for (Profemon profemon : profemons) {
        if (contains(profemon.getName()) == false) {
            if (team[0].getName() == "Undefined") {
                team[0] = profemon;
                currentProfemon = &team[0]; // Set the first profémon in the team as the current profémon
            } else if (team[1].getName() == "Undefined") {
                team[1] = profemon;
            } else if (team[2].getName() == "Undefined") {
                team[2] = profemon;
            } else {
                profedex.push_back(profemon);
            }
        }
    }
}

bool Trainer::contains(std::string name){
    for (Profemon profemon : team){
        if (profemon.getName() == name){
            return true;
        }
    }
    for (Profemon profemon : profedex){
        if (profemon.getName() == name){
            return true;
        }
    }
    return false;
}

// bool Trainer::addProfemon(Profemon profemon){
//     if (contains(profemon.getName()) == true){
//         return false;
//     } else {
//         for (int i = 0; i < 3; i++){
//             if (team[i].getName() == "Undefined"){
//                 team[i] = profemon;
//             } else {
//                 profedex.push_back(profemon);
//             }
//         }
//     }
//     return true;
// }

bool Trainer::addProfemon(Profemon profemon) {
    if (contains(profemon.getName()) == true) {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        if (team[i].getName() == "Undefined") {
            team[i] = profemon;
            if (currentProfemon == nullptr) {
                currentProfemon = &team[i]; // Set the newly added profémon as the current profémon
            }
            return true;
        }
    }

    profedex.push_back(profemon);
    return true;
}

bool Trainer::removeProfemon(std::string name){
    if (contains(name) == false){
        return false;
    } else {
        for (int i = 0; i < 3; i++){
            if (team[i].getName() == name){
                team[i] = Profemon();
            }
        }
        for (vector<Profemon>::iterator pos = profedex.begin(); pos != profedex.end(); pos++){
            if(pos->getName() == name){
                profedex.erase(pos);
            }
        }
    }
    return true;
}

// void Trainer::setTeamMember(int slot, std::string name){
//     if (slot >= 0 && slot < 3 && contains(name) == true){
//         for (int i = 0; i < profedex.size(); i++){
//             if (profedex[i].getName() == name){
//                 if (team[slot].getName() == "Undefined"){
//                     team[slot] = profedex[i];
//                 } else {
//                     swap(team[slot], profedex[i]);
//                 }
//                 break;
//             }
//         }

//     }
// }

void Trainer::setTeamMember(int slot, std::string name) {
    if (slot >= 0 && slot < 3 && contains(name) == true) {
        for (int i = 0; i < profedex.size(); i++) {
            if (profedex[i].getName() == name) {
                if (team[slot].getName() == "Undefined") {
                    team[slot] = profedex[i];
                    profedex.erase(profedex.begin() + i); // Remove the profémon from the profédex
                } else {
                    swap(team[slot], profedex[i]);
                }

                // Update the current profémon pointer if the profémon at the given slot is the current profémon
                if (currentProfemon == &team[slot]) {
                    currentProfemon = &team[slot];
                }

                break;
            }
        }
    }
}


// bool Trainer::chooseProfemon(int slot){
//     if (slot >= 0 && slot <3){
//         if (team[slot].getName() != "Undefined"){
//             currentProfemon = &team[slot];
//             return true;
//         }
//     }
//     return false;
// }

bool Trainer::chooseProfemon(int slot) {
    if (slot >= 0 && slot < 3) {
        if (team[slot].getName() != "Undefined") {
            currentProfemon = &team[slot]; // Update the current profémon pointer
            return true;
        }
    }
    return false;
}

Profemon Trainer::getCurrent(){
    return *currentProfemon;
}

void Trainer::printProfedex(){
    for (Profemon profemon : profedex){
        profemon.printProfemon(false);
        cout << endl;
    }
}

// void Trainer::printTeam(){
//     for(Profemon profemon : team){
//         profemon.printProfemon(true);
//         cout << endl;
//     }
// }

void Trainer::printTeam() {
    for (Profemon profemon : team) {
        if (profemon.getName() != "Undefined") {
            profemon.printProfemon(true);
            cout << endl;
        }
    }
}
