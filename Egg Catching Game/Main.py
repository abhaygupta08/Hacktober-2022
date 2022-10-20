from itertools import cycle
from random import randrange
from tkinter import Canvas, Tk, messagebox, font

canvas_width = 800
canvas_height = 400

#window for tkinter
win = Tk()
#background - sky
c = Canvas(win, width=canvas_width, height=canvas_height, background="pink1")
#background - ground
c.create_rectangle(-5, canvas_height-100, canvas_width+5, canvas_height+5, fill="sea green", width=0)
#left sun dimensions (x,y,x1,y1)
c.create_oval(-80, -80, 120, 120, fill='orange2', width=0)
c.pack()

#list of colors for eggs one-by-one
color_cycle = cycle(["light blue", "light green", "orange3", "coral", "light cyan"])

#egg dimensions 
egg_width = 45
egg_height = 55

egg_score = 10
egg_speed = 400

#new egg imerges 
egg_interval = 3000

#increase speed after catching the egg
difficulty = 0.95

#bucket dimensions
catcher_color = "purple"
catcher_width = 100
catcher_height = 100

#bucket points from left upper point (Xo , Yo) starting point of bucket
# half of canvas width - half of bucket width = Xo

#800/2 - 100/2 = 400 - 50 = 350 = Xo 
catcher_startx = canvas_width / 2 - catcher_width / 2

#400 - 100 - 20 = 280                   (add -20 to make the cup more upwards)
catcher_starty = canvas_height - catcher_height - 20

#right upper point by adding width and height to the starting point (X0,Yo)
catcher_startx2 = catcher_startx + catcher_width
catcher_starty2 = catcher_starty + catcher_height

#4 points for arc Xo,Yo, X2,Y2                                                           (angle of arc = 200 to 140 degrees)        boundary
catcher = c.create_arc(catcher_startx, catcher_starty, catcher_startx2, catcher_starty2, start=200, extent=140, style="arc", outline=catcher_color, width=3)
game_font = font.nametofont("TkFixedFont")
game_font.config(size=18)

#scoring counter
score = 0
score_text = c.create_text(10, 10, anchor="nw", font=game_font, fill="navy", text="Score: "+ str(score))

#active lives counter
lives_remaining = 3
lives_text = c.create_text(canvas_width-10, 10, anchor="ne", font=game_font, fill="navy", text="Lives: "+ str(lives_remaining))

#list of total eggs in basket
eggs = []


# new egg formation
def create_egg():
    x = randrange(10, 740)
    y = 40
    # egg formation
    new_egg = c.create_oval(x, y, x+egg_width, y+egg_height, fill=next(color_cycle), width=0)
    eggs.append(new_egg)
    #window update after catching
    win.after(egg_interval, create_egg)


#egg movement
def move_eggs():
    for egg in eggs:
        (eggx, eggy, eggx2, eggy2) = c.coords(egg)
        c.move(egg, 0, 10)
        if eggy2 > canvas_height:
            egg_dropped(egg)
    win.after(egg_speed, move_eggs)


#egg deletion algo if dropped
def egg_dropped(egg):
    eggs.remove(egg)
    c.delete(egg)
    lose_a_life()
    if lives_remaining == 0:
        messagebox.showinfo("Game Over!", "Final Score: "+ str(score))
        win.destroy()


#life reduce with egg drop
def lose_a_life():
    global lives_remaining
    lives_remaining -= 1
    c.itemconfigure(lives_text, text="Lives: "+ str(lives_remaining))


#if egg touch inside the basket and total catch eggs is less than 40 ms
def check_catch():
    (catcherx, catchery, catcherx2, catchery2) = c.coords(catcher)
    for egg in eggs:
        (eggx, eggy, eggx2, eggy2) = c.coords(egg)
        if catcherx < eggx and eggx2 < catcherx2 and catchery2 - eggy2 < 40:
            eggs.remove(egg)
            c.delete(egg)
            increase_score(egg_score)
    win.after(100, check_catch)


#difficult raise with new egg catch 
def increase_score(points):
    global score, egg_speed, egg_interval
    score += points
    #speed raise at new interval
    egg_speed = int(egg_speed * difficulty)
    egg_interval = int(egg_interval * difficulty)
    c.itemconfigure(score_text, text="Score: "+ str(score))


# left right movement 
def move_left(event):
    (x1, y1, x2, y2) = c.coords(catcher)
    #postive x axis from 0
    if x1 > 0:
        c.move(catcher, -30, 0)

def move_right(event):
    (x1, y1, x2, y2) = c.coords(catcher)
    #positive x axis from x cordinate
    if x2 < canvas_width:
        c.move(catcher, 30, 0)


c.bind("<Left>", move_left)
c.bind("<Right>", move_right)
c.focus_set()
win.after(1000, create_egg)
win.after(1000, move_eggs)
win.after(1000, check_catch)
win.mainloop()
