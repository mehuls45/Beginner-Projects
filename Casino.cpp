#include<iostream>
#include<cstdlib>
using namespace std;

int deposit,i,n,bet_amount,guess,lucky;
string name;
char choice;

void input();
void draw_line(int);
void rules();
void start();

int main(){
    input();
    draw_line(110);
    rules();
    draw_line(110);
    start();

}

void input(){
    cout<<"Enter name: ";
    cin>>name;
    cout<<"\n";
    cout<<"Enter deposit amount to start betting: $";
    cin>>deposit;

    system("cls");

}

void draw_line(int n){

    cout<<"\n\n\n";

    for(i=0;i<n;i++)
        cout<<"_";

    cout<<"\n";

}

void rules(){

    cout<<"\n\n\t\t\t\t\tWELCOME TO ROYAL CASINO\n\n";

    cout<<"\tRULES:\n";

    cout<<"\n\n";
    cout<<"1.You have to guess a number between 1 to 10.\n\n";
    cout<<"2.If the number matches the winning number then you will get 10 times of the betting amount.\n\n";
    cout<<"3.If you fail to guess the winning number, you loose the entire betting amount.\n";

}

void start(){

    again:

    if(deposit > 0){

    cout<<"\n\n";
    cout<<"You have $"<<deposit<<" as your current balance amount.";
    cout<<"\n\n";
    re_enter: cout<<"\nEnter the amount you want to bet: $";
    cin>>bet_amount;

    if(bet_amount > deposit){
        cout<<"\n\nYour betting amount is greater than the deposit money !\n";
        cout<<"\nYou can choose betting amount only up to $"<<deposit<<"\n\n";
        goto re_enter;
    }

    deposit -= bet_amount;

    cout<<"\nEnter a number to guess: ";
    cin>>guess;

    lucky = rand()%10+1;

    if(lucky == guess){
        cout<<"\nYeppie ! You guessed the correct number !\n\n";
        deposit  = deposit + (bet_amount*10);
        cout<<"You current deposit balance is $"<<deposit<<"\n\n";
    }
    else{
        cout<<"\nBad luck !!! You guessed the wrong number !!\n\n";
        cout<<"\nWinning number: "<<lucky<<"\n";
        cout<<"\nYou current deposit balance is $"<<deposit<<"\n\n";
    }

    cout<<"\nContinue betting ? (y/n)\n";
    cout<<"choice: ";
    cin>>choice;

    if(choice == 'y')
        goto again;

    else
        cout<<"\n\nDo come again !\n\n";

    }
    else{

        cout<<"\nYou don't have enough deposit money to play the game !\n\n";

        cout<<"\nDeposit more money ?(y/n)\n";
        cout<<"choice: ";
        cin>>choice;

        if(choice == 'y'){
        system("cls");
        cout<<"Enter deposit money: $";
        cin>>deposit;
        start();
        }
        else
        cout<<"\n\nDo come again !\n\n";
    }


}


