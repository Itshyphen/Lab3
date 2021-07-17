from Gates import AND, OR, XOR
def binary(a): 
	bits_list=[]
	
	while(a>0):
		num=a
		b=int(num%2)
		bits_list.append(b)
		num=num//2
		a=int(a/2)
	bits_list.reverse()
	return bits_list


def Shift(shiftA,shiftQ):

	val=shiftA+shiftQ
	l = len(val)
	i=0
	for i in range(0,l-1):
		val[i]=0
		val[i]=val[i+1]
	del val[i]
	return val

def compliment(bits) :

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

def halfadder(a, b):
    return XOR(a, b), AND(a, b)

def fulladder(a, b, c):
    s0, c0 = halfadder(a, b)
    s1, c1 = halfadder(s0, c)
    return s1, OR(c0, c1)

def Add(A, B):
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

def decimal(bin):
	bin.reverse()
	dec=0
	for i in range(0,len(bin)):
		if(bin[i]==1):
			dec=dec+(bin[i]*(2**i))
		elif(bin[i]==0):
			pass
	bin.reverse()
	return dec

def Restoring(q, m):
    print("Q : ",*q)

    if len(m) < len(q):
        diff=len(q)-len(m)
        for i in range(0,diff+1):
            m.insert(0,0)
    print("M : ",*m)


    ACC = []
    for i in range(0,len(m)):
        ACC.append(0)
    print("A : ",*ACC)

    negM = compliment(m)
    print("-M : ",*negM)
    print("")


    print("          ","      ","   A    ","        ","   Q  ","        ")
    n=1
    counter = len(q)
    while counter > 0:

        
        a = Shift(ACC,q)
        newA=a[0:len(ACC)]
        newQ=a[len(ACC):]

        sumAM = Add(newA,negM)


        b=len(newQ)+1
        if(sumAM[0]==1):
            newQ.insert(b,0)
            sumAM=Add(sumAM,m)
        elif(sumAM[0]==0):
            newQ.insert(b,1)

        ACC=sumAM
        q=newQ

        print("Step : ",n,"        ",*ACC,"        ",*q,"    ")

        n=n+1
        counter=counter-1

    print("Quotient: ",*q,"   ",decimal(q))
    print("Remainder: ",*ACC,"  ",decimal(ACC))

q=binary(12)
m=binary(4)

Restoring(q,m)