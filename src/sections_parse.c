#include <stdio.h>
#include <time.h>
#include <sections_parse.h>
time_t get_utc_from_mjd(unsigned char *dvb_buf)
{
  int i;
  int year, month, day, hour, min, sec;
  long int mjd;
  struct tm dvb_time;

  mjd = (dvb_buf[0] & 0xff) << 8;
  mjd += (dvb_buf[1] & 0xff);
  hour = bcdtoint(dvb_buf[2] & 0xff);
  min = bcdtoint(dvb_buf[3] & 0xff);
  sec = bcdtoint(dvb_buf[4] & 0xff);
/*
 * Use the routine specified in ETSI EN 300 468 V1.4.1,
 * "Specification for Service Information in Digital Video Broadcasting"
 * to convert from Modified Julian Date to Year, Month, Day.
 */
  year = (int)((mjd - 15078.2)/365.25);
  month = (int)((mjd - 14956.1 - (int)(year * 365.25))/30.6001);
  day = mjd - 14956 - (int)(year * 365.25) - (int)(month * 30.6001);
  if (month == 14 || month == 15)
    i = 1;
  else
    i = 0;
  year += i;
  month = month - 1 - i * 12;

  dvb_time.tm_sec = sec;
  dvb_time.tm_min = min;
  dvb_time.tm_hour = hour;
  dvb_time.tm_mday = day;
  dvb_time.tm_mon = month - 1;
  dvb_time.tm_year = year;
  dvb_time.tm_isdst = 0;
  dvb_time.tm_wday = 0;
  dvb_time.tm_yday = 0;
  return(mktime(&dvb_time));
}
