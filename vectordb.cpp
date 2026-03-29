/**
 * vectordb.cpp
 * C++ source file that should contain implementation for member functions
 * - rows()
 * - get()
 * - add()
 * - update()
 * - remove()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Task 3)
 */ 
#ifndef __VECTOR_DB_CPP__
#define __VECTOR_DB_CPP__
#include "vectordb.hpp"
#include <cstring>

/*
*rows() says how many elements/rows there are in the vector of movies (table)
*@return int representing the number of rows
*/
int nwen::VectorDbTable::rows() const{
    return table.size();
}

/*
*gets movie at a certain index
*@param i Index to get from table
*@return pointer to the movie
*/
const nwen::movie* nwen::VectorDbTable::get(int i) const{
    if(table.size() <= i)
        return NULL;
    return table.data()+i;
}

/*
*Adds movie to the table of movies if it is not present
*@param m Movie to be added to table
*@return Boolean of if added to table of movies
*/
bool nwen::VectorDbTable::add(movie m){
    bool isElementPresent = false;
    for ( auto& element : table ) {
       if ( element.id == m.id ) {
          isElementPresent = true;
          break;
       }
    }

    if(isElementPresent == false)
        table.push_back(m);

    return !isElementPresent;
}

/*
*Updates a movie if id is present
*@param u ID of the movie to be updated
*@param m Movie to update
*@return boolean to indicate whether movie 
*info was updated
*/
bool nwen::VectorDbTable::update(unsigned long u, struct movie m){
    int index = -1;
    movie* pointer;
    for(int i = 0; i<table.size(); i++){
        if(table[i].id == u)
            index = i;
    }

    if(index == -1)
        return false;

    pointer = table.data()+index;

    pointer -> id = m.id;
    strcpy(pointer -> title , m.title);
    //pointer -> title = m.title;
    pointer -> year = m.year;
    strcpy(pointer -> director , m.director);

    return true;
}

/*
*Removes a movie from the table if table contains the ID
*@param u ID of he movie to be removed
*@return Boolean of if removed from table of movies
*/
bool nwen::VectorDbTable::remove(unsigned long u){
    int index = -1;
    for(int i = 0; i<table.size(); i++){
        if(table[i].id == u)
            index = i;
    }

    if(index == -1)
        return false;

    table.erase(table.begin()+index);
    return true;
}
#endif