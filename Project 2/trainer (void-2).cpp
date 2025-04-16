//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 07-24-2023
//Program Description: project 2 task B -- trainer

//header files
#include "trainer.hpp"
#include <iostream>

Trainer::Trainer() {
    currentProfemon = nullptr;
}

Trainer::Trainer(std::vector<Profemon> profemons) {
    for (int i = 0; i < profemons.size(); i++) {
        if (team[0].getName() == "Undefined") {
            team[0] = profemons[i];
            currentProfemon = &team[0];
        } else if (team[1].getName() == "Undefined") {
            team[1] = profemons[i];
        } else if (team[2].getName() == "Undefined") {
            team[2] = profemons[i];
        } else {
            profedex.push_back(profemons[i]);
        }
    }
}

bool Trainer::contains(std::string name) {
    for (Profemon& p : team) {
        if (p.getName() == name) {
            return true;
        }
    }

    for (Profemon& p : profedex) {
        if (p.getName() == name) {
            return true;
        }
    }

    return false;
}

bool Trainer::addProfemon(Profemon profemon) {
    if (contains(profemon.getName())) {
        return false;
    }

    for (Profemon& p : team) {
        if (p.getName() == "Undefined") {
            p = profemon;
            currentProfemon = &p;
            return true;
        }
    }

    profedex.push_back(profemon);
    return true;
}

bool Trainer::removeProfemon(std::string name) {
    for (Profemon& p : team) {
        if (p.getName() == name) {
            p = Profemon();
            return true;
        }
    }

    for (auto it = profedex.begin(); it != profedex.end(); ++it) {
        if (it->getName() == name) {
            profedex.erase(it);
            return true;
        }
    }

    return false;
}

void Trainer::setTeamMember(int slot, std::string name) {
    if (slot >= 0 && slot < 3) {
        for (Profemon& p : profedex) {
            if (p.getName() == name) {
                if (team[slot].getName() == "Undefined") {
                    team[slot] = p;
                } else {
                    std::swap(team[slot], p);
                }
                break;
            }
        }
    }
}

bool Trainer::chooseProfemon(int slot) {
    if (slot >= 0 && slot < 3 && team[slot].getName() != "Undefined") {
        currentProfemon = &team[slot];
        return true;
    }
    return false;
}

Profemon Trainer::getCurrent() {
    if (currentProfemon != nullptr) {
        return *currentProfemon;
    }
    return Profemon();
}

void Trainer::printProfedex() {
    for (int i = 0; i < profedex.size(); i++) {
        profedex[i].printProfemon(false);
    }
}

void Trainer::printTeam() {
    for (int i = 0; i < 3; i++) {
        if (team[i].getName() != "Undefined") {
            team[i].printProfemon(true);
        }
    }
}