#include "gtest/gtest.h"

#include "my_class_test.h"

using namespace std;

TEST(test_build_action, test_operator_equal)
{
    EXPECT_TRUE(BuildAction(EntityType::HOUSE, {1, 1}) == BuildAction(EntityType::HOUSE, {1, 1}));
    //equal positions, but not EntityType
    EXPECT_FALSE(BuildAction(EntityType::WALL, {1, 1}) == BuildAction(EntityType::HOUSE, {1, 1}));
    //equal EntityTypes, but not positions
    EXPECT_FALSE(BuildAction(EntityType::HOUSE, {1, 1}) == BuildAction(EntityType::HOUSE, {2, 2}));
}
