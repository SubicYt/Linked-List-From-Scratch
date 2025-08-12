#include <iostream>
#include <stdexcept>
/*
Dynamic memory allocation practice with linkedlist from scratch
We get to determine the length of the list in real time! 
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
		if (len == 0 && !head) {
			std::cout << "Invalid operation";
		}
		if (len == 1) {
			delete head;
			head = tail = nullptr; 
		}
		else {
			Node<temp>* currentNode = head;
			while (currentNode->link != tail) {
				currentNode = currentNode->link; //Loop until pointer points to the tail Node
			}
			tail = currentNode;
			currentNode->link = nullptr;
		}
		len = len - 1;
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
				head = NewHead;
			}
			len = len - 1;
		}
};
	
int main() {
	LinkedList<int> LinkedList1;
	LinkedList1.push_back(6);
	LinkedList1.remove_first();
	std::cout << LinkedList1.getLength();
}
