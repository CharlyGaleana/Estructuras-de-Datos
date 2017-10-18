class pila:
    size = 0
    datos = []
    def _init_(self):
        self.datos = []
        self.size = 0
    def push(self, e):
        self.datos=[e]+self.datos
        self.size += 1
    def pop(self):
        if self.size > 0:
            elem =self.datos[0]
            self.datos = self.datos[1:]
            return elem

miPila = pila()

miPila.push(4)
miPila.push(5)
miPila.push(6)

print (miPila.pop())