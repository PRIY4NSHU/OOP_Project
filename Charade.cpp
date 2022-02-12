#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string.h>
#include <windows.h>
int l1,l2;
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
class player
{
public:
    char set_player();
};


//select number of players

char player::set_player()
{

    // system("COLOR 2");
    cout<<"\t\t\t\t Select the player mode\n\n";
    cout<<"\t\t\t\t press:\n";
    cout<<"\t\t\t\t 1 to play with computer \n \t\t\t\t 2 for two players\n";
    char chp;//choose player
    cout<<"\n\t\t\t\t Enter your choice: ";
    cin>>chp;
    // cout<<chp<<"\n";
    if(chp=='1' || chp=='2')
    return chp;
    else {
        SetConsoleTextAttribute(h,8);
    cout<<"\t\t\t\tEnter a valid input\n";
    SetConsoleTextAttribute(h,2);
    chp = set_player();
    return chp;
    }

}
//select difficulty level
class level
{
public:
    char lev_sel()
    {
        SetConsoleTextAttribute(h,2);
        cout<<"\n\t\t\t\t Select the level\n\n";
        cout<<"\t\t\t\t E for easy\n\t\t\t\t M for medium \n\t\t\t\t H for hard\n";
        char ch;
        cout<<"\n\t\t\t\t Enter your choice: ";
        cin>>ch;
        cout<<"\n\n";
        return ch;
    }
};
//generate a secret number for single player
class secret_number : public level //inherited from class level
{
    public:
        int setnum(char ch)
        {
            int num;

            if(ch=='E')
            {
                srand(time(0));
                num = rand()%100+1;//random number generating funtion
                cout<<"\t\t\t\t Guess a number from 1-100\n";
            }

            else if(ch=='M')
            {
                srand(time(0));
                num = rand()%500+1;
                 cout<<"\t\t\t\t Guess a number from 1-500\n";
            }

            else if(ch=='H')
            {
                srand(time(0));
                num = rand()%1000+1;
                 cout<<"\t\t\t\t Guess a number from 1-1000\n";
            }

            else {
                SetConsoleTextAttribute(h,8);
                cout<<"\t\t\t\t Enter a valid option\n";
                SetConsoleTextAttribute(h,2);
                char a = level::lev_sel();//jump to level selection
                //recursive call for invalid input
                cout<<a<<endl;
                num = setnum(a);
            }
          //  cout<<num<<endl;
            return num;
        }

};
//overloaded fuction for single and multiplayer
class guess_num
{
public:
    static int score1;

    static int score2;
    void game(int);   //handles single player
    int game(int, int); //handles 2 player

    void play(int, int, char[], char[]);//only for 2 player
};
int guess_num::score1=0;
int guess_num::score2=0;

