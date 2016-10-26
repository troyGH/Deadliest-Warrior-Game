// Defines base warrior class and specific warriors' derived classes
#ifndef warrior_h
#define warrior_h
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

/****************************************************************************/
// Warrior is an abstract base class. Must fill in the virtual functions in 
// your class for choice of fighter, as well as a constructor.
/****************************************************************************/
class Warrior
{
protected:
    int atk, def, agil, hp, damage;
    
public:
    Warrior();      // default constructor
    Warrior(int atk, int def, int agil, int hp, int damage = 0);    // copy constructor with initializer list
    Warrior(const Warrior &player); 
    void setHP(int hp){this->hp = hp;};
    void setAtk(int atk){this->atk = atk;};
    void setDef(int def){this->def = def;};
    void setAgil(int agil){this->agil = agil;};
    void setDamage(const Warrior &player);
    int getHP() const {return hp;};
    int getAtk() const {return atk;};
    int getDef() const {return def;};
    int getAgil() const {return agil;};
    int getDamage() const {return damage;};
    virtual void displayMoves() const = 0;
    virtual string getName() const = 0;
    virtual ~Warrior(){} // virtual destructor needed because of using virtual functions
    virtual void setAttributes(int choice) = 0;
};

/*************************/
// default constructor: defaults all private member variables to zero.
/*************************/
Warrior::Warrior()
{
    hp = atk = def = agil = damage = 0;
}

/*************************/
// constructor with initializer list
/*************************/
Warrior::Warrior(int atk, int def, int agil, int hp, int damage)
{
    this->atk = atk;
    this->def = def;
    this->agil = agil;
    this->hp = hp;
    this->damage = damage;
}

/********************/
// copy constructor
/********************/
Warrior::Warrior(const Warrior &player)
{
    atk = player.atk;
    def = player.def;
    agil = player.agil;
    hp = player.hp;
    damage = player.damage;
}

/*************************/
// setDamage: parameter is another class in order to calculate damage taken
//algorithm is : player2 damage = (player1 attack - Player2 agility) - (Player2 defense / player1 attack)
// this function automatically deducts the damage from the warrior's health(HP)
/*************************/
void Warrior::setDamage(const Warrior &player)
{
    damage = (player.getAtk() - agil) - (def / player.getAtk());
    if(damage < 0)
        damage = 0;
    setHP(getHP() - damage);
}
/************** end of Warrior abstract base class *******************************/


/********************************************************************/
// Fighter: Tai Chi Master
/********************************************************************/

class TaiChiMaster: public Warrior
{
private:
    string name;
public:
    TaiChiMaster() : Warrior(150, 150, 150, rand()%200 + 2000){name = "Tai Chi Master";} // parameters for warrior constructor are atk, def, agility, and hp 
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};

/*******************/
// displayMoves will display the moves for
// this particular character
/*******************/
void TaiChiMaster::displayMoves() const
{
    cout << "1 - Lightning Kicks\n2 - Swift Punch\n3 - Dodge\n";
}

/******************/
// setAttributes will randomize the values
// according to move selection(int value parameter)
/******************/
void TaiChiMaster::setAttributes(int choice)
{
    srand((unsigned)time(0));
    switch (choice) {
        case 1:
            setAtk(150 - rand()%41);            //Player1 attack set to a random number between 110 and 150
            setDef(150 - rand()%121);           //Player1 defense set to a random number between 30 and 150
            setAgil(150 - rand()%121);          //Player1 agility set to a random number between 30 and 150
            break;
        case 2:
            setAtk(150 - rand()%71);            //Player1 attack set to a random number between 80 and 150
            setDef(150 - rand()%91);            //Player1 defense set to a random number between 60 and 150
            setAgil(150 - rand()%91);           //Player1 agility set to a random number beteen 60 and 150
            break;
        case 3:
            setAtk(150 - rand()%101);           //Player1 attack set to a random number between 50 and 150
            setDef(150 - rand()%71);            //Player1 defense set to a random number between 80 and 150
            setAgil(150 - rand()%71);           //Player1 agility set to a random number between 80 and 150
            break;
    }
    
}
/************************ end of Tai Chi Master class ******************************/


