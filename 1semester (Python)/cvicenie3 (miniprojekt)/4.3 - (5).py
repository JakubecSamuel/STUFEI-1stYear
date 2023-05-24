import turtle
import math

def polygon(t, n, length):
    for i in range(n):
        t.forward(length)
        t.left(n/n)

def circle(t, r, angle):
    polygon(t, angle, r)
        
janka = turtle.Turtle()
r = (math.pi*200/360)
circle(janka, r, 360)
