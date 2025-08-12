#include <iostream>
#include <stdexcept>
/*
Dynamic memory allocation practice with linkedlist from scratch
We get to determine the length of the list in real time! 
Try to implement try catch statements. 
Singly Linked List
*/
template <typename temp>
struct Node {
	temp item; //The node's respective value (data that is being stored) 
	Node<temp>* link; //Pointer to the next node in the LL.

	Node(temp value) {
		item = value;
		link = nullptr; //Initialize first node link to null pointer. 
	}
};

template <typename temp>
class LinkedList {
private:
	Node<temp>* head; //first node
	Node<temp>* tail; //last node. 
	int len = 0; //tot. num of obj. in LL. 

public:

	LinkedList() {
		head = nullptr;
		tail = nullptr;
		len = 0;
	}

	~LinkedList() {
		Node<temp>* currentNode = head;
		while (currentNode != nullptr) {
			Node<temp>* nextNode = currentNode->link; //Store the next node
			delete currentNode; //Delete the current node
			currentNode = nextNode; //Move to the next node
		}
		head = nullptr;
		tail = nullptr;
		len = 0; //Reset length
	}

	int getLength() {
		return len;
	}

	bool isEmpty() {
		if (!len) {
			return true;
		}
		else {
			return false;
		}
	}
	
	temp getHead() {
		if (head != nullptr) {
			return head->item;
		}
		else {
			std::cout << "LinkedList is empty";
			return 0;
		}
	}

	temp getTail() {
		if (tail != nullptr) {
			return tail->item;
		}
		else {
			std::cout << "LinkedList is empty";
			return 0;
		}
	}

	void push_back(temp item) {
		/*
		* append element to back of list. 
		*/
		Node<temp>* newNode = new Node<temp>(item);
		if (len == 0) {
			head = tail = newNode;
		}
		else {
			Node<temp>* currentNode = tail;
			currentNode->link = newNode;
			tail = newNode;
		}
		len = len + 1;
	}

	void push_front(temp item) {
		Node<temp>* newNode = new Node<temp>(item);
		if (len == 0) {
			head = tail = newNode;
		}
		else {
			newNode->link = head;
			head = newNode;
		}
		//update len
		len = len + 1;
	}
	
	void remove_last() {
		if (len == 0) {
			throw std::runtime_error("Out Of range - empty List");
		}
		if (len == 1) {
			delete head;
			head = tail = nullptr;
		}
		else {
			Node<temp>* currentNode = head;
			while (currentNode->link != tail) {
				currentNode = currentNode->link;
			}
			//break out of loop when currentNode is the second last node.
			tail = currentNode;
			delete currentNode->link; //deletes the last node. 
			currentNode->link = nullptr; //last node link points to null. 
		}
	}

	void remove_first() {
			if (len == 0) {
				throw std::runtime_error("Out Of Range");
			}
			if (len == 1) {
				delete head;
				head = tail = nullptr;
			}
			else {
				Node<temp>* NewHead = head->link;
				delete head;
				head = NewHead;
			}
			len = len - 1;
		}
};
	
int main() {
	LinkedList <int> TestEmpty; //LinkedList Object to test remove from empty list.

	try {
		TestEmpty.remove_last();
	}
	catch(const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	LinkedList<int> TestRemoveOne; //LinkedList Object to test removing one element (check empty).

	TestRemoveOne.push_back(10);
	TestRemoveOne.remove_first();
	TestRemoveOne.push_back(20);
	TestRemoveOne.remove_last();
	std::cout << TestRemoveOne.isEmpty() << "---- If empty, value should be 1" << std::endl;

	LinkedList<int> TestLargeList; //Test push front and back. Also Remove from larger list. 

	TestLargeList.push_back(10);
	TestLargeList.push_back(20);
	TestLargeList.push_front(0);
	TestLargeList.push_back(30);
	TestLargeList.remove_first(); //removes 0
	TestLargeList.remove_last(); //removes 30

	std::cout << TestLargeList.getHead() << " -- Head should be 10" << std::endl; //Head should now be 10
	std::cout << TestLargeList.getTail() << " -- Tail should be 20" << std::endl; //Tail hould be 20
}
