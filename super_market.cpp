#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class super{
    int n,i,no,stock,quan,k,flag,quantity;
    char name[20],date[10],item_name[20];
    double price,total,pr;

public:


    super(){
        k = 0;
        total = 0;
        pr = 0;
    }

    void add_items(super item[]){

        cout<<"\n\t\tAdd number of items to be added: ";
        cin>>n;

        for(i=0;i<n;i++){
            cout<<"\n";
            cout<<"\t\t****** Item Details ******\n\n";
            cout<<"\t\tItem number: ";
            cin>>item[i].no;
            cout<<"\t\tItem name: ";
            cin>>item[i].name;
            cout<<"\t\tManufacturing date: ";
            cin>>item[i].date;
            cout<<"\t\tPrice: ";
            cin>>item[i].price;
            cout<<"\t\tStock: ";
            cin>>item[i].stock;


        }

    }

    void display_items(super item[]){

        cout<<"\n\n\t\tAvailable Items: \n\n";

        for(i=0; i<n; i++){

            cout<<"\t\tItem No:  "<<item[i].no;
            cout<<"\n\t\tItem Name: "<<item[i].name;
            cout<<"\n\t\tManufacturing date: "<<item[i].date;
            cout<<"\n\t\tPrice: "<<item[i].price;
            cout<<"\n\t\tStock: "<<item[i].stock;
            cout<<"\n\n";
        }

    }

    void shop_items(super item[],super cart[]){

        cout<<"\n\t\tEnter name of item: ";
        cin>>item_name;

        flag = 0;

        for(i=0;i<n;i++){

            if(strcmp(item[i].name,item_name) == 0){

                flag = 1;

                if(item[i].stock == 0)
                    cout<<"\n\t\tSorry ! The product is currently unavailable !\n";
                else{

                    cout<<"\n\t\tNumber of quantities: ";
                    cin>>item[i].quantity;


                if(item[i].stock < item[i].quantity )
                    cout<<"\n\t\tSorry ! Stock availability is only "<<item[i].stock<<" for the product !\n";

                else{

                    item[i].stock -= item[i].quantity;

                    cart[k++] = item[i];

                    cout<<"\n\t\tItem added to cart !\n";
                }
                }

            }

        }

          if(flag == 0){
                cout<<"\n\n\t\tItem not found ! Please select one of the available items !\n\n";

            }
    }

    void bil(super cart[]){

        total = 0;

        cout<<"\n\n\t\t*******************************************************";
        cout<<"\n\n\t\t                     BILL DETAILS";
        cout<<"\n\n\t\t*******************************************************";
        cout<<"\n\n";
        cout<<"\t\t     No.\tName\tPrice\tQuantity\tAmount\n\n";

        for(i=0;i<k;i++){

        pr = (cart[i].price*cart[i].quantity);
        cout<<"\t\t     "<<cart[i].no<<"\t"<<cart[i].name<<"\t"<<cart[i].price<<"\t"<<cart[i].quantity<<"\t\t"<<pr;

        total += pr;

        cout<<"\n\n";

        }

        cout<<"\n\n\t\t*******************************************************";
        cout<<"\n\n\t\t                           Total Amount: Rs."<<total<<"  ";
        cout<<"\n\n\t\t*******************************************************";


    }


};

int main(){

    super obj;
    super item[100],cart[100];
    int choice;
    do{ cout<<"\n\n";
        cout<<"\t1. Add items\n";
        cout<<"\t2. Show available items\n";
        cout<<"\t3. Shop items\n";
        cout<<"\t4. Generate bill report\n";
        cout<<"\t5. Exit\n";
        cout<<"\tchoice: ";
        cin>>choice;

        switch(choice){

        case 1: obj.add_items(item);
            break;

        case 2: obj.display_items(item);
            break;

        case 3: obj.shop_items(item,cart);
            break;

        case 4: obj.bil(cart);
            break;

        case 5: system("cls");
                cout<<"\n\n\tThank you for shopping. Do come Again ! \n\n";
            break;
        }


    }while(choice != 5);

}
