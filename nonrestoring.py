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
    return bits

def binary(num,n):
        bin_num = str(bin(abs(num)).replace("0b", ""))
        l = [int(char) for char in bin_num]
        for j in range(len(l),n):
            l.insert(0,0)
        if(num<0):
            return(twoscomplement(l))
        return l

def ShiftLeft(A,Q):
    L = A + Q
    L.pop(0)
    return L[0:len(A)],L[len(A):]

def Decimal(binary):
    return int(binary,2)

def nonRestoring(A,B,n):
    Q = binary(A,n)    #dividend
    M = binary(B,n)     #divisor
    n = len(M)
    Accum =[0]*n
    NegM = twoscomplement(M)

    print("operation","\t   ","A"," \t    \t    ","Q","        ","count")
    while n!=0:
        if(Accum[0]==0):
            Accum,Q=ShiftLeft(Accum,Q)
            print("A>0=>SHL","\t",string(Accum),"         ",string(Q),"     ",n)
            Accum = BinaryAdder(Accum, NegM)
            print("A=A-M","          ",string(Accum),"         ",string(Q),"     ",n)
        else:
            Accum,Q=ShiftLeft(Accum,Q)
            print("A>0=>SHL ","\t",string(Accum),"         ",string(Q),"     ",n)
            Accum = BinaryAdder(Accum, M)
            print("A=A+M","\t\t",string(Accum),"         ",string(Q),"     ",n)

        if(Accum[0]==0):
            Q.append(1)
            print("A>0=>Q0=1","\t",string(Accum),"         ",string(Q),"    ",n)
        else:
            Q.append(0)
            print("A>0=>Q0=0","\t",string(Accum),"         ",string(Q),"    ",n)
        #count--
        n=n-1
    print("******************Count has reached 0*********************")
    if(Accum[0]==1):
        Accum = BinaryAdder(Accum, M)
        print("A<0=>A=A+M","\t",string(Accum),"         ",string(Q),"     ",n)
        print("Result----","\t","Remainder","        ","Quotient")
    rem =Decimal(string(Accum))
    quotient =Decimal(string(Q))
    return rem,quotient
    
A = 123   # dividend
B = 5      # divisor

print("Dividend = ", end=''),print(A)
print("Divisor = ",end=''),print(B)

print("******************NON RESTORING DIVISION ALGORITHM*********************")

R,Q =nonRestoring(A,B,10)#third parameter is max number of bits

print("Quotient = ", end=''),print(Q)
print("Remainder = ",end=''),print(R)
