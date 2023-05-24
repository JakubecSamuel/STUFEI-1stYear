import turtle
import math

def polyline(t, n, length, angle):
    for i in range(n):
        t.forward(length)
        t.left(angle)

def arc(t, r, angle):
    arc_length = 2 * math.pi * r * abs(angle) / 360
    n = int(arc_length / 4) + 3
    step_length = arc_length / n
    step_angle = float(angle) / n
    t.left(step_angle/2)
    polyline(t, n, step_length, step_angle)
    t.right(step_angle/2)
    
def petal(t, r, angle):
    for i in range(2):
        arc(t, r, angle)
        t.left(180-angle)

def kvietok(t,x,y,z):
    for i in range(x):
        petal(t, y, z)
        t.left(360/x)
        
janka = turtle.Turtle()
x = int(input("Koľko lupeňov by mal mať tvoj kvet?"))
y = int(input("Aký radius by mali mať jednotlivé lupene?"))
z = int(input("Aký uhol by mal byť zvieraný v lupeni?"))
kvietok(janka,x,y,z)
