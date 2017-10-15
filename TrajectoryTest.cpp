// TrajectoryTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <windows.h>

#define PI 3.14159265

std::pair<float, float> calcAngAndVel(float angle, float prev);

float dist; //meters

int main()
{
	std::cout << "Target distance in meters: ";
	std::cin >> dist;

	std::pair<float, float> result = calcAngAndVel(PI / 4, PI / 2);

	std::cout << "Angle = " << result.first * 180 / PI << "\n";
	std::cout << "Velocity = " << result.second;

	Sleep(60000);
}

std::pair<float, float> calcAngAndVel(float angle, float prev)
{
	float vert = 6.8408;
	float vel = vert / sin(angle);
	float time = vert / 9.8;
	float horiz = (cos(angle) * vel);
	float deltaX = horiz * time;
	float diff = abs(prev - angle) / 2;

	if (deltaX < dist - 0.001)
		return calcAngAndVel(angle - diff, angle);
	else if (deltaX > dist + 0.001)
		return calcAngAndVel(angle + diff, angle);

	return std::make_pair(angle, vel);
}

