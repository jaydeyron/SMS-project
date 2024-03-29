#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Item{
  public:
    int id[100];
    string name[100];
    int quantity[100];
    int price[100];
    string getName(int i) {
      return name[i];
    }
    int getId(int i) {
      return id[i];
    }
    int getQuantity(int i) {
      return quantity[i];
    }
    int getPrice(int i) {
      return price[i];
    }
    void setQuantity(int j,int quant) {
      quantity[j] = quant;
    }
    void setPrice(int j, int pric){
      price[j]= pric;
    }
};

class Stock: public Item{
  public:
    int numItems;
    Stock()
    {
      numItems=0;
    }
    void addItem() {
      cout<<"\nEnter Item ID: ";
      cin>>id[numItems];
      cout<<"\nEnter Item Name: ";
      cin>>name[numItems];
      cout<<"\nEnter Item quantity: ";
      cin>>quantity[numItems];
      cout<<"\nEnter Item Price: ";
      cin>>price[numItems];
      numItems+=1;
    }
    void updateItem(int uname,int quant,int uprice) {
    int flag2=0;
      for (int j = 0; j < numItems; j++) {
        if (getId(j) == uname) {
          setPrice(j,uprice);
          setQuantity(j,quant);
          flag2=1;
          break;
        }
      }
      if(flag2!=1)
      {
      	cout<<"Item not found";
      }
      else
      {
      	cout<<"Item updated";
      }
    }
    void deleteItem(int dname) {
      int flag=0;
      for (int j = 0; j < numItems; j++) {
        if (getId(j) == dname) {
          for(int n=j;n<(numItems-1);n++)
          {
          name[n]=name[n+1];
          id[n]=id[n+1];
          quantity[n]=quantity[n+1];
          price[n]=price[n+1];
          }
          j--;
          numItems--;
          flag=1;
          break;
        }
      }
      if(flag!=1)
      {
      	cout<<"Item not found";
      }
      else
      {
      cout<<"Item deleted!"<<endl;
      }
    }
    void displayStock() {
      cout << "\nStock Details:" << endl;
      for (int j = 0; j < numItems; j++) {
        cout<<endl<< "Id: " << getId(j) << endl;
        cout<< "Name: " << getName(j) << endl;
        cout<< "Quantity: " << getQuantity(j) << endl;
        cout<< "Price: " << getPrice(j) << endl;
      }
    }
};
class Purchase:public Stock
{
  public:
    int pnum;
    int purchItemid[100];
    int purchQuantity[100];
    int purchPrice[100];
    int purchId[100];
    Purchase()
    {
     pnum=0;
    }
    void purchaseItem(int pItem,int pQnt, Stock &st)
    {
    	purchItemid[pnum]=pItem;
    	purchQuantity[pnum]=pQnt;
    	for(int i=0;i<st.numItems;i++)
    	{
    	  if(st.id[i]==purchItemid[pnum])
    	  {
    	    purchPrice[pnum]=st.price[i];
    	    st.quantity[i]-=purchQuantity[pnum];
    	  }
    	}
    	purchPrice[pnum]=purchPrice[pnum]*purchQuantity[pnum];
    	purchId[pnum]=pnum+1;
    	pnum++;
    	cout<<"Item purchased successfully"<<endl;
    }
     void printBill(int x)
    {
     cout<< "Purchase Details:" << endl<<endl;
     cout<<"Purchase Id: "<<purchId[x]<<endl; 
     cout<<"Item Id: "<<purchItemid[x]<<endl; 
     cout<<"Quantity: "<<purchQuantity[x]<<endl;
     cout<<"Total price: " <<purchPrice[x]<<endl<<endl;
      }
      void printrecentBill()
    {
     cout<< "Purchase Details:" << endl<<endl;
     cout<<"Purchase Id: "<<purchId[pnum-1]<<endl; 
     cout<<"Item Id: "<<purchItemid[pnum-1]<<endl; 
     cout<<"Quantity: "<<purchQuantity[pnum-1]<<endl;
     cout<<"Total price: " <<purchPrice[pnum-1]<<endl<<endl;
      }
    void generateReport(Stock &st,Purchase &pch)
    {
     cout<<"\n\n\t\tREPORT\n\n";
     cout<<"\tSTOCK\n";
     st.displayStock();
     cout<<"\t\tPURCHASES\n\n";
     for(int i=0;i<pnum;i++)
     {
     	pch.printBill(i);
     }
    }
   };

