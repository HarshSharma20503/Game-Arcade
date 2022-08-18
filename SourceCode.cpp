#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<algorithm>
#include<map>
#include<exception>
using namespace std;

class TicTacToe
{
   private:
   char board[3][3]; //two-dimensional array for the grid
   bool GameOver, draw;
   /* GameOver to store weather the game is over or not
      draw to store weather the game ended in draw or not*/
   char Player, num;
   /* Player to store the symbol of the player i.e. 'X' or 'O' 
      To store the position which user enters */
   public:
   string winner;
   // winner to store winner name
   string player1,player2;
   // player1 and player2 to store name of the players 
   TicTacToe() //default constructor to initialise Gameover, draw and Player symbol
   {
      GameOver=false;
	  draw=false;
      Player = 'O';
   }

   // Game starts from here
   void start()
   {
    system("CLS");
    cout << "******* WELCOME TO *******\n";
    cout << "******  Tic-Tac-Toe ******\n";
    cout << "--------------------------"<< endl;
    cout << "Enter Player 1 Name:\n";
    cin  >> player1;
    cout << "Enter Player 2 Name:\n";
    cin  >> player2;
    cout << player1 << " has 'X' moves and "<< player2 << " has 'O' moves\n"; 
    
    SetBoard(); // SetBoard function called

    // loop to repetivly ask for the position until the game ends
	do 
    {
        if( Player == 'X' ) // changes player turn after every move
        {
           Player = 'O';
        }
        else
        {
           Player = 'X';
        } 
        PrintBoard();// prints the board after doing changes of previous turn
        cout << "\nPlayer \"" << Player << "\", it's your turn: ";
        cin >> num; 
        cout << "\n";

        PlayerTurn(num, Player); //PlayerTurn function called
        GameOver = CheckResult(Player, GameOver); // CheckResult function called 
        GameOver= CheckDraw(GameOver);// CheckDraw function called 
		if(GameOver == true) //checks wheather the game is over or not
        {   
			if(!draw) //checks weather game was draw or not
			{         // if game is not draw than these statments gets executed
            if( Player == 'X' )
            winner = player1;
            else
            winner = player2;
            cout << "Player " << winner << " wins!\n\n";
            cout << "-----------------------" << endl;
            cout << "|   CONGRATULATIONS   |\n";
            cout << "-----------------------" << endl << endl; 
			}
        }
        
    } while(!GameOver);//condition of the loop
   }

   //function to initialise the board with 1-9 numbers i.e. the positions of the grid
   void SetBoard() 
   {
      int n = 1;
      int i = 0;
      int j = 0;

      for ( i = 0; i < 3; i++ ) // loop to traverse the grid
      {
         for ( j = 0; j < 3; j++ )
         {
            board[i][j] = '0' + n; //Casting the n to a character
            n++;
         }
      }
   } 

   //function to print (output) our board
   void PrintBoard()
   {
      int i = 0;
      int j = 0;
      cout<<"\n**************\n";
      for ( i = 0; i < 3; i++ )
      {
         for ( j = 0; j < 3; j++ )
         {
            if ( j < 2 ) // if else is used to do designing formatting
            {
               cout << board[i][j] << "  |  ";
            }
            else 
            {
                  cout << board[i][j] << endl;
            }
         }
      }
	  cout<<"\n**************\n";
   } 

   //function to control Player moves
   void PlayerTurn(char num, char Player)
   {
      int i = 0;
      int j = 0;

      bool WrongMove = true; //If true, the player has made a wrong move
      for( i = 0; i < 3; i++ )
      {
         for( j = 0; j < 3; j++ )
         { //Mark square with X or O if WrongMove is not true
            if(board[i][j] == num) 
            { 
               board[i][j] = Player; //Assigns the space with the X or O, 
               WrongMove = false;    //depending on the board. 
            }
         }
      }
      if(WrongMove == true) 
	  { 
		cout << "You can only mark the open sets!\n"; 
	  }
   } 


   //checking for the winner, if any, finish the game. If not, cotinue or check draw
   bool CheckResult(char Player, bool GameOver)
   {
      for(int i = 0; i < 3; i++) //checking rows
      {
         if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
         {
            GameOver = true;
         }
      }
      for(int i = 0; i < 3; i++) //checking coloumns
      {
         if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
         {
            GameOver = true;
         }
      }
      //Checking the Diagonals
      if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
      {
         GameOver = true;
      }
      if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
      {
         GameOver = true;
      }
         return GameOver;
   } 

