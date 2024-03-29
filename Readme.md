Author: İlker Polat

Email: ilkerpolat3@gmail.com

# How does it work
This tool is for approximately finding the total cache size of CPU. After creating arrays in increasing order and then reads random values from arrays, the ratio of the time spend in read/write operation to the size of array gives us a clue about are caches filled up. 

L1 and L2 timing differences are not very noticeable but after filling up L3, you can see in the plot how the ratio changes. 

In python script, firstly compile&run program. Then takes the output of the program (array size and ratio) and use noise filter. "polyValues" are polynomial coefficients of polynomial fitted to our results. Rest of the script basically try to find where concavity changes (point of inflection (POI)). Because there will be many POI, only one of them is true. If you have a higher polynomial degree, you will get more POI. 

You can see plots with noise filter and raw for 4384kB cache.

![alt text](https://github.com/ilkerpolat6/cache_measurement/blob/master/filtered_plot.png)
![alt text](https://github.com/ilkerpolat6/cache_measurement/blob/master/raw_plot.png)

# How to use

Just run "printplot.py". It will compile and run the program and then print plot.

`python printplot.py`

While running the program, I recommend close all other working programs. Also, you don't need to run the compiled program every time if you didn't change "cache_measurment.cpp".

You can check the result with:

`lscpu | egrep cache`

Have Fun!!!

# Fun Fact

If you run this tool for a long time you will see a similar plot like below.

![alt text](https://github.com/ilkerpolat6/cache_measurement/blob/master/long_run.png)

The reason for this curve is the probability of cache misses. If your cache size is X and your data is smaller than X, you will get 0 miss rate. If data is 2X, your miss rate will be 1/2. And if it is 3x, your miss rate will be 2/3 and goes on like 3/4, 5/6. Therefore there is a strong relation between miss rate and data access time we are getting the same plot with the miss rate.

I think it is fun to see the practical results of such a theoretical method.

# TO-DO

Find cache size with miss rate described at above.
