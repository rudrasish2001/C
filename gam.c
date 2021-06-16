#include<stdio.h>
#include<string.h>
struct bookinfo{
char name[50];
char author[50];
char price[100];
};


int main()
(  
 struct bookinfo bk1;
 struct bookinfo bk2;

 

   strcpy(bk1.name,"PHYSICS");  
   strcpy(bk1.author,"SL AURORA");
   strcpy(bk1.price,"337");

   strcpy(bk2.name."MATHS");
   strcpy(bk2.author."S.CHAND"); 
   strcpy(bk2.price,"837");

   printf("bk1 name:%s\n",bk1.title);
   printf("bk1 author:%s\n",bk1.author);
   printf("bk1 price:%s\n",bk1.price);

   printf("bk2 name:%s\n",bk2.title);
   printf("bk2 author:%s\n",bk2.author);
   printf("bk2 price:%s\n",bk2.price);


return 0;

}























