from Gates import *

Gates = Gates()

class Binary:

    def __init__(self, num):
        self.list = [int(char) for char in num]

    def halfsubtractor(self, a, b):
        return Gates.XOR(a, b), Gates.AND(Gates.NOT(a), b)

    def fullsubtractor(self, a, b, bw):
        s0, bw0 = self.halfsubtractor(a, b)
        s1, bw1 = self.halfsubtractor(s0, bw)
        return s1, Gates.OR(bw0, bw1)

    def __str__(self):
        return ''.join([str(elem) for elem in self.list])

    def sub(self, other):
        #difference in number of bits
        diff = len(self.list)-len(other.list)
        if diff > 0:
            for i in range(diff):
                other.list.insert(0,0)
        else:
            for i in range(abs(diff)):
                self.list.insert(0,0)
        
        #initializing carry with 0
        bw = 0
        sum =[]
        for i in range(len(self.list)-1,-1,-1):
            s,bw = self.fullsubtractor(self.list[i],other.list[i],bw)
            sum.append(s)
        print("Borrow = ", end=''),print(bw)
        return Binary(reversed(sum))

#Enter both number of equal bits
A = Binary("111")
B = Binary("1000")


print("A = ", end=''),print(A)

print("B = ",end=''),print(B)
Res=A.sub(B)

print("A - B = ",end=''),print(Res)

# A = 111
# B = 1000
# Borrow = 1
# A - B = 1111
