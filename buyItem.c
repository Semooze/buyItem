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
    printf("Enter number into openAt[%d] 0-999999 or type \"n\" if finished\n",i);
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
    printf("Enter number into closeAt[%d] 1-1000000 or type \"n\" if finish\n",i);
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
 
  i = 0; 
  printf("openAt = {");
  while(openAt[i] != -1){
    printf("%d ",openAt[i]);
    i++;
  }
  printf("}\n");

  i = 0; 
  printf("closeAt = {");
  while(closeAt[i] != -1){
    printf("%d ",closeAt[i]);
    i++;
  }

  printf("}\n");
  printf("walkTime = %d\n",walkTime);
  int item = buyFood(openAt,closeAt,walkTime);
  printf("Return = %d\n",item);
  return 0;

}


int buyFood(int openAt[],int closeAt[],int walkTime){
  int item=0;
  int size;
  int i=0;
  int k = 0;
  /* find out the size of array */
  while(openAt[k] != -1)
    k++;
  size = k;

  /* estimate value of that element in each turn and check is is in range 
     openAt - closeAt 
     tmp = value of first element of array in round 2 we didn't use 
     round 1 because it is 0 
     j is multiplier that make value nearest the range
     first and second is the value in next turn and next two turn; */ 
  for(i=0 ; i < size ; i++){
    int tmp = (walkTime*size);
    int j = openAt[i]/tmp; 
    int first = (walkTime*size*j)+(walkTime*i);
    int second = (walkTime*size*(j+1))+(walkTime*i);
    if((first >= openAt[i]) && (first < closeAt[i])){
      item+=1;
      continue;
    }
    if((second >= openAt[i]) && (second < closeAt[i]))
      item+=1;
  }
  return item;
}
