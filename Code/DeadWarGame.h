// header file containing the functions and algorithms for the game and interface

#ifndef DeadWarGame_h
#define DeadWarGame_h
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "warrior.h"
#include "DispInterface.h"
using namespace std;


/****************************/
// this is the interface and 
// algorithm of the game
/****************************/
class DeadliestWar
{
private:
    Warrior * warrior1;
    Warrior * warrior2;
public:
    DeadliestWar();
    void menu();
    void CharSelect();
    void play();
    bool validMenuChoice(int a);
    bool validChar(int b);
    void clrscn();
    void displayHP(string war, int hp, int r_hp);
    ~DeadliestWar();
};

/**********************/
// Default Constructor
// Initializes both pointers to TaiChiMaster
/**********************/
DeadliestWar::DeadliestWar()
{
    warrior1 = new TaiChiMaster;
    if(warrior1 == NULL)
    {
        cout << "Allocating memory failed . . .";
        exit(EXIT_FAILURE);
    }
    warrior2 = new TaiChiMaster;
    if(warrior2 == NULL)
    {
        cout << "Allocating memory failed . . .";
        delete warrior1;
        exit(EXIT_FAILURE);
    }
}

/****************************/
// menu interface
/****************************/
void DeadliestWar::menu()
{
    int m_choice;
    bool valid = false;
    
    do{
        cout << MenuHeading;
        cin >> m_choice;
        
        valid = validMenuChoice(m_choice);
        
        if(valid == true && m_choice == 1)
        {
            clrscn();
            CharSelect();
            clrscn();
            play();
        }
        
    }while (m_choice != 2);// do end while loop
    cout << "End of Spike's Deadliest Warrior\n\n"; 
}


/**********************/
// CharSelect will get user input on which warrior
// and creates it for warrior1 or warrior2
// depending on the int parameter passed
/**********************/
void DeadliestWar::CharSelect()
{
    int choice_1;
    bool valid = false;
    cout << "*****************************************" << endl;
    cout << "Character Select" << endl;
    cout << "*****************************************" << endl;
    cout << endl << CharList << endl;
    
    do
    {
        cout << "Warrior 1: ";
        cin.ignore();
        cin >> choice_1;
        valid = validChar(choice_1);
        
        if(valid == true)
        {
            delete warrior1;
            
            switch (choice_1)
            {
                case 1:
                    warrior1 = new TaiChiMaster;
                    break;
                    
                case 2:
                    warrior1 = new DrunkIrish; 
                    break;
                    
                case 3:
                    warrior1 = new FloydMayweather;
                    break;
                    
                case 4:
                    warrior1 = new ChuckNorris; 
                    break;
                    
                case 5:
                    warrior1 = new Pirate;
                    break;
                    
                case 6:
                    warrior1 = new Spartan; 
                    break;
                    
                case 7:
                    warrior1 = new Ninja;
                    break;
                    
                case 8:
                    warrior1 = new Samurai; 
                    break;
                    
                case 9:
                    warrior1 = new Cyclopes;
                    break;
                    
                case 10:
                    warrior1 = new Knight;
                    break;
                default:
                    cout << "Select your WARRIOR wisely.";
            }
            
            if(warrior1 == NULL)
            {
                cout << "Allocating memory failed . . .";
                delete warrior2;
                exit(EXIT_FAILURE);
            }
        }
    }while(valid == false);
    
    valid = false;
    
    do
    {
        cout << "Warrior 2: ";
        cin >> choice_1;
        valid = validChar(choice_1);
        
        if(valid == true)
        {
            delete warrior2;
            
            switch (choice_1)
            {
                case 1:
                    warrior2 = new TaiChiMaster;
                    break;
                    
                case 2:
                    warrior2 = new DrunkIrish; 
                    break;
                    
                case 3:
                    warrior2 = new FloydMayweather;
                    break;
                    
                case 4:
                    warrior2 = new ChuckNorris; 
                    break;
                    
                case 5:
                    warrior2 = new Pirate;
                    break;
                    
                case 6:
                    warrior2 = new Spartan; 
                    break;
                    
                case 7:
                    warrior2 = new Ninja;
                    break;
                    
                case 8:
                    warrior2 = new Samurai; 
                    break;
                
                case 9:
                    warrior2 = new Cyclopes;
                    break;
                    
                case 10:
                    warrior2 = new Knight;
                    break;
                    
                default:
                    cout << "Select your WARRIOR wisely.";
            }
            
            if(warrior2 == NULL)
            {
                cout << "Allocating memory failed . . .";
                delete warrior1;
                exit(EXIT_FAILURE);
            }
        }
    }while(valid == false);
    
}

