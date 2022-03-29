//
// Created by rivka on 22/03/2022.
//

#ifndef NOTEBOOK_A_PAGE_HPP
#define NOTEBOOK_A_PAGE_HPP

#include <string>
#include <unordered_map>
#include "Direction.hpp"

using namespace std;
using namespace ariel;

class Page {
private:
    unordered_map<int,char[100]> page;
public:
    void add(int row,int col, string str, Direction direction);
    string get(int row,int col, int len ,Direction direction);
    void show();


};
#endif //NOTEBOOK_A_PAGE_HPP
