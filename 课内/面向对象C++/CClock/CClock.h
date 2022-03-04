#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED
class CClock
{
public :
    void ShowTime () const;
    void SetTime (int iHour, int iMinute, int iSecond)
    {
        m_iHour = iHour;
        m_iMinute = iMinute;
        m_iSecond = iSecond;
    }
private:
    int m_iHour, m_iMinute, m_iSecond;
};
#endif // CLOCK_H_INCLUDED