   //Check the board to see if the match has come to a draw
   bool CheckDraw(bool GameOver)
   {
      int n = 1;
      int i = 0;
      int j = 0;
      int counter = 0;

      for( i = 0; i < 3; i++ )
      {
         for( j = 0; j < 3; j++ )
         {
            //Check to see if the board if full
            if(board[i][j] == '0' + n) 
            { 
               counter++; 
            }
            n++;
         }
      }
      if( counter < 1 ) 
      {
         cout << "No one won :( \n"; 
		 cout << "Better luck next time :) \n\n";
         GameOver = true;
		 draw=true;
      }
      return GameOver;
   }
};

class Memory_Game
{
	vector<vector<string>> user_matrix;
	// 2D vector to store user matrix i.e. the matrix which is printed again and again
	vector<vector<int>> solution_matrix;
	// 2D vector to stoe solution matrix i.e. the matrix which contains the solutions
	int difficulty;
	int score;
	/*difficulty to store difficulty level which user wants
	  score to store the user score*/
    public:
	string player_name; //stores player name 
	
	Memory_Game() // default constructor to intialise score
	{
		score=0;
	}

	//function to set solution matrix randomly everytime the game is played
    void set_solMatrix()
	{
      srand(time(0)); // helps rand function to give random number for every program run 
        
		if(difficulty == 1)//checks difficulty 
		{
			for(int i=0;i<5;i++)
			{
				vector<int >temp; // used to stores rows of the solution matrix
				for(int j=0;j<5;j++)
				{
					int random=rand()%10 +1; // random now stores random number from 1-8;
					temp.push_back(random); // inserts random number to the temp
				}
				solution_matrix.push_back(temp); // inserts whole row into the solution matrix
			}
		}
		// if difficulty is hard than solution matric will be of 5*5 matrix
		else 
		{
			for(int i=0;i<6;i++)
			{
				vector<int >temp;
				for(int j=0;j<6;j++)
				{
					int random=rand()%12 +1;// random now stores random number from 1-10;
					temp.push_back(random);
				}
				solution_matrix.push_back(temp);
			}

		}
	}

    //function to display solution matrix
	void display_solMatrix()
	{
		cout<<"     ";
		for(int i=0;i<solution_matrix.size();i++)
		cout<<i+1<<" | "; // formatting design
		cout<<endl;
		cout<<" ";
		for(int i=0;i<30;i++)
		cout<<"-";
		cout<<endl;
		for(int i=0;i<solution_matrix.size();i++)
		{
			cout<<i+1<<"- |  ";
			for(int j=0;j<solution_matrix.size();j++)
			{
				cout<<solution_matrix[i][j]<<" | ";
			}
			cout<<endl;
		}
    cout<<endl;
	}
    
	//function to initialise userMatrix with '*'
	void set_userMatrix()
	{
		for(int i=0;i<solution_matrix.size();i++)
		{
			vector<string> temp;
			for(int j=0;j<solution_matrix.size();j++)
			{
                temp.push_back("*");
			}
			user_matrix.push_back(temp);
		}
	}
    
	//function to display userMatrix
	void display_userMatrix()
	{
		cout<<"      ";
		for(int i=0;i<user_matrix.size();i++)
		cout<<i+1<<" | ";
		cout<<endl;
		cout<<" ";
		for(int i=0;i<30;i++)
		cout<<"-";
		cout<<endl;
		for(int i=0;i<user_matrix.size();i++)
		{
			cout<<i+1<<"- |  ";
			for(int j=0;j<user_matrix.size();j++)
			{
				cout<<user_matrix[i][j]<<" | ";
			}
			cout<<endl;
		}
    cout<<endl;
	}

	//function to check if the user entered number is correct or not for a given position 
    bool check(int a, int i,int j)
	{
		if(a==solution_matrix[i][j]) 
		{
			if(solution_matrix[i][j]==10)// special condition to check 10
			user_matrix[i][j]="10";
			else
			user_matrix[i][j] = '0'+ a; 
			return true; 
		}
		else
		{
			if(solution_matrix[i][j]==10)
			user_matrix[i][j]="10";
			else
			user_matrix[i][j] = '0'+ solution_matrix[i][j];
			return false;
		}
	}

