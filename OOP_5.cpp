#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;





class Hero 
{
	
	};


class Spell 
{
	public:float damage,power,freeCell;
	       int level;
	       string nameSpell;
	Spell(float damage,int level,string nameSpell,float power=0,float freeCell=0)
	{
	this->damage=damage;
	this->level=level;
	this->power=power;
	this->freeCell=freeCell;
	this->nameSpell=nameSpell;
	}
	
	~Spell(){}
	virtual void wOut(){};
	
	void Search();
};
void Spell::Search()
{
	
	string file;
	ifstream input("Spells.txt",ios::in);
	while (input) getline (input,file,'\0');
	if (!(file.find(nameSpell)+1)) {
		ofstream output("Spells.txt",ios::app);
		output<<nameSpell<<" "<<damage<<" "<<level<<" "<<power<<" "<<freeCell<<" ";
		output.close();
		cout<<"Spells was added \n";}
	else {string oldSpell;
		  int beginPosition,endPosition;
		  beginPosition=file.find(nameSpell);
		  endPosition=file.find(nameSpell)+nameSpell.size()+1;
		  endPosition=file.find(' ',endPosition)+1;
		  endPosition=file.find(' ',endPosition)+1;
		  endPosition=file.find(' ',endPosition)+1;
		  endPosition=file.find(' ',endPosition);
		  oldSpell=file.substr(beginPosition,endPosition-beginPosition);
		  cout<<"Find Spell \n "<<oldSpell<<endl;
		  }
	}

class basicSpell:public Spell
{
	};
	
class middleSpell:public Spell
{
	};

class powerSpell:public Spell
{
	};
	
class Kick 
{
	public:float damages,stamina,object,skill;
	string nameKick;
	Kick(float damages,float stamina,string nameKick,float object=0,float skill=0)
	{
	this->damages=damages;
	this->stamina=stamina;
	this->object=object;
	this->skill=skill;
	this->nameKick=nameKick;
	}
	~Kick(){}

    virtual void Out(){};
    void Searchs();
};

void Kick::Searchs()
{
	
	string file;
	ifstream input("Kicks.txt",ios::in);
	while (input) getline (input,file,'\0');
	if (!(file.find(nameKick)+1)) {
		ofstream output("Kicks.txt",ios::app);
		output<<nameKick<<" "<<damages<<" "<<stamina<<" "<<object<<" "<<skill<<" ";
		output.close();
		cout<<"Kicks was added \n";}
	else {string oldSpell;
		  int beginPosition,endPosition;
		  beginPosition=file.find(nameKick);
		  endPosition=file.find(nameKick)+nameKick.size()+1;
		  endPosition=file.find(' ',endPosition)+1;
		  endPosition=file.find(' ',endPosition)+1;
		  endPosition=file.find(' ',endPosition)+1;
		  endPosition=file.find(' ',endPosition);
		  oldSpell=file.substr(beginPosition,endPosition-beginPosition);
		  cout<<"Find Kicks \n "<<oldSpell<<endl;
		  }
	}
class basicKick:public Kick
{
	};

class MiddleKick:public Kick
{
	};

class powerKick:public Kick
{
	};	




class Mage:public Kick,Spell,Hero

{public:
	Mage(float damage,float damages,float stamina,string nameKik,float power,float object,int level,float skill,string nameSpell,float freeCell):Kick(damages,stamina,nameKik,object,skill),Spell(damage,level,nameSpell,power,freeCell){};
void Out(){cout<<"Kick is used"<<endl;}
void wOut(){cout<<"Your spell have 73 damage for enemy"<<endl;}
void Mad(){cout<<"Spell is used"<<endl<<endl;}
};

class Warior:public Kick,public Spell,public Hero
{public:
	Warior(float damage,float damages,float stamina,string nameKik,float powers,float object,int level,float skill,string nameSpell,float freeCell):Kick(damages,stamina,nameKik,object,skill),Spell(damage,level,nameSpell,power,freeCell){};

void Out(){cout<<"Iam Hill"<<endl;}
void wOut(){cout<<"Your spells level = 3 "<<endl;}
void Med(){cout<<"Spell is used"<<endl<<endl;}
};

class Warlock:public Kick,public Spell,public Hero
{public:
	Warlock(float damage,float damages,float stamina,string nameKik,float powers,float object,int level,float skill,string nameSpell,float freeCell):Kick(damages,stamina,nameKik,object,skill),Spell(damage,level,nameSpell,power,freeCell){};
void Out () {cout<<"Mind hunting"<<endl;}
void wOut() {cout<<"Your spell has name ICE WALL"<<endl;}
void Met () {cout<<"Spell is used"<<endl<<endl;}
};

class Theif:public Kick,public Spell,public Hero
{public:
	Theif(float damage,float damages,float stamina,string nameKik,float powers,float object,int level,float skill,string nameSpell,float freeCell):Kick(damages,stamina,nameKik,object,skill),Spell(damage,level,nameSpell,power,freeCell){};
void Out () {cout<<"Mind hunting"<<endl;}
void wOut() {cout<<"Your spell has name ICE WALL"<<endl;}
void Met () {cout<<"Spell is used"<<endl<<endl;}
};


int main()
{
Mage m1(1,2,3,"pis",4,5,6,7,"sos",8);
m1.Out();
m1.wOut();
m1.Mad();

Spell s1(10,1,"Rogue");
s1.Search();

Kick k1(5,0,"Kiborg");
k1.Searchs();


Warior h1(1,2,3,"pis",4,5,6,7,"sos",8);
h1.Out();
h1.wOut();
h1.Med();

Warlock hh1(1,2,3,"pis",4,5,6,7,"sos",8);
hh1.Out();
hh1.wOut();
hh1.Met();	
	return 0;
}
