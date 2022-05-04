#include <stdio.h>
#include <string.h>
struct student
{
char name[20];
char branch[20];
}s;
int main()
{
struct student *st;
printf("Enter name: ");
scanf("%s", s.name);
printf("Enter branch: ");
scanf("%s", s.branch);
st = &s;
printf("\nName: %s",st->name);
printf("\nBranch: %s",st->branch);
}
