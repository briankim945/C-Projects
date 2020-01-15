#include "Node.h"

#include <iostream>
#include <regex>
#include <algorithm>
#include <utility>

struct path {
	std::string start_name;
	std::string end_name;
	std::vector<std::string> path_list;
	double weight;
	double immediate_weight;
	path() : start_name(""), end_name(""), weight(0.0), immediate_weight(0.0) {}
	path(std::string start_in, std::string end_in, std::vector<std::string> path_in, double weight_in,
		double im_in)
		: start_name(start_in), end_name(end_in), path_list(path_in), weight(weight_in),
		immediate_weight(im_in) {}
};

struct adjacent {
	std::string start_node;
	std::string end_node;
	double weight;
	adjacent(std::string start_in, std::string end_in, double weight_in)
		: start_node(start_in), end_node(end_in), weight(weight_in) { }
};

void node_printer(std::vector<Node> node_list)
{
	int node_num = 1;
	std::vector<Node>::iterator it;
	Node temp_node;

	it = node_list.begin();
	while (it != node_list.end())
	{
		temp_node = (*it);
		std::cout << "Name of node " << node_num << " is " << temp_node.return_name()
			<< std::endl;;
		std::cout << "X coordinate is " << temp_node.return_x() << std::endl;
		std::cout << "Y coordinate is " << temp_node.return_y() << std::endl;

		std::vector<std::string> temp_name_vec;
		std::vector<std::string>::iterator temp_it;

		std::cout << "The linked nodes of this node are:" << std::endl;

		temp_name_vec = temp_node.return_linked();
		temp_it = temp_name_vec.begin();
		while (temp_it != temp_name_vec.end())
		{
			std::cout << (*temp_it) << std::endl;
			++temp_it;
		}

		std::cout << std::endl;

		++it;
		++node_num;
	}
}

std::vector<Node> node_get()
{
	std::vector<Node> node_list;
	std::string name_in;
	std::string temp_text;
	bool break_out;
	int x_in;
	int y_in;
	std::vector<std::string> names_in;
	std::string keep_going = "y";
	std::regex num_match;

	num_match = "[0-9]+";

	while ((keep_going.compare("n") != 0))
	{
		names_in.clear();
		break_out = false;

		// SECTION 1
		// Get the name
		std::cout << "Please enter a name: ";
		std::getline(std::cin, name_in);

		// Check for quitting
		if (name_in.compare("QUIT") == 0) break;

		/*
		// TESTING MODE
		if (name_in.compare("TESTING") == 0)
			return std::vector<Node>{ 
					Node("A", 0, 0, std::vector<std::string>{ "B", "D" }),
					Node("B", 0, 2, std::vector<std::string>{ "A", "C", "E" }),
					Node("C", 3, 3, std::vector<std::string>{ "B", "E", "D" }),
					Node("D", 3, 0, std::vector<std::string>{ "A", "E", "C" }),
					Node("E", 5, 0, std::vector<std::string>{ "C", "D", "B" })
			};
		*/


		// SECTION 2
		// Get the x coordinate. The while loop continues until temp_text is all digits.
		std::cout << "Please enter an x coordinate: ";
		std::getline(std::cin, temp_text);
		// Check for quitting
		if (temp_text.compare("QUIT") == 0) break;

		while (!regex_match(temp_text, num_match))
		{
			std::cout << "That is not a number coordinate. Please try again: ";
			std::getline(std::cin, temp_text);
			// Check for quitting
			if (temp_text.compare("QUIT") == 0) { break_out = true; break; }
		}
		// Check for quitting
		if (break_out) break;
		x_in = std::stoi(temp_text);



		// SECTION 3
		// Get the y coordinate. The while loop continues until temp_text is all digits.
		std::cout << "Please enter an y coordinate: ";
		std::getline(std::cin, temp_text);
		// Check for quitting
		if (temp_text.compare("QUIT") == 0) break;

		while (!regex_match(temp_text, num_match))
		{
			std::cout << "That is not a number coordinate. Please try again: ";
			std::getline(std::cin, temp_text);
			// Check for quitting
			if (temp_text.compare("QUIT") == 0) { break_out = true; break; }
		}
		// Check for quitting
		if (break_out) break;
		y_in = std::stoi(temp_text);



		// SECTION 4
		// Gets the names of the linked nodes.
		std::cout << "Enter a name (to stop entering names, enter 'DONE'): ";
		std::getline(std::cin, temp_text);
		while (temp_text.compare("DONE") != 0)
		{
			if (temp_text.compare("QUIT") == 0) { break_out = true; break; }
			else if ((temp_text.compare(name_in) == 0) ||
				(std::find(names_in.begin(), names_in.end(), temp_text) != names_in.end()))
			{
				std::cout << "Invalid name!" << std::endl;
			}
			else
			{
				names_in.push_back(temp_text);
			}
			std::cout << "Enter a name (to stop entering names, enter 'DONE'): ";
			std::getline(std::cin, temp_text);
		}
		// Check for quitting
		if (break_out) break;

		node_list.push_back(Node(name_in, x_in, y_in, names_in));

		std::cout << "Add another node (y/n)?" << std::endl;
		std::getline(std::cin, keep_going);

		while ((keep_going.compare("y") != 0) && (keep_going.compare("n") != 0))
		{
			std::cout << "Add another node (y/n)?" << std::endl;
			std::getline(std::cin, keep_going);
		}
	}

	return node_list;
}