/*********************************************/
// Fighter: Drunken Irishman
/*********************************************/
class DrunkIrish: public Warrior
{
private:
    string name;
    
public:
    DrunkIrish() : Warrior(310,90,50,rand()%200 + 1500) {name = "Drunk Irishman";}
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};


void DrunkIrish::displayMoves() const
{
    cout << "1 - Bottle Throw\n2 - Headbutt\n3 - Sway Back and Forth\n";
}


void DrunkIrish::setAttributes(int choice)
{
    srand((unsigned)time(0));
    switch (choice) {
        case 1:
            setAtk(310 - rand()%84);  //Player1 attack set to a random number between 227 and 310
            setDef(90 - rand()%73);  //Player1 defense set to a random number between 18 and 90
            setAgil(50 - rand()%41);      //Player1 agility set to a random number between 10 and 50
            break;
        case 2:
            setAtk(310 - rand()%146);             //Player1 attack set to a random number between 166 and 310
            setDef(90 - rand()%55);              //Player1 defense set to a random number between 36 and 90
            setAgil(50 - rand()%31);              //Player1 agility set to a random number beteen 20 and 50
            break;
        case 3:
            setAtk(310 - rand()%208);  //Player1 attack set to a random number between 103 and 310
            setDef(90 - rand()%43);              //Player1 defense set to a random number between 48 and 90
            setAgil(50 - rand()%24);                      //Player1 agility set to a random number between 27 and 50
            break;
    }
    
}
/************* end of drunken irishman class ******************/


/*************************/
//Fighter: Floyd Mayweather
/*************************/

/*************************/
//Fighter: Floyd Mayweather
/*************************/
class FloydMayweather: public Warrior
{
private:
    string name;
    
public:
    FloydMayweather() : Warrior(100,150,200,rand()%200 + 1800) {name = "Floyd Mayweather";}
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};


void FloydMayweather::displayMoves() const
{
    cout << "1 - Left Hook\n2 - Straight Right\n3 - Dodge and Taunt\n";
}


void FloydMayweather::setAttributes(int choice)
{
    switch (choice) {
        case 1:
            setAtk(100 - rand()%28);  //Player1 attack set to a random number between 14 and 20
            setDef(150 - rand()%121);  //Player1 defense set to a random number between 0 and 10
            setAgil(200 - rand()%161);      //Player1 agility set to a random number between 0 and 5
            break;
        case 2:
            setAtk(100 - rand()%48);             //Player1 attack set to a random number between 8 and 20
            setDef(250 - rand()%91);              //Player1 defense set to a random number between 5 and 10
            setAgil(200 - rand()%121);             //Player1 agility set to a random number beteen 3 and 5
            break;
        case 3:
            setAtk(100 - rand()%68);  //Player1 attack set to a random number between 10 and 20
            setDef(250 - rand()%71);              //Player1 defense set to a random number between 7 and 10
            setAgil(200 - rand()%94);                     //Player1 agility set to a random number between 4 and 5
            break;
    }   
}
/************* end of Floyd Mayweather class ******************/

/*************************/
//Fighter: Chuck Norris
/*************************/
class ChuckNorris: public Warrior
{
private:
    string name;
public:
    ChuckNorris() : Warrior(200, 200, 50, rand()%200 +1600) {name = "Chuck Norris";} 
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};

void ChuckNorris::displayMoves() const
{cout << "1 - Chuck Norris Round house Kick \n 2 - Chuck Norris Block \n 3 - Dodge\n";}


void ChuckNorris::setAttributes(int choice)
{
    switch (choice) {
        case 1:
            setAtk(200 - rand()%54);  //Player1 attack set to a random number between 7 and 10
            setDef(200 - rand()%161);  //Player1 defense set to a random number between 5 and 15
            setAgil(50 - rand()%41);      //Player1 agility set to a random number between 0 and 25
            break;
        case 2:
            setAtk(200 - rand()%94);              //Player1 attack set to a random number between 4 and 10
            setDef(200 - rand()%121);              //Player1 defense set to a random number between 9 and 15
            setAgil(50 - rand()%31);             //Player1 agility set to a random number beteen 11 to 25
            break;
        case 3:
            setAtk(200 - rand()%134);  //Player1 attack set to a random number between 1 and 10
            setDef(200 - rand()%94);              //Player1 defense set to a random number between 10 and 15
            setAgil(50 - rand()%24);                      //Player1 agility set to a random number between 20 and 25
        break;}

}
/************* end of Chuck Norris class ******************/


