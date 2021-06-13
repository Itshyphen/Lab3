class Gates:
        
    def AND (self, a, b):
    
        if a == 1 and b == 1:
            return 1
        else:
            return 0

    def OR (self, a, b):
    
        if a == 0 and b == 0:
            return 0
        else:
            return 1

    def NOT (self, a):
        if a == 1:
            return 0
        else:
            return 1

    def NOR (self, a, b):
    
        if a == 0 and b == 0:
            return 1
        else:
            return 0

    def NAND (self, a, b):
    
        if a == 1 and b == 1:
            return 0
        else:
            return 1

    def XOR (self, a, b):
    
        if a != b:
            return 1
        else:
            return 0

    def XNOR (self, a, b):
    
        if a == b:
            return 1
        else:
            return 0

def AND (a, b):
    
    if a == 1 and b == 1:
        return 1
    else:
        return 0

def OR ( a, b):

    if a == 0 and b == 0:
        return 0
    else:
        return 1

def XOR ( a, b):
    
    if a != b:
        return 1
    else:
        return 0