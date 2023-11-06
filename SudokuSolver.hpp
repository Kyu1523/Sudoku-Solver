/*
Name:Kenny Yu 
Date:5/2/23
Description: This is the interface of SudokuSolver
*/

#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>

//We define Location within the Sudoku namespace.
//To use Location, you must specify the namespace Sudoku::Location
//Just like you do when using the standard namespace std::
namespace Sudoku
{ 
  struct Location
  {
    int row;
    int col;
  };
}

class SudokuSolver
{
public:
//Add your public members here
/** 
 @post: constructor that creates a sudoku puzzle that is empty
*/
SudokuSolver();
/**
 @param: A string of the csv file that is read
 @post: reads a csv file of a sudoku puzzle and solves it
*/
SudokuSolver(std::string input_file);

/**
 @post: Destructor for sudokusolver
*/
~SudokuSolver();

/**
 @return: returns whether the puzzle is solvable or not
 */
bool isPuzzleSolvable();

/**
 @post: Sets the value of is_solvable to true
*/
void setSolvable();
/**
 @post: returns the 2d pointer array
*/
int** getPuzzleNumbers();

/**
 @post: Sets the 2d array to the pointer 
*/
void setPuzzleNumbers(int** puzzle);

/**
 @post:Returns the location of the next empty slot
*/
Sudoku::Location returnNextEmpty();

/**
 @param: Integar of the value that is being checked to add into the puzzle
 @param: The coordinates of the slot
 @return: Returns true if the value can be added at the coordinate
*/
bool checkLegalValue(int value, Sudoku::Location location);

/**
 @post: Displays the board
*/
void display();

/**
 * @param:The puzzle that is being solved
 * @param:The coordination of the location being checked
 * @return: True if the sudoku puzzle is solvable
 */

bool solve(int* puzzle[9],Sudoku::Location cord);
private:
//Add your private members here
bool is_solvable = false;
int** puzzle;

};

#endif
