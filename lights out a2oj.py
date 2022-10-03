#https://codeforces.com/problemset/problem/275/A
l =[]
for _ in range(3):
    l1=list(map(int,input().split()))
    l.append(l1)
grid=[[0]*3 for _ in range(3)]
 
 
di =[(1,0),(-1,0),(0,1),(0,-1)]
for i in range(3):
    for j in range(3):
        sm =l[i][j]
        for k in di:
            a=i+k[0]
            b =j+k[1]
            if a>=0 and a<3 and b>=0 and b<3:
                sm+=l[a][b]
        if sm%2==0:
            print(1,end="")
        else:
            print(0,end="")
    print()
