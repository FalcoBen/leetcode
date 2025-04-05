#include <stdio.h>

int lengthOfLastWord(char* s) 
{
    int i = 0;
    int counter = 0;
    while(s[i])
        i++;
    i--;
    printf("[[%d]]", i);
    while(s[i] == ' ' && i >= 0)
        i--;
    
    
    while(s[i] != ' ' && i >= 0)
        i--;
    i++; 
    while(s[i] != ' ' && s[i])
    {
        counter++;
        i++;
    }
    return counter;
}


/*int lengthOfLastWord(char *s) 
{
    while(*s)
        s++;
    
}
*/

int main(int argc, char **argv)
{
    char *str = "a";
    printf("%d\n", lengthOfLastWord(str));
}