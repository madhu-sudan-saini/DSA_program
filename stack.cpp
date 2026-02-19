#include <iostream>
using namespace std;

void push(int arr[], int &top, int size)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    int num;
    cout << "Enter a number: ";
    cin >> num;

    top++;
    arr[top] = num;
}

void pop(int arr[], int &top)
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    cout << "Popped element: " << arr[top] << endl;
    top--;
}

void search(int arr[], int &top)
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    int key;
    cout<<"enter number to search:";
    cin>>key;

    for (int i = top; i >= 0; i--)
    {
        if (arr[i] == key)
        {
            cout << "Element found" << endl;
            return;
        }
    }

    cout << "Element not found" << endl;
}

void show(int arr[], int &top)
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Exit()
{
  exit(0);
}

int main()
{
    int arr[10];
    int size = 10;
    int top = -1;

    int choice;
    do
    {
      cout<<"\n 1.push \n 2.pop \n 3.search \n 4.show \n 5.Exit"<<endl;
      
      cout<<"enter your choice :";
      cin>>choice;
      
      switch(choice)
      {
        case 1: push(arr,top,size);break;
        case 2: pop(arr,top);break;
        case 3: search(arr,top);break;
        case 4: show(arr,top);break;
        case 5 :Exit();
        default:cout<<"eneter invalid number :"<<endl;
            
      }
      
    }while(choice !=5);
    return 0;
}
