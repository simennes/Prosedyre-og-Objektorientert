#include <iostream>
#include "Matrix.h"
#include "Dummy.h"

void fillInFibonacciNumbers(long int result[], int length){
	long int a = 0;
	long int b = 1;
	result[0] = a;
	result[1] = b;

	for(int i = 2; i < length; i++){
		long int c = a + b;
		result[i] = c;
		a = b;
		b = c;
	}
}

void printArray(long int arr[], int length){
	for(int i = 0; i < length && i < 47; i++){
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

void createFibonacci() {
	int n;
	std::cout << "Wazgud myman? How many fibonacci numbers u wanna make? (MAX is 46) ";
	std::cin >> n;
	std::cout << "I hear u brother, no probz: ";
	long int* numbers{new long int[n]};
	fillInFibonacciNumbers(numbers, n);
	printArray(numbers, n);
	delete[] numbers;
	numbers = nullptr;
}

int main(){
	int menu = 1;
	while (menu != 0)
	{
		std::cout << "\n\nMenu:\n"
		"0) End\n"
		"1) Fibonacci\n"
		"2) Test Matrix class\n"
		"3) Test Dummy class\n"
		"Choose (0-3): ";
		std::cin >> menu;
		std::cout << "\n";

		if(menu == 1){
			createFibonacci();
		}
		else if(menu == 2){
			Matrix testMatrix{5, 5};
			std::cout << "\nNull Matrix:\n";
			std::cout << testMatrix;
			Matrix testMatrix2{5};
			std::cout << "\nIdentity Matrix:\n";
			std::cout << testMatrix2;
			Matrix copiedMatrix{testMatrix2};
			std::cout << "\nCopied Identity Matrix:\n";
			std::cout << copiedMatrix;

			Matrix nonQuadMatrix{3,5};
			Matrix equalMatrix = nonQuadMatrix;
			std::cout << "\nMatrix from =:\n";
			std::cout << equalMatrix;

			testMatrix2 += copiedMatrix;
			std::cout << "\nTest of +=:\n";
			std::cout << testMatrix2;

			Matrix addMatrix = testMatrix2 + copiedMatrix;
			std::cout << "\nTest of +:\n";
			std::cout << addMatrix;

		}
		else if (menu == 3){
			std::cout << "\nDummytest:\n";
			dummyTest();
		}
	}

}
