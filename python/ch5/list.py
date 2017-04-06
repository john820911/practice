#1. append(x), extend(x), insert(i, x), remove(x), pop(i), index(x), count(x),
#   sort(), reverse()
a = [1, 2, 3]
a.append(4)
a.extend([5, 6, 7])
a.insert(7, 8)
a.remove(8)
a.pop(6)
print a.index(6)
print a.count(6)

#b. stack, queue
a = [1, 2, 3]
a.append(4)
a.pop()
print a
from collections import deque
a = deque([1, 2, 3])
a.append(4)
a.popleft()
print a

#c. filter, map, reduce
a = []
for x in range(1, 11, 1):
	if x % 2 == 0 or x % 3 == 0:
		a.append(x)
print a
def f(x):
	return x % 2 == 0 or x % 3 == 0
a = filter(f, range(1, 11, 1))
print a
a = [ x for x in range(1, 11, 1) if x % 2 == 0 or x % 3 == 0 ]
print a
a = []
for x in range(1, 11, 1):
	a.append(x ** 2)
print a
def f(x):
	return x ** 2
a = map(f, range(1, 11, 1))
print a
a = [ x ** 2 for x in range(1, 11, 1) ]
print a
a = []
for x in range(1, 4, 1):
	for y in range(1, 6, 2):
		if x is not y:
			a.append((x, y))
print a
def f(x, y):
	return x**2 + 2*x*y + y**2
a = map(f, range(1, 4, 1), range(1, 4, 1))
print a
a = [ (x, y) for x in range(1, 4, 1) for y in range(1, 6, 2) if x is not y ]
print a
def sum(seq):
	def f(x, y):
		return x + y
	return reduce(f, seq)
a = sum(range(1, 11, 1))
print a

#d. transpose
a = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
a_t = []
for i in range(len(a[0])):
	a_t_s = []
	for a_s in a:
		a_t_s.append(a_s[i])
	a_t.append(a_t_s)
print a_t
a = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
a_t = [ [ a_s[i] for a_s in a ] for i in range(len(a[0])) ]
print a_t
a = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
a_t = zip(*a)
print a_t
