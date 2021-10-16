#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Quaternion.h>
#include <QuaternionSlerp.h>

constexpr double M_PIl = 3.14159265358979323846264338327950288;
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

TEST(QuaternionSLERP, Common)
{
    //Arrange
    Quaternion q1{ M_PIl / 6, M_PIl / 6 ,M_PIl / 6 ,"zyx" };
    Quaternion q2{ M_PIl / 3, M_PIl / 3 ,M_PIl / 3 ,"zyx" };

    Quaternion matlab(0.857633733711829, 0.169832226922793, 0.454728939255462, 0.169832226922793);
    matlab.Normalize();

    //Act
    QuaternionSLERP slerp(q1, q2);
    auto ans = slerp.Interpolate(0.5);

    //Assert
    ASSERT_TRUE(EQ(matlab.w(), ans.w()));
    ASSERT_TRUE(EQ(matlab.x(), ans.x()));
    ASSERT_TRUE(EQ(matlab.y(), ans.y()));
    ASSERT_TRUE(EQ(matlab.z(), ans.z()));

    return;
}
