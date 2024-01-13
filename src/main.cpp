#include <iostream>
#include <stdexcept>
#include "IPFilter.h"

void PrintIPs(const IPList& ips) noexcept
{
	for (const auto& [n] : ips)
	{
		std::cout << n[0] << "." << n[1] << "." << n[2] << "." << n[3] << std::endl;
	}
}

void Filter(const IPList& ips, int first_byte) noexcept
{
	for (const auto& [n] : ips)
	{
		if (n[0] == first_byte)
		{
			std::cout << n[0] << "." << n[1] << "." << n[2] << "." << n[3] << std::endl;
		}
	}
}

void Filter(const IPList& ips, int first_byte, int second_byte) noexcept
{
	for (const auto& [n] : ips)
	{
		if (n[0] == first_byte && n[1] == second_byte)
		{
			std::cout << n[0] << "." << n[1] << "." << n[2] << "." << n[3] << std::endl;
		}
	}
}

void FilterAny(const IPList& ips, int any_byte) noexcept
{
	for (const auto& [n] : ips)
	{
		if (n[0] == any_byte || n[1] == any_byte || n[2] == any_byte || n[3] == any_byte)
		{
			std::cout << n[0] << "." << n[1] << "." << n[2] << "." << n[3] << std::endl;
		}
	}
}

int main() noexcept
{
	try
	{
		IPFilter ipf;

		for (std::string line; std::getline(std::cin, line);)
		{
			ipf.AddLine(std::move(line));
		}

		ipf.ReverseSort();

		const auto& ips = ipf.GetIPList();

		PrintIPs(ips);
		Filter(ips, 1);
		Filter(ips, 46, 70);
		FilterAny(ips, 46);
	}
	catch (const std::invalid_argument& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch (const std::runtime_error& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	return 0;
}
