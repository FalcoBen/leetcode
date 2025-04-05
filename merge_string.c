#include <stdio.h>
#include <stdlib.h>


int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}

char *mergeAlternately(char *word1, char *word2)
{
    int len = ft_strlen(word1) + ft_strlen(word2);
    char *dest = malloc(sizeof(char) * (len + 1));
    if(!dest)
        return NULL;
    int x = 0;
    int i = 0;
    int j = 0;
    /*while(word1[i] && word2[j])
    {
        dest[x] = word1[i];
        x++;
        dest[x] = word2[j];
        i++;
        j++;
        x++;
    }*/
    while(len)
    {
        if(word1[i])
        {
            dest[x] = word1[i];
            i++;
            x++;
        }
        if(word2[j])
        {
            dest[x] = word2[j];
            j++;
            x++;
        }
        len--;
    }
    dest[x] = '\0';
    return dest;
}

int main()
{
    char *s1 = "ab";
    char *s2 = "pqrs";
    char *reslut = mergeAlternately(s1, s2);
    printf("%s\n", reslut);
}