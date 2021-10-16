#pragma once
#include "Quaternion.h"
#include <cmath>

class QuaternionSLERP
{
public:
    QuaternionSLERP()=default;
    QuaternionSLERP(const QuaternionSLERP&)=default;
    QuaternionSLERP(QuaternionSLERP&&)=default;
    QuaternionSLERP& operator=(const QuaternionSLERP&)=default;
    QuaternionSLERP& operator=(QuaternionSLERP&&)=default;

    QuaternionSLERP(const Quaternion& q1, const Quaternion& q2);

    Quaternion Interpolate(double t) const;

private:
    Quaternion m_q1, m_q2;
    double m_omega{};
};
