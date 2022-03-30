#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main()
{
	srand(unsigned(time(nullptr)));
	int menu = 1;
	while (menu != 0)
	{
		cout << "\n\nMenu:\n"
		"0) End\n"
		"1) Task 3 - Function-tests\n"
		"2) Task 4 - Target Practice\n"
		"3) Task 5 - Random-test\n"
		"4) Target Practice Game\n"
		"Choose (0-4): ";
		cin >> menu;
		cout << "\n";

		if(menu == 1){
			double initPositionY = 0;
			double initVelocityY = 25;

			double time = 2.5;
			double maxError = 0.01;
			double positionYRef = 31.84;
			double positionY = posY(initPositionY, initVelocityY, time);

			cout << "Oppgave 3c), Test:\n";
			testDeviation(positionYRef, positionY, maxError,
			"y-coord after 2.5 seconds");
		}

		else if (menu == 2){
			cout << "Give negative angle to end\n";
			double distanceToTarget = 100;
			while (true){
				double theta = degToRad(getUserInputTheta());
				if (theta < 0){
					break;
				}
				double absVelocity = getUserInputAbsVelocity();
				double velocityX = getVelocityX(theta, absVelocity);
				double velocityY = getVelocityY(theta, absVelocity);
				double deviation = targetPractice(distanceToTarget, velocityX,velocityY);
				cout << "Missed by " << deviation << " meters\n";
			}
		}

		else if (menu == 3){
			int upper = 0;
			cout << "Upper limit: ";
			cin >> upper;

			int lower = 0;
			cout << "Lower limit: ";
			cin >> lower;


			int random = randomWithLimits(upper, lower);
			cout << "Random number: " << random << "\n";
		}
		
		else if (menu == 4){
			playTargetPractice();
		}
	}
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
			if (abs(compareOperand - toOperand) <= maxError){
				cout << name << ": True\n";
			}
			else{
				cout << name << ": False\n";
			}
}