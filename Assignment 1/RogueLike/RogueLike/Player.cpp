#include "Player.h"

Player::Player(Graphics^ canvas, Random^ rand, array<String^>^ movingFilePath, int formWidth, int formHeight) 
	: Sprite(canvas, rand, movingFilePath, formWidth, formHeight)//contructor that will also pass variables to the parent class Sprite
{
	//initialising all the vairibles
	numFrame = 3;
	frameWidth = currentImage->Width / numFrame;
	frameHeight = currentImage->Height;
	worldPosition = gcnew Point(900, 600);
	position = gcnew Point(300, 226);
	health = 100;
	setCollisionFrame();
}

void Player::moveOffCenter()//move the player of centered
{
	//moving the position variable will make the player character move on the form itself which usually is locked to the center of the form 
	checkBoundries();
	setCollisionFrame();
	currentImage = movingImages[imageDirection];
	position->X += (VELOCITY * velocityDirection[imageDirection]->X);
	position->Y += (VELOCITY * velocityDirection[imageDirection]->Y);
	worldPosition->X += (VELOCITY * velocityDirection[imageDirection]->X);
	worldPosition->Y += (VELOCITY * velocityDirection[imageDirection]->Y);
}

void Player::setCollisionFrame()//setting the player's colllsion frame
{
	left = worldPosition->X;
	right = (worldPosition->X + frameWidth) - 40;
	top = worldPosition->Y - 10;
	bottom = (worldPosition->Y + frameHeight) - 35;
}