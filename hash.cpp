#include "hash.h"

/* Contact class code block*/

std::string Contact::getName()
{
	return this->name;
}

long Contact::getPhoneNumber()
{
	return this->phoneNumber;
}

Contact* Node::getValue()
{
	return this->contact;
}

int Node::setValue(std::string name, long phoneNumber)
{
	this->contact = new Contact(name, phoneNumber);
	this->pNext = NULL;
	return 1;
}

Contact::Contact()
{
	this->name = "NULL";
	this->phoneNumber = 0;
}

Contact::Contact(std::string name, long phoneNumber) {
	this->name = name;
	this->phoneNumber = phoneNumber;
}

/* node class code block */

int Node::createNode(std::string name, long phoneNumber)
{
	*this = Node(name, phoneNumber);
	return 1;
}

void Node::printInfo()
{
	std::cout << "Name: " << this->contact->getName() << std::endl;
	std::cout << "Phone number: " << this->contact->getPhoneNumber() << std::endl;
}

Node* Node::getNextPointer()
{
	return this->pNext;
}

void Node::setNextPointer(std::string name, long phoneNumber) {
	this->pNext = new Node(name, phoneNumber);
}



int Node::setNextPointer(Node *pNext)
{
	this->pNext = pNext;
	return 1;
}

Node::Node()
{
	this->contact = new Contact();
	this->pNext = NULL;
}

Node::Node(std::string name, long phoneNumber)
{
	this->contact = new Contact(name, phoneNumber);
	this->pNext = NULL;
}

Node::Node(std::string name, long phoneNumber, Node* pNext)
{
	this->contact = new Contact(name, phoneNumber);
	this->pNext = pNext;
}



/*LinkedList class code block*/

int LinkedList::createLinkedList(std::string name, long phoneNumber) {
	if (!pHead) {
		pHead = new Node(name, phoneNumber, NULL);
		if (!pHead) {
			return -1;
		}
		size = 1;
		return 0;
	}
	else {
		return -1;
	}
}

int LinkedList::addHead(std::string name, long phoneNumber)
{
	if (!pHead) {
		return -1;
	}
	else {
		Node* pNode = new Node(name, phoneNumber, pHead);
		pHead = pNode;
		++size;
		return 1;
	}
}

int LinkedList::deleteHead() {
	if (!pHead) {
		return -1;
	}
	else {
		Node* pDel = pHead;
		pHead = pHead->getNextPointer();
		pDel->setNextPointer(NULL);
		delete pDel;
		pDel = NULL;
		--size;
		return 1;
	}
}

void LinkedList::printHeadNode() {
	pHead->printInfo();
}

Node* LinkedList::seekHeadNode() {
	return pHead;
}

Node* LinkedList::seekNode(int index) {
	if (index >= size) {
		return NULL;
	}
	else if (index == 0) {
		return pHead;
	}
	else {
		Node *pTemp{ pHead };
		for (int i{ 0 }; i < index; i++) {
			pTemp = pTemp->getNextPointer();
		}
		return pTemp;
	}

}

Node* LinkedList::operator[](int index) {
	if (index >= size) {
		return NULL;
	}
	Node* pTemp = this->pHead;
	for (int i{ 0 }; i < index; i++) {
		pTemp = pTemp->getNextPointer();
	}
	return pTemp;
}

int LinkedList::addTail(std::string name, long phoneNumber) {
	Node * pTemp = pHead;
	while (pTemp->getNextPointer() != NULL) {
		pTemp = pTemp->getNextPointer();
	}
	pTemp->setNextPointer(name, phoneNumber);
	++size;
	return 1;
}

Node * LinkedList::getHeadPointer()
{
	return this->pHead;
}

int LinkedList::getSize()
{
	return this->size;
}

LinkedList::LinkedList() {
	pHead = NULL;
	size = 0;
}

/* Hash class code block */

int Hash::hashFunction(long key)
{
	return key % 5;
}

Hash::Hash()
{

}

int Hash::insert(std::string name, long phoneNumber)
{
	int hash{ hashFunction(phoneNumber) };
	
	if (this->hashTable[hash].getHeadPointer() == NULL) {
		hashTable[hash].createLinkedList(name, phoneNumber);
		return 1;
	}
	hashTable[hash].addTail(name, phoneNumber);
	return 1;
}

