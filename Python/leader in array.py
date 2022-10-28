import math 

def leaders(self, A, N):
    #Code here
    l =  0 
    li = []
    for i in range(N-1,-1,-1):
        if A[i] >= l:
            li.append(A[i])
            l = A[i]
    li.reverse()
    return li
def main(): 
    arr = [4,3,6,7,8]
    n = len(arr)
    print(leaders(arr,n))      

#Output - [8]
