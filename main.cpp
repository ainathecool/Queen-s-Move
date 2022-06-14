#include<iostream>
#include <cstdlib>
#include<cstring>
#include<conio.h>

using namespace std;

#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF //for printing of chess board

// classes player, chess, game, queen, piece, king

class Player
{
	string password;
	public:
		string name;
		int ID;
		Player() //def constructor
		{
			name="queen";
			password="sam.c";
			ID=111;
		}
		//setters getters
		string get_password()
		{
			return password;
		}
		void set_name(string name)
		{
			this->name=name;
		}
		void setting_ID()
		{
			ID=rand();
		}
		void set_password(string password)
		{
			this->password=password;
		}
		//registeration for new member
		void registeration()
		{
			char input;
			cout<<"\nREGISTER ACCOUNT";
			cout<<"\nEnter Name: ";
			cin>>name;
			cout<<"Enter New Password (password should only be of characters and should not include numbers): ";
			cin>>password;
			setting_ID();
			cout<<"ID: "<<ID;
			cout<<"\nEnter any key to continue: ";
			cin>>input;
			
		}
};

class Piece
{
	public:
		int count;
		int row_position, coloumn_position;
		
		Piece()
		{
			row_position=0;
			coloumn_position=0;
			
		}
		void input_position()
		{
			
		}
		void set_position()
		{
			
		}
		void check_count()
		{
			
		}
		
};
class chess
{
	Piece pie1; //has a relationship
	int n; //n denoting the n of  nxn board
//	friend class game;
	public:
		chess()
		{}
		chess(int n) //parameterised constructor, taking n from user
		{
			this->n=n;
		}
		void display_board()
		{
			int Line;
		//	char i;
			for(Line = n-1; Line >= 0; Line--)
			{
		    	if (Line%2 == 0)
		    	{
		        	// Line starting with BLACK
		        	printLine(Line, BLACK_SQUARE, WHITE_SQUARE);
		    	}
				else
		    	{
		        	// Line starting with WHITE
		        	printLine(Line, WHITE_SQUARE, BLACK_SQUARE);
		    	}
		   }
		}
		void printLine(int Line, int Color1, int Color2)
		{
			int subLine,Pair,subColumn,CELL = 6;
			int c=0;
			for (subLine = 0; subLine < CELL/2; subLine++)
			{
        		for(c=0;c<n;c++)
        		{
        			if(c%2==0)
        			{
        				for (int subColumn = 0; subColumn < CELL; subColumn++)
        				{
        					cout << char(Color1);
        					
        				}
					}
					else
					{
						for (int subColumn = 0; subColumn < CELL; subColumn++)
        				{
        					cout << char(Color2);
        				}
					}
				}
        		if(1 == subLine)
    			{
     			   cout << "   " << Line+1;
    			}
      			cout << "\n";
      		}			
		}
};
class Queen : public Piece //inheritance
{
	
	public:
		Queen() : Piece()
		{
			
		}
	/*	void input_position()
		{
			
			cout<<"\nEnter the position for the queen";
			cout<<"\nRow: ";
			cin>>row_position;
			cout<<"Coloumn: ";
			cin>>coloumn_position;
			set_position(row_position, coloumn_position);
		}*/
		void set_position(int row_position,int coloumn_position)
		{
			this->row_position=row_position;
			this->coloumn_position=coloumn_position;
		}
		//will check validity/compare queens objects
	
