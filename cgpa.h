#include <iostream>
#include <iomanip>
#include <limits>
#include <stdlib.h>
#include <vector>

#ifndef CGPA_H
#define CGPA_H

float inputValidation(const std::string &prompt);
void printHeader(const std::string &header);
void exitApplication();
void displayMethod();
void clearScreen();
void calculateGPA();

#endif