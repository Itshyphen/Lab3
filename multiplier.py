from Gates import AND, OR, XOR

class Binary:

    def __init__(self, num):
        self.list = [int(char) for char in num]

    def halfadder(self, a, b):
        return XOR(a, b), AND(a, b)

    def fulladder(self, a, b, c):
        s0, c0 = self.halfadder(a, b)
        s1, c1 = self.halfadder(s0, c)
        return s1, OR(c0, c1)

    def __str__(self):
        return ''.join([str(elem) for elem in self.list])

    def __add__(self, other):
        #difference in number of bits
        bitdif = len(self.list)-len(other)
        if bitdif > 0:
            length=len(self.list)
            for i in range(bitdif):       
                other.insert(0,0)
        else:
            length = len(other)
            for i in range(abs(bitdif)):  
                self.list.insert(0,0)
        
        #initializing carry with 0
        c = 0
        sum =[]
        for i in range(length-1,-1,-1):
            s,c = self.fulladder(self.list[i],other[i],c)
            sum.append(s)
        sum.append(c)
        return sum[::-1]

    def shiftleft(self):
        self.list.append(0)
    
    def __mul__(self, other):
        product =[0]
        for i in range(len(other.list)-1,-1,-1):
            if (other.list[i] == 1):
                product = self.__add__(product)
            self.shiftleft()
        return Binary(product)



A = Binary("1101")
B = Binary("1101")

print("A = ", end=''),print(A)

print("B = ",end=''),print(B)

print("A * B = ",end=''),print(A*B)

# def halfadder(a, b):
#     return XOR(a, b), AND(a, b)

# def fulladder(a, b, c):
#     s0, c0 = halfadder(a, b)
#     s1, c1 = halfadder(s0, c)
#     return s1, OR(c0, c1)



# def binaryAdder(a, b, c):
#     n = (len(a) if len(a) > len(b) else len(b))
#     carry = c
#     sum = [0,0,0,0,0,0,0,0] * n
#     for i in range(0,n):  
#         [sum[n - 1 - i], carry] = fulladder(int(a[n - 1 - i]), int(b[n - 1 - i]), carry)

#     return [sum, carry]


# def partial_product(multiplicant, multiplier):
#     if (len(multiplier) != len(multiplicant)):
#         print("Error")
#         return
    
#     n = len(multiplier)
#     product = "0" * 2*n
#     carry = 0
#     multiplicant = "0" * n + multiplicant

#     for i in range(n, 0, -1):
#         if(multiplier[i - 1] == '1'):
#             [product, carry] = binaryAdder(product, multiplicant, carry)
#         multiplicant = multiplicant + multiplicant[0]
        
#     print(product)

# partial_product("1010","1100")


