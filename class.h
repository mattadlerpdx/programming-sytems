//This file manages the header for all classes:
//Character: fairy, prince, dragon
//Event: volcanoe, lost weapon
//ManageCll: holds CllNode HeadObj
//CllNode: holds Character array of objects
//LLLManageWins: array of Linked lists of wins
//LLLNode: number of wins for player and computer
#include <iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include <sys/time.h>
using namespace std;
class Event{
    public:
        Event();
        ~Event();
        Event(int x);
       int happen();
    private:
        int data;
};
class Volcano:public Event{
    public:
        Volcano();
        ~Volcano();
};
class fullHealth:public Event{
    public:
    fullHealth();
    ~fullHealth();

};
class LLL{//node
    public:
        LLL();
        ~LLL();
        LLL(LLL & src);
        int copy(LLL&src);
        LLL *& getNext();
        int setNext(LLL *&head);
        int setData(int toSet);
        char getData();
    private:
    LLL *next;
    char players;
};
class Battle{
    public: 
        Battle();
        ~Battle();
        Battle(Battle & src);
        int copy(Battle &src);
        int insert(int index,int player);//index of array, info at node
        int display();
        int removeAll(int i);
    private:
        int display(LLL * head);
        int copyR(LLL *src,LLL*&dest);
        int remove_all(LLL *&current);
        int i;
        LLL**head;//one index for wins, other for losses;Index for 1 for winner, 2 for losers
};

class Body{//BASE CLASS FOR CHARACTERS: FAIRY, PRINCE, DRAGON
    public:
        Body();
        virtual ~Body();
        //Body( Body &src);
        virtual int attack()=0;
        virtual int copy(Body & src);
        virtual int setHealth(int toSet);
        virtual int hitHealth(int attack);//affected by opponent attack()
        virtual int showHealth();
        virtual int pickUpWeapon();
        virtual int getWins();
        virtual int setWins(int toSet);
        virtual int giveWin();
        virtual char getName()=0;
        //event* showEvent();
    private:
        int health;
        int wins;
        char name;
        // Event event;
};
class CllNode{
    public:
        CllNode();//initialize data to NULL
        ~CllNode();//delete [] array, next
        CllNode(CllNode & src);//copy constructor RTTI
        int copy(CllNode & src);
        int insert(Body *ptr);
        int display();
        CllNode *& getNext();
        void setNext(CllNode * const toSet);
        int getAttack(char input);
        char getCharacter();
        int hitHealth(int attack, char toHit);
        int getHealth();
        int insertWinner(char winner);//THIS INSERTS A WINNER AND LOSER
        int insertLoser(char loser);
    private:
        CllNode * next;
        Body **array;//array of character/body objects
        Battle object;
        int i;
};
class ManageCll{//Manages CLL of body array objects, i.e. characters player has
    public:
        ManageCll();
        ~ManageCll();
        ManageCll(ManageCll & src);
        int insert(int response);
        int remove(int toRemove);
       int removeAll();
        int display();
        int attack(char toAttack);
        int hitHealth(int attack, char toHit);
        int displayHealth();
    private:
        int copy(CllNode *&dest, CllNode *src, CllNode * srcRear);
        int removeAll(CllNode *&curr);
        int display(CllNode * current);
        int displayHealth(CllNode*current);
        CllNode *rear;
};
class Fairy: public Body{
    public:
        Fairy();
        ~Fairy();
        //Fairy(const Fairy & fairy);
        int attack();//returns a number to main, recieved by opponentdecrements opponent health
        int setHealth(int toSet);
        int hitHealth(int attack);//affected by opponent attack()
        int showHealth();
        int pickUpWeapon();
        int getWins();
        int setWins(int toSet);
        int giveWin();
        char getName();

    private:
        int health;
        int wins;
        char name;
};
class Prince: public Body{
    public:
        Prince();
        ~Prince();
        //Prince(const Prince & prince);
        int attack();//returns a number to main, recieved by opponentdecrements opponent health
        int setHealth(int toSet);
        int hitHealth(int attack);//affected by opponent attack()
        int showHealth();

        int pickUpWeapon();
        int getWins();
        int setWins(int toSet);
        int giveWin();
        char  getName();
    private:
        int health;
        int wins;
        char name;
    
};
class Dragon: public Body{
    public:
        Dragon();
        ~Dragon();
        //Dragon(const Dragon & dragon);
        int attack();//returns a number to main, recieved by opponentdecrements opponent health
        int setHealth(int toSet);
        int hitHealth(int attack);//affected by opponent attack()
        int showHealth();

        int pickUpWeapon();
        int getWins();
        int setWins(int toSet);
        int giveWin();
        char getName();
    private:
        int health;
        int wins;
        char name;
};
