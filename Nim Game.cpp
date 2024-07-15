#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int HUMAN = 1;
const int COMPUTER = 2;
int main()
{
	srand((unsigned)time(nullptr));
	int numberOfObject;
	int playerID = HUMAN;
	char ans;
	cout << "Would you like to go first (y for yes and other input for no)? ";
	cin >> ans;
	playerID = (ans == 'y') ? HUMAN : COMPUTER; 
		do{
			cout << "Enter the initial number of objects: ";
			cin >> numberOfObject;
			if (numberOfObject >= 2)
				break;
			cout << "Number of object must be greater than or equal to 2! Please try again." << endl;
		} while (true);
			cout << endl;
			int limitCount = numberOfObject - 1; 
			int removeCount, prevRemoveCount = 0; 
				while (numberOfObject > 0)
				{
					if (playerID == HUMAN)
					{
						cout << "It is your turn. ";
						do
						{
							cout << "Enter the number of objects to remove (1-" << limitCount
								<< "): ";
							cin >> removeCount;
							// check if the removeCount is valid
							if (removeCount >= 1 && removeCount <= limitCount)
								break;
							cout << "Invalid move. ";
						} while (true);
						prevRemoveCount = removeCount;
						numberOfObject -= removeCount;
						if (numberOfObject == 0)
						{
							cout << "Move accepted. You win. Congratulations!" << endl;
							break;
						}
						else
							cout << "Move accepted. The number of objects remains: " <<
							numberOfObject << endl;
						playerID = COMPUTER; // switch to computer player
					}
					else // computer turn
					{
						
							if (limitCount >= numberOfObject)
								removeCount = numberOfObject;
							else
								removeCount = rand() % limitCount + 1;
						cout << "It is the computer's turn. The computer removes " <<
							removeCount << " objects." << endl;
						prevRemoveCount = removeCount;
						numberOfObject -= removeCount;
						if (numberOfObject == 0)
						{
							cout << "Move accepted. Computer win. Congratulations!" << endl;
							break;
						}
						else
							cout << "The number of objects remains: " << numberOfObject <<
							endl;
						playerID = HUMAN; // switch to human player
					}
					cout << endl;
					// limitCount must not greater the number of remaining objects
					limitCount = ((prevRemoveCount * 2) > numberOfObject) ? numberOfObject :
						(prevRemoveCount * 2);
				}
}