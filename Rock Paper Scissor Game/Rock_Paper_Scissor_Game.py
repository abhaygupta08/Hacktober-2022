def gameWin(comp, you):
    if comp == you:
        return None
    elif comp == 's':
        if you == 'p':
            return False
        elif you == 'r':
            return True
    elif comp == 'p':
        if you == 'r':
            return False
        elif you == 's':
            return True
    elif comp == 'r':
        if you == 's':
            return False
        elif you == 'p':
            return True
print("Comp Turn: Rock(r) Paper(p) Scissor(s) ?")
import random
randNo = random.randint(1, 3)
if randNo == 1:
    comp = 'r'
elif randNo == 2:
    comp = 'p'
elif randNo == 3:
    comp = 's'
print("Computer has chosen")
you = input("Your Turn: Rock(r) Paper(p) Scissor(s) ?\n")
a = gameWin(comp, you)
print(f"Computer chose {comp}")
print(f"You chose {you}")
if a == None:
    print("The game is a tie!")
elif a == True:
    print("You Win!")
else:
    print("You Lose!")
