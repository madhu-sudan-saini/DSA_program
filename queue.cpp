#include<iostream>
using namespace std;

void push(int arr[],int size,int &front,int &rear)
{
  if(rear==size-1)
  {
    cout<<"queue is full"<<endl;
    return;
  }
  
  int num;
  cout<<"enter a number to push:";
  cin>>num;
  
  if(front==-1  && rear==-1)
  {
    front=rear=0;
  }
  else
  {
    rear++;
  }
  arr[rear]=num;
}

void pop(int arr[],int size,int &front,int &rear)
{
  if( front==-1 && front>rear) 
  {
    cout<<"queue is empty"<<endl;
  }
  
  cout<<"remove element is :"<<arr[front]<<endl;
  front++;
}


void search(int arr[],int size,int &front,int &rear,int key)
{
  if( front==-1 && front>rear) 
  {
    cout<<"queue is empty"<<endl;
  }
  
  for(int i=front;i<rear;i++)
  {
    if(arr[front]==key)
    {
      cout<<"element is found"<<endl;
      break;
    }
    else
    {
      cout<<"element is not found"<<endl;
      break;
    }
  }
}

void display(int arr[],int size,int &front,int &rear)
{
  if( front==-1 && front>rear) 
  {
    cout<<"queue is empty"<<endl;
  }
  
  for(int i=front;i<rear;i++)
  {
    cout<<arr[i]<<" ";
  }
}

void Exit()
{
  exit(0);
}
int main()
{
  
  int size=20;
  int arr[size];
  int rear=-1,front=-1;
  int choice;
  
  do
  {
    cout<<"\n 1.push \n 2.pop \n 3.search \n 4.display \n 5.Exit"<<endl;
    
    cout<<"enter a number :";
    cin>>choice;
    
    switch(choice)
    {
      case 1:push(arr,size,front,rear);break;
      case 2:pop(arr,size,front,rear);break;
      case 3:search(arr,size,front,rear,23);break;
      case 4:display(arr,size,front,rear);break;
      case 5:Exit();break;
      default:cout<<"Invalid number"<<endl;
    }
    
  }while(choice !=5);
  
  return 0;
}