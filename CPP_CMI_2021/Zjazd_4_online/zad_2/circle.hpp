#ifndef CIRCLE_HPP
#define CIRCLE_HPP

struct point
{
	int x;
	int y;
};

struct circle
{
	int radius;
	point center;
};

void set_params_from_input_or_default(circle *c1, circle *c2, int argc, char *argv[]);

int count_intersections(circle c1, circle c2);

bool is_the_same_center_and_radius(circle c1, circle c2);

int count_points_of_intersections(circle c1, circle c2);

void print_intersection_result(int points_of_intersection, circle c1, circle c2);

void print(circle c);

#endif
