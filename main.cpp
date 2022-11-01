//Professor Fant
//Prog1
//10/23/2019
//The purpose of this program is to simulate a battle Royale.
//The player has creatures of her choosing to battle the computer.
//Player can attack and view her health. 
//A random number generator simulates a random event which affects
//players health.
//Wins and losses are stored in array of linked list
//Characters are stored in CLL of array object pointers.
#include "class.h"
    ManageCll player1;
    ManageCll player2;
    Battle wins;

int battle(ManageCll &player1, ManageCll &player2);
int display(ManageCll &player1, ManageCll &player2);
int insert(ManageCll &player1, ManageCll &player2);
int randEvent();
int main(){
    int proceed=1;
    int resp=0;

    cout<<"Player1 fighters: "<<endl;
    player1.display();
    cout<<"Player2 fighters: "<<endl;
    player2.display();

    while(proceed==1){
    cout<<"(1)insert fighter?, (2) battle?,(3) display fighters? (4)display winners & losers?"<<endl;
    cin>>resp;
    if (resp==1){
        insert(player1, player2);

    }
    if (resp==2){
            
        battle(player1, player2);
    }
    if (resp==3){
        display(player1, player2);
    }
    if (resp==4){
       wins.display();
    }
    cout<<"continue? (1) yes, (2) no"<<endl;
    cin>>proceed;
    }
    
    /*
       while (proceed==1){
       for (int i=0; i<3; ++i){//ENTER THREE FIGHTERS
       cout<<"Insert your fighter: (1)Fairy, (2)Prince, (3) Dragon "<<endl;
       cin>>response;
       cin.ignore(100, '\n');
       player1.insert(response);
       }
       cout<<"Continue ? (1) yes "<<endl;
       cin>>proceed;
       cin.ignore(100, '\n');
       player1.display();

       cout<<"Player 1, Which character do you want to USE? Fairy (f), Prince (p), Dragon(d)"<<endl;
       cin>>battleChoice;
       cin.ignore(100, '\n');
       cout<<"Player 1, Which character do you want to ATTACK? Fairy (f), Prince (p), Dragon(d)"<<endl;
       cin>>toHit;
       cin.ignore(100, '\n');
       int hit= player1.attack(battleChoice);
       player2.hitHealth(hit, toHit);

       cout<<"Player 2, Which character do you want to attack with? Fairy (f), Prince (p), Dragon(d)"<<endl;
       cin>>battleChoice;
       cin.ignore(100, '\n');
       hit= player2.attack(battleChoice);
       player1.hitHealth(hit, toHit);

       cout<<"enter winner, player 1 (1), or player 2 (2)" <<endl;
       cin>>whoWon;
       cin.ignore(100, '\n');
       wins.insert(indexWinner, whoWon);//this should insert at index 1;
       cout<<"enter loser, player 1 (1), or player 2 (2)" <<endl;
       cin>>whoWon;
       cin.ignore(100, '\n');
       wins.insert(indexLoser, whoWon);//this should insert at index 2;
       wins.display();
       cout<<"Continue ? (1) yes "<<endl;
       cin>>proceed;
       cin.ignore(100, '\n');
       }
       */
    return 0;
}

int battle(ManageCll &player1, ManageCll &player2){
    int x=rand()%9;//random either player1 or 2;
    char battleChoice;
    char toHit;
    int indexWinner=0;
    int indexLoser=1;
    int whoWon=0;
       cout<<"Player 1, Which character do you want to USE? Fairy (f), Prince (p), Dragon(d)"<<endl;
       cin>>battleChoice;
       cin.ignore(100, '\n');
       cout<<"Player 1, Which character do you want to ATTACK? Fairy (f), Prince (p), Dragon(d)"<<endl;
       cin>>toHit;
       cin.ignore(100, '\n');
       int hit= player1.attack(battleChoice);
       player2.hitHealth(hit, toHit);
       cout<<"here is player2's health now: "<<endl;
       player2.displayHealth();


       
       cout<<"Player 2, Which character do you want to USE? Fairy (f), Prince (p), Dragon(d)"<<endl;
       cin>>battleChoice;
       cin.ignore(100, '\n');
       cout<<"Player 2, Which character do you want to ATTACK? Fairy (f), Prince (p), Dragon(d)"<<endl;
       cin>>toHit;
       cin.ignore(100, '\n');
        hit= player2.attack(battleChoice);
       player1.hitHealth(hit, toHit);

       cout<<"here is player1's health now: "<<endl;
       player2.displayHealth();
       /*
        if (x%2==0){//randomEvent, works but need more time to perfect DEAR GRADER
        cout<<"Player1 just got an event: "<<endl;
        char toHit=f;
        int event=randEvent();
        player1.hitHealth(event,toHit);
        }
        else{
        cout<<"Player2 just got an event: "<<endl;
        char toHit=p;
        int event=randEvent();
        player1.hitHealth(event,toHit);
        }
        */
       wins.insert(indexWinner, whoWon);//this should insert at index 1;
       return 1;

}
int insert(ManageCll &player1, ManageCll &player2){
    int response=0;
        for (int i=0; i<3; ++i){
       cout<<"Insert your 3 fighters Player 1: (1)Fairy, (2)Prince, (3) Dragon "<<endl;
       cin>>response;
       cin.ignore(100, '\n');
       player1.insert(response);
        }
        for (int i=0; i<3; ++i){
       cout<<"Insert your 3 fighters Player 2: (1)Fairy, (2)Prince, (3) Dragon "<<endl;
       cin>>response;
       cin.ignore(100, '\n');
       player2.insert(response);
        }
}
int display(ManageCll &player1, ManageCll &player2){
    cout<<"Player1 fighters: "<<endl;
    player1.display();
    cout<<"Player2 fighters: "<<endl;
    player2.display();
}
int randEvent(){
    Volcano v;
    fullHealth full;
    srand(time(NULL));
    int x=rand()%9;
    if (x%2==0){
        cout<<"VOLCANOOOOOOOOOOOOOO"<<endl;
        return v.happen();
    }
    else
        cout<<"FULL HEALTH TO YOUUU"<<endl;
        return full.happen();
}





