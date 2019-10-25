/*
Lane Pruisner
C++ Fall 2019
Due October 24, 2019
Lab #5 Number Guessing Game
Description: Write a number-guessing game in which the computer selects a random
number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
the end of each game, users should be told whether they won or lost, and then be asked
whether they want to play again. When the user quits, the program should output the
total number of wins and losses. To make the game more interesting, the program
should vary the wording of the messages that it outputs for winning, for losing, and for
asking for another game. Create 10 different messages for each of these cases, and use
random numbers to choose among them. This application should use at least one Do-
While loop and at least one Switch statement. Write your C++ code using good style and
documenting comments. You should use functions in your code as well. Your source
code file should be called Lab5.cpp
*/
#include <iostream>
#include <iomanip>

using namespace std;
void correctAns(); //void function
void incorrect(); //void function
void playagain();//void function

int main()//main function
{
	int playanother;// integer input to play another game
	int gamewon = 0;//integer that is used to count how many games the user has won
	int game_loss = 0;//integer that is used to count how many games the user lost
	int userinput;// integer used for the user's input
	srand(unsigned int(time(NULL)));// used for random number
	int RandomNumber = rand() % 101;//integr that the user is guessing between 0-100
	bool Guessgame = true;//Guess game function runs as long as the bool value stays true
	do// Do while function that is used for the main portion of the game
	{
		cout << "Welcome to the Number Guessing Game! Please enter in a number between 0-100: ";//Outputs introduction sentence before every game
		for (int guesses = 19; guesses >= 0; guesses--)//For loop that counts how many guesses the user has left
		{
			cin >> userinput;// Where the user inputs their guesses
			if (!cin)// If the user inputs a letter into the program, the program automatically exits and outputs that the input is invalid
			{
				cout << "Input is invalid: Exiting Game";
				return 2;
			}
			if (userinput == RandomNumber)//if statement for when the user guesses correctly
			{
				correctAns();//void function for all the winning statements
				playagain();//void function for all the play again statements
				guesses = -10;// sets guesses to -10 so the program is able to exit the loop
				gamewon++;// adds a game won to the counter
				cin >> playanother; // integer input so the player can choose to play another game
				switch (playanother)//Switch statement to play another game with two choices
				{
				case 1: Guessgame = true;// press one to run guess game again
					break;
				case 2: Guessgame = false;// press two to quit
					cout << "You won " << gamewon << " games, " << "You lost " << game_loss << " games.";// outputs how many games they won and lost
					break;
				default: cout << "Input is invalid: Exiting game";//outputs invalid statement if the user does not choose one or two
					return 1;// ends program
					break;

				}
				
			}
			if (userinput != RandomNumber && guesses > 0) //If statement when user does not guess right while guesses is above 0
			{
				incorrect();// runs the void function for the incorrect statements
				cout << "You have " << guesses << " guesses left: ";// outputs how many guesses they have left
			}
			if (guesses == 0)// if statement when the user runs out of guesses
			{
				playagain();//runs void functions for the play again statements
				game_loss++;// adds to games the user lost
				cin >> playanother; // integer input for the user to play again
				switch (playanother)//switch statemnet to play again
				{
				case 1: Guessgame = true;// runs guess game again
					break;
				case 2: Guessgame = false;// quits game
					cout << "You won " << gamewon << " games, " << "You lost " << game_loss << " games.";//outputs how many games the user lost and won
					break;
				default: cout << "Input is invalid: Exiting game";// if the user does not input one or two the program exits
					return 1;
					break;
				}
				
			}
		
		}
	
	} while (Guessgame);//runs while guess game is true
	return 0;
}

void correctAns()//correct answer statements
{
	int winround = rand() % 10+1;// outputs random integer to output random statements
	
	switch (winround)
	{
	case 1: cout << "Congrats you won! ";
		break;
	case 2: cout << "Woope doo you tough guy you won! ";
		break;
	case 3: cout << "Holy cow you smart fella you won! ";
		break;
	case 4: cout << "Golly G ya won! ";
		break;
	case 5: cout << "Next time you'll lose but hey you won! ";
		break;
	case 6: cout << "What the heck bro, you finally won! ";
		break;
	case 7: cout << "Bro, you are so dope you won! ";
		break;
	case 8: cout << "You lost... sike you won! ";
		break;
	case 9: cout << "Alright Alright Alright you won! ";
		break;
	case 10: cout << "Welp you won cool ";
		break;
	}
	
}
void incorrect()//incorrect answer statments
{
	int loseround = rand() % 10 + 1;// outputs random integer to output random statements
	switch (loseround)
	{
	case 1:cout << "Ah poopie you lost! ";
		break;
	case 2: cout << "You lost! ";
		break;
	case 3: cout << "You lost you losing loser! ";
		break;
	case 4: cout << "why'd you lose? ";
		break;
	case 5: cout << "congrats you lost! ";
		break;
	case 6: cout << "You looooooossstttt, you lost! ";
		break;
	case 7: cout << "What the heck bro guess it right! ";
		break;
	case 8: cout << "Holy cow you are dumb, ya loser! ";
		break;
	case 9: cout << "Crimney you lost! ";
		break;
	case 10: cout << "Bro you are so dumb, you lost ";
		break;
	}

}
void playagain()// play again statements
{
	
	int varplayagain = rand() % 10 + 1;// outputs random integer to output random statements

	switch (varplayagain)
	{
	case 1: cout << "Would you like to play another game? ";
		break;
	case 2: cout << "Oi mate, play another? ";
		break;
	case 3: cout << "I dare you to play again. ";
		break;
	case 4: cout << "Do it, Do it press one please. ";
		break;
	case 5: cout << "Hey fella, Play another game please. ";
		break;
	case 6: cout << "Wazzzzup, play another mate? ";
		break;
	case 7: cout << "What momma dont know won't hurt her, play another? ";
		break;
	case 8: cout << "Hey dude, itd be cool if you played another game. ";
		break;
	case 9: cout << "Come on little fella, play another to make me happy. ";
		break;
	case 10: cout << "If you press 2, a puppy dies, play another? ";
		break;
	}
	cout << "Enter 1 to play another, 2 to quit: ";// asks user to enter 1 to play again and 2 to quit
}