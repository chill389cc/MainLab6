#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

/*
 * Main Lab 6 - Hot plate
 *
 * Due Oct 27 (for full early extra-credit, normally due nov 2)
 *
 * https://learn.zybooks.com/zybook/BYUCS142Fall2021/chapter/6/section/33
 *
 * Pair programming information:
 *  Caleb Hill - cah34@byu.edu - Section 005
 *  Michael Norris - Section 005
 */

using namespace std;

//declare constants
const int ARRAY_SIZE = 10;
const int PRECISION_SIZE = 3;
const int WIDTH_SIZE = 9;
const double STEADY_STATE_MARGIN = 0.1;
const int TIMES_TO_RUN_INPUTPLATE = 3;

//Function prototypes
void Init2DArray(double[ARRAY_SIZE][ARRAY_SIZE]);
void PrintArray(double[ARRAY_SIZE][ARRAY_SIZE]);
void CopyArray(double[ARRAY_SIZE][ARRAY_SIZE], double[ARRAY_SIZE][ARRAY_SIZE]);
void UpdateElements(double[ARRAY_SIZE][ARRAY_SIZE], double[ARRAY_SIZE][ARRAY_SIZE]);
bool CheckUpdates(double[ARRAY_SIZE][ARRAY_SIZE], double[ARRAY_SIZE][ARRAY_SIZE]);
void WriteToFile(ostream&, double[ARRAY_SIZE][ARRAY_SIZE]);
void ReadFromFile(istream&, double[ARRAY_SIZE][ARRAY_SIZE]);

int main() {

    //Part 1: Initialize the hotplate arrays
    cout << "Hotplate simulator" << endl << endl;
    double mainPlate[ARRAY_SIZE][ARRAY_SIZE];
    double copyOfPlate[ARRAY_SIZE][ARRAY_SIZE];
    //Initialize the arrays with the initial values as specified in the project rubric
    Init2DArray(mainPlate);
    Init2DArray(copyOfPlate);
    cout << "Printing the initial plate values..." << endl;
    PrintArray(mainPlate);

    //Part 2: Update Elements Once
    UpdateElements(copyOfPlate,mainPlate);
    cout << "Printing plate after one iteration..." << endl;
    PrintArray(mainPlate);
    CopyArray(mainPlate, copyOfPlate);

    //Part 3 - Update Elements:
    bool isStable = false; //This boolean tells whether the temperatures have stabilized or not
    while (isStable == false){//This loop will run until the temperatures stabilize
        UpdateElements(copyOfPlate,mainPlate);
        isStable = CheckUpdates(mainPlate,copyOfPlate);
        CopyArray(mainPlate, copyOfPlate);
    }
    cout << "Printing final plate..." << endl;
    PrintArray(mainPlate);

    //Part 4 - Write data to file
    ofstream hotplate;
    hotplate.open("Hotplate.csv");
    //Check to see if Hotplate.csv is open. If it failed to open, quit the program
    if (!hotplate.is_open()) {
        cout << "Unable to open Hotplate.csv file. Program terminating early.";
        return 1;
    }
    //Write values of the final hotplate to a csv
    WriteToFile(hotplate,mainPlate);
    hotplate.close();
    cout << "Writing final plate to \"Hotplate.csv\"..." << endl << endl;

    //Part 5
    ifstream inputText;
    inputText.open("Inputplate.txt");
    //Check to see if Inputplate.txt is open. If it failed to open, quit the program
    if (!inputText.is_open()) {
        cout << "Unable to open Inputplate.txt file. Program terminating early.";
        return 1;
    }
    ReadFromFile(inputText,copyOfPlate);
    //Update the input board 3 times (or as many times as specified by TIMES_TO_RUN_INPUTPLATE
    for (int i = 0; i < TIMES_TO_RUN_INPUTPLATE; i++) {
        UpdateElements(copyOfPlate,mainPlate);
        CopyArray(mainPlate, copyOfPlate);
    }
    cout << "Printing input plate after " << TIMES_TO_RUN_INPUTPLATE << " updates..." << endl;
    PrintArray(mainPlate);
    return 0;
}

//A function to read the values of a files into a 2d array
void ReadFromFile(istream& inputFile, double outputArray[ARRAY_SIZE][ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            inputFile >> outputArray[i][j];
        }
    }
}

//A function to write the values of a 2D array to a file
void WriteToFile(ostream& outputFile, double inputArray[ARRAY_SIZE][ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            outputFile << fixed << setprecision(PRECISION_SIZE) << setw(WIDTH_SIZE) << inputArray[i][j];
            if (j != ARRAY_SIZE - 1){
                outputFile  << ",";
            }
        }
        outputFile << endl;
    }
}

//Update the values in the array by calculating the average temperature of the neighbors of each internal element
void UpdateElements(double sourceArray[ARRAY_SIZE][ARRAY_SIZE], double targetArray[ARRAY_SIZE][ARRAY_SIZE]) {
    double average = 0.0;
    double top = 0.0;
    double bottom = 0.0;
    double left = 0.0;
    double right = 0.0;
    for (int i = 1; i < ARRAY_SIZE-1; i++) {
        for (int j = 1; j < ARRAY_SIZE-1; j++) {
            top = sourceArray[i - 1][j];
            bottom = sourceArray[i + 1][j];
            right = sourceArray[i][j + 1];
            left = sourceArray[i][j - 1];
            average = (top + bottom + right + left) / 4.0;

            targetArray[i][j] = average;
        }
    }
}

//A Function to initialize a 2D array with values for the hotplate
void Init2DArray(double inputArray[ARRAY_SIZE][ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if ((i == 0 || i == ARRAY_SIZE - 1) && (j > 0 && j < ARRAY_SIZE - 1)) {
                inputArray[i][j] = 100.0;
            }
            else {
                inputArray[i][j] = 0.0;
            }
        }
    }
}

//A function for copying one array of doubles into the other, for use in updating the temp array
void CopyArray(double sourceArray[ARRAY_SIZE][ARRAY_SIZE], double targetArray[ARRAY_SIZE][ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            targetArray[i][j] = sourceArray[i][j];
        }
    }
}

// A function for the printing of arrays
void PrintArray(double inputArray[ARRAY_SIZE][ARRAY_SIZE]){
    for (int i = 0; i < ARRAY_SIZE; i++){
        for (int j = 0; j < ARRAY_SIZE; j++){
            cout << fixed << setprecision(PRECISION_SIZE) << setw(WIDTH_SIZE) << inputArray[i][j];
            if (j != ARRAY_SIZE - 1){
                cout  << ",";
            }
        }
        cout << endl;
    }
    cout << endl;
}
//A function that checks to see if the temperatures have stabilized
bool CheckUpdates(double newArray[ARRAY_SIZE][ARRAY_SIZE], double oldArray[ARRAY_SIZE][ARRAY_SIZE]){
    bool updateAgain = true;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if (abs(newArray[i][j] - oldArray[i][j]) > STEADY_STATE_MARGIN){//If the difference between the old and new value is more than 0.1 of any value, update again
                updateAgain = false;
                return updateAgain;
            }

        }
    }
    return updateAgain;
}

