import random
#allows the while loop to run. if the user chooses not to guess another number, the program adds one to game_play and exits the loop 
game_play = 1
info = str(input("Enter your name and favorite food: "))
list_info = info.split()
    
def main():
while game_play == 1:
    print("Lets play a game " + list_info[0] + "!")
    user_draw = int(input("Guess a number between 1 and 100: "))
    num_one = random.randint(1, 100)
    num_two = random.randint(1, 100)
    #assigns randomly generated numbers as the highest and lowest number
    if num_one > num_two:
        highest_num = num_one
        lowest_num = num_two
    else:
        highest_num = num_two
        lowest_num = num_one 
    #reveals the random numbers to the user
    print("The lowest number is " + str(lowest_num) + ", and the highest number is " + str(highest_num))
    #tells the user if they won or lost
    if user_draw > lowest_num and user_draw < highest_num:
        print(list_info[0] + ", you won! Go eat some " + list_info[1] + " as a reward. You deserve it!")
    else:
        print(list_info[0] + ", you lost. Go eat some " + list_info[1] + " to ease the feeling of failure. You can always try again!")
    #asks user if they want to guess again
    try_again = str(input("Do you want to guess again? yes or no? "))
    if try_again == str("no") or try_again == str(“No”):
        game_play = 2

print("Thanks for playing!")

def main()











