//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 07-24-2023
//Program Description: project 2 task A -- skill

#include<iostream>
#include<string>

#include "skill.hpp"
using namespace std;

Skill::Skill(){
    name = "Undefined";
    description = "Undefined";
    totalUses = -1;
    specialty = -1;
}

Skill::Skill(std::string name, std::string description, int specialty, int uses){
    this->name = name;
    this->description = description;
    this->specialty = specialty;
    this->totalUses = uses;
}

std::string Skill::getName() {
    return name;
}

std::string Skill::getDescription(){
    return description;
}

int Skill::getTotalUses(){
    return totalUses;
}

int Skill::getSpecialty(){
    return specialty;
}

void Skill::setName(std::string name){
    this->name = name;
}

void Skill::setDescription(std::string description){
    this->description = description;
}

void Skill::setTotalUses(int uses){
    this->totalUses = uses;
}

bool Skill::setSpecialty(int specialty){
    if (specialty >= 0 && specialty <= 2){
        this->specialty = specialty;
        return true;
    }
    return false;
}