#include<iostream>
#include<string>
#include <bits.h>
using namespace std;

void Jaro_Distance(int match, int len1, int len2, double t) {
	cout << "The Jaro Similarities is : " << (((double)match) / ((double)len1) + ((double)match) / ((double)len2) + ((double)match - t) / ((double)match)) / 3.0 << endl;
}
void Occurances(int len1,string Str1,string Str2,bool *Bool_S1,bool *Bool_S2,double transposition) {
	int point = 0;
	for (int i = 0; i < len1; i++) {
		if (Bool_S1[i]) {

			// Find the next matched character
			// in second string
			while (Bool_S2[point] == false)
				point++;

			if (Str1[i] != Str2[point++])
				transposition++;
		}
	}

	transposition /= 2;

}

void Jaro_Winkler_Algo(string Str1, string Str2){
	// If the strings are equal
	if (Str1 == Str2)
		cout << "The jaro similarities is : " << 1.0 << endl;

	// Length of two strings
	int len1 = Str1.length();
	int len2 = Str2.length();

	// Maximum distance upto which matching
	// is allowed
	int dist = floor(max(len1, len2) / 2) - 1;

	// Count of matches
	int match = 0;

	// Hash for matches
	bool* Bool_S1, * Bool_S2;
	Bool_S1 = new bool[len1];
	Bool_S2 = new bool[len2];

	for (int i = 0; i < len1; i++)
		Bool_S1[i] = false;

	for (int i = 0; i < len2; i++)
		Bool_S2[i] = false;

	for (int i = 0; i < len1; i++) {
		// Check if there is any matches
		int j = max(0, i - dist);
		while (j < min(len2, i + dist + 1)) {
			// If there is a match
			if (Str1[i] == Str2[j]) {
				if (Bool_S2[j] == 0) {
					Bool_S1[i] = Bool_S2[j] = true;
					match++;
					break;
				}
			}
			j++;
		}
	}
	// If there is no match
	if (match == 0) {
		cout << "The Jaro Similarities is : " << 0.0 << endl;
	}
	else {
		// Number of transpositions
		double transposition = 0;

		Occurances(len1, Str1, Str2, Bool_S1, Bool_S2, transposition);
		Jaro_Distance(match, len1, len2, transposition);
	}
}




















// Driver code

int main()
{

	string Str1, Str2;
	cout << "Example 1 : " << endl;
	cout << "Input First string : ";
	cin >> Str1;
	cout << "Input Second string : ";
	cin >> Str2;
	cout << "Finding similarities between " << Str1 << " and " << Str2 << "." << endl;
	Jaro_Winkler_Algo(Str1, Str2);

	cout << "Example 2 : " << endl;
	cout << "Input First string : ";
	cin >> Str1;
	cout << "Input Second string : ";
	cin >> Str2;
	cout << "Finding similarities between " << Str1 << " and " << Str2 << "." << endl;
	Jaro_Winkler_Algo(Str1, Str2);

	cout << "Example 3 : " << endl;
	cout << "Input First string : ";
	cin >> Str1;
	cout << "Input Second string : ";
	cin >> Str2;
	cout << "Finding similarities between " << Str1 << " and " << Str2 << "." << endl;
	Jaro_Winkler_Algo(Str1, Str2);


	cout << "Example 4 : " << endl;
	cout << "Input First string : ";
	cin >> Str1;
	cout << "Input Second string : ";
	cin >> Str2;
	cout << "Finding similarities between " << Str1 << " and " << Str2 << "." << endl;
	Jaro_Winkler_Algo(Str1, Str2);


	cout << "Example 5 : " << endl;
	cout << "Input First string : ";
	cin >> Str1;
	cout << "Input Second string : ";
	cin >> Str2;
	cout << "Finding similarities between " << Str1 << " and " << Str2 << "." << endl;
	Jaro_Winkler_Algo(Str1, Str2);

	return 0;
}






























































