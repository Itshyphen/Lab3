# from Gates import *

# Gates = Gates()

# class Binary:

#     def __init__(self, num):
#         self.list = [str(char) for char in num]
#         self.num = int(self.__str__())

#     def halfadder(self, a, b):
#         return Gates.XOR(a, b), Gates.AND(a, b)

#     def fulladder(self, a, b, c):
#         s0, c0 = self.halfadder(a, b)
#         s1, c1 = self.halfadder(s0, c)
#         return s1, Gates.OR(c0, c1)
    



#     def __str__(self):
#         return ''.join([str(elem) for elem in self.list])

#     def __add__(self, other):
        #difference in number of bits
        # bitdif = len(self.list)-len(other.list)
        # if bitdif > 0:
        #     length=len(self.list)
        #     for i in range(bitdif):       
        #         other.list.insert(0,0)
        # else:
        #     length = len(other.list)
        #     for i in range(abs(bitdif)):  
        #         self.list.insert(0,0)
        
        # #initializing carry with 0
        # c = 0
        # sum =[]
        # for i in range(length-1,-1,-1):
        #     s,c = self.fulladder(self.list[i],other.list[i],c)
        #     sum.append(s)
        # # sum = reversed(sum)
        # # if self.num < other.num:
        # #     sum = self.twoscomplement(sum)
        # # sum.append(c)
        # return Binary(reversed(sum))


from Gates import *

Gates = Gates()

class Binary:

    def __init__(self, num):
        self.list = [int(char) for char in num]
        self.num = int(self.__str__())

    def halfadder(self, a, b):
        return Gates.XOR(a, b), Gates.AND(a, b)

    def fulladder(self, a, b, c):
        s0, c0 = self.halfadder(a, b)
        s1, c1 = self.halfadder(s0, c)
        return s1, Gates.OR(c0, c1)

    def __str__(self):
        return ''.join([str(elem) for elem in self.list])

    def twoscomplement(self,bits) :
        l = len(bits) - 1
        bits = [Gates.XOR(i,1) for i in bits]

        for i in range(l,-1,-1):
            if bits[i] == 0:
                bits[i] = 1
                break

            else:
                bits[i] = 0
                if(i == l):
                    bits.insert(0,1)
        return bits

    def __sub__(self, other):
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
        c = 1
        sum =[]
        for i in range(length-1,-1,-1):
            s,c = self.fulladder(self.list[i],Gates.XOR(other.list[i],1),c)
            sum.append(s)
        sum = sum[::-1]
        if self.num < other.num:
            print("1",end='')
            sum = self.twoscomplement(sum)
        else:
            print('0')

        # sum.append(c)
        return Binary(sum)


A = Binary("1111")
B = Binary("10000")

print("A = ", end=''),print(A)

print("B = ",end=''),print(B)

print("A + B = ",end=''),print(A-B)
print("The first bit is sign bit")





# A = 1111
# B = 10000
# A + B = 100001
# The first bit is sign bit