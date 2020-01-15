#pragma once

#include <string>
#include <vector>

class Node
{
private:
	std::string Name;
	int x_coor;
	int y_coor;
	std::vector<std::string> names_list;
public:
	Node();
	Node(std::string name_in, int x_in, int y_in, std::vector<std::string> names_in);
	std::string return_name();
	int return_x();
	int return_y();
	std::vector<std::string> return_linked();
	double get_distance(Node partner_node);
};