void guess_num::play(int n1, int n2, char name1[], char name2[])
{
    int num1, num2, cnt1=0, cnt2=0, wincnt , flag1,flag2;
    while(cnt1<10)
    {
    cout<<"\t\t\t "<<name1<<"'s turn...\n\t\t\t Enter your guess: ";
    cin>>num1;
    if(num1>n2)
    {
        if(abs(num1-n2)>=1000)
        cout<<"\n\t\t\t\t Too high...nearly 1000 more than the target\n\n";

        else if(abs(num1-n2)>=500)
        cout<<"\n\t\t\t\t Too high...nearly 500 more than the target\n\n";

        else if(abs(num1-n2)>=100)
        cout<<"\n\t\t\t\t Too high...nearly 100 more than the target\n\n";

        else
        cout<<"\n\t\t\t\t Nope. That was too high\n\n";
    }
    else if(num1<n2)
    {

        if(abs(num1-n2)>=1000)
        cout<<"\n\t\t\t\t Too low...nearly 1000 less than the target\n\n";

        else if(abs(num1-n2)>=500)
        cout<<"\n\t\t\t\t Too low...nearly 500 less than the target\n\n";

        else if(abs(num1-n2)>=100)
        cout<<"\n\t\t\t\t Too low...nearly 100 less than the target\n\n";

        else
        cout<<"\n\t\t\t\t Too low. Raise the number\n\n";
    }
    //flag = game(num1, n2);
    cnt1++;
    cout<<"\t\t\t ";
    for(int i=0;i<20+l1;i++)
    cout<<" ";
    cout<<name2<<"'s turn...\n";

    cout<<"\t\t\t ";
    for(int i=0;i<20+l1;i++)
    cout<<" ";
    cout<<"Enter your guess: ";
    cin>>num2;
    if(num2>n1)
    {
        if(abs(num2-n1)>=1000)
        cout<<"\n\t\t\t\t Too high...nearly 1000 more than the target\n\n";

        else if(abs(num2-n1)>=500)
        cout<<"\n\t\t\t\t Too high...nearly 500 more than the target\n\n";

        else if(abs(num2-n1)>=100)
        cout<<"\n\t\t\t\t Too high...nearly 100 more than the target\n\n";

        else
        cout<<"\n\t\t\t\t Nope. That was too high\n\n";
    }
    else if(num2<n1)
    {
        if(abs(num2-n1)>=1000)
        cout<<"\n\t\t\t\t Too low...nearly 1000 less than the target\n\n";

        else if(abs(num2-n1)>=500)
        cout<<"\n\t\t\t\t Too low...nearly 500 less than the target\n\n";

        else if(abs(num2-n1)>=100)
        cout<<"\n\t\t\t\t Too low...nearly 100 less than the target\n\n";

        else
        cout<<"\n\t\t\t\t Too low. Raise the number\n\n";
    }

    cnt2++;
    flag1= game(num1, n2);
    flag2= game(num2, n1);
    if (flag1==1 || flag2==1)
    break;
    }
    if(cnt1>=10)
    {
    cout<<"\t\t\t\t Looks like this will go on forever...\n\t\t\t\t Let's end this round in a tie\n";
    cout<<"\t\t\t The number given by "<<name1<<" was "<<n1<<endl;
    cout<<"\t\t\t The number given by "<<name2<<" was "<<n2<<endl;
    return;
    }
    cout<<"\n\t\t\t\t That's a correct guess!!!"<<endl;
    cout<<"\t\t\t\t ";
    //cout<<"flag1: "<<flag1<<" flag2: "<<flag2<<"cnt1:"<<cnt1<<" cnt2: "<<cnt2<<endl;
    if(flag1!=flag2)
    {
        if(flag1==1)
        cout<<name1;
        else if(flag2==1) cout<<name2;
        wincnt = (cnt1>cnt2)?cnt1:cnt2;
        cout<<" guessed the secret number in ";
        cout<<wincnt;
        cout<<" attempts and has won the round\n\n";
         (flag1>flag2)? score1+=(11-cnt1)
                     : score2+=(11-cnt2);
    }

    else{
        cout<<"\n\t\t\t\t"<<name1<<" and "<<name2<<" scored same\n";
        score1+=(11-cnt1);
        score2+=(11-cnt2);
    }

}
//overloaded fuction for single and multiplayer
int guess_num::game(int num, int check)
{
    // cout<<"check= "<<check<<endl;
    if(num>check)
    {
        //cout<<"\n\t\t\t\t Nope. That was too high\n\n";
        return 0;
    }

    else if(num<check)
    {
        //cout<<"\n\t\t\t\t Too low. Raise the number\n\n";
        return 0;
    }

    else if(num==check)
    {
        return 1;
    }
}

//fuction to give hints to the players
void guess_num::game(int num)
{
    //cout<<num<<"\n";
    // system("COLOR 2");
    int guess;
    int attempt=0;
    while(attempt<10)
    {
        cout<<"\t\t\t\t Guess: ";
      cin>>guess;
      attempt++;

      if(num<guess)
           cout<<"\t\t\t\t come down a little\n";

      else if(num>guess)
           cout<<"\t\t\t\t raise the number\n";

      if(num==guess)
        break;

    }
    if(attempt>10)
    {
        cout<<"\n\n\t\t\t\t Better luck next time \n \t\t\t\t You took too many tries:( \n\n";
        cout<<"\t\t\t\t The number was "<<num<<endl;
    }
    else
    {
        score1=11-attempt;
        cout<<"\n\n\t\t\t\t CONGRATULATIONS...\n\n \t\t\t\t you won with score "<<score1;
        cout<<"\n";
    }
}
//end lines
class endd
{
public:
    char print_end()
    {
        cout<<"\t\t\t\tWould you like to play another game??\n";
        cout<<"\n\t\t\t\t Enter N for new game  Q to quit\n";
        cout<<"\n\n \t\t\t\t NEW GAME\n \t\t\t\t QUIT\n";
        char ch;
        cout<<"\n \t\t\t\t Enter your choice: ";
        cin>>ch;
        return ch;
    }
};


