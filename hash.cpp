#include "hash.h"

/* node class code block */
/*
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

Node*& Node::getNextPointer()
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

*/

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
		pHead = pHead->pNext;
		pDel->pNext = NULL;
		delete pDel;
		pDel = NULL;
		--size;
		return 1;
	}
}

int LinkedList::deleteTail()
{
	Node * pTemp = pHead;
	while (pTemp->pNext->pNext != NULL) {
		pTemp = pTemp->pNext;
	}
	Node * pDel = pTemp->pNext;
	delete pDel;
	pDel = NULL;
	pTemp->pNext = NULL;
	--size;
	return 1;
}
/*
void LinkedList::printHeadNode() {
	pHead->printInfo();
}
*/

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
			pTemp = pTemp->pNext;
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
		pTemp = pTemp->pNext;
	}
	return pTemp;
}

int LinkedList::addTail(std::string name, long phoneNumber) {
	Node * pTemp = pHead;
	while (pTemp->pNext != NULL) {
		pTemp = pTemp->pNext;
	}
	pTemp->pNext = new Node(name, phoneNumber);
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

void LinkedList::setSize(int value)
{
	this->size = this->size + value;
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

bool Hash::findKey(std::string name, long phoneNumber)
{
	int hash{ hashFunction(phoneNumber) };

	if (hashTable[hash].getSize() == 0) {
		return false;
	}

	Node* pTemp = hashTable[hash].getHeadPointer();
	while (pTemp != NULL) {
		if (pTemp->contact.name == name) {
			return true;
		}
		pTemp = pTemp->pNext;
	}
	return false;
}

Node * Hash::findDeleteKey(std::string name, long phoneNumber)
{
	int hash{ hashFunction(phoneNumber) };

	if (hashTable[hash].getSize() == 0) {
		return NULL;
	}

	Node* pTemp = hashTable[hash].getHeadPointer();
	while (pTemp != NULL) {
		if (pTemp->contact.name == name) {
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	return NULL;
}

int Hash::deleteKey(std::string name, long phoneNumber)
{
	if (!findKey(name, phoneNumber)) {
		return -1;
	}
	int hash{ hashFunction(phoneNumber) };

	Node* pTemp{ hashTable[hash].getHeadPointer() };
	if (pTemp->contact.name == name) {
		hashTable[hash].deleteHead();
		return 1;
	}

	if (pTemp->pNext->pNext == NULL && pTemp->pNext->contact.name == name ) {
		hashTable[hash].deleteTail();
		return 1;
	}

	while (pTemp->pNext != NULL) {
		if (pTemp->pNext->contact.name == name) {
			Node* pDel = pTemp->pNext;
			pTemp->pNext = pTemp->pNext->pNext;
			delete pDel;
			pDel = NULL;
			hashTable[hash].setSize(-1);
			return 1;
		}
		pTemp = pTemp->pNext;
	}
}
