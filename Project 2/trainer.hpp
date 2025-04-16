//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 07-24-2023
//Program Description: header file for trainer class

#ifndef TRAINER
#define TRAINER

#include<vector>
#include<string>

#include "profemon.hpp"

class Trainer{
    protected:
        std::vector<Profemon> profedex;
        Profemon team[3];
        Profemon* currentProfemon;
    public:
        Trainer();
        Trainer(std::vector<Profemon> profemons);
        bool contains(std::string name);
        bool addProfemon(Profemon profemon);
        bool removeProfemon(std::string name);
        void setTeamMember(int slot, std::string name);
        bool chooseProfemon(int slot);
        Profemon getCurrent();
        void printProfedex();
        void printTeam();
};

#endif