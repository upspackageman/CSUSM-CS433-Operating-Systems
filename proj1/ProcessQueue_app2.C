// =======================================================
// CS433
// HW1
// Your name: William Ward
// Compiler:  g++
// File type: .C
// 2/5/2015
//=======================================================
#include<time.h> 
#include<cstdlib>
#include<iostream>
#include "ProcessQueue.h"
using namespace std;


int const numbers=1000000;

int main()
{
  srand(time(0));
  
  ProcessQueue q;
  int option;
  int data;
  bool test;
  clock_t tStart=clock();
  int i=0;

  
  while(i<numbers)
    {
      data=rand()%50+1;
      q.insertProc(data);
      i++;
     
    }

  cout<<"\n\nQUEUE SIZE: "<<q.size()<<endl;
  if(q.Isempty())
    {
      test=q.RemoveHighestProc(data);
      cout<<"THE HIGHEST PROCESS DEQUEUED DATA IS : "<<data<<endl;
    }
  else
    {
      cout<<"queue is Empty"<<endl;
    }

  cout<<"Time: "<<(double)((clock()-tStart)/CLOCKS_PER_SEC)<<endl;
  cout<<"Good Bye :)"<<endl;

}
