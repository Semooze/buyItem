#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int buyFood(int openAt[],int closeAt[],int walkTime);

int main(int argc,char *argv[]){
  int openAt[51];
  int closeAt[51];
  int walkTime=0;
  char Buffer [7];
  char *end;
  register int i=0;
  int cmpArray=0;
  
  /* get input from user and put into openAt 
     get string (to avoid user error)input check Is it "n" character ?
     then convert string to integer number and assign into openAt 
     input value is in range 0-999999 and element number is in range 2-50 */ 
 
  while(i<50){
    printf("Enter number into openAt[%d] or type \"n\" if finished\n",i);
    scanf("%s",Buffer);
    if(i>1 && (strcmp(Buffer,"n") == 0))
        break;
    else if(strcmp(Buffer,"n") == 0){
       printf("Enter at least 2 number\n");
       continue; 
    }
    else{
      openAt[i]=strtol(Buffer,&end,10);
      if(*end){
	printf("Please Enter number\n");
	printf("Value = %d \n",openAt[i]);
	continue;
      }
      else if(openAt[i] < 0 || openAt[i] >999999){
	printf("a value is out of range\n");
	continue;
      }
      else 
	printf("Success Value = %d \n",openAt[i]);
    }
    i++;
  }
  openAt[i] = -1;
  cmpArray = i;
  i=0;

  /* get input from user and put into closeAt 
     get string (to avoid user error)input check Is it "n" character ?
     then convert string to integer number and assign into openAt 
     input value is in range 1-1000000 and element number have to equal openAt */ 

  while(i<50){
    printf("Enter number into closeAt[%d]  or type \"n\" if finish\n",i);
    scanf("%s",Buffer);
    if(i>1 && (strcmp(Buffer,"n") == 0))
        break;
    else if(strcmp(Buffer,"n") == 0){
       printf("Enter at least 2 number\n");
       continue; 
    }
    else{
       closeAt[i]=strtol(Buffer,&end,10);
       if(*end){
           printf("Please Enter number\n");
           printf("Value = %d \n",closeAt[i]);
           continue;
       }
       else{
         if (closeAt[i] < 1 || closeAt[i] > 1000000){
	   printf("a value is out of range\n");
	   continue;
	 }
	 else if(closeAt[i] > openAt[i])
	   printf("Success Value = %d \n",closeAt[i]);
	 else{
	   printf("closeAt value have to greater than openAt\n");
	   continue;
	 }
       }
    }
    i++;
  }
  closeAt[i] = -1;
  if (cmpArray != i){
    printf("The element numbers of two array don't equal\n");
    exit(0);
  }

  /* get input into walkTime */
  while(1){
  printf("Enter walk time 1-1000000\n");
  scanf("%s",Buffer);
  walkTime = strtol(Buffer,&end,10);
  if(*end)
    printf("Please enter number\n "); 
  else if(walkTime < 1 || walkTime > 1000000)
    printf("walkTime is out of range \n ");
  else
     break;
  }
 
  int item = buyFood(openAt,closeAt,walkTime);

  printf("walkTime = %d\nReturn = %d\n",walkTime,item);
  return 0;

}


int buyFood(int openAt[],int closeAt[],int walkTime){
  int item=0;
  int currentTime=0;
  int maxcloseAt=0;
  int round=1;
  int allItem=0;
  register int i=0;
 
  /* loop check whether can buy item or not ?. exit loop when all shop closed 
     or have bought all item already.
   */
  while(1){
    printf("round%d\n",round);
    if(closeAt[i] > maxcloseAt)
      maxcloseAt = closeAt[i];
    if(currentTime >= openAt[i] && currentTime < closeAt[i]){
      printf("current Time = %d openAt[%d] = %d closeAt[%d] = %d\n",currentTime,i,openAt[i],i,closeAt[i]);
      item=item+1;
      closeAt[i] = -10 ;
     
    }
    currentTime += walkTime;
    printf("closAt[%d] = %d\ncurrentTime = %d\nmaxCloseAt = %d\n item= %d\n",i,closeAt[i],currentTime,maxcloseAt,item);
    i++;
   
    if(closeAt[i] == -1){
      allItem = i; 
      i = 0;
      round += 1;
    }
    if(round>1){
      if(currentTime > maxcloseAt)
	break;
      else if(item == allItem)
	break;
    }
  }
  return item;
}
