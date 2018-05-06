#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <fstream>
using namespace std;
//structs---------------------------------------------------------------------=
struct Salesperson {
    string name;
    char passchar;
};
struct Pizza {
    string nameOfCustomer;
    string pizzaKind;
    string size;
    string status;
    int priceOfOnePiece;
    int numberOfPieces;
    char coupon;
    int couponSize;
    string systemTime;  
    string topping;
    string dessert;
    int paid;
};
//global Vars-------------------------------------------------------------=
struct Pizza Pizzas[1000];
int index=0; 
//functions Prototypes-----------------------------------------------------=  
void newPizza();
void checkStatus();
void changeStatus();
void generateCoupon();
bool isValid(string coupon);
void history();
void printToFile();
//---------------------------------------------------------=
int main(){    
bool isManager=false; 
int choice;
Salesperson Salespersons[1];
cout<<"\n\t=========Welcome to the Pizza Ordering System=========\n\t";
cout<<"\n\t\t=========The Login Window=========\n\t";
cout<<"\n\t\t\tName : ";
getline(cin,Salespersons[0].name);
cout<<"\n\t\t\tPassChar : ";
cin>>Salespersons[0].passchar;
if(Salespersons[0].passchar=='M'){
    isManager=true;
    cout<<"\n\t\t\tWelcome Back Manager!!\n";
}
while(1){
    cout<<"\n\t\t=========Welcome to the Pizza Ordering System=========\n\t";
    cout<<"\n\t\t\t=========The Menu Window=========\n\t";
    cout<<"\n\t\t||  [1]Sumbit a new order                     ||";
    cout<<"\n\t\t||  [2]Change the status of an order          ||";
    cout<<"\n\t\t||  [3]Check the status of an order           ||";
    cout<<"\n\t\t||  [4]Generate a coupon                      ||";
    if(isManager){
        cout<<"\n\t\t||  [5]History                                ||";
        cout<<"\n\t\t||  [6]Print the History to an external file  ||";
    }
    cout<<"\n\t\t||  [0]EXIT                                   ||";
    cout<<"\n\t\t\tYour Choice : ";
    cin>>choice;
    switch(choice){
        case 0: 
                cout<<"\n\t\t\t============="; 
                    break;
        case 1: 
                newPizza();                
                    break; 
        case 2:
                changeStatus();
                break;
        case 3:
                checkStatus();
                break;                                     
        case 4:
                generateCoupon();
                break;
        case 5:
                history();
                break;
        case 6:
                printToFile();        
}
if(choice==0){
    break;
}
}
    return 0;
}
//-------------------------------------------------------------------------=
 void newPizza(){
    char specialOrder;
    bool isSpecialOrder=false;
    string couponID;
    char isFinal;
    char newOrder;
    char wantDessert;

     for(int i=index;i<1000;i++){
       /*
       ===Tried to implement the time of creation===
        time_t now = time(0);
        string* tm=ctime(&now);
        strcpy(tm,Pizzas[i].systemTime);
        */
        cout<<"\n\t\tIs this a special order(Y|N)?";
        cin>>specialOrder;
        cout<<"\n\t\tName of the Customer : ";
        cin>>Pizzas[i].nameOfCustomer;
        cout<<"\n\t\tPizza Kind : ";
        cin>>Pizzas[i].pizzaKind;
        cout<<"\n\t\tSmall-Medium-Big";
        cout<<"\n\t\tPizza Size : ";
        //cout<<"\t\t";
        cin>>Pizzas[i].size;
        if(specialOrder=='Y'){
            cout<<"\n\t\t Available : 1,2,3,4,5";
            cout<<"\n\t\t please choose the topping you want : ";
            //cout<<"\t\t";
            cin>>Pizzas[i].topping;
            cout<<"\n\t\tDo you want any dessert(Y for Yes)?";
            cin>>wantDessert;
            if(wantDessert=='Y'){
                cout<<"\n\t\t Available : 1,2,3,4,5";
                cout<<"\n\t\tplease choose the dessert you want : ";
                //cout<<"\t\t";
                cin>>Pizzas[i].dessert;
            }
        }
        cout<<"\n\t\tNumber of pieces : ";
        cin>>Pizzas[i].numberOfPieces;
        cout<<"\n\t\tPrice of one piece : ";
        cin>>Pizzas[i].priceOfOnePiece;
        cout<<"\n\t\tAvaliablity of Coupons(Y|N) : ";
        cin>>Pizzas[i].coupon;
        if(Pizzas[i].coupon=='Y'){
        while(1){  
            cout<<"\n\t\tCoupon ID : ";
            cin>>couponID;
            if(isValid(couponID)==false){
                cout<<"\n\t\tInvalid Coupon ID!!";
                continue;
            }else{
                break;
            }
            }                
        cout<<"\n\t\tAmount of discount : ";
        cin>>Pizzas[i].couponSize;
        }
        cout<<"\n\t\tPreparing-Finished-Delivered\n";
        cout<<"\n\t\tOrder Status : ";
        //cout<<"\t\t";
        cin>>Pizzas[i].status;
        Pizzas[i].paid=Pizzas[i].priceOfOnePiece*Pizzas[i].numberOfPieces-Pizzas[i].couponSize;
        cout<<"\n\t\tThis Customer Gotta pay : "<<Pizzas[i].paid;
        cout<<"\n\t\tIs this FINAL(Y|N)?";
        cin>>isFinal;
        if(isFinal=='Y'){
            cout<<"\n\t\tYou Just Sumbitted a new Order!!";
            cout<<"\n\t\tDo you want to sumbit another order(Y|N)?";
            cin>>newOrder;
            if(newOrder=='Y'){
                index++;
                continue;
            }else if(newOrder=='N'){
                index++;
                break;
            }
            }else if(isFinal=='N'){
                index--;
                continue;
        }

     }
     //ToDO: determine the discount from the CouponID automatically
 }
 //----------------------------------------------------------------------=
 void checkStatus(){
     string customerName;
     int anotherChecking=1;
     while(!anotherChecking==0){
        cout<<"\n\t\tPlease Enter the name of the customer : ";
        cin>>customerName;
        for(int i =0;i<1000;i++){
            if(Pizzas[i].nameOfCustomer==customerName){
                cout<<"\n\t\tName : "<<Pizzas[i].nameOfCustomer<<"\n\t\tStatus of the order : "<<Pizzas[i].status;
                break;
         }else{
             cout<<"\n\t\tThere is not any customers with that name in the data!!";
             break;
         }
     }
       cout<<"\n\t\tDo you want to check another order(0 to return)?";
       cin>>anotherChecking;
     }
     //TODO: sensitivity for duplicate names
 }
 //-------------------------------------------------------------------------=
 void changeStatus(){
     string customerName;
     string newStatus;
     int anotherChange=1;
     while(!anotherChange==0){
        cout<<"\n\t\tPlease Enter the name of the customer : ";
        cin>>customerName;
        for(int i =0;i<1000;i++){
            if(Pizzas[i].nameOfCustomer==customerName){
                cout<<"\n\t\tPreparing-Finished-Delivered";
                cout<<"\n\t\tNew Status : ";
                cin>>newStatus;
                Pizzas[i].status=newStatus;
                break;
         }else{
             cout<<"\n\t\tThere is not any customers with that name in the data!!";
             break;
         }
        
     }
        cout<<"\n\t\tDo you want to change another Status(0 to return)?";
        cin>>anotherChange;
     }
          //TODO: sensitivity for duplicate names
 }
 //------------------------------------------------------------------------------=
 void history(){
    int toreturn=1;
     cout<<"\n\t\tThe History : ";
     while(toreturn==1){
         for(int i =0;i<index;i++){
            cout<<"\n"<<"Customer name : "<<Pizzas[i].nameOfCustomer<<" || Pizza Kind : "<<Pizzas[i].pizzaKind<<" || Size : "<<Pizzas[i].size<<" || Status : "<<Pizzas[i].status<<" || Paid : "<<Pizzas[i].paid;
            //TODO: Displaying if the customer had a special order or not
         }
         cout<<"\n\t\tTo return Enter 0 : ";
         cin>>toreturn;
     }
 }
