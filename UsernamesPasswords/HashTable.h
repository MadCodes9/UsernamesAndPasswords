#pragma once
#include<string>
using namespace std;

class HashTable
{
private:
	static const int TABLESIZE = 10;
	static const int a = 33;
public:
	struct user {
		string username;
		string password;
		user* next;
	};
	user* table[TABLESIZE];
public:
	HashTable();
	~HashTable();
	/*
	* to create a hash function, the function takes in a string and
	* manipulates it by adding the string's characters ASCII numbers
	* together to create a integer not within the table, then compresses
	* that integer so that it fits within the hash table.
	* @param username	the string to be transformed into an integer
	* @return index	the compressed index that fits within hash table
	*/
	int hashFunction(string username);

	/*
	* calls HashFunction to know which bucket to store username and password
	* in. Check to see if the username is already taken using find function,
	* if the username is taken, then print out already taken, and otherwise,
	* insert the username and password combinatrion using seperate chaining
	* @param username	the username chosen by user to be inserted
	* @param password	the password chosen by user to be inserted
	*/
	void insert(const string& username, const string& password);

	/*
	* calls HashFunction to know which bucket to search for the username.
	* While the bucket does not equal NULL, than check is the username and 
	* password in bucket is equal to the username and password wanted to 
	* be found, and otherwise, advance down the list to check as long as
	* the next node does not equal NULL
	* @param username	the username wanted to be found
	* @param password	the password wanted to be found
	*/
	void find(const string& username, const string& password);
	void printOfBuckets();	//a printout of the buckets 
};

