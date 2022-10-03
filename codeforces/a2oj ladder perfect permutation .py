#https://codeforces.com/problemset/problem/233/A
n =int(input())
if n&1:
    print(-1)
else:
    l=[]
    for i in range(1,n+1,2):
        l.append(i+1)
        l.append(i)
    for i in l:
        print(i,end=" ")
    
