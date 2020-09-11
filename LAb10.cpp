#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void playBlackJack();
int dealCards(int numberOfCards, string message);
void hit(int &playerScore);
void determineWinner(int humanScore, int houseScore);
int Random(int lowerLimit, int upperLimit);


int main(){

	   char keepPlaying = 'n';

	   do{
			 playBlackJack();
			 cout << "Do you want to play another hand (y/n)?" << flush;
			 cin >> keepPlaying;
	 } while(keepPlaying == 'Y' || keepPlaying == 'y');
	 return 0;
}

void playBlackJack(){

		 srand((int) time(0));

		 int person = dealCards(2, "Your Cards:");
		 cout << " = " << person << endl;
		 int house = dealCards(2, "Computers Cards:");
		 cout << " = " << house << endl;

		// Ask if human wants a hit and keep hitting...
		hit(person);
		cout << endl;

	   //Determine if computer takes a hit
	   while ((house <= 21) && (person <= 21))
	   {
			   if(person<house){
					 break;
				 }
			   house += dealCards(1, "The Computer takes a card ");
			   cout << endl;
		}
	   determineWinner(person, house);
}

void determineWinner(int humanScore, int houseScore){
		if (humanScore == 21)
			cout << "You have 21. You win!" << endl;
		else if ((humanScore < 21) && (humanScore > houseScore))
			cout << "You have the closer hand to 21. You win!" << endl;
		else
			if(houseScore>21&&humanScore<=21)
				cout<<"You win!!!!\n";
			else
				cout << "The computer wins, sorry try again." << endl;
}



int dealCards(int numberOfCards, string message){

	int return_value = 0;
	int value = 0;

	for (int i = 0; i < numberOfCards; i++){
		value = Random(1,10);
		cout << message << " " << value;
		if(numberOfCards)
			cout << " , ";
			return_value += value;
		}
	return return_value;

}


void hit(int &playerScore){
	char hit = 'y';


	while (hit == 'y' || hit == 'Y'){
		cout << endl;
		cout << "Do you want to hit?" << flush;
		cin >> hit;
		cout << endl;

		if (hit == 'y'){
			playerScore += dealCards(1,"You take a card "); // adds humanScore to dealCards()
			cout << "Your score at the moment is: " << playerScore << endl;
		}
		if (hit == 'n'){
			cout << "You decide to stand" << endl;
			cout << "Your score is: " << playerScore;
		}
		if (playerScore > 21){
			cout << "You have gone over 21, You Lose";
			hit = 'n';
		}
	}
}



int Random(int lowerLimit, int upperLimit){
//returns a random number within the given boundary
	return 1 + rand() % (upperLimit - lowerLimit + 1);
}
