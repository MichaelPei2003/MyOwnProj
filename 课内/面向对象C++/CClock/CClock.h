#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED
class CClock
{
public :
    void ShowTime () const;
    ~CClock();
    void SetTime (int iHour, int iMinute, int iSecond)
    {
        m_iHour = iHour;
        m_iMinute = iMinute;
        m_iSecond = iSecond;
    }
private:
    int m_iHour=0, m_iMinute=0, m_iSecond{0};
};
#endif // CLOCK_H_INCLUDED
