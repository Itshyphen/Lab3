from Gates import AND, OR, XOR


def halfadder(a, b):
    return XOR(a, b), AND(a, b)

def fulladder(a, b, c):
    s0, c0 = halfadder(a, b)
    s1, c1 = halfadder(s0, c)
    return s1, OR(c0, c1)

def string(list):
    return ''.join([str(elem) for elem in list])

def BinaryAdder(A, B):
    #difference in number of bits
    bitdif = len(A)-len(B)
    if bitdif > 0:
        length =len(A)
        for i in range(bitdif):       
            B.insert(0,0)
    else:
        length = len(B)
        for i in range(abs(bitdif)):  
            A.insert(0,0)
    #initializing carry with 0
    c = 0
    sum =[]
    for i in range(length-1,-1,-1):
        s,c = fulladder(A[i],B[i],c)
        sum.append(s)
    # sum.append(c)
    return sum[::-1]


def twoscomplement(bits) :

    l = len(bits) - 1
    bits = [XOR(i,1) for i in bits]

    for i in range(l,-1,-1):
        if bits[i] == 0:
            bits[i] = 1
            break

        else:
            bits[i] = 0
    # print(bits)
    return bits

def binary(num):
        bin_num = str(bin(abs(num)).replace("0b", ""))
        l = [int(char) for char in bin_num]
        for j in range(len(l),8):
            l.insert(0,0)
        if(num<0):
            return(twoscomplement(l))
        return l

def cmp(a,b):
    return (a>b)-(a<b)

def ASR(Accum,Q1):
    joined = Accum + Q1
    res =[]
    res.append(joined[0])
    res.append(joined[0])
    for i in range(2,len(joined)):
        res.append(joined[i-1])
    return res[0:len(Accum)],res[len(Accum):]

def Decimal(binary):
    return int(binary,2)

def Booths(A,B):
    M = binary(A)
    Q = binary(B)
    print(M)
    print(Q)
    n = len(M)
    i=8
    Accum =[0]
    NegM = twoscomplement(M)
    Q.append(0)

    print("operation", end='\t')
    print("Accum ", end='\t\t')
    print("Q ", end='\t\t')
    print("q-1 ")

    while i!=0:
        res = cmp(Q[n],Q[n-1])
        # print(res)
        if (res == -1):
            Accum = BinaryAdder(Accum, NegM)
            print("A - M", end='\t\t')
            print(string(Accum), end='\t')
            print(string(Q[0:n]), end='\t')
            print(Q[-1])
            
        elif (res == 1):
            Accum = BinaryAdder(Accum, M)
            print("A + M", end='\t\t')
            print(string(Accum), end='\t')
            print(string(Q[0:n]), end='\t')
            print(Q[-1])
        Accum,Q = ASR(Accum,Q)
        print("ASR", end='\t\t')
        print(string(Accum), end='\t')
        print(string(Q[0:n]), end='\t')
        print(Q[-1])
        i=i-1
    print("Product:", end='\t\t')
    product = string(Accum+Q[0:n])
    decimal = Decimal(product)
    if(A*B<0):
        product = (string(twoscomplement(Accum+Q[0:n])))
        decimal = -1 * Decimal(product)

    print(product, "-->", end='')
   
    return decimal


# # multiplicant
A = -8
# # multiplier
B = -3

print("A = ", end=''),print(A)

print("B = ",end=''),print(B)

product = Booths(A,B)
print(product)



