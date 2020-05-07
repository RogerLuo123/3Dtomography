import tkinter as tk
from tkinter.messagebox import showinfo
import os
import re
import serial


window = tk.Tk()
window.title('Probe Rotation')
window.geometry('700x450')

tk.Label(window, text='Here you can control the motor',font=('Helvetica',20,'bold italic')).place(x=150,y=50)
tk.Label(window, text='Speed',font=('Helvetica',14,'bold italic')).place(x=200,y=100)

entry = tk.Entry(window, textvariable=tk.StringVar(value=()), width=16,font=('Helvetica',14,'italic'))
entry.place(x=300,y=100)




    
def Start():
    showinfo("Probe Rotation", '''
The motor starts to run!
''')

    
    files = os.walk(".")      

    for maindir,subdir,file_name_list in files:
        for f in file_name_list:
            apath = os.path.join(maindir,f)
            file_name = 'sdfgsdfg.py'
            if re.search(file_name,f):
                portion = os.path.splitext(file_name)
                
                if portion[1] == ".py":  
                      
                    newname = portion[0] + ".txt"   
                    os.rename(file_name,newname)

    infile = open('sdfgsdfg.txt','r+',encoding='utf-8')
    with infile as f:
        file_data = ''
        for line in f:
            if 'Speed' in line:
                OriginalValue = line.split('=')
                #print(OriginalValue)
                OriginalValue.remove(OriginalValue[0])
                #print(OriginalValue)
                value = entry.get()
                #print(value)
                if value == '':
                    value = '100'
                if OriginalValue[0] in line:
                    if value != OriginalValue[0]:
                        lline = line.split('=')
                        lline.remove(lline[0])
                line = line.replace(OriginalValue[0],value)
            file_data += line+'\n'
    with open('sdfgsdfg.txt','w',encoding='utf-8') as f:
        f.write(file_data)
                

    infile.close()
    
    files = os.walk(".")      

    for maindir,subdir,file_name_list in files:
        for f in file_name_list:
            apath = os.path.join(maindir,f)
            file_name = 'sdfgsdfg.txt'
            if re.search(file_name,f):
                portion = os.path.splitext(file_name)
                
                if portion[1] == ".txt":  
                       
                    newname = portion[0] + ".py"   
                    os.rename(file_name,newname)


    import sdfgsdfg

def left_1mm():
    arduinoData.write(str.encode('A'))

def left_2mm():
    arduinoData.write(str.encode('B'))

def left_3mm():
    arduinoData.write(str.encode('C'))

def right():
    arduinoData.write(str.encode('R'))

def stop():
    arduinoData.write(str.encode('S'))


arduinoData = serial.Serial('/dev/cu.usbmodem14201',9600)
#arduinoData = 1

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


#window.mainloop()
        
start = tk.Button(window,text='start',font=('Helvetica',14,'italic'),command=Start)
start.place(x=320,y=150)




