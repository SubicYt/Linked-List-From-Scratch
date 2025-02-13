class Node:
    
    def __init__(self, item, link = None):
        """
        Initializes the Node objects
        """
        self.item = item
        self.link = link
    
    def __repr__(self):
        """
        gives string of node(item)
        """
        return str(f"Node({self.item})")

class LinkedList:
    _head: Node
    _tail: Node
    _len: int

    def __init__(self, items = None):
        """Initializes the _head, _tail, and the _len properties"""
        self._head = None
        self._tail = None
        self._len = 0

        if items != None:
            for item in items:
                self.add_last(item)

    def __len__(self):
        """Current length of your linked list"""
        return self._len

    def get_head(self):
        """get the item in the _head node"""
        if self._head:
            return self._head.item
        return None

    def get_tail(self):
        """get the item in the _tail node"""
        if self._tail:
            return self._tail.item
        return None

    def add_last(self, item = None):
        """Adds element to the end of linkedlist """
        newNode = Node(item)
        if len(self) == 0:
            self._head = self._tail = newNode
        else:
            #Link tail should point to new link
            current_node = self._tail
            current_node.link = newNode
            #update our new tail node
            self._tail = newNode
        #increment the length
        self._len+=1

    def add_first(self, item = None):
        """Adds element to the beginning of the linked list, updates new head of linked list"""
        newNode = Node(item)
        if len(self) == 0:
            self._head = self._tail = newNode
        else:
            #The link of the new node should be the current head
            newNode.link = self._head
            #Update the new head to the new node
            self._head = newNode
        #Update the length of the new Node. 
        self._len+=1
            


    def remove_last(self):
        """removes the last node if present"""
        if len(self)==0:
            raise RuntimeError("Cannot remove from empty list")
        else:
            prev, curr=None, self._head
            while curr != self._tail:
                prev = curr
                curr = curr.link         
            prev.link = None
            self._tail = prev

            if not prev:
                self._head = None
            self._len -=1
            return curr.item

    def remove_first(self):
        """
        Removes the first element of a linked list and updates the new head.
        """
        if len(self) ==0:
            raise RuntimeError("Cannot remove from empty list")
        else:
            prevHead = self._head
            self._head = prevHead.link
            if self._head is None:
                self._tail = None
            self._len -= 1
        
        return prevHead.item
