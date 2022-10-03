#https://codeforces.com/problemset/problem/266/A
n =int(input())
s =input()
st =[s[0]]
for i in range(1,n):
    if s[i]==st[-1]:
        continue
    else:
        st.append(s[i])
print(n-len(st))
