# window screen created
wind = turtle.Screen()
wind.title("Snake Maze🐍")
wind.bgcolor("red")

# The screen size
wind.setup(width=600, height=600)


# creating the snake 
snake = turtle.Turtle()
snake.shape("square")
snake.color("black")
snake.penup()
snake.goto(0, 0)
snake.direction = "Stop"

# creating the food
snake_food = turtle.Turtle()
shapes = random.choice('triangle','circle')
snake_food.shape(shapes)
snake_food.color("blue")
snake_food.speed(0)
snake_food.penup()
snake_food.goto(0, 100)

pen = turtle.Turtle()
pen.speed(0)
pen.shape('square')
pen.color('white')
pen.penup()
pen.hideturtle()
pen.goto(0, 250)
pen.write("Your_score: 0 Highest_Score : 0", align="center", 
font=("Arial", 24, "normal"))
turtle.mainloop()
