#include <iostream>
#include <string>
#include <cmath> // for abs()

using namespace std;

const int ROWS = 5;
const int COLUMNS = 5;

// Function to print the seating chart
void printChart(const char chart[ROWS][COLUMNS]) {
    cout << "   A  B  C  D  E" << endl; // Seat identifiers
    // Loop through each row
    for (int i = 0; i < ROWS; ++i) {
        cout << i + 1 << "  "; // Print row number
        // Loop through each column in the row
        for (int j = 0; j < COLUMNS; ++j) {
            cout << chart[i][j] << "  "; // Print seat status
        }
        cout << endl; // Move to the next line for the next row
    }
}

// Function to assign a student to a seat
void assignSeat(char chart[ROWS][COLUMNS], const string& studentName, int row, int column, bool preferNear, const string& preferredStudentName) {
    // Check if the specified row and column are valid
    if (row < 1 || row > ROWS || column < 1 || column > COLUMNS) {
        cout << "Invalid row or column number." << endl; // Display error message
        return; // Exit the function
    }
    // Check if the seat is empty
    if (chart[row - 1][column - 1] == '-') {
        chart[row - 1][column - 1] = studentName[0]; // Assign the student to the seat
        cout << studentName << " has been assigned to row " << row << ", column " << column << "." << endl; // Display success message
    } else {
        cout << "Seat at row " << row << ", column " << column << " is already occupied." << endl; // Display error message if seat is occupied
        return;
    }

    // If preferNear is true, find a seat near the preferred student
    if (preferNear) {
        // Check nearby seats for the preferred student
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newRow = row + i;
                int newColumn = column + j;
                // Check if the nearby seat is within the bounds of the seating chart and is occupied by the preferred student
                if (newRow >= 1 && newRow <= ROWS && newColumn >= 1 && newColumn <= COLUMNS &&
                    (i != 0 || j != 0) && chart[newRow - 1][newColumn - 1] == preferredStudentName[0]) {
                    // Assign the student to the nearby seat
                    cout << studentName << " has been assigned to a seat near " << preferredStudentName << "." << endl;
                    return;
                }
            }
        }
    }
}

// Function to find an empty seat
pair<int, int> findEmptySeat(const char chart[ROWS][COLUMNS]) {
    // Loop through each row and column
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            // Check if the seat is empty
            if (chart[i][j] == '-') {
                // Return the row and column indices of the empty seat
                return {i + 1, j + 1};
            }
        }
    }
    // Return {-1, -1} if no empty seat is found
    return {-1, -1};
}

// Bonus: Function to count the number of empty seats
int countEmptySeats(const char chart[ROWS][COLUMNS]) {
    int emptySeatsCount = 0;
    // Loop through each row and column
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            // Check if the seat is empty
            if (chart[i][j] == '-') {
                // Increment the empty seat count
                ++emptySeatsCount;
            }
        }
    }
    // Return the total count of empty seats
    return emptySeatsCount;
}

int main() {
    // Initialize the seating chart
    char chart[ROWS][COLUMNS] = {
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'}
    };

    // Example usage
    printChart(chart);

    // Ask the user for input to assign a student to a seat
    string studentName, preferredStudentName;
    int row, column;
    bool preferNear;

    cout << "Enter student name: ";
    cin >> studentName;
    cout << "Enter desired row (1-" << ROWS << "): ";
    cin >> row;
    cout << "Enter desired column (1-" << COLUMNS << "): ";
    cin >> column;
    cout << "Prefer near another student? (1 for yes, 0 for no): ";
    cin >> preferNear;
    if (preferNear) {
        cout << "Enter the name of the preferred student: ";
        cin >> preferredStudentName;
    }

    // Assign the seat to the student based on user input
    assignSeat(chart, studentName, row, column, preferNear, preferredStudentName);

    // Display the updated seating chart
    printChart(chart);

    // Find the first empty seat and display its position
    auto emptySeat = findEmptySeat(chart);
    cout << "First empty seat found at row " << emptySeat.first << ", column " << emptySeat.second << endl;

    // Count and display the number of empty seats
    cout << "Number of empty seats: " << countEmptySeats(chart) << endl;

    return 0;
}

