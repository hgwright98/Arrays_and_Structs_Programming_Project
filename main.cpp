#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int Number_of_Runners = 5; // This establishes the constant for the number of runners
const int Number_of_Days = 7;     // This establishes the constant for the number of days in a week

// This function will read the data from the file and store it in the array
void readData(string names[], int miles[][Number_of_Days]) 
    {
        ifstream inputFile("runners.txt"); // This open's the input file
        if (!inputFile) { // This checks if the file opens correctly and if it doesnt an error message is displayed
            cout << "Error opening file." << endl; 
            return;
    }

    // This reads names and miles data from the file and stores them in the arrays
    for (int i = 0; i < Number_of_Runners; ++i) 
        {
            inputFile >> names[i];
            for (int j = 0; j < Number_of_Days; ++j) 
                {
                    inputFile >> miles[i][j]; 
                }
        }

    inputFile.close(); // This closes the file when done
    }

// This function calculates the total miles run by each runner and the average miles per day
void calculateTotalsAndAverages(const int miles[][Number_of_Days], int totals[], double averages[]) {
    for (int i = 0; i < Number_of_Runners; ++i) {
        totals[i] = 0; // Initialize the total miles for the runner
        for (int j = 0; j < Number_of_Days; ++j) {
            totals[i] += miles[i][j]; // Add up miles for the total
        }
        averages[i] = static_cast<double>(totals[i]) / Number_of_Days; // Calculate average miles per day
    }
}

// This function displays the results in a table format
void outputResults(const string names[], const int miles[][Number_of_Days], const int totals[], const double averages[]) 
    {
        cout << setw(14) << left << "Runner Name"; // This is the header for runner names
        for (int j = 1; j <= Number_of_Days; ++j) 
            {
                cout << setw(10) << left << "Day " + to_string(j); // This is the headers for each day
            }
        cout << setw(14) << left << "Total Miles" << setw(10) << right << "Avg Miles" << endl; // This is the headers for totals and averages
        cout << "------------------------------------------------------------------------------------------------------------" << endl; 
        for (int i = 0; i < Number_of_Runners; ++i) // This for statement will display the data in a table format
            {
                cout << setw(15) << left << names[i]; // This outputs the runner's name.
                for (int j = 0; j < Number_of_Days; ++j) 
                    {
                        cout << setw(10) << miles[i][j]; // This outputs the miles run for each day
                    }
                cout << setw(6) << right << totals[i] << setw(15) << fixed << setprecision(2) << averages[i] << endl; // This outputs total and average miles
            }
    }

// Main function to run the program
int main() 
    {
        string names[Number_of_Runners]; // This array storea runner names
        int miles[Number_of_Runners][Number_of_Days]; // This array stores miles run by each runner each day
        int totals[Number_of_Runners]; // This array stores total miles run by each runner
        double averages[Number_of_Runners]; // This array stores average miles run per day by each runner

        readData(names, miles); // This calls the function to read data
        calculateTotalsAndAverages(miles, totals, averages); // This calls the function to calculate totals and averages
        outputResults(names, miles, totals, averages); // This calls the function to output results

        return 0; // This ends the program
    }