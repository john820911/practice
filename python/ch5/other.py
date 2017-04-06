a = [ x for x in range(1, 4, 1) ]
b = [ x for x in range(9, 6, -1) ]
c = { x:10-x for x in range(1, 4, 1) }
for k, v in enumerate(b):
	print k+1, v
for k, v in zip(a, b):
	print k, v
for k in c.keys():
	print k, c[k]
for k, v in c.iteritems():
	print k, v
