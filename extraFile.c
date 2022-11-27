#include<stdio.h>
//#include<conio2.h>
#define size 3
#include<string.h>



  void titleScreen(){

		gotoxy(45,5);
		printf("Welcome to the Low Budget Sabong Game\n");
		textcolor(GREEN); 
		gotoxy(52,6); 	
		printf("    ____ _    ______\n");
		gotoxy(52,7); 
		printf("   / __  ||  / / __  |\n");
		gotoxy(52,8);
		printf("  / /_/ / | / / /_/ /\n");
		gotoxy(52,9);
		printf(" / ____/| |/ / ____/ \n");
		gotoxy(52,10);
		printf("/_/     |___/_/      \n\n");
		gotoxy(51,12);
		textcolor(WHITE); 
		gotoxy(57,16);
		printf("   \\\\ \n");
		gotoxy(57,17);
		printf("   (o>\n");
		gotoxy(57,18);
		printf(" \\_/_)\n");
		gotoxy(57,19); 
		printf(" \\_//)\n");
		gotoxy(57,20);
		printf("  _|_\n\n");
		gotoxy(52,22);
		printf("The Protagonist/Player\n");
		gotoxy(54,23);
		printf("(Chicken Ni Papa) "); 
		gotoxy(51,25);
		printf("Press any key to start ");                                                        
    	getch();
    	clrscr();
		}
		
	   void chickenDisplayCharacter(){
	   	gotoxy(51,6);
		printf("   \\\\ \n");
		gotoxy(51,7);
		printf("   (o>\n");
		gotoxy(51,8);
		printf(" \\_/_)\n");
		gotoxy(51,9);
		printf(" \\_//)\n");
		gotoxy(51,10);
		printf("  _|_");
	   }
	   
	   void chickenDisplayFight(){
	   	gotoxy(10,20);
		printf("   \\\\ \n");
		gotoxy(10,21);
		printf("   (o>\n");
		gotoxy(10,22);
		printf(" \\_/_)\n");
		gotoxy(10,23);
		printf(" \\_//)\n");
		gotoxy(10,24);
		printf("  _|_");
	   }
	   
	   
	   void displayEnemy(int y){
	   	switch(y){
	   		case 0: 
	   		textcolor(BROWN);
	   		gotoxy(80,2);
			printf("           __\n");
			gotoxy(80,3);
			printf("          /'{>\n");
			gotoxy(80,4);
			printf("      ____) (____\n");
			gotoxy(80,5);
			printf("    //'--;   ;--'\\\\\n");
			gotoxy(80,6);
			printf("   ///////\\_/\\\\\\\\\\\\\\\n");
			gotoxy(80,7);
			printf("          m m\n");
			textcolor(WHITE);
			break;
			case 1:
			textcolor(MAGENTA);
			gotoxy(85,2);
			printf("     _\\|      __     |/_\n");
			gotoxy(85,3);
			printf("   _-  \\_   _/0 >   _/  -_\n");
			gotoxy(85,4);
			printf("   -_    `-'(   )`-'    _-\n");
			gotoxy(85,5);
			printf("    `=.__.=-(   )-=.__.='\n");
			gotoxy(85,6);
			printf("            |/-\\|\n");
			gotoxy(85,7);
			printf("            Y   Y\n");
			textcolor(WHITE);break;
			
			case 2:
			gotoxy(85,8);
			textcolor(LIGHTRED);
			printf("          _.-'`)     (`'-._\n");
			gotoxy(85,9);
			printf("        .' -' / __    \\ '- '.\n");
			gotoxy(85,10);
			printf("       / .-' ( '-,`|   ) '-. \\\n");
			gotoxy(85,11);
			printf("      / .-',-`'._/ \\_.'`-,'-. \\\n");
			gotoxy(85,12);
			printf("     ; ; /.`'.-'(   )'-.'`.\\ ; ;\n");
			gotoxy(85,13);
			printf("     | .-'|\\//'-/   \\-'\\/|'-. |\n");
			gotoxy(85,14);
			printf("     |` |; :|'._\\   /_,'|: ;| `|\n");
			gotoxy(85,15);
			printf("     || : |;    `Y-Y`    ;| : ||\n");
			gotoxy(85,16);
			printf("     \\:| :/======""======\\| |:/\n");
			gotoxy(85,17);
			printf("     /_:-`                 `-;_\n");
			textcolor(WHITE);break;
		   }
	   }
	   void versusScreen(){
	   	textcolor(RED);
	   	gotoxy(50,13);
	   	printf(" _    _______\n");
	   	gotoxy(50,14);
	   	printf("| |  / / ___/\n");
	   	gotoxy(50,15);
	   	printf("| | / /\\__ \\ \n");
	   	gotoxy(50,16);
	   	printf("| |/ /___/ / \n");
	   	gotoxy(50,17);
	   	printf("|___//____/ \n");
	   	textcolor(WHITE);
       
	   }
	   void displayRound(int y){
	   	switch(y){
	   		case 0: 
	   		textcolor(LIGHTBLUE);
	   		printf("    ____                        __   ___\n");
			printf("   / __ \\____  __  ______  ____/ /  <  /\n");
			printf("  / /_/ / __ \\/ / / / __ \\/ __  /   / / \n");
			printf(" / _, _/ /_/ / /_/ / / / / /_/ /   / / \n");
			printf("/_/ |_|\\____/\\__,_/_/ /_/\\__,_/   /_/  \n");textcolor(WHITE); break;
			
			case 1:
			textcolor(LIGHTBLUE); 
			printf("    ____                        __   ___ \n");
			printf("   / __ \\____  __  ______  ____/ /  |__ \\\n");
			printf("  / /_/ / __ \\/ / / / __ \\/ __  /   __/ /\n");
			printf(" / _, _/ /_/ / /_/ / / / / /_/ /   / __/ \n");
			printf("/_/ |_|\\____/\\__,_/_/ /_/\\__,_/   /____/ \n");textcolor(WHITE);break;
			
			case 2:
			textcolor(LIGHTBLUE); 
			printf("    ____  ____  __________    __________________  ________\n");
			printf("   / __ )/ __ \\/ ___/ ___/   / ____/  _/ ____/ / / /_  __/\n");
			printf("  / __  / / / /\\__ \\\\__ \\   / /_   / // / __/ /_/ / / /   \n");
			printf(" / /_/ / /_/ /___/ /__/ /  / __/ _/ // /_/ / __  / / /    \n");
			printf("/_____/\\____//____/____/  /_/   /___/\\____/_/ /_/ /_/     \n");textcolor(WHITE);break;
		   }
	   }
	   
	  void storyTime(){
    	printf("\t\t\t\t\t\t\tSTORY \n\n");
    	printf("\t\t\tThis is the story of a young man whose father is a cockfighting legend. \n");
    	printf("\t\t\tBecause of the nature of his work. He is more focused on his cocks than\n");
    	printf("\t\t\this own son (you). In order to get his attention, you decide to enter\n");
    	printf("\t\t\t\tthe world of cockfighting and defeat your own father.\n");
    	printf("\t\t\t\t    Plot Twist: Your father is Sir Beets.\n\n");
    	printf("\t\t\t\t\t    Press any key to continue\n");
    	getch();
    	clrscr();
	}
	
	
		int checkWinner(char you, char computer){
		int retval;
		if (you == computer){
		  	retval = -1;
		}else if (you == 'c' || you == 'C' && computer == 'w' || computer == 'W'){
		  	retval = 0;
		}else if (you == 'w' || 'W' && computer == 'c'|| computer == 'C'){
		   	retval= 1;
		}else if (you == 'c' || you == 'C' && computer == 'p' || computer == 'P'){
		    retval = 1;
		}else if (you == 'p' || you == 'P' && computer == 'c' || computer == 'C'){
		    retval = 0;
		}else if (you == 'w' || you == 'W' && computer == 'p' || computer == 'P'){
			retval = 0;
		}else if (you == 'p' || you == 'P' && computer == 'w' || computer == 'W'){
    		retval = 1;
		}
		return retval;
		}

	void displayBihag(){
	textcolor(RED);
	gotoxy(45,10);
	printf("    ____  ______  _____   ______\n");
	gotoxy(45,11);
	printf("   / __ )/  _/ / / /   | / ____/\n");
	gotoxy(45,12);
	printf("  / __  |/ // /_/ / /| |/ / __  \n");
	gotoxy(45,13);
	printf(" / /_/ // // __  / ___ / /_/ /  \n");
	gotoxy(45,14);
	printf("/_____/___/_/ /_/_/  |_\\____/  \n");
	textcolor(WHITE);
	}
	
	void displayDaog(){
	textcolor(GREEN);
	gotoxy(45,10);
	printf("    ____  ___   ____  ______\n");
	gotoxy(45,11);
	printf("   / __ \\/   | / __ \\/ ____/\n");
	gotoxy(45,12);
	printf("  / / / / /| |/ / / / / __  \n");
	gotoxy(45,13);
	printf(" / /_/ / ___ / /_/ / /_/ /  \n");
	gotoxy(45,14);
	printf("/_____/_/  |_\\____/\\____/   \n");
	textcolor(WHITE);
	}
	
	void displayGameOver(){
		gotoxy(35,10);
        printf("   _________    __  _________   ____ _    ____________ \n");
        gotoxy(35,11);
		printf("  / ____/   |  /  |/  / ____/  / __ \\ |  / / ____/ __ \\\n");
		gotoxy(35,12);
		printf(" / / __/ /| | / /|_/ / __/    / / / / | / / __/ / /_/ /\n");
		gotoxy(35,13);
		printf("/ /_/ / ___ |/ /  / / /___   / /_/ /| |/ / /___/ _, _/ \n");
		gotoxy(35,14);
		printf("\\____/_/  |_/_/  /_/_____/   \\____/ |___/_____/_/ |_| \n");                                   
	}
	
	void displayShop(){
		textcolor(YELLOW);
		printf("   _____ __  ______  ____ \n");
		printf("  / ___// / / / __ \\/ __ \\\n");
		printf("  \\__ \\/ /_/ / / / / /_/ /\n");
		printf(" ___/ / __  / /_/ / ____/ \n");
		printf("/____/_/ /_/\\____/_/      \n");
		textcolor(WHITE);
	}
	
	void displayVictory(){
		textcolor(GREEN);
		gotoxy(51,6);
		printf("   ____________\n");
		gotoxy(51,7);
		printf("  / ____/ ____/\n");
		gotoxy(51,8);
		printf(" / / __/ / __  \n");
		gotoxy(51,9);
		printf("/ /_/ / /_/ /  \n");
		gotoxy(51,10);
		printf("\\____/\\____/   \n");
		textcolor(WHITE);
		gotoxy(39,12);
		printf("Congratulations! You defeated your father");
		gotoxy(53,15);
		printf("   \\\\ \n");
		gotoxy(53,16);
		printf("   (o>\n");
		gotoxy(53,17);
		printf(" \\_/_)\n");
		gotoxy(53,18);
		printf(" \\_//)\n");
		gotoxy(53,19);
		printf("  _|_");
		gotoxy(43,20);
		printf("Press any key to continue ->");
	}
