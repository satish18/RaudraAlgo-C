#include <stdio.h>
#include <stdlib.h>

int fun(int num)
{
    return (num*num - 10*num - 20);
}

int Search(int start, int end)
{
    if (end >= start)
    {
        int middle = (start + end) / 2;
        if (fun(middle) > 0 && (middle == start || fun(middle - 1) <= 0))
            return middle;
        return fun(middle <= 0)? Search((middle + 1), end): Search(start, (middle - 1));
    }
    return -1;
}

int getFirstPositive()
{
    int index;
    if(fun(0) > 0)
        return 0;

    for(index = 1; fun(index) <= 0; index*=2);
    return Search(index/2, index);
}

int main()
{
    printf("The value n where fun() becomes positive first is %d", getFirstPositive());
    return 0;
}
