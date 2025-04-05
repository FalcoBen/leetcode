#include <libc.h>


void ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void moveZeroes(int *nums, int numsSize) 
{
	int i = 0;
	int j;
	while(i < numsSize - 1)
	{
		j = 0;
		while(j < numsSize - 1)
		{
			if(nums[j] == 0)
				ft_swap(&nums[j], &nums[j + 1]);
			j++;
		}
		i++;
	}
}


int main()
{
	int arr[] = {0,0,4,0,12};
	int size = sizeof(arr) / sizeof(arr[0]);
	moveZeroes(arr, size);
	int i = 0;
	for(int i = 0; i < size; i++)
		printf("%d\t", arr[i]);

}
