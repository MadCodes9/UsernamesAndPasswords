/*
* Program: UsernamePassword.cpp
* Author: Ceiara Madrigal
* Course: CSCI 230
* Date: 3/20/20
* Description: This project implements a hash function to store usernames and passwords into a bucket array,
* which will be initialized by loading username/password sets from a file called password.txt. A polynomial
* hash function stores the username in order to determine which bucket the username/password combination is
* in. Collsions are handled by seperate chaining. Once all username/passwords are loaded from the file, a
* printout of the buckets are shown and the program prompts for a username and password combination, which
* checks the combination is corrects. The user than has the option to continue or exit the program.
*
* I certify that the following code is my own work.
*
* Exception(s): N/A
*/
#include <iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include "HashTable.h"
using namespace std;

int main()
{
    cout << setw(52) << "====================================" << endl;
    cout << setw(52) << "= Welcome Back to Players Connect! =" << endl;
    cout << setw(52) << "====================================" << endl;
    cout << endl;

    HashTable hashObj;
    ifstream inFile;
    string username;
    string password;
    bool stay = true;

    inFile.open("password.txt");

    if (!inFile.is_open()) {    //checks if file is open
        cout << "Could not open file" << endl;
        return 1;
    }
    while (inFile >> username >> password) {    //read text file
        hashObj.insert(username, password);  //insert text file info.
    }
    hashObj.printOfBuckets();   //print usernames in buckets

    while (stay == true) {
        string inputUsername;
        string inputPassword;
        char choice;

        cout << "\n\t\t= Please enter your username and password below =" << endl;

        cout << "\n\t\tLogin: ";
        cin >> inputUsername;
        cout << "\t\tPassword: ";
        cin >> inputPassword;
        hashObj.find(inputUsername, inputPassword);

        cout << "\t\tWould you like to try again?(Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            stay = true;
        }
        else {
            stay = false;
            hashObj.~HashTable();
            cout << "\n\t\tDisconnecting from Players Connect... " << endl;
            cout << "\t\t\t Goodbye!" << endl;
        }
    }
    inFile.close();
    cin.get();  //portable than system("pause")
    return 0;
}

