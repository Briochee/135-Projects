//Name: Rio Simpson
//Email: Simpson.Rions@gmail.com
//Date: 07-24-2023
//Program Description: project 2 task B -- department

#include<vector>
#include "department.hpp"

// MLDepartment constructor
MLDepartment::MLDepartment(std::vector<Profemon> profemons) : Trainer() {
    for (Profemon profemon : profemons) {
        if (profemon.getSpecialty() == Specialty::ML) {
            addProfemon(profemon);
        }
    }
}

// MLDepartment addProfemon function
bool MLDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() == Specialty::ML) {
        return Trainer::addProfemon(profemon);
    }
    return false;
}

// SoftwareDepartment constructor
SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons) : Trainer() {
    for (Profemon profemon : profemons) {
        if (profemon.getSpecialty() == Specialty::SOFTWARE) {
            addProfemon(profemon);
        }
    }
}

// SoftwareDepartment addProfemon function
bool SoftwareDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() == Specialty::SOFTWARE) {
        return Trainer::addProfemon(profemon);
    }
    return false;
}

// HardwareDepartment constructor
HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons) : Trainer() {
    for (Profemon profemon : profemons) {
        if (profemon.getSpecialty() == Specialty::HARDWARE) {
            addProfemon(profemon);
        }
    }
}

// HardwareDepartment addProfemon function
bool HardwareDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() == Specialty::HARDWARE) {
        return Trainer::addProfemon(profemon);
    }
    return false;
}
