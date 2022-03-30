//
// Created by rivka on 20/03/2022.
//

#include "Notebook.hpp"
#include "Direction.hpp"
#include <stdexcept>


const int MAX =100;
using namespace std;

namespace ariel {
    //The function gets a position (page, row and column), direction (horizontal or vertical), and a string that represents what needs to be written, and writes the string in a notebook in the appropriate place
    void Notebook::write(int page, int row, int column, Direction direction, string const &str) {
        int size = str.length();
        if (direction == Direction::Horizontal) {
            if ((column + size) >= MAX) {
                throw std::out_of_range{"wrong value"};
            }
        }
        if (column >= MAX) {
            throw std::out_of_range{"wrong value"};
        }
        if (str=="\n"){
            throw std::out_of_range{"wrong value"};
        }
        if (column < 0) {
            throw std::out_of_range{"wrong value"};
        }
        if (row < 0) {
            throw std::out_of_range{"wrong value"};
        }
        if (page < 0) {
            throw std::out_of_range{"wrong value"};
        }
        for (unsigned long  i=0;i < str.length();i++) {
            if (str[i]== '~') {
                throw std::out_of_range{"wrong value"};
            }
            if (str[i] > '~'){
                throw std::out_of_range{"wrong value"};
            }
            if (str[i] < ' '){
                throw std::out_of_range{"wrong value"};
            }
        }


        Notebook::notebook[page].add(row, column, str, direction);
    }

//The function gets position (page, row and column), direction (horizontal or vertical), and number of characters, reads what is written in the notebook at the given position and length, and returns a string.
    string Notebook::read(int pag, int row, int column, Direction direction, int length) {
        if (direction ==Direction::Horizontal ) {
            if ((column + length) > MAX) {
                throw std::out_of_range{"wrong value"};
            }

        }
        if (column >= MAX) {
            throw std::out_of_range{"wrong value"};
        }
        if (column < 0) {
            throw std::out_of_range{"wrong value"};
        }
        if (length < 0) {
            throw std::out_of_range{"wrong value"};
        }
        if (row < 0) {
            throw std::out_of_range{"wrong value"};
        }
        if (pag < 0) {
            throw std::out_of_range{"wrong value"};
        }
        string s = Notebook::notebook[pag].get(row,column,length,direction);
        return s;
    }
//The function gets position (page, row and column), direction (horizontal or vertical), and number of characters, and deletes what is written in the relevant position and direction. Since we are writing with a pen, the function will not be deleted but "scribbled" in the appropriate places. (Place the characters in the character ~)
    void Notebook::erase(int page, int row, int column, Direction direction, int length) {

        if (direction == Direction::Horizontal) {
            if ((column + length) >= MAX) {
                throw std::out_of_range{"wrong value"};
            }

        }
        if (column >= MAX) {
            throw std::out_of_range{"wrong value"};
        }

        if (column < 0) {
            throw std::out_of_range{"wrong value"};
        }
        if (length < 0) {
            throw std::out_of_range{"wrong value"};
        }
        if (row < 0) {
            throw std::out_of_range{"wrong value"};
        }
        if (page < 0) {
            throw std::out_of_range{"wrong value"};
        }

        string s;
        for (int i = 0; i < length; i++) {
            s+='~';
        }
        Notebook::notebook[page].add(row, column, s, direction);
    }
//The function receives a page number and displays it in a convenient way for writing, in any format of your choice
    void Notebook::show(int page) {
        if (page < 0) {
            throw std::out_of_range{"wrong value"};
        }
        Notebook::notebook[page].show();
    }

};