#include "cannonball.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "cannonball_viz.h"

double acclY(){
    return -9.81;
}

double velY(double initVelocityY, double time){
    double velY = initVelocityY + acclY() * time;
    return velY;
}


double posX(double initPositionX, double initVelocityX, double time){
    double posX = initPositionX + initVelocityX * time;
    return posX;
}


double posY(double initPositionY, double initVelocityY, double time){
    double posY = initPositionY + initVelocityY * time + 0.5 * acclY() * pow(time, 2);
    return posY;
}

void printTime(double time){
    int hours = time / 3600;
	time -= 3600 * hours;
	int minutes = time / 60;
	time -= minutes * 60;
	cout << hours << " hours, " << minutes << " minutes and " << time <<" seconds.";
}
double flightTime(double initVelocityY){
    double time = -2 * initVelocityY/acclY();
    return time;
}

double getUserInputTheta(){
    double theta = 0;
    cout << "Give angle: ";
    cin >> theta;
    return theta;
}

double getUserInputAbsVelocity(){
    double vel = 0;
    cout << "Give velocity: ";
    cin >> vel;
    return vel;
}

double degToRad(double deg){
    double pi = atan(1)*4;
    double rad = deg * pi/180;
    return rad;
}

double getVelocityX(double theta, double absVelocity){
    double velocityX = absVelocity * cos(theta);
    return velocityX;
}
double getVelocityY(double theta, double absVelocity){
    double velocityY = absVelocity * sin(theta);
    return velocityY;
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velocityVector(2);
    velocityVector[0] = getVelocityX(theta, absVelocity);
    velocityVector[1] = getVelocityY(theta, absVelocity);
    return velocityVector;
}

double getDistanceTraveled(double velocityX, double velocityY){
    double time = -2 * velocityY / acclY();
    double distance = posX(0, velocityX, time);
    return distance;
}

double targetPractice(double distanceToTarget,
double velocityX,
double velocityY){
    double distance = getDistanceTraveled(velocityX, velocityY);
    double deviation = distance - distanceToTarget;
    return deviation;
}

bool checkIfDistanceToTargetIsCorrect(int distanceToTarget, double velocityX, double velocityY) {
    double error = targetPractice(distanceToTarget,velocityX,velocityY);
    if(abs(error) < 5) {
        return true;
    }
    else{
        return false;
    }
}

void playTargetPractice(){
    int distanceToTarget = randomWithLimits(1000, 100);
    cout << "Your target is " << distanceToTarget << " meters ahead. Give angle and initial velocity to hit. "
    "Give angle zero to end.\n";

    bool hit = false;
    int attempts = 10;
    double theta = 1.0;

    while(!hit && attempts > 0 && theta != 0.0){
        cout << "\n\nYou have " << attempts << " attempts left\n";
        theta = degToRad(getUserInputTheta());

        double absVelocity = getUserInputAbsVelocity();
        double velocityX = getVelocityX(theta, absVelocity);
        double velocityY = getVelocityY(theta, absVelocity);
        double deviation = targetPractice(distanceToTarget, velocityX, velocityY);
        bool hit = checkIfDistanceToTargetIsCorrect(distanceToTarget, velocityX, velocityY);

        cannonBallViz(distanceToTarget, 1000, velocityX, velocityY, 10);

        cout << "Your ball traveled for ";
        printTime(flightTime(velocityY));

        if(hit){
            cout << "\nBullseye, congratulations!";
            break;
        }
        else if (deviation > 0){
            cout << "\nYour attempt was " << abs(deviation) << " meters too long";
        }
        else{
            cout << "\nYour attempt was " << abs(deviation) << " meters too short";

        attempts--;
        if (attempts == 0){
            cout << "\nBetter luck next time!";
        }
        }
    }
}