#COA next lab:  non restoring division and memory( LRU ra FIFO cache replacement policy :array ma number rakhne ani lru, fifo huda kasari update huncha bhanera dekhaune)

def LRUCache(pages,nFrames):
    frame = ['x']*nFrames
    faults = 0
    hit = 0

    for i in pages:
        print(" Input= ",i,end=" :")
        if i in frame:
            hit+=1
            frame.remove(i)
            frame.insert(0,i)
            print(frame,end="  ")
            print("Hit")
            continue
        else:
            frame.insert(0,i)
            frame.pop()
            faults += 1
            print(frame)
    return hit,faults

def FIFOCache(pages,nFrames):
    frame = []
    faults = 0
    hit = 0

    for i in pages:
        print(" Input= ",i,end=" :")
        if i in frame:
            print(frame,end="  ")
            print("Hit")
            hit+=1
        else:
            if len(frame) == nFrames:
                frame.pop()
                frame.insert(0,i)
            else:
                frame.insert(0,i)
            faults += 1
            print(frame)
        
    return hit,faults

  


pages = [1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6]
print("******************LRU CACHE REPLACEMENT*********************")
hits,faults =LRUCache(pages,4)

print("Total Hits:",hits)
print("Total page faults:",faults)

print("******************FIFO CACHE REPLACEMENT*********************")
hit,fault =FIFOCache(pages,4)
print("Total Hits:",hit)
print("Total page faults:",fault)





    
