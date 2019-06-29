#include <iostream>
using namespace std;
#include <time.h>
#include <unistd.h>

#define maxCacheSize 20000 //(kbayt)2 times bigger than real cache size recommended
#define minCacheSize 1     //(kbayt)Smaller better for aproximate cache size at python script (more data make it more consistent)
#define searchStep 25      //(kbayt)Smaller better for aproximate cache size at python script (more data make it more consistent)
#define accessLoop 50      //How much time you will spent for each search

int createArray(int size, int loop)
{
    clock_t start, stop;
    int *pa = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i += 16)
    {
        pa[i] = 1;
    }
    int a;                         //we need to access all variables. Otherwise compile eliminate unused variables
    for (int k = 0; k < loop; k++) //random access loop
    {
        a = pa[size / 10];
        for (int i = 0; i < size; i += 64)
        {
            long randnum = rand(); //max is 32767
            randnum = (randnum << 16) | rand();
            if (randnum < 0)
                randnum = -randnum;
            randnum %= size;
            a = pa[randnum];
        }
    }
    free(pa);

    return a;
}

int main()
{
    clock_t start, stop;
    double time0;
    unsigned long int counter = 0;
    int size = 1, temp;
    cout << "size\ttime" << endl;

    for (int i = minCacheSize; i < maxCacheSize; i = i + searchStep) //"i" present 1 kbayt
    {
        size = i * 256;
        start = clock();
        temp = createArray(size, accessLoop);
        stop = clock();
        time0 = stop - start;
        time0 = time0 / i;
        cout << i << "\t";
        cout << time0 << endl;
    }

    return 0;
}
