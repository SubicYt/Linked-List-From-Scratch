import unittest
from linkedlist import *

class TestNode(unittest.TestCase):
    
    def test_init(self):
        node1 = Node(1)
        node2 = Node(2)
        node3 = Node(3, node2)
        
        self.assertEqual(node1.item, 1)
        self.assertEqual(node2.item, 2)
        self.assertEqual(node2.link, None)
        self.assertEqual(node3.link, node2)
    
    def test_repr(self):
        node1 = Node(10)
        self.assertEqual(repr(node1), "Node(10)")

class TestLinkedList(unittest.TestCase):

    def test_init(self):
        linkedList = LinkedList()

        self.assertEqual(linkedList.get_head(), None)
        self.assertEqual(linkedList.get_tail(), None)
        self.assertEqual(len(linkedList), 0)

    def test_add_last(self):

        linkedList = LinkedList()
        linkedList.add_last("A")
        linkedList.add_last("B")
        linkedList.add_last("C")
        linkedList.add_last("D")

        self.assertEqual(linkedList.get_head(), "A")
        self.assertEqual(linkedList.get_tail(), "D")

    def test_remove_last(self):

        linkedList = LinkedList()
        linkedList.add_last("A")
        linkedList.add_last("B")
        linkedList.add_last("C")
        linkedList.add_last("D")

        self.assertEqual(linkedList.get_head(), "A")
        self.assertEqual(linkedList.get_tail(), "D")

        linkedList.remove_last()

        self.assertEqual(linkedList.get_tail(),"C")

    def test_add_first(self):
        linkedList = LinkedList()
        """
        linkedList.add_last("A")
        linkedList.add_last("B")
        linkedList.add_last("C")
        linkedList.add_last("D")
        linkedList.add_first("X")
        """
        items = ["A","B","C","D"]
        for item in items:
            linkedList.add_first(item)

        self.assertEqual(linkedList.get_head(), "D")
        self.assertEqual(linkedList.get_tail(), "A")

        linkedList.remove_last()

        self.assertEqual(linkedList.get_tail(),"B")

    def test_remove_first(self):

        linkedList = LinkedList()
        linkedList.add_last("A")
        linkedList.add_last("B")
        linkedList.add_last("C")
        linkedList.add_last("D")

        self.assertEqual(linkedList.get_head(), "A")
        self.assertEqual(linkedList.get_tail(), "D")

        linkedList.remove_first()

        self.assertEqual(linkedList.get_head(),"B")

        linkedList2 = LinkedList()
        linkedList2.add_last("A")

        linkedList2.remove_first()
        self.assertEqual(linkedList2.get_head(), None)
if __name__ == "__main__":
    unittest.main()
