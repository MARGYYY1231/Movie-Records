# Movie Records Database Project — C++
## Overview

This project is a C++-based movie records database system developed as part of a university assignment. It simulates a database table using object-oriented programming concepts such as abstract classes, vectors, and structures.

The application supports full CRUD operations and allows importing and exporting movie data using CSV files.

## Features
Create, Read, Update, and Delete (CRUD) movie records
Vector-based data storage using C++ STL
Abstract class design for extensibility
CSV import/export using file I/O
Input validation and error handling
Modular and maintainable code structure
Unit-style test files for validation
## Project Structure
.
├── abstractdb.hpp    // Abstract base class definition
├── abstractdb.cpp    // Base class implementation
├── vectordb.hpp      // Derived class using vector storage
├── vectordb.cpp      // Vector database implementation
├── t3test.cpp        // Test file 3
├── t4test.cpp        // Test file 4
├── t5test.cpp        // Test file 5

## Requirements
C++ compiler (e.g., g++, clang++)
Terminal / command line
## How to Compile and Run
▶️ Compile main database files
g++ abstractdb.cpp vectordb.cpp -o moviedb
▶️ Run the program
./moviedb

## Running Test Files
Each test file can be compiled and run individually:

### Test 3
g++ t3test.cpp vectordb.cpp -o t3test
./t3test
### Test 4
g++ t4test.cpp vectordb.cpp -o t4test
./t4test
### Test 5
g++ t5test.cpp vectordb.cpp -o t5test
./t5test

## CSV Functionality
Import movie records from CSV files
Export database contents to CSV
Ensure correct format (e.g., title, year, genre, rating)

## Concepts Demonstrated
Object-Oriented Programming (OOP)
Abstract classes and inheritance
Data structures (vectors, structs)
File handling in C++
Error handling and validation
Basic testing practices

## Project Status
Completed as part of university coursework.

## Author
Margaret Nieves Gonzales
