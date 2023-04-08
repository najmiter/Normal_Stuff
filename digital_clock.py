from tkinter import *
from time import strftime

root = Tk()
root.title('Digital Clock by CodeMite')

def time():
    str_time = strftime('%r\n%b %d %Y')
    label.config(text=str_time)
    label.after(1000, time)

label = Label(root, font=('Space Mono', 100, 'bold'), bg='#22272d', fg='white')

label.pack(anchor='center', fill='both', expand=1)

time()
mainloop()

# you can download the Space Mono font from fonts.google.com for free