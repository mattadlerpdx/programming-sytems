//The purpose of this program is to simulate a battle Royale.
//Body is the base class and holds hierarchy: fairy, prince, dragon
//Event: volcanoe, lost weapon
//ManageCll: holds CllNode HeadObj
//CllNode: holds Character array of objects
//LLLManageWins: array of Linked lists of wins
//LLLNode: number of wins for player and computer
#include "class.h"

Event::Event(): data(0){}
Event::Event(int x):data(x){}
Event::~Event(){}
int Event::happen(){
    return data;
}
Volcano::Volcano():Event(10){}
Volcano::~Volcano(){}
fullHealth::fullHealth():Event(100){}
fullHealth::~fullHealth(){}
Battle::Battle(){
    head = new LLL*[2];
    for(int i=0; i<2; ++i){
        head[i]= NULL;
    }
}
Battle::~Battle(){
    for (int i=0; i<2; ++i){
        removeAll(i);
    }
}
int Battle::display(){
    if (!head){
        cout<<"no winners yet "<<endl;
        return 0;
    }
        cout<<"Here are the winners: "<<endl;
        display(head[0]);
        cout<<"Here are the losers: "<<endl;
        display(head[1]);
}
int Battle::display(LLL *head){
    if (!head)
        return 1;
    cout<<head->getData()<<endl;
    display(head->getNext());
} 
    
int Battle::copy(Battle &src){
    LLL*dest[2];
    for (int i=0; i<2; ++i){
       copyR(src.head[i],dest[i]);
    }
}    

int Battle::copyR(LLL *src,LLL*&dest){
    if (!src)
        return 1;
    dest=new LLL;
    dest->setData(src->getData());
    return copyR(src->getNext(), dest->getNext());
}

int Battle::removeAll(int i){
    if (!head)//no array
        return 0;
    remove_all(head[i]);
}

int Battle::remove_all(LLL *&current){
    if(!current)
        return 1;
    remove_all(current->getNext());
    delete current;
    current=NULL;
}

int Battle::insert(int index,int player){//index of array, info at node
    
    if (!head){//if no nodes
        head[index] = new LLL;
        head[index]->setData(player);
        
    }
    else{ 
        LLL *temp= new LLL;
        temp->setData(player);
        temp->setNext(head[index]);
        head[index]=temp;
    }
    return 1;
}
LLL::LLL(){
    next=NULL;
    players=0;
}
LLL::~LLL(){
    next=NULL;
    players=0;
}

LLL::LLL(LLL & src){
    copy(src);
}
int LLL:: copy(LLL&src){
    next=src.next;
    players=src.players;
    return 1;
}

LLL*&LLL::getNext(){
    return next;
}
int LLL::setNext(LLL *& head){
    next=head;
    return 1;
}
int LLL::setData(int toSet){
    players=toSet;
    return 1;
}
char LLL::getData(){
    return players;
}
Body::Body():health(100),wins(0){}
Body::~Body(){
    health=0;
}
/*
   Body::Body(Body &src){
   copy(src);
   }*/
int Body::copy(Body & src){
    this-> health=src.health;
    this->wins=src.wins;
    return 1;
}
int Body::setHealth(int toSet){
    health=toSet;
}
int Body::hitHealth(int attack){
    if(health==0)
        setHealth(0);

        return 0;
    return health-=attack;
}

int Body::showHealth(){
    return health;
}
int Body::pickUpWeapon(){

}

int Body::setWins(int toSet){
    wins+=toSet;
    return 1;
}
int Body::getWins(){
    return wins;
}
int Body::giveWin(){
    if (showHealth()==0){
        return 1;
    }
    return 0;
}

Fairy::Fairy():Body(){
   health=100; 
    name='f';
};
Fairy::~Fairy(){
    health=0;
    wins=0;
}
int Fairy::attack(){
    return 10;
}

int Fairy::setHealth(int toSet){
    health=toSet;
}
int Fairy::hitHealth(int attack){
    if(health==0)
        return 0;
    health-=attack;
    return health-=attack;
}

int Fairy::showHealth(){
    return health;
}
int Fairy::pickUpWeapon(){

}

int Fairy::setWins(int toSet){
    wins+=toSet;
    return 1;
}
int Fairy::getWins(){
    return wins;
}
int Fairy::giveWin(){
    if (health==0){
        return 1;
    }
    return 0;
}
char Fairy::getName(){
    return name;
}
Prince::Prince():Body(){
    health=100;
    name= 'p';
};
Prince::~Prince(){
    health=0;
    wins=0;
}
int Prince::attack(){
    return 5;
}

int Prince::setHealth(int toSet){
    health=toSet;
}
int Prince::hitHealth(int attack){
    if(health==0)
        return 0;
    health-=attack;
    return health;
}

int Prince::showHealth(){
    return health;
}
int Prince::pickUpWeapon(){

}

int Prince::setWins(int toSet){
    wins+=toSet;
    return 1;
}
int Prince::getWins(){
    return wins;
}
int Prince::giveWin(){
    if (health==0){
        return 1;
    }
    return 0;
}
char Prince::getName(){
    return name;
}

Dragon::Dragon():Body(){
    health=100;
    name= 'd';
};
Dragon::~Dragon(){
    health=0;
    wins=0;
}
int Dragon::attack(){
    return 15;
}
int Dragon::setHealth(int toSet){
    health=toSet;
}
int Dragon::hitHealth(int attack){
    if(health==0)
        return 0;
    health-=attack;
    return health;
}

int Dragon::showHealth(){
    return health;
}
int Dragon::pickUpWeapon(){

}

