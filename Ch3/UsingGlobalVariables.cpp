#include <iostream>

// Initialize three global integers
int firstNumber = 0;
int secondNumber = 0;
int multiplicationResult = 0;

void multiplyNumbers() {
   // Get inputs
   std::cout << "Enter the first number: ";
   std::cin >> firstNumber;

   std::cout << "Enter the second number: ";
   std::cin >> secondNumber;

   // Process inputs
   multiplicationResult = firstNumber*secondNumber;

   // Display results
   std::cout << "Displaying results from multiplyNumbers(): ";
   std::cout << firstNumber << " x " << secondNumber << " = ";
   std::cout << multiplicationResult << std::endl;

   return;
}

int main(int argc, char const *argv[])
{
   std::cout << "This program will help you multiply two numbers." << std::endl;

   multiplyNumbers();

   // Diplaying results as global variables from main()
   std::cout << "Displaying from main(): ";
   std::cout << firstNumber << " x " << secondNumber << " = ";
   std::cout << multiplicationResult << std::endl;
}
