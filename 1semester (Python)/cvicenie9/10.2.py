def nested_sum(listt):
    t = []
    b = 0
    for i in listt:
            b = b + i
            t.append(b)
    return t

t =  [1, 2, 3]
print(nested_sum(t))
