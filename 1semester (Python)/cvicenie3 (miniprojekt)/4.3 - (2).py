import turtle
def square(t, length):
    for i in range(4):
        t.forward(length)
        t.left(90)
        
janka = turtle.Turtle()
square(janka, 100)
