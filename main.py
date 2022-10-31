import pygame
import random
import math

#initialize pygame
pygame.init()


#score
score_value=0
font = pygame.font.Font('freesansbold.ttf',32)

#show score
def show_score(x,y):
    score=font.render("SCORE: "+str(score_value),True,(255,255,255))
    screen.blit(score,(x,y))
#title changing and editing
pygame.display.set_caption("Space Invaders")
icon=pygame.image.load('game icon.png')
pygame.display.set_icon(icon)
 
#adding player image
playerImg = pygame.image.load('spaceship_1.png')
playerX = 370
playerY = 480
playerX_change = 0

#adding enemy image
enemyImg=[]
enemyX = []
enemyY = []
enemyX_change = []
num_enemy=6
enemy_state=[]

for i in range(num_enemy):
    enemyImg.append(pygame.image.load('ufo.png'))
    enemyX.append(random.randint(2,750))
    enemyY.append(40)
    enemy_state.append(1)
    enemyX_change.append(2.7)

#adding bullet image
bulletImg = pygame.image.load('bullet.png')
bulletY_change = 4
bulletY=460
bulletX=0
#bullet state variable 
bullet_state="ready"

def player(x,y): 
    #drawing image on surface
    screen.blit(playerImg,(x,y))

def enemy(x,y,i): 
    #drawing image on surface
    screen.blit(enemyImg[i],(x,y))

def fire_bullet(x,y):
    global bullet_state
    bullet_state="fire"
    screen.blit(bulletImg,(x+10,y+16))

def Iscollision(bulletX,bulletY,enemyX,enemyY):
    distance = math.sqrt(math.pow(bulletX-enemyX,2)+math.pow(bulletY-enemyY,2))
    if distance<27:
        return True
    else:
        return False

#screen create
screen = pygame.display.set_mode((800,600))

#back ground create
background = pygame.image.load("background.png")

running = True
while running:
    #background colour add
    screen.fill((0,0,0))
    #background image add
    screen.blit(background,(0,0))


    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            running = False
        
        #control spaceship movement
        if event.type == pygame.KEYDOWN:
            if bullet_state=="ready":
                if event.key == pygame.K_SPACE:
                    bulletX=playerX
                    fire_bullet(bulletX,bulletY)
            if event.key == pygame.K_KP_4:
                playerX_change = -1.3
            if event.key == pygame.K_KP_6:
                playerX_change = 1.3
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_KP_4:
                playerX_change = 0
            if event.key == pygame.K_KP_6:
                playerX_change = 0
        


    #movements
    playerX += playerX_change
    if bulletY<=0:
        bulletY=460
        bullet_state="ready"

    if bullet_state is "fire":
        fire_bullet(bulletX,bulletY)
        bulletY -= bulletY_change
    if playerX<=1:
        playerX = 1
    elif playerX>=759:
        playerX = 759
    for i in range(num_enemy):
        if enemy_state[i]!=0:
            enemyX[i] += enemyX_change[i]
            if enemyX[i]>=759 or enemyX[i]<=1:
                enemyX_change[i] *= -1
                enemyY[i] += 40
            #collision
            collision=Iscollision(bulletX,bulletY,enemyX[i],enemyY[i])
            if collision:
                enemy_state[i]=0
                bulletY=480
                bullet_state="ready"
                score_value+=1
                #enemyX[i] = random.randint(2,750)
                #enemyY[i] = 40
            enemy(enemyX[i],enemyY[i],i)

    player(playerX,playerY)
    show_score(10,10)
    pygame.display.update()