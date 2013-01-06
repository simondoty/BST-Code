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

# test
newNode = Node("simon")
print newNode
print newNode.left
newNode = Node("simon2", newNode)
print newNode
print newNode.left
print newNode.right
newNode2 = Node(3, newNode)
print newNode.getInfo()
print newNode2.getInfo()
print 3