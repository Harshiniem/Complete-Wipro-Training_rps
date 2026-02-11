/*
 * Purpose          : Define a class MyArray, you provide constructors (default, single parameterized, copy), printArray(), extend(It will add new contents from an existing array).
	
	class MyArray{
		int arr[100];
		int size;
	public:
		MyArray();
		MyArray(int data);
		MyArray(const MyArray&);
		void printArray();
		void extend(const MyArray&);
	};

 * Author           : Harshinie M
 * Date             : 26/12/2025
 */
#include <iostream>
using namespace std;

class MyArray {
    int arr[100];
    int size;

public:
    MyArray() {
        size = 0;
    }

    MyArray(int data) {
        arr[0] = data;
        size = 1;
    }

    MyArray(const MyArray &obj) {
        size = obj.size;
        for(int i=0;i<size;i++)
            arr[i] = obj.arr[i];
    }

    void extend(const MyArray &obj) {
        for(int i=0;i<obj.size;i++)
            arr[size++] = obj.arr[i];
    }

    void printArray() {
        for(int i=0;i<size;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    MyArray a1(5);
    MyArray a2(10);

    a1.extend(a2);
    a1.printArray();

    return 0;
}

