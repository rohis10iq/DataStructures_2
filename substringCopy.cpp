#include <iostream>
#include <cstring> 

using namespace std;


char* extractSubstring(char* inputString, int startIndex, int stopIndex) {
    int length = stopIndex - startIndex + 1;
    char* result = new char[length + 1]; 

    
    for (int i = 0; i < length; ++i) {
        result[i] = *(inputString + startIndex + i);
    }

    result[length] = '\0'; 
    return result;
}

int main() {
    
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    
    char* inputArray = new char[input.size() + 1];
    strcpy(inputArray, input.c_str());

    int startIndex, stopIndex;
    cout << "Enter the start index: ";
    cin >> startIndex;
    cout << "Enter the stop index: ";
    cin >> stopIndex;

    
    char* result = extractSubstring(inputArray, startIndex, stopIndex);

    
    cout << "Substring between indexes " << startIndex << " and " << stopIndex << ": " << result << endl;

    
    delete[] inputArray;
    delete[] result;

    return 0;
}
