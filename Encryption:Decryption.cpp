#include <iostream> //for input/output for user
#include <string> //to convert string into int and vice versa

using namespace std;


string caesar_encrypt(string message);
string caesar_decrypt(string message);
string Vigenere_Encrypt(string message, string key);
string Vigenere_Decrypt(string message, string key);


//this is the main code
int main() {
	cout << "Welcome to our program used for Encryption and Decryption!" << endl;
	cout << "----------------------------------------------" << endl;

	int technique, algorithm; //variables used for cipher technique AND encrypt or decrypt algorithm 
	string message, codedMessage;//variables used for message and coded message
	string key; //variable used for key for vigenere cipher
	int loopValidate = 1; //used to validate the data loops, 1 is true and 0 is false
	int dataValidate = 1;
	int programLoop = 0;//used to terminate loop

	cout << "\nOur program allows you to encrypt or decrypt a certain message using the Caesar Cipher or Vigenere Cipher" << endl;

	//this do loop will keep running the program until the user enters a 3
	do {
		//this do loop will only run once if the data entered is a 1, 2 or 3
		do {
			
			cout << "Please enter a (1) to use the Caesar Cipher or a (2) to use the Vigenere Cipher or a (3) to quit the program: ";
			cin >> technique;

			//this if loop determines if data is valid or not, 1 means valid, and 0 means invalid
			if (technique == 1 || technique == 2 || technique == 3) {
				loopValidate = 1;
			}
			else {
				cout << "\nThat is an invalid answer, please try again\n";
				loopValidate = 0;
			}
		} while (loopValidate== 0);

		//once cipher technique is chosen, this loop will continue as long as data entered for encryption/decryption is invalid
		do {
			if (technique == 1) {
				cout << "\nYou have chosen to use the Caesar Cipher! Please enter a (1) to encrypt or a (2) to decrypt the code: ";
				cin >> algorithm;

				if (algorithm == 1) {
					cout << "\nYou have chosen to Encrypt your code using the Caesar Cipher!" << endl;
					cout << "Please enter the message you want to encrypt: ";
					cin.ignore(); //To clear \n left by cin
					getline(cin, message); //To include whitespace

					codedMessage = caesar_encrypt(message);

					cout << "\nThe encrypted message is: " + codedMessage + "\n";
					dataValidate = 1;//will not continue loop
				}//end of caesar cipher encrypt loop
				else if (algorithm == 2) {
					cout << "\nYou have chosen to Decrypt your code using the Caesar Cipher!" << endl;
					cout << "Please enter the message you want to decrypt: ";
					cin.ignore();
					getline(cin, message);

					codedMessage = caesar_decrypt(message);

					cout << "\nThe decrypted message is: " + codedMessage +"\n";
					dataValidate = 1;//will not continue loop
				}//end of caesar cipher decrypt loop
				else {
					cout << "\nThat is not a valid answer, please try again" << endl;
					dataValidate = 0;//will run loop again
				}//end of else loop for caesar cipher

			}//end of caesar cipher Technique loop 
			else if (technique == 2) {
				cout << "\nYou have chosen to use the Vigenere Cipher! Please enter a (1) to encrypt or a (2) to decrypt the code: ";
				cin >> algorithm;

				if (algorithm == 1) {
					cout << "\nYou have chosen to Encrypt your code using the Vigenere Cipher!" << endl;
					cout << "Please enter the message you want to encrypt: ";
					cin.ignore();
					getline(cin, message);

					cout << "Please enter the key for the encryption: ";
					cin >> key;

					codedMessage = Vigenere_Encrypt(message, key);

					cout << "\nThe encrypted message is: " + codedMessage + "\n";
					dataValidate = 1;//will not continue loop
				}//end of vigenere cipher encrypt loop
				else if (algorithm == 2) {
					cout << "\nYou have chosen to Decrypt your code using the Vigenere Cipher!" << endl;
					cout << "Please enter the message you want to decrypt: ";
					cin.ignore();
					getline(cin, message);

					cout << "Please enter the key for the encryption: ";
					cin >> key;

					codedMessage = Vigenere_Decrypt(message, key);

					cout << "\nThe encrypted message is: " + codedMessage + "\n";
					dataValidate = 1;//will not continue loop
				}//end of vigenere cipher decrypt loop
				else {
					cout << "\nThat is not a valid answer, please try again" << endl;
					dataValidate = 0;//will run loop again
				}//end of else loop for vigenere cipher

			}//end of vigenere cipher technique loop 
			else if (technique == 3) {
				cout << "\nThank you for using our program!\n";
				dataValidate = 1;
				programLoop = 1;
			}
			else {
				cout << "\nThat is not a valid answer, please try again" << endl;
				dataValidate = 0;//will run loop again
			}//end of data validation of cipher technique loop

		} while (dataValidate == 0);
	} while (programLoop == 0);
}//end of main code

