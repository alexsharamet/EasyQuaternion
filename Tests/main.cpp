#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Quaternion.h>

template<typename T1, typename T2>
constexpr bool EQ(T1 t1, T2 t2, double accuracy = Accuracy) noexcept
{
    static_assert(std::is_convertible_v<T1, double>, "not convertiable to double");
    static_assert(std::is_convertible_v<T2, double>, "not convertiable to double");

    return abs(static_cast<double>(t1) - static_cast<double>(t2)) < accuracy;
}

TEST(Quaternion, Construct)
{
    Quaternion q1{ 10,1,2,3 };

    //Assert
    ASSERT_TRUE(EQ(q1.w(), 10));
    ASSERT_TRUE(EQ(q1.x(), 1));
    ASSERT_TRUE(EQ(q1.y(), 2));
    ASSERT_TRUE(EQ(q1.z(), 3));
}

TEST(Quaternion, Scale)
{
    //Arrange
    Quaternion q{ 1, 2, 3, 4 };
    double val = 3;
    //Act
    q.Scale(val);
    //Assert
    ASSERT_TRUE(EQ(q.w(), 3));
    ASSERT_TRUE(EQ(q.x(), 6));
    ASSERT_TRUE(EQ(q.y(), 9));
    ASSERT_TRUE(EQ(q.z(), 12));
}

TEST(Quaternion, Norm)
{
    //Arrange
    Quaternion q{ 1, 2, 3, 4 };

    //Act
    q.Normalize();
    //Assert
    ASSERT_TRUE(EQ(q.w(), 1.0 / sqrt(30)));
    ASSERT_TRUE(EQ(q.x(), 2.0 / sqrt(30)));
    ASSERT_TRUE(EQ(q.y(), 3.0 / sqrt(30)));
    ASSERT_TRUE(EQ(q.z(), 4.0 / sqrt(30)));
}

TEST(Quaternion, Invert)
{
    //Arrange
    Quaternion in{ 1, 2, 3, 4 };

    //Act
    auto q = in.Invert();
    //Assert
    ASSERT_TRUE(EQ(q.w(), 1.0 / sqrt(30)));
    ASSERT_TRUE(EQ(q.x(), -2.0 / sqrt(30)));
    ASSERT_TRUE(EQ(q.y(), -3.0 / sqrt(30)));
    ASSERT_TRUE(EQ(q.z(), -4.0 / sqrt(30)));
}

TEST(Quaternion, Multiplication)
{
    //Arrange
    Quaternion q1{ 1, 2, 3, 4 };
    Quaternion q2{ 4, 3, 2, 1 };

    //Act
    auto q = q1 * q2;
    //Assert
    ASSERT_TRUE(EQ(q.w(), -12.0));
    ASSERT_TRUE(EQ(q.x(), 6.0));
    ASSERT_TRUE(EQ(q.y(), 24.0));
    ASSERT_TRUE(EQ(q.z(), 12));
}
