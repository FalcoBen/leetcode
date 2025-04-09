#include <unistd.h>
#include <limits.h>
#include <libc.h>


int removeDuplicates(int *nums, int numsSize) 
{
	int i = 0;
	int writed[2000] = {0};
	int offset = 1000;
	int j = 0;
	printf("numsize%d\n", numsSize);
	while(i < numsSize)
	{
		if(writed[nums[i] + offset] == 0)
		{
			nums[j] = nums[i];
			writed[nums[i] + offset] = 1;
			j++;
		}
		i++;
	}
	return j;
}

int main()
{
	int arr[] = {-1,2};
	int size = sizeof(arr) / sizeof(arr[0]);
	for(int i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	int k = removeDuplicates(arr, size);
	printf("\nk = %d\n", k);
	printf("\nafter\n");
	for(int i = 0; i < k; i++)
		printf("%d\t", arr[i]);
}