Node get_node_by_name(std::string name, std::vector<Node> node_list)
{
	std::vector<Node>::iterator it;

	it = node_list.begin();

	while ((it != node_list.end()) && (name.compare((*it).return_name()) != 0)) ++it;

	try
	{
		if (it != node_list.end()) return (*it);
		else throw name;
	}
	catch (std::string e)
	{
		std::cout << "An exception occurred. " << e << " is not a valid name." << std::endl;
	}
}

void print_path(path path_data)
{
	std::vector<std::string>::iterator path_it;
	std::cout << "The path to " << path_data.end_name << " is ";
	path_it = path_data.path_list.begin();
	while (path_it != path_data.path_list.end() - 1)
	{
		std::cout << (*path_it) << " > ";
		++path_it;
	}

	std::cout << path_data.path_list.back() <<
		". The weight of this path is " << path_data.weight << std::endl;
}

std::vector<path> dijkstra_search(std::string start_name, std::vector<Node> node_list)
{
	std::vector<std::string> visited;
	std::vector<path> adjacent_list;
	std::vector<path> path_list;
	std::vector<std::string> cur_path;
	Node cur_node;
	std::vector<std::string> temp_adj_list;
	std::vector<std::string> string_path;
	
	cur_node = get_node_by_name(start_name, node_list);
	cur_path.push_back(start_name);

	path_list.push_back(path(start_name, start_name, cur_path, 0, 0));

	temp_adj_list = cur_node.return_linked();
	for (std::vector<std::string>::iterator it = temp_adj_list.begin();
		it != temp_adj_list.end(); ++it)
	{
		string_path = cur_path;
		string_path.push_back(*it);
		adjacent_list.push_back(path(cur_node.return_name(), (*it), string_path,
			cur_node.get_distance(get_node_by_name((*it), node_list)),
			cur_node.get_distance(get_node_by_name((*it), node_list))));
	}


	while (!adjacent_list.empty())
	{
		int cur_dist{ INT_MAX };
		path temp_path;
		double prior_weight;

		std::vector<path>::iterator path_it;
		std::vector<path>::iterator temp_path_it;

		// Find the nearest adjacent point
		temp_path_it = adjacent_list.begin();
		path_it = adjacent_list.begin();
		while (temp_path_it != adjacent_list.end())
		{
			if ((*temp_path_it).weight < cur_dist)
			{
				cur_dist = (*temp_path_it).weight;
				path_it = temp_path_it;
			}
			++temp_path_it;
		}

		temp_path = (*path_it);
		
		visited.push_back(temp_path.end_name);
		cur_node = get_node_by_name(temp_path.end_name, node_list);
		string_path = temp_path.path_list;
		prior_weight = temp_path.weight;

		// Clear out adjacent node
		adjacent_list.erase(path_it);

		temp_adj_list = cur_node.return_linked();
		for (std::vector<std::string>::iterator it = temp_adj_list.begin();
			it != temp_adj_list.end(); ++it)
		{
			std::vector<path>::iterator temp_path_it;
			std::vector<path>::iterator temp_adj_it;
			std::vector<std::string> new_path;
			Node temp_node;
			path new_path_data;

			temp_path_it = std::find_if(path_list.begin(), path_list.end(),
				[it](path element) {return element.end_name.compare(*it) == 0; });
			temp_adj_it = std::find_if(adjacent_list.begin(), adjacent_list.end(),
				[it](path element) {return element.end_name.compare(*it) == 0; });
			temp_node = get_node_by_name(*it, node_list);
			new_path = string_path;
			new_path.push_back((*it));
			//new_path_data = ;
			double new_weight{ cur_node.get_distance(temp_node) };

			if (temp_adj_it != adjacent_list.end() && prior_weight + new_weight < (*temp_adj_it).weight)
			{
				*temp_adj_it = path(string_path.back(), (*it), new_path,
					prior_weight + new_weight, new_weight);
			}
			else if (temp_adj_it == adjacent_list.end() && temp_path_it == path_list.end())
			{
				adjacent_list.push_back(path(string_path.back(), (*it), new_path,
					prior_weight + new_weight, new_weight));
			}
		}

		path_list.push_back(temp_path);
	}

	return path_list;
}

