"""
Exercise in implementing a Binary Search Tree in python.
by simon doty, 1/2013

"""

class Node:

	# define a node constructor that takes value variable
	def __init__(self, info, left = None, right = None):
		self.info = info
		if left is None:
			self.left = None
		else:
			self.left = left
		if right is None:
			self.right = None
		else:
			self.right = right

	
	# return string rep of info in node
	def __str__(self):
		return str(self.info)

	# return the data attribute info
	def getInfo(self):

		return self.info

	# set info of node
	def setInfo(self, info):
		self.info = info

	# return left child
	def getLeft(self):
		return self.left

	# return right child
	def getRight(self):
		return self.right

	# set left child
	def setLeft(self, newLeft):
		self.left = newLeft

	# set right child
	def setRight(self, newRight):
		self.right = newRight



"""
Implementation of the Binary Search Tree with methods Add, Remove
and isPresent. 
Data members included are root node, and size.
"""

class BSTPython:

	def __init__(self):
		self.root = None
		self.size = 0

	# Add node to 
	def add(self, info):
		if self.size == 0:
			self.root = Node(info)
			self.size = 1
		else:
			# call recursive add helper
			self.root = self.recursiveAdd(self.root, info)

	#recursive helper for add method
	def recursiveAdd(self, node, info):
		if node is None:
			self.size = self.size + 1
			newNode = Node(info)
			return newNode
		if info < node.getInfo():
			node.setLeft(self.recursiveAdd(node.getLeft(), info))
		elif info > node.getInfo():
			node.setRight(self.recursiveAdd(node.getRight(), info))
		else:
			return node
		return node

	# Remove node if present
	def remove(self, info):
		if self.size == 0:
			print "Tree is empty"
			return None
		self.root = self.recursiveRemove(self.root, info)

	# recursiveRemove helper method
	def recursiveRemove(self, node, info):
		if node is None:
			return None
		if info < node.getInfo():
			node.setLeft(self.recursiveRemove(node.getLeft(), info))
		elif info > node.getInfo():
			node.setRight(self.recursiveRemove(node.getRight(), info))
 		else:
 			self.size = self.size - 1
 			if node.getRight() is None and node.getLeft() is None:
 				node = None
 			elif node.getLeft() is None: # there is a right child
 				node = node.getRight()
 			elif node.getRight() is None:
 				node = node.getLeft()
 			else:
 				self.size = self.size + 1
 				node.setInfo(self.max(node.getLeft()))
 				node.setLeft(self.recursiveRemove(node.getLeft(), node.getInfo()))
 		return node
	
	# Max helper method for remove algorithm
	def max(self, node):
		while node.getRight() is not None:
			node = node.getRight()
		return node.getInfo()

	# isPresent method to check if value is in tree already
	def isPresent(self, info):
		if self.size == 0:
			return False
		temp = self.root
		while temp is not None:
			tempInfo = temp.getInfo()
			print "printing tempInfo: " + str(tempInfo) + " and info: " + str(info)
			if tempInfo == info:
				return True
			elif tempInfo < info:
				temp = temp.getRight()
			else:
				temp = temp.getLeft()
		return False


	# PrintTree method
	def printTree(self):
		self.printTreeInOrder(self.root, "")
	def printTreeInOrder(self, node, spaces):
		if node is not None:
			self.printTreeInOrder(node.getRight(), spaces + "  ")
			print spaces + str(node)
			self.printTreeInOrder(node.getLeft(), spaces + "  ")





# test
tree = BSTPython()
print "Tree size is: " + str(tree.size)
print "Adding 5"
tree.add(5)
print "Printing Tree with 5"
tree.printTree()
print "Tree size is: " + str(tree.size)
print "Adding 10"
tree.add(10)
tree.printTree()
print "Adding 3"
tree.add(3)
print "Tree size is: " + str(tree.size)
tree.printTree()
tree.add(15)
tree.printTree()
tree.add(12)
tree.printTree()
print ""
tree.remove(5)
tree.printTree()
print "5 is present: " + str(tree.isPresent(5))
print "15 is present: " + str(tree.isPresent(15))
print tree.size
