// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Monster.h"
#include <string>

class Player
{
public:
	// Constructor.
	Player();

	// Methods
	bool isDead();

	int  getArmor();

	void takeDamage(int damage);

	void createClass();
	bool attack(Monster& monster);
	void levelUp();
	void rest();
	void viewStats();
	void victory(int xp,int gold);
	void gameover();
	void displayHitPoints();
	//int	 gold_display();
	// ^^^^^^^^^^^^^^^
 
private:
	// Data members.
	std::string mName;
	std::string mClassName;
	int         mAccuracy;
	int         mHitPoints;
	int         mMaxHitPoints;
	int         mExpPoints;
	int         mNextLevelExp;
	int         mLevel;
	int         mArmor;
	Weapon      mWeapon;
	int			mGold;
	//^^^^^^^^^^
};

#endif //PLAYER_H