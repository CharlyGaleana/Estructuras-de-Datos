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

	def top(self):
		return datos[0]
	
	def empty(self):
		if size == 0 :
			return 1
		return 0

heap = Heap()

datos = [6, 12, 13, 1, 4, 3, 2, 34, -2, 9, 7, 2, 10, 29, 7, 98, 0, 15, -1, 31, 23, 100]

for i in datos:
	heap.push(i)

for i in range(len(datos)):
	print (heap.pop())
 