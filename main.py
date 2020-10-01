import pygame
import random
import math
from pygame import mixer

# mixer help us to handle all type of music in game whether it can be repeating, loading or anything to do with music.

# Initialize the Pygame
pygame.init()
# Creating a Starting Window of (width,height) in pixels
screen = pygame.display.set_mode((800, 600))
# just created a tuple using inner bracket
# after running program till now, game window will appear but it just closed in seconds.
# to bypass this we will create an infinite loop

# Background
background = pygame.image.load('background.png')

# Background Sound
mixer.music.load('smb_stage_clear.wav')
mixer.music.play(-1)
# here -1 is input to run for infinite as long as game persists...if we keep it empty at after certain moment of time,it
# will stop.

# Title and Icon
pygame.display.set_caption("Spaceship & Zombies")
icon = pygame.image.load('spaceship.png')
pygame.display.set_icon(icon)
# in bracket here comes variable name 'icon' which is created in above line.
# Now for background or something which we want persistently during the game ...should be written for game loop.


# Player
playerImg = pygame.image.load('Player.png')
playerX = 340
playerY = 480  # These coordinates are chosen to keep in mind about the starting position of player.
playerX_change = 0

# Enemy
enemyImg = []
enemyX = []
enemyY = []
enemyX_change = []
enemyY_change = []
num_of_enemies = 6
for i in range(num_of_enemies):
    enemyImg.append(pygame.image.load('zombie.png'))
    enemyX.append(random.randint(0, 735))
    enemyY.append(random.randint(50, 150))
    enemyX_change.append(2)
    enemyY_change.append(40)

# Bullet

# Ready - You can't see the bullet on screen
# Fire - The bullet is currently moving

bulletImg = pygame.image.load('bullets.png')
bulletX = 0
bulletY = 480
bulletX_change = 0
bulletY_change = 10
bullet_state = "ready"

# Score
score_value = 0
font = pygame.font.Font('Ubuntu-Italic.ttf', 32)

textX = 10
textY = 10

# Game Over text
over_font = pygame.font.Font('Ubuntu-Bold.ttf', 64)


def show_score(x, y):
    score = font.render("Score : " + str(score_value), True, (0, 0, 0), (255, 255, 255))
    screen.blit(score, (x, y))


def game_over_text():
    over_text = over_font.render("GAME OVER", True, (0, 0, 0), (255, 255, 255))
    screen.blit(over_text, (250, 200))


def player(X, Y):
    screen.blit(playerImg, (X, Y))


# blit just means to draw.

def enemy(X, Y, i):
    screen.blit(enemyImg[i], (X, Y))


def fire_bullet(X, Y):
    global bullet_state
    bullet_state = "fire"
    screen.blit(bulletImg, (X + 16, Y + 10))


def isCollision(enemyX, enemyY, bulletX, bulletY):
    distance = math.sqrt((math.pow(enemyX - bulletX, 2)) + (math.pow(enemyY - bulletY, 2)))
    if distance < 32:
        return True
    else:
        return False


# Game Loop
running = True
while running:
    # RGB color for background
    screen.fill((0, 0, 0))  # don't forget inner bracket
    # Background Image
    screen.blit(background, (0, 0))
    # playerY -= 0.1 .. just to understand mechanics of movement in game development
    # print(playerX) .. just to show how co-ordinates are changing.
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        # if keystroke is pressed, check whether it is left or right arrow.
        if event.type == pygame.KEYDOWN:  # when key is pressed
            # print("Any key is pressed other than arrow")
            if event.key == pygame.K_LEFT:  # here comes key not type
                # print("Left arrow key is pressed")
                playerX_change = -5
            if event.key == pygame.K_RIGHT:
                # print("Right arrow key is pressed")
                playerX_change = 5
            if event.key == pygame.K_SPACE:
                if bullet_state == "ready":
                    bullet_sound = mixer.Sound('laser.wav')
                    bullet_sound.play()
                    # Get the current x coordinate of spaceship & store in variable bulletX
                    bulletX = playerX
                    fire_bullet(bulletX, bulletY)
        if event.type == pygame.KEYUP:  # when key is released
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                # print(" Arrow key is released")
                playerX_change = 0

    # Checking for boundaries of spaceship (so that it doesn't goes out of bounds)
    playerX += playerX_change
    if playerX <= 0:
        playerX = 0
    elif playerX >= 736:  # (800 - 64) or (width - size of spaceship.png)
        playerX = 736

    # Enemy Movement
    for i in range(num_of_enemies):
        # Game Over
        if enemyY[i] > 440:
            game_sound = mixer.Sound('smb_gameover.wav')
            game_sound.play()
            for j in range(num_of_enemies):
                enemyY[j] = 2000
            game_over_text()
            break
        enemyX[i] += enemyX_change[i]
        if enemyX[i] <= 0:
            enemyX_change[i] = 4
            enemyY[i] += enemyY_change[i]
        elif enemyX[i] >= 736:  # (800 - 64) or (width - size of zombie.png)
            enemyX_change[i] = -4
            enemyY[i] += enemyY_change[i]
        # Collision
        collision = isCollision(enemyX[i], enemyY[i], bulletX, bulletY)
        if collision:
            collision_sound = mixer.Sound('smb_coin.wav')
            collision_sound.play()
            bulletY = 480
            bullet_state = "ready"
            score_value += 1
            enemyX[i] = random.randint(0, 735)
            enemyY[i] = random.randint(50, 150)
        enemy(enemyX[i], enemyY[i], i)

    # Bullet Movement
    if bulletY <= 0:
        bulletY = 480
        bullet_state = "ready"
    if bullet_state == "fire":
        fire_bullet(bulletX, bulletY)
        bulletY -= bulletY_change

    player(playerX, playerY)
    show_score(textX, textY)
    pygame.display.update()
# pygame provides something to update in display window... therefore we are going to use that to feel the changes we did
# Now if we will run, it may hang the window...no cross button will work. Why it will hang? because we don't
# have a event of quit. we declared a running value for True. removing pass from while loop and seeing what's is
# happening in game window. Let's just code in while loop again we go to a for loop for a variable event from all the
# events happening in window. NOW WE CHECK IF WE CLICK CLOSE button then we get out of while loop by making it False.
