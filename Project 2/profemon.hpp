//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 07-24-2023
//Program Description: header file for profemon class

#ifndef PROFEMON_HPP
#define PROFEMON_HPP

//header files
#include "skill.hpp"

#include<string>
using namespace std;

enum Specialty{
    ML,
    SOFTWARE,
    HARDWARE};

class Profemon{
    private:
        std::string name;
        int level;
        int requiredExp;
        int currentExp;
        double maxHealth;
        Specialty specialty;
        Skill skills[3];
    public:
        //constructor
        Profemon();
        Profemon(std::string name, double max_health, Specialty specialty);
        
        //accessors
        std::string getName();
        Specialty getSpecialty();
        int getLevel();
        double getMaxHealth();
        void printProfemon(bool print_skills);

        //mutators
        void setName(std::string name);
        void levelUp(int exp);
        bool learnSkill(int slot, Skill skill);

};

#endif