//Pirate Class
class Pirate: public Warrior
{
private:
    string name;
public:
    Pirate() : Warrior(190, 170, 90, rand()%200 + 1700){name = "Pirate";}
    // parameters for warrior constructor are atk, def, agility, and hp
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};
void Pirate::displayMoves() const
{
    cout << "1 - Stab with Peg Leg\n2 - Power swing with Cutlas\n3 - Distract Enemy with Parrot\n";
}
void Pirate::setAttributes(int choice)
{
    switch (choice) {
        case 1:
            setAtk(190 - rand()%52);
            setDef(170 - rand()%137);
            setAgil(90 - rand()%73);
            break;
        case 2:
            setAtk(190 - rand()%90);
            setDef(170 - rand()%103);
            setAgil(90 - rand()%55);
            break;
        case 3:
            setAtk(190 - rand()%128);
            setDef(170 - rand()%80);
            setAgil(90 - rand()%43);
            break;
    }
}
//End pirate class

//Start Spartan Class
class Spartan: public Warrior
{
private:
    string name;
    
public:
    Spartan() : Warrior(200,180,70,rand()%200 + 1600) {name = "Spartan";}
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};


void Spartan::displayMoves() const
{
    cout << "1 - Javelin Throw\n2 - Gladius Stab\n3 - Shield Wall\n";
}


void Spartan::setAttributes(int choice)
{
    switch (choice) {
        case 1:
            setAtk(200 - rand()%54);
            setDef(180 - rand()%145);
            setAgil(70 - rand()%57);
            break;
        case 2:
            setAtk(200 - rand()%94);
            setDef(180 - rand()%109);
            setAgil(70 - rand()%43);
            break;
        case 3:
            setAtk(200 - rand()%134);
            setDef(180 - rand()%85);
            setAgil(70 - rand()%34);
            break;
    }
}


/********************************************************************/
// Fighter: Ninja
/********************************************************************/

class Ninja: public Warrior
{
private:
    string name;
public:
    Ninja() : Warrior(150, 100, 200, rand()%200 + 1400){name = "Ninja";} // parameters for warrior constructor are atk, def, agility, and hp 
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};

/*******************/
// displayMoves will display the moves for
// this particular character
/*******************/
void Ninja::displayMoves() const
{
    cout << "1 - Shruiken!(Throwing Stars)\n2 - MultiBlades Slash\n3 - Shadow Clones\n";
}

/******************/
// setAttributes will randomize the values
// according to move selection(int value parameter)
/******************/
void Ninja::setAttributes(int choice)
{
    switch (choice) {
        case 1:
            setAtk(150 - rand()%41);  //Player1 attack set to a random number between 7 and 10
            setDef(100 - rand()%81);  //Player1 defense set to a random number between 5 and 15
            setAgil(200 - rand()%161);      //Player1 agility set to a random number between 0 and 25
            break;
        case 2:
            setAtk(150 - rand()%71);              //Player1 attack set to a random number between 4 and 10
            setDef(100 - rand()%61);              //Player1 defense set to a random number between 9 and 15
            setAgil(200 - rand()%121);            //Player1 agility set to a random number beteen 11 to 25
            break;
        case 3:
            setAtk(150 - rand()%101);  //Player1 attack set to a random number between 1 and 10
            setDef(100 - rand()%48);              //Player1 defense set to a random number between 10 and 15
            setAgil(200 - rand()%94);                     //Player1 agility set to a random number between 20 and 25
            break;
    }
    
}
/************************ end of Ninja class ******************************/


/********************************************************************/
// Fighter: Samurai
/********************************************************************/

