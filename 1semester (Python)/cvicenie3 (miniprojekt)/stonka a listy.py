import turtle
import math

def polyline(t, n, dlzka, uhol):
    for i in range(n):
            t.forward(dlzka)
            t.left(uhol)

def arc(t, r, uhol):
    arc_length = 2 * math.pi * r * abs(uhol) / 360
    n = int(arc_length / 4) + 3
    step_length = arc_length / n
    step_angle = float(uhol) / n
    t.left(step_angle/2)
    polyline(t, n, step_length, step_angle)
    t.right(step_angle/2)
    
def petal(t, r, uhol):
    for i in range(2):
        arc(t, r, uhol)
        t.left(180-uhol)

def kvietok(t, x, y, z):
    for i in range(x):
        petal(t, y, z)
        t.left(360/x)

def stonka(t, u, d):
    t.left((0.75*360)-(u/2))
    arc(t, d, u)
    t.seth(0)
    
def listy(t, d, u):
    for i in range(2):
        petal(t, d, u)
        t.left(180-u)

def posun(t, p):
    t.pu()
    t.goto(p,0)
    t.seth(0)
    t.pd()
           
anduin = turtle.Turtle()
anduin.speed(0)
p = 0

for i in range(3):
    x = int(input("Počet lupeňov v kvete: "))
    y = int(input("Rádius lupeňov: "))
    z = int(input("Uhol zvieraný v lupeňoch: "))
    kvietok(anduin, x, y, z)
    u = int(input("Uhol stonky: "))
    d = int(input("Dĺžka stonky: "))
    stonka(anduin, u, d)
    a = int(input("Uhol listov: "))
    b = int(input("Dĺžka listov: "))
    listy(anduin, b, a)
    p = p+175
    posun(anduin, p)
    
           
