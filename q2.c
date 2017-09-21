#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct keyValue{
char key[10];
int value;
struct keyValue *next;
};

int hashFunction(int n)
{
return n%9;
}



int main()
{
struct keyValue* hashTable[9];
char key[10];
int value;
char cont='Y';
do
{
printf("\nEnter key:");
scanf(" %s",key);
printf("\nEnter value:");
scanf("%d",&value);
int position=hashFunction(strlen(key));
if(hashTable[position]==NULL)
{
hashTable[position]=(struct keyValue*)malloc(sizeof(struct keyValue));
strcpy(hashTable[position]->key,key);
hashTable[position]->value=value;
hashTable[position]->next=NULL;
}
else
{
struct keyValue* start=&hashTable[position];
while(start->next!=NULL)
start=start->next;
start->next=(struct keyValue*)malloc(sizeof(struct keyValue));
strcpy(start->next->key,key);
start->next->value=value;
start->next->next=NULL;
}
printf("\n Continue?");
scanf(" %c",&cont);
}
while(cont=='Y'||cont=='y');

char search[10];
printf("\nEnter key to search:");
scanf(" %s",search);
int searchPos=hashFunction(strlen(search));
printf("\nThe bucket number is %d\n",searchPos);
struct keyValue* s=&hashTable[searchPos];
while(s!=NULL)
{
if(strcmp(search,s->key)==0)
{
printf("The value is %d",s->value);
break;
}
else
{
s=s->next;
}
} 
return 0;

}
