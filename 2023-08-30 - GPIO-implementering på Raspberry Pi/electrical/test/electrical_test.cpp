
#include <electrical.h>
#include <gtest/gtest.h>

TEST(ElectricalTest, Test1) {
    struct electrical* e1 = electrical_new(10, 2.5);
    EXPECT_NEAR(electrical_voltage_v(e1), 10, 0.001); 
    EXPECT_NEAR(electrical_current_ma(e1), 2.5, 0.001);
    EXPECT_NEAR(electrical_resistance_kohm(e1), 4, 0.001);
    EXPECT_NEAR(electrical_power_mw(e1), 25, 0.001);
    electrical_delete(&e1);
}

TEST(ElectricalTest, Test2) {
    struct electrical* e1 = electrical_new(10, 0);
    EXPECT_NEAR(electrical_voltage_v(e1), 10, 0.001); 
    EXPECT_NEAR(electrical_current_ma(e1), 0, 0.001);
    EXPECT_NEAR(electrical_resistance_kohm(e1), 0, 0.001);
    EXPECT_NEAR(electrical_power_mw(e1), 0, 0.001);
    electrical_delete(&e1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}