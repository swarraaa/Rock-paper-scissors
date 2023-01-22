#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char rock = 'r', paper = 'p', scissors = 's';
char player, comp;
string name;
int pscore=0, cscore=0;

void playerchoice()
{
    cout << "\n\tOptions: \n\t\t(r) for ROCK \n\t\t(p) for PAPER \n\t\t(s) for SCISSORS" << endl;
    cout << "\n\tEnter your choice: ";
    cin >> player;
    while (player != 'r' && player != 'p' && player != 's')
    {
        cout << "\n\tPlease choose one of the following options only. \n\t\t(r) for rock \n\t\t(p) for paper \n\t\t(s) for scissors " << endl;
        cout<<"\n\t\tEnter your choice : ";
        cin >> player;
    }
    cout << "\t" << name << "'s choice is: ";
    if (player == 'r'){ cout << "Rock" << endl; }    
    if (player == 'p'){ cout << "Paper" << endl; }   
    if (player == 's'){ cout << "Scissors" << endl; }
}

void computerchoice()
{
    int num = rand() % 3 + 1;
    if (num == 1) { comp = 'r'; }
    if (num == 2) { comp = 'p'; }
    if (num == 3) { comp = 's'; }
    cout << "\n\tComputer's choice is: ";
    if (comp == 'r'){ cout << "Rock" << endl; }    
    if (comp == 'p'){ cout << "Paper" << endl; }   
    if (comp == 's'){ cout << "Scissors" << endl; }
}

void score(char winner){
    if(winner=='c')
    {
        cscore++;
        cout<<"\n\tCurrent score: ";
        cout<<"\n\t\t"<<name<<" : "<<pscore<<"\tComputer : "<<cscore<<endl;
    }
    else if(winner=='p')
    {
        pscore++;
        cout<<"\n\tCurrent score: ";
        cout<<"\n\t\t"<<name<<" : "<<pscore<<"\n\t\tComputer : "<<cscore<<endl;
    }
    else{
        cout<<"\n\tCurrent score: ";
        cout<<"\n\t\t"<<name<<" : "<<pscore<<"\n\t\tComputer : "<<cscore<<endl;
    }
}

void winner(){
    cout<<"\n\t";
    if (player == rock && comp == paper)
    {
        cout << "Computer Wins! Paper wraps Rock." << endl;
        score('c');
    }
    else if (player == paper && comp == scissors)
    {
        cout << "Computer Wins! Scissors cut Paper." << endl;
        score('c');
    }
    else if (player == scissors && comp == rock)
    {
        cout << "Computer Wins! Rock smashes Scissors." << endl;
        score('c');
    }
    else if (player == rock && comp == scissors)
    {
        cout <<name<<" Wins! Paper wraps Rock." << endl;
        score('p');
    }
    else if (player == paper && comp == rock)
    {
        cout <<name<<" Wins! Paper wraps Rock." << endl;
        score('p');
    }
    else if (player == scissors && comp == paper)
    {
        cout <<name<<" Wins! Scissors cut Paper." << endl;
        score('p');
    }
    else
    {
        cout << "It's a tie! Play again win the Game." << endl;
        score('t');
    }
}

void continueGame(int *choice){
    cout<<"\n\tEnter (1) to continue the game and (0) to end the game : ";
    cin>>*choice;
}

int main()
{
    cout << "\n\t\t\tO----------- Welcome to the game ROCK-PAPER-SCISSORS -----------O" << endl;
    cout << "\n\tWin against the computer to be smarter than a machine ;) ";
    cout << "\n\tYour name: ";
    cin >> name;
    cout << "\n\tLet the game begin!" << endl;
    cout << "\n\t\t" << name << " v/s Computer" << endl;
    int choice = 1;
    while (choice)
    {
        playerchoice();
        srand(time(0));
        computerchoice();
        winner();
        continueGame(&choice);
    }
    return 0;
}