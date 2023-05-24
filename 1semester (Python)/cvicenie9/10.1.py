def nested_sum(listt):
    t = 0
    for i in listt:
        for b in i:
            t = t + b
    return t

t =  [[1, 2], [3], [4, 5, 6]]
print(nested_sum(t))
