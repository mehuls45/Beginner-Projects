#include<iostream>
#include<cstdlib>
using namespace std;

char num[] = {'o','1','2','3','4','5','6','7','8','9'};

void board();
int check_win();

int main(){

    int player = 1;
    int put,i;

    char mark;

    do{
    board();

    player = (player % 2)?1:2;

    mark = (player == 1)?'X':'O';

    cout<<"\tPlayer "<<player<<". Select a number:  ";
    cin>>put;

    if(put == 1 && num[1] == '1')
        num[1] = mark;

     else if(put == 2 && num[2] == '2')
        num[2] = mark;

     else if(put == 3 && num[3] == '3')
        num[3] = mark;

     else if(put == 4 && num[4] == '4')
        num[4] = mark;

     else if(put == 5 && num[5] == '5')
        num[5] = mark;

     else if(put == 6 && num[6] == '6')
        num[6] = mark;

     else if(put == 7 && num[7] == '7')
        num[7] = mark;

     else if(put == 8 && num[8] == '8')
        num[8] = mark;

     else if(put == 9 && num[9] == '9')
        num[9] = mark;

    else{
        cout<<"\n\t\tError: Invalid move !";
        player--;
        cin.ignore();
        cout<<" Press enter to continue playing.";
        cin.get();
    }

    i = check_win();
     player++;

    }while(i == -1);

        board();

        if(i == 1)
            cout<<"\n\t\tPlayer "<<--player<<" wins !\n";
        else if(i == 0)
        cout<<"\n\t\tGame Draw !\n";
}

/*  Returns:
	1 if game is over with result !
	-1 if game is in progress !
	0 if game is over and no result !  */

    void board(){

    system("cls");

    cout<<"\n\t\tTIC-TAC-TOE\n\n";
    cout<<"\tPlayer 1: X";
    cout<<"\tPlayer 2: O\n\n";

	cout<< "\t\t     |     |     " <<"\n";
	cout<< "\t\t  " << num[1] << "  |  " << num[2] << "  |  " << num[3] <<"\n";

	cout<< "\t\t_____|_____|_____" <<"\n";
	cout<< "\t\t     |     |     " <<"\n";

	cout<< "\t\t  " << num[4] << "  |  " << num[5] << "  |  " << num[6] <<"\n";

	cout<< "\t\t_____|_____|_____" <<"\n";
	cout<< "\t\t     |     |     " <<"\n";

	cout<< "\t\t  " << num[7] << "  |  " << num[8] << "  |  " << num[9] <<"\n";

	cout<< "\t\t     |     |     " <<"\n\n";


    }

    int check_win(){

        if(num[1] == num[2] && num[2] == num[3])
            return 1;

        else if(num[4] == num[5] && num[5] == num[6])
            return 1;

         else if(num[7] == num[8] && num[8] == num[9])
            return 1;

         else if(num[1] == num[4] && num[4] == num[7])
            return 1;

         else if(num[2] == num[5] && num[5] == num[8])
            return 1;

         else if(num[3] == num[6] && num[6] == num[9])
            return 1;

         else if(num[1] == num[5] && num[5] == num[9])
            return 1;

         else if(num[3] == num[5] && num[5] == num[7])
            return 1;

        else if(num[1]!='1' && num[2]!='2' && num[3]!='3' && num[4]!='4' && num[5]!='5' && num[6]!='6' && num[7]!='7' &&
                num[8]!='8' && num[9]!='9')
            return 0;

        return -1;

    }