int Dragon::setWins(int toSet){
    wins+=toSet;
    return 1;
}
int Dragon::getWins(){
    return wins;
}
int Dragon::giveWin(){
    if (health==0){
        return 1;
    }
    return 0;
}
char Dragon::getName(){
    return name;
}

CllNode::CllNode(){
    this->next= NULL;
    array = new Body*[3];
    for(int i=0; i<3; ++i){
        array[i]= NULL;
    }

}
CllNode::~CllNode(){
    next=NULL;
    if(array){ 
        for (int i=0; i<3; ++i){
            if (array[i]){
                delete array[i];
                array[i]=NULL;
            }
        }
    }
    array=NULL;

}
CllNode::CllNode( CllNode & src){
    copy(src);
}

int CllNode::copy(CllNode &src){
    i=src.i;
    next=src.next;
    for (int i=0; i<3; ++i){
        Fairy*fPtr= dynamic_cast<Fairy*>(src.array[i]);
        Prince*pPtr= dynamic_cast<Prince*>(src.array[i]);
        Dragon*dPtr= dynamic_cast<Dragon*>(src.array[i]);
        if (fPtr){
            this->array[i] = new Fairy(*fPtr);
        }
        else if(pPtr){
            this->array[i]= new Prince(*pPtr);
        }
        else if(dPtr){
            this->array[i]= new Dragon(*dPtr);
        }
        else
            this->array[i]=NULL;
    }
}


int CllNode::display(){
    if (!array)
        return 0;
    for (int i=0; i<3; ++i){
        if (array[i])
            cout<<array[i]->getName()<<endl;
    } 
    return 1;
}

int ManageCll::display(){
    if (!rear)
        return 0;
    return display(rear);
}

int ManageCll::display(CllNode * current){   
    current->display();
    if(current->getNext()!=rear)
        display(current->getNext());
    return 1;
}
int ManageCll::attack(char input){
    if (!rear)
        return 0;
    return rear->getAttack(input);
}

int CllNode::getAttack(char input){//which character attack we want to use
    for (int i=0; i<3; ++i){
    if (input==array[i]->getName()){//go through array and find match to make attack;
        return array[i]->attack();
        }
    }
}
int CllNode::hitHealth(int attack, char toHit){
    char winner;
    char loser;
    for (int i=0; i<3; ++i){
    if (toHit==array[i]->getName()){//go through array and find match to make attack;
       int x= array[i]->hitHealth(attack);
        if (x=0){//loser 
            loser=array[i]->getName();
        insertLoser(loser);
        }
        else{
        winner=array[i]->getName();
        insertWinner(winner);
        }
        }
    }
}

int CllNode:: insertLoser(char loser){
    int indexLoser=0;
    object.insert(indexLoser,loser);
}

int CllNode::insertWinner(char winner){//THIS INSERTS A WINNER AND LOSER
    int indexWinner=1;
   object.insert(indexWinner,winner);
}

ManageCll::ManageCll():rear(NULL){
    int number=0;
    ifstream file_in;
    file_in.open("data.txt");
        if (file_in){
            while (!file_in.eof()){
                file_in>>number;
                file_in.ignore(100, ':');
                insert(number);
            }
        }
        file_in.close();
};

ManageCll::ManageCll(ManageCll & src){
    if (!rear)
        rear=NULL;
    rear= new CllNode(*(src.rear));
    CllNode *temp= NULL;
    copy(temp, src.rear->getNext(), src.rear);
    rear->setNext(temp);
    
}

int ManageCll::copy(CllNode *&dest, CllNode *src, CllNode * srcRear){
    if (!src||srcRear)
        return 1;
    if (src==srcRear)
        dest=rear;
        return 1;
    dest= new CllNode(*src);
    CllNode * temp;
    temp=NULL;
    copy(temp, src->getNext(), srcRear);
    dest->setNext(temp);
}

ManageCll::~ManageCll(){
    removeAll();
}
int ManageCll::removeAll(){
    if (!rear)
        return 0;
    removeAll(rear->getNext());
    rear=NULL;
}
int ManageCll::removeAll(CllNode *&curr){
    if (curr==rear){
        return 1;
    }
    removeAll(curr->getNext());
    delete curr;
} 
int ManageCll::displayHealth(){
    if (!rear)
        return 0;
    displayHealth(rear);
}
int ManageCll::displayHealth(CllNode *current){
    current->getHealth();
    if(current->getNext()!=rear)
        display(current->getNext());

}
int CllNode::getHealth(){//DISPLAYS NODE'S character's health;
    if (!array)
        return 0;
    for (int i=0; i<3; ++i){
        if (array[i])
            cout<<array[i]->getName()<<endl;
            cout<<array[i]->showHealth()<<endl;
    } 
}

int CllNode::insert(Body*ptr){
    if (ptr==NULL){//invalid input
        return 0;
    }
    if (i<3){
        array[i]=ptr;
        ++i;
        return 1;//success
    }
    else
        return 2;//array is full;
}
int ManageCll::hitHealth(int attack, char toHit){
    if (rear)
        return rear->hitHealth(attack,toHit);
    return 0;
}

int ManageCll::insert(int response){
    Body*ptr;
    if (response==1){
        ptr=new Fairy;
    }
    else if (response==2){
        ptr=new Prince;
    }
    else{
        ptr=new Dragon;
    }
    if (!rear){
        rear= new CllNode;
        rear->setNext(rear);
        rear->insert(ptr);
    } 
    else if (rear->insert(ptr)==2){//create new node;
        CllNode *temp= new CllNode;
        temp->setNext(rear->getNext());
        rear->setNext(temp);
        temp->insert(ptr);
    }
}

CllNode*&CllNode::getNext(){
    return next;
}

void CllNode::setNext(CllNode * srcNext){
    this->next=srcNext;
}
