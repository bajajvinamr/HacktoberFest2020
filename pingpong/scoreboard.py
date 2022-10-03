from turtle import Turtle
class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.penup()
        self.hideturtle()
        self.color("white")
        self.lscr=0
        self.rscr=0


        self.updatescr()

    def updatescr(self):
        self.goto(-100, 200)
        self.write(f"{self.lscr}", True, align="left", font=("arial", 24, "normal"))
        self.goto(100, 200)
        self.write(f"{self.rscr}", True, align="right", font=("arial", 24, "normal"))

    def currentleftscr(self):
        self.lscr+=1
        self.clear()
        self.updatescr()
    def currentrightscr(self):
        self.rscr+=1
        self.clear()
        self.updatescr()

