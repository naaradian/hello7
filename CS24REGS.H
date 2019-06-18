#define VideoMicrocodePtr 0x0000;
#define AudioMicrocodePtr 0x0000;
#define PicPtr 		  0x0000;
#define CS24_VLOAD_SEG     0xe000;
#define CS24_ALOAD_SEG     0xe200;

#define	chip_control 	0x0	//	Control video decoder operation Chip Control R/W 94
#define	chip_mode 	0x1	//	Video decoder operational mode Chip Control R/W 95
#define	sync_stc2 	0x2	//	STC bits 32:30 Timer Control R/W 96
#define	sync_stc1 	0x3	//	STC bits 29:15 Timer Control R/W 97
#define	sync_stc0 	0x4	//	STC bits 14:0 Timer Control R/W 98
#define	sync_pts2 	0x5	//	PTS bits 32:30 Timer Control R 99
#define	sync_pts1 	0x6	//	PTS bits 29:15 Timer Control R 100
#define	sync_pts0 	0x7	//	PTS bits 14:0 Timer Control R 101
#define	fifo 		0x8	//	FIFO data port FIFO Control R/W 102
#define	fifo_stat 	0x9	//	FIFO status FIFO Control R/W 103
#define	command 	0x0A 	//	Send command to decoder Command I/F R/W 104
#define	cmd_data 	0x0B 	//	Command parameter data Command I/F R/W 105
#define	cmd_stat 	0x0C 	//	Command status Command I/F R/W 106
#define	cmd_addr 	0x0D 	//	Command address Command I/F R/W 107
#define	proc_iaddr 	0x0E 	//	Instruction store (I-Store) address I-Store Access R/W 108
#define	proc_idata 	0x0F 	//	Data port for I-Store I-Store Access R/W 109
#define	host_int 	0x10	//	Interrupt register Interrupt Control R 110
#define	host_int1 	0x11	//	Interrupt 1 register Interrupt Control R 111
#define	mask 		0x12	//	Masks for interrupt register Interrupt Control R/W 112
#define	mask1 		0x13	//	Masks for interrupt 1 register Interrupt Control R/W 113
#define	disp_mode 	0x14	//	Operational mode for display Display Control R/W 114
#define	disp_dly 	0x15	//	Setting for 'Sync' signal delay Display Control R/W 115
#define	vbi_cntl 	0x16	//	VBI (vertical blanking interval) control Display Control R/W 117
#define	disp_lbor 	0x17	//	Set left border of display Display Control R/W 118
#define	disp_tbor 	0x18	//	Set top border of display Display Control R/W 119
#define	osd_fl_addr 	0x19	//	First link address for OSD OSD_Control R/W 120
#define	osd_mode 	0x1A 	//	OSD mode control OSD_Control R/W 121
#define	rb_threshold 	0x1B 	//	Rate buffer threshold FIFO Control R/W 122
#define	infc_ctl 	0x1C 	//	Program control of signal polarity Polarity Control R/W 123
#define	pts_delta 	0x1E 	//	Difference between PTS and STC PTS Control R 124
#define	pts_control 	0x1F 	//	PTS Control PTS Control R/W 125
#define	wr_protect 	0x25	//	I-Store write protection I-Store Access R/W 126
#define	block_size 	0x29	//	Block size (bytes) for copy operation DRAM Access R/W 127
#define	dram_data 	0x2A 	//	Data port for DRAM access DRAM Access R/W 128
#define	dram_control 	0x2B 	//	DRAM command and status DRAM Access R/W 129
#define	dram_addrhi 	0x2C 	//	DRAM address 21:16 DRAM Access R/W 130
#define	dram_addrlo 	0x2D 	//	DRAM address 15:0 DRAM Access R/W 131
#define	src_addrhi 	0x2E 	//	DRAM source address 21:16 DRAM Access R/W 132
#define	src_addrlo 	0x2F 	//	DRAM source address 15:0 DRAM Access R/W 133
#define	base_addr_indx 	0x30	//	Base address stack index address DRAM Access R/W 134
#define	base_addr 	0x31	//	Base address port DRAM Access R/W 135
#define	match_tc_high 	0x35	//	Time code match on high order bits Support R/W 136
#define	match_tc_low 	0x36	//	Time code match on low order bits Support R/W 136
#define	parm_addr 	0x37	//	Stream Parameter Stack Address Support R/W 138
#define	parm_data 	0x38	//	Stream Parameter Data Support R 139
#define	aud1_data_port 	0x39	//	Audio1 compressed data input port Audio W 140
#define	aud2_data_port 	0x3A 	//	Audio2 compressed data input port Audio W 141
#define	rb_size 	0x3F 	//	Rate buffer size FIFO Control R/W 142
//Table 33: Host Address Map
#define	location 	0x80	//	R/W 143
#define	data_transfer 	0x81	//	R/W 144
#define	interrupt_reg 	0x82	//	R/W 145
//#define	reserved	0x83:8F
//Table 34: Register Location Map
//Front-End Registers
#define	 configuration1		0x0	//	R/W 147
#define	 control1 				0x1	//	R/W 149
#define	 fend_stat 				0x2	//	R/W 150
#define	 fend_stat_imask 	0x3	//	R/W 152
//Clock Recovery Registers
#define	pcr_high 					0x10	//	R 153
#define	pcr_low 					0x11	//	R 154
#define	latched_stc_high 	0x12	//	R 155
#define	latched_stc_low 	0x13	//	R 156
#define	stc_high					0x14	//	R 157
#define	stc_low 					0x15	//	R 158
#define	pwm 							0x16	//	R/W 159
#define	pcr_stc_threshold 0x17	//	R/W 160
#define	pcr_stc_delta 		0x18	//	R 161
#define	stc_compare 			0x19	//	R/W 162