int main()
{
     cout<<endl<<endl;
     SetConsoleTextAttribute(h,13);//color change
     for(int i=0;i<=100;i++)
     cout<<"*";
     cout<<endl<<endl;
     SetConsoleTextAttribute(h,5);
     cout<<"\t\t\t\t    *WELCOME TO THE GUESSING GAME*\n\n";
     SetConsoleTextAttribute(h,13);
     for(int i=0;i<=100;i++)
     cout<<"*";
     cout<<endl<<endl;
     SetConsoleTextAttribute(h,2);
    while(1)//infinite loop
    {

        player p;
        char chp=p.set_player();  //select number of players
        //cout<<chp<<"\n";
        //player 1 code
        if(chp=='1')
       {
           char chl;//choose level
           level L;//class
           chl=L.lev_sel(); //level selection

           secret_number num; //secret number generation
           int number = num.setnum(chl);
            // cout<<"under comment"<<number<<"\n";


           guess_num play;
           play.score1=0;
           play.score2=0;
           play.game(number);


       }
       //player 2 code

       if(chp=='2')
       {
           char name1[20], name2[20];
           int n1, n2;
           guess_num start;
           start.score1=0;
           start.score2=0;

           cout<<"\t\t\t\t Player 1 enter your name: ";
           cin>>name1;
           l1=strlen(name1);
           cout<<"\t\t\t\t Player 2 enter your name: ";
           cin>>name2;
           l2=strlen(name2);
           //player 1 vs player 2 box
          cout<<"\t\t\t ";
          //line 1
           for(int i=0;i<l1+l2+26;i++) //for making box
          cout<<"_";
          cout<<endl;
          //line 2
          cout<<"\t\t\t|";
          for(int i=0;i<l1+l2+26;i++)
          cout<<" ";
          cout<<"|";
          cout<<endl;
          //line 3

          cout<<"\t\t\t|  "<<name1<<"          VS          "<<name2<<"  |\n";
          //line 4
          cout<<"\t\t\t|";
          for(int i=0;i<l1+l2+26;i++)
          cout<<"_";
          cout<<"|\n";

           int rn=1; //round no.

           while(rn<=3)
           {
            SetConsoleTextAttribute(h,6);
           cout<<"\n\t\t\t ";
           for(int i=0; i<l1+8; i++)
           cout<<" ";
            cout<<":Round "<< rn <<":"<<endl<<endl;
           SetConsoleTextAttribute(h,2);
           cout<<"\t\t\t\t "<<name1<<" give a secret number for "<<name2<<" to guess"<<endl<<"\t\t\t\t ";
           SetConsoleTextAttribute(h,0);
           cin>>n1;
           SetConsoleTextAttribute(h,2);
           cout<<"\t\t\t\t "<<name2<<" give a secret number for "<<name1<<" to guess"<<endl<<"\t\t\t\t ";
           SetConsoleTextAttribute(h,00);
           cin>>n2;
           SetConsoleTextAttribute(h,2);

          //Individual boxes
          //line 1
          cout<<"\t\t\t ";
          for(int i=0; i<l1+4; i++)
          cout<<"_";
          for(int i=0; i<18; i++)
          cout<<" ";
          for(int i=0; i<l2+4; i++)
          cout<<"_";
          cout<<endl;
          //line 2
          cout<<"\t\t\t|";
          for(int i=0; i<l1+4; i++)
          cout<<" ";
          cout<<"|";
          for(int i=0; i<16; i++)
          cout<<" ";
          cout<<"|";
          for(int i=0; i<l2+4; i++)
          cout<<" ";
          cout<<"|\n";
          //line 3
          cout<<"\t\t\t|  "<<name1<<"  |";
          for(int i=0; i<16; i++)
          cout<<" ";
          cout<<"|  "<<name2<<"  |\n";
          //line 4
          cout<<"\t\t\t|";
          for(int i=0; i<l1+4; i++)
          cout<<"_";
          cout<<"|";
          for(int i=0; i<16; i++)
          cout<<" ";
          cout<<"|";
          for(int i=0; i<l2+4; i++)
          cout<<"_";
          cout<<"|\n\n";


           start.play(n1, n2, name1, name2);
           SetConsoleTextAttribute(h,9);
           cout<<"\n\t\t\t\t Scores:\n";
           cout<<"\t\t\t\t "<<name1<<": "<<guess_num::score1<<"\t"<<name2<<": "<<guess_num::score2<<endl<<endl;
           SetConsoleTextAttribute(h,2);
           rn++;
           }


           SetConsoleTextAttribute(h,15);
           cout<<"\n\n\t\t\t\t **CONGRATULATIONS**:)!!!\n\n";
           if(guess_num::score1>guess_num::score2)
           cout<<"\t\t\t\t "<<name1<<" has won the game!!\n";
           else if (guess_num::score1==guess_num::score2)
           cout<<"\t\t\t\t THAT WAS A TIE\n ";
           else cout<<"\t\t\t\t "<<name2<<" has won the game!!\n";
           SetConsoleTextAttribute(h,2);

       }

       endd E;
       char quit;
       quit=E.print_end();
       if(quit =='Q'){
        // cout<<"\t\t\t\t Thanks for playing";
        SetConsoleTextAttribute(h,13);
     for(int i=0;i<=100;i++)
     cout<<"*";
     cout<<endl<<endl;
     SetConsoleTextAttribute(h,5);
     cout<<"\t\t\t\t    * THANKS FOR PLAYING :D *\n\n";
     SetConsoleTextAttribute(h,13);
     for(int i=0;i<=100;i++)
     cout<<"*";
        break;
       }
    }
}
