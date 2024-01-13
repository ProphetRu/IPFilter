#pragma once

#include <string>
#include <vector>

constexpr auto IP_SIZE = 4;

struct IP final
{
	int n[IP_SIZE]{ 0 };

    [[nodiscard]] bool operator<(const IP& other) const noexcept
	{
        for (int i = 0; i < IP_SIZE; ++i)
        {
            if (n[i] > other.n[i]) 
            {
                return true;
            }

            if (n[i] < other.n[i]) 
            {
                return false;
            }
        }

        return false;
    }
};

using IPList = std::vector<IP>;


class IPFilter final
{
public:
	void AddLine(const std::string&& line);

	void ReverseSort();

	[[nodiscard]] const IPList& GetIPList() const noexcept;

private:
	IPList m_IPList;
};
