#include <iostream>

using namespace std;

int main(){

    int m = 4;
    int n = 3;

    int **arr = new int*[m];
    for(int i = 0; i<m; i++){
        arr[i] = new int[n];
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            arr[i][j] = j+1;
            cout<<arr[i][j];
        }  
        cout<<endl;
    }
}

