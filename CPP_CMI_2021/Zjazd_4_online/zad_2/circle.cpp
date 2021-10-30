#include <iostream>
#include <climits>
#include <cmath>
#include "circle.hpp"

using namespace std;

void set_params_from_input_or_default(circle *c1, circle *c2, int argc, char *argv[])
{
	if (argc > 3)
	{
		*c1 = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};
	}
	else
	{
		*c1 = {5, 0, 0};
	}

	if (argc > 6)
	{
		*c2 = {atoi(argv[4]), atoi(argv[5]), atoi(argv[6])};
	}
	else
	{
		*c2 = {5, 0, 0};
	}
}

int count_intersections(circle c1, circle c2)
{
	int points_of_intersection;

	if (is_the_same_center_and_radius(c1, c2))
	{
		points_of_intersection = INT_MAX;
	}
	else
	{
		points_of_intersection = count_points_of_intersections(c1, c2);
	}

	return points_of_intersection;
}

bool is_the_same_center_and_radius(circle c1, circle c2)
{
	bool result;

	result = (c1.center.x == c2.center.x) && (c1.center.y == c2.center.y) && (c1.radius == c2.radius);

	return result;
}

int count_points_of_intersections(circle c1, circle c2)
{
	int radius_sum = c1.radius + c2.radius;
	int radius_diff = abs(c1.radius - c2.radius);
	double center_distance = sqrt(pow(c1.center.x - c2.center.x, 2) + pow(c1.center.y - c2.center.y, 2));

	int points_of_intersection;

	if (radius_sum == center_distance || radius_diff == center_distance)
	{
		points_of_intersection = 1;
	}
	else if (center_distance < radius_sum && center_distance > radius_diff)
	{
		points_of_intersection = 2;
	}
	else
	{
		points_of_intersection = 0;
	}

	return points_of_intersection;
}

void print_intersection_result(int points_of_intersection, circle c1, circle c2)
{
	cout << "\n\t Found \"";
	if (points_of_intersection == INT_MAX)
	{
		cout << "infinity";
	}
	else
	{
		cout << points_of_intersection;
	}
	cout << "\" points of intersections between:\n"
		 << endl;
	print(c1);
	print(c2);
}

void print(circle c)
{
	printf("Circle -> radius = %d \t| x = %d \t| y = %d\n", c.radius, c.center.x, c.center.y);
}
