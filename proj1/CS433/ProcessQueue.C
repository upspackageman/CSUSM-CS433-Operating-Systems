// =======================================================

// Extra Credit
// CS311
// Your name: William Ward
// Compiler:  g++
// File type: .C
// 2/5/2015
//=======================================================



#include<iostream>
#include <string>
using namespace std;
#include "ProcessQueue.h"


bool ProcessQueue:: insertProc(int data)
{
  node*temp=new node();

  if(temp==NULL) // if system memory is full return false
    {
      return false;

    }

  else // if system memory is not full then enque
    {

      if(head==NULL)
        {

          temp->data=data;
          temp->next=NULL;
          head=temp;

        }
      else if(head->next==NULL)//Search for the position for the new node
        {
          if(head->data<data)
            {

              temp->data=data;
              temp->next=head;
              head=temp;

            }
          else if(head->data>data)
            {

              temp->data=data;
              temp->next=NULL;
              temp->next=head->next;
              head->next=temp;

            }
        }

      else
        {
          node*curr=head;
          if(head->data<data)
            {

              temp->data=data;
              temp->next=NULL;
              temp->next=head;
              head=temp;

            }
          else
            {
              while(curr->next!=NULL)
                {
                  if(curr->next->data<data)
                    {
                      break;
		    }

                  curr=curr->next;

                }

              temp->data=data;
              temp->next=curr->next;
              curr->next=temp;

            }
        }

      return true;
    }
}
bool ProcessQueue:: RemoveHighestProc(int&data)
{
  node*curr=head;
  if(curr==NULL)//no nodes
    {
      return false;
    }
  else
    {
      data=curr->data;
      head=curr->next;
      delete curr;
      return true;
    }
}

bool ProcessQueue:: Isempty()//check if node is NULL
{
  if(head==NULL)
    {
      return false;
    }
  else
    {
      return true;
    }
}

int ProcessQueue::size()//count the # of nodes
{count=0;
  node* p= head;
  while(p!=NULL)
    {
      count++;
      p=p->next;
    }
  return count;

}