/********************/
//Function makes sure users picks the right menu number
/********************/
bool DeadliestWar::validMenuChoice(int a)
{
    if(a < 1 || a > 2)
    {
        cout << endl << "ERROR -> Select your numbers correctly." << endl;
        return false;
    }
    else
        return true;
}

/********************/
//Function makes sure users pick the right warrior
/********************/
bool DeadliestWar::validChar(int b)
{
    if(b < 1 || b > 10)
    {
        cout << endl << "Select your warrior wisely." << endl;
        return false;
    }
    else
        return true;
}



/*************************/
// play function will run the battle sequence
/*************************/
void DeadliestWar::play()
{
    int choice;
    int i =0, init;
	int hp1=warrior1->getHP(), hp2=warrior2->getHP(); //hp1 = warrior1's starting hp, hp2 = warrior2's starting hp
    
    srand((unsigned)time(0));  //seeds the random number generator, prevents same values
    //each time the program is run.
    
    cout <<"Welcome to our fight simulator!\n\n";       // this will probably end up in some menu class
	displayHP(warrior1->getName(), hp1, warrior1->getHP());
	displayHP(warrior2->getName(), hp2, warrior2->getHP());
    
    while (warrior1->getHP() > 0 || warrior2->getHP() > 0)  //Checks to see if both combatants are still alive
    {
        
        i++; 
        cout <<"Round "<<i<<"!\n\n";
        
        init = rand()%2+1;  //random number between 1 and 2.
        if (init == 1) 
            
        { // chooses who goes first, i.e. if the random init number was 1, then player 1 goes first.
            
            cout <<warrior1->getName()<<" goes first\n";
            cout<<"What do you want to do?\n";
            warrior1->displayMoves();
            
            do{cin>>choice;}while(choice>3 || choice<1); //Hardcoded check on whether the user entered a valid chioce
            
            warrior1->setAttributes(choice);
            warrior1->setDamage(*warrior2);
            
            cout << endl;
            cout<<warrior2->getName()<<", what do you want to do?\n";
            warrior2->displayMoves();
            
            do{cin>>choice;}while(choice>3 || choice<1); //Hardcoded check on whether the user entered a valid chioce
            
            warrior2->setAttributes(choice);
            warrior2->setDamage(*warrior1);  
            
            clrscn();
            
            cout<<warrior2->getName()<<" did "<<warrior1->getDamage()<<" damage to "<<warrior1->getName()<<".\n";
            displayHP(warrior1->getName(), hp1, warrior1->getHP());
            cout<<warrior1->getName()<<" did "<<warrior2->getDamage()<<" damage to "<< warrior2->getName() << endl;
            displayHP(warrior2->getName(), hp2, warrior2->getHP());
            cin.get(); // ????????
            
            if (warrior2->getHP() <= 0) {
                clrscn();
                displayHP(warrior1->getName(), hp1, warrior1->getHP());
                displayHP(warrior2->getName(), hp2, warrior2->getHP());
                cout<<warrior1->getName()<<" killed "<<warrior2->getName()<<". "<<warrior1->getName()<< " won with "<<warrior1->getHP()<<" hp left.\n";
                cout << endl << "Press enter to return to menu ";
                cin.get();
                clrscn();
                return;
            }
            
            if (warrior1->getHP() <= 0) {
                clrscn();
                displayHP(warrior1->getName(), hp1, warrior1->getHP());
                displayHP(warrior2->getName(), hp2, warrior2->getHP());
                cout<<warrior2->getName()<<" killed "<<warrior1->getName()<<". "<<warrior2->getName()<<" still has "<<warrior2->getHP()<<" hp left.\n";
                cin.get();
                clrscn();
                return;
            }
            
            
            
        }
        
        
        
        else {
            cout<<warrior2->getName()<<" goes first\n\n";
            
            
            cout<<warrior2->getName()<<", what do you want to do?\n";
            warrior2->displayMoves();
            
            do{cin>>choice;}while(choice>3 || choice<1); //Hardcoded check on whether the user entered a valid chioce
            
            warrior2->setAttributes(choice);
            warrior2->setDamage(*warrior1);
            
            cout <<warrior1->getName()<<", what do you want to do?\n";
            warrior1->displayMoves();
            do{cin>>choice;}while(choice>3 || choice<1);
            
            warrior1->setAttributes(choice);
            warrior1->setDamage(*warrior2);  
            
            clrscn(); 
            
            cout<<warrior2->getName()<<" hit "<<warrior1->getName()<<" for "<<warrior1->getDamage()<<" damage.\n";
            displayHP(warrior1->getName(), hp1, warrior1->getHP());
            cout<<warrior1->getName()<<" hit "<<warrior2->getName()<<" for "<<warrior2->getDamage()<<" damage. \n";
            displayHP(warrior2->getName(), hp2, warrior2->getHP());
            
            cin.get();
            
            if (warrior1->getHP() <= 0) {
                clrscn();
                displayHP(warrior1->getName(), hp1, warrior1->getHP());
                displayHP(warrior2->getName(), hp2, warrior2->getHP());
                cout<<warrior1->getName()<<" died. "<<warrior2->getName()<< " still has "<<warrior2->getHP()<<" hp left.\n";
                cin.get();
                clrscn();
                return;
            }
            
            if (warrior2->getHP() <= 0) {
                clrscn();
                displayHP(warrior1->getName(), hp1, warrior1->getHP());
                displayHP(warrior2->getName(), hp2, warrior2->getHP());
                cout<<warrior1->getName()<<" killed "<<warrior2->getName()<<". "<<warrior1->getName()<<" won with "<<warrior1->getHP()<<" hp left.\n";
                cin.get();
                clrscn();
                return;
            }
            
        } 
        
    }
    
} // end of play function

