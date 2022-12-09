#pragma once
#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


using namespace std;

template <typename nodetype> class LinkedList {
//private:
public:
	nodetype data;
	LinkedList* nextNode;
	int size{};

public: 
	//constructors 
	LinkedList() {
		data = NULL;
		nextNode = nullptr;
	}

	LinkedList(nodetype& headValue) {
		data = headValue;
		nextNode = nullptr;
		size = 1;
	}

	LinkedList(LinkedList& list) {
		if (list.isEmpty()) {
			data = NULL;
			nextNode = nullptr;
			return;
		}

		data = list.get();
		LinkedList* traverseThis = this;
		LinkedList* traverseList = list.nextNode;

		while (traverseList != nullptr) {
			traverseThis->nextNode = new LinkedList(list.nextNode->data);
			

			//updating the traverses 
			traverseThis = traverseThis->nextNode;
			traverseList = traverseList->nextNode;
		}

		size = list.size();
	}

	LinkedList(int* nums, int numsSize) {
		for (int i = num - Size - 1; i > -1; i--) {
			add(nums[i], 0);
		}
	}


	//modifying the list 

	void add(nodetype value) {
		if (nextNode == nullptr) {
			nextNode = new LinkedList(value);
			size++;
		}

		nextNode->add(value);
	}

	void add(nodetype value, int index) {
		if (index > (size + 1)) {
			// out of bounds error TODO
			return;
		}

		if (index == 0) {
			this->nextNode = this;
			this->data = value;
		}
		else {
			LinkedList* traverser = this;

			for (int i{ 1 }; i < index; i++) {
				traverser = traverser->nextNode;
			}

			LinkedList* node = new LinkedList(value);
			node->nextNode = traverser->nextNode;
			traverser->nextNode = node;
		}

		size++;
	}

	void deleteNode(int index) {
		if (index > (size + 1)) {
			// out of bounds error TODO
			return;
		}

		if (index == 0) {
			this->data = this->nextNode->data;
			this->nextNode = this->nextNode->nextNode;

			// bad memory allocation TODO
		}

		LinkedList* traverse = nextNode;

		for (int i{ 1 }; i < index; i++) {
			traverse = traverse->nextNode;
		}

		traverse->data = traverse->nextNode->data;
		traverse->nextNode = traverse->nextNode->nextNode;

		// bad memory allocation TODO
	}


	//get Functions
	nodetype get() {
		return data;
	}

	nodetype get(int index) {
		if (index > (size + 1)) {
			// out of bounds error TODO
			return NULL;
		}
		if (index == 0) {
			return get();
		}

		LinkedList* traverse = nextNode;

		for (int i{ 1 }; i < index; i++) {
			traverse = traverse->nextNode;
		}

		return traverse->data;

	}

	int size() {
		return size;
	}

	// bool functions 
	bool isEmpty() {
		if (data == NULL) {
			return true;
		}

		return false;
	}


};

#endif