int main() {
 system("clear");
 int ch1,ch2,ch3;
 string pass;
 Stock st;
 Item it;
 Purchase pch;
 label1:
 while(1)
 {
   system("clear");	//user login page loop
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
      while(1)//password checking
     {
      cout<<"Enter password:\t";
      cin>>pass;
      cout<<endl;
      if(pass=="RSET123!")
      {
       label3:
     system("clear");
     int c3=0;
     while(1)
     {		//shop owner ui with report included
     	cout<<"\n\n\t\tSTOCK MANAGEMENT SYSTEM (SHOP OWNER)"<<endl;
  cout<<"\n1. Add item\n2. Delete item\n3. Update Item\n4. Display Stock\n5. Manage purchases\n6. Generate report\n7. Exit\n";
  cout<<endl<<"Enter your choice:\t";
  cin>>ch3;
  switch(ch3)
  {
      case 1:{
        st.addItem();
        cout<<"\nItem added!";
        break;
      }
      case 2:{
        int del;
        cout<<"\nEnter item ID to delete:\t";
        cin>>del;
        st.deleteItem(del);
        break;
      }
      case 3:{
        int ups;
        int upi,upp;
        cout<<"\nEnter item ID to update:\t";
        cin>>ups;
        cout<<"\nNew quantity:\t";
        cin>>upi;
        cout<<"\nNew price:\t";
        cin>>upp;
        st.updateItem(ups,upi,upp);
        break;
      }
      case 4:{
          st.displayStock();
          break;
      }
      case 5:{
      	  system("clear");
          while(1)
          {
            int ch5;
            cout<<"\n\nPURCHASES MENU\n\n";
            cout<<"1. Add purchase\n2. Print bill for last purchase\n3. Exit"<<endl<<endl;
            cout<<"Enter your choice:\t";
            cin>>ch5;
            switch(ch5)
            {
            	case 1:
            	{
            	 int iid,qq;
            	 cout<<"Enter Item id:  ";
          	 cin>>iid;
          	 cout<<"Enter quantity:  ";
          	 cin>>qq;
          	 pch.purchaseItem(iid,qq,st);
          	 break;
            	}
            	case 2:
            	{
            	 pch.printrecentBill();
            	 break;
            	}
            	case 3:
            	{
            	 goto label3;
            	}
            }
          }
      }
      case 6:{
          pch.generateReport(st,pch);
          break;
      }
      case 7:{
          cout<<"\n\n\t\tTHANK YOU"<<endl<<endl<<endl;
          c3=1;
          break;
      }
      default:{
          cout<<"\nInvalid choice, please try again";
          break;
      }
  }
  if(c3==1)
  {
  	goto label1;
     }
    }
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
       goto label1;
      }
     }
    }
    case 2:
    {
     label2:
     system("clear");
     int c2=0;
     while(1)
     {		//employee ui without report
     	cout<<"\n\n\t\tSTOCK MANAGEMENT SYSTEM (EMPLOYEE)"<<endl;
  cout<<"\n1. Add item\n2. Delete item\n3. Update Item\n4. Display Stock\n5. Manage purchases\n6. Exit\n";
  cout<<endl<<"Enter your choice:\t";
  cin>>ch2;
  switch(ch2)
  {
      case 1:{
        st.addItem();
        cout<<"\nItem added!";
        break;
      }
      case 2:{
        int del;
        cout<<"\nEnter item ID to delete:\t";
        cin>>del;
        st.deleteItem(del);
        break;
      }
      case 3:{
        int ups;
        int upi,upp;
        cout<<"\nEnter item ID to update:\t";
        cin>>ups;
        cout<<"\nNew quantity:\t";
        cin>>upi;
        cout<<"\nNew price:\t";
        cin>>upp;
        st.updateItem(ups,upi,upp);
        break;
      }
      case 4:{
          st.displayStock();
          break;
      }   
      case 5:{
          system("clear");
          while(1)
          {
            int ch5;
            cout<<"\n\nPURCHASES MENU\n\n";
            cout<<"1. Add purchase\n2. Print bill for last purchase\n3. Exit"<<endl<<endl;
            cout<<"Enter your choice:\t";
            cin>>ch5;
            switch(ch5)
            {
            	case 1:
            	{
            	int iid,qq;
            	cout<<"Enter Item id:  ";
          	cin>>iid;
          	cout<<"Enter quantity:  ";
          	cin>>qq;
          	pch.purchaseItem(iid,qq,st);
          	break;
            	}
            	case 2:
            	{
            	pch.printrecentBill();
            	break;
            	}
            	case 3:
            	{
            	 goto label2;
            	}
            }
          }
      }
      case 6:{
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
  	goto label1;
     }
    }
    }
    case 3:{
      cout<<endl<<endl<<"\t\t\tTHANK YOU"<<endl<<endl<<endl;
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
