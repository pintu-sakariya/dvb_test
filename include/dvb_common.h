#ifndef __DVB_COMMON_H__
#define __DVB_COMMON_H__
#include <dvb_stdid.h>
#include <si_objects.h>


/*
* struct pat_table - program assocation table in trasport stream.
* @
*
* its gives location of PMT and NIT table in multiplex service.
*/
struct pat_table {
	uint16_t pat_pid;
};

/*
* struct pmt_param - program map table in trasport stream.
* @
*
* location of stream that make up each service,location of PCR for a service.
*/
struct pmt_table {
	uint16_t pmt_pid;
};

/*
* struct nit_param - network inforamtion table in transport stream.
* @
*
* provide inforamtion about physical network.
*/
struct nit_table {
	uint16_t nit_pid;
};

/*
* struct cat_table - cat table info in transport stream.
* @
*
* provides inforamation on CA system used in multiplex, private and dependent.
* include location of EMM(Entitlement Management Message)stream when applicable.
*/
struct cat_table {
	uint16_t cat_pid;
};

struct si_table {
	struct pat_table pat_param;
	struct pmt_table pmt_param;
	struct nit_table nit_param;
	struct cat_table cat_param;
};

/*
*  IDENTIFICATION OF SERVICE AND EVENT FOR USER IN SI
*/

/*
* struct bat_table - bouquet association table
* @
*
* bouquets name,list of services for each bouquet. 
*/
struct bat_table {
	uint16_t bat_pid;
};

/*
* struct sdt_table - service description table
* @
*
* name of the service,service provider. 
*/
struct sdt_table {
	uint16_t sdt_pid;
};

/*
* struct eit_table - event inforamtion table
* @
*
* concerning events or programmes - event name,start time,duration etc.  
*/
struct eit_table {
	uint16_t eit_pid;
};

/*
* struct rst_table - running status table
* @
*
* status of a events (running/not running),allows timely switching of events. 
*/
struct rst_table {
	uint16_t rst_pid;
};

/*
* struct tdt_table - UTC time and date table
* @tdt_pid	0x0014 
* @tdt_section	object which hold tdt section
*
* present time and date,info given in separate table due to frequent
* updating of this info 
*/
struct tdt_table {
	uint16_t tdt_pid;
	struct time_date_section tdt_section;
};

/*
* struct tot_table - UTC time and date information and locale offset
* @tot_pid	0x0014
* @tot_section	object hold tot section
*
* UTC time,date and local time offset - info given in separate table.  
*/
struct tot_table {
	uint16_t tot_pid;
	struct time_offset_section tot_section;
};

/*
* struct st_table - stuffing table
* @
*
* invalidate existing section for example at delivery system boundaries. 
*/
struct st_table {
	uint16_t st_pid;
};

/*
* struct sit_table - selection inforamation table
* @
*
* used in partial(recorded)bit stream.
* summury of SI inforamtion required to describe the stream in the partial. 
*/
struct sit_table {
	uint16_t sit_pid;
};

/*
* struct dit_table - discountinuity inforamtion table
* @
*
* used only in partial bit streams.
* inserted where the SI information in the partial bitstream may be discountinous. 
*/
struct dit_table {
	uint16_t dit_pid;
};
#endif /* __DVB_COMMON_H__ */
