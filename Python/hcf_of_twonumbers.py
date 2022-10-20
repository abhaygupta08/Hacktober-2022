#python program to find hcf of two numbers
# pass two arguments x,y
# solving using set comprehensions
def hcf(x,y): 
    x1 = {i for i in range(1,x+1) if x % i == 0}
    x2 = {j for j in range(1,y+1) if y % j == 0}
    y2 = x1.intersection(x2)
    print(max(y2))

hcf(54,24)