//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 07-24-2023
//Program Description: project 2 task B -- trainer

//header files
#include "trainer.hpp"

#include<vector>
#include<string>
#include<iostream>


Trainer::Trainer(){
    currentProfemon = nullptr;
}

Trainer::Trainer(std::vector<Profemon> profemons){
    for(int i = 0;i < 3; i++){
        team[i] = profemons[i];
    }
    if (profemons.size() > 3){
        for (int i = 3; i < profemons.size(); i++){
            addProfemon(profemons[i]);
        }
    }
    chooseProfemon(0);
}

bool Trainer::contains(std::string name){
    for (int i = 0; i < profedex.size(); i++){
        if (profedex[i].getName() == name){
            return true;
        }
    }
    return false;
}

bool Trainer::addProfemon(Profemon profemon){
    if (contains(profemon.getName())) {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        if (team[i].getName() == "Undefined") {
            team[i] = profemon;
            currentProfemon = &team[i];
            return true;
        }
    }

    profedex.push_back(profemon);
    return true;
}

bool Trainer::removeProfemon(std::string name){
    for (int i = 0; i < 3; i++) {
        if (team[i].getName() == name) {
            team[i] = Profemon();
            return true;
        }
    }

    for (auto toRemove = profedex.begin(); toRemove != profedex.end(); toRemove++) {
        if (toRemove->getName() == name) {
            profedex.erase(toRemove);
            return true;
        }
    }

    return false;
}

void Trainer::setTeamMember(int slot, std::string name){
    if (slot >= 0 && slot < 3) {
        for (Profemon& profemon : profedex) {
            if (profemon.getName() == name) {
                if (team[slot].getName() == "Undefined") {
                    team[slot] = profemon;
                } else {
                    std::swap(team[slot], profemon);
                }
                break;
            }
        }
    }
}

bool Trainer::chooseProfemon(int slot){
    if (slot >= 0 && slot < 3 && team[slot].getName() != "Undefined") {
            currentProfemon = &team[slot];
            return true;
        }
    return false;
}

Profemon Trainer::getCurrent(){
    return *currentProfemon;
}

void Trainer::printProfedex(){
    for (Profemon profemon : profedex) {
        profemon.printProfemon(false);
        std::cout << std::endl;
    }
}

void Trainer::printTeam(){
    for (Profemon profemon : team) {
        if (profemon.getName() != "Undefined") {
            profemon.printProfemon(true);
            std::cout << std::endl;
        }
    }
}