Author: İlker Polat
Email: ilkerpolat3@gmail.com

#How does it work

This tool is for approximately finding total cache size of CPU. After creating arrays in increasing order and then reads random values from arrays, the ratio of the time spend in read/write operation to the size of array gives us a clue about are caches filled up. 

L1 and L2 timing differences are not very noticeable but after filling up L3, you can see in the plot how ratio changes. 

In python script, firstly compile&run program. Then taking output of program (array size and ratio) and filtering noise. "polyValues" is a polynom coefficenies of  polynom fitted to our results. Rest of the script basicly try to find where concavity changes (point of inflection (POI)). Because of there will be many POI, only one of than is true. If you have higher polynom degree, you will get more POI. 

You can see plots with filter and raw.

https://github.com/ilkerpolat6/cache_measurement/blob/master/filtered_plot.png
https://github.com/ilkerpolat6/cache_measurement/blob/master/raw_plotted.png
#How to use

Just run "printplot.py". It will compile and run program and then print plot.

`python printplot.pys`

While running program, I recommend close all other working programs. Also you don't need to run compiled program every time if you didn't change "cache_measurment.cpp".

You can check is result correct with:

`lscpu | egrep cache`

Have Fun!!!
