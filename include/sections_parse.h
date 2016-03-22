#ifndef __SECTIONS_PARSE_H__
#define __SECTIONS_PARSE_H__

#define bcdtoint(i) ((((i & 0xf0) >> 4) * 10) + (i & 0x0f))
time_t get_utc_from_mjd(unsigned char *dvb_buf);

#endif /* __SECTIONS_PARSE_H__ */
