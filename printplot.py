import matplotlib.pyplot as plt
import numpy as np
import os
from scipy.interpolate import interp1d
from scipy.signal import lfilter

i_want_to_compile_and_run = 1

if(i_want_to_compile_and_run):
    os.system("g++ -O0 cache_measurement.cpp -o cache_measurement")#compile program without optimization
    os.system("./cache_measurement > cache_measurement.out")

x=np.loadtxt("cache_measurement.out",delimiter='\t',skiprows=1)
y=x[:,0]
x=x[:,1]

#some noise filtering
n = 15  # the larger n is, the smoother curve will be. If n is 1, you will get non-filtered plot
b = [1.0 / n] * n
a = 1
x = lfilter(b,a,x)

plt.xlabel("size of array created(kbayt)")
plt.ylabel("time spend in process / array size")
plt.plot(y,x)

#polynom fitting
polyDegree=5 #must be higher than 2. 5 work well.6 better   
polyValues = np.polyfit(y, x, polyDegree)
polyForm = np.poly1d(polyValues)
plt.plot(y,polyForm(y),"r--")
#finding POI
d=np.polyder(polyForm)
d=np.polyder(d)
d=np.roots(d)
plt.plot(d,polyForm(d),"go")

for a,b in zip(d,polyForm(d)): 
    plt.text(a, b, str(a))

plt.show()