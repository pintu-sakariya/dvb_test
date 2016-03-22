#include <filters.h>
#include <stdio.h>
#include <dvb_stdid.h>
#include <si_objects.h>

int filter_section(unsigned char *dvb_buf,unsigned int pid)
{
	struct ts_header tsMetaData;
	int adaption_len = 0;
	int table_id = 0x0;
	tsMetaData.ts_pid =  (unsigned int )((dvb_buf[1] & 0x1f) << 5) | dvb_buf[2];
	tsMetaData.ts_error_indicator = dvb_buf[1]>>7;
	tsMetaData.payload_indicator  = dvb_buf[1]>>6;
	tsMetaData.ts_priority = dvb_buf[1]>>5;
	tsMetaData.scrambling_ctl = (dvb_buf[3] & 0xc0)>>2; 	
	tsMetaData.adaption_flag = dvb_buf[3]>>5; 	
	tsMetaData.payload_flag = dvb_buf[3]>>4; 	
	tsMetaData.countinuty_count = dvb_buf[3] & 0xf; 	
	if(tsMetaData.adaption_flag) 
		adaption_len = dvb_buf[4];
	table_id = dvb_buf[5+adaption_len]; 
	if (ts_pid_table[pid] == tsMetaData.ts_pid) {
		printf("Main id 0x%2x table_id 0x%2x\n",ts_pid_table[pid],table_id);
		fprintf(stderr,"Transport Error Indicator %d\n",tsMetaData.ts_error_indicator);
		fprintf(stderr,"Payload Unit Start Indicator %d\n",tsMetaData.payload_indicator);
		fprintf(stderr,"Transport Priority %d\n",tsMetaData.ts_priority);
		fprintf(stderr,"Scrambling control %d\n",tsMetaData.scrambling_ctl);
		fprintf(stderr,"Adaptation field flag %d\n",tsMetaData.adaption_flag);
		fprintf(stderr,"Payload flag %d\n",tsMetaData.payload_flag);
		fprintf(stderr,"Continuity counter %d\n",tsMetaData.countinuty_count);

	} else {
		return 0;
	}
	return table_id;
}

