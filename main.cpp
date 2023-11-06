#include <iostream>
#include "SudokuSolver.hpp"

int main(){
    SudokuSolver a("puzzle2.csv");
    a.display();
    std::cout << a.isPuzzleSolvable();
}