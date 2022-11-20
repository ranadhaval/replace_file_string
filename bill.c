#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *replace(char *s,char *new_word,char *old_word)
{
int new_length = strlen(new_word);
int old_length = strlen(old_word);
int i=0,count=0;
for(i=0;s[i]!='\0';i++)
{
    if(strstr(&s[i],old_word)==&s[i])
    {
        count++;
        i=i+old_length-1;
    }
}
char * resultstring ;
resultstring = (char*)malloc(i+count*(new_length -old_length));
i=0;

while(*s)
{
    if(strstr(s,old_word)==s)
    {
        strcpy(&resultstring[i],new_word);
        i+=new_length;
        s+=old_length;
    }
    else
    {
        resultstring[i] =*s;
        s++;
        i++;
    }
}
resultstring[i]='\0';

return resultstring;

}


int main()
{

char str[200];
FILE *ptr1,*ptr2;
ptr1=fopen("nn.txt","r");
fgets(str,200,ptr1);
printf("%s",str);

// make next file
char *newstr =str;

newstr = replace(str,"dhaval","name");
newstr = replace(newstr,"deeps","geeks");
ptr2=fopen("gf.txt","w");
fprintf(ptr2,"%s",newstr);
printf("\n");
printf("new string::: %s",newstr);
}