		void display_board(int n, int row, int col, int cheQ[][10])
		{
			int Line;
	
			for(Line = 1; Line <= n; Line++)
			{
		    	if (Line%2 == 0)
		    	{
		        	// Line starting with BLACK
		        	printLine(Line, BLACK_SQUARE, WHITE_SQUARE, n, row, col, cheQ);
		    	}
				else
		    	{
		        	// Line starting with WHITE
		        	printLine(Line, WHITE_SQUARE, BLACK_SQUARE,n, row, col, cheQ);
		    	}
		   }
		}
		void printLine(int Line, int Color1, int Color2, int n, int row, int col, int cheQ[][10])
		{
		
			int ci, cj;
			int subLine,Pair,subColumn,CELL = 6;
			int c=0;
			for (subLine = 0; subLine < CELL/2; subLine++)
			{
        		for(c=1;c<=n;c++)
        		{
        			if(c%2==0)
        			{
        				for (int subColumn = 0; subColumn < CELL; subColumn++)
        				{
        					for(ci=0;ci<10;ci++) //cheQ
        					{
        						for(cj=0;cj<10;cj++)
        						{
        							if(cheQ[ci][cj]==1)
        							{
        								ci=row;
        								cj=col;
        								if(subLine==1 && subColumn==3 && c==cj && Line==ci )
										{
											cout<<"q";
										}
            							else
            							{
             					 			 cout << char(Color1);
          				 				}
									}
								}
							}
        					
        				}//end of for
					}//end of if
					else
					{
						for (int subColumn = 0; subColumn < CELL; subColumn++)
        				{
        					for(ci=0;ci<10;ci++) //cheQ
        					{
        						for(cj=0;cj<10;cj++)
        						{
        							if(cheQ[ci][cj]==1)
        							{
        								ci=row;
        								cj=col;
        								if(subLine==1 && subColumn==3 && c==cj && Line==ci)
										{
											cout<<"q";
										}
            							else
            							{
             					 			 cout << char(Color2);
          				 				}
									}
								}
							}
        				}
					}
				}//end of for
        		if(1 == subLine)
    			{
     			   cout << "   " << Line;
    			}
      			cout << "\n";
      		
      		}			
		}
};

class King : public Piece
{
	public:
		King()
		{
			count = 4; //bonus kings awarded as soon as user joins game
		}
		AddKings()
		{
			count++; //incremented at every level up
		}
		
};
class Game
{
	Player* P1; //has a relationship with player class
	King k;
//	Queen q1;
//	Queen q[10];
	int levQ=0; //counter to check k sari queens correctly placed hain k nai
	public:
		int choice; //level of game 
		Game(Player* P1)
		{
			this->P1=P1;
		}
		void check_account()
		{
			char choice;
			cout<<"\nHave an account?:(type y for yes and n for no): ";
			cin>>choice;
			if(choice=='y' || choice=='Y')
			{
				system("CLS");
				login();
			}
			else if(choice=='n' || choice=='N')
			{
				
				DisplayHeadString("REGISTERATION");
				P1->registeration();
				
				system("CLS");
				login();
			}
			else
			{
				cout<<"\ninvalid choice";
				check_account();
			}
		}
		void login()
		{
			DisplayHeadString("LOGIN");
			string name1;
			string password1;
			int id;
			cout<<"\nLOGIN";
			cout<<"\nEnter Name: ";
			cin>>name1;
			cout<<"Enter ID: ";
			cin>>id;
			cout<<"Enter Password: ";
			cin>>password1;
			if((name1==P1->name) && (password1==P1->get_password()) && (id==P1->ID))
			{
				system("CLS");
				Welcome();
			}
			else
			{
				char input;
				cout<<"\ninvalid name or password or ID";
				cout<<"\nEnter any key to continue: ";
				cin>>input;
				system("CLS");
				login();
			}
		}
		//to display the central string 
void DisplayCentralString(const char* string)
{
	int len=0; // length for number of spaces to print on output screen for message to be in center
	int pos=0; //position counter for spaces
	
	len = (98 - strlen(string))/2; //calc initial spaces before the string
	printf("\t\t\t");
	
	for(pos=0;pos<len;pos++)
	{
		cout<<" ";
		
	}
	cout<<" "<<string;
}

//to display the main header string 
void DisplayHeadString(const char* string)
{
	system("cls"); //clear screen
	cout<<"\t\t\t--------------------------------------------------------------------------------------------------";
	cout<<"\n\t\t\t----------                                                                              ----------";
	cout<<"\n\t\t\t----------                             SAM.C QUEEN's MOVE                               ----------";
	cout<<"\n\t\t\t----------                                                                              ----------";
	cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------";
	cout<<"\n";
	DisplayCentralString(string); //will call centrals tring function and print whatever string we want as the central message
	cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------\n\n\n";
	
	

}

// to display the welcome message to the library
void DisplayWelcome()
{
	DisplayHeadString("SAM.C GAMES"); //will call headstring function which will print header and then call central string function which will then print this string
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t--------------------------------------------------------------------------------------------------";
	cout<<"\n\t\t\t----------                                                                              ----------";
	cout<<"\n\t\t\t----------                        WELCOME TO SAM.C 'QUEEN's MOVE'                       ----------";
	cout<<"\n\t\t\t----------                                                                              ----------";
	cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------";
	cout<<"\n Enter any key to continue.";
//	getche();
	
}

