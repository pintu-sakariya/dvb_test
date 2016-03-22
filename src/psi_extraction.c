#include <stdio.h>
#include <string.h>
#include <time.h>
#include <si_objects.h>
#include <dvb_stdid.h>
#include <sections_parse.h>

time_t tdt_section_parse(unsigned char *dvb_buf)
{
	unsigned char *ptr = dvb_buf+5;
	fprintf(stderr,"table_id 0x%2x\n",ptr[0]);
	fprintf(stderr,"section_syntax_indicator %d\n",(ptr[1]&0x80)?1:0);
	fprintf(stderr,"section length %d\n",((unsigned int)(ptr[1]&0x0f)<<4) | ptr[2]);
return get_utc_from_mjd(ptr+3);
}

time_t tot_section_parse(unsigned char *dvb_buf)
{
	unsigned char *ptr = dvb_buf+5;
return get_utc_from_mjd(ptr+3);
}
