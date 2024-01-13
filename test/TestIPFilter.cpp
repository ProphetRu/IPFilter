#include <gtest/gtest.h>

#include "IPFilter.h"
#include "IPFilter.cpp"

TEST(IPFilter, AddEmptyLine) 
{
    // Arrange
    IPFilter ipf;

    // Act
	//

    // Assert
    ASSERT_THROW(ipf.AddLine(""), std::invalid_argument);
}

TEST(IPFilter, AddInvalidLine) 
{
    // Arrange
    IPFilter ipf;

    // Act
    //

    // Assert
    ASSERT_THROW(ipf.AddLine("1.1.1.1.2.2"), std::runtime_error);
}

TEST(IPFilter, AddLines) 
{
    // Arrange
    IPFilter ipf;

    // Act
    ipf.AddLine("1.1.1.1\t111\t0\n");
    ipf.AddLine("1.2.1.1\t5\t6\n");
    ipf.AddLine("1.10.1.1\t2\t1\n");

    const auto& ips = ipf.GetIPList();

    // Assert
    ASSERT_EQ(ips.size(), 3);
}

TEST(IPFilter, SortLines) 
{
    // Arrange
    IPFilter ipf;

    // Act
    ipf.AddLine("1.1.1.1\t111\t0\n");
    ipf.AddLine("1.2.1.1\t5\t6\n");
    ipf.AddLine("1.10.1.1\t2\t1\n");

    ipf.ReverseSort();
    const auto& ips = ipf.GetIPList();

    IPList fixed =
    {
        {1, 10, 1, 1},
        {1, 2,  1, 1},
        {1, 1,  1, 1},
    };

    // Assert
    ASSERT_EQ(ips.size(), fixed.size());

    for (size_t i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            ASSERT_EQ(ips[i].n[j], fixed[i].n[j]);
        }
    }
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
