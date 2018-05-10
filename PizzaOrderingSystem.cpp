#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <fstream>
#include <ctype.h>
using namespace std;
//structs---------------------------------------------------------------------=
struct Salesperson {
    string name;
    string passchar;
};
struct Pizza {
    string nameOfCustomer;
    string pizzaKind;
    string size;
    string status;
    //int priceOfOnePiece;
    int numberOfPieces;
    //char coupon;
    int couponSize;
    string specialOrder;
    string topping;
    string dessert;
    int paid;
};
//global Vars-------------------------------------------------------------=
struct Pizza Pizzas[1000];
int index=0;
string menu[10] = {"Berry","Arugula","Prosciutto","Macaroni","Cheese","Cantaloupe","Sweet Ricotta","Chicken Alfredo","null","null"};
int prices[10] = {15,24,56,35,74,83,96,25,0,0}; 
int numberMenu=8;
//functions Prototypes-----------------------------------------------------=  
void newPizza();
void checkStatus();
void changeStatus();
void generateCoupon();
bool isValid(string coupon);
void history();
void printToFile();
int captureCouponSize(string CouponID);
void showPizzaMenu();
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
getline(cin,Salespersons[0].passchar);
if(Salespersons[0].passchar=="M"){
    isManager=true;
    cout<<"\n\t\t\tWelcome Back Manager!!\n";
    goto MainScreen;
}
while(1){
    MainScreen:
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
    while(1){
        cout<<"\n\t\t\tYour Choice : ";
        cin>>choice;
        if(choice>=0&&choice<=6){
            break;
        }else{
            continue;
        }
    }
    switch(choice){
        case 0: 
                cout<<"\n\t\t\t============="; 
                    break;
        case 1: 
                newPizza();                
                    //break;
                    goto MainScreen; 
        case 2:
                changeStatus();
                //break;
                goto MainScreen; 

        case 3:
                checkStatus();
                //break;
                goto MainScreen; 
                                     
        case 4:
                generateCoupon();
                //break;
                goto MainScreen; 

        case 5:
                history();
                //break;
                goto MainScreen; 

        case 6:
                printToFile();
                goto MainScreen; 
 
}
if(choice==0){
    break;
}
}
    return 0;
}
//-------------------------------------------------------------------------=
 void newPizza(){
    string specialOrder;
    bool isSpecialOrder=false;
    string couponID;
    string isFinal;
    string newOrder;
    char wantDessert;
    int ofMenu;
    string hasCoupon;

     for(int i=index;i<1000;i++){
       /*
       ===Tried to implement the time of creation===
        time_t now = time(0);
        string* tm=ctime(&now);
        strcpy(tm,Pizzas[i].systemTime);
        */
        while(1){
            cout<<"\n\t\tIs this a special order(Y|N)?";
            cin>>specialOrder;
            if(specialOrder=="Y"||specialOrder=="N"){
                break;   
            }else{
                cout<<"\n\t\t\tInvalid Input";
                continue;
            }   
        }
        if(specialOrder=="Y"){
            Pizzas[i].specialOrder="Yes";
        }else if(specialOrder=="N"){
            Pizzas[i].specialOrder="No";
        }

        cout<<"\n\t\tName of the Customer : ";
        cin>>Pizzas[i].nameOfCustomer;
        cout<<"\n\t\tWe have : ";
        showPizzaMenu();
        cout<<"\n\t\tYour choice : ";
        cin>>ofMenu;
        Pizzas[i].pizzaKind=menu[ofMenu-1];
        cout<<"\n\t\tSmall-Medium-Big";
        cout<<"\n\t\tPizza Size : ";
        cin>>Pizzas[i].size;
        if(specialOrder=="Y"){
            cout<<"\n\t\t Available : 1,2,3,4,5";
            cout<<"\n\t\t please choose the topping you want : ";
            cin>>Pizzas[i].topping;
            cout<<"\n\t\tDo you want any dessert(Y for Yes)?";
            cin>>wantDessert;
            if(wantDessert=='Y'){
                cout<<"\n\t\t Available : 1,2,3,4,5";
                cout<<"\n\t\tplease choose the dessert you want : ";
                cin>>Pizzas[i].dessert;
            }
        }
        nospecial:
        cout<<"\n\t\tNumber of pieces : ";
        cin>>Pizzas[i].numberOfPieces;
        //cout<<"\n\t\tPrice of one piece : ";
        //cin>>Pizzas[i].priceOfOnePiece;
        while(1){
            cout<<"\n\t\tAvaliablity of Coupons(Y|N) : ";
            cin>>hasCoupon;
            if(hasCoupon=="Y"||hasCoupon=="N"){
                break;
            }else{
                cout<<"\n\t\tEnter Either \"Y\" or \"N\"!!";
                continue;
        }
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
        }
        cout<<"\n\t\tPreparing-Finished-Delivered\n";
        cout<<"\n\t\tOrder Status : ";
        //cout<<"\t\t";
        cin>>Pizzas[i].status;
        Pizzas[i].paid=prices[ofMenu-1]*Pizzas[i].numberOfPieces-captureCouponSize(couponID);
        cout<<"\n\t\tThis Customer Gotta pay : "<<Pizzas[i].paid;
        while(1){
            cout<<"\n\t\tIs this FINAL(Y|N)?";
            cin>>isFinal;
            if(isFinal=="Y"||isFinal=="N"){
                break;
            }else{
                cout<<"\n\t\tEnter Either \"Y\" or \"N\"!!";
                continue;
            }
        }
        if(isFinal=="Y"){
            cout<<"\n\t\tYou Just Sumbitted a new Order!!";
            while(1){
                cout<<"\n\t\tDo you want to sumbit another order(Y|N)?";
            cin>>newOrder;
            if(newOrder=="Y"||newOrder=="N"){
                break;
            }else{
            cout<<"\n\t\tEnter Either \"Y\" or \"N\"!!";
            continue;
        }
            }
            if(newOrder=="Y"){
                index++;
                continue;
            }else if(newOrder=="N"){
                index++;
                break;
            }
            }else if(isFinal=="N"){
                index--;
                continue;
        }

     }
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
        while(1){ 
            cout<<"\n\t\tDo you want to check another order(0 to return)?";
            cin>>anotherChecking;
            if(anotherChecking==0){
                break;
            }else{
                cout<<"\n\t\tYou can only enter \"0\"!";
                continue;
            }
        }
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
        
     }  while(1){
            cout<<"\n\t\tDo you want to change another Status(0 to return)?";
            cin>>anotherChange;
            if(anotherChange==0){
                break;
            }else{
                cout<<"\n\t\tYou can only enter \"0\"!";
                continue;
            }
     }
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
        while(1){
            cout<<"\n\t\tTo return Enter 0 : ";
            cin>>toreturn;
            if(toreturn==0){
                break;
            }else{
                cout<<"\n\t\tYou can only enter \"0\"!";
                continue;
            }
        }
     }
 }
//-------------------------------------------------------------------------------=
void generateCoupon(){
    int sizeOfCoupon;
    string couponID;
    while(1){
        cout<<"\n\t\tEnter the Size of the coupon to be generated : ";
        cin>>sizeOfCoupon;
        if(isdigit(sizeOfCoupon)){
            break;
        }else{
            cout<<"\n\t\tPlease enter a proper size!";
            continue;
        }

    }
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
//------------------------------------------------------------------------------------------=
int captureCouponSize(string couponID){
    int couponSize;
    couponSize = atoi(couponID.substr(couponID.find(".")+1,couponID.find("z")).c_str());
        return couponSize;
}
//---------------------------------------------------------------------------------------=
void showPizzaMenu(){
    for(int i =0;i<10;i++){
        if(i%2==0&&menu[i]!="null"){
            cout<<"\n\t\t\t>> "<<"["<<i+1<<"]"<<menu[i]<<" - ";
        }else if(i%2!=0&&menu[i]!="null"){
            cout<<"["<<i+1<<"]"<<menu[i];
        }
    }
}