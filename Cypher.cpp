#include <iostream>
#include <string>
using namespace std;



class Cypher {
public:
	string k;
	Cypher(string k) {
		for (int i = 0; i < k.size(); ++i) {
			if (k[i] >= 65 && k[i] <= 90 || k[i] == 32) // checks between ascii values of A and Z
				this->k += k[i];
			else if (k[i] >= 97 && k[i] <= 122) // checks between ascii values of a and z
				this->k += k[i] + 65 - 97; // if a lower case letter was entered in the key enter section, this converts it to uppercase ascii number
		}
	}
	string encode(string t) {
		string output;
		for (int i = 0, j = 0; i < t.length(); ++i) 
		{
			char p = t[i];
			 if (p >= 97 && p <= 122)
				p += 65 - 97;
			else if (p < 65 || p > 90)
				continue;
			if (p >= 97 && p <= 122)
			output += (p + k[j]) % 26 + 65; //65 to make the correct ascii code for the letter cout'ed
			j = (j + 1) % k.length();
		}
		return output;
	}
	string decode(string t) 
	{
		string output;
		for (int i = 0, j = 0; i < t.length(); ++i) {
			char p = t[i];
			if (p >= 97 && p <= 122)
				p += 65 - 97;
			else if (p < 65 || p > 90)
				continue;
			output += (p - k[j] + 26) % 26 + 65;
			j = (j + 1) % k.length();
		}
		return output;
	}
};


void userMenu(string userKey, string userMessage, string encode, string decode)
{
	
	bool inputCheck = true;
	int userSelection = 0;
	while (inputCheck == true)
	{
		cout << "Welcome the Vigenere Cypher Encoder and Decoder!\n";
		cout << "Please choose from the following options by entering the number of choice:\n ";
		cout << "Enter 1 for Creating a Cypher with your own key \n   or \n Enter 2 to decode a Cypher with your own key.\n";
		cin >> userSelection;
		cout << endl;
		if (userSelection == 1 || userSelection == 2)
		{
			if (userSelection == 1)
			{
				cout << "Please enter the message you would like to encode (No spaces or special characters): ";
				cin >> userMessage;
				cout << "Please enter the key to be used: ";
				cin >> userKey;
				Cypher c(userKey);
				encode = c.encode(userMessage);
				cout << "Your coded message is: " << encode << endl;
			}
			else
			{
				cout << "Please enter the message you would like to decode(No spaces or special characters): ";
				cin >> userMessage;
				cout << "Please enter the key to be used, in all CAPS: ";
				cin >> userKey;
				Cypher c(userKey);
				decode = c.decode(userMessage);
				cout << "Your decoded message is: " << decode << endl;
			}
				
			inputCheck = false;
			cout << "userCheck set to false\n";
		}
		else
			cout << "PLEASE INPUT A NUMBER FROM THE CHOICES GIVEN!\n";

	}
	cout << "exited while loop\n";
	return;
};


int main() {
	string userKey;
	string userMessage;
	string encode;
	string decode;
	bool userCheck = true;
	string userSelection = "";
	while (userCheck == true)
	{
		userMenu(userKey, userMessage, encode, decode);
		cout << "\n   Would you like to encode or decode another message?\n";
		cout << "\n     Please enter Y for yes or N for no: ";
		cin >> userSelection;
		if (userSelection == "N" || userSelection == "n")
			userCheck = false;
	}
	system("pause");
	
	
}