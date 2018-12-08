#include <string>
#include <iostream>
#pragma once

struct Contact {
	std::string name;
	long phoneNumber;

	Contact() {
		name = "";
		phoneNumber = 0;
	}

	
};

struct Node {
	Contact contact;
	Node* pNext;

	Node() {
		pNext = NULL;
	}

	Node(std::string name, long phoneNumber) {
		contact.name = name;
		contact.phoneNumber = phoneNumber;
		pNext = NULL;
	}

	Node(std::string name, long phoneNumber, Node* pNext) {
		contact.name = name;
		contact.phoneNumber = phoneNumber;
		this->pNext = pNext;
	}

};

/*class Node {
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
};*/

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
	//void printHeadNode();
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
	LinkedList hashTable[5];
	
public:

	int insert(std::string, long);
	bool findKey(std::string, long);
	Node* findDeleteKey(std::string, long);
	int deleteKey(std::string, long);
	int hashFunction(long);
	Hash();
};
