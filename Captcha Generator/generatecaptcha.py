#Import the required libraries 
import random
import string
from tkinter import Tk, Label, Entry, Button, END
from PIL import ImageTk, Image
from captcha.image import ImageCaptcha


def createImage(flag=0):
  
    # This wil generate random captcha image  
    global random_string
    global image_label
    global image_display
    global entry
    global verify_label

    # The if block below works only when we press the
    # Reload Button in the GUI. It basically removes
    # the label (if visible) which shows whether the
    # entered string is correct or incorrect.
    if flag == 1:
        verify_label.grid_forget()

    # Removing the contents of the input box.
    entry.delete(0, END)

    # Generating a random string for the Captcha
    random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=6))

    # Creating a Captcha Image
    image_captcha = ImageCaptcha(width=250, height=125)
    image_generated = image_captcha.generate(random_string)
    image_display = ImageTk.PhotoImage(Image.open(image_generated))

    # Removing the previous Image (if present) and
    # displaying a new one.
    image_label.grid_forget()
    image_label = Label(root, image=image_display)
    image_label.grid(row=1, column=0, columnspan=2,
                     padx=10)


def check(x, y):
    """
    Defining the method check() which will check
    whether the string entered by the user matches
    with the randomly generated string. If there is
    a match then "Verified" pops up in the window.
    Otherwise, "Incorrect!" pops up and a new Captcha
    Image is generated for the user to try again.
    """

    # Making the scope of the below mentioned
    # variables because their values are accessed
    # globally in this script.
    global verify_label

    verify_label.grid_forget()

    if x.lower() == y.lower():
        verify_label = Label(master=root,
                             text="Verified",
                             font="Arial 15",
                             bg='#ffe75c',
                             fg="#00a806"
                             )
        verify_label.grid(row=0, column=0, columnspan=2, pady=10)
    else:
        verify_label = Label(master=root,
                             text="Incorrect!",
                             font="Arial 15",
                             bg='#ffe75c',
                             fg="#fa0800"
                             )
        verify_label.grid(row=0, column=0, columnspan=2, pady=10)
        createImage()


if __name__ == "__main__":
    # Initializing Tkinter by creating a root widget,
    # setting Title and Background Color
    root = Tk()
    root.title('Image Captcha')
    root.configure(background='#ffe75c')

    # Initializing the Variables to be defined later
    verify_label = Label(root)
    image_label = Label(root)

    # Defining the Input Box and placing it in the window
    entry = Entry(root, width=10, borderwidth=5,
                  font="Arial 15", justify="center")
    entry.grid(row=2, column=0)

    # Creating an Image for the first time.
    createImage()

    # Defining the path for the reload button image
    # and using it to add the reload button in the
    # GUI window
  
    reload_img = ImageTk.PhotoImage(Image.open("refresh.png").resize((32, 32), Image.ANTIALIAS))
    reload_button = Button(image=reload_img, command=lambda: createImage(1))
    reload_button.grid(row=2, column=1, pady=10)

    # Defining the submit button
    submit_button = Button(root, text="Submit", font="Arial 10", command=lambda: check(entry.get(), random_string))
    submit_button.grid(row=3, column=0, columnspan=2, pady=10)
    root.bind('<Return>', func=lambda Event: check(entry.get(), random_string))

    # This makes the program loops till the user
    # doesn't close the GUI window
    root.mainloop()
