//
// Created by rivka on 22/03/2022.

#include "Page.hpp"
#include <iostream>
#include <unordered_map>

const int MAX =100;
using namespace std;
using namespace ariel;
//The function writes into a page
void Page::add(int row, int col, string str, Direction direction) {
    int index = col;
    int rowi=row;
    for (unsigned long  i=0;i < str.length();i++){
        if ((page[rowi][index]!='\0')&&(str.at(i)!='~')){
            throw std::out_of_range{""};
        }
        if ((page[rowi][index]=='~')&&(str.at(i)!='~')){
            throw std::out_of_range{""};
        }
        if (direction == Direction::Vertical){
            rowi++;
        }
        else {
            index++;
        }
    }
    index=col;
    for (unsigned long i = 0; i < str.length(); i++) {
        if (str.at(i)==' '){
            page[row][index] = '_';
        }
        else if (str.at(i)=='_'){
            page[row][index] = '\0';
        }else{
            page[row][index] = str.at(i);

        }
        if (direction == Direction::Vertical){
            row++;
        }
        else {
            index++;
        }
    }
}
//The function gets position (row and column), direction (horizontal or vertical), and number of characters, reads what is written on the page at the given position and length, and returns a string.
string Page::get(int row, int col, int len, Direction direction) {
    string str;
    int index = col;
    for (int i = 0; i < len; i++) {
        if (page[row][index] == '\0') {
            str += '_';
        }
        else if (page[row][index] == '_') {
            str += ' ';
        }
        else{
            str+=page[row][index];
        }
        if (direction == Direction::Vertical){
            row++;
        }
        else {
            index++;
        }
    }
    return str;
}
//The function prints what is on the page
void Page::show() {
    int endRow = 0;
    for (auto iter = page.begin(); iter != page.end(); iter++){
        if (endRow<iter->first ){
            endRow = iter->first;
        }
}
      for (int i = 0; i < endRow; i++) {
        for (int j = 0; j < MAX; j++) {
            if (page[i][j]=='\0'){
                cout <<'_';
            }
            else{
                cout << page[i][j];
            }
        }
        cout<<endl;

    }

}








