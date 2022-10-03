from turtle import Turtle , Screen

class Game(Turtle) :
    def __init__(self,position):
        super().__init__()
        self.penup()
        self.color("white")
        self.shape("square")
        self.shapesize(4, 1)
        self.goto(position)
    def goup(self):
        newy = self.ycor()+20
        self.goto(self.xcor(),newy)
    def godown (self):
        newy = self.ycor()-20
        self.goto(self.xcor(),newy)


