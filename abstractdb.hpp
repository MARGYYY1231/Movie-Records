/**
 * abstractdb.hpp
 * C++ header file that should contain declaration for
 * - struct movie (given)
 * - AbstractDbTable abstract class
 * 
 * You need to modify this file to declare AbstractDbTable abstract class 
 * as specified in the hand-out (Task 1)
 */ 



#ifndef __ABSTRACT_DB_HPP__
#define __ABSTRACT_DB_HPP__

#include <string>

using namespace std;

/*
*namespace nwen contains the movie structure and abstract class AbstractDbTable
*class VectorDbTable will be implemented in another file but declared here
*so that can be a part of the nwen namespace
*/
namespace nwen 
{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };

    class VectorDbTable;

    class AbstractDbTable{
        public:
            virtual int rows() const = 0;
            virtual const movie* get(int i) const = 0;
            virtual bool add(movie m) = 0;
            virtual bool update(unsigned long u, movie m) = 0;
            virtual bool remove(unsigned long u) = 0;
            bool loadCSV(string str);
            bool saveCSV(string str);
    };
}

#endif /* __ABSTRACT_DB_HPP__ */