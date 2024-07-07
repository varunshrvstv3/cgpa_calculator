#include "cgpa.h"

int main() {
    while(true) {
        clearScreen();
        printHeader("CGPA Calculator");

        std::cout << "1. Calculate GPA" << std::endl;
        std::cout << "2. Calculate CGPA" << std::endl;
        std::cout << "3. How GPA and CGPA are calculated" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice = static_cast<int> (inputValidation("Enter Your Choice: "));

        switch(choice) {
            case 1:
                calculateGPA();
                break;
            case 2:
                break;
            case 4:
                exitApplication();
                return 0;
                break;
            case 3:
                displayMethod();
                break;
            default:
                std::cout << "Invalid choice! Please enter from number 1-4" << std::endl;
                break;

        }
        std::cout << "Please press enter to continue ... ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}
