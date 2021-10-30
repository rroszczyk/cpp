#include <iostream>
#include <climits>
#include <cmath>
#include "circle.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	circle c1 = {5, 0, 0};
	circle c2 = {5, 0, 0};

	set_params_from_input_or_default(&c1, &c2, argc, argv);

	int points_of_intersection = count_intersections(c1, c2);
	print_intersection_result(points_of_intersection, c1, c2);

	return 0;
}
