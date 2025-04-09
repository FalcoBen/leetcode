#include <libc.h>

int main(int ac, char **av)
{
	char *str = av[1];
	int i = 0;
	int writed[256] = {0};
	while(str[i])
	{
		if(writed[str[i]] == 0)
		{
			write(1, &str[i], 1);
			writed[str[i]] = 1;
		}
		i++;
	}
	return 0;
}