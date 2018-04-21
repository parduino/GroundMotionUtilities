#include "PointSourceRupture.h"


PointSourceRupture::PointSourceRupture(double magnitude, const RuptureLocation &location, double averageRake, double averageDip, QObject *parent): QObject(parent), m_location(location.latitude(), location.longitude())
{
    this->setMagnitude(magnitude);
    this->setAverageDip(averageDip);
    this->setAverageRake(averageRake);
}

double PointSourceRupture::magnitude() const
{
    return m_magnitude;
}

void PointSourceRupture::setMagnitude(double magnitude)
{
    if(this->m_magnitude != magnitude)
    {
        m_magnitude = magnitude;
        emit this->magnitudeChanged(this->m_magnitude);
    }
}

double PointSourceRupture::averageRake() const
{
    return m_averageRake;
}

void PointSourceRupture::setAverageRake(double averageRake)
{
    if(this->m_averageRake != averageRake)
    {
        m_averageRake = averageRake;
        emit this->rakeChanged(this->m_averageRake);
    }
}

double PointSourceRupture::averageDip() const
{
    return m_averageDip;
}

void PointSourceRupture::setAverageDip(double averageDip)
{
    if(this->m_averageDip != averageDip)
    {
        m_averageDip = averageDip;
        emit this->dipChanged(this->m_averageDip);
    }
}

RuptureLocation &PointSourceRupture::location()
{
    return this->m_location;
}
