def corresponding(a, aStart, bStart, dist):
    if a in range(aStart, (aStart+dist)):
        return bStart + (a - aStart)
    else:
        return a
    



(word, b) = input().split(':')


(aStart, bStart, dist) = input.split(' ')

things = dict()
for i in range (0, b.length()):
    things[b[i]] = b


