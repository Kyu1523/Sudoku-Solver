/*
Name:Kenny Yu
Date:5/2/23
Description: This the implemetation of SudokuSolver
*/

#include "SudokuSolver.hpp"

/** 
 @post: constructor that creates a sudoku puzzle that is empty
*/
SudokuSolver::SudokuSolver(){
    puzzle = new int*[9];
    for(int i = 0 ; i < 9 ; i++){
        puzzle[i] = new int[9];
    }
    for(int i = 0 ; i < 9;i++){
        for(int j = 0; j < 9; j++){
            puzzle[i][j] = 0;
        }
    }
}
/**
 @param: A string of the csv file that is read
 @post: reads a csv file of a sudoku puzzle and solves it
*/
SudokuSolver::SudokuSolver(std::string input_file){
    std::ifstream file(input_file);
    bool not_solved = true;
    bool has_legal_value = true;
    bool has_backtrack_value = false;
    std::string temp_string;
    std::string temp_line;
    std::string line;
    puzzle = new int*[9];
    for(int i = 0 ; i < 9 ; i++){
        puzzle[i] = new int[9];
    }
    for(int i = 0; i < 9; i++){
        std::getline(file,line);
        std::istringstream temp_line(line);
        for(int j = 0; j < 9; j++){
            getline(temp_line,temp_string,',');
            puzzle[i][j] = stoi(temp_string);
        }
    }
    Sudoku::Location cord;
    cord.row = 0;
    cord.col = 0;
    solve(puzzle,cord);
}

/**
 @post: Destructor for sudokusolver
*/

SudokuSolver::~SudokuSolver(){
    delete[] puzzle;
    puzzle = nullptr;
}

/**
 @return: returns whether the puzzle is solvable or not
 */
bool SudokuSolver::isPuzzleSolvable(){
    return is_solvable;
}

/**
 @post: Sets the value of is_solvable to true
*/
void SudokuSolver::setSolvable(){
    is_solvable = true;
}
/**
 @post: returns the 2d pointer array
*/
int** SudokuSolver::getPuzzleNumbers(){
    return puzzle;
}

/**
 @post: Sets the 2d array to the pointer 
*/
void SudokuSolver::setPuzzleNumbers(int** pointer_to_array){
    pointer_to_array = puzzle;
}

/**
 @post:Returns the location of the next empty slot
*/
Sudoku::Location SudokuSolver::returnNextEmpty(){
    Sudoku::Location coordinates;
    coordinates.row = -1;
    coordinates.col = -1;
    for(int i = 0; i < 9 ; i++){
        for(int j = 0; j < 9; j++){
            if(0 == puzzle[i][j]){
                coordinates.row = i;
                coordinates.col = j;
                return coordinates;
            }
        }
    }
    return coordinates;
}

/**
 @param: Integar of the value that is being checked to add into the puzzle
 @param: The coordinates of the slot
 @return: Returns true if the value can be added at the coordinate
*/
bool SudokuSolver::checkLegalValue(int value, Sudoku::Location location){
    int row = location.row;
    int col = location.col;
    for(int i = 0; i < 9;i++){
        if(value == puzzle[i][col]){
            return false;
        }
        if(value == puzzle[row][i]){
            return false;
        }
    }
    int sub_array_row = row/3;
    int sub_array_col = col/3;
        if(sub_array_row == 0){
            if(sub_array_col == 0){
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(value == puzzle[i][j]){
                            return false;
                        }
                    }
                }
            }
            else if(sub_array_col == 1){
                for(int i = 0; i < 3; i++){
                    for(int j = 3; j < 6; j++){
                        if(value == puzzle[i][j]){
                            return false; 
                        }
                    }
                }
            }
            else if (sub_array_col == 2){
                for(int i = 0; i < 3; i++){
                    for(int j = 6; j < 9; j++){
                        if(value == puzzle[i][j]){
                            return false; 
                        }
                    }
                }
            }
        }
        else if (sub_array_row == 1){
            if(sub_array_col == 0){
                for(int i = 3; i < 6; i++){
                    for(int j = 0; j < 3; j++){
                        if(value == puzzle[i][j]){
                            return false;
                        }
                    }
                }
            }
            else if(sub_array_col == 1){
                for(int i = 3; i < 6; i++){
                    for(int j = 3; j < 6; j++){
                        if(value == puzzle[i][j]){
                            return false; 
                        }
                    }
                }
            }
            else if (sub_array_col == 2){
                for(int i = 3; i < 6; i++){
                    for(int j = 6; j < 9; j++){
                        if(value == puzzle[i][j]){
                            return false; 
                        }
                    }
                }
            }
        }
        else if(sub_array_row == 2){
            if(sub_array_col == 0){
                for(int i = 6; i < 9; i++){
                    for(int j = 0; j < 3; j++){
                        if(value == puzzle[i][j]){
                            return false;
                        }
                    }
                }
            }
            else if(sub_array_col == 1){
                for(int i = 6; i < 9; i++){
                    for(int j = 3; j < 6; j++){
                        if(value == puzzle[i][j]){
                            return false; 
                        }
                    }
                }
            }
            else if (sub_array_col == 2){
                for(int i = 6; i < 9; i++){
                    for(int j = 6; j < 9; j++){
                        if(value == puzzle[i][j]){
                            return false; 
                        }
                    }
                }
            }
        }
    return true;
}

/**
 @post: Displays the board
*/
void SudokuSolver::display(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(puzzle[i][j] == 0){
                std::cout << "X ";
            }
            else{
                std::cout << puzzle[i][j] << " ";
            }
            if(j == 2 || j== 5){
                std::cout << " | ";
            }
        }
        if(i == 2 || i == 5){
            std::cout << std::endl;
            for(int x = 0; x < 12;x++){
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
    if(isPuzzleSolvable()){
        std::cout << "Here is the solved Puzzle" << std::endl;
    }
    else{
        std::cout << "Puzzle is not solvable" << std::endl;
    }
}

bool SudokuSolver::solve(int* puzzle[9], Sudoku::Location cord){
    if(returnNextEmpty().row == -1){
        setSolvable();
        return true;
    }
    int row = cord.row;
    int col = cord.col;
    for(int i = 1; i <= 9;i++){
        if(checkLegalValue(i,returnNextEmpty())){
            puzzle[row][col] = i;
            if(solve(puzzle,returnNextEmpty())){
                return true;
            }
        }
        puzzle[row][col] = 0;
    }
    return false;
}
