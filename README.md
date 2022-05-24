# UsernamesAndPasswords
Implements a hash function to store usernames and passwords into a bucket array
## General Information
This project implements a hash function to store usernames and passwords into a bucket array,
which will be initialized by loading username/password sets from a file called password.txt. A polynomial
hash function stores the username in order to determine which bucket the username/password combination is
in. Collsions are handled by seperate chaining. Once all username/passwords are loaded from the file, a
printout of the buckets are shown and the program prompts for a username and password combination, which
checks the combination is corrects. The user than has the option to continue or exit the program.

**Hash Function Used**
```C++
int HashTable::hashFunction(string username) {
	int size = username.size() - 1;
	int ascii = 0;
	long long polynomial = 0;
	int bucket = 0;

	for (int i = 0; i < username.size(); i++) {	
		ascii = (int)username[i];	
		polynomial = polynomial + (ascii * (long long)pow(a, size));	
		size--;
	}
	bucket = polynomial % 10;	
	return bucket;
}
```
## Technologies
Project is created with 
* IDE: Microsoft Visual Studio 2019
* Version: 16.11.10
* Language: C++20
## Setup
To run this project use Microsoft Visual Studio or an IDE that supports C++20 and download the .cpp and .h files into your IDE..
The password.txt file is located in the Debug Folder and can be changed to different usernames and passwords.
The user will be prompt to enter user name and password combo. 

**Sample Output**

![image](https://github.com/MadCodes9/UsernamesAndPasswords/blob/main/UP2.png)
## Status 
This is a project created by @MadCodes9 :grinning:

Source: *Data Structures and Algorithms in C++ 2nd Edition*

