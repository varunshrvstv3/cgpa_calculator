#include "cgpa.h"

void printHeader(const std::string &header) {
    std::cout << std::setw(50) << std::setfill('-') << "\n";
    std::cout << std::setw((50 + header.length()) / 2) << std::setfill(' ') << header << "\n";
    std::cout << std::setw(50) << std::setfill('-') << "\n\n";
}

float inputValidation(const std::string &prompt) {
    float input;
    if (!prompt.empty())
        std::cout << prompt << " ";
    while(!(std::cin >> input) || input < 0) {
        std::cout << "Invalid input. Please enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

void exitApplication() {
    clearScreen();
    std::cout << "Thank you for using GPA and CGPA calculator." << std::endl;
}

void displayMethod() {
    clearScreen();
    printHeader("Calculation Method");
    std::cout << "GPA is calculated as the sum of (credit hours * grade points) for all subjects, divided by the total credit hours." << std::endl;
    std::cout << "CGPA is the average of GPA calculated across all semesters." << std::endl;
}

void calculateGPA() {
    clearScreen();
    printHeader("GPA Calculator");

    int numSubjects = static_cast<int>(inputValidation("Enter the number of subjects: "));
    std::vector<float> credits(numSubjects), grades(numSubjects);

    float totalCredits = 0, weightedSum = 0;

    for (int i=0; i<numSubjects; i++) {
        std::stringstream ss;
        ss << "Enter credit for the subject " << i+1 << ": ";
        credits[i] = inputValidation(ss.str());

        ss.str("");
        ss.clear();

        ss << "Enter grade for the subject " << i+1 << ": ";
        grades[i] = inputValidation(ss.str());
        
        weightedSum += credits[i] * grades[i];
        totalCredits += credits[i];
    }

    std::cout << "Your GPA is: "<< std::setprecision(2) << std::fixed << weightedSum / totalCredits << std::endl;

}

void clearScreen() {
    system("clear");
}