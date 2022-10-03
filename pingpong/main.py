from turtle import Turtle ,Screen
from play import Game
from ball import Ball
from scoreboard import Score
import time
screen = Screen()
paddle1 = Game((350,0))
paddle2 = Game((-350,0))
ball = Ball()
score = Score()
screen.tracer(0)

paddle1.goto(350,0)
paddle2.goto(-350,0)

screen.setup(width=800,height=600)
screen.bgcolor("black")
screen.title("PONG")


screen.listen()
if paddle1.xcor()<390 or paddle2.ycor()<-350:
    screen.onkey(fun=paddle1.goup,key="Up")
    screen.onkey(fun=paddle1.godown,key="Down")
    screen.onkey(fun=paddle2.goup,key="w")
    screen.onkey(fun=paddle2.godown,key="s")

game_on = True
while game_on:
    time.sleep(ball.move_speed)
    ball.move()
    if ball.ycor()>280 or ball.ycor()<-280:
        ball.reflect()
    if ball.distance(paddle1)<40 or ball.distance(paddle2)<40:
        ball.bounce()

    if ball.xcor()>400 :
        ball.refresh()
        score.goto(-300, 250)
        score.currentleftscr()
    if ball.xcor() < -400:
        ball.refresh()
        score.goto(300, 250)
        score.currentrightscr()
    screen.update()


screen.exitonclick()
