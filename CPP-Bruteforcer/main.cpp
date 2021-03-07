#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <time.h>

using namespace std;

// Creating the functions for the options if they need it

int helpCommand() {
	cout << "\t\t=========================\n";
	cout << "\t\t===== List Searcher =====\n";
	cout << "\t\t ======== Help =========\n\n\n";
	cout << "-----Description:\n";
	cout << "\tThis is a program for iterating through a file, to find matches.\n";
	cout << "\tAlthough this may seem like grep, it will soon have support for some hashes.\n\n\n";
	cout << "-----Options:\n";
	cout << "\tNOTE: For options with two or more names, the last one specified in the command will be used.\n\n";
	cout << "\t-w/--wordlist:\tSpecify a wordlist to use, can use filepaths\n";
	cout << "\t-p/--password:\tSpecify a word to search for, must be specified if -i is not\n";
	cout << "\t-i/--input:\tSpecify a file to use for passwords. One password per line\n";
	return 0;
}



// Function to check inputs if they use the -i option

int listFileSecondary(string password, string wordlist) {
	bool secondaryPasswordGuessed = false;
	fstream wordlistFile;
	wordlistFile.open(wordlist, ios::in);
	if (wordlistFile.is_open()) {
		string tp;
		while (getline(wordlistFile, tp)) {
			if (tp.compare(password) == 0) {
				secondaryPasswordGuessed = true;
				cout << password << "\n";
				cout.flush();
				return 0;
			}
		}
		if (not (secondaryPasswordGuessed == true)) {
			cout << password << " was not able to be found.\n";
		}
	}
	wordlistFile.close();
	return 0;
}


int listFile(string input, string wordlist) {
	bool currentPasswordGuessed = false;
	fstream inputFile;
	inputFile.open(input, ios::in);
	if (inputFile.is_open()) {
		string currentPassword;
		while (getline(inputFile, currentPassword)) {
			listFileSecondary(currentPassword, wordlist);
		}
		inputFile.close();
	}
	return 0;
}

// Function to check inputs if they only specify -p/--password

int checkPassword(string password, string wordlist) {
	// All the bools for arguments and such
	bool passwordGuessed = false;
	// Create the newfile, then open it
	fstream newfile;
	newfile.open(wordlist, ios::in);
	if (newfile.is_open()) {
		// If it is open, make a string
		string tp;
		cout << "Search beginning\n";
		fflush(stdout);
		while(getline(newfile, tp)) {
			// Iterate through the lines in the file
			if (password.compare(tp) == 0) {
				// If the line matches the password...
				passwordGuessed = true;
				cout << tp << " is the correct password!\n";
			}
			if (passwordGuessed) {
				// This causes it to break once I get the password
				break;
			}
		}
		newfile.close();
		if (!(passwordGuessed)) {
			cout << "Password was not found.\n";
		}
	} else {
		cout << "Please give a valid file including the .txt file extension\n";
	}
	cout.flush();
	return 0;
}

int main(int argc, char** argv) {
	clock_t tStart = clock();
	
	// Creating the variables to hold everything
	string password;
	string passlist;
	string wordlist = "./rockyou.txt";
	
	bool useDashP = false;
	bool useDashI = false;
	
	// Parse the arguments, here we go.
	
	for (int i=1; i<=argc-1; i++) {
		// Convert argv[1] to a string, since I can't use a char in compare
		string argument = argv[i];
		// Password inputs
		if ((argument.compare("-h") == 0) or (argument.compare("--help") == 0)) {
			helpCommand();
			return 0;
		}
		if (((argument.compare("-p") == 0) or (argument.compare("--password") == 0)) and not useDashI) {
			useDashP = true;
			if (argv[i+1] == NULL) {
				cout << argv[i] << " requires a parameter.\n";
				return 0;
			}
			if (i<argc-1) {
				password = argv[i+1];
			}
		}
		
		if (((argument.compare("-i") == 0) or (argument.compare("--input") == 0)) and not useDashP) {
			useDashI = true;
			if (argv[i+1] == NULL) {
				cout << argv[i] << " requires a parameter.\n";
				return 0;
			}
			if (i<argc-1) {
				passlist = argv[i+1];
			}
		}
		
		// Wordlist inputs
		if ((argument.compare("-w")==0) or (argument.compare("--wordlist") == 0)) {
			if (argv[i+1] == NULL) {
				cout << "./rockyou.txt will be used\n";
			}
			if (i<argc-1) {
				wordlist = argv[i+1];
			}
		}
	}
	
	
	// Actually call things
	
	if (useDashP == true) {
		checkPassword(password, wordlist);
	}
	if (useDashI == true) {
		listFile(passlist, wordlist);
	}
	
	cout << "Search completed. Terminating file\n";
	cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " seconds\n";
	
}
