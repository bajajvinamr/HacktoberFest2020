import pygame
import math
import time

pygame.init()
clock = pygame.time.Clock()
display = pygame.display.set_mode((500, 500))
r_sec = 100
r_min = 75
r_hour = 45
pi = 3.14
while True:
    display.fill((0, 0, 0))
    pygame.draw.circle(display, (255, 255,255), (250, 250), 120, 2)
    t = time.localtime()
    sec = (int(time.strftime('%S', t))) * 6
    min = (int(time.strftime('%M', t))) * 6
    hour = (int(time.strftime('%H', t))) * 30
    sec_x = int(250 + r_sec * (math.cos((pi / 180) * (sec-90))))
    sec_y = int(250 + r_sec * math.sin((pi / 180) * (sec-90)))
    min_x = int(250 + r_min * (math.cos((pi / 180) * (min-90))))
    min_y = int(250 + r_min * (math.sin((pi / 180) * (min-90))))
    hour_x = int(250 + r_hour * (math.cos((pi / 180) * (hour-90))))
    hour_y = int(250 + r_hour * (math.sin((pi / 180) * (hour-90))))
    pygame.draw.line(display, (255, 0, 0), (250, 250), (sec_x, sec_y), 5)
    pygame.draw.arc(display, (255, 0, 0), [150, 150, 200, 200], -(pi / 180) * (sec - 90), pi / 2, 3)
    pygame.draw.arc(display, (255, 0, 255), [182, 182, 142, 142], -(pi / 180) * (min - 90), pi / 2, 3)
    pygame.draw.arc(display, (255, 255, 0), [200, 200, 94, 94], -(pi / 180) * ((hour/3) - 60), pi / 2, 3)
    pygame.draw.line(display, (255, 0, 255), (250, 250), (min_x, min_y), 5)
    pygame.draw.line(display, (255, 255, 0), (250, 250), (hour_x, hour_y), 5)
    pygame.display.update()
pygame.quit()