void print_paths(std::vector<path> paths)
{
	std::vector<path>::iterator it;
	std::vector<std::string> path;
	double weight;

	it = paths.begin();
	while (it != paths.end())
	{
		std::vector<std::string>::iterator path_it;

		path = (*it).path_list;
		weight = (*it).weight;

		std::cout << "The path to " << (*it).end_name << " is ";
		path_it = path.begin();
		while (path_it != path.end() - 1)
		{
			std::cout << (*path_it) << " > ";
			++path_it;
		}

		std::cout << path.back() << ". The weight of this path is " << weight << std::endl;

		++it;
	}
}

int main()
{
	std::vector<Node> node_list;
	std::string temp_name;
	std::string start_name;
	std::string end_name;
	std::vector<path> paths;

    std::cout << "Welcome to my implementation of Dijkstra's Algorithm!" << std::endl;
	std::cout << "Please enter all the relevant nodes:" << std::endl;
	std::cout << "If you want to stop while entering data, write 'QUIT'." << std::endl;

	node_list = node_get();

	std::cout << std::endl;

	node_printer(node_list);

	std::cout << "Please double-check the list above!" << std::endl;
	std::cout << "If it's not accurate, the algorithm will not work properly." << std::endl;
	std::cout << "If the above is a valid, non-directed graph, type 'continue'" << std::endl;
	std::cout << "Anything else will end the program: ";
	std::getline(std::cin, temp_name);

	if (temp_name.compare("continue") != 0) return 0;

	std::cout << "What is the name of the starting node? ";
	std::getline(std::cin, start_name);

	std::cout << std::endl;

	paths = dijkstra_search(start_name, node_list);

	//print_paths(paths);

	bool unfinished_business = true;
	while (unfinished_business)
	{
		std::cout << "What is the name of the ending node (to stop the program, type 'COMPLETE')? ";
		std::getline(std::cin, end_name);
		if (end_name.compare("COMPLETE") == 0)
		{
			std::cout << "Thank you for using my program!" << std::endl;
			return 0;
		}

		std::vector<path>::iterator temp_it;
		temp_it = std::find_if(paths.begin(), paths.end(),
			[end_name](path element) {return element.end_name.compare(end_name) == 0; });

		if (temp_it == paths.end())
			std::cout << "That is not a valid name." << std::endl;
		else
			print_path(*temp_it);
	}
}
