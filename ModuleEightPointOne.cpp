     #include <iostream>
     #include <algorithm>

    using namespace std;

// I wanted to perform a bubble sort on the array instead of iterating using a for-loop
   
     void bubbleSort(int arr[], int n) {
//to check if any swaps are made in an iteration
       
        bool isUnsorted;
    
/* do-while repeats until no swaps are made. 'iunsorted' is initialized to false so that if the array meets the if '(arr[i] > arr[i + 1])'
      its value is converted to true.  */
   
     do {
        isUnsorted = false;  
        
// Loop through the array
       
        for (int i = 0; i < (n - 1); i++) {
            
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isUnsorted = true;  
            }
        }
    } while (isUnsorted); 
// Continue until no swaps are made
}

 
    int main() {

// the array that stores batting averages
    
    int baverages[8];  

/* statement prompts the user to enter batting averages once, then the loop iterates 7 times, then stores the user-inputted values
  to the baverages array  */
   
    cout << "Enter eight batting averages: " << endl;
    
    for (int i = 0; i < 8; ++i) {
       
        cout << "Enter batting average " << (i + 1) << ": ";
        cin >> baverages[i];  
    }
 

 // Starting of bubbleSort that sorts the array. 8 refers to the number of elements in the array.
  
    bubbleSort(baverages, 8);
// Finds maximum and minimum batting averages in the sorted array
   
    int maximum = baverages[7];  
    int minimum = baverages[0];  

/* Calculates the sum of batting averages, the sum is then stored in the total variable. The total variable 
    adds each batting average (baverages[i]) as the loop iterates through the array. All the values added (++i) to 'total' is used for the 'average' variable.

*/
   
    int total = 0;
    for (int i = 0; i < 8; ++i) {
        total += baverages[i];  
    }
    
// for calculatign batting average
   
    double average = static_cast<double>(total) / 8;

// Output the sorted array

    cout << "Sorted array: ";
    for (int i = 0; i < 8; ++i) {
        cout << baverages[i] << " ";  
    }
    
// Output the maximum, minimum, and average batting averages
   
    cout << "The Maximum value is " << maximum << ". The Minimum value is " << minimum << ". The average is " << average << endl;

    return 0;  
}

