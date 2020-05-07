import serial
import tkinter as tk

window = tk.Tk()
window.title('Probe Rotation')
window.geometry('700x450')

tk.Label(window, text='Here you can control the motor',font=('Helvetica',20,'bold italic')).place(x=150,y=50)
tk.Label(window, text='Speed',font=('Helvetica',14,'bold italic')).place(x=200,y=100)

entry = tk.Entry(window, textvariable=tk.StringVar(value=()), width=16,font=('Helvetica',14,'italic'))
entry.place(x=300,y=100)

#arduinoData = serial.Serial('com4',9600)
arduinoData = 1

def left_1mm():
    arduinoData.write('A')

def left_2mm():
    arduinoData.write('B')

def left_3mm():
    arduinoData.write('C')

def right():
    arduinoData.write('R')

def stop():
    arduinoData.write('S')




Button = tk.Button

btn1 = Button(window, text="left 1mm", command=left_1mm)
btn2 = Button(window, text="left 2mm", command=left_2mm)
btn3 = Button(window, text="left 3mm", command=left_3mm)
btn4 = Button(window, text="right", command=right)
btn5 = Button(window, text="stop", command=stop)



btn1.place(x=200,y=200)
btn2.place(x=200,y=250)
btn3.place(x=200,y=300)
btn4.place(x=300,y=200)
btn5.place(x=400,y=200)


window.mainloop()

