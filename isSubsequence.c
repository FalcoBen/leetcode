#include <libc.h>
#include <stdbool.h>

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

bool isSubsequence(char *s, char *t) 
{
	int i = 0;
	int j = 0;
	int counter = 0;
	int len = ft_strlen(s);
	while(t[i])
	{
		if (t[i] == s[j])
		{
			counter++;
			j++;
		}
		i++;
	}
	if (counter == len)
		return true;
	return false;
}
int main()
{
	char *s = "abc";
	char  *t = "acbgd";
	printf("%d", isSubsequence(s, t));
}