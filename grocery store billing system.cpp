#include<bits/stdc++.h>
#include<conio.h>
#include <fstream>
#include <string>

using namespace std;
class grocerysystem{
    public:
    void addItem();
    void viewItem();
    void deleteItem();
    void generateBill();
};

void grocerysystem::addItem()
{
    string itemName;
    int itemPrice,itemQuantity,itemUID;
    ofstream outFile("additem.txt",ios::app);
    if(!outFile)
    {
        cout<<"Error: Could not open file!\n";
        return;
    }
    cout<<"\n\t\t------------------------\n";
    cout<<"\t\t[ADD ITEMS TO YOUR CART]\n";
    cout<<"\t\t========================\n";

    cout<<"\nEnter the name of item: ";
    cin>>itemName;
    cout<<"\nEnter items UID: ";
    cin>>itemUID;
    cout<<"\nEnter unit price: ";
    cin>>itemPrice;
    cout<<"\nEnter quantity: ";
    cin>>itemQuantity;

    outFile<<itemName<<" "<<itemUID<<" "<<itemPrice<<" "<<itemQuantity<<endl;
    cout<<"\nItem added successfully!\n";
    outFile.close();
    cout<<"(Press any key to return to menu...)\n";
    getch();
}

void grocerysystem::viewItem()
{
    string itemName;
    int itemPrice,itemQuantity,itemUID;
    ifstream inFile("additem.txt");
    if(!inFile)
    {
        cout<<"Error: Cart is empty or file not found!\n";
        return;
    }
    cout<<"\n\t\t--------------------\n";
    cout<<"\t\t[ITEMS IN YOUR CART]\n";
    cout<<"\t\t====================\n";

    while(inFile>>itemName>>itemUID>>itemPrice>>itemQuantity)
    {
        cout<<"Item name: "<<itemName<<endl;
        cout<<"Item UID: "<<itemUID<<endl;
        cout<<"Unit price: "<<itemPrice<<" TK"<<endl;
        cout<<"Quantity: "<< itemQuantity<<" Pc"<<endl;
        cout<<"--------------------"<<endl;
    }
    inFile.close();
    cout<<"\n(End of list. Press any key to return...)";
    getch();
}

void grocerysystem::deleteItem()
{
    string itemName;
    int itemPrice,itemQuantity,itemUID,deleteUID;
    char confirm;
    bool found = false;

    ifstream inFile("additem.txt");
    ofstream tempFile("temp.txt");

    if(!inFile || !tempFile){
        cout<<"Error opening files!"<<endl;
        return;
    }

    cout<<"Enter the UID of the item to delete: ";
    cin>>deleteUID;

    while(inFile>>itemName>>itemUID>>itemPrice>>itemQuantity){
        if(itemUID == deleteUID){
            found = true;
            cout<<"\nItem Found:"<<endl;
            cout<<"Item name: "<<itemName<<"\nPrice: "<<itemPrice<<"\nQty: "<<itemQuantity<<endl;
            cout<<"Are you sure you want to delete this item? (y/n): ";
            cin >> confirm;
            if(confirm =='y' || confirm =='Y'){
                cout<<itemName<<" deleted successfully!"<<endl;
                }
                else
                {
                cout<<"Deletion cancelled"<<endl;
                tempFile<<itemName<<" "<<itemUID<<" "<<itemPrice<<" "<<itemQuantity<<endl;
                }
            }
            else
            {
                tempFile<<itemName<<" "<<itemUID<< " "<<itemPrice<<" "<<itemQuantity<<endl;
            }
    }

    inFile.close();
    tempFile.close();

    remove("additem.txt");
    rename("temp.txt","additem.txt");

    if(!found){
        cout<<"Item with UID "<<deleteUID<<" not found!"<<endl;
    }
    cout<<"\n(Press any key to continue...)\n";
    getch();
}

void grocerysystem::generateBill()
{
    string itemName;
    int itemPrice,itemQuantity,itemUID,total;
    int grandTotal = 0;

    ifstream inFile("additem.txt");
    if(!inFile){
        cout<<"File not found!"<<endl;
        return;
    }

    cout<<"\n\t\t------------\n";
    cout<<"\t\t[TOTAL BILL]\n";
    cout<<"\t\t============\n";
    cout<<"UID\t"<<"Item Name\t"<<"Price\t"<<"Qty\t"<<"Total"<<endl;
    cout<<"------------------------------------------------\n";

    while(inFile>>itemName>>itemUID>>itemPrice>>itemQuantity)
    {
        total = itemPrice*itemQuantity;
        grandTotal += total;
        cout<<itemUID<<"\t"<<itemName<<"\t\t"<<itemPrice<<" TK\t"<<itemQuantity<<" Pc\t"<<total<<" TK"<<endl;
    }

    cout<<"------------------------------------------------\n";
    cout<<"Grand Total: \t\t\t\t"<<grandTotal<<" TK"<<endl;
    inFile.close();
    cout<<"\n(Bill generated. Press any key to return...)\n";
    getch();
}

int main()
{
    grocerysystem shop;
    int choice;

    while(true)
    {
        cout<<"\n\t\t------------------------------\n";
        cout<<"\t\t[GROCERY STORE BILLING SYSTEM]\n";
        cout<<"\t\t==============================\n\n";
        cout<<"1. Add Item\n2. View Item\n3. Delete Item\n4. Generate Bill\n5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==5)
        {
            cout<<">> Thank you for using the system <<\n";
            return 0;
        }
        switch(choice)
        {
            case 1:
                shop.addItem();
                break;
            case 2:
                shop.viewItem();
                break;
            case 3:
                shop.deleteItem();
                break;
            case 4:
                shop.generateBill();
                break;
            default:
                cout<<">> Invalid choice! Try again <<\n";
                break;
        }
    }
    return 0;
}
