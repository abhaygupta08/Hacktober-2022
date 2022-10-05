def bubble(a,n):
    for i in range(n):
        for j in range(n-1):
            if a[j]>a[j+1]:
                a[j],a[j+1]=a[j+1],a[j]
    for i in range(n):
        print(a[i],end=" ")
    return 
a=[5,6,7,9,3,4,2]
n=len(a)
bubble(a,n)
