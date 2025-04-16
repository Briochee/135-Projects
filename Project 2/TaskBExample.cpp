#include <iostream>
#include "trainer.hpp"
#include "department.hpp"

int main() {
    // Creating some profémons
    Profemon profemon1("Charmander", 100, Specialty::ML);
    Profemon profemon2("Bulbasaur", 120, Specialty::SOFTWARE);
    Profemon profemon3("Squirtle", 90, Specialty::HARDWARE);
    Profemon profemon4("Pikachu", 80, Specialty::ML);

    // Creating a vector of profémons
    std::vector<Profemon> profemons;
    profemons.push_back(profemon1);
    profemons.push_back(profemon2);
    profemons.push_back(profemon3);
    profemons.push_back(profemon4);

    // Creating a trainer with the profémons
    Trainer trainer(profemons);

    std::cout << "Initial Team:" << std::endl;
    trainer.printTeam();
    std::cout << std::endl;

    // Testing Trainer's addProfemon function
    Profemon newProfemon("Jigglypuff", 150, Specialty::ML);
    if (trainer.addProfemon(newProfemon)) {
        std::cout << "Jigglypuff added successfully!" << std::endl;
    } else {
        std::cout << "Failed to add Jigglypuff!" << std::endl;
    }

    // Testing Trainer's contains function
    if (trainer.contains("Charmander")) {
        std::cout << "Trainer has Charmander in their team or profédex!" << std::endl;
    } else {
        std::cout << "Trainer does not have Charmander in their team or profédex!" << std::endl;
    }

    // Creating different departments
    MLDepartment mlDepartment(profemons);
    SoftwareDepartment softwareDepartment(profemons);
    HardwareDepartment hardwareDepartment(profemons);

    // Adding new profémon to departments
    if (mlDepartment.addProfemon(newProfemon)) {
        std::cout << "Jigglypuff added to MLDepartment successfully!" << std::endl;
    } else {
        std::cout << "Failed to add Jigglypuff to MLDepartment!" << std::endl;
    }

    // Printing profédex of each department
    std::cout << "ML Department Profédex:" << std::endl;
    mlDepartment.printProfedex();
    std::cout << std::endl;

    std::cout << "Software Department Profédex:" << std::endl;
    softwareDepartment.printProfedex();
    std::cout << std::endl;

    std::cout << "Hardware Department Profédex:" << std::endl;
    hardwareDepartment.printProfedex();
    std::cout << std::endl;

    return 0;
}
