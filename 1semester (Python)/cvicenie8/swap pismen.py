def rotate_word(s,a):
    for c in s:
        new = ord(c) + a
        if new > 122:
            new = new - 26
        elif new < 97:
            new = new + 26
        print(chr(new), end = '')
        
rotate_word("abcdefgh", -1)

