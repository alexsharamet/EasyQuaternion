#include "QuaternionSlerp.h"

QuaternionSLERP::QuaternionSLERP(const Quaternion& q1, const Quaternion& q2)
        : m_q1(q1), m_q2(q2), m_omega(0)
{
    //Most code get wrom this url http://www.gamedev.ru/articles/?id=30129&page=4
    //Operation understaning is here https://habr.com/ru/post/426863/
    m_q1.Normalize();
    m_q2.Normalize();

    double cos_omega = m_q1.w() * m_q2.w() +
                       m_q1.x() * m_q2.x() +
                       m_q1.y() * m_q2.y() +
                       m_q1.z() * m_q2.z();

    if (cos_omega < 0)
    {
        cos_omega = -cos_omega;
        m_q2 = m_q2.Invert();
    }
    if (cos_omega > 1-Accuracy)
        cos_omega = 1-Accuracy;

    m_omega = acos(cos_omega);

    double inv_sin_omega = (1.0 / sin(m_omega));
    m_q1.Scale(inv_sin_omega);
    m_q2.Scale(inv_sin_omega);
}

Quaternion QuaternionSLERP::Interpolate(double t) const
{
    return (m_q1 * sin((1.0 - t) * m_omega) + m_q2 * sin(t * m_omega)).Normalize();
}
