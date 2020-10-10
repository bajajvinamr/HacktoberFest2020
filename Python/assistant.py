#creating a speech recognition assistant
import speech_recognition as sr
import pyttsx3
import webbrowser
import tkinter as tk
import wikipedia
engine = pyttsx3.init()
voice_id = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices\Tokens\TTS_MS_EN-US_ZIRA_11.0"
#female voice id
  
# Use female voice 
engine.setProperty('voice', voice_id) 
  

name="Edu" 
#chatbot name





#some pre defined chats

greetings=["hello","hi","hey"]
wish={"morning":"Good morning","night":"Good night","care":"You too.","bye":"Please don't go"}
silly={"marry":"No, i have a boyfriend","love":"I love myself","hate":"lmao, look at your face ","children":"Oh please."}

global answer
global order

def check(): #defining function
        
    r=sr.Recognizer()
    with sr.Microphone() as source:
        audio=r.listen(source)  #listening audio
        order=r.recognize_google(audio,language="en-in") #recognizing the audio
    e2.insert(tk.END,order)  #insert in textarea
    global x
    x=order.split(' ')  #tokenizing the sentence
    
    
    
    for word in x:
        if word in greetings:   #creating random logic
            answer="Hey, My name is Edu. Nice to meet you."
            
        elif word in wish:
            answer=wish[word]
            engine.say(answer)
            engine.runAndWait()
            e1.insert(tk.END, answer)
            
        elif "play" in x:  
            webbrowser.open_new(f"https://www.youtube.com/results?search_query={x[1]}")
            
        elif "search" in x:
            webbrowser.open_new(f"https://www.youtube.com/results?search_query={x[1]}")
            
        elif "what" in x or "who" in x:
            
            try:
                order=order.replace("who","")
        
            except:
                order=order.replace("what","")
            answer=wikipedia.summary(order,sentences=1)
            engine.say(answer)
            engine.runAndWait()
            e1.insert(tk.END, answer)
            break

            
        elif word in silly:
            answer=silly[word]
            engine.say(answer)
            engine.runAndWait()
            e1.insert(tk.END, answer)
            
        elif "quit" in x:
            root.destroy()
            
#creating GUI
root=tk.Tk()
root.geometry("200x300")
root.title("EDUYEAR")
root.configure(bg="black")
e1=tk.Text(root)
l1=tk.Label(root,text="Output:")
l1.place(x=10,y=5)
e1.place(x=10,y=35,height=50,width=180)
e2=tk.Text(root)
l=tk.Label(root,text="-----------------------------------")
l.place(x=10,y=90)
l=tk.Label(root,text="You said:")
l.place(x=10,y=120)
e2.place(x=10,y=150,height=30,width=180)
b1=tk.Button(root,text="Speak",bg="red",fg="white",command=check)
b1.place(x=50,y=200,height=50,width=100)

root.mainloop()