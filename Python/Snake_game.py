import pygame
import time
import random
import sys

pygame.init()

# Display Window size(width,height)
Display_size_w = 800
Display_size_h = 600

# pygame R G B
Black = (0, 0, 0)
White = (255, 255, 255)
Grey = (64, 64, 64)
Blue = (40, 55, 55)
Green = (0, 255, 0)
Red = (255, 0, 0)
Gren = (170, 150, 0)

# Initialising display
Display_window = pygame.display.set_mode((Display_size_w, Display_size_h))
pygame.display.set_caption('Classic Snake Game - Kiranmaye')

# Our snake
snake_size = 10
snake_speed = 10

# Clock to track the game's frame rate
Timer = pygame.time.Clock()

# setting font
small_font = pygame.font.SysFont("times new roman", 25)
medium_font = pygame.font.SysFont("times new roman", 50)


# Displaying score function
def display_score(score):
    value = small_font.render("By Kiranmaye "  "                                            "
                                                     "                               YOUR SCORE:{scr}".format(scr=score), True, White,"medium")
    Display_window.blit(value, [0, 0])


# snake function
def snake(snake_size, snake_list):
    for x in snake_list:
        pygame.draw.rect(Display_window, Green, [x[0], x[1], snake_size, snake_size])


# objects to display text on screen
def text_inference(text, color, size):
    if size == "small":
        textSurface = small_font.render(text, True, color)
    if size == "medium":
        textSurface = medium_font.render(text, True, color)
    return textSurface, textSurface.get_rect()


# display message function
def message(msg, color, y_coordinate=0, size=""):
    textSurface, textRect = text_inference(msg, color, size)
    textRect.center = (Display_size_w / 2), (Display_size_h / 2) + y_coordinate
    Display_window.blit(textSurface, textRect)


# Welcome
def welcome():
    intro = True

    while intro:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_p:
                    intro = False
                if event.key == pygame.K_q:
                    pygame.quit()
                    quit()

        Display_window.fill(Gren)
        message("Welcome", White, -80, "medium")
        message("Press P to play or Q to Exit ", Black, 150, "small")

        pygame.display.update()
        Timer.tick(5)


def main():

    game_ended = False
    game_exit = False

    x1 = Display_size_w / 2
    y1 = Display_size_h / 2

    x1_next = 0
    y1_next = 0

    snake_List = []
    Length_of_snake = 1

    food_x = round(random.randrange(0, Display_size_w - snake_size) / 10.0) * 10.0
    food_y = round(random.randrange(0, Display_size_h - snake_size) / 10.0) * 10.0

    while not game_ended:

        while game_exit == True:
            Display_window.fill(Black)
            message("GAME OVER", Red, y_coordinate=-80, size="medium")
            message("Press C to Continue or  Q to Quit", White, y_coordinate=50, size="small")
            pygame.display.update()
            display_score(Length_of_snake - 1)
            pygame.display.update()

            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        game_ended = True
                        game_exit = False
                    if event.key == pygame.K_p:
                        main()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_ended = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x1_next = -10
                    y1_next = 0
                elif event.key == pygame.K_RIGHT:
                    x1_next = 10
                    y1_next = 0
                elif event.key == pygame.K_UP:
                    y1_next = -10
                    x1_next = 0
                elif event.key == pygame.K_DOWN:
                    y1_next = 10
                    x1_next = 0

        if x1 >= Display_size_w or x1 < 0 or y1 >= Display_size_h or y1 < 0:
            game_exit = True
        x1 += x1_next
        y1 += y1_next
        Display_window.fill(Grey)
        pygame.draw.rect(Display_window, Red, [food_x, food_y, snake_size, snake_size])


        snake_Head = []
        snake_Head.append(x1)
        snake_Head.append(y1)
        snake_List.append(snake_Head)
        if len(snake_List) > Length_of_snake:
            del snake_List[0]

        for x in snake_List[:-1]:
            if x == snake_Head:
                game_exit = True

        snake(snake_size, snake_List)
        display_score(Length_of_snake - 1)

        pygame.display.update()

        if x1 == food_x and y1 == food_y:
            food_x = round(random.randrange(0, Display_size_w - snake_size) / 10.0) * 10.0
            food_y = round(random.randrange(0, Display_size_h - snake_size) / 10.0) * 10.0
            Length_of_snake += 1

        Timer.tick(snake_speed)

    pygame.quit()
    quit()


welcome()
main()
