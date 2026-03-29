/**
 * vectordb.hpp
 * C++ header file that should contain declaration for
 * - VectorDbTable class
 * 
 * You need to modify this file to declare VectorDbTable class 
 * as specified in the hand-out (Task 2)
 */ 
#ifndef __VECTOR_DB_HPP__
#define __VECTOR_DB_HPP__
#include <iostream>
#include <vector>
#include "abstractdb.hpp"

/*
*Vector table class is child class of AbstractDbTable
*Has declarations of every virtual function of abstract class
*Also has the vector which stores a vecctor of movies
*/
class nwen::VectorDbTable : public AbstractDbTable{
public:
    std::vector<movie> table;
    int rows() const;
    const movie* get(int i) const;
    bool add(movie m);
    bool update(unsigned long u, movie m);
    bool remove(unsigned long u);
};


//class VectorDbTable;

#endif