#ifndef __DVB_STDID__
#define __DVB_STDID__
enum TS_PID_LIST {
PAT_PID, /* mandatory */
CAT_PID,  
TSDT_PID,
NIT_PID,/* mandatory */
SDT_BAT_PID,/* mandatory */
EIT_CIT_PID,
RST_PID,
TDT_TOT_PID,/* mandatory */
NET_SYNC_PID,
RNT_PID,
INBAND_PID,
MEASUREMENT_PID,
DIT_PID,
SIT_PID
};

static const unsigned int  const  ts_pid_table[] = {
				[PAT_PID] = 0x0000, 
				[CAT_PID] = 0x0001,
				[TSDT_PID] = 0x0002,
				[NIT_PID] = 0x0010,
				[SDT_BAT_PID] = 0x0011,
				[EIT_CIT_PID] = 0x0012,
				[RST_PID] = 0x0013,
				[TDT_TOT_PID] = 0x0014,
				[NET_SYNC_PID] = 0x0015,
				[RNT_PID] = 0x0016,
				[INBAND_PID] = 0x001C,
				[MEASUREMENT_PID] = 0x001D,
				[DIT_PID] = 0x001E,
				[SIT_PID] = 0x001F
			};

enum PSI_TABLE_LIST {
	TDT_ID,
	TOT_ID
};
static const unsigned int const psi_table_id[] = {
		[TDT_ID] = 0x70,
		[TOT_ID] = 0x73
	};			
#endif /* __DVB_STDID__ */
