import turtle
def polygon(t, n):
    for i in range(n):
        t.forward(100)
        t.left(360/n)
        
janka = turtle.Turtle()
polygon(janka, 8)
