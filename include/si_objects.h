#ifndef __SI_OBJECTS_H__
#define __SI_OBJECTS_H__

#include <stdint.h>

struct ts_header {
	unsigned int ts_error_indicator:1;
	unsigned int payload_indicator:1;
	unsigned int ts_priority:1;
	unsigned int ts_pid:13;
	unsigned int scrambling_ctl:2;
	unsigned int adaption_flag:1;
	unsigned int payload_flag:1;
	unsigned int countinuty_count:4;
};

struct network_information_section {
	uint8_t table_id;                	/* 8 */  /* 0x40 actual,0x41 other n/w */
	uint8_t section_syntax_indicator;  	/* 1 */
/*
	uint8_t reserved_future_use; 		 1 
	uint8_t reserved;			 2 
*/
	uint16_t section_length; 		/* 12 */  /* start "00",MAX 1021 immediatly after section length */
	uint16_t network_id;			/* 16 */
/*
	uint8_t reserved; 			   2 
*/
	uint8_t version_number;			/* 5 */
	uint8_t current_next_indicator;		/* 1 */
	uint8_t	section_number;			/* 8 */
	uint8_t	last_section_number;		/* 8 */
/*
	uint8_t	reserved_future_use; 		* 4 *
*/
	uint16_t network_descriptors_length;	/* 12 */
/*
	uint8_t reserved_future_use; 		* 4 *
*/
 	uint16_t transport_stream_loop_length;  /*12 */
	uint16_t transport_stream_id; 		/* 16 */
	uint16_t original_network_id; 		/* 16 */
/*
	uint8_t	reserved_future_use;    	* 4 *
*/
	uint16_t transport_descriptors_length;  /* 12 */
	uint32_t CRC_32;  			/* 32 */
};

/* 
* struct time_date_section - TDT section 
* @table_id	0x70 table id
* @section_syntax_indicator	set to "0"  
* @section_length	first two bits "00",length of the section immediatly after section_length	   
* @UTC_time	16 bits MJD,24 bit 4-BCD 93/10/13 12:45:00 is coded as 0xC079124500
*
* UTC time and date section
*/
struct time_date_section {
	uint8_t table_id;			/* 8 */  
	uint8_t section_syntax_indicator;	/* 1 */  
/*
reserved_future_use; 1 
reservedi; 2 
*/
	uint16_t section_length; 		/* 12 */  
	uint8_t UTC_time [8]; 			/* 40 */ 
};

/*struct time_offset_section - TOT section
* @table_id	0x73
* @section_syntax_indicator	set to "0"
* @section_length	first two bits "00",length of the section immediatly after section_length	   
* @UTC_time	16 bits MJD,24 bit 4-BCD 93/10/13 12:45:00 is coded as 0xC079124500
* @descriptors_loop_length	total length in bytes of the following descriptors
*
* UTC time and date information and local offset
*/
struct time_offset_section {
	uint8_t table_id;			/*  8 */
	uint8_t section_syntax_indicator;	/* 1 */
	/*
	   reserved_future_use; 1 bslbf
	   reserved; 2 bslbf
	 */
	uint16_t section_length; 	/* 12 */ 
	uint8_t UTC_time [8]; 		/* 40 */
	/*
	   reserved 4; bslbf
	 */
	uint16_t descriptors_loop_length;	/* 12 */
	uint8_t CRC_32 [8]; 		/* 32 */
};

#endif /*__SI_OBJECTS_H__ */