/****************************/
// clears console screen
/****************************/
void DeadliestWar::clrscn()
{
    cout << string(50, '\n');
}

/****************************/
// graphic display of health(health bar)
/****************************/
void DeadliestWar::displayHP(string war, int hp, int r_hp) //gets warriors name, starting hp, and remaining hp
{
	float p = ((static_cast<double>(r_hp)/static_cast<double>(hp))*100)/2; //algorithm to get the number of * to display
    
	int j = 50 - war.length();
	cout << "\n\t";
	for(int i = 0; i < j/2; i++)
		cout << "-";
    
	cout << war;
    
	for(int i = 0; i < j/2; i++)
		cout << "-";		//displays and center ********Warrior's Name********
    
	cout << "\n\t" << "HP = " << r_hp << "/" << hp << "\t\t\t\t" << "HP% = " << static_cast<int>(p*2) << "%" << endl;	//displays the starting hp, remaining hp, and hp %
    
	cout << "\t";
	for(int i = 0; i < 50; i++) //displays the outline of the hp bar
		cout << "=";
    
	cout << "\n\t";
	for(int i = 0; i < p; i++) //displays the percentage left in the hp bar in "*" char
		cout << "*";
    
	cout << "\n\t";
	for(int i = 0; i < 50; i++) //displays the outline of the hp bar
		cout << "=";
    
	cout << "\n\n\n";
}


/***************************/
// Destructor
/***************************/
DeadliestWar::~DeadliestWar()
{
    if(warrior1 != NULL)
        delete warrior1;
    if(warrior2 != NULL)
        delete warrior2;
}

/********** end of DeadliestWar class ********************/

#endif
