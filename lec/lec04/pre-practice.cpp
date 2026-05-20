#include <iostream>
#include <fstream>
#include <string>
 
// ============================================================
//  EXERCISE 1 — std::cout
//
//  Task: Print the following to the console:
//    Line 1: "Hello, Streams!"
//    Line 2: The number 42
//    Line 3: The double 3.14
//
//  Expected output:
//    Hello, Streams!
//    42
//    3.14
// ============================================================
void exercise1_cout() {
    std::cout << "=== Exercise 1: cout ===\n";

    std::cout << "Hello, Sreams" << std::endl;
    std::cout << 42 << std::endl;
    std::cout <<  3.14 << std::endl;

    std::cout << "\n";
}
 
 
// ============================================================
//  EXERCISE 2 — std::cin
//
//  Task: Ask the user for their name and favourite number,
//        then print:
//          "Hello [name], your favourite number is [number]!"
//
//  Example:
//    Enter your name: Alice
//    Enter your favourite number: 7
//    Hello Alice, your favorite number is 7!
//
//  Note: For this exercise, assume the name is a single word
// ============================================================
void exercise2_cin() {
    std::cout << "=== Exercise 2: cin ===\n";
 
    std::string name;
    int number;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your favourite number: ";
    std::cin >> number;

    std::cout << "Hello " << name << ", your favourite number is " << number << "!" << std::endl; 
  
    std::cout << "\n";
}
 
 
// ============================================================
//  EXERCISE 3 — std::ofstream
//
//  Task: Create a file called "numbers.txt" and write
//        the numbers 1 through 5 to it, one per line.
//        Then print "File written!" to the console.
//
//  Expected file contents:
//    1
//    2
//    3
//    4
//    5
//
//  Requirements:
//    - Check the file opened successfully before writing
//    - If it fails, print "Error: could not open file" to std::cerr
// ============================================================
void exercise3_ofstream() {
    std::cout << "=== Exercise 3: ofstream ===\n";
 
    // YOUR CODE HERE
    std::ofstream ofile("numbers.txt");

    if (!ofile.is_open()) {
        std::cerr << "Error: could not open file\n";
        return;
    }

    for (int i = 0; i < 5; i++) {
        ofile << (i + 1) << "\n";
    }
 
    std::cout << "\n";
}
 
 
// ============================================================
//  EXERCISE 4 — std::ifstream
//
//  Task: Read back the "numbers.txt" file from Exercise 3
//        and print each number to the console in the format:
//          "Number: 1"
//          "Number: 2"
//          ... and so on
//
//  Requirements:
//    - Check the file opened successfully
//    - Use a while loop to read until end of file
// ============================================================
void exercise4_ifstream() {
    std::cout << "=== Exercise 4: ifstream ===\n";

    std::ifstream ifile("numbers.txt");

    if (!ifile.is_open()) {
        std::cerr << "Error: could not open file\n";
        return;
    }

    int number;

    while (ifile >> number) {
        std::cout << "Number: " << number << "\n";
    }

    std::cout << "\n";
}
 
 
// ============================================================
//  EXERCISE 5 — Stretch goal
//
//  Task:
//    1. Ask the user to enter 3 numbers via cin
//    2. Write them to a file called "user_numbers.txt"
//    3. Read the file back and print each number
//    4. Append the number 99 to the file
//       without overwriting the existing numbers
//    5. Read and print the whole file one more time to confirm
//
//  Hint: For step 4, look up std::ios::app
// ============================================================
void exercise5_combined() {
    std::cout << "=== Exercise 5: Combined ===\n";
 
    std::cout << "Enter 3 numbers: ";
    int number1, number2, number3;
    std::cin >> number1;
    std::cin >> number2;
    std::cin >> number3;

    std::ofstream ofile("user_numbers.txt");

    if (!ofile.is_open()) {
        std::cerr << "Fail to open file\n";
        return;
    }

    ofile << number1 << "\n" << number2 << "\n" << number3 << "\n"; 

    ofile.close();

    std::ifstream ifile("user_numbers.txt");

    if (!ifile.is_open()) {
        std::cerr << "Faile to read file\n";
        return;
    }

    int num;

    while (ifile >> num) {
        std::cout << num << "\n";
    }
    
    ifile.close();

    std::ofstream appfile("user_numbers.txt", std::ios::app);
    
    if (!appfile.is_open()) {
        std::cerr << "Faile to open append file\n";
        return;
    }

    appfile << 99;
    appfile.close();

    std::ifstream newifile("user_numbers.txt");

    if (!newifile.is_open()) {
        std::cerr << "Faile to open new in file\n";
        return;
    }

    while (newifile >> num) {
        std::cout << num << "\n";
    }


 
    std::cout << "\n";
}
 

int main() {
    exercise1_cout();
    exercise2_cin();
    exercise3_ofstream();
    exercise4_ifstream();
    exercise5_combined();
 
    return 0;
}