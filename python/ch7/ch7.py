#1. str v.s repr
s = "This is a string!!\n"
x = 1.0/7.0
print str(s) #This is a string!!
print repr(s) #"This is a string!!\n"
print str(x) #round
print repr(x) #detailed
#comment: str() for string, repr() for numeric

#2. str.ljust(), str.rjust(), str.center(), str.zfill(), str.format()
for x in range(1, 11, 1):
	print repr(x).zfill(4).ljust(4), repr(x**2).zfill(4).rjust(4),
	print repr(x**3).zfill(4).center(4)
for x in range(1, 11, 1):
	print "{0:2} {1:3} {2:4}".format(x, x**2, x**3)

#3 str.format() advanced usage
print "{} name is {}".format("My", "Johnson")
print "{0} name is {1}".format("Your", "Johnson")
print "{Who} name is {Name}".format(Who="His", Name="Johnson")
#comment: {0:10}--ljust for str, {0:10d}--rjust for numeric, {0:.3f}--round

#4 r, w, a, b, +
#comment: 
#r -- open, read
#w -- create, clean, write
#a -- create, append
#b -- binary
#+ -- both read & write

#5 file
f = open("read.txt", "r")
print f.read()
f.close()
f = open("read.txt", "r")
print f.readline()
print f.readline()
print f.readline()
print f.readline()
f.close()
with open("read.txt", "r") as f:
	print f.read()
f.close()
with open("read.txt", "r") as f:
	for line in f:
		print line
f.close()
#comment: f.read(), f.write(), f.seek()

#6 json
import json
fw = open("dump.json", "w+")
x = [1, 2, "Hi"]
json.dumps(x)
json.dump(x, fw)
fw.close()
fr = open("dump.json", "r+")
y = json.load(fr)
print y
fr.close()
