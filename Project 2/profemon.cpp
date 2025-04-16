//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 07-24-2023
//Program Description: project 2 task A -- profemon

#include<iostream>
#include<string>

#include "profemon.hpp"
using namespace std;

Profemon::Profemon() {
    name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialiy){
    this->name = name;
    this->maxHealth = max_health;
    this->specialty = specialiy;
    requiredExp = 50;
    currentExp = 0;
    level = 0;
    for (int i = 0; i < 3; i++){
        skills[i] = Skill();
    }
}

std::string Profemon::getName(){
    return name;
}

Specialty Profemon::getSpecialty(){
    return specialty;
}

int Profemon::getLevel(){
    return level;
}

double Profemon::getMaxHealth(){
    return maxHealth;
}

void Profemon::setName(std::string name){
    this->name = name;
}

// void Profemon::levelUp(int exp){
//     if(specialty == 0){
//         if(exp >= requiredExp){
//             level++;
//             exp -= requiredExp;
//             requiredExp += 10;
//             currentExp = exp;
//             levelUp(exp);
//         }
//     } else if (specialty == 1){
//         if(exp >= requiredExp){
//             level++;
//             exp -= requiredExp;
//             requiredExp += 15;
//             currentExp = exp;
//             levelUp(exp);
//         }
//     } else if (specialty == 2){
//         if(exp >= requiredExp){
//             level++;
//             exp -= requiredExp;
//             requiredExp += 20;
//             currentExp = exp;
//             levelUp(exp);
//         }
//     }
// }

void Profemon::levelUp(int exp) {
    currentExp += exp;

    while (currentExp >= requiredExp) {
        level++;
        currentExp -= requiredExp;

        if (specialty == 0) {
            requiredExp += 10;
        } else if (specialty == 1) {
            requiredExp += 15;
        } else if (specialty == 2) {
            requiredExp += 20;
        }
    }
}

bool Profemon::learnSkill(int slot, Skill skill){
    if (slot >=0  && slot < 3 && skill.getSpecialty() == specialty){
        skills[slot] = skill;
        return true;
    }
    return false;
}

void Profemon::printProfemon(bool print_skills){
    std::string specialtyStr[3] = {"ML", "SOFTWARE", "HARDWARE"};
    std::cout << name << " [" <<
            specialtyStr[specialty] << "] | lvl " << level
                << " | exp " << currentExp << "/" << requiredExp 
                    << " | hp " << maxHealth << std::endl;
    if(print_skills == true){ 
        for (int i = 0; i < 3; i++){
            if(skills[i].getName() != "Undefined"){
                std::cout << "    " << skills[i].getName() << " ["
                    << skills[i].getTotalUses() << "] : " << skills[i].getDescription()
                        << std::endl;
            }
        }
    }
}