#define	stc_compare_disarm 	0x001A 	//	W 163
//Additional PID Registers
//#define	pid 0-pid 31_filter registers r/w 164	0x0100:011F 	//
#define	audio1_ch_change 	0x01F1 	//	R/W 165
#define	audio2_ch_change	0x01F2 	//	R/W 166
#define	pcr_pid 					0x01FF	//	R/W 167
//Back-End Configuration and Control Registers
#define	configuration2 				0x1000	//	R/W 168
#define	packet_buffer_level 	0x1002	//	R/W 170
#define	general_mask 					0x1003	//	R/W 171
#define	memory_configuration	0x1004	//	R/W 173
#define	interrupt_mask2 			0x1005	//	R/W 174
//Back-End Status and Interrupt Mask Registers
#define	queue_int 					0x1010	//	R 175
#define	queue_imask 				0x1011	//	R/W 176
#define	audio1_status 			0x1012	//	R/W 177
#define	audio1_status_imask	0x1013	//	R/W 179
#define	video_status 				0x1014	//	R/W 180
#define	video_status_imask 	0x1015	//	R/W 182
#define	audio2_status 			0x1016	//	R/W 183
#define	audio2_status_imask	0x1017	//	R/W 185
//Queue Configuration and Control Registers
#define	bucket_queue 				0x1021	//	R/W 186
#define	queue_stop 					0x1024	//	R/W 187
#define	queue_reset 				0x1025	//	R/W 188
#define	section_filter_change 	0x1026	//	R/W 189
//Audio Decoder Registers Channel 1
#define	aud1_ctrl0 	0xA0 	//	Audio Control 0 R/W 201
#define	aud1_ctrl1 	0xA1 	//	Audio Control 1 R/W 203
#define	aud1_ctrl2 	0xA2 	//	Audio Control 2 R/W 204
#define	aud1_isr 	0xA4 	//	Interrupt Status R 206
#define	aud1_imr 	0xA5 	//	Interrupt Mask R/W 207
#define	aud1_dsr 	0xA6 	//	Decoder Status R 208
#define	aud1_stc 	0xA7 	//	System Time Clock R/W 209
#define	aud1_csr 	0xA8 	//	Channel Status R/W 210
#define	aud1_pts 	0xAA 	//	Presentation Time Stamp R 212
#define	aud1_tone_ctrl 	0xAB 	//	Tone Generation Control R/W 213
#define	aud1_tone_val 	0xAC 	//	Tone Generation Value R/W 214
#define	aud1_adr	0xAD 	//	Ancillary Data R 215
#define	aud1_stream_id 	0xAE 	//	Stream ID R/W 216
#define	aud1_dsp_stat 	0xB0 	//	DSP Status R 217
#define	aud1_dsp_ctrl 	0xB2 	//	DSP CONTROL R/W 218
#define	aud1_mdr 	0xB4 	//	Microcode Download R/W 219
#define	aud1_seg1_r 	0xB6 	//	Segment 1 Base R/W 220
#define	aud1_seg2_r 	0xB7 	//	Segment 2 Base R/W 221
#define	aud1_atten_front 	0xB9 	//	Front Audio Attenuation R/W 222
#define	aud1_atten_rear 	0xBA 	//	Rear Audio Attenuation R/W 223
#define	aud1_atten_center 	0xBB 	//	Center Audio Attenuation R/W 224
#define	aud1_seg3_r 	0xBC 	//	Audio Rate Buffer Base Address&Size R/W 225
#define	aud1_offsets 	0xBD 	//	Audio Offset Addresses R/W 226

