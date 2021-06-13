from Gates import *

Gates = Gates()

class Binary:

    def __init__(self, num):
        self.list = [int(char) for char in num]

    def halfadder(self, a, b):
        return Gates.XOR(a, b), Gates.AND(a, b)

    def fulladder(self, a, b, c):
        s0, c0 = self.halfadder(a, b)
        s1, c1 = self.halfadder(s0, c)
        return s1, Gates.OR(c0, c1)

    def __str__(self):
        return ''.join([str(elem) for elem in self.list])

    def __add__(self, other):
        #difference in number of bits
        bitdif = len(self.list)-len(other.list)
        if bitdif > 0:
            length=len(self.list)
            for i in range(bitdif):       
                other.list.insert(0,0)
        else:
            length = len(other.list)
            for i in range(abs(bitdif)):  
                self.list.insert(0,0)
        
        #initializing carry with 0
        c = 0
        sum =[]
        for i in range(length-1,-1,-1):
            s,c = self.fulladder(self.list[i],other.list[i],c)
            sum.append(s)
        sum.append(c)
        return Binary(reversed(sum))


A = Binary("1111")
B = Binary("1111")

print("A = ", end=''),print(A)

print("B = ",end=''),print(B)

print("A + B = ",end=''),print(A+B)