	//start of the game
	void start()
	{
		cout << "-=WELCOME  TO=-\n";
        cout << "-=Memory Game=-\n";
        cout << "---------------"<< endl;
        cout << "Enter Player Name:\n";
        cin  >> player_name;
		cout << "Select your difficulty Level:\n";
		cout << "Press 1 for easy: \nPress 2 for hard:\n";
		cin  >> difficulty;
		set_solMatrix();
		cout<<"Lets check your memory :\n";
		cout<<"Try to remember all the number at correct position:\n ";
		display_solMatrix();
		int n;
		cout<<"Press 1 to start the game:\n";
		cin>>n;
		if(n!=1) // if user doesn't enter 1
		{
			cout<<"\nPress 1 for exit:\n";
		    cout<<"Press any other number key to start Memory game again:\n";
			int s;
			cin>>s;
			if(s==1)
			exit(0);
			else
			start();
		}
		else
		{
			system("CLS"); //this function clears the screen
			set_userMatrix();//function set_userMatrix called
			for(int i=0;i<user_matrix.size();i++)
			{
				for(int j=0;j<user_matrix.size();j++)
				{
					display_userMatrix(); //displaying matrix after everytime user enter number
					cout<<"What was the number at position ("<<i+1<<","<<j+1<<") :\n";
					int a;
					cin>>a;
					if(check(a,i,j))
					{
						score+=10;
						cout<<"Correct answer:\nScore is : ";
						cout<<score<<endl;
						cout<<"*******************************************\n";
					}
					else
					{
						cout<<"Wrong answer\n";
						cout<<"Score is : "<<score<<endl;
						cout<<"*******************************************\n";
					}
				}
			}
			cout<<"\n***********--Well PLayed "<<player_name<<"--************\n";
			cout<<"Your final score is : "<<score<<endl<<endl;
		}
	}
};

class High_Low
{
    int number;
    int score,chances,chanscor,totchan,guess;
    public:
	string player_name;

    /*number to store the computer generated number which user has to guess
	  score to store score of the player
	  chanscore to store the score per chance
	  totchan to store total chance a player has to guess the number
	  guess to store guess user number guess
	  player_name to store players name*/

    High_Low()//default constructor to initialise score chances and total chances
    {
        score=0;
        chances=0;
        totchan=7;
    }

	//start of the game
    void start()
    {
         system("CLS");
         cout<<"Welcome to the High/Low game.\n";
		 cout<<"Enter your Name:\n";
		 cin>>player_name;
         cout<<"I will pick a random number from 0 to 100.\n";
         cout<<"You must try to guess the number.\n";
         srand(time(0));
         number=(int)(rand()%100);
         chanscor=100/totchan;  //score for each successful chance
         
		 //loop to get number from user again and again
		 do
         {
            cout<<"What is your guess? (0 to 100) \n";
            //takes the guess from user
			cin>>guess;
            if((guess<0)||(guess>100)) //condition to check guess is high or low or equal to number
            {
	           cout<<"Sorry, but your guess "<<guess<<" must be from 0 to 100.\n";
            }
            else if(guess < number)
            {
	           cout<<guess<<" is low.Try a higher number.\n";
            }
            else if(guess > number)
            {
	           cout<<guess<<" is high.Try a lower number.\n";
            }
            else		//if correct number is guessed
            {			//number is correct, and the "do" loop will end below
	           cout<<guess<<" is correct. Congratulations!\n";
	           score=chanscor*(totchan-chances);   //score calculated for number of chances left
	           cout<<"Your score is "<<score<<endl;
               break;
            }
            chances++; //increases the chances after every turn
            if(guess!=number)
	        cout<<"Now you have "<<totchan-chances<<" chances left.\n"<<endl;
            if(chances==totchan) // if chances are over loops get break
	        { 
               cout<<"Only "<<totchan<<" chances are allowed.Better luck next time\n";
	           cout<<"The actual number was "<<number<<endl;
	           break;
	        }
            }while (guess!=number); /* loop continues till number is not equal 
			                           to guess or chances finishes*/
            cout<<"Thank you for playing \n\n"<<player_name<<endl;
    }
};

class Quiz
{
   int QNO,totques;
   public:
   string playername;

   /*QNO to store the question number
     totques to store total number of question asked to player
	 playername stores the name of player*/
   
   //default constructor to initialise QNO and totques
   Quiz()
   {
   	QNO=30;
   	totques=10;
   }

