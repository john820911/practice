#1. construction
a = [1, 2, 3]
b = (1, 2, 3)
c = [("one", 1), ("two", 2), ("three", 3)]
d = ([1, 9], [2, 8], [3, 7])
e = set(a) #set(b) is also the same
f = dict(c) #set(d) is also the same
print a
print b
print c
print d
print e
print f

#2. simplier construction
a = [ x for x in range(1, 4, 1) ]
e = { x for x in range(1, 4, 1) }
f = { x:10-x for x in range(1, 4, 1) }
f = dict(one=1, two=2, three=3)
print a
print e
print f

#3. print element
print a[0]
print b[0]
print c[0], c[0][1]
print d[0], d[0][0]
print f["one"]

#4. in
print 1 in a
print 1 in b
print ("one", 1) in c
print [1, 9] in d
print 1 in e
print "one" in f

#5. assign element
a[0] = 1
c[0] = ("one", 1)
d[0][0] = 1
f["one"] = 1
print a
print c
print d
print f

#6. del
del a[0]
del c[0]
del d[0][0]
del f["one"]
print a
print c
print d
print f

#7. sort, reverse
sorted(a)
sorted(b)
sorted(c)
sorted(d)
sorted(e)
sorted(f)
print a
print b
print c
print d
print e
print f