class Samurai: public Warrior
{
private:
    string name;
public:
    Samurai() : Warrior(180, 180, 90, rand()%200 + 1500){name = "Samurai";} // parameters for warrior constructor are atk, def, agility, and hp 
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};

/*******************/
// displayMoves will display the moves for
// this particular character
/*******************/
void Samurai::displayMoves() const
{
    cout << "1 - Double Thrust\n2 - Final Strike\n3 - Skin of Steel\n";
}

/******************/
// setAttributes will randomize the values
// according to move selection(int value parameter)
/******************/
void Samurai::setAttributes(int choice)
{
    switch (choice) {
        case 1:
            setAtk(180 - rand()%49);  //Player1 attack set to a random number between 7 and 10
            setDef(180 - rand()%145);  //Player1 defense set to a random number between 5 and 15
            setAgil(90 - rand()%73);      //Player1 agility set to a random number between 0 and 25
            break;
        case 2:
            setAtk(180 - rand()%85);              //Player1 attack set to a random number between 4 and 10
            setDef(180 - rand()%109);              //Player1 defense set to a random number between 9 and 15
            setAgil(90 - rand()%55);            //Player1 agility set to a random number beteen 11 to 25
            break;
        case 3:
            setAtk(180 - rand()%121);  //Player1 attack set to a random number between 1 and 10
            setDef(180 - rand()%85);              //Player1 defense set to a random number between 10 and 15
            setAgil(90 - rand()%43);                     //Player1 agility set to a random number between 20 and 25
            break;
    }
    
}
/************************ end of Samurai class ******************************/

/********************************************************************/
// Fighter: Cyclopes
/********************************************************************/

class Cyclopes: public Warrior
{
private:
    string name;
public:
    Cyclopes() : Warrior(250, 180, 20, rand()%401 + 2300){name = "Cyclopes";} // parameters for warrior constructor are atk, def, agility, and hp 
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};

/*******************/
// displayMoves will display the moves for
// this particular character
/*******************/
void Cyclopes::displayMoves() const
{
    cout << "1 - Giant Stomp\n2 - Swing Club\n3 - Throw Boulder\n";
}

/******************/
// setAttributes will randomize the values
// according to move selection(int value parameter)
/******************/
void Cyclopes::setAttributes(int choice)
{
    switch (choice) {
        case 1:
            setAtk(250 - rand()%68);  
            setDef(180 - rand()%145);  
            setAgil(20 - rand()%17);      
            break;
        case 2:
            setAtk(250 - rand()%118);          
            setDef(180 - rand()%109);            
            setAgil(20 - rand()%13);        
            break;
        case 3:
            setAtk(250 - rand()%168); 
            setDef(180 - rand()%85);
            setAgil(20 - rand()%10);
            break;
    }
    
}
/************************ end of Cyclopes class ******************************/

/********************************************************************/
// Fighter: Knight
/********************************************************************/

class Knight: public Warrior
{
private:
    string name;
public:
    Knight() : Warrior(200, 170, 80, rand()%200 + 1900){name = "Knight";} // parameters for warrior constructor are atk, def, agility, and hp 
    virtual void displayMoves() const;
    virtual string getName() const {return name;}
    virtual void setAttributes(int choice);
};

/*******************/
// displayMoves will display the moves for
// this particular character
/*******************/
void Knight::displayMoves() const
{
    cout << "1 - Kick\n2 - Sword Thrust\n3 - Sword Block\n";
}

/******************/
// setAttributes will randomize the values
// according to move selection(int value parameter)
/******************/
void Knight::setAttributes(int choice)
{
    switch (choice) {
        case 1:
            setAtk(200 - rand()%54);  
            setDef(170 - rand()%137);  
            setAgil(80 - rand()%65);      
            break;
        case 2:
            setAtk(200 - rand()%94);          
            setDef(170 - rand()%103);            
            setAgil(80 - rand()%49);        
            break;
        case 3:
            setAtk(200 - rand()%134); 
            setDef(170 - rand()%80);
            setAgil(80 - rand()%38);
            break;
    }
    
}
/************************ end of Knight class ******************************/

#endif