   //start of the game
   void start()
   {
    ifstream fins("Quiz.txt"); //open Quiz file to get the questions from it
	ofstream output("NewText.txt"); //open newText file to store the questions and answer of user
	string text;
	string option1, option2, option3, option4,option,correct,category;
	int score = 0;
	int arr[QNO];

	/*
	  text to store the text from quiz file
	  option1 to store option 1 from question
	  option2 to store option 2 from question
	  option3 to store option 3 from question
	  option4 to store option 4 from question
	  option to get option from player
	  correct to store correct option from the quiz file
	  category to store the category from the quiz file
	  score to store the score of the player
	  arr to store the line number of every question
	*/

	if(!fins.is_open())//checks if file is opened or not
	{
		cout<<"Quiz File Can't Be OPENED\n";
	}
	if(!output.is_open())
	{
		cout<<"NewText File Can't Be CREATED\n";
	}

	Display();//function display called
	
	for (int i = 0; i < 30; i++)//loop to store 1,11,21,31,.. to arr
	{
		arr[i] = 10 * i + 1;
	}
	
	//loop to ask questions again and again
	for (int j = 0; j < totques; j++)
	{
		srand(time(NULL));
		int x = rand()%3;
		int loc = (3 * j) + x;
	    
		//loop to get the pointer to a random question
		for (int i = arr[3*j]; i < arr[loc]; i++)
		{
			string empty;
			getline(fins, empty);
		}

        /*loop for next 10 lines to store question and options*/
		for (int i = 1; i <= 10; i++)
		{
			getline(fins, text);// get the line from QUIZ file
			
			if(i==1) //if it is line 1 it has question
			{
			  cout<<"Q"<<j+1<<") "<<text;
			  output<<"\nQ"<<j+1<<") "<<text<<endl;
			}
			
			if(i==2)//line 2 is blank space so just need to get pointer to next line
			{
				output<<text<<endl;	
			}
			
			//line 3 contains option1
			if(i==3)
			option1 = text;
			
			//line 4 contains option2
			if(i==4)
			option2 = text;
			
			//line 5 contains option3
			if(i==5)
			option3 = text;
			
			//line 6 contains option4
			if(i==6)
			option4 = text;
			
			//line 2 is blank space so just need to get pointer to next line
			if (i>1 &&  i<= 7)
				cout << text << endl;
            
			//line 8 contains coorect answer
			if (i == 8)
				correct = text.substr(0, 40);

			//line 9 contains category
			if (i == 9)
				category = text.substr(0, 40);
		}
        
		//function asked called
		asked(option, option1, option2, option3, option4, correct, category,output,&score);
		
		//loop to get the pointer to next question
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		{
			for (int i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
				string empty;
				getline(fins, empty);
			}
		}
        
		//clear the screens after every questions
		system("cls");
	}
	output<<"\n You got "<< score/4<<" correct answer with total score : "<<score<<" out of 40 ";
	
	//closes the file after the game
	fins.close();
	output.close();

	//to show the result new text is opened
	ifstream out("NewText.txt");
	string read;//to contain line from newText
	
	//to print line on the console from the newText which contains result
	while(getline(out,read))	
	{
		cout<<read<<endl;
	}
	
	system("pause");
   }

