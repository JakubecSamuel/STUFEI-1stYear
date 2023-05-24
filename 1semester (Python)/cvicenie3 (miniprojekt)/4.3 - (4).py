import turtle
import math

def polygon(t, n, length):
    for i in range(n):
        t.forward(length)
        t.left(360/n)

def circle(t, r):
    polygon(t, 360, r)
        
janka = turtle.Turtle()
r = (math.pi*100/360)
circle(janka, r)
