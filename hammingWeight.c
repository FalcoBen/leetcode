#include <libc.h>

int hammingWeight(int n) 
{
	int i = 30;
	int byte[32] = {0};
	int x = 0;
	while(i >= 0)
	{
		if((n >> i) & 1)
			byte[x] = (byte[x] << 1) | 1; 
		else 
			byte[x] = byte[x] << 1;
		x++;
		i--;
	}
	int z = 0;
	int counter = 0;
	while(z < 31)
	{
		if(byte[z] == 1)
			counter++;
		z++;
	}
	return counter;
}


int main()
{
	int n = 2147483645;
    // print_bits(n);
	printf("%d\n", hammingWeight(n));
}