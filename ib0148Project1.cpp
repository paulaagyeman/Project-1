#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main()
{
//header
 cout << "+-----------------------------------------------------+"<< endl;
 cout << "       Computer Science and Engineering" << endl;
 cout << "        CSCE 1030 - Computer Science I" << endl;
 cout << "  Paula Agyeman (pga0026) paulaagyeman@my.unt.edu\n"<< "  Nuria Huerta del Angel (nh0354) nuriahuertadelangel@my.unt.edu\n" << "  Arnav Saxena (as2360) arnavsaxena@my.unt.edu \n"<< "  & Isaias Barrera (ib0148) isaiasbarrera@my.unt.edu\n";
 cout << "+----------------------------------------------------+"<< endl;
// variables used
	int points = 100;
	enum userChoice {displayLeft = 1, displayRight = 2, Guess = 3, Change = 4, Exit = 5};
	int oldPoints;
	int guess;

// allows us to get the right name
	string userName;
    bool flag = false;
    while (!flag) {
        cout << "Enter your name: ";
        getline(cin, userName);
        flag = true;
        for (int i = 0; i < userName.length(); i++) {
            if (!isalpha(userName[i]) && !isspace(userName[i])) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << "Error, the name can only have letters and white spaces, please enter again." << endl;
        }
    }
    cout << "These are the game rules. Try to guess in between the bounds of the hidden integers. Press '1' to display the lower bound, press '2' to display the upper bound (you can only display one bound), press '3' to guess, press '4' to change the bounds, and press '5' to exit. "<< endl;

// This generates the random numbers
	int rand1;
	int rand2;
	srand(time(NULL));
	do{
		rand1 = (rand() % 101) + 100;
		rand2 = (rand() % 101) + 100;
	} while(rand1>rand2);

	int negative1 = -1;
	int negative2 = -1;

	cout << "Here are the two hidden integers:" << endl;
	cout << negative1 << "      " << negative2 << endl;

//this switch case allows the user to have different choices
	int userChoice;
	cout << "What is your next move?" << endl;
	cin >> userChoice;
	while (userChoice != 5) {
        switch(userChoice)
        {
			case displayLeft:
				cout << rand1 << "      " << negative2 << endl;
				cout << "A correct guess will earn 1 point and a wrong guess will lose 10 points." << endl;
				break;
			case displayRight:
				cout << negative1 << "      " << rand2 << endl;
				cout << "A correct guess will earn 1 point and a wrong guess will lose 10 points." << endl;
				break;
			case Guess:
				cout << "Please guess a number between the two random numbers:" << endl;
				cin >> guess;
				//if ((userChoice == !1) || (userChoice == !2)){
				    if ((guess > rand1) && (guess < rand2)){
			            points = points + 1;
			        	cout << "Correct, you have: " << points << " points." << endl;
				    }
				    else {
				        points = points - 10;
				        cout << "Incorrect, you have been deducted points." << endl;
				        cout << "Your point total is: " << points << " points." << endl;
				    }
				break;
				//}
				//else {
				//points = points - 10;
				cout << points << endl;
				//}
				break;
			case Change:
			    srand(time(NULL));
            	do{
		        rand1 = (rand() % 101) + 100;
		        rand2 = (rand() % 101) + 100;
            	} while(rand1>rand2);
				points = points - 1;
				cout << "New random numbers have been generated. You now have " << points << "points" << endl;

				break;
			default:
                cout << "Error, you did not enter any of the options provided. Enter a game key to try again. " << endl;
				break;
            
        }
	
	cin >> userChoice;
	}
	cout << "Thank you for playing! You finished with a total of " << points << " points." << endl;
	return 0;
	}


