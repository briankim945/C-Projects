#include <iostream>
#include <string>
#include <iterator>
#include <list>

bool check_number(std::string check_string)
{
	std::string::const_iterator it = check_string.begin();
	while (it != check_string.end() && std::isdigit(*it)) ++it;
	return !check_string.empty() && it == check_string.end();
}

int double_sum(int val)
{
	int doub_val = val * 2;
	int temp_val;
	if (doub_val > 9)
	{
		temp_val = 0;

		while (doub_val > 9)
		{
			temp_val += doub_val % 10;
			doub_val /= 10;
		}

		return temp_val + doub_val;
	}
	else
	{
		return doub_val;
	}
}

bool cred_val(std::string rev_num)
{
	int len = rev_num.length();
	int checksum;
	std::string::iterator it = rev_num.begin();
	int even_sum = 0;
	int odd_sum = 0;

	while (it != rev_num.end())
	{
		// Remember that indices start at 0
		if ((std::distance(rev_num.begin(), it) % 2) == 0)
		{
			odd_sum += (int)(*it);
		}
		else
		{
			even_sum += double_sum((int)(*it));
		}

		++it;
	}

	if (((odd_sum + even_sum) % 10 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::string num_string;

    std::cout << "Welcome to your credit card validation application. Please enter your number: " << std::endl;
	std::getline(std::cin, num_string);

	std::reverse(num_string.begin(), num_string.end());

	if (check_number(num_string))
	{
		std::cout << "This is valid credit card number! Please continue." << std::endl;
	}
	else
	{
		std::cout << "This is not a valid number." << std::endl;
	}

	std::cout << "Press Enter to finish the program." << std::endl;
	std::getline(std::cin, num_string);
}