   //function to get name and ask user to start
   void Display()
	{
		cout<<"Enter your name     :\n";
		cin>>playername;
		cout<<"1) 4 MARKS WILL BE AWARDED FOR CORRECT     \n";
		cout<<"2) NO MARKS WILL AWARDED FOR INCORRECT     \n";
		cout<<"3) SCORE CARD WILL BE GIVEN AT END         \n";
		system("pause");
		system("cls");				
	}

//asked function checks if the player entered correct answer
//also prints the result in newText
void asked(string option,string option1,string option2,string option3,string option4,string correct,string category,ofstream& fp,int *score)
{
	cout << "Your Option : ";
	cin >> option;
	
	//changes lowercase to uppercase
	transform(option.begin(), option.end(), option.begin(), ::toupper);
	option.append(")");
	
	fp<<category<<endl;
	
	//checks if option is correct or not
	if (option[0] == correct[0])
	{
		if (option[0] == option1[0])
			fp << " Your entered correct answer  : " << option1 << endl;
		if (option[0] == option2[0])
			fp << " Your entered correct answer  : " << option2 << endl;
		if (option[0] == option3[0])
			fp << " Your entered correct answer  : " << option3 << endl;
		if (option[0] == option4[0])
			fp << " Your entered correct answer  : " << option4 << endl;
			
			//if answer is correct scorre gets incremented
			*score += 4;
			fp<<" You are awarded 4 marks for this correct answer "<<endl;
	}

	//if answer is not correct than correct answer is printed in newText 
	else
	{
		//if correct
		string correctanswer;
		if (correct[0] == option1[0])
			correctanswer = option1;
		if (correct[0] == option2[0])
			correctanswer = option2;
		if (correct[0] == option3[0])
			correctanswer = option3;
		if (correct[0] == option4[0])
			correctanswer = option4;

		string wronganswer;
		
		//if wrong
		if (option[0] == option1[0])
			wronganswer = option1;
		if (option[0] == option2[0])
			wronganswer = option2;
		if (option[0] == option3[0])
			wronganswer = option3;
		if (option[0] == option4[0])
			wronganswer = option4;

		fp << " You entered     : " << wronganswer << endl;
		fp << " Correct answer  : " << correctanswer << endl;
		fp << " You are awarded 0 marks for this wrong answer "<<endl;
		
	}
		fp<<" -----------------------------------------------------------------------------\n";		
		fp<<" -----------------------------------------------------------------------------\n";

}
};

class Rules
{
	int ans;
	//to store the response of the user
    public:
    
	//default constructor
	Rules()
	{
        cout<<"Which game rules you want know:\n\n";
		cout<<"Press 1 for tic tac toe********\n";
		cout<<"Press 2 for Memory Game********\n";
		cout<<"Press 3 for High Low   ********\n";
		cout<<"Press 4 for Quiz       ********\n";
		cin>>ans;
		if(ans==1)
		{
			tictactoe();
		}
		else if(ans == 2)
		{
			MemoryGame();
		}
		else if(ans == 3)
		{
			HighLow();
		}
		else if(ans == 4)
		{
			Quiz();
		}
		else
		{
            cout<<"Wrong input:(\n";
			cout<<"Start again and enter correct input this time:\n";
			exit(0);   
		}
	}

    void tictactoe()
    {
       cout<<"******************** RULES FOR TIC-TAC-TOE ********************\n";
       cout<<"1. The game is played on a grid that's 3 squares by 3 squares.\n";
       cout<<"2. You are X, your friend (or the computer in this case) is O.\n";
       cout<<"   Players take turns putting their marks in empty squares.\n";
       cout<<"3. The first player to get 3 of her marks in a row (up, down,\n";
       cout<<"   across, or diagonally) is the winner.\n";
       cout<<"4. When all 9 squares are full, the game is over. If no player\n";
       cout<<"   has 3 marks in a row, the game ends in a tie.";
	   cout<<"5. If you enter wrong input your turn will be cancelled\\n";
    }

    void MemoryGame()
    {
        cout<<"******************** RULES FOR MEMORY GAME ********************\n";
        cout<<"1. Player will have to memorize the whole matrix.\n";
        cout<<"2. Player will be asked if he wants to play in easy mode or hard\n";
        cout<<"   mode.Easy mode has 4x4 matrix and hard mode has 5x5 matrix.\n";
        cout<<"3. Player would be asked what was the number at different positions\n";
        cout<<"   and user has to tell the number.\n";
        cout<<"4. Correct answer will reward to +10 in the score.\n";
        cout<<"5. Wrong answer will have no increase in score.\n";
    }

    void HighLow()
    {
        cout<<"******************** RULES FOR HIGH LOW ********************\n";
        cout<<"1. Computer will think of a number from 1-100.\n";
        cout<<"2. Player has to guess the number.\n";
        cout<<"3. If the guess of the is lesser than the than computer will\n";
        cout<<"   print guess is low or if it is on higher end than computer\n";
        cout<<"   print guess is high.";
        cout<<"4. PLayer has total of 7 chances and the lesser chances he uses\n";
        cout<<"   higher the score he will get.\n";
    }

    void Quiz()
    {
        cout<<"******************** RULES FOR QUIZ ********************\n";
        cout<<"1. PLayer will be asked various questions for various \n";
        cout<<"   categories.\n";
        cout<<"2. If the player chooses correct option than he will be\n";
        cout<<"   awarded +4 score.";
        cout<<"3. There will be total of 10 questions asked and the\n";
        cout<<"   score and result will be shown at the end.\n";   
    }
};