//Audio Decoder Registers Channel 2
#define	aud2_ctrl0 	0xC0 	//	Audio Control 0 R/W 201
#define	aud2_ctrl1 	0xC1 	//	Audio Control 1 R/W 203
#define	aud2_ctrl2 	0xC2 	//	Audio Control 2 R/W 204
#define	aud2_isr 	0xC4 	//	Interrupt Status R 206
#define	aud2_imr 	0xC5 	//	Interrupt Mask R/W 207
#define	aud2_dsr 	0xC6 	//	Decoder Status R 208
#define	aud2_stc 	0xC7 	//	System Time Clock R/W 209
#define	aud2_csr 	0xC8 	//	Channel Status R/W 210
#define	aud2_pts 	0xCA 	//	Presentation Time Stamp R 212
#define	aud2_tone_ctrl 	0xCB 	//	Tone Generation Control R/W 213
#define	aud2_tone_val 	0xCC 	//	Tone Generation Value R/W 214
#define	aud2_adr	0xCD 	//	Ancillary Data R 215
#define	aud2_stream_id 	0xCE 	//	Stream ID R/W 216
#define	aud2_dsp_stat 	0xD0 	//	DSP Status R 217
#define	aud2_dsp_ctrl 	0xD2 	//	DSP CONTROL R/W 218
#define	aud2_mdr 	0xD4 	//	Microcode Download R/W 219
#define	aud2_seg1_r 	0xD6 	//	Segment 1 Base R/W 220
#define	aud2_seg2_r 	0xD7 	//	Segment 2 Base R/W 221
#define	aud2_atten_front 	0xD9 	//	Front Audio Attenuation R/W 222
#define	aud2_atten_rear 	0xDA 	//	Rear Audio Attenuation R/W 223
#define	aud2_atten_center 	0xDB 	//	Center Audio Attenuation R/W 224
#define	aud2_seg3_r 	0xDC 	//	Audio Rate Buffer Base Address&Size R/W 225
#define	aud2_offsets 	0xDD 	//	Audio Offset Addresses R/W 226
/*
char str_k[]= "ДТВМ-200          РАДИАН";
char str_e4[]="Скорость потока: 4Е1    ";
char str_e3[]="Скорость потока: 3Е1    ";
char str_v[]= "Нет входного потока !   ";
*/