// =======================================================
// CS311
// Extra Credit
// Your name: William Ward
// Compiler:  g++
// File type: .C 
// 2/5/2015
//=======================================================




#include<iostream> 
#include "ProcessQueue.h" 
using namespace std;

int main()
{
  ProcessQueue q;
  int option;
  int data;
  bool test;
  
    
	  cout<<"Enter data or Press 999 to exit : ";
	  while(data!=999)
	  {
               cin>>data;
	    if(data!=999)
	    {
	    if(q.insertProc(data))
            {
	      cout<<"Succesfully entered"<<endl;
            }
	  else
            {
	      cout<<"system memory is full"<<endl;
            }
            }
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

	  if(q.Isempty())
            {
	      cout<<"DEQUEUED DATA IS : ";
              while(q.Isempty())
                {
                  test=q.RemoveHighestProc(data);
                  cout<<data<<" ";
                }
              cout<<endl;
              
             }
          else
            {
              cout<<"queue is Empty"<<endl;
            }
	  cout<<"Good Bye :)"<<endl;

}


        

