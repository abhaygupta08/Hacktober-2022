import tkinter as tk
import requests

URL = 'https://api.kanye.rest/'


def get_quote():
    response = requests.get(url=URL)
    response.raise_for_status()
    quote = response.json()['quote']
    canvas.itemconfig(quote_text, text=quote)


window = tk.Tk()
window.title('Kanye says...')
window.config(padx=50, pady=50)

canvas_background = tk.PhotoImage(file='background.png')
canvas = tk.Canvas(height=414, width=300)
canvas.create_image(150, 207, image=canvas_background)
quote_text = canvas.create_text(155, 187, text='', width=250,
                                font=('Arial', 16, 'bold'), fill='white')
canvas.grid(column=0, row=0)

kanye_img = tk.PhotoImage(file='kanye.png')
kanye_button = tk.Button(image=kanye_img, highlightthickness=0, bd=0, height=132, width=102,
                         activebackground='#efefef', command=get_quote)
kanye_button.grid(row=1, column=0)

get_quote()

window.mainloop()
