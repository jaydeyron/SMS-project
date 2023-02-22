#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Item {
  public:
    
    string name[50];
    int quantity[50];
    int price[50];
    Item() {
    }
    string getName(int i) {
      return name[i];
    }
    int getQuantity(int i) {
      return quantity[i];
    }
    double getPrice(int i) {
      return price[i];
    }
    void setQuantity(int j,int quant) {
      quantity[j] = quant;
    }
};

class StockManager{
  public:
    int numItems = 0;
    StockManager()
    {
    }
    void addItem(Item &i) {
      cout<<"\nEnter Item Name: ";
      cin>>i.name[numItems];
      cout<<"\nEnter Item quantity: ";
      cin>>i.quantity[numItems];
      cout<<"\nEnter Item Price: ";
      cin>>i.price[numItems];
      numItems++;
    }
    void deleteItem(Item &i,string dname) {
      for (int j = 0; j < numItems; j++) {
        if (i.getName(j) == dname) {
          for(int n=j;n<(numItems-1);n++)
          {
          i.name[n]=i.name[n+1];
          i.quantity[n]=i.quantity[n+1];
          i.price[n]=i.price[n+1];
          }
          j--;
          numItems--;
          break;
        }
      }
    }
    void updateItem(Item &i,string uname,int quant) {
      for (int j = 0; j < numItems; j++) {
        if (i.getName(j) == uname) {
          i.setQuantity(j,quant);
          break;
        }
      }
    }
    void displayStock(Item &i) {
      cout << "\nStock Details:" << endl;
      for (int j = 0; j < numItems; j++) {
        cout << "Name: " << i.getName(j) << endl;
        cout << "Quantity: " << i.getQuantity(j) << endl;
        cout << "Price: " << i.getPrice(j) << endl;
      }
    }
    
};

int main() {
 system("clear");
 int ch1,ch2;
 string pass;
 StockManager stockManager;
 Item it;
 while(1)
 {
   system("clear");
   cout<<endl<<endl<<"\t\tUSER LOGIN"<<endl<<endl;
   cout<<"1. Shop owner login\n2. Employee login\n3. Exit"<<endl<<endl;
   cout<<"Enter your choice:\t";
   cin>>ch1;
   switch(ch1)
   {
    case 1:
    {
      int c1=0;
      system("clear");
      while(1)
     {
      cout<<"Enter password:\t";
      cin>>pass;
      cout<<endl;
      if(pass=="RSET123!")
      {
       cout<<"ENTER CODE"<<endl;
      }
      else if(pass=="EXIT")
      {
       c1=1;
      }
      else
      {
       cout<<"Invalid password, please try again"<<endl;
       cout<<"(Type EXIT to go back)"<<endl<<endl;
      }
      if(c1==1)
      {
       break;
      }
     }
     break;
    }
    case 2:
    {
     int c2=0;
     while(1)
     {
     	cout<<"\n\n\t\tSTOCK MANAGEMENT SYSTEM (EMPLOYEE)"<<endl;
  cout<<"\n1.Add item\n2.Delete item\n3.Update Item\n4.Display Stock\n5.Exit\n";
  cout<<endl<<"Enter your choice:\t";
  cin>>ch2;
  switch(ch2)
  {
      case 1:{
        stockManager.addItem(it);
        cout<<"\nItem added!";
        break;
      }
      case 2:{
        string del;
        cout<<"\nEnter item name to delete(in lower case): ";
        cin>>del;
        stockManager.deleteItem(it,del);
        break;
      }
      case 3:{
        string ups;
        int upi;
        cout<<"\nEnter item name to update(in lower case): ";
        cin>>ups;
        cout<<"\nSet quantity: ";
        cin>>upi;
        stockManager.updateItem(it,ups,upi);
        break;
      }
      case 4:{
          stockManager.displayStock(it);
          break;
      }
      case 5:{
          cout<<"\n\n\t\tTHANK YOU"<<endl<<endl<<endl;
          c2=1;
          break;
      }
      default:{
          cout<<"\nInvalid choice, please try again";
          break;
      }
  }
  if(c2==1)
  {
  	break;
     }
    }
    break;
    }
    case 3:{
      cout<<endl<<"\t\tTHANK YOU"<<endl<<endl<<endl;
      return(0);
    }
    default:
    {
     cout<<"Invalid choice, please try again";
     break;
    }
   }
 }
  }