class finish
{
	TicTacToe *finish1;
	Memory_Game *finish2;
	High_Low *finish3;
	Quiz *finish4;
	static map<string,vector<string>> names;
	int ans;

	/*
	  map to store name of the players with there respective game
	  finish1 pointer to finish tictactoe game and store players name
	  finish2 pointer to finish memory game and store player name
	  finish3 pointer to finish high/low game and store player name
	  finish4 pointer to finish Quiz game and store player name
	  ans to store answer of the of user to exit or play game again
	*/

    public:

    //default constructor
	finish(){}
    
	//function for finishing tictactoe
	void tictactoe(TicTacToe *obj)
	{
        finish1 = obj;
		
		//storing the players name in map
		names["TIC-TAC-TOE"].push_back(obj->player1);
		names["TIC-TAC-TOE"].push_back(obj->player2);

		//asking player to play again,see names or to exit
		cout<<"Press 1 to see the Players name:\n";
		cout<<"Press 2 to go to main menu:\n";
		cout<<"Press 3 to exit:\n";
		cin>>ans;
		if(ans == 1)
		{
			//loop to traverse every element of map
			//this is a special loop called for ranged loops
			for(auto &i : names)
			{
               auto &game=i.first; // storing game name
               auto &name=i.second; // storing player name
			   cout<<"Name of the Players are in "<<game<<": \n";
			   
			   //loop to print all the names that is stored in vector
			   for(int i=0;i<name.size();i++)
			   {
                   cout<<i+1<<") "<<name[i]<<endl;
			   }
			}
			cout<<"\nPress 1 for exit:\n";
			cout<<"Press 2 to go to main menu:\n";
			cin>>ans;
			if(ans ==1)
			{
				exit(0); // function used to exit the program
			}
		}
		else if(ans == 3)
		{
            exit(0);
		}
	}
    
	//function for finishing memorygame
	void memorygame(Memory_Game *obj)
	{
		finish2 = obj;
		//storing name
		names["Memory-Game"].push_back(obj->player_name);

		//asking player to play,see names,or exit
        cout<<"Press 1 to see the Players name:\n";
		cout<<"Press 2 to go to main menu:\n";
		cout<<"Press 3 to exit:\n";
		cin>>ans;
		if(ans == 1)
		{
			for(auto &i : names)
			{
               auto &game=i.first;
               auto &name=i.second;
			   cout<<"Name of the Players are in "<<game<<": \n";
			   for(int i=0;i<name.size();i++)
			   {
                   cout<<i+1<<") "<<name[i]<<endl;
			   }
			}
			cout<<"\nPress 1 for exit:\n";
			cout<<"Press 2 to go to main menu:\n";
			cin>>ans;
			if(ans == 1)
			{
				exit(0);
			}
		}
		else if(ans == 3)
		{
            exit(0);
		}
	}
    
	//function to finsih high low game
	void highlow(High_Low *obj)
	{
		finish3 = obj;
		names["High-Low"].push_back(obj->player_name);
		cout<<"Press 1 to see the Players name:\n";
		cout<<"Press 2 to go to main menu:\n";
		cout<<"Press 3 to exit:\n";
		cin>>ans;
		if(ans == 1)
		{
			for(auto &i : names)
			{
               auto &game=i.first;
               auto &name=i.second;
			   cout<<"Name of the Players are in "<<game<<": \n";
			   for(int i=0;i<name.size();i++)
			   {
                   cout<<i+1<<") "<<name[i]<<endl;
			   }
			}
			cout<<"\nPress 1 for exit:\n";
			cout<<"Press 2 to go to main menu:\n";
			cin>>ans;
			if(ans ==1)
			{
				exit(0);
			}
		}
		else if(ans == 3)
		{
            exit(0);
		}
	}
    
	//function to finish quiz game
	void quiz(Quiz *obj)
	{
		finish4 = obj;
		names["Quiz"].push_back(obj->playername);
		cout<<"Press 1 to see the Players name:\n";
		cout<<"Press 2 to go to main menu:\n";
		cout<<"Press 3 to exit:\n";
		cin>>ans;
		if(ans == 1)
		{
			for(auto &i : names)
			{
               auto &game=i.first;
               auto &name=i.second;
			   cout<<"Name of the Players are in "<<game<<": \n";
			   for(int i=0;i<name.size();i++)
			   {
                   cout<<i+1<<") "<<name[i]<<endl;
			   }
			}
			cout<<"\nPress 1 for exit:\n";
			cout<<"Press 2 to go to main menu:\n";
			cin>>ans;
			if(ans ==1)
			{
				exit(0);
			}
		}
		else if(ans == 3)
		{
            exit(0);
		}
	}
};
//initialising static map
map<string,vector<string>> finish:: names ={};

