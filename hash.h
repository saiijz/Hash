#include <string>
#include <iostream>
#pragma once

class Contact {
private:
	std::string name;
	long phoneNumber;

public:

	std::string getName();
	long getPhoneNumber();
	
	Contact();
	Contact(std::string, long);
};

class Node {
private:
	Contact* contact;
	Node* pNext;
public:
	int createNode(std::string, long);
	void printInfo();
	Node*& getNextPointer();
	int setNextPointer(Node*);
	Contact* getValue();
	int setValue(std::string, long);
	void setNextPointer(std::string, long);


	Node();
	Node(std::string, long);
	Node(std::string, long, Node*);
};

class LinkedList {
private:
	Node * pHead;
	int size;
public:
	int createLinkedList(std::string, long);
	int addHead(std::string, long);
	int addTail(std::string, long);
	int deleteHead();
	int deleteTail();
	void printHeadNode();
	Node* seekHeadNode();
	Node* seekNode(int);
	Node* operator[](int);
	Node* getHeadPointer();
	int getSize();
	void setSize(int value);
	LinkedList();
};

class Hash {
private:
	LinkedList hashTable[25];
	
public:

	int insert(std::string, long);
	bool findKey(std::string, long);
	Node* findDeleteKey(std::string, long);
	int deleteKey(std::string, long);
	int hashFunction(long);
	Hash();
};
