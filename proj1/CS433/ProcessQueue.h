// =======================================================

// Extra credit
// CS311
// Your name: William Ward
// Compiler:  g++
// File type:.h
// 2/5/2015
//=======================================================


struct node
{
  int data;
  node*next;

  node()
    {
      data=-1;
      next=NULL;
    }
  node(int n,node*temp)
    {
      data=n;
      next=temp;
    }
};
class ProcessQueue
{
 protected:
  node*head;
  node*tail;
  int count; 
 
 public:
  ProcessQueue()
    {
      head=NULL;
      tail=NULL;
    }
  
  bool insertProc(int data);
  bool RemoveHighestProc(int& data);
  bool Isempty();
  int size();
  class Overflow{}; 
  class Underflow{}; 
};
