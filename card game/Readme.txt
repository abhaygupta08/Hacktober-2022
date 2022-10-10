# Class that models playing cards
************************************************************************
class Card:
    suits = ["spades",
             "hearts",
             "diamonds",
             "clubs"]

    values = [None, None,"2", "3",
              "4", "5", "6", "7",
              "8", "9", "10",
              "Jack", "Queen",
              "King", "Ace"]

    def __init__(self, v, s):
        """suit + value are ints"""
        self.value = v
        self.suit = s

    def __lt__(self, c2):
        if self.value < c2.value:
            return True
        if self.value == c2.value:
            if self.suit < c2.suit:
                return True
            else:
                return False
        return False

    def __gt__(self, c2):
        if self.value > c2.value:
            return True
        if self.value == c2.value:
            if self.suit > c2.suit:
                return True
            else:
                return False
        return False

    def __repr__(self):
        v = self.values[self.value] +\
            " of " + \
            self.suits[self.suit]
        return v

The first class in our card game with Python is a Card class, which has two class variables, suits and values.
Suits is a tuple of strings representing all the suits a card can be: spades, hearts, diamonds, clubs. 

value is a tuple of strings representing the different numeric values a card can be: 2–10, Jack, Queen, King, and Ace.

The elements of the first two indexes of the value tuple are None, so the strings in the tuple match the index they represent. 
So the string “2” in the tuple of values is at index 2.

Card objects have two instance variables: suit and value, each represented by an integer. T
ogether, the instance variables represent the card type of the Card object. 
For example, you create a 2 of hearts by creating a Card object and passing it the parameters 2 (for color) and 1.

The code for these magic methods can also handle whether the cards have the same value, for example, if both cards have a value of 10. 
If this happens, the methods use the value of the combinations to break the tie.

The combinations are ranked in order of strength in the combination tuple – with the strongest combination last, 
and thus assigned to the highest index, and the less powerful combination to the lowest index.
***********************************************************************************************************************************************
***********************************************************************************************

# define a class to represent a deck of cards:

class Deck:
    def __init__(self):
        self.cards = []
        for i in range(2, 15):
            for j in range(4):
                self.cards\
                    .append(Card(i,
                                 j))
        shuffle(self.cards)

    def rm_card(self):
        if len(self.cards) == 0:
            return
        return self.cards.pop()

When you initialize the Deck object, the two for loops of __init__ create Card objects representing all the cards in a 52-card deck and add them to the card list. 
The first loop goes from 2 to 15 because the first value of a card is 2 and the last value of a card is 14 (the ace).

Each time around the inner loop, a new card is created using the integer from the outer loop as the value 
(i.e. 14 for an ace) and the integer from the inner loop as the suit. This process creates 52 cards – one card for each combination of suit and value.

After the method creates the cards, the shuffle method of the shuffle module randomly rearranges the items in the card list; imitating the shuffle of a deck of cards.

Our deck has another method called rm_card which removes and returns a card from the card list, or returns None if it is empty.
************************************************************************************
************************************************************************************

# a class to represent each player in the game to keep track of their cards 
# and the number of tricks won:

class Player:
    def __init__(self, name):
        self.wins = 0
        self.card = None
        self.name = name

The Player class has three instance variables: wins to keep track of the number of turns a player has won, 
card to represent the card a player currently holds,and name to keep track of a player’s name.
***********************************************************************
***********************************************************************

# a class to represent the game: 

class Game:
    def __init__(self):
        name1 = input("p1 name ")
        name2 = input("p2 name ")
        self.deck = Deck()
        self.p1 = Player(name1)
        self.p2 = Player(name2)

    def wins(self, winner):
        w = "{} wins this round"
        w = w.format(winner)
        print(w)

    def draw(self, p1n, p1c, p2n, p2c):
        d = "{} drew {} {} drew {}"
        d = d.format(p1n,
                     p1c,
                     p2n,
                     p2c)
        print(d)

    def play_game(self):
        cards = self.deck.cards
        print("beginning War!")
        while len(cards) >= 2:
            m = "q to quit. Any " + \
                "key to play:"
            response = input(m)
            if response == 'q':
                break
            p1c = self.deck.rm_card()
            p2c = self.deck.rm_card()
            p1n = self.p1.name
            p2n = self.p2.name
            self.draw(p1n,
                      p1c,
                      p2n,
                      p2c)
            if p1c > p2c:
                self.p1.wins += 1
                self.wins(self.p1.name)
            else:
                self.p2.wins += 1
                self.wins(self.p2.name)

        win = self.winner(self.p1,
                         self.p2)
        print("War is over.{} wins"
              .format(win))

    def winner(self, p1, p2):
        if p1.wins > p2.wins:
            return p1.name
        if p1.wins < p2.wins:
            return p2.name
        return "It was a tie!"

When you create the game object, Python calls the __init__ method 
and the input function collects the names of the two players in the game 
and stores them in the variables name1 and name2.

Then you create a new Deck object, store it in the instance variable deck, 
and create two Player objects using the names in name1 and name2. 
The play_game method of the Game class starts the game. 
There is a loop in the method that maintains the game as long as there are two or more cards left in the deck, 
and as long as the variable response is not equal to q .

On each loop turn, you assign the variable response to user input. 
The game continues until the user types “q” or when there are less than two cards left in the deck. 
Two cards are drawn each time in the loop and the play_game method assigns the first card to p1 and the second card to p2.

Then he prints each player’s name and the card he drew, compares the two cards to see which card is the bigger one, 
increments the wins instance variable for the player with the highest card, and prints a message indicating who won. 
The Game class also has a method called winning which takes two player items, 
looks at the number of tricks they’ve won, and returns the player who has won the most tricks.

When the Deck object runs out of cards, the play_game method displays a message that the war is over, 
calls the winning method (passing both p1 and p2), and 
displays a message with the result – player name who won.
**************************************************************************
**************************************************************************

game = Game()
game.play_game()