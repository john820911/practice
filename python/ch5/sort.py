a = [1, 2, 3]
b = (1, 2, 3)
c = [(1, 9), (2, 8), (3, 7)]
d = ([1, 9], [2, 8], [3, 7])
e = set(a)
f = dict(c)
print sorted(a)
print sorted(b)
print sorted(c)
print sorted(d)
print sorted(e)
print sorted(f)
print set(sorted(e))
print dict(sorted(f.iteritems()))

from operator import itemgetter
print sorted(f.iteritems(), key=lambda x:x[1])
print sorted(f.iteritems(), key=itemgetter(1))
