#include "HashTable.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

HashTable::HashTable() {
	for (int i = 0; i < TABLESIZE; i++) {	//create initial buckets in hash table
		table[i] = new user;
		table[i]->username = "empty";
		table[i]->password = "empty";
		table[i]->next = NULL;
	}
}
HashTable::~HashTable() {
	for (int i = 0; i < TABLESIZE; i++)
	{
		delete table[i];
		table[i] = NULL;
	}
}
int HashTable::hashFunction(string username) {
	int size = username.size() - 1;
	int ascii = 0;
	long long polynomial = 0;
	int bucket = 0;

	for (int i = 0; i < username.size(); i++) {	//hash function using a polynomial
		ascii = (int)username[i];	//ASCII value of char
		polynomial = polynomial + (ascii * (long long)pow(a, size));	//long long type to avoid overflow
		size--;
	}
	bucket = polynomial % 10;	//compression function, to fit in bucket
	return bucket;
}
void HashTable::insert(const string& username, const string& password) {
	int bucket = hashFunction(username);

	if (table[bucket]->username == "empty") {	//bucket that has no user info.
		table[bucket]->username = username;
		table[bucket]->password = password;
		table[bucket]->next = NULL;
	}
	else {
		user* ptr = table[bucket];	//points to the beggining of the bucket
		user* node = new user;	//new node 
		node->username = username;
		node->password = password;
		node->next = NULL;

		while (ptr->next != NULL) {
			ptr = ptr->next;	//advance down list
		}

		ptr->next = node;	//once ptr->next = NULL (end of list), link new node info. 
	}
}
void HashTable::find(const string& username, const string& password) {
	int bucket = hashFunction(username);
	user* ptr = table[bucket];	//points to the beggining of the bucket

	while (ptr != NULL) {
		if (ptr->username == username && ptr->password == password) {	//username and password match
			cout << "\t\tAuthorization successful" << endl;
			return;	//wont print next statement if true
		}
		else if (ptr->next == NULL) {	//end of list 
			cout << "\t\tAuthorization failure" << endl;
		}
		ptr = ptr->next; //advance down list
	}
}
void HashTable::printOfBuckets() {

	for (int i = 0; i < TABLESIZE; i++) {
		user* ptr = table[i];

		cout << "\t\t" << i << ": ";
		while (ptr != NULL) {
			cout << ptr->username << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
}