		void Welcome()
		{
			//DisplayWelcome();
			main_menu();
		}
		char another;
		void main_menu()
		{
		//	int choice;
			DisplayHeadString("MAIN MENU");
			cout<<"\nWhere to head next?";
			cout<<"\n1. How To Play\n2. Levels\n3. Achievements\n4. Quit Game";
			cout<<"\nchoice: ";
			cin>>choice;
			
			switch (choice)
			{
				case 1:
					system("CLS");
					HowToPlay();
					cout<<"\nReturn to main menu? press y.";
					cin>>another;
					if(another=='y' || another=='Y')
					{
						main_menu();	
					}
					
					break;
				case 2:
					system("CLS");
					Levels();
					cout<<"\nReturn to main menu? press y.";
					cin>>another;
					if(another=='y' || another=='Y')
					{
						main_menu();	
					}
					break;
				case 3:
					Achievements();
					cout<<"\nReturn to main menu? press y.";
					cin>>another;
					if(another=='y' || another=='Y')
					{
						main_menu();	
					}
					break;
				case 4:
					cout<<"THANK YOU FOR PLAYING!";
					exit(1);
					break;
				default:
					cout<<"\ninvalid option";
					system("CLS");
					main_menu();
			}
		}
		void HowToPlay()
		{
			DisplayHeadString("HOW TO PLAY");
			cout<<"\n\t\t\tThere are three basic constraints of attempting N-Queen's game.";
			cout<<"\n\t\t\t\t1.One row must contain one queen.";
			cout<<"\n\t\t\t\t2.One coloumn must contain one queen.";
			cout<<"\n\t\t\t\t3.One diagonal must contain one queen.";
			cout<<"\n\n\t\t\tThe queens must be placed in such an order that no queen on the board is in position to attack another queen.";
			cout<<"\n\t\t\tYou must place n queens on the NxN board correctly to attempt the next higher level.";
			cout<<"\n\n\t\t\tHOW IT WORKS: ";
			cout<<"\n\t\t\t\tThe game will ask you for the row and coloumn positions of the queen. \n\t\t\tIf you place any queens incorrectly, the game will ask you to try again. \n\t\t\tThis will repeat until you attempt the level correctly.";
			cout<<"\n\n\n\t\t\tGOOD LUCK.";
			
		}
		void Achievements()
		{
			
			DisplayHeadString("YOUR ACHIEVEMENTS");
			cout<<"\n\t\t\tYou can view current achievements here.";
			cout<<"\n\n\t\t\tAwarded Kings: "<<k.count;
			cout<<"\n\n\t\t\tMedals: "<<k.count;
			cout<<"\n\n\n\t\tKEEP PLAYING TO UNLOCK MORE ACHIEVEMENTS.";
		}
		void Levels()
		{
			char input;
			DisplayHeadString("LEVELS");
			int choice;
			cout<<"\n\t\tDo you want to play or return to main menu? (press p for play and m for main menu:)";
			cin>>input;
			if(input=='p' || input=='P')
			{
				cout<<"\nYou must have the same number of kings as the level you want to play. You will be awarded more kings as you level up. ";
			cout<<"\nYour current king count is: "<<k.count;
			cout<<"\nChoose the level by entering the number of queens you want to set on the board. ";
			cout<<"\n4 Queens\t5 Queens\t6 Queens\t7 Queens\t8 Queens\t9 Queens\t10 Queens";
			cout<<"\nSelection: ";
			cin>>choice;
			
			if(k.count == choice)
			{
				chess c(choice);
				system("CLS");
				DisplayHeadString("PLAY GAME. GOOD LUCK.");
				c.display_board();
				play_game(choice);
			}
			else
			{
				char input;
				cout<<"\nPlease enter an allowed level choice.";
				cout<<"\nPress any key to try again: ";
			//	cin>>input;
				getche();
				Levels();
			}
			} //outer if play ya main menu
			else if(input=='m' || input=='M')
			{
				main_menu();
			}
			else
				cout<<"\ninvalid choice";
				cout<<"\nPress any key to continue:";
				getche();
				Levels();
			
			
		}
		void levelUp()
		{
			if(levQ!=choice)
			{
				system("CLS");
				DisplayHeadString("LEVEL UP! CONGRATULATIONS GAMER! ALLAH AAPKO QUEEN BANAYE YA QUEEN DEY! AMEEN!");
				cout<<"\n\n\n\t\t\t\tYou are a success! Definitely made your parents proud!\nYOU HAVE BEEN AWARDED A KING AND A MEDAL!\nGOOD LUCK FOR THE NEXT LEVEL!";
				k.AddKings();
				cout<<"Press any key to continue: ";
				getche();
				Levels();
			}
			else
			{
				system("CLS");
				DisplayHeadString("LEVEL FAILED! GOOD LUCK NEXT TIME, LOSER! AIK QUEEN SET NAI HOYI, LOSER! ");
				cout<<"\n\n\n\n\t\t\t\tAcha yaar rou mat, try again!";
				cout<<"Press any key to continue: ";
				getche();
				main_menu();
			}
		}
		void play_game(int choice) //choice yaani kis position pa rakhna hai queen ko atm 
		{
		
			Queen q[choice]; //choice yaani n (jitni queens/nxn board)
			int cheQ[10][10] = {0}; //array which will store queens positions, needed for validity of positions
			int  m, k; //loop counters
			int row, col; //variables to input position from user
			
			for(k=0;k<choice;k++)
			{
				do
				{
					cout<<"\nEnter the position for the queen";
					cout<<"\nRow: ";
					cin>>row;
					cout<<"Coloumn: ";
					cin>>col;
					//cheQ[row-1][col-1] = 1; //all positions are 0 except user given positon which is now 1,
					q[k].set_position(row,col);  //setting values in queen class
					
					if(is_valid(m, cheQ, row, col, choice)==1)
					{
						cheQ[row-1][col-1] = 1;
						q[k].display_board(choice, row, col, cheQ); //print board with correct queen
						levQ++;
						break;
					}
					
					
				}
				while(is_valid(m, cheQ, row, col, choice)!=1);
			}
			levelUp();
		}
		int is_valid(int m, int cheQ[][10], int row, int col, int choice)
		{
			int i, j; //loop counters
			
			//ab check karna hai k jo user na latest position dee hai, uss par already koi queen tou nai hai?
			//tou we'll check our array with user's latest position, and see k uspar 1 hai ya nai (agar 1 hai tou its already in use & wahi invalidated
			//agar 0 hai tou its allowed, but agar 0 hai tou hum dekhain ga k kya wo kisi ka diagonal tou nai
			
			for(i=0;i<choice;i++)
			{
				for(j=0;j<choice;j++)
				{
					if(cheQ[i][j]==1 && (i==(row-1) || j==(col-1)) )
					{				
															
						cout<<"\ninvalid row or column";
						cout<<"\nacha rou mat, loser. try again.";
						cout<"\a\a\a";
						return 0;
					}
					else if ( (cheQ[(row)][(col)]==1 || cheQ[(row)][(col-2)]==1 || cheQ[(row-2)][(col)]==1))
					{	//
						cout<<"\ninvalid diagonal";
						cout<<"\nkya yaar aik queen set nai horhi :(";
						cout<"\a\a\a";
						return 0;
					}
					

				}
			}
			return 1;

		} //end of is valid function
};
main()
{
	system("Color 64"); //pehla num is bg, second num is text
	Player player;
	Game g(&player);
	g.DisplayWelcome();
	g.check_account();
}

