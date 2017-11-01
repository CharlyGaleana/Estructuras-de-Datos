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
		parent = (pos - 1) / 2
		while pos > 0 and self.datos[parent] > e:
			self.datos[pos] = self.datos[parent]
			pos = parent
			parent = (pos - 1) / 2
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
			print(datos[i]),
		print("\n")

	def top(self):
		return datos[0]
	
	def empty(self):
		if size == 0 :
			return 1
		return 0

heap = Heap()

datos = [2, 4, 3, 6, 5]

for i in datos:
	heap.push(i)

heap.printHeap()	
	
for i in range(len(datos)):
	print (heap.pop()),
