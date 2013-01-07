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

	

# test
tree = BSTPython()
print tree.size
print tree.root
tree.add(5)
print tree.root.getInfo()
print tree.root
print tree.add(8)
print tree.root.getRight()
print tree.root.getLeft()