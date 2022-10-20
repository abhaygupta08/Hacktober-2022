#https://codeforces.com/problemset/problem/110/A
s =input()
c=0 
for i in s:
    if i=='4' or i=='7':
        c+=1 
if  c==7 or c==4:
    print("YES")
else:
    print("NO")
