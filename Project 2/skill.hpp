//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 07-24-2023
//Program Description: header file for skill class

#ifndef SKILL_HPP
#define SKILL_HPP

#include<string>
using namespace std;

class Skill{
    private:
        std::string name;
        std::string description;
        int totalUses;
        int specialty;
    public:
        //constructor
        Skill();
        Skill(std::string name, std::string description, int specialty, int uses);

        //accessors
        std::string getName();
        std::string getDescription();
        int getTotalUses();
        int getSpecialty();

        //mutators
        void setName(std::string name);
        void setDescription(std::string description);
        void setTotalUses(int uses);
        bool setSpecialty(int specialty);

};

#endif