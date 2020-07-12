#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
void Rabin_Karp(char *Text, char *Patt) {
	int len_Text = strlen(Text), len_Patt = strlen(Patt), counter1 = 0, counter2 = 0;
	int Value_for_Patt = 0;
	int Value_for_Text = 0;
	int value = 1;

	for (counter1 = 0; counter1 < len_Patt - 1; counter1++)
		value = (value * 26);
	for (counter1 = 0; counter1 < len_Patt; counter1++) {
		Value_for_Patt = (26 * Value_for_Patt + Patt[counter1]);
		Value_for_Text = (26 * Value_for_Text + Text[counter1]);
	}
	for (counter1 = 0; counter1 <= len_Text - len_Patt; counter1++) {
		if (Value_for_Patt == Value_for_Text) {
			for (counter2 = 0; counter2 < len_Patt; counter2++) {
				if (Text[counter1 + counter2] != Patt[counter2])
					break;
			}
			if (counter2 == len_Patt)
				cout << "Pattern found at index " << counter1 + 1 << endl;
		}
		if (counter1 < len_Text - len_Patt) {
			Value_for_Text = (26 * (Value_for_Text - Text[counter1] * value) + Text[counter1 + len_Patt]);
			if (Value_for_Text < 0)
				Value_for_Text = (Value_for_Text + 13);
		}
	}
}

int main() {
	ifstream myfile;
	myfile.open("file.txt",ios::in);
	//this code if for 5 times input 
	if (myfile.is_open()) {
		string line1,line2;
		bool flag = 0;
		while (myfile.eof()) {
			if (flag == 0) {
				getline(myfile, line1);
				flag = 1;
			}
			if (flag == 1) {
				getline(myfile, line2);
				flag = 0;
				Rabin_Karp(line1, line2);
			}
		}

	}
	
	char Text1[] = "AABAACAADAABAABA";
	char Patt1[] = "AABA";
	cout << "Example 1 : " << endl;
	Rabin_Karp(Text1, Patt1);

	cout << "Example 2 : " << endl;
	char Text2[] = "jdsjjoiojojoskjdjjojoscnsjdnjojo";
	char Patt2[] = "jojo";
	Rabin_Karp(Text2, Patt2);

	cout << "Example 3 : " << endl;
	char Text3[] = "SDSFGGHWKIQUISDSFLKKKJVSNCSDSS";
	char Patt3[] = "SDSF";
	Rabin_Karp(Text3, Patt3);

	cout << "Example 4 : " << endl;
	char Text4[] = "HJHAXHJHJSABNDWEHAJABDSNBAHJHJSDBNHJHSUDIUEHDAHJHJ";
	char Patt4[] = "HJHJ";
	Rabin_Karp(Text4, Patt4);

	cout << "Example 5 : " << endl;
	char Text5[] = "QSDFGQWERTYAJDKHSAQWERTYSAJHADJQWERTYCJHSAHDQWERTYXDKSAJHDMN";
	char Patt5[] = "QWERTY";
	Rabin_Karp(Text5, Patt5);
	
	return 0;
}