//-------------------------------------------------------------------------------=
void generateCoupon(){
    int sizeOfCoupon;
    string couponID;
    cout<<"\n\t\tEnter the Size of the coupon to be generated : ";
    cin>>sizeOfCoupon;
    srand((unsigned)time(0)); 
    int randomnum = rand()%1000; 
    couponID="Pi-"+to_string(randomnum)+'.'+to_string(sizeOfCoupon)+'z';
    cout<<"\n\t\tcoupon ID : "<<couponID;
    //TODO: Add ability to generate more than one coupon
}
//----------------------------------------------------------------------------------=
bool isValid(string couponID){
    bool isValid=false;
    if(couponID.find("-")==2&&couponID.find(".")==6&&couponID.find("z")==9){
        isValid=true;
    }
    return isValid;
}
//-------------------------------------------------------------------------------------=
void printToFile(){
    ofstream history;
    history.open("history.txt");
    for(int i =0;i<index;i++){
            history<<"\n"<<"Customer name : "<<Pizzas[i].nameOfCustomer<<" || Pizza Kind : "<<Pizzas[i].pizzaKind<<" || Size : "<<Pizzas[i].size<<" || Status : "<<Pizzas[i].status<<" || Paid : "<<Pizzas[i].paid;
         }
    history.close();
    cout<<"Done Printing To File";     
}
//imp TODO: names with spaces in the newPizza function
