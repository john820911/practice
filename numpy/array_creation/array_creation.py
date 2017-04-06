import numpy as np
#1. array creation
x = np.array([[1, 2, 3], [4, 5, 6]], dtype="int64", copy=True, order="K", subok=True, ndmin=0)
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize

#2. zeros, zeros_like, ones, ones_like, empty, empty_like, eye, identity
x = np.zeros(2)
x = np.zeros((2,))
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.zeros((1, 2))
x = np.zeros((1, 2), dtype="float64", order="C")
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.ones(2)
x = np.ones((2,))
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.ones((1, 2))
x = np.ones((1, 2), dtype="float64", order="C")
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.empty(2)
x = np.empty((2,))
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.empty((1, 2))
x = np.empty((1, 2), dtype="float64", order="C")
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.array([[1., 2., 3.], [4., 5., 6.]], dtype="float64", copy=True, order="K", subok=True, ndmin=0)
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.zeros_like(x)
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.ones_like(x)
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.empty_like(x)
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.ones(1, dtype=[("time", [("hour", "int64"), ("min", "int64")]), ("sec", "float64")])
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.eye(2)
x = np.eye(2, 6)
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x = np.eye(2, 6, k=4)
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize
x=  np.identity(2)
print x, x.ndim, x.shape, x.size, x.dtype, x.itemsize

#3. arange, linespace, logspace
x = np.arange(6).reshape(2, 3)
print x
x = np.linspace(0, 6, num=4, endpoint=False, retstep=True)
print x
x = np.linspace(0, 6, num=5, endpoint=True, retstep=True) 
print x
x = np.logspace(0, 6, num=4, endpoint=False, base=10)
print x

#4. meshgrid, mgrid, ogrd, r_
x = np.meshgrid(np.arange(0, 3, 1), np.arange(0, 10, 2))
print x
x = np.mgrid[0:3:1, 0:10:2]
print x
x = np.ogrid[0:3:1, 0:10:2]
print x
x = np.r_[0:3:1, 0:10:5j]
print x
x = np.r_[np.arange(0, 3, 1), np.linspace(0, 10, num=5, endpoint=True)]
print x
x = np.r_['0,1,1', 0:3:1, 0:10:3j]
print x
x = np.r_['0,2,1', 0:3:1, 0:10:3j]
print x
x = np.r_['1,2,1', 0:3:1, 0:10:3j]
print x
x = np.r_['0,2,0', 0:3:1, 0:10:3j]
print x
x = np.r_['1,2,0', 0:3:1, 0:10:3j]
print x

