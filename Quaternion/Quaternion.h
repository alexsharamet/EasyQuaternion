#pragma once
#include <string>

constexpr double Accuracy = 1e-5;

class Quaternion
{
public:
    Quaternion() = default;
    Quaternion(double w, double x, double y, double z);
    Quaternion(double x, double y, double z, std::string order);

    Quaternion(const Quaternion&) = default;
    Quaternion(Quaternion&&) = default;
    Quaternion& operator=(const Quaternion&) = default;
    Quaternion& operator=(Quaternion&&) = default;

    friend Quaternion operator+(const Quaternion& a, const Quaternion& b);
    friend Quaternion operator*(const Quaternion& a, const Quaternion& b);
    friend Quaternion operator*(const Quaternion& a, double b);

    Quaternion& Normalize();
    Quaternion& Scale(double val);
    [[nodiscard]] Quaternion Invert() const;

    [[nodiscard]] double w()const { return m_w; }
    [[nodiscard]] double x()const { return m_x; }
    [[nodiscard]] double y()const { return m_y; }
    [[nodiscard]] double z()const { return m_z; }
private:
    [[nodiscard]] double Length()const;

    double m_w=0, m_x=0, m_y=0, m_z=0;
};



