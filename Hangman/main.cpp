// Classic game Hangman

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
	system("title Hangman");

	// Formation of a list of answers to the riddle.
	vector<string> answers;
	answers.push_back("STEVENSON");
	answers.push_back("DEFOE");
	answers.push_back("DICKENS");
	answers.push_back("SWIFT");
	answers.push_back("ORWELL");

	// Random selection of a hidden word from a list of answers.
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(answers.begin(), answers.end());
	const string ANSWER_WORD = answers[0];

	// Information for the user. Displays up-to-date information about the letters used and the number of attempts remaining.
	string opened(ANSWER_WORD.size(), '-');
	string used = "";

	const int MISS_LIMIT = 10;
	int missCounter = 0;

	char guess; // User's attempt to guess a letter.

	// Game loop.
	while (missCounter < MISS_LIMIT && opened != ANSWER_WORD)
	{
		system("cls");

		// Header.
		cout << "Hello and welcome to the classic hangman game.\n\
The name of a famous writer is hidden here and you have only a few attempts to guess the word...\n\
...until you are hanged.\n";

		// Output of the current state of the game.
		cout << endl << "So far you have guessed the following letters: " << opened << endl;
		cout << "You have used the following letters: " << used << endl;
		cout << "Now, you have " << MISS_LIMIT - missCounter << " incorrect guesses left. You'll be hanged when it's gone.\n";

		// Request to player to make a move.
		cout << endl << "Enter your guess letter here: ";
		cin >> guess;
		guess = toupper(guess);
		if (used.find(guess) != string::npos)
		{
			cout << endl << "You've already guess this letter. Be careful next time.\n";
			system("pause");
			continue;
		}

		used = used + guess + ' '; // Updating the list of used letters.

		// Checking for a correct guess and updating the list of guessed letters.
		if (ANSWER_WORD.find(guess) != string::npos)
		{
			cout << endl << "Good! You guessed the letter.\n";
			for (int i = 0; i < ANSWER_WORD.length(); i++)
			{
				if (ANSWER_WORD[i] == guess)
				{
					opened[i] = guess;
				}
			}
			system("pause");
		}
		else
		{
			cout << endl << "Sorry! You have chosen the wrong letter.\n";
			++missCounter;
			system("pause");
		}
	}

	// Game result output.
	if (missCounter == MISS_LIMIT)
	{
		cout << endl << "You've been hanged!\nThe word was " << ANSWER_WORD << ".\n";
	}
	else
	{
		cout << endl << "The word was: " << opened << endl;
		cout << "Congratulations! You solved the riddle and survived.\n";
	}
	return 0;
}