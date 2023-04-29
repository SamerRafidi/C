/*
 * SLLSet.cpp
 *
 *  Created on: Decemeber 8th, 2021
 *      Author: Samer Rafidi
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet(){
	size = 0;
	head = NULL;
}
SLLSet::SLLSet(int sortedArray[], int arrSize){
	//	Initialized variables
	size = arrSize;
	head = NULL;
	//	Iterated through for loop to create each node
	for (int i = size-1; i>=0; i--){
		//	Initializing new node structure
		SLLNode* node = new SLLNode;
		//	Assigning value of node to its sortedArray value
		node->value = sortedArray[i];
		//	Assigning the next pointer
		node->next = head;
		head = node;
	}
	
}
int SLLSet::getSize()
{
	return size;
}

SLLSet SLLSet::copy(){
	//	Initialized variables
	SLLNode* temp = head;
	int arr[size];
	//	Iterated through for loop to set values for arr at index i
	for (int i=0; i<size; i++) {
		arr[i] = temp->value;
		// next node is pointing at temp
		temp = temp->next;
	}
	return *(new SLLSet(arr,size));
}

bool SLLSet::isIn(int v){
	//	Initialized variable
    SLLNode* temp = head;
    //	Iterated through for loop to check if any element in SLLSet is equal to v
    for (int i=0; i<size; i++) {
    	if (temp->value == v) {
    		return true;
    	}
    	temp = temp->next;
    }
	return false;
}
void SLLSet::add(int v){
	//	Initialized variable
	SLLNode* newNode = head;
	//	Checking if v is already in the set
	if(isIn(v) == false) {
		//	Check if set is empty
    	if(newNode == NULL) {
    		//	Initialized a new node
    		SLLNode* temp1 = new SLLNode(v,NULL);
    		newNode = temp1;
    	}
    	//	Accounting for when the value to be added is at the beginning of the set
    	else if(newNode->value > v){
    		//	Initialized a new node with value and next pointer to the current head
    	    SLLNode* temp2 = new SLLNode(v,newNode);
    	    head = temp2;
    	}
    	else {
    		//	Iterating through each node
    		while (newNode->next!=NULL) {
    			//	Finding the correct location for the added value
    			if (newNode->value < v && newNode->next->value > v){
    				//	Initialized a new node with the value, pointing to the next node
    				SLLNode* temp3 = new SLLNode(v,newNode->next);
    				newNode->next = temp3;
    			}
    			//	If the condition above is not met, move on to next node
    			else {
    				newNode = newNode->next;
    			}
    		}
    		if(newNode->value < v){
    			//	Initialized a new node with the value v, which points to NULL
    			SLLNode* temp4 = new SLLNode(v,NULL);
    			newNode->next = temp4;
    		}
    	}
    //size is incremented by 1
    size+=1;
	}
}

void SLLSet::remove(int v){
	//	Checking if v is already a part of the set, if so it can be properly removed
	if(isIn(v) == true) {
		//	Initialized new node
		SLLNode* temp = head;
		//	If v is equal to the value at head, then it is removed
		if (v == head->value) {
			head = head->next;
			//	Size is decreased by 1 to consider for the value that is removed
			size -= 1;
		}
		//	Created while loop to update the temp pointer for the next node
		while (temp !=NULL && temp->next != NULL) {
			//	Checking if the correct node is found, if so the previous pointer is changed to point at the next node, skipping the removed value
			if ((temp->next)->value == v) {
				temp->next = (temp->next)->next;
				size -= 1;
			}
			//	This code is ran if the condition above is not met
			else {
				temp = temp->next;
			}
		}
	}
}
SLLSet SLLSet::setUnion(SLLSet s){
	// Initialized variables
	SLLNode* nodeUnion = new SLLNode();
	SLLSet* setUnion = new SLLSet();
	setUnion->head = nodeUnion;
	int sizeCount = 0;
	// Tracks the node address
	SLLNode* unionSetAdd = setUnion->head;
	SLLNode* oldSetAdd = head;
	SLLNode* newSetAdd = s.head;
	for(int i=0; i<size+s.getSize(); i++) {
		// If oldSetAdd is NULL, add all values from the set
		if(oldSetAdd == NULL){
			// Keep adding the values until the set does not equal NULL
			if(newSetAdd != NULL){
				// Current union set value is set equal to the current new set value
				unionSetAdd->value = newSetAdd->value;
				newSetAdd = newSetAdd->next;
				sizeCount += 1;
			}
		}
		// This occurs if the new set is equal to NULL instead of the old set
		else if(newSetAdd == NULL){
			if(oldSetAdd != NULL){
				unionSetAdd->value = oldSetAdd->value;
				oldSetAdd = oldSetAdd->next;
				sizeCount += 1;
			}
		}
		// Makes sure that the lower value is added to unionSet first
		else if(oldSetAdd->value < newSetAdd->value){
			unionSetAdd->value = oldSetAdd->value;
			// Next value is updated
			oldSetAdd = oldSetAdd->next;
			sizeCount += 1;
		}
		// the opposite case occurs to ensure the lower value is added to unionSet first
		else if(oldSetAdd->value > newSetAdd->value){
			unionSetAdd->value = newSetAdd->value;
			newSetAdd = newSetAdd->next;
			sizeCount += 1;
		}
		// Adding value when both oldSet values are equal
		else if(oldSetAdd->value == newSetAdd->value){
			// Updated unionSet with equal value
			unionSetAdd->value = oldSetAdd->value;
			oldSetAdd = oldSetAdd->next;
			newSetAdd = newSetAdd->next;
			sizeCount += 1;
		}
		if(oldSetAdd == NULL && newSetAdd == NULL){
			break;
		}
		// Initialized a new node in unionSet for the next value
		SLLNode* nextUnionNode = new SLLNode();
		unionSetAdd->next = nextUnionNode;
		unionSetAdd = nextUnionNode;
	}
	// Accounting for when there is no union between the sets
	if(sizeCount == 0){
		// Deleting the first created node union as we will not be using it.
		delete nodeUnion;
		setUnion->head = NULL;
		setUnion->size = 0;
		return *setUnion;
	}
	unionSetAdd->next = NULL;
	// Updating the size of unionSet
	setUnion->size = sizeCount;
	return *setUnion;
}
SLLSet SLLSet::intersection(SLLSet s){
	//	Initialized intersection set
	SLLSet* setInter = new SLLSet();
	//	If the current set is empty. The intersection set will be returned
	if (head == NULL) {
		return *setInter;
	}
	//	If the s set is empty, The intersection set will be returned
	if (s.head == NULL) {
		return *setInter;
	}
	//	Initialized node and set it equal to head
	SLLNode* temp = head;
	//	Created while loop to iterate through each node
	while (temp!= NULL) {
		//	If temp-> value is not an element in s set, then it is removed
		if (s.isIn(temp->value) == false) {
			remove(temp->value);
		}
		//	Pointer is updated
		temp = temp->next;
	}
	if (head == NULL) {
		return *setInter;
	}
	*setInter = copy();
	return *setInter;
}
SLLSet SLLSet::difference(SLLSet s){
	//	Initialized variable
	SLLSet *setDiff = new SLLSet();
	//	If the head points to NULL. The set difference will be returned
	if (head == NULL) {
		return *setDiff;
	}
	//	If the s.head points to NULL. The set difference will be returned
	if (s.head == NULL) {
		*setDiff = copy();
		return *setDiff;
	}
	//	temp node is initialized and set equal to head
	SLLNode *temp = head;
	//	Created while loop to iterate through each node
	while (temp != NULL) {
		//	If the value at any node is an element of set s, then it is removed
		if (s.isIn(temp->value) == true) {
			remove (temp->value);
		}
		temp = temp->next;
	}
	//	If the given node points to NULL. The set difference will be returned
	if (head == NULL) {
		return *setDiff;
	}
	*setDiff = copy();
	 return *setDiff;
}
SLLSet SLLSet::setUnion(SLLSet sArray[],int size){
	//	Initialized variable
	SLLSet* setUnion = new SLLSet();
	//	Created for loop to iterate through sArray
	for (int i=0; i<size; i++) {
		//	Updated setUnion
		*setUnion = (*setUnion).setUnion(sArray[i]);
	}
	return *setUnion;
}
string SLLSet::toString(){
	//	Initialized variable
	SLLNode *temp = head;
	string output = "";
	//	Created for loop to iterate through each node
	for (int i=0; i<size; i++) {
		//	Elements are converted to strings and added to output
		output += to_string(temp->value);
		temp = temp->next;
		//	Adding ", " between each element
		if (temp!=NULL) {
			output += ", ";
		}
	}
	return output;
}


