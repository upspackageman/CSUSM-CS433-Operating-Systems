#include<stdlib.h> 
#include<unistd.h>
#include<stdio.h> 
#include<sys/wait.h> 



int main(int argc, char* argv[]){

  pid_t pid, wait_pid;

  int i=atoi(argv[1]);
  int status=0;


  pid=fork();
  if(i<=-1){
    //So program doesn't run forever when entering other than positive integers 
       printf("Positive integers only. Thank you. \n\n");
    }
  else  if(pid<0){
    //ERROR OCCURRED 
    printf("Fork Failed");
    return 1;
  }
  else if(pid==0){
    //CHILD PROCESS
    printf("Child Process\n");
    
    while(i!=1){
      printf("%d\n",i);
      if(i%2==0){//integer is even
	i=i/2;
      }
      else{
	i=i*3+1;  //odd integer
      }
    }
    printf("%d\n",i); 

    exit(1);
  
  }
  //Parent Process
      while((wait_pid=wait(&status))>0){

	printf("Child Process Exit\n");

      }  

  return 0; 
}



