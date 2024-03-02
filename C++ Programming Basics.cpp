#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function to calculate the updated salary
double calculateUpdatedSalary(double currentSalary, double percentIncrease) {
    return currentSalary * (1 + percentIncrease / 100);
}

int main() {
    // Open the input file
    ifstream inputFile("SalaryData.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Open the output file
    ofstream outputFile("SalaryOut.txt");

    if (!outputFile) {
        cerr << "Error: Unable to create output file." << endl;
        return 1;
    }

    string firstName, lastName;
    double currentSalary, percentIncrease;

    // Read data from the input file and process it
    while (inputFile >> lastName >> firstName >> currentSalary >> percentIncrease) {
        // Calculate the updated salary
        double updatedSalary = calculateUpdatedSalary(currentSalary, percentIncrease);

        // Write the output to the output file
        outputFile << fixed << setprecision(2) << firstName << " " << lastName << " " << updatedSalary << endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Salary information has been updated and saved to SalaryOut.txt" << endl;

    return 0;
}   