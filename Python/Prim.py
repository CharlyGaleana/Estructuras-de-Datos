import math

class Heap:
	size = 0
	datos = []
	def _init_(self):
		self.datos = []
		self.size = 0
		
	def push(self, e):
		self.datos=self.datos + [e]
		pos = self.size
		self.size += 1
		parent = math.floor( (pos - 1) / 2 )
		while pos > 0 and self.datos[parent] > e:
			self.datos[pos] = self.datos[parent]
			pos = parent
			parent = math.floor( (pos - 1) / 2 )
		self.datos[pos] = e
		
	def pop(self):
		if self.size <= 0:
			return
		ret = self.datos[0]
		self.size -= 1
		e = self.datos[self.size]
		
		pos = 0
		leftC = pos * 2 + 1
		rightC = leftC + 1
		minC = 0
		if rightC >= self.size or self.datos[leftC] < self.datos[rightC]:
			minC = leftC
		else:
			minC = rightC
		
		while minC < self.size and self.datos[minC] < e:
			self.datos[pos] = self.datos[minC]
			pos = minC
			leftC = pos * 2 + 1
			rightC = leftC + 1
			if rightC >= self.size or self.datos[leftC] < self.datos[rightC]:
				minC = leftC
			else:
				minC = rightC
		
		self.datos[pos] = e
		return ret
		
	def printHeap(self):
		for i in range(self.size):
			print(self.datos[i]),
		print("\n")

	def top(self):
		return datos[0]
	
	def empty(self):
		if self.size == 0 :
			return 1
		return 0

heap = Heap()
vis = set()

edges = [ ('A', 'B', 10), ('C', 'A', 12), ('C', 'B', 9), ('B', 'D', 8), ('C', 'E', 3), ('D', 'E', 7), ('C','F', 1), ('F', 'E', 3), ('F', 'H', 6), ('H', 'D', 5), ('D', 'G', 8), ('G', 'H', 9), ('G', 'I', 2), ('H', 'I', 11)  ];
nodes = [ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' ]
E = {}

for node in nodes:
	E[node] = []
	
for edge in edges:
	E[edge[0]].append( (edge[2], edge[1]) )
	E[edge[1]].append( (edge[2], edge[0]) )

MST = []
heap.push( (0, nodes[0], nodes[0]) )
cost = 0

while not heap.empty():
	newEdge = heap.pop();
	node = newEdge[1];
	parent = newEdge[2];
	if not node in vis:
		vis.add(node)
		cost += newEdge[0];
		if node != parent:
			MST.append(newEdge)
		
		for edge in E[node]:
			if edge[1] not in vis:
				heap.push( (edge[0], edge[1], node) )

print(cost)
print(MST)
