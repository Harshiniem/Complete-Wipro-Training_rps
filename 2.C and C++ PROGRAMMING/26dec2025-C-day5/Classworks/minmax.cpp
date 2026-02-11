/*
 * Purpose          : Find min, max of values in an array. Pass arr along with Min and Max as reference or Address as argument.
		void findMinMax(int *arr, int size, int &min, int &max);
 * Author           : Harshinie M
 * Date             : 26/12/2025
 */
#include <iostream>
using namespace std;

void findMinMax(int *arr, int size, int &min, int &max) {
    min = max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
}

int main() {
    int arr[] = {4, 9, 1, 7, 3};
    int min, max;
    findMinMax(arr, 5, min, max);
    cout << "Min: " << min << " Max: " << max << endl;
    return 0;
}

