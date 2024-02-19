    #include <iostream>

 // Include the string library for using string data type

        #include <string> 
        using namespace std;  

     int main() {

  // equates to the maximum number of students

    const int maxSTUDENTS = 20; 

// arrays to store student names, ages, and grades.

    string names[maxSTUDENTS]; 
    int ages[maxSTUDENTS];      
    char grades[maxSTUDENTS];   

// for-loop asks the user the name 20 times, like the 'baverages' array in 8.1
    
    cout << "Enter names (up to 20): " << endl;
    for (int i = 0; i < maxSTUDENTS; ++i) {
        cout << "Enter name " << (i + 1) << ": ";
        cin >> names[i];
    }

// Input for student ages, then the 'if' decision structure validates grade input. The 'return 1' exits the program with an error code

    cout << "Enter ages (up to 20): " << endl;
    for (int i = 0; i < maxSTUDENTS; ++i) {
        cout << "Enter age " << (i + 1) << ": ";
        cin >> ages[i];
        if (ages[i] < 0) {
            cout << "Enter a number greater than or equal to zero" << endl;
            return 1;  
        }
    }

 // Input for student grades, then the 'if' decision structure validates grade input. The 'return 1' exits the program with an error code

    cout << "Enter grades (up to 20): " << endl;
    for (int i = 0; i < maxSTUDENTS; ++i) {
        cout << "Enter grade " << (i + 1) << ": ";
        cin >> grades[i];
        
        if (grades[i] != 'A' && grades[i] != 'B' && grades[i] != 'C' && grades[i] != 'D' && grades[i] != 'F') {
            cout << "Enter a valid letter grade (A, B, C, D, or F): " << endl;
            return 1;  
        }
    }

// Output the data

    cout << "Entered data:" << endl;
    for (int i = 0; i < maxSTUDENTS; ++i) {
        cout << "Name: " << names[i] << ", Age: " << ages[i] << ", Grade: " << grades[i] << endl;
    }

    return 0;  
}