class driver
{
    TicTacToe * myGame1;
    Memory_Game * myGame2;
    High_Low * myGame3;
    Quiz * myGame4;
	finish *finish1;
    Rules *rul;
	/*
	  pointers whicher later allocated memory to play the games
	*/

    public:
    
	//default constructor
    driver()
	{
		//exception handling if memory is not allocated
		try
		{
	        finish1 = new finish;
		}
		catch(bad_alloc &ba)
		{
			cout<<"Sorry memory could not be allocated\n";
			cout<<"Game could not be further progressed\n";
			cout<<"Try Again :(\n";
			exit(0);
		}
	}

    void tictactoe()
    {
		try
		{
           myGame1=new TicTacToe;
           myGame1->start();
           finish1->tictactoe(myGame1);
		}
		catch(bad_alloc &ba)
		{
			cout<<"Sorry memory could not be allocated\n";
			cout<<"Game could not be further progressed\n";
			cout<<"Try Again :(\n";
			exit(0);
		}
    }

    void memoryGame()
    {
		try
        {
            myGame2=new Memory_Game;
	        myGame2->start();
	        finish1->memorygame(myGame2);
		}
		catch(bad_alloc &ba)
		{
			cout<<"Sorry memory could not be allocated\n";
			cout<<"Game could not be further progressed\n";
			cout<<"Try Again :(\n";
			exit(0);
		}    
    }

    void highLow()
    {
		try
		{
            myGame3=new High_Low;
            myGame3->start();
	        finish1->highlow(myGame3);
		}
		catch(bad_alloc)
		{
			cout<<"Sorry memory could not be allocated\n";
			cout<<"Game could not be further progressed\n";
			cout<<"Try Again :(\n";
			exit(0);
		}
    }

    void quiz()
    {
		try
		{
            myGame4=new Quiz;
            myGame4->start();
		    finish1->quiz(myGame4);
		}
		catch(bad_alloc)
		{
			cout<<"Sorry memory could not be allocated\n";
			cout<<"Game could not be further progressed\n";
			cout<<"Try Again :(\n";
			exit(0);
		}
    }

	void rule()
	{
        try
		{
            rul=new Rules;
			cout<<endl;
			system("PAUSE");
		}
		catch(bad_alloc)
		{
			cout<<"Sorry memory could not be allocated\n";
			cout<<"Game could not be further progressed\n";
			cout<<"Try Again :(\n";
			exit(0);
		}
	}
};

class Welcome
{
    int game;
    driver obj;
	/*
	  game to ask which game user want to play
	  obj is a driver object 
	*/

    public:
	
	//default constructor
    Welcome()
    {
        cout<<"******   Welcome to our gaming arcade       ******\n";
        
		//checks which game user wants to play
		check_game();
    }

	//function check game
    void check_game()
    {
		cout<<"*****    Which game would you like to Play:  *****\n";
        cout<<"****     Press 1 ---- Tic Tac Toe!            ****\n";
        cout<<"***      Press 2 ---- Memory Game!             ***\n";
        cout<<"**       Press 3 ---- High Low!                 **\n";
        cout<<"*        Press 4 ---- Quiz!                      *\n";
		cout<<"         Press 5 ---- Rules of the games          \n";
        cin>>game;
		
		//according to user driver function is called
        if(game==1)
        {
            obj.tictactoe();
        }
        else if(game==2)
        {
            obj.memoryGame();
        }
        else if(game==3)
        {
           obj.highLow();
        }
        else if(game==4)
        {
           obj.quiz();
        }
		else if(game==5)
		{
			obj.rule();
		}
		else
		{
			cout<<"Wrong input:(\n";
			cout<<"Start again and enter correct input this time:\n";
			exit(0);
		}
    }

};

//Main function of the program
int main()
{
	try
	{
        while(true)
     	{
           system("CLS");
	       Welcome obj;
	    }
	}
	catch(...)
	{
		cout<<"Some sort of exception has occured\n";
		cout<<"Sorry for the inconvince\n ";
		cout<<"Plz try again\n";
	}
    return 0;
}
