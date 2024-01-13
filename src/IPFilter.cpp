#include "IPFilter.h"
#include <stdexcept>
#include <algorithm>

constexpr auto TAB = '\t';
constexpr auto DOT = '.';

void IPFilter::AddLine(const std::string&& line)
{
	if (line.empty())
	{
		throw std::invalid_argument("Line is empty");
	}

	IP ip;

	std::string buf;
	int index = 0;

	for (auto c : line)
	{
		if (c == TAB || c == DOT)
		{
			if (!buf.empty() && index < IP_SIZE)
			{
				ip.n[index] = std::stoi(buf);
				++index;
				buf.clear();
			}
			else
			{
				throw std::runtime_error("Invalid format");
			}

			if (c == TAB)
			{
				break;
			}

			continue;
		}

		buf.push_back(c);
	}

	m_IPList.emplace_back(ip);
}

void IPFilter::ReverseSort()
{
	if (m_IPList.empty())
	{
		throw std::invalid_argument("IP list is empty");
	}

	std::sort(begin(m_IPList), end(m_IPList));
}

[[nodiscard]] const IPList& IPFilter::GetIPList() const noexcept
{
	return m_IPList;
}
