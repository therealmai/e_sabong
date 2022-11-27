#include <stdio.h>
#define size 3
#include<string.h>
//#include <conio2.h>
#include "extraFile.c"
#include <time.h>
#include <math.h>

//   typedef struct{
//   	char itemName[16];
//   	char description[30];
//   	int effect;
//   	float cost;
//   }shop;
   
    typedef struct{
    	char bagName[50];
    	char description[50];
    	float powerUp;
		int count;
	}infoBag;
	
    typedef struct{
    	infoBag items[2];
	}bag;
	
    typedef struct{
        int HP;
        int damage;
        float money;
		bag backpack;
		char name[30];
    }hero;
    
    typedef struct{
    	hero player[size];
	}character;
	
    void titleScreen();
    void storyTime();
    void getValue(character* enemy);
  	void displayCharacter(hero player);
    void chooseBuff(hero* player);
    void buyShop(hero* player);
    void startFight(hero* player, int y, character* enemy, int*life);
    int attack(hero*player, character*enemy, int round);
    int checkWinner(char you, char computer);
    void insertItems(int catcher,hero* player);
    void displayBag(hero* player);
    void useItems(hero* player, int y);
    int useFlag =0,bossFlag=0;
    
    void main(){
    	int game = 1;
    	while(game != 0){
	    int num,x,y=0;
	    char catcher;
	    int life = 1;
	    titleScreen();
	    storyTime();
	    hero player = {100,40,100.00, "Metal Claw", "Damage Amplified (+20%% Damage)", 1.2, 0, "Electrolyte Drink", "Healing Potion", 50, 0};
	    character enemy;
	    getValue(&enemy);
	    printf("Enter the name of your rooster: ");
	    scanf("%s",player.name);
	    clrscr();
	    displayCharacter(player);
	    chooseBuff(&player);
	    while(life > 0){
	    	startFight(&player,y,&enemy,&life);
	    	y++;
	    	clrscr();
	    	if(life > 0 && y != size){
	    	buyShop(&player);
			}else if(life == 0){
				break;
				bossFlag = 0;
			}else{
				bossFlag=1;
				break;
			}
	    	
		}
		if(bossFlag == 1){
			displayVictory();
			getch();
			clrscr();
//			endStory();
		}
		displayGameOver();
		getch();
		clrscr();
		gotoxy(47,10);
    	printf("Do you want to play Again?\n");
    	gotoxy(45,11);
		printf("Press 1 to restart else Press 0 -> ");
		scanf("%d", &game);
		clrscr();
		}
    }
    	
	void getValue(character* enemy){
		enemy->player[0].damage = 20; /*Change ni*/
		enemy->player[0].HP = 100;
		strcpy(enemy->player[0].name,"Banaba");
		enemy->player[1].damage=30;
		enemy->player[1].HP = 100;
		strcpy(enemy->player[1].name,"Joloano");
		strcpy(enemy->player[2].name,"Father's Legendary Chicken");
		enemy->player[2].damage=50;
		enemy->player[2].HP = 200;
	}
	
    
    void displayCharacter(hero player){
    	chickenDisplayCharacter();
    	gotoxy(52,12);
    	printf("Name->%s\n", player.name);
    	gotoxy(53,13);
    	printf("HP->%d\n", player.HP);
    	gotoxy(51,14);
    	printf("Damage->%d\n", player.damage);
    	gotoxy(44,15);
    	printf("Press any key to continue-> ");
    	getch();
    	clrscr();
	}
    
    void chooseBuff(hero *player){
    	int catcher,x=player->damage,y=player->HP;
    	printf("Pick your buff\n");
    	printf("\nPress 1 = Chick Steroids -> Damage Increase(+%%50 Damage)");
    	printf("\nPress 2 = Chick Booster -> Health Increase (+%%50 Health)\n-> ");
    	scanf("%d", &catcher);
    	switch(catcher){
    		case 1: player->damage *=1.5; printf("Damage Increase from %d -> %d", x,player->damage) ;break;
    		case 2: player->HP *=1.5; printf("Health Increase from %d -> %d", y,player->HP); break;
		}
		printf("\n\nYou also have the following items that you can only use once after every match\n");
		printf("\nMetal Claw = Damage Amplified (+20%% Damage)\n");
		printf("Electrolyte Drink = Healing Potion (+50 HP)\n");
		printf("Press any key to continue...");
		getch();
		clrscr();
	}
	
	 void buyShop(hero* player){
	 	int x;
	 	useFlag =0;
	 	int catcher;
	 	while(catcher != 4){
	 	displayShop();
	 	printf("What do you want to buy?\n");
	 	printf("\n1.Metal Claw = Damage Amplified (+20%% Damage): Cost: 60\n");
	 	printf("\n2.Electrolyte Drink = Regeneration (+50 HP): Cost: 50\n");
	 	printf("\n3.Display Bag\n");
	 	printf("\n4.Press 4 to exit\n");
		printf("\nCurrent Gold -> %.2f\n-> ",player->money);
	 	scanf("%d", &catcher);
	 	clrscr();
	 		if(catcher == 3){
	 			displayBag(player);
		 	}else if(catcher !=4){
		 		insertItems(catcher, player);
			 }
		 }
	 }

	 
		void startFight(hero* player, int y, character* enemy, int* life){
		char catcher;
		float newMoney=0;
		int retval=0;
	  	while(player->HP > 0 && enemy->player[y].HP > 0){
	  		displayRound(y);
	  		versusScreen();
	  		displayEnemy(y);
	  		gotoxy(69,4);
	  		printf("Name-> %s",enemy->player[y].name);
	  		gotoxy(69,5);
	  		printf("HP-> %d",enemy->player[y].HP);
	  		gotoxy(69,6);
	  		printf("Damage-> %d",enemy->player[y].damage);
	  		chickenDisplayFight();
	  		gotoxy(20,22);
	  		printf("Name-> %s", player->name);
	  		gotoxy(20,23);
	  		printf("HP-> %d", player->HP);
	  		gotoxy(20,24);
	  		printf("Damage-> %d", player->damage);
	  		gotoxy(35,22);
	  		printf("Type A to attack\n");
	  		gotoxy(35,23);
	  		printf("Type U to use an item\n");
	  		gotoxy(35,24);
	  		printf("-> ");
	  		scanf("%c", &catcher);
	  		switch(catcher){
	  			case 'A' : retval = attack(player,enemy,y);break;
	  			case 'a' : retval = attack(player,enemy,y);break;
				case 'U' : useFlag=1; displayBag(player);break;
				case 'u' : useFlag=1; displayBag(player);break;
			  }
			  clrscr();
		  }
		  if(retval == 1){
		  	displayDaog();
		  	newMoney =player->money+ 100;
			*life = 1;
		  	gotoxy(39,16);
		  	printf("Your Money now is %.2f + 100.00 = %.2f",player->money, newMoney);
		  	gotoxy(44,17);
		  	player->money = newMoney;
		  	printf("Press any Key to Continue -> ");
		  	getch();
		  }else if (retval == -1){
		  	displayBihag();
		  	*life = 0;
		  	gotoxy(46,16);
		  	printf("Press any Key to Continue -> ");
		  	getch();
		  }
	  }

	int attack(hero* player, character*enemy, int round){
		int n,result,retval;
		char you, computer,catcher1, catcher2;
		char str1[40], str2[40];
		srand(time(NULL));
		
		n = rand()%100; /*Change this */
		if(n<33){
			computer = 'c';
		}else if(n > 33 && n < 66){
			computer = 'p';
		}else{
			computer = 'w';
		}
		gotoxy(35,26);
		printf("Enter c for Claw, p for Peck,and w for Wing Attack-> ");
		fflush(stdin);scanf("%c",&you);
		
		catcher1= computer;
		catcher2 = you;
		switch (catcher1){
			case 'c': strcpy(str1,"Claw");break;
			case 'p': strcpy(str1,"Peck");break;
			case 'w': strcpy(str1,"Wing Attack");break;
		}
		if(catcher2 == 'c' || catcher2 == 'C'){
			strcpy(str2,"Claw");
		}else if(catcher2 == 'p' || catcher2 == 'P'){
			strcpy(str2,"Peck");
		}else{
			strcpy(str2,"Wing Attack");
		}
		
		result = checkWinner(you, computer);
		switch (result){
			case -1: gotoxy(20,28);printf("You and the enemy picked the same skill (No Damage)");break;
			case 1: gotoxy(20,28); printf("Your enemy tried to use [%s] but your skill [%s] is stronger. Enemy takes damage",str1,str2);(enemy)->player[round].HP -= (player)->damage;break;
			case 0:gotoxy(20,28); printf("You tried to use [%s] but your enemy's [%s] is stronger. You take damage",str2,str1);(player)->HP -= (enemy)->player[round].damage; break;
		}
		getch();
		fflush(stdin);
		if((enemy)->player[round].HP <= 0){
			retval = 1;
		}else if((player)->HP <= 0){
			retval = -1;
		}
		return retval;	
	}
	
	void insertItems(int catcher,hero* player){
		int x;
		
			if(catcher == 1){
			if(player->money >= 60){
				player->backpack.items[0].count++;
				player->money = player->money - 60.0;
				clrscr();
				printf("Purchase Successful: Press any key to continue-> ");
				getch();
				clrscr();
			}else{
				clrscr();
				printf("Insufficient Funds: Press any key to continue->");
				getch();
				clrscr();
			}
			
			}else if(catcher == 2){
				if(player->money >= 50){
				player->backpack.items[1].count++;
				player->money = player->money - 50.0;
				clrscr();
				printf("Purchase Successful: Press any key to continue-> ");
				getch();
				clrscr();
			}else{
				clrscr();
				printf("Insufficient Funds: Press any key to continue->");
				getch();
				clrscr();
			}
			}
			clrscr();	
	}
	
	void displayBag(hero* player){
		clrscr();
		int x,num=1,y,ctr=0;
		
		for(x =0 ; x<2; x++){
			if(player->backpack.items[x].count > 0){
				ctr++;
		    }
			printf("%d. %s : x%d\n",num++,player->backpack.items[x].bagName,player->backpack.items[x].count);
		}

		if(ctr == 0){
			printf("\nYou have no items left\n");
			printf("Press any key to return ->");
		}
		else if(useFlag ==1){
			printf("-> ");
			scanf("%d", &y);
			useItems(player, y);	
		}
		getch();
		clrscr();
		}
	
	
	void useItems(hero* player, int y){
			if(player->backpack.items[y-1].count > 0){
				switch(y){
					case 1: player->damage *= player->backpack.items[0].powerUp;player->backpack.items[0].count--;break;		
					case 2: player->HP += player->backpack.items[1].powerUp;player->backpack.items[1].count--;break;
					default : printf("Wrong Input");
				}	
			}else{
				printf("Can't use item");
			}
			
		}
		
        


	


    

