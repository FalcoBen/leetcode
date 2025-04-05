#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}
int count_chara(char *str)
{
    int counter = 1;
    int i = 0;
    while(str[i])
    {
        if(str[i] == ' ' || str[i] == '\t')
            i++;
        else
            counter++;
        i++;
    }
    return counter;
}
char *epur_str(char *str)
{
    int i = 0;
    int flag = 1;
    int j = 0;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    int len = count_chara(str);
    while(str[i] && len > 0)
    {
            if(flag == 0)
            {
                str[j] = ' ';
                j++;
            }
            while(str[i] == ' ' || str[i] == '\t')
                i++;
            while(str[i] && str[i] != ' ' && str[i] != '\t')
            {
                str[j] = str[i];
                i++;
                j++;
            }
            while(str[i] == ' ' || str[i] == '\t')
                i++;
            flag = 0;
            len--;    
        }
        str[j] = '\0';
        return str;
}
//"      fahd    ben   allal     ";
void put_char(char c)
{
    write(1, &c, 1);
}
void  *reverseWords(char *s) 
{
    char *rev = NULL;
    char *tmp = epur_str(s);
    int len = ft_strlen(tmp);
    char *dest = malloc(sizeof(char ) * (len + 1));
    dest[len] = '\0';
    len--;
    int i = 0;
    while(len > 0 && dest[i])
    {
       // while(s[len] == ' ' || s[len] == '\t')
         //   len--;
        printf("leen == %d\n", len);
        if(tmp[len - 1] == ' ')
        {
            rev = &tmp[len];
            while(*rev && *rev != ' ')
            {
                dest[i] = *rev;
                rev++;
                i++;
            }
            dest[i++] = ' ';
        }
        if(len == 0)
        {
            rev = &tmp[len];
            while(*rev && *rev != ' ')
            {
                dest[i] = *rev;
                rev++;
                i++;
            }
        }
        len--;
    }
    //dest[i] = '\0';
    return dest;
}




int main()
{
    char str[] = "a good   example";
    //char *reslut = reverseWords(str);
    
    //printf("%s\n", epur_str(str));
   // printf("%d\n", count_chara(str));
    char *result = reverseWords(str);
    printf("%s\n", result);

}