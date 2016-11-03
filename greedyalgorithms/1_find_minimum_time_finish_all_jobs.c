#include <stdio.h>
#include <stdlib.h>

int getMaximum(int *jobs, int size)
{
	int result = jobs[0];
	for(int index = 1; index < size; index++)
		if(jobs[index] > result)
			result = jobs[index];
	return result;
}

int min(int a, int b)
{
	return a < b ? a: b;
}

int isPossible(int *jobs, int time, int assignees, int size)
{
	int count = 1, currTime = 0;
	for(int index = 0; index < size; )
	{
		if(currTime + jobs[index] > time)
		{
			currTime = 0;
			count++;
		}
		else 
		{
			currTime += jobs[index];
			index++;
		}
	}
	return (count <= assignees);
}

int findMinimumTime(int *jobs, int size, int assignees, int time)
{
	int end = 0, start = 0, index, result, maxTimeJob;
    for (index = 0; index < size; index++)
        end += jobs[index];
    result = end;
    maxTimeJob = getMaximum(jobs, size);

    while(start <= end)
    {
        int middle = (start + end) / 2;
        if (middle >= maxTimeJob && isPossible(jobs, middle, assignees, size))
        {
            result = min(result, middle);
            end = middle - 1;
        }
        else
            start = middle + 1;
    } 
    return (result * time);
}

int main()
{
	int *jobs, size, assignees, time;
	printf("Enter number of jobs\n");
	scanf("%d", &size);

	printf("Enter time intervals for jobs\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &jobs[index]);

	printf("Enter number of assignees available\n");
	scanf("%d", &assignees);

	printf("Enter time taken by assign to finish one unit of job\n");
	scanf("%d", &time);

	printf("The minimum time = %d is required to finish all jobs\n", 
		findMinimumTime(jobs, size, assignees, time));
	return 0;
}