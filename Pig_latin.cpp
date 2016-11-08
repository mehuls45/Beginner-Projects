#include<iostream>
#include<cstring>
using namespace std;

int vowel(char);

int main(){

    char word[80],init,con[80],new_word[80];
    int i,k,j;

    cout<<"Enter a word: ";
    cin>>word;

    init = word[0];

    if(vowel(init)){

        strcat(word,"way");

        cout<<"\nNew word: "<<word<<"\n\n";

    }
    else {
        k = 0;
        i = 0;
        j = 0;
       // con = "";

        while(word[i]!='\0' && !vowel(word[i])){

            con[k++] = word[i++];
        }

        con[k] = '\0';

        while(word[i]!='\0')
            new_word[j++] = word[i++];

        new_word[j] = '\0';

        strcat(new_word,con);
        strcat(new_word,"ay");

        cout<<"\nNew word: "<<new_word<<"\n\n";

        }

    }


int vowel(char token){

    if(token=='A'||token=='E'||token=='I'||token=='O'||token=='U'||token=='a'||token=='e'||token=='i'||token=='o'||token=='u')
        return 1;
    return 0;

}
