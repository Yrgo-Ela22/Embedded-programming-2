/********************************************************************************
 * @brief Example of unit testing of C functions for addition and division.
 ********************************************************************************/
#include <gtest/gtest.h>

/********************************************************************************
 * @brief C code to be tested.
 * 
 * @note extern "C" is used to compile code with the C compiler. 
 *       extern "C" can be placed in C headers to make it possibly to use
 *       C code in C++ programs.
 ********************************************************************************/
extern "C" {

/********************************************************************************
 * @brief Adds two integers.
 * 
 * @param x 
 *        The first integer to add.
 * @param y
 *        The second integer to add.
 * @return
 *        The sum of the two integers.
 ********************************************************************************/
static inline int add_int(const int x, const int y) {
    return x + y;
}

/********************************************************************************
 * @brief Divides two integers.
 * 
 * @param x
 *        The dividend.
 * @param y
 *        The divisor (must not be 0).
 * @return
 *        The quotient of the floating-point numbers or 0 if the divisor is 0.
 ********************************************************************************/
static inline double divide_int(const int x, const int y) {
    return y != 0 ? x / (double)(y) : 0;
}

/********************************************************************************
 * @brief Adds two floating-point numbers.
 * 
 * @param x 
 *        The first floating point number to add.
 * @param y
 *        The second floating number to add.
 * @return
 *        The sum of the two floating-point numbers.
 ********************************************************************************/
static inline double add_double(const double x, const double y) {
    return x + y;
}

/********************************************************************************
 * @brief Divides two floating-point numbers.
 * 
 * @param x
 *        The dividend.
 * @param y
 *        The divisor (must not be 0).
 * @return
 *        The quotient of the floating-point numbers or 0 if the divisor is 0.
 ********************************************************************************/
static inline double divide_double(const double x, const double y) {
    return y != 0 ? x / y : 0;
}
} /* extern "C" */

/********************************************************************************
 * @brief Tests the addition functions. When performing floating-point addition,
 *        the precision of the sum is set to 0.001. 
 ********************************************************************************/
TEST(MathTest, AdditionTest) {
    EXPECT_EQ(add_int(3, 4), 7);
    EXPECT_EQ(add_int(3, -4), -1);
    EXPECT_NEAR(add_double(3.5, 4.2), 7.7, 0.001);
    EXPECT_NEAR(add_double(3.5, -4.2), -0.7, 0.001);
}

/********************************************************************************
 * @brief Tests the division functions. The precision of the quotient is set 
 *        to 0.001. If an invalid divisor is passed (0), all division functions
 *        shall return exactly 0.
 ********************************************************************************/
TEST(MathTest, DivisionTest) {
    EXPECT_NEAR(divide_int(3, 4), 0.75, 0.001);
    EXPECT_NEAR(divide_int(3, -4), -0.75, 0.001);
    EXPECT_EQ(divide_int(1, 0), 0);
    
    EXPECT_NEAR(divide_double(3.2, 2), 1.6, 0.001);
    EXPECT_NEAR(divide_double(3.2, -2), -1.6, 0.001);
    EXPECT_EQ(divide_double(1, 0), 0);
}

/********************************************************************************
 * @brief Runs all unit tests.
 * 
 * @param argc
 *        The number of input arguments entered in the terminal when running 
 *        the program.
 * @param argv
 *        Reference to vector containing all the input arguments entered in
 *        the terminal.
 * @return
 *        Success code 0 if all tests could be run, else error code 1.
 ********************************************************************************/
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
