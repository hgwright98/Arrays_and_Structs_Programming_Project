#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int Number_of_Runners = 5; // This establishes the constant for the number of runners
const int Number_of_Days = 7;     // This establishes the constant for the number of days in a week

// The establishes a struct to hold runner data
struct Runner 
    {
        string name;                     // Name of the runner
        int miles[Number_of_Days];       // Miles run each day
        int totalMiles;                  // Total miles for the week
        double averageMiles;             // Average miles per day
    };

// This function will read the data from the file and store it in the array of structs
void readData(Runner runners[]) 
    {
        ifstream inputFile("runners.txt"); // This opens the input file
        if (!inputFile) // This checks if the file opens correctly
            { 
                cout << "Error opening file." << endl; 
                return;
            }

        // This reads names and miles data from the file and stores them in the struct array
        for (int i = 0; i < Number_of_Runners; ++i)    
            {
                inputFile >> runners[i].name; // This stores the runner's name in the struct
                for (int j = 0; j < Number_of_Days; ++j) // This stores the miles for each day for the runners using the constant of Number_of_Days
                {
                    inputFile >> runners[i].miles[j]; 
                }
            }

        inputFile.close(); // This closes the file when done
    }

// This function calculates the total miles run by each runner and the average miles per day
void calculateTotalsAndAverages(Runner runners[]) 
    {
        for (int i = 0; i < Number_of_Runners; ++i) 
            {
                runners[i].totalMiles = 0; // This initializes the total miles for the runner
                for (int j = 0; j < Number_of_Days; ++j) 
                    {
                        runners[i].totalMiles += runners[i].miles[j]; // This adds up miles for the total
                    }
                runners[i].averageMiles = static_cast<double>(runners[i].totalMiles) / Number_of_Days; // This calculates the average miles per day
            }
    }

// This function displays the results in a table format
void outputResults(const Runner runners[]) 
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
                cout << setw(15) << left << runners[i].name; // This outputs the runner's name.
                for (int j = 0; j < Number_of_Days; ++j) 
                    {
                        cout << setw(10) << runners[i].miles[j]; // This outputs the miles run for each day
                    }
                cout << setw(6) << right << runners[i].totalMiles << setw(15) << fixed << setprecision(2) << runners[i].averageMiles << endl; // This outputs total and average miles
            }
    }

// Main function to run the program
int main() 
    {
        Runner runners[Number_of_Runners]; // This array stores runner data using the struct

        readData(runners); // This calls the function to read data
        calculateTotalsAndAverages(runners); // This calls the function to calculate totals and averages
        outputResults(runners); // This calls the function to output results

        return 0; // This ends the program
    }