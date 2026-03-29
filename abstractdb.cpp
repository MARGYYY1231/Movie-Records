/**
 * abstractdb.cpp
 * C++ source file that should contain implementation for member functions
 * - loadCSV()
 * - saveCSV()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Tasks 4 and 5)
 */ 

#ifndef __ABSTRACT_DB_CPP__
#define __ABSTRACT_DB_CPP__
#include "abstractdb.hpp"
#include "vectordb.hpp"
#include <fstream>
#include <vector>
#include <regex>
#include <sstream>
#include <string>
#include <cstring>

/*
*saveCV writes all records in the table into given file name
*@param name Name of the file
*/
bool nwen::AbstractDbTable::saveCSV(std::string name)
{
    ofstream fsOut;
    fsOut.open(name, ios::out);
    if(!fsOut.is_open())
        return false;

    for(int i = 0; i<rows(); i++){
        const movie* m= get(i);
        fsOut << m->id<<","<< "\""<<m->title<<"\""<<","<< m->year<<","<< "\""<< m->director <<"\"\n";
        if(fsOut.bad()){return false;}
    }

    fsOut.close();
    return true;
}

/*
*loadCSV reads a file and if line has the correct structure
*if it is then adds movie to the table
*@param name Name of the file
*/
bool nwen::AbstractDbTable::loadCSV(std::string name)
{
    ifstream infn;
    infn.open(name, ios::in);
    string line;
    string id;
    string title;
    string year;
    string director;

    std::regex re("\\d+,\\w+[\\s\\w+]*,\\d+,\\w+[\\s\\w]*");

    if(!infn.is_open())
        return false;
    
    getline(infn,line);

    if(!std::regex_match(line, re))
        return false;

    stringstream X(line);
    getline(X, id,',');
    getline(X, title,',');
    getline(X, year,',');
    getline(X, director,',');

    movie m1;
    movie *m = &m1;
    m->id = stoi(id);
    strcpy(m -> title, title.c_str());
    m->year = stoi(year);
    strcpy(m -> director, director.c_str());
    add(*m);


    while(getline(infn,line)){
        if(!std::regex_match(line, re))
            return false;

        stringstream X(line);
        getline(X, id,',');
        getline(X, title,',');
        getline(X, year,',');
        getline(X, director,',');

        movie m1;
        movie *m = &m1;
        m->id = stoi(id);
        strcpy(m -> title, title.c_str());
        m->year = stoi(year);
        strcpy(m -> director, director.c_str());
        add(*m);
    }
    infn.close();
    return true;
}

#endif