string Vigenere_Encrypt(string message, string key)
{
	string secret = "";
	int keyNum = 0;
	int count = 0;

	for (int i = 0; i < message.size(); i++)
	{
		//Key
		keyNum = key.at((count) % key.size()) - 97;

		//Lowercase
		if (int(message.at(i)) >= 97 && int(message.at(i)) <= 122)
		{
			secret += (message.at(i) - 97 + keyNum) % 26 + 97;
			count++;
		}
		//Uppercase
		else if (int(message.at(i)) >= 65 && int(message.at(i)) <= 90)
		{
			secret += (message.at(i) - 65 + keyNum) % 26 + 65;
			count++;
		}
		//Whitespace and other symbols
		else
		{
			secret += message.at(i);
		}
	}
	return secret;
}

string Vigenere_Decrypt(string secret, string key)
{
	string message = "";
	int keyNum = 0;
	int count = 0;

	for (int i = 0; i < secret.size(); i++)
	{
		//Key
		keyNum = key.at((count) % key.size()) - 97;

		//Lowercase
		if (int(secret.at(i)) >= 97 && int(secret.at(i)) <= 122)
		{
			message += (secret.at(i) - 97 - keyNum + 26) % 26 + 97;
			count++;
		}
		//Uppercase
		else if (int(secret.at(i)) >= 65 && int(secret.at(i)) <= 90)
		{
			message += (secret.at(i) - 65 - keyNum + 26) % 26 + 65;
			count++;
		}
		//Whitespace and other symbols
		else
		{
			message += secret.at(i);
		}
	}
	return message;
}

string caesar_encrypt(string message)
{

	string hidden;
	// the input will be shifted by 7
	int shift = 7;

	hidden = message;

	//shift each character in the entered input
	for (int i = 0; i < message.length(); i++)
	{
		//If there are uppercase characters subtract them by 65
		if (message[i] >= 'A' && message[i] <= 'Z')
			hidden[i] = 65 + (message[i] + shift - 65) % 26;

		//If there are lowercase characters subtract them by 97
		else if (message[i] >= 'a' && message[i] <= 'z')
			hidden[i] = 97 + (message[i] + shift - 97) % 26;
	}

	return hidden;

}


string caesar_decrypt(string message)
{
	// normal is the string after it is decrypted using caesar cipher
	string normal;

	// the input will be shifted by 7
	int shift = 7;

	normal = message;

	//shift each character in the entered input
	for (int i = 0; i < message.length(); i++)
	{
		//If there are uppercase characters subtract them by 65
		if (message[i] >= 'A' && message[i] <= 'Z')
			normal[i] = 65 + (message[i] - shift - 65 + 26) % 26;

		//If there are lowercase characters subtract them by 97
		else if (message[i] >= 'a' && message[i] <= 'z')
			normal[i] = 97 + (message[i] - shift - 97 + 26) % 26;

	}

	return normal;

}
