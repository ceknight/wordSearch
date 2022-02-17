//This program opens a file from user input
//It the reads the file and assigns each string inside into an array
//The program closes the file and opens a new file from user input
//It then compares all the words from the new file with the array of strings from the original file
//The program then notifies the user how many similar words were found and how many comparisons were made in total

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int const n = 10000;
	string wordArr[n]; //array to store our 10000 words

	ifstream fin;
	fin.open("C:\\Users\\cekni\\OneDrive\\Desktop\\List of 10000 Random Words.txt");

	for (int i = 0; i < n; i++) { //using a for loop to assign each string from file into the array
		getline(fin, wordArr[i]);
	}
	fin.close();

	int wordsFound = 0, comparisons = 0;
	string searchWord;
	fin.open("C:\\Users\\cekni\\OneDrive\\Desktop\\Search Words.txt");

	if (fin.is_open()) { //using some nested loops to compare the words from our new file with each element of the array one at a time

		while (getline(fin, searchWord)) {
			for (int x = 0; x < n; x++) {
				if (wordArr[x] == searchWord) {
					wordsFound++; //documenting each match
					comparisons++;
				}
				else {
					comparisons++; //documenting each comparison for testing purposes
				}
			}
			int x = 0;
		}
	}

	cout << wordsFound << " similar words were found!" << endl;
	cout << comparisons << " comparisons were made!" << endl << endl;

	return 0;
}