#include "Node.h"

Node::Node()
{
	Name = "BLANK";
	x_coor = 0;
	y_coor = 0;
}

Node::Node(std::string name_in, int x_in, int y_in, std::vector<std::string> names_in)
{
	Name = name_in;
	x_coor = x_in;
	y_coor = y_in;
	names_list = names_in;
}

std::string Node::return_name()
{
	return Name;
}

int Node::return_x()
{
	return x_coor;
}

int Node::return_y()
{
	return y_coor;
}

std::vector<std::string> Node::return_linked()
{
	return names_list;
}

double Node::get_distance(Node partner_node)
{
	int partner_x;
	int partner_y;

	partner_x = partner_node.return_x();
	partner_y = partner_node.return_y();

	double x_dist{ 1.0 * (x_coor - partner_x) };
	double y_dist{ 1.0 * (y_coor - partner_y) };

	return sqrt((x_dist * x_dist) + (y_dist * y_dist));
}
