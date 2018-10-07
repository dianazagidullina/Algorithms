import numpy as np
X = np.array([[0, 0, 1], [0, 1, 1], [1, 0, 1], [1, 1, 1]])
Y = np.array([[0, 1, 1, 0]]).T
 
def func(x):
    return 1 / (1 + np.exp(-x))
 
def deriv(x):
    return x * (1 - x)
 
syn0 = np.random.uniform(0, 1, (3, 2))
syn1 = np.random.uniform(0, 1, (2, 1))
 
for iter in range(80000):
    l1 = func(np.dot(X, syn0))    
    l2 = func(np.dot(l1, syn1))
   
    error2 = Y - l2
    delta2 = error2 * deriv(l2)
   
    error1 = delta2.dot(syn1.T)
    delta1 = error1 * deriv(l1)
   
    syn1 += np.dot(l1.T, delta2)
    syn0 += 0.1 * np.dot(X.T, delta1)    
print(l2)