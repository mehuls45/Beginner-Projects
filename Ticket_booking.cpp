#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int seat_no;
    char row_no;
    char status;
    node *next;
    node *prev;
};

class cinemax{
public:
    node *hn,*cn;
      char ROW,row;
      int COL,seat,i;

    cinemax(){
        hn = NULL;
    }

    void create(){
        ROW = 'A';
         i=1;
        do{
            COL = 1;
        do{
        node *nn;
        nn = new node;
        nn->next = nn->prev = NULL;
        nn->row_no = ROW;
        nn->seat_no = COL;
        nn->status = 'n';

        if(hn == NULL){
            hn = nn;
            nn->next = nn->prev = hn;
        }
        else{
            cn = hn;

        while(cn->next!=hn)
            cn = cn->next;

        cn->next = nn;
        nn->prev = cn;
        nn->next = hn;
        hn->prev = nn;
        }
        COL++;
        }while(COL<=9);
        ROW++;
        i++;
        }while(i<=10);
    }

    void display(){
        int j;
        i=j=1;
        cn = hn;
        cout<<"\n\n";
        cout<<"\t\t\t\t\t\t   SCREEN THIS SIDE\n\n";
        cout<<"\t  ------------------------------------------------------";
        cout<<"-----------------------------------------------\n\n\n";
        for(i=1;i<=10;i++){
                cout<<"\t\t";
            for(j=1;j<=9;j++){
                    if(cn->status=='n'){
                    cout<<"  "<<cn->row_no<<cn->seat_no;
                    cout<<"      ";
                    }
                    else{
                        cout<<"BOOKED    ";
                    }
                    cn = cn->next;
            }
            cout<<"\n\n";
        }
        cout<<"\n\t  ------------------------------------------------------";
        cout<<"-----------------------------------------------\n";
    }

    void book_tickets(){
        int tickets,number;
        number = 0;
        cout<<"\n\nNumber of tickets to book:  ";
        cin>>tickets;
        for(i=1;i<=tickets;i++){
            cout<<"Ticket "<<i<<": ";
            cin>>row>>seat;

           if((row>='A' && row<='J') && (seat>=1 && seat<=9)){
                cn = hn;
           while(cn->row_no != row)
            cn = cn->next;

           while(cn->seat_no!=seat)
            cn = cn->next;

           if(cn->row_no == row && cn->seat_no == seat){
            cn->status = 'b';
            number++;                          //count of successfully booked tickets
           }

           }else{
               cout<<"ENTER A VALID SEAT NUMBER!!"<<endl;
           }
            cout<<"\n";
        }
         cout<<"\n"<<number<<" TICKETS BOOKED SUCCESSFULLY !!!\n\n";
    }

    void cancel_booking(){
        cout<<"\nEnter row and seat number to cancel booking: ";
        cin>>row>>seat;

         if((row>='A' && row<='J') && (seat>=1 && seat<=9)){
                cn = hn;
           while(cn->row_no != row)
            cn = cn->next;

           while(cn->seat_no!=seat)
            cn = cn->next;

           if(cn->row_no == row && cn->seat_no == seat && cn->status=='b'){
            cn->status = 'n';
            cout<<"\nTicket booking of "<<row<<seat<<" canceled successfully !\n\n";
           }
           else{
            cout<<"\nUNBOOKED SEATS CANNOT BE CANCELLED !!!\n\n";
           }
           }else{
               cout<<"\nENTER A VALID SEAT NUMBER!!"<<"\n\n";
           }
    }
};

int main(){
    cinemax obj;
    int choice;
    obj.create();
    obj.display();
     cout<<"\n";
    do{
            cout<<"\n";
            cout<<"***** MENU *****"<<endl;
            cout<<"1.Book tickets"<<endl;
            cout<<"2.Show status"<<endl;
            cout<<"3.Cancel booking"<<endl;
            cout<<"4.Exit"<<endl;
            cout<<"Choice: ";
            cin>>choice;

            switch(choice){
            case 1: obj.book_tickets();
                break;
            case 2: obj.display();
                break;
            case 3: obj.cancel_booking();
                break;
            case 4: system("cls");
                    cout<<"\n\n\t\tTHANK YOU AND COME AGAIN !\n\n";
                break;
            }
    }while(choice!=4);
}
