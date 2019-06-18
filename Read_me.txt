www.win2.cn/f
1   22.03.07	memtest1 	Working wersion of memetest to IAR.
2   26.03.07	memtest2	Many disabled in init.c - bin file is loaded to debug chennel can get low or not pin 78.
3   26.03.07	memtest3	make loop for high or low for .bin file; it is download and work!
4   --		memtest4	can go to pmc_mckr it comment  a.s. on it hangt. 
5   --		_5		for slow clocks make void delay_ms to view on tester.	
6   --		_6		not hangt.
7   02.04.07	m_7		first try to start on emb.
8   --		m_8		After make link from 0x200000 have maender on pin PB0 (Pin80)!!!!!!! Plata emb!!!!
9   --		m_9		work P80 on-off in main loop. Need make property clocks< right init sdram and flash<and finish xmodem.
10  --		m_10		Correctly initialized debug uart.
11  --		m_11		Write any strings to debug port.
12  --		m_12		Link at 0x200000 not work, link at 0x00000000 work!!
13 05.04.07	four 		empty projekt compiled by metadeveloper
14 06.04.07	five		proekt widch mqx option, compiled by metadeveloper.
15 --		five2		Debugger nat get off after try loading programm 
16 --		five3		Try link as address 0x0000. Make linker.cdb file.
17 --		m_13		working memory test for AS-9200.
18 --		m_14		maked binary file.
19 06.04.11	v18		start to make on iar loader to emb.
20 --		v18_1		work print to debug channel in emb.
21 --		v18_3		start added dataflash.
22 --		v18.._4		next step to read data flach and jump to sdram. maked heap 500 -> 200 and rom size 12 -> 13
23 --		v18.._5		first step to make assembler jump to address.
24 --		v18.._6		work jump to address now is 0x20000.
25 --		v18.._7		next step to read data flash.
26 --		v18.._8		--
27 --		v18.._9
28 --		v18.._10	cyckling view spi on oscilloscop.
29 --		v18.._11	view reading setted size of flash.
30 --		v18.._12	read some value from flash and jump to setted address. Need make writing!
31 --		v18.._13	read and jump are commented start making write.
32 --		v18.._14	next step to making write flash.
33 --		v18.._15	Go back to line read and jump - writing make from lpt.
34 06.04.13	v19.._1		Start making copy to sdram and jump to programm.
35 --		v19.._2		Remove all functions with flash.
36 --		v19.._3		Next step.
37 06.04.16     Jack5_1		Succesful frite to flash.
38 --		Jack5_2		Make right indikating status, reading 100 k. Need make start page.
39 --		Jack5_3		Next step.
40 --		Jack5_4		After set 120 Oms - work some.
44 --		Jack5_5		Work full.
45 --		v20_		Is written romboot.bin from atmel widch changed 6-s vector!!!
46 --		v22		Is compiled in ads1.2 romboot!!!!!!
47 --		v22_1		Maked radian header. Need: change start uboot address, size of uboot, oszillator freqs.
48 --		v22_2		Correct sdram init, maked start address for programm 40 page. In .bin file is added fo 6 vector : 17; a0; 41; 08 (11776 bytes loaded)
49 --		v22_3		Get off function reset registers to work programm started in sdram - it work!
50 --		v23		Imitation of main programm, their is be downloaded and work in sdram - work!
51 --		v23_1		make main application size 182 k and it is loaded by bootrom and work! 
52 --		v27		File is compiled by metadeveloper and not have abort data.
53 06.04.17	v27_1		have mesage -undef found ; in simulator all work!
54 --		v28		some time work at as9200 and later restart.
55 --		demo		work in simulator, but not have some about at91rm9200.
56 06.04.19	v29_full	maiby work on as-9200 widch load 0x20000000 and start from 0x20000f20
57 06.04.20	v30		make bootrom for emb widch quartz 18.432 MHz start from 0x20000f20.
58 --		v30_1		make bootrom widch flash address of main programm 0xc081000.
59 
59 06.04.26     v32_2		in link.met are changed ram to rwmem and rom to romem to property jump to start_os.
59 06.04.23	v30_2		my main work if copy to 0x20000000 and jump to 0x20000000.
60 --		v23_2		is property loaded to v30_2 to sdram and work.
61 --		v32		Any step to work widch io port in mqx.
62 --		v32_1		Next step.
63 --		v32_2		Try make serial, or jump1(0) - but not view effect.
64 06.05.12     source		This version mqx get toggles io pin for demo example. 
65 --		demo1		Binary file from demo can be load and con toggle io pin b0!
66 07.05.16     source1		added asm_test and toggling io pin.
67 07.05.21	asm_test	asm test work in thumb and property go back to thumb-mqx
68 --		demo2		compare for register r2 do not work in debug mode but work in .bin file!(Pogramm not cyckling) 
69 070522	source2		Can go in _shed_start_internal!
70 --		source3		Work 3 tasks after start! btimeslice, atimeslice, main!
71 070523	demo3		comment msgg_send() in main task and have 19 times the activity of tasks!
72 070524	source4		Add IDLE_TASK and view toggling io pin from main task.
73 --		demo4		-"-
74 --		demo5		If add in main_task time_delay_ticks() to have working idle task!
75 --		source6, demo6: Can view any enover tasks in debugger.
76 070528       hello5_1	Start of ethernet. Can start in simulator.
77 --		hello6		Generate one task and can view statistical data in performance tool widch working in hardvare.
78 070530	hello7_1 & source7_1	Can view in .dat file any interrupts and tcpip activity.
79 --		hello7_2 & source7_2 & rtsc Can view in kernel config time in millisecs. Work performance tool. View any interrupts. Whu bsp_timer_isr address is zero?
80 070531       hello7_3 & source7_3	View statistics : ip statistics : total received 1 rx discarded 1! Discarded illegal destination 1. And have ip if statistics : 3 bursts are received.
81 070601	hello7_4		Any next point.
82 --		hello7_5, source7_5, souec_rtsc7_5  : WORK PING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ip address : 155.155.155.15
83 070604	hello7_6, source7_6 Remove "io_toggle" from all to start making .bin can start. ping work if it start AFTER!!! start this application in debugger!
84 --		hello7_7		Added to main loop toggling io.
85 --		hello7_8 & source7_8    Added toggling io at start of the programm. Work widch ping. Can view starting toggling at programm start from .bin file.
85 --		hello7_8  --
86 070605       hello7_10 & source 7_10 start of new day.
87 --		hello7_11 & source 7_11	maked toggling io between callins of main task. It are 5 ms, period 10 ms. Ping work.
88 --		hello7_12 & source7_12	is loaded from .bin! but from bin timer do not work and not start without ethernet bursts
89 --		hello7_13 & source7_13	can be started without ethernet cable (get out long loop in autonegotiation). work from .bin. ping work from bin only one time.
90 --		hello7_16, source7_16, source_rtsc7_16   ping work.
91 070606	hello7_17, source7_17	work from .bin file : maked struct MQX_intt_struct locally. ping work from debugger , application from .bin where stopped.
92 070607	hello7_18, source7_18 go from bin file to main.
93 --		hello7_19, source7_19 go back from 7_17 to can view all tasks. work from .bin, ping work from debugger, from bin pping do not work.		
94 070608	hello7_20, source7_20	make archiv before add snmp.
95 --		hello7_21, source7_21   can view snmp agent in task summary. timer now do not work 
96 --		hello7_22, source7_22	timer work! snmp wiev in tasks, ping on debugger work.
97 070609       hello7_23, source7_23	try make pingfrom .bin start new day.
98 --		_24			start try change isr
99 --		_25			in file eninit.c : void enet_isr: get off back pressure; and uncomment clear and set receive enable bit : receive frames get more better!
100 --		_26			in file enetprv.h change rxring_len 1 to 2. Work if start under ping ? - not ewer, but not lost bursts if started. .bin not loadoble on as-9200, loadable on emb.
101 --          v30_ada_boot1_3_slow_clocks	version bootloader for emb ,working on slow clocks
102 --		v33_romboot_as9200		?? bootloader for as-9200?
103 070613	hello7_27, source7_27		start new day. ping work good, start from .bin do not work?
104 --		_28				any try make in slow_clock _rad init of the clock block.
105 070614	_29				get back in _mqx_init_kernel_data_internal to arc variant ping from debugger work.
106 --		_30 little step. 		ping from debugger work , in  .bin can view two togglings.
107 --		_31				from .bin mmu not init, try get off mmu - ping fork 10 times faster from debugger!
108 070615	_32				add to asm_start switch_to_sVc macro, but do not view some changes.
109 --		_33				move second toggle_io() to shed_start_internal - ping work in debugger; add command "e" to uboot - load programm to tftp.
110 070618	_34				send deklaration of task_template_struck into void _mqx - sheduler work from .bin
111 --		_35				maked that we can view enet interrupts event - as change state of io pin.
112 --		_36				can view ping from "run e" command for u-boot - load bin from tftp.
113 070619	_37				start new day. ping do work from debugger, tasks are start from .bin
114 070620	_39				start new day maked _task_create1 and tested creating rtcs task.
115 070621	_40				start new day
116 070622	_41				after many not needed changes of debug init tcpip task. ping on debugger work.
117 070625	_42				start new day ping work from debugger.
118 --		_43				can control idle_task from stephany5 ping work from debugger.
119 070626	_44				remove init globals for rtcs to file rtcscmd.c stack_size is correct now!!!
120 070627	_45				any try making enet init. find hanging in _QUEUE_LINK. ping do not work. go back to version _43.
121 --		_46				maked from _43 changed files rtcscmd.c (added init global variables) and mqx_prv.h (comment nxt->prev =...). Very long time it was work from .bin
122 070628	_47				maked correctly removing nxt->prev from macros .._LINK  not work ping from .bin not start after long power off.
123 --		_48				remove two constants into void bsp_enable_card
124 --		_49				set nxt back in makros - if tasks use this macros it hangt. ping work about nxt - big ???
125 070629	_50				rtcs start from cold state!!!!! this point is start for make cold ping and enover changes. snmp and tftp are commented  queue is overlov tcpip not start
126 --		_51				start point to go for. tftp and snmp are coomented,  in rtce added init global veriables. need check start this from cold state, after this make ping. Now ping work from debugger!!! Not work from cold state.
127 --		_52				comment in hello.c all about rtcs.Mqx hier is start from cold state!!!  if add _51 sources -> this is working mqx!!!!!!!!!!!!!
128 --		_53				rtcs_create is start from cold!? maked lwsem_wait1 widch commented _sched_execute_scheduler_internal. if uncomment if bind if_add and gate_add and run from debugger - ping work! This is point "2" for next. 
129 070702	_54				start of new day. if return from enet_initialize before chip initialize sheduler work from cold flash "run f" it work not so as "run e" - hot restart.
130 --		_55				work half of rtcs_if_add(); maked init of rtcs_enet, RTCS_IF_ENET in RTCS_create().
131 --		_56				comment _task_block() in _msgq_send_internal1 in file ms_sendi.c - have toggling after RTCS_if_add(). If will be du not work ping - need check - why we have _task_block()
132 --		_57				change in if_bind and in gate_add  _msgq_send_internal to _msgq_send_internal1 - view toggling after all from cold. ping from cold do not work.
133 --		_58				maked from _53; added init of RTCS_IF_ENET in rtcscmd.c ; if uncomment if_bind and if_add ping work from debugger and debugger get view of tasks state and kernel. should be work from cold this is point "3" of make mqx. 
134 --		_58_NEXT			maked only in rtcs init RTCS_IF_LOCALHOST and RTCS_IF_PPP it is need to do.
135 070703	_59				added snmp agent, ping work from debugger, debugger get info about mqx, need check from cold!!!! 
136 070704	_60				checked from cold - run ping bin (if snmp comment?) do not now this. snmp run up debugger!!! need add velues to data, ifsnmp request get from cold this stopped ping - need find snmp uninit variables. without snmp this is point "4" to make mqx rtcs.
137 --		_61				added and after checking - comment mib1213_init() - after this can view up debugger answer to snmp request without errors. mibclient can view devise. if comment mib1213_init can start from cold. maybe need mib1213_init before snmp_init? it have many uninit global variables! i can make mymib. this is point "5" to make mqx!
138 070705	_62				added half of mib1213_init() comment is RTCSMIB_mib_add(). maked only one snmp node - ? thi is correct? Can start from cold.  This is point "6" to make mqx.
139 --		_63				added to mib1213_init() init two nodes and uncomment RTCSMIB_mib_add(). can start from cold. this is point "7" to make mqx.
140 --		_64				make init of nodes their are in mib.c -> ping not get off by snmp discovery.Can start from cold. This is point "8" to make mqx. 
141 070706	_65				make more nodes for mib1213. can start from cold, not breack off if maked snmp request. Point "9".
142 --		_66				maked from _61 add last1213.c to can view sysname need comment two lines in his init //MIBNODE_sysName.TYPE = RTCSMIB_NODETYPE_INT_CONST //MIBNODE_sysName.GET.INT_PTR = NULL; - after this can view in mibclient sysname. need check from cold. - after cold programm go, but not view answers of data to snmp request - view only NULL.
143 --		_67				up debugger get to snmp time, from cold - not state no such name  -? need init node snmp - innosuchname and others?  if run from cold to enover features - can be point.
144 070709	_68				if make snmp discavery, after this make get for sustime- view answer witch system time!!!!! from cold!!!! after this not view any answers for anybody if not make reset.
145 --		_69				delete error : mibnode_syscontact was declared locally!!! Now answer from cold to snmp discavery!!!!!
146 070710	_70				snmp command "get" run from cold. this is point "10" to make mqx. Start making com port.
147 070711	_71				to make init uart comment lwsem_wait and lwsem_post in _io_dev_install_ext1 first step to make uart.
148 --		_72				make fh_ptr = (pointer)_io_fopen1("ittyb:", IO_SERIAL_RAW_IO); - need it?
149 --		_73				can print to debug uart!!!!! need make read. this is point "11" to make mqx? - need check from cold.
150 070713	_74				maked output from polled debug uart
151 --		_75				have any reaction in cyckling polled reading to type any key!!!!! funktion go to enover vey if ping key in terminal programm!!!!
152 070716	_76				function fgetc work!!! can read symbol from serial port.!!!!
153 --		_77				can use fflush to clear file! printed to terminal symbols getted back!
154 --		_78				make start menu skeleton. 
155 070717	_79				Is maked toggling pin c13 - LED in future and setting pin PA23 as input pin for irq3.
156 --		_80				Maked ISR to irq3 to edge.
157 070718	_81				Maked isr for irq2, irq1, irq0.
158 --		_82				Maked isr for fiq.
159 --		_83				Maked lovest priority for fiq to not have hangt situation.
160 070719	_84				Can view as io devises nvram and xilinx.
161 --		_85				if make cyckling, can view cs0 on oscilloscope. cs2 is olweis in zero?
162 070720	_86				work cs2.
163 --		_87				maked template for spi driver
164 070724	_88				Next step to make spi driver.
165 --		_89				View some moving on spi "0"?
166 --		_90				View moving on spi1.
167 --		_91				View moving on spi1.
168 --		_92				View fast cs on spi1!!!!!!!!!!!!!!
169 070725	_93				Comment spi, start porting dataflash functions from atmel to mqx. All tested. Point "12".
170 --		_94				maked first version projekt witch functions of dataflach.
171 --		_95				init of debug uart moved in init_bsp.c not correctlu work reading keys, but printf work!!!
172 070726	_96				next step to make dataflash - somthing work undo debuger from cold state do not view somthing.
173 --		_97				print somfing about flash from cold state.
174 --		_98				correctly printed info about flash on cs0. maked sources for cs1 but do not check.
175 --		_99				added check of write-read flash cs0.
176 --		_100				correctly work dialog at start.
177 --		_101				maked first version of polled usart1.
178 070730	_102				start new day to making usart1.
179 --		_103				after enabling clocks in pmc for usart1 - view data on output usart1!!!!
180 --		_104				maked usart1 in 485 mode.
181 --		MibClient_1			compollid on computer EMB version of snmp server to con operate snmp-devises.
182 070731	Mover1				First step to make snmp server.
183 --		MibClient_2_1			Can send somthing from menu item options->SetName
184 --		_2				Can send command "set"!!!!!
Now is need write all to /arc1/
185 070801	MibClient2_3			Can send oid to snmp "set" burst.
186 --		_4				can send new name to snmp. this breack down mqx now!
187 --		source_rtcs7_105,hello7_105     Runned snmp command "set" for SysName, but functions memory_free is commented!!!! Need make it to not lost memory!!!!
188 --		_106				command "set" work , memory block maked as free, but not can coalesced to enover blocks.
189 070802	_107				maked going widch error from mem_free (file : mem_free.c : comment pregms # if MQX_check_errors). Setting name was go without hanging devise.
190 --		MibClient2_5			maked command set for concrete ip address.
191 --		Mover2				fully compilled and linked "empty" projekt for snmp dialog.
192 070803	Mover3				Can set only one time request "get".
193 --		Mover4				Can many times seng request "get".
195 --		Mover5				Can send command "set".
196 --		Mover6				View in debugger going into onsnmpreceive after send or receive snmp burst.
197 --		Mover7				Can view data from snmp in cedit box!
198 --		Mover8				Make command get to concrete ip address and view data from concrete ip address.
199 --		_9				Property set name - deleted nod needed .0 in sended oid.
200 --		_10				Can set and read name to snmp.
201 --		_11				Maked release of mover.
202 --		_12				Maked IP address.
203 070806	hello7_108			Is tested to making long devise service function - void Device() - MQX get time to it. 
204 --		_109				work data out from usart1 in interrupt mode.
205		_110				work input and output in interrupt mode to usart1!!!!!!!!!
206 --		Mover13				maked destructors to correctly exit from mover.
207 070807	_111				Can make restart devise from start menu - use watchdog.
208 --		_112				Added internal watchdog to devise.
209 --		_113				Added node for restart devise.1.3.6.1.1.0
210 --		Mover14				Added buttons to restart devise. 
211 --		hello7_114			first step to  try use classes.
212 --		_115				Is tested using cpp classes in programm.
213 070808	Mover15				Can view in ethereal answer from devise to request gettime.
214 --		Mover16				Can view unformatted value of time in the dialog.
215 --		Mover17				Can view formatted value of time in dialog.
216 --		Mover18				First step to make reading data from devise.
217 --		Mover19				Correctly send address to devise if read data.
218 070809	_116				Can send any data to snmp request from work.c.
219 --		Mover20				--.
220 --		Mover21				Next step to view data.
221 --		_117				--.
222 --		Mover22				Can read data from devise.
223 --		hello7_118			--.
224 070810	_119				Can write somthing to devise.
225 --		Mover23				--.
226 --		_120				Correctly SNMP write and read from high addresses 0xffffffff.
227 --		_121				Maked correctly work widch short addresses and short data.
228 --		Mover24				--.
229 --		_122				Maked readin and writing from mover to cs0 and cs2.
230 070813	_123				Remove using of the piob0 to prepare load xilinx through ssc.
231 070814	_124				Next point to making loading xilinx.
232 --		_125				View any data and clocks on outputs SSC0 !!!!
233 070815	_126				Porting example for audio application for ssc0. This is "fixed point".
234 --		_127				View continuosly generated 8 bytes. Any little error in snmp.
235 --		_128				Deleted error in snmp.
236 --		_129				View data from flash on ssc output.
237 070816	_130				Cange address in flash for xilinx now is 0xc07c0000. View right two bytes on ssc output.
238 --		_131				Start clocks of ssc moved to start of data.
239 070817	_132				First version loading xilinx.
240 --		_133				Start version of remote for usart1. First time devise restarted, but next time answer property. 
241 --		_134				Delete "strtok". Devise not restarted. Have answers to command. Need make any test right command. Mayby make some classes of data?
242 070820	_135				First version of class mdatac. Was need to make init of class exemplar function. Need make operate of storage, display, snmp, and correct format for print to remote.
243 --		_136				View correct answer to remote.
244 --		_137				Make to line PCK0 to xilinx 18,432 MHz.
245 070821	_138				Maked first version of storage. Need check in hardware.
246 --		_139				This version can run one time command from snmp witch serial remote protokol.
247 --		Mover25				Send from snmp commands for remote protokol.
248 --		_140				View answers to serial commands in snmp.
249 --		_141				Work serial protocol through snmp.
250 --		Mover26				Add ';' to end of command to run end commands in line. not need add to end '.' and to start '#00'.				
251 070822	_142				Added functions to can write to xilinx in running any remote commands.
252 --		_143				Added to projekt class MDataI.
253 070831	_144				Added class MDataV.
254 --		_145				Was added classes Item and Menu. Need make support of display and kbd.
255 070903	_146				First step to work widch pult-rs232.
256 --		_147				Maked transmit to interrupts.
257 --		_148				Maked transmit widch buffer.
258 070904	_149				First step to make init of usart0 and usart3. transmitters are in reset and are not ready.
259 --		_150				Next step to make serial ports. Need make switch debug uart <> usart0 and operate of idcommand for all ports.
260 --		_151				Maked self parser for every usart. Need make self buffers  and parser for snmp. and swtch debug uart <> usart0.
261 --		_152				Maked selector of debug uart or usart0.
262 070905	_153				Maked RunRemoteCS.
263 --		_154				Maked RunRemoteVS, RunRemoteIS.
264 --		_155				Maked rightu using transmit buffeer for usart3. This can be "Point". 
265 --		_156				Start making changable IP address.
266 --		_157				To remote command can be add second, third and ...IP address - devise can have many ip addresses. Need remove old address.
267 --		_158				Can unbind old ip address.
268 070906	source7_159			Make widch mmu all as i will: now mmu disabled, cashes are enabled.
269 --		_160				Deleted error in remote : in last answer "K1" symbol "1"  was not getted.
270 --		_161				Work jump to "AT91C_JUMP_ADDR" - 32 bits mode!!!!! Jump commented before pack.
271 --		_162				Work Jump to any "C" function m_uart_init - 16 bits mode. Jump commented before pack.
272 --		_163				Maked on ftp server - it ansver for connect : >ftp 155.155.155.15 -> : 220 Precise/RTCS FTP Ready 220 Precise/RTCS FTP Ready User (155.155.155.15:(none)):.
273 070907	_164				FTP server not start after night. TFTP server start. This can be "Point".
274 --		_165				Maked blinking of LED to 0,5 sec.
275 --		_166				First port of EmbIsr of Max.
276 070910	_167				Next step to port embisr.
277 --		_168				--
278 --		_169				EmbIsr is ported as possible without hardvare.
279 --		_170				usart1 and usart0 are init to data rate 38400.
280 070911	_171				First step to try make tftp. Maked in tftpacc enabling to write and read files to tftp.
281 --		_172				Added to rtcscmd.c #define fopen io_fopen1. After this tcpip task not blocked an i have answer "file not found". May be need file create before open?; View send file out to name dbug_uart:out!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
282 --		_173				Work many times tftp file send asm_test to dbug_uart:asm_test!!!!!!!!!!!!!! If i try read from dbug_uart:test to file "test" and ping keys i view in readed file this keys!!!!!!!!!!!!!!!!!
283 --		_174				Added internal devise : sdram - can read sdram from tftp. If try write - have restart - need use addresses += 4! for sdram and write for 32 bits words.
284 070912	_175				define fopen moved to rtcs.h tested tftp. 
285 --		_176			  	if uncomment rtcs_load_tftp_bin() application can load any data to sdram. One block  size of data setted 128; loop "while" is commented.  uncomment "while" is need think.
286 070913	_177				Maked in start menu reading and writing to cs0 and cs2.
287 --		Mover27				Can write data to devise from file.
289 --		Mover28				Make shorter delay between snmp bursts.
290 070914	Mover29				Mover can send remote commands for parser of devise commands.
291 --		_178				First step to port mf20_3.cpp.
292 --		_179				Next step to port mf20_3.
293 --		_180				--
294 070917	_181				--
295 --		_182				Added AsciiInit().
296 --		_183				Maked call of embtimer.IsrXX() witch rate 0,2 ms. (need o,1 ms)
297 --		_184				Maked call rate 0,125 ms. 
298 --		_185				Maked reading clocks of timekeeper.
299 070918	_186				Can set date and time in start menu.	
300 --		_187				Can exchange data from start menu.
301 --		_188				Start making setting ip address from start menu.
302 070919	_189				Can set IP address from start menu.
303 --		_190				Start making class MDataS. Usart0 and 1 getted back to 38400.
304 --		_191				Have remote command "N1" to operate through void DeviseData() with internal address area.
305 --		JackS50				Start make programm, sends file to comport.
306 070920	_51				Get message to error.
307 --		hello7_192			To not get off hello task temporary get off mf20_init() mf20() and timer interrupt for mf20 -? we have not area for any? In parser for usart1 for MDataS deleted error to ++ pointer.
308 070921	JackS52				View answers "K0".
309 --		hello7_193			Make _time_notify_kernel() in 5 times rejekting as time_notify_core() have property answers to remote - somtime bad answers; address parser not olweis right.  
310 --		Jacks53				Often have property answers.
311 --		hello7_194			If get off idle task and set mximum priority - have property work widch usart1.
312 --		_195				Make blink LED and max priority for all usarts.
313 --		JackS54				Can send file to address space.
314 --		JackS55				Make better view. Somtime devise getted off.
315 --		_196				Make reset from snmp back.
316 070924	_197				Work remote restart to snmp.
317 --		JackS56				Add delay to can load to internal address space any data from uart.
318 --		_57				Use answer from devise to operate it.
319 --		hello7_198, source7_198		Make usart1 interrupt not shared to system timer!!!!!!!!!!!
320 --		JackS58				Next version of JackS - close file if devise not answer and use two times try sending command.
321 070925	_199t				Test version cyckling if addr != 0x200000000; serial work if ethernet getted off.
322 --		_200t				Work better, but somtime loss symbols in serial.
323 070926	_201				Maked getting off ethernet to 10 ms if received in serial valid address; can load serial commands if send first dummu command widch valid address and after this send commands without delau more 10 ms. Usarts 0 1 and 3 maked to self interrupt.
324 --		JackS59				Make dummu command before load file to devise to get off ethernet.
325 --		JackS60				Get message if com port is used by another programm.
326 --		_61				Use MFC as static library. 
327 ==		_62				Can send commands from file.
328 --		_63				Added window "answer".
329 070927	_64				Start makking read and write to address.
330 --		_65				Maked log to load data from file.
331 --		_66				Can set data to address.
332 --		_67				Can read and write data to any address through uart.
333 --		hello7_202			Added command to restart devise: "#00@1."
334 --		JackS_68			Added button to restart devise.
335 071003	v33_7_1				view impulses on outpet c13!
336 --		_203				Get back toggling io in start mqx to making my romboot.
337 071004	v33_7_2, _204			If not change programm, run debugger, wait while mqx start and reload programm and start from debugger it work!!!!!!
338 --		v33_7_romboot_emb_3		If loat rombootr.bin (vector 6 is corrected) - can write flash!!!!!!!!!!
339 071005	v33_7_romboot_emb_4		Can write big files >131k!!!!!
340 071008	v33_7_5	. _205			Comment init stack for system mode - blink led after reset.
341 --		v33_7_6,  _206			After making go to interrupt and from interrupt in svc mode, init stack of svc mode last and not change cpsr in jump - mqx start!
342 --		v33_7_7				Disable interrupts before start to mqx - mqx stort sucsesful more often.
343 --		v33_7_8				Maked init system mode stack, max size to download 8MB, can view first bytes the file of MQX.
344 --		source7_207			maked back init in int_inst.c init of stack for system mode.
345 071009	hello7_208			getted on many funktions ; are off loading xilinx and mf20.
346 --		v33_7_9a			not working bootloader, but witch it if write to flach .bin as mqx and make start mqx , and reload after first start - can view mqx information
347 --		v33_7_10			Added delay after load pll and load in cpsr not 0xd3 but 0x13.
348 --		v33_7_11			Work bad but sometime work.
349 --		v33_7_12			Work better, but somtime not load.
350 071010	hello7_209			Make XilAddressToDownload to lower 16M - not have interrupt if try write data for xilinx in not setted higher 16M!
351 071011	v33_7_13			Make version to feature as load programm to memory from rs232 and jump to it.
352 --		v33_8_1				Make romboot to sdram 9 columns (8x16) - to use 32 MSDRAM.
353 --		hello7_210			Delete error in init ssc - to semd msb in ever byte first.
354 071014	hello7_211			First loading xilinx!!!! All interrupts are disabled- need any enable back.
355 --		_212				Sometime not olwais xilinx is loaded.
356 --		_213				Three times try load xilinx.
357 071015	_214				Xilinx is load stability: clocks for spi changed from 10 MHz to 2 MHz.
358 --		FileConvXil			Add 32 bytes defore data to file of xilinx to changing vector 6 not damage data.
359 --		_215				Remove from mqx.c call clock_low_rad and toggle_io
360 071017	_216				Make right cs2 init.
361 --		_217				Make reading data from xilinx not in irq2 - devise not hangt to irq2.
362 --		_218				Can write on LED.
363 --		_219				Next version writing an lcd and test LED.
364 071018	_220				--.
365 --		_221				If isable irq2 before init pult - writing logo not hangt.
366 --		_222				Init pult to not have irqs to transmit - to not hangt.
367 --		_223				work widch keys to irq2.
368 --		_224				full add data for mf20.
369 --		_225				really add data from usart0 to receve buffer of emb.
370 --		_227				Make dara rate for usart0 38400 and make usart0 on before start work loop.
371 071019	_228				Maked bigger delay to init ethernet and first item menu.
372 --		_229				Can go between menu items to keys enter and esc. If slovly ping only this items all work.			
373 071022	_230				Delete error in menu - if get to next item was not checked if is it NULL.
374 --		_231				Print on display string to interrupt, but only second string - need make oneoperation to print full indikator.
375 --		_232				Use two buffers for two string of display. For data - can use every buffer.
376 --		_233				Next step - if slowly ping - work two strings.
377 --		_234				Make interrupts counter - if fast ping keys pult work not stopped.
378 -- 		_235				Work tickets - have zummer on ping keys - ? need use command for full string for item to do not work too long.
379 --		_236				Use command "I" for send items - not view not needed symbols on indicator.
380 --		_237				Maked item without data "IP address".
381 071023	_238				Can view mdatac0.
382 --		_239				Start making gotoxy as buffer command.
283 --		_240				Start make IBuffer as common transmit buffer.
284 --		_241				IBuffer used more.
285 --		_242				More use IBuffer. Property setted cursor if changed data.
286 --		_243				Storage work for MdataC?
287 --		_244				Maked IPAddress2.
288 --		_245				Maked on indikator menu item and datra ip address. Need make real set function.
289 --		_246				Maked exchange IPAddress0,1,2,3 widch IPAddress.
290 071024	_247				Maked Ring(), and little change in init enet.
291 --		_248				All cprintfs maked to using function ToIBuf.
292 --		_249				Maked any try to check property init of ENET. If not good - restart.
293 --		_250				Start making menu item uart address.
294 --		_251				Maked data for menu item UART address.
295 --		_252				Maked working address for uart remote channels.
296 071025	_253				Make redrawperiod to from remote not can be overflow buffer of data for pult.
297 --		_254				Make correctly printing message if setted value of data is not alloved.	
298 --		_255				Maked correctly control of data.
299 --		_256				Make parser of usart0 not in body of interrupt.
300 --		_257				For all usarts make parsers not in bodies of interrupts.
301 071026	_258				In background read pult to anybody not can hengt one.
302 --		_259				Added control to size of remote address for objekt class MDataS DevData. May be need and control  size of data.
303 071029	_260				If number of devise is not zero - mf20cfg3 can operate witch it.
304 071030	_261				Maked init of global variables for mf20 to not hangt to remote.
305 --		_262				Start making port for addrRam of mf20.
306 --		_263				Devise not hangt if try read or write cnfg - commented operations 05 - write and 06 - read.
307 --		_264				Can read data from nvram. Need make write. 
308 --		_265				Can write and read configuration from start address nvram. Not hangt. Need check structures ul2uc; ui2uc - from this deklared char long can be not collect.
309 071031	_266				Make eth_off if have usart0 interrupt - to property work emb remote for mf20. Have results.
310 --		_267				Delete error - now in init objekts of MDataV and MDataC not try write in zero address of nvram.
311 --		_268				Make Munu item now without data IDItem.
312 --		_269				Delete error to right change hexdecimal value in menu.
313 --		_270				Maked objekts of MDataC for devise ID parameters.
314 --		_271				Can keep devise ID parameters in flash.
315 071101	_272				Full make devise id parameters and delete some errors in menu and remote.
316 --		_273				Maked data objekt POK - "Programm OK" keep in last page of flash +8 and +9 if POK == 0 start uboot else start work programm.
317 --		v37_BL_Select_1			Start make bootloader without menu and can select - what load : uboot or mqx.
318 --		v37_BL_Select_2			If set pll to 180 MHz - to can view munu from UBoot and starting UBOOT!!!!
319 --		v37_BL_Select_3			If POK NOT setted to 0x1000 go to uboot, else direct start mqx; menu for change bootloader keep, but unvisible - if press Enter at start and use keys - can use all points of start menu : change uboot, bootloader and read-write memory. Can set in uboot automatic rewrite programm from tftp witch delay.
320 --		_274				Not enable write in nvram in writestorages if address is zero. Remove from start all printfs.
321 071102	v37_BL_Select_4			Can start uboot from cold.
322 --		v37_BL_Select_5			Make at91_spi_clk from 10 MHz to 500 kHz and bigger delay for mck.
323 --		_6				Make at91_spi_clk 1 MHz, make plla to 180 mhz sdram refresh 816 times. Work better
324 --		_7				== _6 ?
325 --		_275				Not ping PLL and mck - not have messages  -UNDEF
326 --		v37_BL_Select_8			Load mqx from flash 2 times; make freq for spi 2 MHz, write in 8 MB sdram zeros.
327 --		_276				Get back ping pll and mck to will be work USRT0.
328 --		_277				Start debug BU in case witch enover blocks. Delete one error : "0x300+" can print to terminal current state; MF20 is init after delay.
329 --		_278				Can view PK2 in case.
330 071106	_279				Make reading config from blocks 7 0x7f - can view in case blocks sl4.
331 --		_280				Make all variables in void mf20() as "static"  as this work in mf20 as everytime loop.
332 --		mf20cfg3_1			Compare ticker to 20 to not clear configuration. Need check - why have so long delay?				
333 071108	_281				Maked void SaveCommut1. It work with 32 types of blocks - not 128 - work correct witch mf20cfg3 if is pinget "Load Configuration".
334 --		_282				Make long savecommut2 - every slot in its time with big delay.
335 071109	_283				Work widh block without section : make any witch receive buffer ::Get.
336 --		v37_BL_Select_9			Make not reading keys in start mode pok = 1000. Can start with working mf20cfg3.
337 071112	_284				Maked control for TestMode objekt.
338 071113	_285				First step to try using snmp on mf20 exchnging data.
339 --		_286				Maked Byte exchange witch mf20 through snmp commands "BJ"(write Byte) and "BK"(read byte). Temporary answers going to rs232 also. 
340 --		mf20cfg3snmp_1			First step to make mf20cfg3snmp.
341 --		_2				Maked some dialogs.
342 --		_3				Added class moverdlg; m_hwnd is not init!
343 071114	_4				Have message Error Init SNMP.
344 --		_5				Start make SNMP direct in class Mf20cfg3.
345 --		_6				Can send command "BK" to mf20 and have ansver.
346 --		_7				Delete including moverdlg.h.
347 --		_8				Make little changes in arguments of functions.
348 --		hello7_287			First try using big buffer.
349 --		_288				Temporary make little buffer to 23 bytes - it work. highest byte of len need make & 0x7F to get off highest byte. 
350 071115	_289				Work buffer for transmit to 150 Bytes.
351 --		_290				Maked correct len in answer to command BM.
352 --		mf20cfg3snmp_10			Start making receive of snmp.
353 --		mf20cfg3snmp_11			After adding messages snmp and tcp to message map view receive of snmp.
354 --		_12				Try send command "BN" with buffer of data.
355 --		_13				Can view answers "U" from devise.
356 --		hello7_291			--.
357 071116	Mf20cfg3snmp_14			Maked function OnSendCommandFull - it can send command with zeros in body.
358 --		hello7_292			Maked void Mf20RBuff - to can fill rs232 receive buffer mf20  from snmp. View as mf20 trying to get answer. Need make so functions for answers of mf20.
359 --		source_rtcs7_292		Make mib node 1361414 to fill rbuffer of mf20 from snmp.
360 --		hello7_293			Make first version for reading TBuffer1 node 13361415.
361 --		source_rtcs7_293		Make node 1361415 to read data from transmit buffer mf20.
362 --		Mf20cfg3snmp_15			Maked requests to 150 Bytes from mf20 to node 1361415.
363 --		hello7_294			Maked property reading TBuffer1 to node 1361415.
364 --		Mf20cfg3snmp_16			View number of MF20 to snmp!!!!!
365 071119	Mf20cfg3snmp_17			Added any sleep in any points - Can read configuration from ethernet!!!!!
366 --		_18				Make little change - compare numofserial with 2.
367 --		-19				Get bak any delay betveen bursts to have sequentally requests and answers.	
368 --		hello7_295			Make correct len in TBuff.Value[0] and [1] if buffer is readed and not fill.
369 --		Mf20cfg3snmp_20			Maked WatAnswer to not receive information if it is now received.
370 071120	Mf20cfg3snmp_21			Maked check counter to == 2 but not > 2 to not have dublokated requests.
371 --		_22				Maked setting to zero ticker if changed interface - not loss mf20 if change interface.
372 --		_23				Not olweis , slow can read configuration from ethernet without printing to uart.
373 --		hello7_296			Added delay to print in buffer to work reading configuration from snmp it work not olweis.
374 --		Mf20cfg3snmp_24			Ticker compare not to 3  but to 5 - reading of configuraTION work stabilly!!!!!!!!
375 --		hello7_297			Reading config work stabilly; now setted delay in transmit0c need try remove it.
376 071121	Mf20cfg3snmp_25			Maked progressbar.
377 --		hello7_298			Maked 3 - byte in every burst burst counter for check udp exchange.
378 --		Mf20cfg3snmp_26			--
379 --		hello7_299			Use two buffers for transmit.
380 --		Mf20cfg3snmp_27			Work witch two buffers.
381 --			_28			Deleted one Sleep(100) - work better!
382 --			_29			Deleted one Sleep(10) - work!
383 --			_30			Maked timer 40 - work faster.
384 --		hello7_300			Deleted error to init len = 3.
385 --		hello7_301			Maked delay_mcs(170) - work better.
386 --		Mf20cfg3snmp _31		Current work version.	
387 --		hello7_302			Maked init of transmit buffers in function of fill receive rs232 of mf20.	
388 --		Mf20cfg3snmp_32			Maked Have4 to indicate that is received answer to fill receive buffer and can be requested transmit buffer.
389 071122		_33			Maked clearing receive snmp buffer to not use second time old snmp answers.
390 --		hello7_303			Maked clearing transmit buffer before fill receive buffer.
391 --		Mf20cfg3snmp_34			Clear receive buffer if ping button "read configuration".
392 --			_35			Maked Have5. Need make bigger size of TBuffer to can write to it up to 160 Bytes - this is size of answer to getconfiguration. Now for work need make so delays - to it can moved to 3 bursts!!!!!			
393 --		Mf20cfg3snmp_35			Maked #define BURST_SIZE 200 - to can receive bursts longer 150. Make temporary more slow timer to cantroller can fill answer in first burst. Getlen() to answer command "06" get not right len!
394 --		hello7_304			Make more little delay in fill buffer - this enable fill it quickly.
395 --		Mf20cfg3_snmp_36		Correctly celling length of bursts.
396 --		hello7_305			Full remove delays in transmit0c.
397 --		Mf20cfg3snmp_37			Get back timer to 55ms. 
398 --		hello7_306			Remove prin type of message.
399 --		Mf20cfg3snmp_39			Work with Ethernet though used another programm com port.
400 071123	hello7_307			Deleted error in init of TRBuffer - need set buffsize - size; TESTED ON TDA5!!!!!!!
401 --		Mf20cfg3snmp_40			Can find mf20, if it get off and bak on.
402 071126	hello7_308			Deleted error in init buffers of remote mf20. His must be init at start of programm, undependently of detect of blocks!!!
403 071127	hello7_309			Start making adding two mdatac data in item.
404 --		hello7_310			Can write and read MAC address from flash and have menu item witch MAC.
405 --		hello7_311			MAC address from flash work for ethernet init.  
406 --		hello7_312			Make ten times checking of bit .Some to quckly work witch display. 
407 --		_313				Make 24 times - work faster.
408 --		Mf20cfg3snmp_41			Make more delay to load devise.
409 071128	hello7_314			Start meking using NVRAM witch pointers - not as file. 
410 --		hello7_316			Any step to use mf20 pointer : right init it in void init!!!!
411 --		hello7_317			Next step to use pointer to nvram.
412 --		hello7_318			Use pointer to xilinx addresses.
413 --		hello7_319			Remove operating witch files from functions to read-write xilinx and nvram. Tested on TDA-5.
414 --		hello7_320			Added delay 100 mcs to can view sothing on pult. In future need delete this delay.
415 --		hello7_321			Deleted delay, added time_delay_ticks(1) - ethernet work property. Pult work very slowly.
416 071129	hello7_322			To pult work faster change funktions operatedown and operateup - to redaraw only changed data - this work better.
417 --		_323				Make IRQ2 not in timer.
418 --		_324				If init usart0 after usart3 - devise start property witch working in this time programm mf20cfg3.exe.
419 071130	_325				Maked disabling interrupts before init uart and enabling after init. Devise not hanged if start witch working mf20 cfg3. 
420 071203	_326				Can read devise serial number from snmp from node SysObjektId - it is notcorrect - hier need get number of node to operate parameters.
421 --		_327				Make correctly get sysobjektid 1.3.6.1.4.1 (enterprises).
422 --		_328				Devise get to snmp syslocation and sysservises. 
423 071204	_329				Make some nodes up to any from udp.
424 --		_330				Work 15 nodes of snmp.
425 --		_331				All nodes of snmp are init.
426 071205	_332				Added some init nodes of tcp and udp and ip.
427 --		_333				Maked all working nodes in MQXZ. Not-working nodes are shorted to not get off snmp.
428 --		_334				IPaddress keep in one point nvram. Deleted error when reading from storage check key "Enter" - it not work now.
429 --		_335				Make address for uart 0xff - universally. On this address will be answered all devises!
430 --		_336				Devise print at start if test mode is not zero on rate 115200 to debug uart all variables: MAC address, UART address, Devise ID and enover.
431 --		_337				Void DeviseData more property check address to devise not hangt.
432 --		JackS69				Make data rate 38400, more delays, used universal uart address ff.
433 071206	JackS70				Can read IP address.
434 --		JackS71				Can set IP address.
435 --		JackS72				Can work witch POK.
436 --		JackS73				Can read and write all now knowned data.
437 071210	hello7_338			Not redraw item to startchanging and stopchanging -this work more quickly.
438 --		JackS74				Moke more comfortable interface with data.	
439 --		hello7_339			Load xilinx with added to begin 96 bytes.
440 --		FileConvXil_1			Convert any file : add at start of file 96 Bytes : date of last modyfing and name of converted filewith name _plus.
441 071211	hello7_340			Maked objekt XilFileData - can get information frome header of xilinx file - name and data of last modifikation.
442 --		FileConvXil_2			Added to header name before data.
443 --		hello7_341			Maked view xilinx file name and date in menu and receiving to remote.
444 --		JackS75				Can view version xilinx file.
445 --		truck1				Start making tftp truck.
446 071212	hello7_342t			Any step to make tftp : at strt programm called RTCS_load_TFTP_BIN().
447 --		_343t				Wotk 32-bits pointer for using sdram. For SDRAM not get char* pointer?	
448 071213	_344t				Use char buffer and not add betveen packets four bytes.
449 --		_345				Can load by means of TFTP files up to 500 kBytes.!!!!!!!
450 --		_346				Make tftp loading to remote command "BV":  #ffBV1. "1" - now dummu symbol.
451 --		_347				Tftp loading call moved to loaddevises().
452 --		_348 				Can write to flash file witch size of 250 k.
453 --		_349				Added to FileUpdateInFlash() calling usart_command_eth_on() to this function can be work from remote.
454 --		Mover30				Can get ip address of host and init tftp loading programm file to devise.
455 --		hello7_350			Receive command from host, read host IP address and load programm hello7.bin to his flash address.
456 --		Mover31				Can send name and data of file.
457 071214	hello7_351			Can read name of file for loading.
458 --		_352				Can read size of file for loading.
459 --		_354				Can read address for loading.
460 --		Mover_32			Can full write programm to address c07daf00.
461 --		Mover_33			Before write check programm file size.
462 --		Mover_34			Can write xilinx.
463 071217	hello7_355			Temporary stop trying load xilinx dyring ssc. This is mf20 without wd. Archivwd before start making md34.
464 --		_356				Added wd to mf_20.  FINAL OF MF20?________________________________________? Need make usart1.
465 --		hello7_357			Core , free from mf20 : can be start to many devises.
466 071218	hello7_358			First full compiled version bmd34 without timer, serials and interrupts and init and loop and loading xilinx.
467 --		hello7_359			BMD34 with uarts and interrupt.
468 071219	hello7_400			Can use ssc to load little xilinx!!!!! This wersion load xilinx in loop.
469 --		_401				Use ssc on 6 MHz to load xilinx.
470 --		_402				Load xilinx to many bloks size 20000 , to can load big xilinx.
471 --		_403				From cold state sucsessive load xilinx on 3 MHz. On 6 MHz do not load.
472 --		_404				Not meke "-1" to count xilinx load volume - to can use buffer 50000. Make buffer 30000.
473 --		_405				Can get to remote programm version.
474 --		JackS76				Can read version of programm.
475 --		JackS77				Can calling tftp loading programm to flash.
476 --		JackS78				Can calling tftp loading xilinx to flash.
477 --		Mover_35			Can get and set devise ID.
478 --		_36				-- Version.
479 --		_37				More best view.
480 071221	_38				Can get and set MAC address.
481 --		_39				-- USART address.
482 --		_40				POK and Test Mode.
483 --		_41				First release.
484 --		hello7_406			Maked WD to 30 secs.
485 071224	Mover_42			Make button "Load programm default".
486 --		Mover_43			Can set host IP for load programm and xilinx from enover host. Can be loaded from internet? Set POK to zero before start load programm. After loading need set POK to 0x1000 manually if all ok.
487 --		JackS79				Can change host IP for TFTP loading. 	
488 --		JackS80				Maket buttons LOad programm and xilinx default.
489 --		hello7_407			If set TestMode to '1' devise try load prog_test.bin from host 155.155.155.157 and jump to it.
490 --		_408				Can load file to TFTP buffer. Need copy data to setted address and start test programm.
491 --		JackS_81, Mover_44		Default xilinx file size maked as 70000 to not damage programm area!
492 --		v41_ads_try_main4		Start ok if load to 20000000 and go 20000000.
493 071225	hello7_409			If debug uart on, jump work in thumb mode can start ads compiled programm from mqx programm if will set test mode parameter to 1. 
494 --		v41_ads_try_main4_1		Compilled to address 201056a4 start first printing.
495 --		hello7_410			Are disabled interrupts and wd before start - loaded programm work full.
496 --		v41_ads_trymain4_2		Can read NVRAM!
497 --			_3			Can write NVRAM!
498 --			_4			Read and write xilinx addresses from 0x600 (pult). Commented writing to flash.
499 --		source7_411			maked file link_16M.met to using it for compilling programs with 9MB ram.
500 --		hello7_411			linked with link_16m.met to have ram 9MByte; maked TFTP_Buffer size 2MBYte.
512 --		_412				Can set test mode to 1 from snmp.
513 --		_413				Can load and run programm from all hosts to use fileupdate remote command.
514 --		Mover45				--
515 -- 		JackS82				-- 
516 071226	hello7_414			Xilinx file  moved to address 0xC0700000.
517 --		Mover46				--
518 --		JackS83.			--
519 --		hello7_415			Can load up to 3 xilinxes load_xilinx1(char pg). pg can be 1,2,3.
520 --		_416				Can get information about xilinx2 and xilinx3.
521 --		_417				Are testing 3 xilinxes, update xilinx information aftter writing.
522 --		JackS84				Can write xilinx2 and xilinx3.
523 --		Mover47				--.
524 071228	hello7_418			New address for ID 0xC0043000.
525 --		_419				New addresses for xilinxes : 0xc00A7000; 0xC0100000; 0xC01A0000.
526 --		JackS85				-- and for programm 0xC0044000.
527 --		Mover48				--
528 --		v37_BL_Select10			LOADER : make address for programm 0xC0044000 and ID address 0xC0043000.
529 --		v37_bl_select11			Remove path to /v33 and remove from menu start mqx and run programm.
530 --		Mover49				Added button "Add Header To Xilinx".
531 --		JackS86				--
532 --		hello7_420			Compilled back mf_20. Heve new xilinx and id plases. New programm place.
533 071229	Mover50				Have windows to set names of programm and xilinx files.
534 --		JackS87				--
535 --		hello7_421			Move tftp_buffer[] to address 0x20500000. To can compile loadable programm to fixed address.
536 080109	v41_ads_try_main4_5		Working test programm from address 0x20500000. Address for uart is 115200!!!!!
537 --		hello7_422			Tested work of test programm from address 0x20500000.
538 --		_423				Ported some tail of rs485 interface of bmd_34 to mf20.
539 --		_424				Put calccrc from bmd-34.
540 --		_425				Put answers to rs485 to mf20 from bmd_34. Tested witch mf20 cfg3.
541 --		_426				Make finish the parser loop for rs232 before start parser loop for rs485.
542 --		_427				Maked init receive buffer for rs485.	
543 080110	_428				Maked if is tftp loading - usart not can disable ethernet.
544 --		_429				Use EmptyReceive() for clearing buffer of rs485.
545 --		_430				Deleted some not needed functions.
546 --		_431				Transmit from rs232 to snmp use only Tbuffer1; TBuffer2 will be used for rs485.
547 --		_432				All prepared to use snmp for rs485.
548 --		_433				Added SNMP support for rs485.
549 --		source_rtcs7_433.		--.
550 --		source7_433			--.
551 080115	_434				View lone done for Xilinx1 of bmd34!!!!!! On 2 MHz. Line Init have strange form. 
552 --		_435				Loaded xilinx1 and xilinx2 and xilinx3. Maked common file from impact. Load it as xilinx1 size is 740000 bytes.
553 --		_436				Work loading more quckly 2->3 MHz and no delay after loading. 
554 080116	_437				WD - on; Maked wd 45 secs; address for xilinx2 : 0xc0200000; address for xilinx3 : 0xc0300000.
555 --		Mover51				Maked big xilinx1 size, new addresses for xilinx2 and xilinx3.
556 --		JackS88				--.
557 --		hello7_438			BMD-34: Little changes for #define.
558 --		hello7_439			MF-20: Start version for Autopribor.
559 080118	Mover52				Write files witch extension ".mov".
560 --		Mover_User52			--
561 --		JackS89, JackS_User89, JackS_User_Com2_89 --
562 080121	hello7_440			BMD-34: function eth_off not disabled now managment port! and devise not hangt if not have link but user try tftp loading somthing to tftp.
563 --		_441t				MF-20: If write to emac cfg register 10 mbit - work tftp on 10MBit!!!
564 --		_442				MF-20: Support hub 10MBit. But tftp get off if long files.
565 080122	hello7_443			MF-20: Support TFTP on hub 10 MBit.
566 --		source_rtcs7_443		Added return to function of setting adaptive timeout for tftp. Work tftp on 10 MBit hub.
567 --		hello7_444			BMD-34: support 10 MBit hub.
568 --		hello7_445			BMD-34: to command "BL" can read status of devise : bit 0 - is line "DONE".
569 --		hello7_446			BMD-34: devise do not bloking TFTP task if user try load file witch long name. 
570 --		hello7_447			MF-20: added all last changes reading "Done" and checking length of file names. 
571 080123	installer1			First version installer for mover.
572 --		_2				Added files c1 and d1 to programm dir. 
573 --		_3				Not create not needed user dir.
574 --		installer_mover_4		Added another readme.txt file.
575 --		_5				Add iconcs to desctop and to programm menu.
576 --		installer_mf20cfg3_1		Maked setup to install mf20cfg3 to computers with win2000.
577 --		installer_movers1_1		Maked setup to install movers1 - user variant.
578 --		installer_movers2_1		-- for movers2.
579 080124	JackS_User_Short_1		Make minimum buttons for changing xilinx.
580 080124	JackS_User_Short_COM2_1		Make minimum buttons for changing xilinx.
581 080124	installer_movers1_2		Make minimum buttons for changing xilinx.
582 080124	installer_movers2_2		Make minimum buttons for changing xilinx.
583 --		installer_mover6		Tested on win2000 : added library mfc42d and msvcrtd. Get any messege in installed procedure, but all work.
584 --		installer_mf20cfg3_2		Tested on win2000 : added library mfc42d and msvcrtd.
585 --		hello7_448			BMD-34 : in RadView correctly can view Devise ID : unsigned in any strukt changed tyo unsigned short.
586 --		hello7_449			BMD-34 : RView can read xilinx version signature_hardvere = read_xil_char
587 080125	JackS1_User_short_2		Make more easy menu: only one xilinx; fixed name of xilinx file: "xh.bin".
588 --		installer_movers1_3		Added tftpsrv.exe to istallation.
589 --		JackS1_User_short_3		Maked support many com ports.
590 --		hello7_450			BMD34 : Add using irq0.
591 080128	hello7_451			BMD34:  Make maximum priority for irq0, disable all enover irqs, frite in end of irq any value to end of interrupt register.
592 --		hello7_452			MF20 : interrupts irq 0, 1, 2, 3, fiq are disabled.
593 --		JackS1_User_short_4		Maked start and stop running tftpsrv.exe from this application.
594 --		installer_movers1_5		--
595 --		JackS1_User_short_5		Maked filter to open binary files.
596 --		installer_movers1_6		--.
597 080129	hello7_453t			Maked many tests and delays to work channels on mf20; uncomment deal(). Channels work!!!!!
598 --		hello7_454			MF20: work wersion. Tested. Maked delay after start to init blocks.
599 --		hello7_455			MF20: Added new xilinx for mf20.
600 --		hello7_456			MF20: Get on WD.
601 080130	JackS1_SetIP1			First wersion of programm for only changing IP address of device.
602 --		installer_setip1		--
603 --		JackS1_SetIP_2			Change small Icon.
604 --		installer_setip2		--
605 --		JackS1_User_short_6		Maked scrolling  and small icon.
606 --		installer_movers1_7		--
607 080131	mf20cfg3snmp_42			Maked message for COM ports "disabled or used another programm"
608 --		installer_mf20cfg3_1_3		Not register mfc42d - not have warnings during install.
609 --		installer_mf20cfg3_1_4		Not write anyfiles to system directory.
610 --		hello7_457			Added delays in SetBlockTLF_OT to can set output level treshold is 200, i set 400.
611 --		mover_user_short_1		Make short mover version for users.
612 --		hello7_458			MF20: after loading configuration from mf20cfg3 - full init all devise and load to property load 2x wire <-> 4 wire.
613 --		installer_mover_user_1		Installer for user version of mover.
614 080201	JackS1_user_short_7		Terminate tftp server in finish application not in end of void.
615 --		installer_movers1_8		--
616 080204	source_rtcs_7_457		pack before change mib.
617 --		_458				changed mib to can be use radian pen; but work only if pen is "1";
618 080205      source_rtcs_7_459		Deleted error in mqx - to not can use big pen!!!! Added to RTCSMIB_get adding one to mib->oidlen if id > 0x1000!!!!
619 --		source_rtcs_7_460		Maked adding +1 to command get_next and add our pen 30856.test: 1.3.6.1.4.1.30856.1.2.0 
620 --		hello7_460			MF20: _________Version with new MIB!!!!!!!!!!!!!!!!!!! It use PEN. Need for it another mf20cfg3, mover.
621 --		mf20cfg3snmp_43_pen		MF20cfg3 with using PEN on snmp.
622 --		installer_mf20cfg3_1_5p		--
623 --		hello7_461			MF20: restored in 1213.cpp in end adding mib2 RTCSMIB_mib_add(&MIBNODE_mib2) to can view mib2 parameters on snmp.
624 --		source_rtcs7_461		--
625 --		mover_user_short_2_pen		Use three with pen.
626 --		installer_mover_user_2_pen	--	
627 --		hello7_462p			BMD-34:  Use pen; without pragme USE_PULT - not read kbd and not try print to display. Need make reload xilinx.	
628 080206	hello7_463			BMD-34: Scan xilinx state if done is low - reload xilinx and init devise. Remove any pult functions.
629 --		hello7_464			MF20: --
630 080207	hello7_465_test_transit1	Test version only for test modem transit channel.
631 --		hello7_465_test_transit2	Test transit for four channels. How without interrupts.
632 --		hello7_465_test_transit3	Test transit work with interrupts to level!!!
633 --		hello7_466			BMD34:make irq0 - high level sensitive. Make my_int_diasable_irq0() and my_int_enable_irq0(). Not hangt!
634 --		hello7_467			BMD34: can call test transit from work programm. Need set TestMode = 2.
635 080208	hello7_468			BMD34: can call test transit to snmp.
636 --		hello7_469			BMD34: make timer for bmd right: 1 ms (was 5ms) Telephone work property.
637 --		source7_469			--
638 --		hello7_470			BMD34: maked test for telephene test mode 3; NEED SET ONLY LOOP FOR TRANSIT OR ONLY LOOP FOR MODEM.
639 080211	hello7_471			BMD34: maked main loop period from 5ms to 1ms to better working for transit: con more often free buffers. 
640 --		source7_471			--
641 --		hello7_472			BMD-34: more seldom blink controller LED.
642 080212	JackS1_User_short8		Write file xh.bin in directory wrom with was started programm.
643 --		hello7_473			BMD34: Added to BuffersState bit TFTP_PROCEED.
644 --		JackS1_User_short9		tftpsrv.exe can start oly from programm directory.
645 --		_10				Can write color circles to in future indicate writing. 
646 --		_11				Work timer and painting color circles.
647 080213	_12				Full MoverS. Why without choose file writing bad?
648 --		installer_movers1_9		Installer for MoverS_user.
649 --		source_rtcs7_473		Fixed point before try reconstruct .bin for first mf20 - fir it mib not have pen.
650 --		hello7_474_restore_no_pen	MF20: restore .bin file with no pen snmp to can if need get old versiion of mf20
651 --		hello7_475			MF20: PEN added.
652 080214	JackS90				Make timer and auto request tftp server.
653 --		JackS91				In start request only programm and xolinx versions.
654 --		hello7_476t			BMD-34: programm for upper modem to work monitoring test programm for distant modem with technology print : distant modem is viewed from programm AVT.
655 080215	hello7_477t			BMD-34: programm for down modem to work monitoring
656 --		hello7_478t			BMD-34: programm for upper and down modems.
657 080218	hello7_479t			BMD-34: added delay after UsedSendMod() and tBuffEmbMsgEast.Used() - work for down modem without printf.
658 --		_750t				BMD-34: for upper modem remove printf -keep only delay - modem channel work.
659 --		_751t				BMD-34: for upper and down : only delay work on upper and down modems.
660 --		_752				BMD-34: Added init of buffers for messages EmbMsgA. Programm AVT work without delays.
661 --		_753				BMD-34: Max correct 485 interface.
662 --		_754				BMD-34: Start version for test rs485.
663 --		_755				MF20: Added delay to reload xilinx ~100 sec.
664 --		_756				MF20: Deleted error  mIN priority for usart0 get back to MAX.
665 080219	_757				BMD-34: Added test RS485.
666 --		_758				BMD-34: Disable IRQ0 if xilinx not loaded.
667 080221	_759				BMD-34: Not send to 485 interface not needed answers. Need check back channel : from enover device to station.
668 080222	_760				MPC-34: First version of MPC-34.
669 --		_761				MPC-34: Added test of NVRAM and mode write-read to xilinx.
670 --		_762				BMD-155: First version.
671 080226	_763				BMD-34: Maked changing addresses : can view mpc-34 to rs485!!! Need remove testing print. And make this in bmd-155.
672 080227	_764				BMD-34: Removed testing printf. Fixed Point. "ASU" work.
673 --		_765				BUK-C : First version.
674 --		_766				MPC-34: Correct view connect to e3.
675 --		_767				MPC-34: Changed struct "statePUM" to align to 4 bytes to correctly read errors. CHanged time diagramm for chip select2!!! It for all devises.
676 080228	JackS_COM2			Version JackS for COM2.
677 --		JackS92				To not loss answers find not "%" but ".".
678 --		JackS_COM2_1			--.
679 --		JackS1_SetIP_3			--.
680 --		JackS1_User_Short12		--.
681 --		installer_movers1_10		--.
682 --		installer_setip3		--.
683 --		installer_mover_full		First version installer.
684 --		JackS1_User_Short13		Used not const NUM_SERIAL but variable num_serial to can use com2 and enover. 
685 --		installer_movers1_11		--.
686 080229      hello7_768			BMD-34: use new time parameters for cs2 and check for usart address not only 'f' and big 'F'.
687 --		hello7_769			BMD-34: make correct statepum. POSTAVKA.
688 080303	hello7_770			BMD155: correct statepum. POSTAVKA.
689 --		hello7_771			BUK-C : --.
690 --		hello7_772			BMD2  : first version. Need ask about interrupts. Init make in point as mf20 : before init usarts to correct set buffers.
691 080304	hello7_773			BUK-C : Make calling ISRXX in irq0 routline.
692 --		hello7_774			BUK-C : Enabled receive irq, deleted error from not calling embmsga.init.
693 080305	hello7_775			BUK-C : Enabling interrupts after all inits.
694 --		_776				BUK-C : Make xilinx loading freq 3Mhz->2MHz. Postavka.
695 --		_777	`			BMD2  : Enabling interrupts after all inits.
696 --		_778				MPC-155: First version vithout cse3.
697 080306	_779				BUK-C : Make watch dog  = 200 times without main loop for interrupt int0 to devise not hangt if xilinx not get off interrupt.
698 --		JackS1_User_Short_14		Used new class CSerial to try work witch another as com1 comports.		
699 080307	JackS1_User_Short_15		Work witch com2!!! Was need remove propertis "sort" from select comport menu.
700 --		installer_movers1_12		--
701 --		JackS1_User_Short_16		Can read ip address of devise from configuration file. On end set ip address of devise "0.0.0.0".
702 --		JackS1_User_Short_17		Deleted not needed menu elements.
703 --		JackS1_User_Short_18		Can view current and choosen xilinx file versions.	
704 080311	JackS1_User_Short_19		Maked more property operating witch CStrings. Need keep IP address? Need compare strings.			
705 --		JackS1_User_Short_20		Maked Yellow LED if versions in computer and in device are not identical.
706 --		JackS1_User_Short_21		Use full path for configuration file.
707 --		installer_movers1_13		--.
708 --		JackS1_SETIP_4			More right read programm and xilinx versions. Need test for com2.
709 --		JackS1_User_Short_22		More right read programm and xilinx versions.
710 080312	hello7_780			MF20: One time init; xilinx load up to 5 times; freq loading xilinx is changing from max to divided to 5; chack line dine to minimize delay after loading xilinx.
711 --		_781				BUKC: --
712 --		_782				BUKC: added get off idication after start.
713 --		_783				MPC155 : added cse3.
714 --		_784				BUKC: maked correct try loading of xilinx.
715 080313	_785				MF20: Class MDataS get answers witch '.' in end.
716 --		JackS1_User_Short_23		Can compare vile versions with '.' in end.
716 --		installer_movers1_14		--
717 080314	_786				BMD155: maked little changes in counting errors ( xx + 0x10000) - yy. Tested full. Not critical changes. Can be used in postavka.
718 --		avt2_1				Programm ASU. Debug version work ok.
719 080318	avt2_2				AVT : in function added check state of devise.
720 080319	ComLogger1			First version of logger data from comport.
721 --		avt2_3				AVT: maked writing bad messages about near devise to file; use one time calling Deal();Not use now delay or check state comport before reading data. 
722 --		hello7_787			MF20: before try loading  xilinx is checked : of have header symbol ':' to not loss time in first init of devises.
723 080320	JackS1_SETIP_5			Correctly work witch com2.	
724  --		installer_SetIP5		--.
725 080321   	JackS1_User_Short_24t		Not working wersion after many debugs.
726  --		hello7_788			BUKC: deleted error to not set interrupt bit if buffer is not empty.
727 080324	hello7_789			BUKC: work command to restart from usart0 - deleted reset wd in usart interrupt.
728 --		hello7_790			MF20: deleted error - call mf20_init() in start programm. It was be loss. Maked control of pTBuff0, pRBuff0
729 --		JackS1_User_Short_25		Last version.
730 --		hello7_791			BMD-34: 	deleted error : in isrxx was not set interrupt bit if buffer is not empty.
731 --		hello7_792			BMD-155: --.
732 080325	JackS1_User_Short_Prog1		Can automatic write programms to devise.
733 --		installer JackS1_User_short_prog	--
734 --		hello7_793s			First step to using sockets.
735 --		_794s				Next step. Work connect to tcpip client.
736 --		v_c1_1				Can connect to device 155.155.155.212 port 17.	
737		hello7_795			MPC155: Next step.
738 		_796				Work Test_MPC155().	
739		_797				Maked some changes.	
740 080331	_798				Can to remote read and write to OED.
741 --		_799				MPC155:First working version!!!!!!
742 080401	_800t				To not hangt programm on block 3367 temporary disable nwait for cs3.
743 --		_801				MPC155 : maked porting MX155 to can change configuration for remote. After stort set default config proprty. 
						Need check and uncomment calling in start init void SetHlx(). 
744 --		_802				MPC155: Uncommented loading config from RAM in start. Tested on Victoria.
745 --		_803				MPC155: Start making test for tlf.
746 --		_804				MPC155: Start making test for transit.
747 080402	_805				MPC155: Next step to making test.
748 080403	_806				MPC155: If xilinx not loaded - not exchange witch EOD- to not hawe line NWAIT low.
749 --		_807				MPC155: Maked  NVRAM_FILE_SIZE 7kB.
750 --		_808				MPC155: added CRC to remote.
751 --		_809		08040304 		MPC155: maked number 506
752--		_810		08040305		MPC155: added count errors and sethlx.
753 --		_811		--		BMD155: added CRC to remote.
754 --		_812		--		MPC34: --
755 --		_813		--		BMD34: --
756 --		_814		--		BUKC: --
757 --		_815		--		BMD2:--
758 --		_816		--		MF20: --
759 --		_817		08040306		MF20: deleted error with NVRAM_FILE_SIZE  set softver 200. 	
760 --		_818		--		MPC155: --	
761 --		_819		--		BMD155: --
762 --		_820		--		MPC 34: --
763 --		_821		--		BMD34: --
764 --		_822		--		BUKC: --
765 --		_823		--		BMD2: --
766 080404	source_rtcs7_824 			RTCS: first step to make radian ethernet protocol.
767 --		source_rtcs7_825			RTCS: next step.
768 --		source_rtcs7_826			RTCS:--
769  080407	source_rtcs7_827			RTCS:--	
770 --		source_rtcs7_828			RTCS: start level for RDN protokol : it dublicated as ARP. Now need change it to we will can send and receive our packets.  	
771 --		_829				RTCS: next step.
772 080408	hello7_830			RTCS: can transmit any packets to Ethernet!!!!!!!!!!
773 --		source_rtcs7_830			RTCS: --.
774 --		source_rtcs7_831			RTCS: can correctly send to setted by my MAC Address.
775 --		source_rtcs7_832			RTCS: one step back: this version not hangt after tftp loading if before was power off.
776 --		source_rtcs7_833			RTCS: correctly set length of data : not hangt - ?????? or hangt
777 --		_834t				RTCS: can send message Hello but hangt if have tftp loading.
778 --		_835				RTCS: can send message "Hello!" from tftp not hangt !!!!
779 --		_836				RTCS: not have losses of memory if send radian bursts.
780 --		_837				RTCS: deleted RDN_find.
781 --		hello7_838			RTCS: can send 128 Bytes of data.
782 --		sourrce_rtcs7_838			RTCS:--
783 --		_839				RTCS: can send 1028 bytes of data.
784 080409	source_rtcs7_840			RTCS: get to send data and address to pointers.
785 --		hello7_841			RTCS: make more short and temporery data size 48.
786 --		source_rtcs7_841			RTCS: --.
787 --		hello7_842			RTCS: work counter for receiwed radian packets!!!!!!! Need chack losses of memory.
788 --		source_rtcs7_842			RTCS: -- need check losses of memory.
789 080410	hello7_843			All: can view to remote link status if bufferstate have bit 0x80 - no have link to ethernet.
790 --		source_rtcs7_844			Go to normal pecket data size 1028 bytes.
791 --		hello7_845			Can receive data to buffer from eternet on RDN protocol and write it to buffer and print it.
792 --		source_rtcs7_845			--
793		hello7_846			Transmit from 485 to ethernet start version.
794 080411	hello7_847			Added start version receive from ethernet to rs485.
795 --		hello7_848			Can send burst of needed length.
796 --		source_rtcs7_848			--.
797 --		hello7_849			Delete some not needed operands. Need : 1 add dest addres to transmit 2 delete not needed filling and print rBuff 3. Delete not needed transmit.
798 --		source_rtce7_849			--.
799 --		hello7_850			Version for testing RDN <-> rs485 in system.
800 --		source_rtcs7_850			--
801 --		source7_850			--.	
802 --		hello7_851			In testMode '4' work transit ethernet <-> rs232!!!!!
803 080414	hello7_852			MF20: support RDN protokol.
804 --		_853				BMD34: --
805 --		_854				MPC34: --
806 --		_855				BMD155: --
807 --		_856				MPC155: --
808 --		_857				BUKC:--
809 --		_858				BMD2:--
810 --		_859				BMD34: First version try working in receive parallely from ethernet and from 485.
811 --		_860				BMD34: reconstruct embisr.cpp
812 080415	_861				BMD34: reconstruct embisr.h
813 --		_862				BMD34: delete some errors.
814 --		_863				BMD34: removed some not needed operands.
815 --		_864				MPC34: added parallel work ethernet and 485.
816 --		_865				BMD155: --
817 --		_866				MPC155: --
818 --		_867				BUKC:--
819 --		_868				BUKC: -- and delete some errors
820 --		_869				BMD2: --
821 080417	_870				BMD34: compilling is ok.
822 --		_871				BMD34: deleted error sending packets witch address EmbMsg.AddrS() need embMsgRequest->AddrS().
823 --		_872				MPC34: --
824 --		_873				BMD155: --
825 --		_874				MPC155:--
826 --		_875				BUKC: --
827 --		_876				BMD2: --
828 --		_877				MF20: --
829 080418	RawEth_1			My pinger work with address 155.155.155.212.
830 --		RawEth_2			Can send mailformed packets. If setted "raw" not added to list.
831 080422	sendpack_1			Sucsessfully compiled example from winpcap to send raw packets to ethernet.
832 --		hello7_878			PUM :first
833 --		hello7_879			PUM: Tested version with old modem is viewed of AVT.
834 --		hello7_880			PUM: More full maked defines of PUM.
835 --		sendpack_2			working on my computer example of send raw packet!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
836 --		pktdump_ex1			working on my computer receiving packets from ethernet!!!!!!!!!!!!!!!!!!!!!!!!!!
837 --		hello7_881			MF20: to emb232 added support of ethernet for 232 need add this to main loop.
838 080423	hello7_882			MF20: suppert rs232eth to half added to main loop.
839 --		_883				MF20: full added eth232 to main loop. In packets added one byte to start in position 3(packet type: 0 - 485; 1- 							232) not compatible with previons - it all packets use as 485 and use from 3 byte now - from 4 byte
840 --		_884				Added to mf20 direct 232.
841 --		JackS1_eth_1			Sucsessfully compilled start of terminal will using direct eth 232.
842 --		_2				Maked some for receive.
843 --		_3				Next step.
844 --		_4				Can view variants of interfaces in combo box.
845 --		_5				Can send packet to button.
846 --		_6				Maked void SendPacket().
847 080424	_7				Can send broadcast packets with protokol 0x0888.
848 --		hello7_885			MF20: view broadcast answers to protokol 0x0888.
849 --		_886				MF20: view unicast answers.
850 --		JackS1_eth_8			Can view received packets in log.
851 --		hello7_887			BMD34 :Added support to 232 protocol from ethernet protokol 888.
852 --		hello7_888			BMD155: --
853 --		_889				MPC34: --
854 --		_890				MX155: -- Find error : not use in modems and  mux "rs232.TransEC"!!!!!!!!!!!!!!!
855 --		_891				BUK/PUM: --
856 --		_892				BMD2: -- + added TRANSEC for 232.
857 080425	_893				Added rs232.TransEC.
858 --		_894				BMD2_BMD34 : maked common projekt for bmd2 and bmd34
859 --		_895				BMD2_BMD34 : Added rs232.TransEC
860 --		_896				MPC34 added TRANSEC for 232
861 --		_897				MPC34 - use remotemux.inc and delete .init for messages 232 and 232e need make this for mpc155 and buk
862 080428	_898				BMD2 : maked loading xilinx. Postavka.
863 --		Mover53				Use file xh.bin for writing xilinx.
864 --		hello7_899			MF20: can view it to remote. : added 485.emptyreceve - ?? need add thisto all interface channels; from command "01" remave changing addreses -- work now mf20 cfg4?
864 --		_900				MF20: removed debug print; tested on mf20 cfg4 and on near and far ends from avt.
865 --		_901				BMD2: change some in making statePUM.
866 --		_902				BMD2: added some changes in statepum.
867 --		_903				MF20: work snmp get time; mf20cfg3; avt - checked. get off 232.emptyreceive to work mf20cfg3. NOT WORK WITH SL4!!!!!!!!!!!!!!!!!!!!!!!! Getted off. get to using mf20_3.cpp from hello7_877.
868 080429	_904				MX155: added  rs232.TransEC.
869 --		_905				BUK: --.
870--		JackS1_eth9			work getmac().
871 --		_906				start find errors to operate of mf20 with include file for remote and remote from mux.
872 --		_907				tested operating with blocks sl4; from this point can make changes to wiewing from avt and eth <-> 232.
873 --		_908				MF20: wiev to AWT; need check sl4. maked enower changing addreses and removed settom from command "01".
874 080430	_909				MF20: added rs232<->eth; AVT - ok - need check for sl4. Need check why cyckling if no maked EmptyReceive()
875 --		_910				MF20: deleted error to send some to ethernet and init embmsgans.init
876 --		_911				MF20: receive from 232eth packets included host mac.
877 --		JackS1_eth10			Generate packets< included in body mac of host.
878 --		_912				MF20: moved 232eth buffer to buffers usart3. 
879 --		_913				MF20: answer to computer to individual mac address.
880 080504	_914				MF20: make HostMAC local for class embrs232 to can in future many connections if need.
881 --		_915				MF20: embrs232 answer to mac address thast must be now included to packet. now: packet type 01 - use parser to loop in embdevise, packet type 02 - use my parser for classes; packet type 00 - enower format (not added mac directly) use parser loop for 485.  		
882 --		_916				BMD34: --
883 --		_917				BMD2: --
884 --		_918				BMD34: deleted in start of file bmd34_bmd2.cpp "if(1){" to hawe answermod.inc as in bmd155.
885 --		_919				BMD155: added HostMAC full.
886 --		_920				MPC34: --
887 --		_921				MPC155: -- + deleted error
888 --		_922				BUK: restored file buk_pum.cpp from old versions (904) need add allthat added after file_904.
889 080505	_923				BUK: added last changes and HostMAC.
890 --		_924				BUK: added flagrequest = 5.
891 --		JackS1_eth11			Start making finding RDN devises.
892 --		JackS1_eth12			Can view mac addresses of devicse in the ComboBox.
893 --		JackS1_eth13			Have color indication view devices or not.
894 --		JackS1_eth14			Not use "while" construction in timer.
895 080508	hello7_925			MF20: AVT not lost mf20 if try operate it of far end.
896 --		hello7_926			MF20: (ver 238): is deleted critical error : now it can be configurable from channell 485 : is used not embmsg.Bodu but embmsgrequest->body!!!!!!
897 --		_927				MF20: (238) : can correctly view version in RadView. Need continue debug of remote loading.	
898 080512	Mover54				Mover usung PEN =31073.	
899 --		hello7_928			MF20: (239) : 1: maked PEN 31073 2: maked in start programm (if pok == 2 set pok = 0x1000).	
900 --		source_rtcs7_928			RTCS: maked PEN 31073.
901 --		JackS1_Eth15			Can get text string from combobox. 
902 --		JackS1_Eth16			After select device , send packets only for it.
903 --		JackS1_Eth17			If selected device power off program destination address maked back as broadcast to find enover devices.
904 --		JackS1_Eth18			Start making theards. Need get parameters.
905 080513	JackS1_Eth19			Next step to make thread. get paameters to thread.
906 --		hello7_929			BMD-34: new PEN and POK set to 0x1000 when it is 2.
907 --		JackS1_Eth20			Next step.
908 --		_21				temporary not use theards.
909 --		_22				start making parseanswer.
910 --		_23				next step to make parseanswer.
911 --		hello7_930			MPC34: new PEN and POK set to 0x1000 when it is 2.
912 --		_931				BUKC: --
913 --		JackS1_Eth24			View message "Receive!".
914 080514	hello7_932			BMD155: new PEN and POK set to 0x1000 when it is 2.	
915 --		_933				MPC155:--
916 --		_934				BMD2: --
917 --		_935				PUM: --
918 --		JackS1_Eth25			Can view ID of device.
919 --		_26				-- Version.
920 --		_27				Can set version.
921 --		_28				Can get IP address.
922 --		_29				Can set IP address.
923 --		_30				Can operate MAC.
924 080515	_31				Can operate POK, TestMode, Xilinx and Programm versions.
925 --		_32				Maked get all parameters and set all parameters.
926 --		_33t				Test version : started second theard, used pcap.
927 --		_34				Use two theards work quckly!!!!!
928 --		_35				Can exchange dato with registers and restart devices.
929 --		_36				Can set data from file.
930 --		_37				Can send commands from file.
931 080516	_38				Maked loading and run test programm with tesst to short name vithout calling tftp server.
932  --		_39				Can tftp write programm without rewrite file in programm directory.
933 --		_40				Can tftp write xilinx.
934 --		_41				Delete not needed windows.
935 --		_42				--.
936 --		_43				--.
937 --		_44				Maked release version and really changing interface. Need make auto setting and clear IP address.
938 080519	_45				Not get to all devices if tftp_write and require select device if try write or change some.
939 --		_46				Remove serial as class.
940 --		_47				In header of dialog one can view Jack_E.
941 --		_48				Maked small icon.
942 --		installer_jack_e_1			Installer for Jack_E.
943 --		_2				Working installer: need install winpcap4.0 at target computer.
944 --		_3				Install WinPcap_4_0 automatically.
945 --		JackS1_user_short_eth_1		Start making class for pcap.
946 080520	JackS1_user_short_eth_2		Next step to making class of pcap.
947 --		_3				Added Thread procedure.
948 --		_4				Added some functions.
949 --		_5				Can send any packets and receive answers.
950 --		_6				Can view adapters in dialog.
951 --		_7				Can select device.
952 080521	_8				Can view ID of device.
953 --		_9				Can view xilinx file in device.
954 --		_10				Can rewrite xilinx.
955 --		_11				Can restart device and remove cserial.
956 --		_12				Can compare versions.
957 --		hello7_936			MPC155: not init device if xilinx is not loaded.
958 --		JackS1_user_short_eth_13		Use angetall only if fevice is selected.
959 080522	_14				Exit before cdialog::ok - not have error on exit.
960 --		JackS1_Eth49			Property work with big addresses : added conversion to unsigned before function sprintf.
961 --		installer_jack_e_4			Maked more property version.
962 --		JackS1_user_short_eth_15		More right work.
963 --		installer_movers1_eth_1		Installer changer xilinx  use ethernet only.
964 --		JackS1_user_short_prog_eth_1	Chnger programm only through ethernet.
965 --		installer_movers1_prog_eth_1	installer changer programm.
966 --		installer_movers1_eth_2		Added .cfg file.
967 --		installer_movers1_prog_eth_2	Added .cfg file.
968 080523	JackS1_user_short_prog_eth_2	Any step to make cloass ethernet; any try correctly finich second thread.
969 --		hello7_937			MPC155: 241 can write xilinx as init device - BAD!!!
970 --		hello7_938			MPC155:242 remowed check state of line nwait - tested and run ok.
971 080526 	JackS1_user_short_prog_eth_3	Use AfhEndThread();
972 --		_4				Maked class EDrive.
973 --		_5				Remove GHost as global, make it locally.
974 --		_6				Make some changes to detect interface.
975 080527	_7				Can be work and debug without .cfg file; can be work to two net cards (but not close previons thread) .
976 --		_8				Can use POK to safe write.
977 --		installer_movers1_prog_eth_3	--.
978 --		hello7_939			BMD2 : 242  Maked working test mode 2 (before are writed too much).
979 080528	hello7_940			MF20 :  242 Maked test TELO.
980 --		_941				MF20: 242 Maked test TLLO.
981 --		_942				MF20: 243 Some vosual changes in text of programm.
982 --		_943				MF20: 243 Disabled kernel log.
983 --		source_mqx_7_943			MQX: Disabled kernel log.
984 --		_944				MF20:243 Maked test BUS.
985 --		_945				MF20: 243 Maked test w2o0in0.
986 --		_946				MF20: make frequency with flash 1,5MHz (was 2MHz). Need make testing checksum of programm.
987 080529	_947				MF20: go back to 2MHz with flash; init ethernet two times; added test w4013in13.
988 --		source_mqx7_947			Etherrnet init two times.
989 --		JackS1_Eth_50			Jack_E: not go automatic to broadcast packets if is selected any device.
990 --		installer_jack_e_5			installer to jack_e not go to broadcast packets if device is already selected .
991 --		addchk_1				start making programm to add checksum to programm file.
992 --		_2				have file lengh.
993 --		_3				add 4 byte of checksum to end of file and write file length with cadded 4 bytes of checksum to vektor 6 : bytes 20 -23 (numerating from 0 ).
994 080530	addchck_4			write length not to address "17", but to address 0xf00; 0xf01, 0xf02.0x03.
995 --		hello7_948			MF20:(243) at start control checksum, writed ta address 0xc0000f00 - point of not used function get id. If checksum not get, added 0x10 to bufferstate variable - it can be readed.
996 --		source_mqx_7_948			use 31 M af sdram make tftp buffer 20M.
997 --		hello7_949			added test of NVRAM.
998 080602	hello7_950			IP address moved to flash.
999 --		_951				TestMode moved to flash.
1000 --		_952				UARTAddress moved to flash. 
1001 --		_953				Removed objekts  ClkNumber and CommandData.
1002 --		_954				Optimized time to loading xilinx; reading from enet in init reduced from 80000 to 2. Maked piker led to count calling main loop but not timer.
1003 --		source_mqx7_954			Reduced reading from ethernet.
1004 --		hello7_955			Cahgetestmode setted after readdevid.
1005 --		v37_BL_select_12			Romboot : remowed two times loading; can write files without ping flach addresses in hyperterminal. Init to zeros 31MByte. SetPLL before reading to sdram main programm.
1006 080604	hello7_956			Momentally reload xilinx after revriting in flash. Maked more size for DEV_ID_SIZE (+4 Bytes).
1007 --		hello7_957			ACT155: (243) First version of ACT155 (maked as BMD155). 
1008 --		JackS93				Maked more wide window for reading versions.
1009 --		hello7_958			MF20: tftp buffer maked 17 MBytes. More right .met file for linker.
1010 080606	hello7_959			MF20: compiled with last mqx library. //link31Mb
1011 --		source_mqx_7_959	t		MQX: BAD - not can use debugger!!!!  make some inits for any const parameters.
1012 --		v37_bl_selekt_13			Romboot: make init PllB to mayby not have somtime slow work at start. Maked menu for direkt download pamboot, uboot and envinronment.
1014 --		_14				Romboot:  added init pllb to void InitPLL1 to equally load mqx and U-Boot.
1015 --		hello7_960			ACT155: link with link_16M.met - to have inited with zeros SDRAM in kernel if used old RomBoot.
1016 --		v37_bl_selekt_15t			RomBoot : write zeros only in kernel area and read program from flash one time to work more quickly.
1017 --		hello7_961			MF20: compiled with previons version of mqx to can use seecode debugger.
1018 080607	hello7_962			MF20: repaired TestMode 4: to wlash writed 1 and after set test mode = 4 to property testing.
1019 --		hello7_963			MF20: deleted state : if setted testmode = 0; was setted printf to debug usart.
1020 --		hello7_964			ACT155: maked with all last changes. First flashed version.
1021 080609	hello7_965			TUTS: Start version.
1022 --		_966				TUTS: Next step.
1023 --		_967				TUTS: get off interrupts and loading and check xilinx.
1024 080610	_968				TUTS: maked outputs functions.
1025 --		_969				TUTS: add classes and remote: need : add storage, add init of outputs, make read of inputs to remote or olwais.
1026 --		_970				TUTS: correct keep data in flash. Inputs reads as LED blinked.
1027 --		_971				TUTS: added operate inputs/outputs to internal operate channel 
1028 --		_972				TUTS: removed any writing to not used xilinx; ON BLOCK MF20 : if not loadxilinx - do not work rs485.
1029 --		JackS1_Eth_51			Check select one device before read parameters. 
1030 --		installer_jack_e_6			--
1031 080611	_973				BUKU: First step without loading xilinx.
1032 --		_974				BUKU: next step TEMPORARY disable line NWAT in cs of xilinx.
1033 --		_975				BUKU: stop - this devise not will be maked.
1034 080616	_976				MF20(243): make timer for eth off 1ms from 10 ms to device can work with ethernet if temp to rs485 will be 10 ms.
1035 --		_977				MF20(243): more quickly test nvram.
1036 --		_978				ACT155(243): --.
1037 --		_979				BMD155(243): --.
1038 --		_980				BMD2(243): --.
1039 --		_981				BMD34(243): --.
1040 --		_982				BUKC(243):--.
1041 --		_983				MPC155(243):--.
1042 --		_984				MPC34(243):--.
1043 --		_985				PUM(243): --.
1044 --		_986				TUTS(243): --.
1045 --		_987				TUTS(243): added triggering state of inputs.
1046 --		_988				TUTS(243): added commands "A" and "B".
1047 080617	_989				ACT155N(243): start version (dev number 108).
1048 --		JackS1_Eth52			Jack_E: use last net card; more right compare mac addresses (unsigned char) to receive own packets.
1049 --		installer_Jack_e_7			--
1050 080618	JackS1_User_short_prog_eth	--
1051 --		JackS1_User_short_eth_16		--
1052 --		installer_movers1_prog_eth_4	--
1053 --		installer_movers1_eth_3		--
1054 --		JackS1_user_short_eth_17		Deletod error : before can work only ethernet card 2 so was maked in onusepcap().
1055 --		installer_movers1_eth_4		--
1056 --		snmp7_989			snmp before make mib for tuts.
1057 080619	hello7_990			ACT155(243): work test MOD.
1058 --		_991				ACT155N(243): make modem test full to interrupt; right write name and type; whu hangt after test? -- need check at old bmd155.
1059 080620	_992				ACT155N(243): after finich test mode2 (test modem) setted test mode 1 to property work interrupts after test and device not hangt.
1060 --		snmp7_992			next step to make snmp operating for tuts.
1061 --		snmp7_993			have response to request of inps 1.3.6.1.4.1.31073.1.8.0.
1062 --		snmp7_994			get value as counter32 : brovser not hangt, but not receive first bytes.
1063 --		 hello7_994			TUTS(243): added some commands and functions for tuts.
1064 --		hello7_995			TUTS(243): maked functions to operate outputs through snmp : have mask and writing to flash from main loop.
1065 --		hello7_996			--: can get state of outputs and set outputs to 1.3.6.1.4.1.31073.1.9. type counter!!!! value need set decimal.
1066 --		snmp7_996			--
1067 080623	v42_Test_SDRAM_1		First version test of sdram from bootloader.
1068 --		hello7_997			TUTS(243): can be setted outputs with status "No Error" tupe is counter32, setted value in tenfold numeric system
1069 --		snmp7_997			--
1070 --		hello7_998			TUTS(243): added node 1.3.6.1.4.1.31073.1.10.0 - get triggered inputs (it will be cleared after reading state of inputs).
1071 --		snmp7_998			SNMP: --.
1072 --		hello7_999			TUTS: can read state of input1.
1073 --		snmp7_999			SNMP: -- added 1.3.6.1.4.1.31073.1.11.1.
1074 080624	hello7_1000			TUTS: maked TUTS_INP_SEL2 1.3.6.1.4.1.31073.1.11.2.0
1075 --		snmp7_1000			snmp: --
1076 --		hello7_1001			TUTS: maked TUTS_INP_SEL3...32
1077 --		snmp7_1001			snmp: --
1078 --		hello7_1003			TUTS: maked TUTS_OUT_SEL1 1.3.6.1.4.1.31073.1.13.1.
1079 --		hello7_1004			TUTS: maked   TUTS_OUT_SEL2...8  1.3.6.1.4.1.31073.1.13.2. ...1.3.6.1.4.1.31073.1.13.8.
1080 --		snmp7_1004			snmp: --. ?? snmp do not support sequency af "set" commands????????
1081 080625	hello7_1005			ACT155N: start make new 485.
1082 --		_1006				--: added class embmsg485.
1083 --		_1007				--: added some of parse 485 
1084 --		_1008				--: removed some of old parse 485.
1085 --		_1009				--: removed from 485 transec.
1086 --		_1010				--: modyfed command type "9".
1087 080626	_1011				ACT155N: added buk protokol for rs 485. ? What need from statepum.
1088 --		_1012				--: used to write to 485 io_serial_int_write() to can use PDC
1089 --		_1013				--: all get back; if make interval 50 ms ping work property; pdc not change somthing. !!!!485 receive himself and get off ethernet!!!!!!!
1090 --		hello7_1014			ACT155N(243): if not disable ethernet on receive - ping work property.
1091 080627	_1015				TUTS(243): delete some errors. need make clear triggered inputs.
1092 080630	_1016				TUTS(243): can clear triggered inputs when read.
1093 --		_1017				TUTS(243): get on clocks to port a: now work any inputs.
1094 --		_1018				TUTS(243): make operating inputs in hardware sequence.
1095 --		_1019				TUTS(243): added MIB for tuts.
1096 --		_1020				TUTS(243): if readed selected inputs to snmp , cleared only selected triggered inputs.
1097 --		snmp7_1020			snmp : --
1098 --		hello7_1021			ACT155N(243): added struct state rrl and command 0x10 to get state rrl.
1099 080702	_1022				ACT155N(243): more fast parse received data from rs485. 
1100 --		tuts_1				prog for operate tuts need set com2.
1101 --		tuts_2				can set outputs for tuts. 
1102 --		tuts_3				delete some errors
1103 --		tuts_4				replace radiobutton to checkbox
1104 080704	hello7_1023			ACT155(243): have first results, view bad checksums.
1105 --		hello7_1024t			ACT155(243): maked debug print to rs232 that received from rs485 maked RRL_ADDR1,2 "0" and "1".
1106 --		hello7_1025t			Tuts -test: maked debug prunt to ethernet broadcast bursts.
1107 --		EthDebug1			Start making ethernet debugger.
1108 --		hello7_1026			ACT155(243) : make delay 30ms. Base version.
1109 --		EthDebug2			Ethdebugger : maked place for parse debug packet and after this print it.
1110 --		hello7_1027			ACT155(243): added InitClocks();
1111 080722	EthDebug_3			View hello in window.
1112 --		EthDebug_4			View manu hello in debug window.
1113 080723   	JackS1Eth_53			Start new thread if change interface work on computer BA.
1114 --		installer_Jack_e_8			--.
1115 --		JackS1_user_short_eth_19		--.
1116 --		installer_movers1_5			--.
1117 --		hello7_1028			ACT155(243): added check first byte to CheckClocks();	
1118 --		EthDebug_5			automatically added new strings in end line.	
1119 --		_6				Can go to next line!!!!!
1120 --		_7				Can add new lines. maked property "\r\n" two times!
1121 --		hello7_1029			ACT155(243): added two bytes to InitClocks();
1122 --		EthDebug_8			Can clear window.
1123 --		EthDebug_9			Not open  .cfg file and not change ip address.
1124 --		installer_etdebug_1			--
1125 080724	Ethdebug_10			Maked more size and button "change program".
1126 --		installer_ethdebug_2		--.
1127 --		hello7_1030t			tuts : testing print to ethernet long values.
1128 --		EthDebug_11			maked print without changing line.
1129 --		installer_etdebug_3			--
1130 --		hello7_1031t			tuts: added test output to ethernet any bytes.
1131 080725	hello7_1032t			MPC155: maked test version with disabling usingtranswitch.
1132 --		hello7_1033			TLV: first step to make indicator : view some on indikator!!!!!
1133 --		_1034				TLV: make irq2 to negative edge - view menu on idikator!!!!!! Interrupts are going as low lewel.
1134 --		_1035				TLV: for irq2 make disabling and enabling interrupt : menu work property !!!!!!!!!!!!!!!!!!!!!!!!
1135 --		_1036				TLV: irq2 make as LLS. All work; but in top level menu if press esc : view on indikator some wrong. + need								make to controller usart.
1137 --		_1037				TLV: if make lengyh of string 24 symbols not have wrong symbols on idikator.
1138 080728	_1038				TLV: use usart3 for reset pult.
1139 --		_1039				If manually reset bit 2 view an indicator some symbols: ootput ever 1s.  
1140 --		source_mqx7_1039			make init usart3 to 57600 for pult.
1141 --		RadView1			start making print 32 bytes of state_rrl.
1142 080729	RadView2			Maked debug print state rrl. for com1
1143 --		RadView3			Maked sweep to 2 byte staterrl for eduard.
1144 --		hello7_1040			In registers xilinx clear default setting tu use xilinx usart.
1145 --		_1041				View first item of menu will need reading state of keys.
1146 080730	_1042				Start reading keys; after first ping have rings.
1147 --		_1043				PULT_USART work property.
1148 --		_1044				start making changes for writing to flash from internal channel
1149 --		TUTS_5				compiled operate tuts programm for com2.
1150		hello7_1045			added some to command 5: can write to ram_buffer; added command 0x35 : start write to ram; command 0x36 : 						stop write to ram.
1151 --		RadViewProg1			Start making writer programm to devise through system channel.
1152 --		_2				added button write programm.	
1153 --		_3				Can send command 0x35 : start write programm to flash.	
1154 080731	_4				Start making send command 0x05 (write data).	
1155 --		hello7_1046t			Maked writing to test address of flash. Have debug print. Not correctly compared checksums?.
1156 080801	RadViewProg_5			Work loading loop; need make addresses and getting data from file.
1157 --		hello7_1047t			Work loading some from emb protokol to tftp buffer.
1158 --		RadViewProg_6			Use full file size to load.
1159 080804	hello7_1048t			programm can be rewrited through internal channel!!!! Have test print.
1160 --		hello7_1049			MF20: programm can be rewrited from internal channel.
1161 --		RadViewProg_7			Sucsessful rewrite programm.
1162 --		hello7_1050			MF20: can rewrite xilinx from internal channel.
1163 --		RadViewProg_8			Programm can rewrite xilinx from internal channel.
1164 080805	EthDebug_12			Get off receiving own packets.
1165 --		EthDebug_13			If do not make somthing in destruktor - get off work property. To bad result get terminateprocess and killtimer  in destruktor?
1166 --		EthDebug_14			Maked getting off first 0x1000 symbols in debug window if common symbols more of 0x5000 to view do not stopped.
1167 --		installer_ethdebug_4		--
1168 --		hello7_1051			start making programming flash of pult.
1169 --		hello7_1052			ready to debug version for programming flash of pult.
1170 080807	hello7_1053			pack before find errors for plata_argussoft : unpack hello7_464.zip
1171 --		hello7_1054t_from464		projekt 464 recompiled with mqx and rtcs library. Wiev pulses on ioc13.
1172 --		_1055t				added last hello7.h
1173 080808	_1056t				+ work.c
1174 --		_1057t				+ hello.c
1175 --		_1058t				modify hello.c : not init cs and not init classes.
1176 --		_1053ta				maked 1053 asmf20 and comment initcs, init class and make at start loop.
1177 --		_1053tb				if remove many files from projekt - loop work!.
1178 --		_1053c				remove only flash - do not work.
1179 --		_1053td				when add embisr.h and caomment rs232::transinit : started hellotask!!!! view pulses on c13.
1180 --		_1053te				If add to 1053 ONLY old embisr.h and modyfy all for it - programm WORK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						changed ACT_BUFFER_SIZE and classes for ethernet-232-485.
1182  080811	_1059				If reduce act_BUFFER_SIZE from 100000 to 10000 programm work.
1183 --		_1060				Next step to try programming flash of pult : maked ethernet debug.
1184 080812 	_1061				View any answer on pins if try read atmel status bits!!!!!
1185 --		_1062				View answer 0x73 to request atmel signature to addr 0x31.
1186 --		_1063				Can print answer 0x73 to request atmel signature request.
1187 --		_1064				Can view writend data (0x99) to address 0!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
1188 --		_1065				View correctly writened 0x50 bytes. 
1189 --		_1066				View ok to comparin data to memory. Now use small size of file; need make full.
1190 --		_1067				Programm writed full.
1191 080813 	_1068				More better print.
1192 --		_1069				Next step.
1193 --		_1070				Added operation "3" for tftp loading - to start programm pult.
1194 --		JackS1_Eth_54			Maked button "Programm Pult". Remove terminate process and kill timer from destruktor.
1195 --		installer_jack_e_9			--
1196 --		JackS94				Maked button "Programm Pult"
1197 --		hello7_1071			Maked getting off transmitter usart3 if pult is programmed.
1198 080814	hello7_1072			KTVM: first version maked from mf20.
1199 --		_1073				--: clear some from mf20.
1200 --		_1074				--: more clear; somtime have rings from pult!!!! 
1201 --		_1075				--: more clear.
1202 --		_1076				ACT155N: added to commands A and B operating with ports.
1203 080817	EthDebug_15			If power of selected device get off not get to unselected state. 
1204 --		installer_ethdebug_5		--.
1205 --		_1077t				Have test print to ethdebug. Start making  self buffer for dir_eth232.
1206 --		_1078t				Maked self buffer for keys. View restart of device!!!!!!
1207 --		_1079t				Maked ticket_on() back to view bags if it is. Device HANGT SOMTIME!!!! Get bak to file of mf20.
1208 --		_1080t				Maked init buffer rcvbuffE for Emb232 to device not restart with using dirrs232.
1209 080819	_1081				ACT155N: deleted error  of not init rcvbufE.
1210 --		_1082				TUTS: --
1211 --		_1083				ACT155N: compiled without not needed pult.
1212 --		_1084				TUTS: --
1213 080822	_1085t				KTVM: version compiled from files load11 and ktvm but not linked
1214 --		_1086				KTVM: version compiled and linked from files load11 and ktvm2000 and api16.cpp and basic.cpp
1215 --		_1087				KTVM: delete some varnings.
1216 080825	_1088				KTVM: compiled without new warnings.
1217 --		_1089				KTVM: added inportb_dir.
1218 --		_1090				KTVM:added itoa; removed  "_dir".
1219 --		_1091				KTVM: added reading dpd to ram.
1220 --		Jack_S1_User_Short_DPD_Eth1	First version applikation for writing dpd.
1221 --		_1092				KTVM: started .bin; blocked all : loading xilinx, init and run.
1222 --		_1093				KTVM: go any steps on property init.
1223 --		_1094				KTVM: make init before main loop to can debug init  of three.
1224 080826 	_1095				KTVM :start making any changes
1225 --		_1096				KTVM: more right init dpd of mf20: make big heap and init size.
1226 --		_1097				KTVM: use global embtree in Encoder_Set() - function ::Down work!!!!!
1227 --		_1098				TUTS: version with property init of ethernet buffers.  
1228 --		_1099				ACT155N: -- and maked enover chsnges addresses I S R for near end.
1229 --		_1100				KTVM: ktvm_init() compiled full and not hangt.
1230 080827	_1101				KTVM: ktvm() compiled and not hangt.
1231 --		_1102				KTVM: if testmode is 0x20 - keys are go to my meny; else - to dpd menu.	
1232 --		_1103				KTVM: have rings to keys in void ktvm().	
1233 080828	_1104				KTVM: GetParameterNum added to embtreetvm; deleted using virtual inportb.
1234 --		_1105				KTVM: Commented SetStr1 in main loop; viev print keys names.
1235 --		_1106				KTVM:View second string in menu!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! If ping keys!!!!!!!!!!!!!!!!
1236 --		_1107				KTVM: View first string.
1237 080829	_1108				-- make some
1238 --		_1109				-- add to embtreetvm  ViewParameter().
1239 --		_1110				-- add to embtreetvm  ViewComParameter().
1240 --		_1111				-- add to class embtree function outportb from class embtreetvm.
1241 --		_1112				--	inportb.
1242 --		_1113				-- not use class embtreetvm!!!!
1243 		_1114				-- remove class embtreetvm from code.
1244 080901	_1115				-- print something on start
1245 --		_1116				-- some print on startpage
1246 --		_1117				--remove all parameters from encoder_set.
1247 --		_1118				-- maked all for irq0 (Low level sensitive) and loading xilinx. 
1248 --		_1119				-- korrected interrupt_wait.
1249 --		_1120				-- more right symbol table.	
1250 --		_1121				-- --.
1251 --		JackS1_User_Short_DPD_Eth2	make more right get out; not use POK; if power off not get to generating broadcast packets.
1252 --		RadViewProg_9			maked buttons for writing programm and for writing xilinx.
1253 --		_1122				KTVM: DPD file for pimenov work in menu!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1254 --		_1123				KTVM: make property address for writing of address of device.
1255 --		_1124				KTVM: restored waiting in initivac().
1256 --		_1125				KTVM: make some delays changing from for() to delay_mcs().
1257 080903	_1126				KTVM: add some delay_mcs().	
1258 --		_1127				KTVM: make dempfer buffer for working to receive ethernet in interrupt.	
1259 --		_1128				KTVM: make template class trbuffer direck for char type.
1260 --		_1129				KTVM: added EmbInit() to start!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Menu work.
1261 --		_1130				KTVM: added ring and leds test on start.
1262 --		_1131t				DTVM: start making programm for decoder.
1263 --		_1132				DTVM: first compiled and linked version; need check interrupts.
1264 --		installer_dpd_1			First version programm for writing dpd.
1265 080908	_1133				DTVM: added calling InitFreePtr() before allocMemory and device not hangt after start.
1266 --		_1134				DTVM: void restart() - in maket resetted indikator, but it is only on maket?
1267 --		_1135				DTVM: add irq1. Need check on schematic what class member need use for irqs.
1268 --		_1136				DTVM: maked ZeroStorage = 0xffffffff to make free address "0" in NVRAM to can make remote for parameters ov device.
1269 080909	_1137				DTVM: maked data of type MDataV RateData for operating parameter rate. Need make property answer to remote and control.
1270 --		_1138				DTVM: Have property answer to remote command control not used to can have more global menu.
1271 --		_1139				DTVM: Remove old nmi interrupts.
1272 080910	_1140				DTVM: Make parameter videodata for operate of video standart.
1273 --		_1141				DTVM: Make parameter testsignaldata.
1274 --		_1142				DTVM: Make parametr sounddata.
1275 --		_1143				DTVM: Make address for GetErr and EmbGetAddr +3 to can be used class MDataC for remote.
1276 --		_1144				DTVM: Make MDataC parameter for State.
1277 --		_1145				DTVM: Make ErrData for remote about errors. May be need remote for inportb?
1278 080911	_1146				--	: maked pointdata.
1279 --		_1147				--	: maked addrdata.
1280 --		_1148				KTVM : Compiled; added time_notify_core().
1281 --		_1149				KTVM : adderd ratedata.
1282 --		_1150				KTVM: added all remote.
1283 080912	v_37_bl_select16			BOOTLOADER: not pick PLLB at it work frpm start CPU. it is v9.1
1284 --		v42_test_sdram_2			TEST_SDRAM : make test number of address keep in address full read after fiull write.
1285 --		_1151				KTVM : added keydata : can make remote keyboard.
1286 --		_1152				--: added ind0data - can remote view first line on indikator.
1287 --		_1153				--: added ind1data :can remote ping keys and read indikator
1288 --		_1154				DTVM: --.
1189 080915	_1155				DTVM: add to end of result string zeros.
1190 --		_1156				KTVM: --.
1191 --		rempult_1				RemPult: start make programm imitate pult. 
1192 --		rempult_2				--	: write somthing from str0 and str1.
1193 --		rempult3				-- : more working.
1194 --		_1157				KTVM: really add to end of result string zeros.
1195 --		rempult_4				REMPULT: getInd used inly device is selected.
1196 080916	hello7_1158			KTVM: CoppyIndToRemot setted before converttowin1251.	
1197 --		rempult_5				REMPULT: Correctly can view russian symbols from menu.	
1198 --		rempult_6				REMPULT: have informatio about cursor.
1199 --		rempult_7				REMPULT: can view cursor.	
1200 --		hello7_1159			KTVM: can get information about leds.	
1201 --		rempult_8				REMPULT: can request data about last led command. only last?
1202 080917	hello7_1160			DTVM: can get information about leds.
1203 --		hello7_1161			DTVM: correctly russian symbols for rempult.
1204 080918	hello7_1162			DTVM: get iformation about all used leds. 
1205 --		hello7_1163			KTVM: --.
1206 --		rempult_9				REMPULT: can view state of leds.
1207 --		istaller_rempult_1			--: --.
1208 --		installer_dpd_2			DPD: installer can set dpd.
1209 080919	v45_try_full_mqx_2_1		ADS : Start try using irq in ads 1.2.
1210 --		_2				ADS : Called in init back AIC_Open().
1211 --		_3				--:  maked source of handler for irq0 - need init and enable.
1212 --		_4				--:  maked init and enabling irq0 and can view print from handler!!!!!!!!!!!!!!!!!!!!!!!!
1213 --		_5				--: start making self init chip selects (now used init from mqx).
1214 0809.22	_6				--: added init chip selects (it can be changed).
1215 --		_7				--: compiled for address 20000f20 and need load manual tftp 20000f20 (not 20000000). But needloaded xilinx! => go back to using address 0x20500000.
1216 --		_9				-- go back to address 0x20500000.
1217 --		_10				--: make for example user functions : frite three zeros and three ones to nvram. 
1218 080926	hello7_1164			DTVM : maked property working ingenerny  menu if testmode is 20.
1219 --		_1165				--: added funktion setrate() - maked for snmp.
1220 --		_1166				--. maked funktions for snmp SetRate and Getrate.
1221 --		_1167				--Added StRate to Init26 to changing in menu can be viewed from snmp.
1222 --		snmp7_1167			--maked snmp files
1223 080929	_1168				-- : maked all for VideoData. if need set use 1.3.6.1.4.1.31073.1.9.0	
1224 --		snmp7_1168			--: --.	
1225 --		_1169				--: maked for testsignal.
1226 --		snmp7_1169			--: --.
1227 --		hello7_1170			--: added funktions for sound, state, err.
1228 --		_1171				DTVM: added setaddr1 and setpoint1.
1229 --		_1172				KTVM: maked property ingenerny menu.
1230 --		_1173				KTVM: maked changing from dpd pult variables for menu.
1231 --		_1174				BMD155: commented checkdone(); start making snmp.
1232 --		_1175				--: maked pragma WITHOUT_XILINX to property debug snmp on maket.
1233 080930	_1176				BMD155: maked init watch dog at start programm; disabling ethernet to start main loop to can unit usart buffers.
1234 --		_1177				BMD155: maked first node for snmp.
1235 --		_1178				--: added funktions to realise snmp.
1236 081001	_1179				--: maked snmp operating without setloop.
1237 --		_1180				--: added set_LOOPM - now without loading xilinx - for maket only.
1238 081003	_1181				--: maked snm operating as octet string but first value for get is not defined!
1239 --		snmp7_1181			--: --.
1240 --		hello7_1182			--: correctly read init state of TlfNUmber. may be need init second byte of buffer?
1241 --		snmp7_1182			--: --
1242 --		hello7_1183			--: can read zero value.
1243 --		snmp7_1183			--:--.
1244 081006	moverT_1				Can write for test zero values to octet string node .....19.
1245 --		hello7_1184			BMD155: set : 1234 get : 4321.
1246 --		_1185				--: use type octet string - not disp string, not unsigned int; can set any value and can read now "ok"
1247 --		snmp7_1185			--:--
1248 081007	hello7_1186			--:--data send from external function
1249 --		snmp7_1186			--: --.
1250 --		hello7_1187			--: full maked node TLFNUMBER.
1251 --		snmp7_1187			--:--
1252 --		hello7_1188			BMD155: maked SNMP with loading xilinx:
1253 --		snmp7_1188			--:--.
1254 --		hello7_1189			BMD34: --.
1255 --		snmp7_1189			--:--.
1256 081008	hello7_1190			BUKC: first step to make snmp-radian.
1257 --		_1191				BUKC: deleted error of not init. Are working first three mib nodes. Xilinx is not loaded, maked test printing.
1258 --		snmp7_1191			snmp:--.
1259 --		hello7_1192			BUKC: maked node STATERRL1.
1260 --		snmp7_1192			snmp:--.
1261 --		hello7_1193			BUKC: maked node STATERRL2.
1262 --		snmp7_1193			snmp:--.
1263 --		hello7_1194			BUKC: first step making RRLCMD.
1264 --		snmp7_1194			snmp: --.
1265 081009	hello7_1195			BUKC: make variables.
1267 --		hello7_1196			ACT155N : make as default for act155n to usart no can stop ethernet as default. hello.c taked from archive of 								act155n - current version do not work for all interfaces.
1268 081010	hello7_1197			BUKC : make last snmp commend need chack correctly length and pipe addresses ; compiled with loading 							             xilinx.
1269 --		_1198				ACT155N: make not waiting end of messages in parse232, counters to 200, beffer for transit to 32 messages.
1270 081014	_1199				ACT155N: make disabling ethernet to 1 ms.
1271 --		_2200				ACT155N: make usarts priority min - tuts bursts was not lost!
1272 --		_2201				ACT155N: make priority of irq0 loves - tuts burst of tots will be less be lost.
1273 --		_2202				ACT155N: maked disabling exchange on rs485 with upp to 200 ms if send somthing to my ethernet protokol.
1274 --		_2203				--: delay 180 ms; remove any test functions.
1275 081015	_2204				-- : use for all interrupts(usarts, enet, irq0123,fiq) system timer. Need check transit - work?
1276 --		source7_2204			mqx: -- add to init usarts and ethernet interrupts using system timer.
1277 081016	hello7_2205			ACT155N: disable some interrupts when write data from ethernet. have 0 bad packets from tuts.
1278 --		hello7_2206			ACT155N: maked guaranted request period 500ms.
1279 --		jacks1_eth_55			JackE: added buttons "Set ethernet priority" and "Set Usart Priority".
1280 --		installer_jack_e_10			--: --.
1281 --		JackS1_user_short_prog_eth_10	JackP: not set to zero all ip addresses in network.
1282 --		installer_movers_prog_eth_5		--:--.
1283 --		JackS1_user_short_eth_19		JaxkX: --
1284 --		installer_movers1_eth_6		JackX: --.
1285 081017	hello7_2207			ACT155N: maked really guarantee of 500 ms request upp; checking not end of messages to rs232 and rs232E; 							priority of rs232 setted (AT91RM9200_AIC_SMR_PRIO_MAX-1)
1286 --		hello7_2208			ACT155N: getted off test calkcrc before send answer of 485E!!!!!!!!!!!!!!!!!!!!!!
1287		_2209				--: disable interrupts in two points.
1288 081020 	_2210				ACT155N: maked timer priority highest, enet priority 6; enet stack size 10000.
1289 --		source7_2210			MQX: --.
1290 --		source_rtcs7_2210			RTCS: --.
1291 --		hello7_2211			ACT155N: maked priority of rs232(usart0) highest - not have a lost requests  of modem.
1292 --		hello7_2212			ACT155N: deleted ERROR: do naot have variable mode5a for rs485, rs232e,rs484e!!!! This error need delete in 							all devises. 
1293 081022	jacks1_eth_56			JackE: in OnTimer() have information about selected devise : prepered to can be blink red if device not 						answerd.
1294 --		jacks1_eth_57			JackE: Can compare source address ans address in selected device.
1295 --		jacks1_eth_58			JackE: Maked full monitoring accesibility of ever mac address.
1296 --		installer_jack_e11			JackE: --.
1297 --		hello7_2213			ACT155N: remove disabling interrupts when exchange with tuts.
1298 --		_2214				ACT155N: make "else" for embmsg485e addresses checking.
1299 --		_2215				--:  make soft ver "247". 
1300 081023	_2216				--: move answer for rs485e to answer group : do not have lost packets????
1301 081024	_2217				BMD155 : maked correctly mode5a and sending answers.
1302 --		_2218				BMD34 : --.
1303 --		_2219				BMD2: --.
1304 --		_2220				BUKC: --.
1305 --		_2221				TUTS: --.
1306 --		_2222				MF20: --.
1307 --		_2223				MPC34: --.
1308 --		_2224				MPC155: --.
1309 081027 	_2225				ACT155N: make new tree for snmp - to have unikally pipe for enover node enover device. 
1310 --		snmp7_2225			SNMP: --.
1311 081028	hello7_2226			ACT155N: deleted some errors from snmp.
1312 --		snmp7_2226			SNMP: --.
1313 081029	full_mib_1			First version of full MIB.
1314 --		Mibbrovser_1			Used mibbrovser.
1315 --		full_mib_2			Added bmd34.
1316 --		full_mib_3			Added bukc.
1317 --		full_mib_4			Added tuts to end.
1318 --		full_mib_5			Go back, where tuts was in device node.
1319 081030	hello7_2227			TUTS: maked node "out_sel1" to  as octet string operating.
1320 --		snmp7_2227			snmp : --.
1321 081031 	hello7_2228			TUTS: maked all nodes for outs as octet strings type.
1322 --		snmp7_2228			SNMP: --.
1323 --		full_mib_6			MIB: --.
1324 081101	JackS1_User_Short_Prog_Eth_11	JackP: 1- maked in 2 points stting ethernet priority;2- in 2 points setting usart priority;3 - maked no killing timer in end of programm; 4 -not coming to broadcast address if device is selected but not answer; 
1325 --		installer_movers1_Prog_eth_6	JackP_installer: --. 
1326 :		JackS1_user_short_eth_20		JackX : --
1327 081105	installer_moverS1_eth_7		JackX_installer: --.
1328 --		hello7_2229			BUKC: maked node for commandrrl as setting to buffer of rs232 command.
1329 --		snmp7_2229			snmp : --.
1330 081106	hello7_2230			dtvm: start making compiled projekt.
1331 --		_2231				dtvm : working projekt.
1332 --		snmp7_2232			snmp :maked node mibnode_dtvm.
1333 --		hello7_2233			dtvm : maked starting nodes from node mibnode_dtvm.
1334 --		snmp7_2233			snmp: --.
1335 --		hello7_2234			dtvm : added three nodes for snmp operating : sound, addr station, addr device.
1336 081107	hello7_2235			dtvm : correctly make "set" command for sound and addresses.
1337 --		snmp7_2235			snmp: --.
1338 --		hello7_2236			dtvm : added setpointo and getpointo.
1339 --		hello7_2237			dtvm : station number snmp node maked full as octet string...
1340 --		hello7_2238			dtvm : added functions : setaddr10 and getaddro.
1341 --		_2239				dtvm : device address maked as octet string!
1342 --		snmp7_2239			snmp : --.
1343 081110	hello7_2240			ktvm : start making snmp operating.
1343a 081110	hello7_2241			ktvm : finish making snmp operating.
1343b --		snmp7_2242			snmp: --.
1344 --		full_mib7				mib: added nodes for ktvm and dtvm.
1345 081111	JackS1_User_Short_Prog_Eth_12	JackP: change name of string file in devise to Programm Version.
1346 --		JackS1_User_Short_Prog_Eth_13	JackP: check writed length of programmm to not load foad feil chosen files.	
1347 081113	installer_movers1_Prog_eth_7	installer JackP: --		
1348 --		hello7_2243			ACT155N: change operating parameters witch cs2 : to property work with modem and tranzit.
1349 081114	hello7_2244			BMD35: Start making BMD35.
1350 --		_2245				--: next step.
1351 --		_2246				--: next step.
1352--  		_2247				--: --.
1353 --		_2248				--:--.
1354 081117	_2249				--: compiled and linked version; no interrupts, no xilinx, no init, no device.		
1355 --		_2250				--: pult is programmed!
1356 --		_2251				--: added ti cycle calling device bmd35().
1357 --		_2252				-- : can view some on rempult.
1358 --		_2253				-- : added loading xilinx.
1359  081118	_2254				-- : maked to can view init menu.  
1360 --		_2255				-- : make to sound if get "on" - view "on" cursor blink --? - need this perameter keep in memory?
1361 081119	_2256				--: start making transit.
1362 --		_2257				-- : added Init_BMD34() and BMD34().
1363 --		_2258				-- : start menu moved from main loop to start.
1364 --		_2259				-- : use RemoteMode to change remoteprotokol... 
1365 --		_2260				--: xilinx loaded.
1366 --		_2261				--: start making menu item protokol.
1367 --		_2262				--: with dpd file md35d.dpd can view in menu : protikol : R1/R2. 
1368 081120	_2263				--: make all for baseaddr as unsigned long.
1369 --		_2264				-- : use 32 bit for addresses! can use NVRAM for keep parameters.
1370 --		_2265				--: go back in using funktions inport, inportb, outport.
1371 --		_2266				--: first step to make saved protokol.
1372 081121	_2267				--:can view parameter Protokol.
1373 --		_2268				--: more work parameter Protokol.
1374 --		_2269				BMD35: comment  IsRing().
1375 --		_2270				MPC35 : compiled from act - not added now mpc34.
1376 --		_2271				MPC35 : added mpc34; not have in dpd and in menu protokol; not divide remote for protokol.
1377 081123	_2272				--: make dpd with protokol; menu witch protokol; need divide receive to either protokol. 
1378 --		_2273				--: make using GetProtokol().
1379 --		_2274				ACT155N: make send west transit to ethernet.
1380 --		_2275				--: maked proect can be opened!
1381 --		_2276				-- maked send to eth for east.
1382 081124 	_2277				--: first step to make eth->tranzit need init and make messages buffer.
1383 --		_2278				--: any step.
1384 --		_2279				ACT155N: first version with added channel transit <-> ethehernet.
1385 --		_2280				ACT155N: added some and deleted any errirs with sending transit <-> ethernet.
1386 --		_2281				BMD35: next step.
1387 --		_2282				BMD35 : not hangt if have empty dpd file. 
1388 --		_2283				--: make sound keeped in nvram.
1389 --		_2284				MPC35 : ----.
1390 --		_2285				MPC35 : first work version.
1391 --		_2286				MPC35: more good work if dpd is not writed.
1392 --		_2287				MPC35 : get off isring().
1393 081125	_2288				BMD35: not enable irq2 to pelt - it is not maket_plata.
1394 --		Rempult_10			Rempult: can write .dpd file.
1395 --		installer_rempult2			--: --.
1396 --		_2289				BMD35: change restoring sndlock and in makealarm() use sndlock.
1397 --		_2290				MPC35: --.
1398 --		_2291				--: not read errors as in bmd34 and write to register 0x65e 0xff - to init ethernet.
1399 --		Rempult_11			RemPult: make open .dpd file every time if ping button.
1400 --		installer_rempult3			--:--.
1401 --		hello7_2292			BMD35 : register 0x65e (94 dec)  keeped in nvram addr 0x10000055 (csram+85 dec).
1402 --		hello7_2293			MPC35 : -- + MakeRing analyze sndlock.
1403 --		_2294				--: maked .dpd file witch more right addresses.
1404 --		_2295				BMD34PS: first step.
1405 --		_2296				--: maked some.
1406 --		_2297				--: next step.
1407 081129	_2298				BMD155PS: first version.
1408 --		_2299				MPC35 : to ports 0x5XX added 0x40. Sound maked back. Removed delay.
1409 --		_2300				MPC35: corrected addresses in any ports 0x5XX.
1410 --		_2301				MPC35: added xilinx.
1411 --		_2302				BMD35 : corrected some ports addresses?
1412 081201	_2303				MPC35: correct menu items in dpd file; in programm maked delay for indikator 60 mcs, and removed for 									err_psp channel 0.
1413 --		_2304				MPC35 : maked property divided clocks.
1414 --		_2305				BMD35 : maked proprty clocks and changed dpd.
1415 --		_2306				--: added xilinx, changed .dpd, maked telephone number == addr of device.
1416 --		_2307				MPC35: deleted error to time1, time2, time3 are used as common witch mpc34.
1417 --		_2308				BMD35: --.
1418 --		_2309				BMD35: maked define MENU_DELAY - to use 500 ms for redraw menu.
1419 --		_2310				MPC35 : --.
1420 --		_2311				BMD35 : make do not reading act_type to have two channels.
1421 --		_2312				MPC35: make write to registers before read and mask 0xff for readed errors to inport().
1422 --		_2313				BMD35: maked mask for reading errors.
1423 081202	_2314				BMD35 : maked setting in test mode nvram to zero and to one.
1424 --		_2315				MPC35 : added time corrector to probability.
1425 --		_2316				BMD35 : --.
1426 --		_2317				MPC35 : corrected error to if /1000 time setted to zero.
1427 --		_2318				BMD35 : --.
1428 --		_2319				MPC35 : maked alarm state on  if bit 6 in addr 0x642 is "1".
1429 081203	_2320				--: start using inportx().
1430 --		_2321				--: deleted error to lost input errors. POSTAVKA.	
1431 --		_2322				BMD35 : maked using inportx() correctly are viewed errors if channel is off.	
1432 --		_2323				BMD155 : maked support snmp -> getted to Maxim.
1433 --		_2324				BMD35 : maked for xilinx500 size for loading up to 860000 Bytes.
1434 081205	_2325				MPC35 : write in dpd file 32 registers to work RadView. 
1435 --		_2326				BMD35 : work without .dpd.
1436 --		RView1				Rwiew  : work with modems and mux station 1 numbers mux - 2 ; modem - 3; . comcretly names of dpd files. 
1437 --		snmp7_2327			snmp : for bmd155 added some nodes.
1438 --		snmp7_2328			snmp : added get funktions. 
1439 --		rempult12				rempult : not set all ip addresses to zero.
1440 --		hello7_2329			BMD155 : maked snmp view of lock 1 or 2 channel.
1441 --		hello7_2330			--: maked more for snmp : only not have writing to 21, 22, 23 nodes.
1442 --		Jaccks1_user_short26		JackS1 : maked -_com1
1443 081208	hello7_2331			BMD35 : delete error of not keep parameters of ethernet.
1444 --		installer_rempult4			rempult : not set all addresses to zero.
1445 -- 		installer_movers1_15		movvers1 : go back to comport1 at start.
1446 --		hello7_2332			BMD35 : added init of nvram.
1447 --		hello7_2333			MPC35 : --.
1448 --		snmp7_2334			snmp : added writing to parameters of bmd155 bloopnear, bloopfar, balarmlaser.
1449 --		hello7_2334			BMD155 : --.	
1450 --		hello7_2335			BMD155 : first step to making node BER.
1451 --		_2336				--: maked BER node.	
1452 081209	_2337				--: in BER node no zeros.	
1453 --		_2338				BMD34 : added some nodes to mib.
1454 --		_2339				MPC35 : delete not needed printEthLongHex(test).
1455 --		_2340				BMD155PS : maked power channel; corrected test of channels.
1456 --		_2341				BMD155PS : make BER with 1 digit after point.
1457 081210	_2342				--: maked view BER as "<" ef have zero errors.	
1458 --		_2343				--: irqs 0,1,2,3 removed back from timer.	
1459 --		_2344				BMD34 : maked '<' for BER and interrupts off from timer.	
1460 --		_2345				MAKET_AST155N: maked for Eduard without xilinx and interrupts.
1461 --		mib_bmd155_1; mib_bmd_34_1; mib_bukc_1	SNMP: next step of mibs.	
1462 --		_2346				BMD155PS : indikate BER with using seconds not milliseconds.
1463 --		_2347				BMD34 : --.
1464 --		_2348				BMD34PS: --.
1465 --		_2349				MPC35 : deleted error of not keep remotemode in flash.
1466 --		_2350				BMD34PS: corrected some for rigch get data for nodes.
1467 081211	_2351				TEST_PLATA: first step to make lock.
1468 --		_2352				--: TestMode is  locked!
1469 --		_2353				BMD155PS: getted off checking community in snmp.
1470 --		source_rtcs7_2353			RTCS: --.
1471 --		_2354				BMD34PS : --.
1472 --		_2355				BUKC : --
1473 --		_2356				BMD34PS: recompiled.
1474 081212	_2357				MAKET_PLATA : maked setting to remote lock mode and can reading it from buffersstate.
1475 --		JackS95				JackS1 : can view lock mode of device and have button to lock and have name for key4.  May be  for all wil 						be used key3?
1476 --		hello7_2358			BUKC : first step to make more in mib.
1477 --		hello7_2359			---: delete some errors in mib.
1478 --		hello7_2360			--: make setting power witch using 8 bit.
1479 08.12.15	_2361 				BUKC: recompile.
1480 --		rtcs7_2361			RTCS: --.
1481 --		hello7_2362			BUKC: delete error in prini in GetSTRPD1 ,GetSTRPM1,GetSTRPD2,GetSTRPM2.
1482 --		JackS96				JackS: maked some little changes.
1483 --		JackS97				JackS : maked compatible witch previons dewices.
1484 --		hello7_2363			MAKET_PLATA: continue making lock mode maked compatible witch previons devices indication.
1485 --		JackS1_Eth_59			Jack_E : first step to operate witch lock mode.
1486 --		JackS1_Eth_60			Jack_E : ready for lockmode.
1487 08.12.16	JackS1_Eth_61			Jack_E : added button "Lock".
1488 --		installer_jack_e_12			--: --.
1489 --		JackS1_Eth_62			Jack_E : more good view.
1490 --		installer_Jack_E_13		--:--.
1491 --		hello7_2364			MAKET_PLATA: added lockmode.Value = 3 and FIVE_KEY - for changing id, mac adderess, pok. 
1492 --		_2365				Class DevData is locked for remote.
1493 --		_2366				Classes DevID; DevYear, DevVer1, DevVer2 are locked.
1494 --		_2367				Class POK is locked.
1495 --		JackS1_Eth_63			Jack_E : first try get off green access if device is restarted.
1496 08.12.17	JackS1_Eth_64			Jack_E : work green off in access.
1497 --		installer_Jack_E_14`		--:--.
1498 --		hello7_2368			MAKET_PLATA: disable changing mac address without key and all test modes without needed for testing and 									programming devises.
1499 --		_2369				BUKC: deleted error - in snmp commands to operate pewer was used variable char and for it was get value 						0x100;
1500 --		_2370				BUKC: more right get nodes 7,8,9,10 - correktly divide to 2.
1501 --		_2371				BUKC : make working node11; need make so nodes 12- 16.
1502 081218	_2372				BUKC: maked nodes 12-16 to can have values more as 127.
1503 --		snmp_2372			snmp : --.
1504 --		_2373				BUKC :  added nodes to enable and disable changing power and frequency. 
1505 --		_2374				BUKC :  deleted error to getting in node diap2 data from diap1.
1506 081219	_2375				Maket_Plata : can generate pakets with IP sign.
1507 --		_2376				-- : more advanced packets.
1508 --		_2377				--: send traps without checksum and mac address.
1509 081222	_2378				-- : have correct checksum in IP header!
1510 --		_2379				Maket Plata : UDP checksum is correct!
1511 081223	_2380				ACT155N : make eth_tranzit.
1512 --		_2381				--: have correct transmit.
1513 081224	_2382				-- : go to parse.
1514 --		_2384				-- : can view modem from ethernet!!!!!
1515  --		_2385				-- : clear some not needed variables. 
1516  081225	_2386				-- : start new day : can view all.
1517 --		_2387				-- : delete error in buffcashe::add need use (cashe_size-1)	. All objekts are viewed.	
1518 --		_2388				-- : use cashe size 8 : not get something.
1519 --		_2389				-- : make separate buffer for pakets from ethernet.
1520 --		_2390				-- : delete rror in cashe - cashe work! length = 128.
1530 --		_2391				-- : make separated buffers for east and west.
1531 081226	_2392				--: make cashe for requests : if have request with same parameters - skip it. Good statistics!	
1532 --		_2393t				-- : for test cashe getted off (comparing olwais get zero!) separate answers for east and west getted off. On 									rs485 TUTS IS NOT WIEWED! - so rs485 in act155n - work with ppu! Tuts is wiewed on far end to 							direkt ethernet cable!	
1533 --		rnms1				rnms : view tuts on far end.	
1534 --		hello7_2394t			act155N : get off cashe for requests : view tuts on near modem with modem channel; not view tuts on far end 						 witch tranzit channel. 
1535 --		hello7_2395			act155N: added address "R" to test in cashe : view tuts on far end! on modem witch modem channel(4043), on 						modem witch rs232 channel! (4031) not viewed tuts on modem on "far: ethernet end! and answers from it are half of 					quantity. 
1536 --		hello7_2396			-- : added answers to ethernet from peripheal! view answers on far end!
1537 --		hello7_2397			-- : try and get back witch cashe of answers: working wariant; view if loop answers * 5.
1538 --		_2398				-- make cashe_size = 64
1539 081229	_2399t				--: maked for test many back to have good tranzit answers. now tranzit is ok! (tranzit cable is setted 4347<>4028 marked end 4028  eth 4347)
4348 		_2400				-- irq0 from timer  work better! more answers!
4349		_2401				-- maked buffer for answer messages.
4350		_2402				-- maked message buffer for answers.
4351 --		_2403				-- maked testing in cashe compare() IsRs485()
4352 --		_2404				-- maked return if sended one message to ethernet. 
4353 --		_2405				-- maked some to more best work. 
4354 081230	_2406				-- : any version with debug print.
4355 --		_2407				-- : can view counters of send to eth and receive from eth.
4356 --		_2408				-- : not send to ethernet pakets witch not needed starting data with paket with selfid.
4357 --		_2409				-- : !!!!!!!!!!!!!!!!!!!!!!!! if TUTS is connected all is ok!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
4358 --		_2410				-- : remove debug print.
4359 --		_2411				-- : full remove debug print and make staticvariables for  init buffers
4360 --		_2412				-- : set timer to answer.
4361 --		_2413				-- : work property!
4362 090115	_2414				-- : delete any not needed print. work property.	
4363 --		_2415				-- : ETH_SEND_TIMER maked "0". Tested. Work.
4364 --		_2416				-- : added "else" parse tranzit modem and ethernet buffers
4365 --		_2417				--  :added caches for modem and tranzit - not get somthing? - but devices work!
4366 --		_2418				-- : deleted error in adding to cashe.
4367 090116	_2419				-- : modem do not answer to second requests. Work property on six modems.
4368 --		rnms3			          rnms : work property configuration of six modems.
4369 --		_2420			    ACT155N : maked more right class of cache.
4370 --		_2421				-- : maked cashe for tranzit have only doubled vays for requests!
4371 --		_2422				-- : maked cashe for modem.
4372 090118	_2423			   BMD155PS : compiled any version.
4373 --		_2424				--: deleted error witch rbuffemdmsg : to it not added sothing.
4374 --		JackS1_User_short_prog_eth	JackP : maked static text "status".
4375 --		insaller_movers1_prog_eth_7		-- : --.
4376 --		_2425				ACT155N :  deleted error in  cur_AnsE = 3;
4377 --		_2426				-- : delete some errors witch (char)X>> 8
4378 090119	_2427				BMD155PS : added command 0x5 to remote.
4379 --		_2428				-- : added command 0x17.
4380 --		_2429				-- : maked my_rand().
4381 090121	_2430				-- : my_rand() added olwais. Is commented not needed print.
4382 --		JackS1_eth_65			JackE : work witch mac 0x011004580.
4383 --		installer_jackE_15			--:--.
4384 --		_2431				BMD34PS : maked all changing.
4385 --		_2432				TUTS : maked init embmsg485e to not cyckling answers! Make tehnology printing if try set outputs.
4386 090123	_2433				ACT155N :   Maked embMsgWest.Init(); - in ethernet all pakets will be good - have little packets.
4387 --		_2435				-- : deleted error : recieveWest = 0 =>recieveWestE = 0
4388 --		_2436				-- : added recieveEastE = 0.
4389 --		_2437				-- : not use timer for parse modem and transit.
4390 090126	_2438				MF20 : start making LOAD_EXT_MODEM
4391 --		_2439				-- : maked cs for LOAD_EXT_MODEM
4391 --		_2440				-- : finish for LOAD_EXT_MODEM
4392 --		_2442				BMD155PS : next step.
4393 --		_2443				-- : next step  GOOD.
4394 090127	_2444				ACT155N : tested ok.	
4395 --		_2445				-- : added test mode = 0x27 : one time can reload without reload xilinx.
4396 --		_2446				-- : work property without timer delays!!!!	
4397 --		_2447				-- : make "return" in receiving data from ethernet buffer from first message beeter results!
4398 090128	_2448				--: any point to fixing start changing.	
4399 --		_2449				--: next startpoint. work property witch ethernet + tranzit tested on 5 modems. rnms packed next.	
4400 --		rnms4				rnms : fix results of testing _2449.
4401 --		_2450				ACT155N : tested ok. really good work on five modems witch transit cable. BASE_POINT!!!!!!!!!!!!!!!!!!!!!!!!!!!!
4402 --		rnms5				rnms : fix results of _2450
4403 --		_2451t				TUTS: any try to add crc. have debug print.
4404 --		_2452				ACT155N : next base point. Deleted error to recieveWest = 0
4405 090129	_2453				-- : try send to ethernet from one point tested witch transit. work more property without transit!!!!! BASE_POINT!
4406 --		_2454				-- : add CalcCRC before send .
4407 090130	_2455				-- : maked debug print for added bytes to string.
4408 --		_2456t				BMD35 : send in test "0xe7" to channels.
4409 --		_2457				ACT155N : make while() in send packets and ethreceivetimer used with selfid. Better results without transit. Not tested  on many modems.
4410 --		_2458				-- : maked using telephone number direkt from nvram.
4411 --		_2459				BMD35 : maked more slovly testpu37.
4412 090202	_2460				ACT155N : use my_rand for delay and try send two times to ethernet to have better results.
4413 --		_2461				-- : hawe two buffers for answers and send it in enover time moments.
4414 --		_2462				-- : get off ethsendtimer and more empty ProtocolFromEthTransit().
4415 --		_2463				-- : init ethreceivetimer; reseive not set timer to sero to not lock devise.
4416 --		_2464				TUTS: without crc but init messages and lock enabled.
4417 --		_2465				BMD35 :  changed modem and transit protokols. Need view embsend.
4418 --		_2466				-- : -- next step.
4419 090203	_2467				-- : work modem channel.
4420 --		_2468				-- : work rs485.
4421 090204	_2469				-- : added check2inittransitmoedm - need?? tested.
4422 --		_2470				TUTS: maked version witch lock.
4423 --		_2471				BMD35 : use 3 digits for telephone number.	
4424 --		operate_pok1			operate_pok : start version.
4425 --		_2				--: can work without  .cfg file.
4426 --		_3				-- : not change ip address of device.
4427 --		_4				-- : any step to read pok.
4428 090205	_5				-- : final version.
4429 --		hello7_2472			TUTS : added crc and from command "C" removed init tuts. signature hardvare for test maked "= i"
4430 090206	_2473				-- : really added crc; added cashe for requests. ? need remove sign hardvare = i ?
4431 090209	operate_pok6			operate_pok : can work witch locked devices.
4432 --		_2474				BMD155PS :  added test mode 0x27 restart without reload xilinx.
4433 -- 		_2475				-- : deleted error to not save testmode to flash.
4434 --		_2476				ACT155N : --.
4435 --		_2477				TUTS : maked init to zero signature.
4436 --		_2478				BMD155PS : delete not needed print "crc is not correct".
4437 --		_2479				BMD34PS : maked version with all changes.
4438 090210	_2480				BMD155PS : make counter reading lock and time 6 sec.
4439 --		_2481				-- : use errors after reed-solomon.
4440 --		_2482				-- : next step.
4441 --		_2483				BMD34PS: tested version.
4442 090212	Test232_1			Test232 : start version : can send any byte to rs232.
4443 --		Test232_2			-- : really send what value is writed in Hex format. 
4444 --		Test232_3			-- : can view , what is received from rs232.
4445 --		Test232_4			-- : can view errors.
4446 --		hello7_2484			BMD34PS : maked 3 sec delay.
4447 --		Test232_5			Test232 : maked counters to send and receive.
4448 --		Test232_6			-- : maked increment of sended byte.
4449 090213	hello7_2485			BMD34PS : get off compare errors.
4450 --		Test232_7			Test232 : can view chaer if it is in errror.
4451 --		Test232_8			Test232 : can make quick Test.
4452 --		hello7_2486			ACT155N: any first version with reanimated sockets.	
4453 090216	hello7_2487			-- : any test version for tcpip : can print ip address of client.
4454 --		_2488				-- : can print test string sended from host!!!!!
4455 --		v_c1_2				tcpip client : send any data after connecting.
4456 --		_2489				ACT155N : can send back any data.
4457 --		_2490				-- : any next step.
4457 --		_2491				-- : --.
4458 --		_2492				-- : maked counter and removed some.
4459 090217	_2493				-- : added standart echoserver task!!!!! Work!
4460 --		_2494				-- : remove enover sockets.
4461 --		v_c1_3				tcpip client : maked using port 7 - standart echo server.	
4462 --		_2495				ACT155N : added RDNSRV_init()  - radian server task on port 155. 	
4463 --		source_rtcs7_2495			rtcs : --.	
4464 --		v_c1_4				tcpip client : work with port 155.	
4465 --		_2496				ACT155N : maked receive from RDNSRV().
4466 --		_2497				-- : any next step.
4467 --		_2498				-- : first step adding task for transmit.
4468 --		source_rtcs_2498			rtcs : --.
4469 090218	_2499				ACT155N : send back on port 155 deta from emb232.trans.
4470 --		source_rtcs_2499			rtcs : --.
4471 --		_2500				ACT155N : have readed sign that tcpip buffer is overflow.
4472 --		_2501				BMD34PS : --.
4473 --		_2502				ACT155N : maked test mode 0x28 - echo mode.
4474 090219	JackS98				JackS1 : not break off if device is in mode 28
4475 --		hello7_2503			BMD155_ETH : maked init registers of xilinx : 0x515 from 0x10007ff3; 0x523 from 0x10007ff4. for moskau.
4476 090220	hello7_2504			ACT155N : support TCPIP_CONNECT.
4477 --		_2505				MF20 : --. And can view that xilinx is loaded.
4478 --		_2506				BMD34PS : added command 0x22.
4479 --		_2507				-- : added snmp commands.
4480 090224	_2508				TUTS : added command 0x22.
4481 --		_2509				MF20 : --.
4482 --		_2510				KTVM : maked cs3, and not use checkdone().
4483 --		_2511				BMD34PS : changed command 0x22.
4484 --		_2512				TUTS : --.
4485 --		_2513				MF20 : --
4486 090225	_2514				TUTS : removd crc - to can be view on radview.
4487 --		_2515				ACT155N : command 0x22.
4488 --		_2516				BMD155PS : -- + changed version to 0x251
4489 --		_2517				BMD155 : --.
4490 --		_2518				MPC155 : --.
4491 --		_2519				MPC34 : --.
4492 --		_2520				MPC35 : --.
4493 --		_2521				BMD34 : --.
4494 --		_2522				BMD2 : --.
4495 --		_2523				BMD35 : --.
4496 --		_2524				BUK-C : --.
4497 --		_2525				PUM : --.
4498 --		_2526				DTVM : --.
4499 --		_2527				ACT155N: --.
4500 --		_2528				MF20 : --.
4501 --		_2529				ktvm : make good start without dpd.
4502 090226	_2530				ktvm : make init of nvram.
4503 --		_2531				dtvm : -- + --.
4504 --		_2532				BMD35 : use for tlf number number of station.
4505 --		_2533				TUTS : make back control of crc.	
4506 --		_2534				MPC35 : make Outportb - keep parameters in NVRAM.	Need make this in bmd35.	
4507 090302	_2535				BMD35 : start making Outportb().	
4508 --		_2536				--: maked some.
4509 --		_2537				-- : corrected .dpd file to can set rate of channel1 : can set from radview data rate competible.
4510 --		_2538				MPC35 : work test mode 2 (modem channel.)
4511 --		_2539				-- : first step to add modem channel.
4512 --		_2540				MPC35 :  next step to make remote with modem channel.
4513 --		_2541				BMD35 : add work modem and transit channels if remotemode = 0.
4514 090303	_2542				BMD35 : maked correktly init of protokol.
4515 --		_2543				MPC35 : --.
4516 --		_2544				-- : remove debug printing.
4517 --		_2545				BMD35 : --.
4518 --		_2546				MPC35 : start making MPC35_MOD_CHANNEL.
4519 090304	_2547				-- : next step to making  MPC35_MOD_CHANNEL
4520 --		_2548				-- : try back compile without ETH_TRANZIT.
4521 --		_2549				-- : more removed tranzit; compiled witch ETH_TRANZIT.
4522 --		_2550				ACT155N : compiled now for remove some code for eth_tranzit ti EMBISR.cpp.
4523 --		_2551				MPC35 : make init some buffers and variables!
4524 090305	_2552t				BMD35 : any step to make eth_tranzit.
4525 --		_2553t				BMD35 : next step to make eth_tranzit  /// wivout answermod.inc.
4526 --		_2554				BMD35 : --.
4527 --		_2555				BMD35 : maked up to md35 level ; need make all points for buffer.
4528 --		_2556				BMD35 : maked many using tbuffembmsgall as in act155n. 
4529 --		_2557				MPC35 : next step to make property ETH_TRANZIT.
4530 --		_2558				-- : make more for channel eth_tranzit.
4531 090306	operate_pok7			Operate POK : can view version of xilinx.
4532 --		operate_pok8				-- : more property work witch uart.
4533 090310	_2559t				BMD35 : first step to can view on menu version of programm.
4534 --		_2560t				-- : --.
4535 --		_2561				BMD35 : can view version of programm.
4536 --		_2562				BMD35 : can view version of xilinx. 
4537 --		_2563				MPC35 : can view versions of xilinx and programm.
4538 --		_2564				DTVM : can view version of programm.
4539 --		_2565				KTVM : --.
4540 090311	Jacks1_user_short_prog_eth_15	JackP : changed parser to can work with all IDs.
4541 --		installer_movers1_prog_eth_9 	-- : --.
4542 --		Jacks1_user_short_eth_21		JackX : --.
4543 --		installer _movers1_eth_8		-- : --.
4544 --		JackS1_eth_66			JackE : --.
4545 --		installer_Jack_E_16		--:--.
4546 --		JackS1_eth_67			JackE : in parseanswer() where should be address check if have symbol '%' - can view any names of xilinx file 							witch '-'.	
4547 --		installer_jack_e_17			--:--.
4548 --		JackS1_user_short_eth_22		JackX : --.
4549 --		installer_movers1_eth_9		JackX : --.
4550 --		Jacks1_user_short_prog_eth_16	JackP : --.
4551 --		installer_movers1_prog_eth_10 	JackP : --.
4552 090313	OperateState1			OperateState : first version of programm can to revrite any programs on device without reload xilinx. 
4553 --		RemPult_13			RemPult : more better work witch mac address 001111:004025.
4554 --		installer_rempult5			-- : --.
4555 090317	JackS1_eth_68			JackE : property work button "Cansel".
4556 --		installer_jack_e_18			-- : --.
4557 --		JackS1_user_short_eth_23		JackX : --.
4558 --		imstaller_movers1_eth_10		--:--.
4559 --		Jacks1_user_short_prog_eth_17	JackP :
4560 --		installer_movers1_prog_eth_11	JackP : --.
4561 --		RemPult_14			RemPult : --.
4562 --		installer_rempult_6			--:--.
4563 --		JackS1_User_Short_27		MoverS :--.
4564 --		installer_movers1_16		-- : --.
4565 --		JackS1_user_short_prog_2		JackSP : --.
4566 --		Installer_jacks1_user_short_prog_2	JackSP : --.
4567 -- 		JackS99				JackS  : --.
4568 --		hello7_2566			BMD35 : make differen digits and default telephone numers for protokols r1 and r2.
4569 090318	_2567				-- : maked number of version 252 to can view or have tlf numbers 3 digits for old protokol and 2 digits for new protokol and common numbers 777 for old and 99 for new.
4570 --		_2568				BMD35 : maked work with port 0x49.
4571 090319	_2569				BMD35 : maked correctly operating with programm RView about 
4572 --		_2570				-- : changed version to 253.
4573 090320	_2571				BMD35 : make real work telephone number with three digits.
4574 --		JackS100			JackS1 : can loop write and read data.
4575 --		_2572				ktvm : maked rwhold 2 cyckles = 20 ns.
4576  090323	_2573				bmd35 : maked to r2 - new protokol, r1 - old protokol.
4577 --		_2574				mpc35 : --.
4578  --		_2575				bmd35 : to property view telephone channels : change in some ports Inportv, Outportb, Out.
4579 090331	JackS1_Eth_69			Jack_E : make loop writing and reading from device.
4580 --		installer_jack_e_19			-- : --.
4581 090401	ServicePack1			ServicePack : start version.
4582 --		ServicePack2			-- : next step.
4583 --		ServicePack3			-- : --.
4584 --		hello7_2576			MF20 : compiled for maket_plata!  added commands for restart of device and set test mode (later can be set test mode 0x27).
4585 090402	_2577				--: changed command 0x36.
4586 -- 		ServicePack4			changed using command 0x36.
4587 --		ServicePack5			added checkbox to not reload xilinx after restart.
4588 --		hello7_2578			MF20 : support programm SERVICE _PACK : CHANGED version up to      !!!!! 2 5 6 !!!!
4589 --		ServicePack6			ServicePack : make buttons : restart programm only.
4590 --		hello7_2579			BMD34 : support ServicePack!
4591 --		hello7_2580			BMD2 : --.
4592 --		_2581				BMD155 : --.
4593 --		_2582				BMD155PS : --.
4594 --		_2583				ACT155N : --.
4595 --		_2584				BUKC : --.
4596 090403	_2585				PUM : --.	
4597 --		_2586				MPC34 : --.
4598 --		_2587				MPC155 : --.
4599 --		_2588				BMD35 : --. need add changing dpd.
4600 --		ServicePack_7			ServicePack : can write dpd.
4601 --		_2589				BMD35 : added can changing dpd to servicepack!
4602 --		_2590				MPC35 : --.
4603 --		_2591				PU_M : start version.
4604 090406	_2592				-- : next step.
4605 --		_2593				-- : make xilinx size 740k.
4606 --		_2594				-- : 180k; added remote from modem bmd155.
4607 --		_2595				-- : next step.
4608 --		_2596				-- : removed multiplexer.
4609 --		_2597				-- :  maked version PU_M_MUX witch multiplexer.	
4610 090407	_2598				PU_M : mked using telephone number from nvram.	
4611 --		_2599				PU_M_MUX : --. 
4612 --		_2600				PU_M : maked some inits.
4613 --		_2601				PU_M_MUX: --.
4614 --		_2602				PU_M : added counting erors from bmd155 and can operating with interrupt irq0!
4615 --		_2603				PU_M_MUX : --.
4616 --		_2604				PU_M : maked correct types of data in struct  Emb2TypeVer - can property view on  RadView and ServicePack.
4617 --		_2605				PU_M_MUX : --.
4618 --		_2606				ACT : maked with all last changes () this is not 700 MHz!
4619 --		_2607				PUM( = BUK) : maked with all last changes.
4620  090408	_2608				KTVM : maked calling SetPLLKTVM in testmode 0x29.
4621 --		_2609				KTVM : start making I2C.
4622 090409	_2610				--: next step to make I2C.
4623 --		_2611				-- : maked loading coder to I2C test mode 0x30 - v1; 0x31 - v2.
4624 --		_2612				-- : deleted error pin 9 is not init.
4625 --		_2613				PU_M : make more strong command for reset.
4626 090410	_2614				PU_M_MUX : --. 
4627 --		ServicePack_8			ServicePack : --.		
4628 --		_2615				PU_M : make all programm commands to one command.
4629 --		ServicePack_9			ServicePack: --.
4630 --		_2616				PU_M : added to program tests of telephone and test of modem
4631 --		_2617				-- : delete error in added test.
4632 --		_2618				KTVM : disable kash when make jump to srgey programm.
4633 --		_2619				DTVM : make more high size of xilinx.
4634 090413	_2620				PU_M : enable interrupts bits in init - tests work.
4635 --		_2621				-- : make checking crc and not use 0x55 and 0xAA in commands 0x5 and 0x38
4636 --		ServicePack_10			ServicePack : not use 0x55 and 0x AA in command 0x38        
4637 090414	ServicePack_11			-- : can add shift<<16 to address to write big files!!!!!!!!
4638 --		_2622				PU_M: can rewrite programm with new servicepack!!!!!!
4639 --		_2623				PU_M : use absolute address forwriting of file.
4640 --		ServicePack_12			ServicePack : --.
4641 --		_2624				PU_M_MUX : --.
4642 --		_2625				MF20 : --.
4642 --		_2626				BMD34 :--.
4643 --		_2627				BMD34PS : --.
4644 --		_2628				BMD2 : --.
4645 090415	_2629				PU_M : added command "2".
4646 --		_2630				-- : changed version to "2 5 7"( this have command "2")!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
4647 --		_2631				BMD155 : --.
4648 --		_2632				BMD155PS : repaired command "2" change version to "258"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VVVVVVVVVVVVV
4649 --		_2633				ACT155 : --.
4650 --		_2634				ACT155N : --.
4651 --		_2635				BUKC: --.
4652 --		_2636				PUM=BUKC: --.		
4653 090416	_2637				MPC34:--.	
4654 --		_2638				MPC155 : --.
4655 --		_2639				BMD35 : --.
4656 --		_2640				MPC35 : --	
4656 --		_2641				KTVM : first step to make prot_2 : need init all that added!	
4657 --		_2642				KTVM : change chip_selekts timing and at init disable cashes!
4658 --		_2643				KTVM : temporary commented using xilinx and ktvm_init.
4659 --		_2644				-- : next step to add KTVM_PROT2 : need now add this to dpd and to scan in menu.
4660 090417	_2645t				-- : ktvm : for maket plata : get back init to work .dpd.		
4661 --		_2646t				-- : make more little delays.
4662 --		_2647				-- : maked wor full plata.
4663 --		_2648				PU_M : start making new test mode2.
4664 --		_2649				-- : first step tuo use classes for testmode2.
4665 --		_2650t				-- : maked one time working test mode2 : need make olweis enabled enable_irg0().
4666 090420	_2651t				-- : full maked working test of modem channel, work on interrupts.
4667 --		_2652				-- : maked test on interrupts for tranzit channel.
4668 --		_2653				-- : maked for all channells.
4669 --		_2654				-- : maked more comfortable time of test.
4670 --		_2655				-- : added testin for channells modem and up1 and up2.
4671 --		Jack_E				Jack_E : more wide window for data.
4676 --		_2656				PU_M : removed some not needed.
4677 --		_2657				TUTS : add support srvicepack.
4678 --		_2658t				KTVM: can set and change protokol r1/r2.
4679 --		_2659				PU_M :maked self remote - no remote of modem - need add commands for servicepack.	
4680 090421	_2660				-- : packed before make remote from modem remote.	
4681 --		_2661				-- : maked answerpum.
4682 --		JackS1_user_short_eth_24		JackX : maked getip1().
4683 --		JackS1_user_short_eth_25 		JackX:  maked keep ip address in device.
4684 --		installer_movers1_eth_11		-- : --.
4685 --		JackS1_user_short_prog_eth_18	JackP:  maked keep ip address in device.
4686 --		installer_movers1_prog_eth_12	JackP : --.	
4687 090422	hello7_2662			PU_M : 	added command 0x22 (changing IP)
4688 --		_2663				PU_M_MUX : --.
4689 --		JackS1_user_short_DPD_eth_3	JackD : maked keep ip address in device.
4690 --		RemPult_15			RemPult : --.
4691 --		installer_RemPult_7			-- : --.
4692 --		JackS101			JackS1 : more quickly test of rs232.
4693 --		JackS102			-- : maked any times without transmit.
4694 --		ServicePack13			ServicePack : maked printing type of device. Need check!
4695 090423	hello7_2664t			KTVM : deleted error : remote mode at start correctly readed from flash.
4696 --		_2665t				KTVM : maked init of remotemode.
4697 --		ServicePack14			ServicePack : if not have device number in base - print it.
4697 090424	_2666				ACT155N : maked SERIAL_ETH_OFF_TIMEOUT_MS  1ms : to make more little losses from ethernet.
4698 --		_2667				TUTS : first step to using ring buffer for usart0 : need now uncomment polling_scan_usart0 and remove from 						mqx isr for usart0 calling my function. Hane changed  io_serial_int_read to io_serial_int_read1. - not change symbols
4699 --		_2668				MF20 : go back to use interrupt for usart0.
4700 090427	_2669t				ACT155N : test version to answer to all addresses.
4701 090428	_2670				DTVM : maked prot_2 : for support servicepack.
4702 --		_2671				ACT155N : make better parameters for have more answers (485 period maked 100ms)
4703 090430	_2672				-- : maked init of embmsg485E an two points - work better on asu!
4704 090504	_2673				KTVM : start making sergey changes. need add I2c! before start
4705 --		_2674				-- : any step to making sergey changes.
4706 --		_2675				-- : next step.
4707 090505	_2676				-- : --.
4708 --		_2677				-- : --.
4709 090506	_2678				BMD35 : maked test tranzit , worked on standert interrupt isr.
4710 090508	_2679				-- : maked version ____________________-----  2 5 9 ---------------------!!!!!
4711 --		_2680				BMD34 : --.
4712 --		_2681				BMD34PS : --.
4713 --		_2682				BMD2 : --.
4714 --		_2683				ACT155N : --.
4715 --		_2684				ACT155 : --.
4716 --		_2685				BMD155PS : --.
4717 --		_2686				BMD155 : --.
4718 090512	_2687				MPC35 : --.
4719 --		_2688				MX155 : -- now this test is not used!
4720 090513	_2689				BMD35 : start make test tlf.
4721 --		_2690				-- : --.
4722 --		_2691				BMD35 : finished adding to telephone test ring test.
4723 --		_2692				ACT155N : --(added ring test).
4724 --		_2693				ACT155N :  maked updating signature_softvare in main loop to property can view in arm. _____----2 6 0---- 
4725 --		_2694				DTVM : maked init of cs2 as in ktvm.
4726 090515	_2695				ACT155N : maked pragma all_addr for ethernet channel. Startfind errors.
4727 --		_2696				KTVM : maked some changes in init device.
4728 --		_2697				--: --.
4729 --		_2698				-- : --.
4730 --		_2699t				ACT155N : make multiaddress : 6000 - 6999 - for tranzit 7000 - 7999 - for ethernet.
4731 090518	_2700				-- : maked one transmit to ethernet and not enable transmit in  rs232e
4732 --		_2701				BMD34 : maked update softvare version and ring test.
4733 --		_2702				BMD34PS : --
4734 --		_2703				BMD2 : --.
4735 --		_2704				PU_M : --.
4736 --		_2705				PU_M_MUX : --.
4737 --		_2706				BMD35 : --.
4738 --		_2707				MPC35 : --.
4739 --		_2708				MPC34 : --.
4740 --		_2709				MPC155 : --.
4741 --		_2710				BMD155 : --.
4742 --		_2711				BMD155PS : --.
4743 --		_2712				ACT155.
4744 --		_2713				ACT155N : changed delay to 75 ms work better. maked version ________________---2-6-1---___________
4745 --		_2714				KTVM : maked some changes.
4746 090519	_2715				ACT155N : remove counter to 10 in parse rs232. make version ------2---6---2------------_________________
4747 --		_2716				BMD155 : --.
4748 --		_2717				BMD155PS : --.
4749 --		_2718				ACT155=bmd155 : --.
4750 --		_2719				BMD34 : --.
4751 --		_2720				BMD34PS : --.
4752 --		._2721				BMD2 : --.
4753 --		_2722				DTVM : bloked init to do not have using cse2.
4754 090520	_2723				-- : comment temporary test_rb() in callback0()
4755 --		_2724				PU_M : remove counter to 10 in parse 232.
4756 --		_2725				PU_M_MUX : --.
4757 --		_2726				DTVM : support loading video and audio files.
4758 --		RemPult16			Rempult : support writing video and audio files.
4759 --		RemPult17			RemPult : open .bin files; right open tftp server. 
4760 --		installer_rempult8			--:--.
4761 --		hello7_2727			MPC34 : 	remove counter to 10 in parse 232.
4762 --		_2728				BMD35 : --.
4763 --		_2729				MPC35 : --.
4764 090521	RemPult18			Rempult : write full size of videofile.
4765 --		installer_rempult9			--:--.
4766 --		_2730				DTVM : more property load video and audio.
4767 --		_2731				DTVM : deleted error to not hangt without writed dpd_file.
4768 --		_2732				DTVM : next step. Deleted little error to print and maked test mode 0x33.
4769 090522	_2733				DTVM : decoder started!!!!!!!
4770 --		_2734				DTVM : next step to make.
4771 --		_2735				-- : add delays to read32 and write32.
4772 --		_2736				-- : removed debug print.
4773 --		_2737				TUTS : removed i232 counter.
4774 --		_2738				MF20 : --.
4775 090524	_2740				DTVM : maked delays and setpll.
4776 --		_2741				PU_M : keep port parameters in NVRAM.
4777 --		_2742				PU_M_MUX : --.
4778 090525	_2743				MF20 : support ServicePack : declare shift as unsigned long!
4779 --		_2744				-- : maked init of data and counter in write_buffer_char1(). Changed version to 263!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
4780 090527	source_mqx7_2745			MQX : enetprv.h : changed int_disable() to my_int_disable_eth() 
4781 --		source_rtcs7_2745			RTCS : rtcs_prv.h : changed  int_disable() to my_int_disable_eth()
4782 --		hello7_2746			KTVM : make some changes in set_sound()
4783 --		_2747				DTVM : --.
4784 090528	ServicePack15			ServicePack : get message if comport1 is used by another programm or disabled.
4785		_2748				DTVM : use irq0 for EmbCS24.IsrXX()
4786 090529	_2749				MF20 : maked ver 263 on old mqx and rtsc (eth disabled all interrupts). And correctly init variables in write_buffer_char1()
4787 --		_2750				BMD2 : --.
4788 --		_2751				ACT155N : --.
4789 090601 	_2752				BMD155 : --.
4790 --		_2753				BMD155PS --.
4791 --		_2754				ACT155 --
4792 --		_2755				BUK-C --
4793 --		_2756				PUM = BUKC : --
4794 --		_2757				DTVM : first step to make Âõîä_E1
4795 --		_2758				DTVM : next step to make --.
4796 --		_2759				-- : --.
4797 --		_2760				-- : --.
4798 --		_2761				-- : right setted test signal.
4799 --		_2762				-- : repaired work1.cpp.
4800 --		_2763				PU_M : maked init of data and counter in write_buffer_char1().
4801 090602	_2764				PUM_MUX : --.
4802 --		_2765				MPC-34 : --
4803 --		_2766				MPC155 : -- !!! deleted error! unsigned short shift -> unsigned long shift
4804 --		_2767				BMD35 : --.
4805 --		_2768				MPC35 : --.
4806 --		_2769				TUTS : --!!! deleted error unigned short shift -> unsigned long shift
4807 --		_2770				DTVM : start make i2cread.
4808 --		_2771				DTVM : next step : any changes in set _sound and some added to hello.c
4809 --		_2772				DTVM : last version. 0xf8 not sevefd to 0xf3.
4810 --		_2773				DTVM : temporary stopped.
4811 --		_2774				KTVM : added some_init.
4812 --		_2775				KTVM : maked reading 0x12 and first try reading I2C.
4813 090603	_2776				broken : KTVM : changed I2C reading.
4814 --		_2777				KTVM : maked indikating "no signal".
4815 --		_2778				PRM_PCH : first version.
4816 --		_2779				PRM_PCH : next step.
4817 --		_2780				KTVM : repaired reading on i2c.
4818 --		_2781				KTVM : maked get off lads pal/secam if signal is off.
4819 --		_2782				KTVM : change numbers of ports 0x5XX to 0xXX
4820 --		_2783				KTVM : remove some inits to ktvm_init().
4821 090604	_2784				KTVM : make different LoadCoder() for signa linputs 
4282 --		_2785				-- : maked correcly address for keep rate 4e1 /3e1.
4283 --		_2786				KTVM : maked operating leds.
4284 --		_2787				DTVM : 
4285 --		_2789				KTVM : kan keep 4e1 after power get off.
4286 --		_2790				DTVM : --.
4287 090605	_2791				PRM_PCH : maked from bmd155.
4288 --		_2792				DTVM : temporary comment in set_audio changing rate and ncn  -> not all variants are loaded!!!!
4289 --		_2793				DTVM : maked more correctly work witch dpd and menu : setting pal/secam and bars /off.
4290 --		_2794				KTVM : make some test writing and prints and make loading some in set_audio if use setting 2mono.
4291--		_2795				KTVM : maked more delays for suksessful print.
4292 --		_2796				PRM_PCH :  added some from bukc.
4293 --		_2797				PRM_PCH : added some commands from bukc.
4294 090606	_2798				PRM_PCH : added some structures.
4295 --		_2799				-- ; next step.
4296 --		_2800				-- : --.
4297 --		_2801				-- : --.
4298 --		_2802				-- : maked answer tio command 00.
4299 --		_2803				-- : tested answer from maket plata to command 01.
4300 --		_2804				-- : start making unions.
4301 --		_2805				-- : maked unions.
4302 --		_2806				-- : maked one command for Edik.
4303 --		_2807				--: repaired command1.
4304 --		_2808				-- : maked command3.
4305 --		_2809				-- : maked command6.
4306 090607	_2810				-- : maked some commands for Edik.
4307 --		_2811				-- : maked full start version.	
4307 --		_2812				-- : version for non - maket plata, maked answer type of command for command 2.
4308 --		_2813				-- : send to edik some only if roulette1 or 2 return  1 or have any command - not olweis.	
4309 --		_2814				-- : if have one answer fom edik set hardvare bits to one	
4310 --		_2815				--: maked technology print; maked indikating if power is off.
4311 090608	_2816				DTVM : maked next step.
4312 --		_2817				DTVM : next step.
4313 --		_2818				DTVM : maked delay and after delay writing f8 <- 03  f9<- 03 work!
4314 --		_2819				PRM_PCH : maked setting set_att.
4315 --		_2820				DTVM : get off funktions using port 0x505.
4316 --		_2821				DTVM : more right work setvideostandart and settestsignal.
4317 --		_2822				-- : make keep sound sate in nvram.
4318 090609	_2823				DTVM : next step.
4319 --		v_c1_5				tcpip client : client for prm_pch : send one command for prm_pch1 and have ansver.
4320 --		hello7_2824			PRM_PCH : next step
4321 --		_2825				PRM_PCH - test version witch debug print.
4322 --		_2826t				DTVM : any next step.
4323 --		_2827t				DTVM : any next try.
4324 --		_2828				PRM_PCH : changed formula. - tested
4325		_2829				DTVM : any next step.
4326 --		_2830				DTVM : if load first chamel last it will be not brocked!
4327 --		_2831				DTVM : maked sete14() to end after long delay() and maked writing to 0f 00 - to not broken channells.
4328 --		_2832				BMD155 : maked test print to terminal.
4329 --		_2833				PRM_PCH : make funktions keepparam and restoreparam.
4330 --		_2834				-- : make cycle requests and restore parameters.
4331 090613	_2836				-- : start making commands 7 and 8.
4332 --		_2837				-- : changed struct em5statusreceiver.
4333 --		_2838				-- : any changing in send status - anly need at start send freq and level.
4334 --		_2840				-- : maked commands 7 and 8 for channel1.
4335 --		_2841				-- : maked commands 7 and 8 for channel2.
4336 --		_2842				-- : version without debug print.
4337 --		_2843				-- : more correctly get answer to command "8".
4338 --		_2844				--: added unsigned short ConvVal
4339 --		_2845				-- : used signed short ConvVal.
4340 090615	_2846				-- : get on remote back to can set ip address to command 0x22
4341 --		_2847				-- : hardvare[1] not fill from read_xil_char().
4342 --		_2848				-- : calling keepparam maked addr and data as in callings.
4343 --		_2849				-- : remove debug print from setatt().
4344 --		prm_pch1			Operate_PRM_PCH : can send command1.
4345 --		_2850				PRM_PCH : maked delay1 and delay2.
4346 --		_2851				-- : make get off leds alarms.
4347 --		_2852				-- : restore in status att and freq freq from storage and from setted commands. 
4348 060916	_2853				PRM_PCH : new formula.	
4349 --		_2854				-- : maked operate leds.	
4350 --		PRM_PCH2			-- : receive some?		
4351 --		Prm_pch3			-- : can view answer of device!
4352 --		prm_pch4			-- : have 8 commands.
4353 --		hello7_2855			PRM_PCH : some changes in formula2.
4354 060917	_2856				-- : some changed in formula and get on roulette.	
4355 --		_2857				-- : --.
4356 --		_2858				DTVM : maked restart from menu command.
4357 --		prm_pch5			PRM_PCH : can view more in answers in messageboxes. 
4358 --		_2859				KTVM : is compiled.
4359 060918	_2860				PRM_PCH : using formula3.
4360 --		_2861				PRM_PCH : make delay in scan 3ms.
4361 060919	_2862				-- : any changes in formula.
4362 --		test232_9				send some to 232 without requests for device after test.
4363 --		_2863t				MF20 : test version witch pragma TEMPORARY+MAKE_FULL_ETH : do no work under Jack_E.
4364 --		_2864				DTVM : get off last loading sete14().
4365 --		_2865				PRM_PCH : generated one of three values for formula3.(555000)	
4366 --		_2866				PRM_PCH : maked first version for command 9 - request information about up down channel.
4367 060922	_2867				-- : maked init array of levels if is received command "7".
4368 --		_2868				-- : setted back delay to zero, removed calc crc, 
4369 --		_2869				-- added some to commannd9.
4370 --		_2870				-- clear statistics to command9.
4371 --		_2871				-- maked back not clearing delay if some received.
4372 --		_2872				--changed some in formula. -> this version is sended to user!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
4373 --		_2873				-- : deleted error!!!! get off using getmod() in init without testing of usedmod()!!!!! This need make in all devices!
4374 --		_2874				-- : deleted two errors : crc() : not need add to reading value 1; calccrc : need get to (unsigned char).
4375 --		_2875				-- : deleted error : if put off channel 1 it can be setted in signature hardvare.
4376 060923	_2876				BMD155 :  deleted error!!!! get off using getmod() in init without testing of usedmod()!!!!! changed version to 										-264-vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
4377 --		_2877				BMD155PS : --.
4378 --		_2878				ACT155 : --.
4379 --		_2879				ACT155N : --.
4380 --		_2880				PRM_PCH : deleted error for curval2++,  maked full roulette, removed some from remote.
4381 --		_2881				-- : removed more from remote.
4382 060925	_2882				KTVM : deleted error of not init remote if have return without dpd.
4383 --		_2883				PRM_PCH : use Formula4.
4384 --		_2884				DTVM : maked return from init if dpd file is not written
4385 --		_2885				DTVM : maked debug print of interrupts  to comport and to ethernet. Get on all interrupts.
4386 --		_2886				-- : maked disable interrupts in time of read16 write16 read32 and write32.
4387 --		_2887				-- : remove debug print to ethernet.
4388 --		_2888				-- : maked operating e14norma from state register.
4389 --		_2889				-- : next step maked operating rele
4390 --		_2890				-- : make restore saved state of test signal and videostandart.
4391 --		_2891				-- : restore file hello7.h.
4392--		_2892				ktvm : deleted error with mask of getting off PAL/SECAM
4393 090629	_2893				ACT155N : maked back i232; ADDED commands 5 and 38!!! Get off pragma "RS232E_ENABLE"; xilinx is 									loaded only if before is not loaded!!!!; to command 28 added prameter 6 for loading xilinx!

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>hot restart
4394 --		_2894t				ktvm : any next step from sergey.
4395--		_2895				-- : any next changes in any inits.
4396 090630	_2896				ACT155N : maked in hardware[2] counter of restarts up to 255 this is version 						-265------------------------------------------------!!!! only fom hier ast 155 support service pack.
4397 --		_2897				DTVM : added some loadings for pll.
4398 090701	_2898t				ACT155N : compiled with pragma "ALL_ADDR" for operate stend and imitate many stations.
4399 --		_2899				ACT155N: maked many constants back as from version 247; get off emb485e.Init, in testmode.value = 0x36 : reload only xilinx. Need make restarting eth controller.
4400 --		_2900				DTVM : make more long delays in reset_buffer(); and delete error on == need = and maked printing results.
4401 --		_2901				ACT155N : maked restarting ethernet controller if 10 secs is no_link; maked for ethernet maximum priority.
4402 --		_2902				KTVM : maked loading delay to sound encoder.
4403 --		_2903				ACT155N : maked not only restart but autoneg ethernet controller..
4404 --		_2904				KTVM : maked delay : 18 -> 19.	
4405 --		_2905				TUTS : maked restarts counter and command for clear restarts counter.
4406 090702	_2906				KTVM : can get on oshibki and get off (PAL/SECAM)	
4407  --		_2907				KTVM : maked operating  of inputs from menu.	
4408 --		_2908				TUTS : ethernet do not interrupted from rs232 and rs485.	
4409 --		_2909				DTVM : changed address for alarms rele from 0xf5 to 0xf6
4410 --		_2910				TUTS : eth do not stopped; do not use cashe; need get off checksum?
4411 --		_2911				ACT155N : eth do not stopped
4412 --		_2912				KTVM : maked LoadCoder for second input. 
4413 090703	_2913				KTVM : in load11 changed in init getmode and getsound
4414 --		_2914				KTVM : changed some in set_sound().
4415 --		_2915				KTVM : --.
4416 090706	_2916				TUTS  : first step to make sending version : init message if crc is bad. 
4417 --		_2917				TUTS : next stop to make more optimal operatig, disable interrupts if send to ethernet.
4418 --		_2918				TUTS : delete many not needed, move restarts counter in hardware[15] .
4419 090707	_2919				ACT155N : maked self stack for rs232.
4420 --		_2920				-- : for rs485E.
4421 --		_2921				-- : formodem channel.
4422  --		_2922				-- : for ethernet channel
4423 --		_2923				--: remove not needed code and making include stack_commands.c
4424 --		_2924t				-- : for test : answer to all addr.
4425 --		_2925t				DTVM : dtvm : for test : not make restarting  from errors state - for debug.
4426 090708	_2926t				ACT155N : maked with pragma all_addr forst step to can get off eth_tranzit mode. Need init all objekts of embmsg.
4427 --		_2927,28				ACT155N : remove emb232e, compiled without all_addr.
4428 --		_2929				-- : init more messages.
4429 --		_2930				-- : usart0 not disable ethernet to not loss devices never first modem.
4430 090709	_2931				DTVM: used deltaPTS in one point.
4431 --		_2932				ACT155N : use for ethtranzit only one tBuffEmbMsgEthAll. SENDED AS 						version____________265________________________________!!!!!!!!!!!!!!!!!!!!!
4432 --		_2933				DTVM : any changes in operating errors.
4433 --		_2934				ACT155N : print state of eth_tranzit to signature_software
4434 090710	_2935				DTVM : maked menu item Çâóê ñèíõð. 
4435 --		_2936				PU_M_MUX : maked more bigger size of xilinx.
4436 --		_2937				ACT155N: disabled interrupts when call RDN_transmit() set version 
___--------------------266------------------------------------
4437 --		_2938				PU_M_MUX : maked tests and cse4, remove debug print,
4438 --		_2939				ACT155N: removed debug print.
4439 --		_2940				PRM_PCH : start make PRM_PCH_THREE_LINES, maled power channel in class emb34act 	
4440--		_2941				ACT155N : added snmp.	
4441 090713	_2942				-- : remove int_disable int_enable from receive and change in transmit while to if.
4442 090714	_2943				PRM_PCH : next step to make PRM_PCH_THREE_LINES.
4443 --		_2944				-- : compiled for two lines and formula3. not work?
4444 --		_2945				-- : maked version for three lines!
4445 090715	_2946				PU_M_MUX : use inportb3, outportb3.
4446 --		_2947t				PRM_PCH : for test maked! three lines and use formula5.
4447 --`		ServicePack16			ServicePack : added button for direkt reload xilinx - need for devices witch hot restart (now ACT155N).
4448 --		_2948				PU_M_MUX : not reload xilinx in hot restart.	
4449 --		_2949				DTVM : maked restart xilinx only from pult.	
4450 090716	_2950				PU_M_MUX: keep in NVRAM parameters of multiplexer - not tested.	
4451 --		_2951				-- : added for keep address 0x37.
4452 --		JackS1_Eth_71			Jack_E	added to restart command, command for reload xilinx.
4453 --		installer_Jack_E_20		-- : --.
4454 --		_2952				PRM_PCH : compiled three lines formula3, correct calculate checksum.
4455 --		_2953				-- : make modescan1 = 0 in MakeNextStepScan1().
4456 090717	_2954				-- :  01 :compiled witch mode two_lines tested by edik.
4457 --		_2955				-- :  02 :three_lines - tested by edik, commutator.
4458 --		_2956				-- : v0917.03 : use formula3 direkt from viezd1 
4459 --		_2957				-- v091704 : used formula5.
4460 --		_2958				- v070905 : corrected formula5
4461 --		JackS103			JackS : some changes in desigm and add to reset button command to reload xilinx - to reload it anywai without 
hot restart.
4462 090803	_2959				PRM_PCH : state of this projekt after otpusk. for radview ver vill be 266; for string ver is 275. As Is after Max.
4463 --		_2960				BMD35 : maked version with hot restart - not reload xilinx if it is loaded; for this device writed version 						_______________-----------276--------__________
4464 --		_2961				MPC35 : --.
4465 --		_2962				MF20 : -- .
4466 --		_2963				BMD34: --.
4467 --		_2964				BMD34PS : --.
4468 --		_2965				BMD2 : --.
4469 --		_2966				BMD155 : --.
4470 090804	_2967t				BMD35 : maked any change in class embcommand : to function add added init if value is more as maximum.
4471 --		_2968				-- : removed debug print.
4472 --		_2969				-- : maked embthree.clearerr in init procedures to correctly view zero errors without pushing esc button.
4473 090805	_2970				MPC35 : compiled with corrected class embcommand.
4474 --		_2971				BMD155PS : compiled with hot restart.
4475 --		_2972				ACT155=BMD155 : --.
4476 --		_2973				BUK-C : --.
4477 --		_2974				PUM = BUKC : --.
4478 --		_2975				PU_M : --.
4479 --		_2976				mpc 34 :-- .
4480 --		_2977				mpc155 : --.
4481 090806	_2978				BMDN: modem N+1 start version maked from bmd155
4482 --		JackS1_User_Short_Eth_26		JackX: on restart send command BH36 : direktly reload xilinx.
4483 --		_2979				DTVM : take dtvm200 and init26 from Sergey.
4484 090807	_2980				DTVM : remove tests checksum and nvram from point between init dtvm and enabling interrupts.
4485 --		installer_jackx_15			JackX : on restart send command BH36 : direktly reload xilinx.
4486 --		_2981				DTVM: move enabling iterrupts never main loop to not have time delay before servicing in main loop.
4487 --		_2982				DTVM : state after tests.
4488 090810	Servicepack_17t			Servicepack : try automatic add headers : NEED files set in catalog of programm!!!
4489 090810	Servicepack_18t			Servicepack : Can write xilinx from enover catalog!
4490 --		ServicePack_19			-- : make adding headers for . dpd files. Final for com1.
4491 --		ServicePack_20			Servicepack : send before #ffCJ1. - ste device to protokol1 mode.
4492 090811	ServicePack_21			ServicePack : maked dialog for open programm file. not need using only hello7.
4493 --		_22				-- : can change com port from menu.
4494 --		_23				-- : for dpd files use menu with dpd extensions.
4495 --		_24t				--: maked opening configuration file servicepack.cfg.
4496 --		_25t				--: usen number of comport from configuration file.
4497 090812	hello7_2983			PRM_PCH : changed formula5 + added wd_reset() to command5 to support servicepack.
4498 --		ServicePack_26			ServicePack : keep current comport in configuration file. 	
4499 090813	ServicePack_27			ServicePack : do not change protokol to R2  in device - it can be setted from pult.
4500 090814	AddHeader1			AddHeader : first version programm to adding headers to fpga and dpd files before its writing to flash through 
u-boot.
4501 090815	_2984t_sergey			KTVM,DTVM from sergey	need synchronize with my files.
4502 090819	_2985				PRM_PCH: pack before get to projekt files from sergey.	
4503 090820	_2986				DTVM : compiled after collect files from sergey. added () in If()operators with "=".	
4504 090821	_2987				MF20: compiled witch pragma LOCK_ENABLED version__________________279_______________________
4505 --		_2988				BMD34 : --.
4506 --		_2989				BMD34PS : --.
4507 --		_2990				BMD2: --.
4508 --		_2991				BMD155 : --.
4509 --		_2992				ACT155 : --.
4510 --		_2993				ACT155N : --.
4511 --		_2994				BUKC : --.
4512 --		_2995 				PUM=BUKC: --.
4513 --		_2996				PU_M : --.
4514 --		_2997				PU_M_MUX : --.
4515 --		_2998				MPC34 : --.
4516 --		_2999				MPC155 : --.
4517 --		_3000				BMD35 : --.
4518 --		_3001				MPC35 : --.
4519 090824	_3002				MF20 : start making clocks operating.
4520 090825	_3003				MF20 : next step to make clocks
4521 --		_3004				-- : full maked operating with seconds (can change if get key3.dat) clacks start /stop to key5.
4522 --		_3005				-- : full maked operating with clocks.
4523 090826	JackS104t			JackS : start making set and get time.
4524 --		_105t				-- : maked synchronize seconds with computer time.
4525 --		_106t				-- : added minutes.
4526 --		JackS107			JackS : full maked setting time.
4527 090831  	hello7_3006			MF20 : write to joornal two events : power off and power on.
4528 --		JackS108t			JackS : start making Journal.
4529 090901	hello7_3007			MF20 : more right addresses in init yournal.
4530 090902 	JackS109t			JackS : maked more for journal.
4531 --		JackS110t			--:--.
4532 --		hello7_3008			MF20 : next step to make journal.
4533 --		JackS111			JackS : next step.
4534 090903	hello7_3009			MF20 : remove debug print.
4535 --		JackS112			JackS : print to protokol id , programm version and xilinx version.
4536 --		JackS113			-- : work more quckly.
4537 090904	hello7_3010			MF20 : deleted error in yournal : loss event in maximum address, maked size of journal to 50 records. 
4538 --		JackS114			JackS : maked yournal size 50 events deleted some errors.
4539 090908	hello7_3011			MPC35: make writing time as unix -time.
4540 --		hello7_3012t			PRM_PCH : -- deleted any errors.
4541 --		source7_3012			mqx : --
4542 --		JackS115			JackS : --.
4543 090909	hello7_3013			PRM :PCH : maked writing device id.
4544 --		JackS116			JackS : --.
4545 --		hello7_3014			PRM_PCH : added data of event to yournal.
4546 --		JackS117			JackS : -- and can using all events!
4547 --		hello7_3015			PRM_PCH_C : start version. 
4548 --		_3016				-- : next step.
4549 090910	_3017				-- : maked start1,start2,start3.
4550 --		_3018				-- : correctly address for power port
4551 --		_3019				-- : more right make indikation
4552 --		_3020				-- : not all channels togeder can be get on : at start getted on channel 1; later channel2, later channel3.
4553 --		_3021				-- : use status register forcheck : sending or not commands 
4554 --		_3022				-- : get back to use power port; get off old using port 0x510 as telephone address.
4555 --		_3023				--: added using status register.
4556 --		_3024				-- : make indication alarm_input - whan not have channel.
4557 --		_3025				-- : make many changes. TESTED for two channells! ok
4558 090911	_3026				-- : more right idikation.
4559 --		_3027				-- : try make idikation alarms PM	
4560 --		_3028				-- : where start1 or start2 or start3 - not make some to commands tcp. TESTED ON CHANNEL3.
4561 --		_3029				-- : maked idikating alarm pm if not have answers on using channel.
4562 090912	_3030				-- : if start1 or start2 or start3	answer type of command and zeros.	 tested.	
4563 --		_3033				-- : first time maked formula6.		
4564 090914	_3034				-- : start after holiday
4565 --		_3035				-- : maked checksem using +2to have correct result.
4566 --		_3036				-- : remove interruptwatchdog.
4567 --		_3037				ktvm :maked timer to get off.
4568 --		_3038				PRM_PCH : deleted some errors and getted of roulette.
4569 --		_3039				-- : tru not view channels with power off.
4570 --		_3040				-- : remove technology print.
4571 090915	_3041				-- : changed formula6 and convval.
4572 --		JackS118			JackS : added sound and graphikal resources.
4573 090916	JackS119			-- : can play some!!!!!	
4574 --		JackS120			-- : added property sounds.
4575 --		_3042				PRM_PCH_C : deleted error : in channel1 - do not send code command.
4576 --		_3043				-- : file prm_pch after clearing.
4577 --		_3044				-- : if crc is not correct not use parceUD_1, 2, 3.
4578 --		_3045				-- : maked at start empty15 readings of channel ports.
4579 090917	_3046				-- : in setfreq1, 2, 3 getted out using code_ prm 
4580 --		_3047				-- : maked "testcrc" - creectly celling crc.
4581 090918	_3048				-- : current state of projekt; formula 6 : must be changed.
4582 --		_3049t				YOURNAL : maked command "CT" to can read full RECORD.
4583 --		_3050				PRM_PCH_C : start using formula7.
4584 --		JackS121			JackS : deleted error in setting hours.
4585 --		JackS122t			-- : any step to get records from one command.
4586 --		JackS123			-- : can quick get yournal. need get off some problems with zeros.
4587 090919	_3051				PRM_PCH_C : copy of projekt at start of day.
4588 --		JackS124			JackS : use binary buffer for can receive zeros.
4589 --		JackS125			JackS : any next step to try using zeros.
4590 090921	hello7_3052			PRM_PCH_C : final of holiday?
4591 --		JackS126			JackS : maked succesful reading yournal to full record.	
4592 --		hello7_3053			crecord : maked reading records to command "CT" witch using zeros.
4593 090922	JackS127			Printed data of yournal and changed some sounds.	
4595 --		JackS128			Added picture LOGO3 to dialog.	
4596 --		hello7_3054			PRM_PCH_C : current version with formula7.
4597 --		_3055				-- : version witch formula6.
4598 --		JackS129			JackS : maked printing strings "power on" and "power off".
4599 --		JackS1_User_short_prog_eth_19	JackP : can send restart to locked device and use com files. Need make installer.
4600 090923	installer_JackP1			-- : --.
4601 --		JackS1_User_Short_Eth_27		JackX : --
4602 --		installerJackX_13			-- : --.
4603 --		RemPult19			Rempult : --.
4604 --		installer_rempult_10		-- : --.
4605 --		JackS130			JackS : automatic send key3 in getusartaddress.
4606 --		JackS1_Eth_72			Jack_E : first step to add sounds.
4607 --		JackS1_Eth_73			-- : can play sound chimes.	
4608 090925	JackS1_Eth_74			-- : removed using blocking storage : can find device after sounds.		
4609 --		hello7_3056			-- : last version of projekt.
4610 090928	RemPult_20t			RemPult : added one button - arrow
4611 -		rempult_21			-- : added four buttons with arrows.
4612 091002	hello7_3057			PRM_PCH_C : if channel is off answers of commandsget attribute 0xfe for command2.
4613 --		_3058				-- : maked thi for commans 2,3,7,and 8 _______________ver 280_____________________
4614 091008   	_3059				PROG_PROV : first step.
4615 --		_3060				-- : added some to loading programm and configuration file.
4616 --		_3061				PRM_PCH_S : start version.
4617 --		_3062				-- : next step. >>>>>>>>>>>>>>>bad
4618 091009	_3063				-- : --.
4619 --		_3064				-- : --.
4620 --		_3065				-- : --.
4621 --		_3066				-- : --.
4622 --		_3067				--: --.
4623 --		_3068t				-- : --.
4624 --		_3069				-- : added channel "4"
4625 --		_3070				-- : added 5 and 6.
4626 --		_3071				-- : added command "2".
4627 091012	_3072t				-- : -- full; compiled for debug without interrupts and with print.
4628 --		_3073				-- : work version.
4629 --		_3074				-- : delete some errors.
4630 --		_3075				-- : --.
4631 --		_3076				-- : make some for indikation.
4632 --		_3077				-- : --.
4633 --		_3078				-- : --.
4634 091013	_3079				-- : deleted some debug print.	
4635 --		_3080				-- : corrected pragmas.
4636 --		_3081				-- : corrected progmas and correct indikation.	
4637 --		_3082				-- : maked some.	
4638 091014	_3083t				-- : start adding formula8.	
4639 --		_3084				-- : maked formula8.
4640 --		_3085				PRM_PCH_C(3 lines) : maked formula 8.
4641 091015	_3086				PROV : added two funktions for loading - need see his.
4642 --		_3087				PRM_PCH_C(3 lines) : maked formula 8a
4643 --		_3088				PRM_PCH_S(6 lines) : --.
4644 --		_3089				MPC4E : fish
4645 091016	_3090				PRM_PCH_C(3 lines) : changed formula 8a.
4646 --		_3091				PRM_PCH_S(6 lines) : some repaired in channel 6; power bit in parse ud and in command8.
4647 --		_3092				-- : maked alarm indikation to checked crc.
4648 --		_3093				-- : clearing channells when testing next channel - postavka.
4649 --		RemPult22			RemPult : use all buttons as bitmaps.
4650 091019	_3094				PRM_PCH_S : changed formusa 8a at holiday. - postavka?
4651 091020	_3095				ACT155 = BMD155 deleted error to not get right addresses of ansvers from rs485 to rs232. new nersion ___181____
4652 --		_3096				PRM_PCH_S : maked mask for answer of type of device.
4653 --		_3097				ACT155 : maked witch snmp.
4654 --		_3098				-- : added LOCK_ENABLED
4655 --		_3099				-- : tested have working on rs485 with buk = pum printing data and no printing data.
4656 --		_3100				PRM_PCH_S : maked no_scan_delay 75 -> 3 ms.
4657 --		_3101				-- : maked NO_SCAN_DELAY 1 ms.
4658 --		_3102				-- : changed formula8.
4659 091021	_3103				-- : maked no_scan_delay = 0; roulette_delay = 75
4660 --		_3104				-- : set delays to value "no_scan_delay"  in all points where is changing modescan	
4661 --		_3105				ACT155 : can really work with 485e interface (changed setting addresses). maked version __________282______________	
4662 091022	_3106				BMD155 : --(view ver 281).
4663 --		_3107				BMD34 : --(view ver 281).
4664 --		_3108				BMD2 : --(view ver 281).
4665 --		_3109				BMD35 : --(view ver 281).
4666 --		_3110				PRM_PCH_S : changed formula8.
4667 --		_3111				-- : --.
4668 --		_3112				PU_M : maked local send answers from rs485 and 485e (view ver 281).
4669 --		_3113				PU_M_MUX : -- (view ver 281).
4670 091023 	_3114				PRM_PCH_S : changed formula8.
4671 --		_3115				MPC4E : next step.
4672 --		_3116				-- : getted on m_get_clk1().
4673 --		_3117				PRM_PCH_S : maked resending for channel1.
4674 --		_3118t				-- : any step to make resending.
4675 --		_3119				PRM_PCH_C : make resending.
4676 --		_3120				PRM_PCH_S : --.
4677 --		_3121				-- : maked resend_delay = 5 and scan_delay = 4
4678 --		_3122				PRM_PCH_C : --.
4679 --		_3123t				PRM_PCH_S : maked test for resending packets.
4680 --		_3124				-- : full maked resending packets.
4681 091024 	_3125				PRM_PCH_S : removed "break" from reading channel data and having "is end" Campiled as "debug"
4682 --		_3126				-- : maked in debug mode : need set test mode 0x50 to have test print.
4683 --		_3127t				-- : make no_scan_delay 7 ms - to externally not send commands momentally.; compiled witch debug1 option
4684 --		_3128				-- : compiled witch no _debug1 option make version ____________283_____________
4685 --		_3129				-- : changed operating of attenuator.
4686 091026	_3130				-- : changed formula8  Postavka/ make version ________________284_______________
4687 --		_3131				MPC4E : have 18 MHz on portA4.
4688 --		_3132				-- : maked 48MHz.
4689 --		_3133				-- : ucomment all remote - not hangt -- need check in future.
4690 091027	RemPult23			RemPult : maked picture buttons.
4691 --		installer_rempult11			-- : --.
4692 091028	source_mqx_3134			MQX : deleted error in init serials : quelle_size not setted two times.	
4694 091030         _3134t				Maket : maked test version of prog on test mode 57 send 100 times '1'
4695 091102	_3135t				Maket : maked setting in test mode 0x55 baud rate for usart1 921600 witch oversampling "8" - work!
4696 091103	JackS1_Eth_75			Jack_E : work on computers whu do not yours mac addresses : set to it 0xff.
4697 --		installer_jack_E_21			-- : --.
4698 --		JackS1_user_short_eth_28		JackX : --
4699 --		installer_JackX_14			-- : --.
4700 --		JackS1_user_short_prog _eth_20	JackP:--.
4701 --		installer_JackP_2			-- : --.
4702 091104   	_3136t				PRM_PCH_L (CM): first step to make prm_pch_l.
4703 --		_3137t				-- : next step.
4704 --		_3138t				-- : --.
4705 --		_3139				-- : maked full keep parameters.
4706 --		_3140				-- : maked test and compiled not for maket.
4707 --		_3141				-- : remove some not needed operations for 4 5 6 channels.
4708 --		_3142				PRM_PCH_S (AC) : changed operating of attenuator : only to 30
4709 --		_3143				PRM_PCH_L (CM) : --.
4710 091105	_3144t				PU_M : test version with comparing the ports of xilinx and data in nvram; and are printing data writend in port.
4711 091106	JackS1_Eth_76			Jack_E: use for MAC address random value.
4712 --		_3145				PRM_PCH_L : get off error to not run coomands.		
4713 --		_3146t				PRM_PCH : any step to make delayed answer to commands.
4714 --		_3147t				-- : --.	
4715 --		_3148				PRM_PCH_S : maked version with wait full run command.
4716 --		_3149				PRM_PCH_L : --	
4717 --		_3150				-- : add to answer tupe_run_bad if breakflag is zero make version ____________286____________
4718 --		_3151				PRM_PCH_S : --.
4719 091108	_3152				-- : use some debug prints.
4720 --		_3153				-- : delete error - not correct level in scan mode was not used mask 0xfff.
4721 --		_3154				PRM_PCH_L : --.
4722 --		prm_pch_6			ctcp/ip lient for prm_pch : correctly send command "7"
4723 --		JackS1_User_Short_Eth_29		JackX : use as mac address random value.
4724 --		installerJackX_15			-- : --.
4725 091109	_3155				PRM_PCH_L : changed formula 8.
4726 --		_3156				PRM_PCH_S : --.
4727 --		_3157				-- : get off restoring attenuator value, maked working testmode 50.
4728 --		_3158				PRM_PCH_L : --
4729 --		JackS1_user_short_prog _eth_21	Jack_P : --.
4730 --		installer_jackp_3			-- : --.
4731 --		JackS1_user_short_prog _eth_22	JackP : set key3 before change ip address. 
4732 091110	_3159				PRM_PCH_S : added some GetCode() in roulettes.
4733 --		_3160				-- : if countmod > max value init message to not send it to not working device.
4734 --		_3161				-- : in roulette removed all not used commands.
4735 --		_3162				PRM_PCH_L : --.
4736 --		_3163t				-- : maked checking countmod in time cyckle to not clear not sended message.
4737 --		_3164				PRM_PCH_S : -- for all channels. if power is off one tyme senddee ever message. need set countmod to zero in makingcommands.
4738 --		_3165				PRM_PCH_L : --.
4739 --		prm_pch7			client for prm_pch : make celling answers (can view in debug mode)
4740 --		_3166				PRM_PCH_S : if power is off send  only 5 times command.
4741 --		_3167				PRM_PCH_L : --.
4742 091111	_3168				ACT155 : getted  off my stack on rs485; in ToBufferIP() is checked len - to awoid problems.
4743 --		_3169				-- : maked lock for all! changed version to _________________287___________________
4744 --		installerJackP_4			JackP: send key3 before try change IP.
4745 --		_3170				ACT155 : lock mode key3 get off after restart. before was not so.
4746 --		JackS1_User_Sort_Eth30		JackX : send key3 before try change IP.
4747 --		installer JackX16			-- : --.
4748 --		rempult_24			RemPult : --. it not can set ip back!
4749 --		installer_rempult12			-- : --.
4750 --		_3171				ACT155 : added CRC to rs232 , maked snmp, operating files locked of key3.
4752 --		_3172				-- : added checking crc to modem channel.
4753 --		_3173				-- : added checking crc to transit channel 
4754 --		_3174				-- : get back shutdown socket - not restart if get off rnms.
4755 091112	_3175				ACT155 : deleted error to wrong working transit!!!! maked wer____________288_____ naad make this for 								bmd155.
4756 --		_3176				BMD155 : --.
4757 091113	_3177				PRM_PCH_N : start making.
4758 --		_3178				-- : uncomment using rs485 compiled for maket plata.
4759 --		_3179				PRM_PCH_S : make more right led indikation.
4760 --		_3180				PRM_PCH_N : next step.
4761 --		_3181				-- : --.
4762 --		_3182				-- : --.
4763 --		_3183				-- : --.
4764 091116	_3184				-- : --.
4765 091117	_3195				-- : --.
4766 --		_3196				-- : --.
4767 --		_3197				-- : maked some in debug.
4768 --		_3198				-- : -- view sometine full message.
4769 091118	_3199				-- : have better statistics.
4770	--	_3200				-- : next step.
4771 --		_3201				-- : --.
4772 --		_3202t				PRM_PCH_S : test version with formula8.
4773 --		_3203				PRM_PCH_N : maked some for disable ethernet. 
4774 091119	_3204				-- : maked file prm_pch_n; formula8 - changed for test!!!!!!!
4775 --		_3205				-- : maked more to resize file.
4776 --		_3206				-- : full version.
4777 --		_3207				-- : maked more short file - remove some.
4778 --		_3208				-- : --.
4779 --		_3209				-- : --.
4780 --		_3210				-- : set uart address to answers
4781 --		_3211				-- : added command "23".
4782 --		_3212				-- : go to formulaN from formula8.
4783 --		_3213t				-- : start making freq
4784 --		_3214				-- : maked attenuator
4785 --		_3215				--: maked test print
4786 --		_3216				-- : added testpu_37
4787 --		_3217				-- : for test maked on maket plata printing from rs485
4788  091120	_3218				-- : more correctly check crc.
4789 --		_3219				-- : added command type to command.	
4790 --		_3220				-- : more correctly get answer to command 4.
4791 --		_3221				PRM_PCH_S : changed formula8.
4792 --		_3222				prm_pch_N : return stepatt as is setted and not use makeatt().
4793 091123	_3223				PRM_PCH_S : changed formula8. maked ver_______ 290___________
4794 091123	_3224				PRM_PCH_S : changed formula8. maked ver_______ 291___________
4795 --		_3225t				-- : any step to try make pdc for usart receive.
4796 091124	_3227t				-- : --.
4797 --		_3228t				--: have answers
4798 --		_3229t				-- : have reaktion to every symbol but last three sembols are ib buffer.
4799 091125	_3230t				-- : property print symbols with work with pdc!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
4800 --		_3231t				-- : view start at JackS : but loss symbol if try read register.
4801 --		_3232				PRM_PCH_S : maked delay if changed b[2] 100 ms.
4802 091126	_3233				PRM_PCH_N : maked formula 0.
4803 091127	_3234				-- : have answers from edik.	
4804 --		_3235				-- : remove some not needed.	
4805 --		_3236				-- : changed formula 0.
4806 091130	_3237				-- : --.		
4807 --		_3238				USART : next step to make pdc : need right make timeout interrupt.
4808 --		_3239				PRM_PCH_N : added sending 0xAA in group of commands.
4809 091201	_3240				-- : maked makeAtt() and MaikeAttBack(). + formula 0
4810 --		_3241				PRM_PCH_S : changed formula 8.
4820 --		_3242t				USART : not hangt at start - need make interrupts. 
4821 --		_3243t				-- : next step.
4822 --		_3244t				USART : work JackS!!!!!
4823 --		_3245				PRM_PCH_N : maked command5 and command6.
4824 091202	_3246				-- : changed some in formula0.
4825 --		_3247				--: removed roulette, keep parameters, delay1 setted to zero to work shorter, repaired makeatt.
4826 --		_3248				--: maked test version - start exchange witch edik direct from interrupt.
4827 --		_3249				-- : changed formula0; maked BSP_ALARM_FREQUENCY  (5000) =>  time 200 mkseconds!!!!
4828 091203	_3250				-- : maked task interval 100 mcsec.
4829 --		source_3250			-- : use 100 mcsec for task time
4830 --		_3251				-- : changed formula 0
4831 091204	_3252				PRM_PCH_S : changed formula8.
4832 --		_3253				-- : heve error!!!!.
4833 --		_3254				USART_PDC : need check.
4834 --		_JackS1_eth_77			Jack_E : send key3 when write automatically.
4835 --		installer _jacke_23			-- : --.
4836 --		_3255				PRM_PCH_S : deleted error to not init start1, start2, start3
4837 --		_3256, _3257			PRM_PCH_N : added to cammand 4 rejektor and filtr.
4838 091207	_3258...3261			PRM_PCH_S : changed formula8	
4839 --		_3262				PRM_PCH_N : changed formula0
4840 --		_3263				PRM_PCH_S : changed formula8 -> postavka.
4841 --		_3264				PRM_PCH_L : changed formula8 -> postavka.
4842 --		_3265				PRM_PCH_S : maked delay 40 ms to answer to one packet to tcpip. ____________v 298
4843 --		_3266				PRM_PCH_L :  --.
4844 --		_3267				PRM_PCH_S : maked delay 100 ms to answer to one packet to tcpip. ___________v 299
4845 --		_3268				PRM_PCH_L :  --.
4846 091208	_3269t				USART_PDC : print to int why work.
4847 --		_3270t				-- : work property but ethernet will stopped it!
4848 091209	_3271				PRM_PCH_S : added some to answer 0xfe ver______________v300
4849 --		_3272				PRM_PCH_L : --.
4850 091210	_3273				PRM_PCH_S : changed formula 8.
4851 --		_3274				PRM_PCH_L : --.
4852 091215	_3275				TRY_PDC : keep working variant without pdc.
4853 091216	_3276t				KTVM : maked for sergey function senddatai2c1 - full projekt is your.	
4854 091217	_3277				ACT155:maked checking in isend > len+13; maked init message if counter >270____________v301.
4855 --		_3278				-- : maked back => 13 to work with rnms.
4856 091218	_3279				ACT155: added snmp and maked property  printethstring.	
4857 --		_3280				-- : get off checking crc, make buffer size 1500 -> 900; if len in buffer > size correct len and send to buffer and not return
4858 --		_3281				-- : maked watch dog in rdn_echo_server : to restart modem if this is blocked.
4859 --		_3282				-- : remowed vd from echo_server.
4860 --		_3283				-- : maked enebling reset watch dog in rdn ech server.
4861 --		_3284				-- : make buffers back 1500
4862 --		_3285				-- : remove enabling wd from echo server.
4863 --		_3286				-- : any next step.
4864 --		_3287				-- : remove send symbol 0x55 if receive 0x55 on rs232 ???? need in all devices????
4865 091221	_3288				-- : send echo to rdn olweis  even len is zero.
4866 --		_3289				-- : maked pragma : RS485_NOT_DISABLE_ETHERNET. 
4867 --		_3290t				-- : can loss tcpip connect!!!
4868 --		_3291				-- : remove transEC to trans for modem and transit channels.
4869 --		_3292				-- : make init mesages for modem and transit channels. SENDED FOR USERS!!!!!!!!!!!!!!!!!!!
4870 --		_3293				-- : clear some in answermod.inc _______________________________v 302
4871 --		_3294				-- : maked init of msg485 and msg485e
4872 --		_3295				-- : remove "else" in parse of messages!!!! can view results : view best next modem.
4873 --		_3296				-- : maked bak parsing of addresses by bukc
4874 091222	_3297t				-- : test version; maked from 281 version!!!_________________v303
4875 --		_3298				-- : added yournal, printing at start, send if length = 0 one char 'U' ________________v304 need make parser of lines? and check timer of tcpip
4876 --		_3299				PRM_PCH_N : changed formula0.
4877 --		_3300				act155 : temporary added yournal, printing at start, send if length = 0 one char 'U' , maked back from prm_pch tcp ack delay 40 ms. work night best.
4878 091223	_3301				--: compiled with snmp and without  debug print and yournal.
4879 --		_3302				-- : get back from try making better statistics to write remote_act_15501.inc
4880 --		_3303				-- : rs485 can disable ethernet to not loss PUM on rs485.
4881 091224	_3304				-- : icnge for rbufmsg if to while
4882 --		_3305t				-- : compiled with pragma "all addr" - this was work at night.
4883 --		_3306				-- : without pragme "all_addr".
4884 091225	_3307				tuts : maked delayed answer to 485e; - mere high % of answers.
4885 091228	_3308				ACT15502 : mked ERIAL_ETH_OFF_TIMEOUT_MS  1ms. _________________ver 305____________
4886 --		_3309t				-- : test wersion with all_addr.
4887 091229	_3310				PUM_MUX (PUM155) : deleted error in function ReadPort() - use emmsgrequest->
4888 --		_3311				-- : deleted error in function WritePort() - use emmsgrequest->
4889 100110	_3312				PU_M : --.
4890 --		_3313t				ACT155-01 : maked test version without rs485 with option ETH_TRANSIT : make more good statistics! need make fuul or get back to 3312
4891 100111	_3314t				-- : any step to make rs485. need compare with rs485e and find all using rs485 in previons variant.
4892 --		_3315t				-- : any step.
4893 --		_3316				-- : added adding rs485 to ethtransit channel. need make pragma all_addr
4894 --		_3317				-- : checked near pum with good statistics.
4895 100113	_3318t				-- : compiled with prgma all_addr.
4896 --		_3319				-- : final?
4897 100115	_3320				-- : disable interrupts in void toip. send
4898 100118 	_3321				-- : rs232 and rs485 - not disabled ethernet.
4899 --		_3322				PU_M : have answers in system on rnms maked not setting flagrequest to zero and changed changing addresses
4900 --		_3323t				-- : on this variant modem get to not ping mode!!!!
4901 --		_3324				ACT15501 : rs232 and rs485 - not disabled ethernet _______v307 - tested - not hangt tcpip!!!!!! 
4902 --		_3325				BMD155 : --.
4903 --		_3326				PUM_M_MUX :  have answers in system on rnms maked not setting flagrequest to zero and changed changing 
4904 --		_3327				PUM_M : --.
4905 --		_3328t				PRM_PCH_S : test version, use delay on scan 6ms and print in test mode 5d
4906 --		_3330t 31t,32t				-- : next step of testing
4907 --		_3333				PRM_PCH_S : full maked "isreceived" flags and init received messages after parse.
4908 100121	_3334				PRM_PCH_L : --.
4909 100122	_3335t				PRM_PCH_S : next step of testing
4910 100125	_3336t				-- : --.
4911 --		_3337				ACT15501 : maked can 232 disable ethernet for srevicepack :  support back servicepack 						_____________v308______________
4912 100126	_3338				-- : added snmp and not big delay for tcpip. - postavka
4913 --		_3339				BMD155 :  --
4914 100127	_3340				PRM_PCH_S : set at start command buffer pointer to zero.
4915 --		_3341				PRM_PCH_L : --.
4916 100128	_3342				PRM_PCH_S : changed formula8.
4917 --		_3343				-- : -- : use in formula8 -use in formula band of receiver. _____________v309_______________
4918 --		_3344				-- : next step.
4919 100201	_3345				--: changed formula8.
4920 --		_3346t				maked any tested in future Eth_restart
4921 --		_3347				PRM_PCH_S : changed formula8 right compiled without print.
4922 --		_3348t				next step to maked eth_restart
4923 --		_3349t				restore file work1.
4924 --		_3350				PRM_PCH_S : deleted error in changing formula8.
4925 --		_3351t				-- : rtcs_can restart.
4926 --		_3352, _2253			PRM_PCH_S : deleted error in changing formula8.	
4927 --		_3354				-- : --		
4928 --		_3355				-- : --.
4929 10202	_3356				-- : --.
4930 --		_3357t				tcpip client try connect to gotd server port17.
4931 --		_3358t				any step to make quoteserver
4932 --		_3359t				next step to make quoteserver
4933 100203	_3360t				have connect with pc ip155155155118!
4934 --		_3361t				have connection and closing session from client on test mode 0x5e
4935 --		_3362				PRM_PCH_S : changing formula8.
4936 --		_3363t				send "Hello" from q_client_socket in test mode 0x5e
4937 --		_3364t				send "Hello" with period 400 ms
4938 --		_3365t				PRM_PCH_S : changing formula8.
4939 100204	_3366				version of qserver; need make send and receive.
4940 --		_3367t				qserver maked from ech-server - can view received data!!!!!
4941 --		_3368t				qserver celling quantity of received packets and print it.	
4942 --		_3369t				qclient try send 100000 packets.
4943 --		_3370t				qclient use udp.	
4944 --		_3371t				next step to make udp.	
4945 --		_3372t				can send to udp 100 bytes.	
4946 100205	_3373t				try send 1000 bytes - have packets to 1500 Bytes. 2 ms and 0,5 ms.
4947 --		_3374t				PRM_PCH_S : test version vithout correction.
4948 --		_3375t				udp_client make 180 MHz -> period of transmit is 2ms.
4949 --		_3376t				udp_client : multipleer maked to 48 - have1,6 ms
4950 100208	_3377				prm_pch_n : make direct rs485.
4951 --		_3378				-- : view in testmode 0x50 printing crc - ok for all packets number.
4952 100209	_3379t				prm_pch_n : first step to try make pdc usart1	
4953 --		_3380t				-- : --.
4954 --		_3381t				-- : -- have correct crc!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!		
4955 --		_3382t				-- :maked counter for reading pdc buffer to have 300 mcs betveen reading.
4956 --		_3383t				-- : run in scan mode without bad checksum.!!!!!!!!!!!!!!!!
4957 100210	_3384t				-- : try have transmit on rs485 : go back from pdc, enable tasks. testmode 4 work only for rs232.
4958 --		_3385t				--: make for usart divisor8. have in terminal correct symbols.
4959 --		_3386t				-- : compiled with option pdc in main program and usart file.pdc and test rs485 are working!
4960 --		_3387t				-- : interrupt funktion do not recompiled - rs485 test and pdc work. 
4961 --		_3388t				-- : maked high_rate option. full version ? need only comment message "bad crc". - not - this prin is only in test 						      mode 0x50
4962 --		_3389				prm_pch_n - first version vithout xilinx with usart; need compile for non - maket -plata.
4963 --		_3390				-- : corrected command length : +1 by code of command.
4964 100211	_3391				-- : next step.
4965 --		_3392				-- : --.	
4966 --		_3393				-- : -- try make buffer for pdc in internal memery and go back - somtime hangt!.
4967 100215	_3394				BMDN : any step to make modem.
4968 --		_3395				-- : make empty init and loop and add remote.	
4969 --		_3396				-- : added api.	
4970 --		_3397				-- : can use funtion api_open().
4971 --		_3398				-- : maked init of some constants.
4972 --		_3399				-- : maked timer for any using.
4973 --		_3400				-- : next step.
4974 100216	_3401t				PRM_PCH_N : hangt if get all from timer!
4975 --		_3402				-- : uncomment all in timer - do not hangt.
4976 --		_3403				-- : keep only timer.isrxx to change time1-used in commands!
4977 --		_3404				BMDN : next step. need delete enums.
4978 --		_3405				-- : -- compiled with xilinx and interrupts.
4979 --		_3406				-- : start changing enums.
4980 --		_3407				-- : any step to delete enums
4981 --		_3408				-- : --.
4982 --		_3409				-- : --.
4983 --		_3410				-- : added some writing to xilinx.
4984 --		_3411				-- : remove writing to xilinx.
4985 --		_3412				-- : any step.
4986 100218	_3413				-- : init some	
4987 --		_3414				-- : make some for use xilinx spi.	
4988 --		_3415				-- : next step for spi.	
4989 --		_3416				-- maked read from spi.	
4990 --		_3417				-- maked periodikal sending get version api function.	
4991 --		_3418				-- : next step.	
4992 --		_3419				-- added to prijekt hostprotokolopcodes.h.
4993 --		_3420				-- : are init opcodes.
4994 100224	_3421				--: start make uart - com.	
4995 --		_3422				-- : have test prit to comport	
4996 -- 		_3423				-- : have answer from provingent to usart0 on rate 115200!
4997 --		_3424				-- : answer to rs232 is full valid!
4998 --		_3425				-- : next step.
4999 --		_3426				ACT15501 : make rs485 with pdc. without snmp. - bad!
5000 --		_3427t				-- : make any version before find bug in rs485.	
5001 --		_3428				-- : really work rs485 with pdc.
5002 --		_3429t				-- : try make rs232 with pdc.
5003 --		_3430t				-- : next step to make rs232pdc - do not disable now interropt rxready?
5004 --		_3431				-- : maked pdc for receive rs232.
5005 --		_3432				-- : remove snmp.	
5006 --		_3433				-- : in rdn_server do not shutdown socket if have bad length.	
5007 --		_3434				-- : setted back shutdown - it need!	
5008 100227	_3435t	36t, 37t			-- : steps to try make pdc to transmit usart0 
5009 --		_3438				PRM_PCH_S : start adding new command.
5010 --		_3439				-- : next step.
5011 100301	_3440				-- : make restoring parameters from ram
5012 --		_3441				-- : next step.
5013 --		_3442				-- : make command 10 to command11
5014 --		_3443				ACT15501 : tested  using pdc for transmit - very infrequent irqs
5015 --		_3444				-- : first try make pdc for transmit usart1.
5016 --		_3445				-- : go step back not pdc for transmit for usart0 and usart1 - usart work!
5017 --		_3446				-- : work pdc transmit to rs232 with working rs485.
5018 100302	_3447				-- : work pdc transmit on rs485?
5019 --		_3448				-- : really not have interrupts on rs485.
5020 --		_3449				-- : make low priority for usart0 and irq0.
5021 --		_3450				-- : make watch dog to check of property working tcpip task.
5022 --		_3451				-- : make rs232_not_disable ethernet - with pdc - work.
5023 --		_3452				prm_pch_s : next step to make attsetrpu.
5024 --		_3453				-- : added some to answer to tcp.
5025 --		_3454				--: maked some.
5026 --		_3455				-- : maked property keep parameters
5027 100303	_3456				-- : change level and channels functions.
5028 --		_3457				prm_pch_l : --.
5029 --		_3458				bmdn : in test mode7 - do not send to spi any.
5030 --		_3459				act15501: maked writing every 10 secs to emac_ptr->CR &= ~0x00000004; emac_ptr->CR |= 0x00000004;
5031 100304	_3460				prm_pch_L : changed formula 8 _______v310
5032 --		_3461				prm_pch_S : --
5033 --		_3462				prog_bmdn : any step to make loading config file.
5034 --		_3463t			     	-- : make test version for maket plata	
5035 --		_3464t				-- : can view xilinx data
5036 100305	_3465				-- : have some answers to try loading.
5037 100309  	_3466				-- : any step to try load from usart.
5038 --		_3467				-- : can view version api from usart - get off temporary pdc.
5039 --		_3468				-- : have for usart step 06
5040 --		_3469				-- : any next step.
5041 --		_3470				-- : view answer PVG610_BOOT_OPCODE_UNEXPECTED_E if try load from usart.
5042 100310	_3471				-- : start making device_from_host_reload.
5043 --		_3472				-- : try reload from spi.
5044 --		_3473				prm_pch_s : test version without corrections.
5045 --		_3474				prog_bmdn : make file size 86940 bytes and delay in usart
5046 --		_3475				-- : get error jump addr not alive!
5047 --		_3476				-- : get off print_flag.
5048 100311	_3477				-- : start making command 0xf and dann command 60
5049 --		_3478				-- : add delay to receive data from usart - view any exchange!!!!!! to commanf 0xf
5050 --		_3479				-- : have answer : flash timeout.
5051 --		_3480				-- : print version api
5052 --		_3481				-- : have success answer to write flash.
5053 --		_3482				-- : more sucsess working!
5054 --		_3483t				--: try go to spi.
5055 100315	_3484				-- : load to usart - more better statistics.
5056 --		_3485				-- : make all back.
5057 100316	_3486				ACT15501 : do not check ethernet rate, do not write 04 to enable receive, can in test modes 						0x64 65 - canrestart rtcs, maked back snmp.
5058 --		_3487				prm_pch_l_6 : start making device 2xprm_pch_L
5059 --		_3488				-- : next step.
5060 --		_3489				prm_pch_l_6 : maked as prm_pch_l and in prm_pch_l - maked keeping of six channels 
5061 100317	_3490 				prm_pch_n_1 : start making prm_pch_n_1.
5062 --		_3491				-- : any next step with ssc.
5063 --		_3492				-- : maked some to configure ssc1.
5064 100318	_3493				-- : maked some for add interrupts - can be used for some.
5065 -- 		_3494				-- : any next step.
5066 --		_3495				-- first version for testing on maket
5067 --		_3496				-- : make some on ssc1!!!!!!!!
5068 --		_3497				-- : make low levwel on tf - olwais?
5069 --		_3498				-- : next step.
5070 --		_3499				-- : view property TF sygnal
5071 --		_3500				-- : more short view.
5072 --		_3501				-- : use buffer ssc1.
5073 --		_3502				-- : next step.
5074 --		_3503				-- : can view interrupts.
5075 100322	_3504				-- : start make io pins.
5076 --		_3505 				-- : maked TF pin as IO pin.
5077 --		_3506, 07			--: start using deta from formula0 to sending ssc.
5078 --		_3508				PU__MUX : deleted error to have errors in struct - before rs2 view errors in data channel.
5079 --		_3509				-- : make task time 10 ms.
5080 --		_3510				prm_pch_n_1 : start making receive interrupt.	
5081 --		_3511				-- : view sending 5 bytes
5082 100323	_3512				-- more short impulses on line TF
5083 --		_3513				-- : next step.
5084 --		_3514				-- : have only 5 interrupts - as need!!!!!!!!!
5085 --		_3515				-- :  view any sending 5 bytes : 0x55 .... 0x 59
5086 --		_3516				-- : have printing, what i have receive
5087 --		_3517				-- : make TF pin as IO to it do not work in enover mode without clocks.
5088 --		_3518				-- : do not loss interripts with this settings.
5089 --		_3519				-- : added delay 3 mcs and receive all bytes?
5090 --		_3520				-- : maked pragma TEST_PRM_PCH_1
5091 --		_3521				-- : start work version.
5092 100324	_3522				BMDN : added command DirectLoad - load after restart.
5093 --		_3523	_3524			-- : do not use pdp to send full file.
5094 --		_3525				PUM_MUX : maked reading ports 507 and 508.
5095 100329	_3526				prm_pch_n_1 : start making rs232msgN.
5096 --		_3527				-- : next step.
5097 --		_3528				-- : maked timer.
5098 --		_3529				-- : maked flag.
5099 --		_3530 				-- : maked as work wresion but for this it is == maket plata version(without interrupts, 							without xilinx)
5100 --		_3631 3532			-- : remove some not needed
5101 --		_3533				-- : added testmode 0x67 to can set usart0 baud rate 38400
5102 --		_3534				-- : removed some
5103 --		_3535				-- : --.
5104 --		_3536				-- : --.
5105 100330	_3537				-- : maked stopping going to mode 115200 in command writing data to buffer.
5106 --		_3538				-- : usart0 do not use pdc - work servicepack all.
5107 --		_3539				-- : added function Init_IOs().
5108 --		_3540				-- : maked some.
5109		_3541				-- maked some for protokol.
5110 --		_3542				-- : --.
5111 101031	_3543				--:add formula1.
5112 --		_3544				-- : next step
5113 --		_3545				-- : maked setupr.
5114 --		_3546				-- : maked settattn
5115 --		_3547				-- : --.
5116 --		_3548				-- : changed levels.
5117 --		_3549				-- : make init of attenuators.
5118 --		_3550				-- : next step.
5119 --		_3551				-- : maked some for led.
5120 --		_3552				PRM_PCH_L_6 : maled restoring_ signature_hardware12 and 13 
5121 --		_3553				-- : set hardwere of power if have 1 in variables start1...6
5122 --		_3554				PRM_PCH_N_1 : changed formula1.
5123 --		_3555 3556				-- : --.
5124 --		_3557				--: Maked SetLed2
5125 100402	_3558				-- : maked ports for led.	
5126 --		_3559				PRM_PCH_L_6 : 	TCP_RTO_MIN  ìàêåd 500, 	and receivers types can changed only at start.					
5127 --		_3560				PRM_PCH_N_1 : changed formula1
5128 100405	_3561				BMDN : next try to load.
5129 --		_3562				-- : view on rs232data logger correct data from flash!!! need rewrite data from mdp, write it to flash.
5130 --		_3563				ACT15501 : maken functions restart_eth2, restart_eth_3
5131 --		_3564				-- : maked full programm with xilinx
5132 --		_3565				-- : maked pdc for usart0 and test modec 64 65 68 69 70
5133 --		_3566	3567			PRM_PCH_N_1 : changed formula1
5134 --		_3568				ACT15501: aked pdc for usart0 and test modec 64 65 68 69 70.
5135 --		_3569				PRM_PCH_N_1 : changed formula1
5136 100406	_3570				-- : --.
5137 --		_3571				--: --.
5138 --		_3572				BMDN : for maket plata - send correct file!!!
5139 --		_3573				-- : working version!!!! - have load to test mode 66 programm and can read version in test mode 0x60
5140 --		_3574				ACT15502 : maked pdc for usarts.
5141 --		_3575				PRM_PCH_N_1 : changed formula1
5142 100407	_3576				MPC155 : maked version with my protokol on usart1
5143 --		_3577				BMDN : start making loading firmware to loader
5144 100408	_3578	3579			PRM_PCH_N_1 : changed formula1 , deleted errror in setatt2
5145 --		_3580t				ACT15502 - try find autoneg if loss connect on tcp ip - have debug print
5146 --		_3581 - 3585			PRM_PCH_N_1 : maked leds
5147 --		_3586				-- : inverted led2 and led3 some at start - need check
5148 --		_3587				ACT15502 - try find autoneg if do not receive tcp ip -_____________v312____________
5149 --		_3588				-- : added pdc on usart0.
5150 --		_3589				BMDN : next step
5151 --		_3590				-- : --.
5152 --		_3591				-- : --.
5153 10412	_3592				ACT15502 - try find autoneg.
5154 --		_3593				ACT15501 : --
5155 --		_3594				BMDN : next step.
5156 --		_3595				-- : view correct sending on rate 38400 command with opcode 00. This is starting in test mode 0x75
5157 --		_3596				-- : next step view sending some blucks but have any error at addr 0x181
5158 100413	_3597t				ACT15502 -start making printing in tetsts.
5159 --		_3598				-- : tetst mode4 work!
5160 --		_3599t				-- : maked some for work test 2 and test3.
5161 --		_3600				-- : maked test tlf for pdc.
5162 --		_3601				-- : maked  test2 and test3 full.
5163 --		_3602				-- : maked  test2 and test3 better _______________________v313_________________
5164 --		_3603				ACT15501 : --
5165 --		_3604t				PRM_PCH_L_6 : find types olweis - maked back
5166 100415	_3605, _3606 3607	 3608		BMDN : next step.
5167 --		_3609				-- : send file of 90 k!!!!!! in test mode 0x5f
5168 --		_3610t				PRM_PCH_N_1 : half of making command 0x80.
5169 --		_3611				-- : full maked command 0x80.
5170 --		_3612				BMDN : version not for maket.
5171 --		_3613				-- : not High Rate.
5172 --		_3614				-- : maked work directload - test mode 0x66 and reading version - test mode 0x60
5173 --		_3615				-- : in mode 0x5f - maked success loading first tail - second loader / this is maked in 						pragma TEST_BMDN to return after short size;  con in test mode 0x60 read version!!! this is working with file pvg610.fw!!!!!!!!

5174 100419	_3616				-- : nexst step for testing - retern before build send and receive
5175 --		_3617				-- : next step - init counter for commands
5176 --		_3618t				-- : make for test length 10000 - need check
5177 --		_3619				PRM_PCH_N_1 : changed f1
5178 --		_3620				-- : maked cyckle 150 mcs.
5179 --		_3621				-- : maked starting delay 4 periods after parse command
5180 --		_3622				BMDN : can printf somthing
5181 --		_3623t				-- : print all.
5182 --		_3624t				-- : enabling sending data to device
5183 --		_3625				-- : next step.
5184 --		_3626				-- : full loaded pvg610.fv to command 0x5f. If try read version api - have ver 030316!!!!!!!!!!!!!!!!! Need move all to dir current!!!!
5185 --		_3627				-- : make common projekt for bmdn and enover.
5186 100421	_3628 				PRM_PCH_N_1 : changed f1
5187 --		_3629t				BMDN : first step to make spi can to spi read version api!!!!
5188 100422	_3630t				-- : sucssesfully load loader 892 to spi? - need check! Was maked test mode 5f; 77;60
5189 --		_3631t				-- : load second loader to spi without printing every symbol to usart maked return from step 6 and delays. 1 and 3 sec	
5190 --		_3632t				-- success reun comand witch length 0103!!!!!		
5191 --		_3633t				-- load full file to spi!!!! can set 77 and set 60  - 0b 35 and set 60 - have version of prog!!!!
5192 --		_3634				-- : can view version of programm to commands to spi
5193 100427	_3635				-- : maked common directorii.
5194 --		_3636				-- : start making loading config file
5195 --		_3637				-- : next step. 
5196 100428	_3638	_3639			PRM_PCH_L6 : changed formula8 ______________v314
5197 --		_3640	_3640			BMDN : maked command config get
5198 100429	_3641				-- : really view readed  config file in Hyperterminal.
5199 --		_3642				-- : maked command run cfg file work lock!!!!!!!
5200 --		_3643				-- : can read modem status.!!!!!
5201 --		_3644				-- : added reading AcmCounters
5202 100430	_3645				-- : ModemAcquireCountersGet
5203 --		_3646				-- : maked loading automatically.
5204 --		_3647				-- : maked feccounter
5205 --		_3648				-- : start making mailboxes.
5206 100504	_3649t				-- : any next step
5207 --		_3650				-- : added some opcodes !!!!! mailbox work!!!!!
5208 100505	_3651				-- : maked test mailboxes.
5209 --		_3652				-- : next step.
5210 --		_3653				-- : sended mailboxes = received mailboxes.
5211 --		_3654				-- : next step
5212 --		_3655				-- : --.
5213 --		_3656				-- : --
5214 --		_3657t				-- :  make timeout 5ms from 1000ms
5215 --		_3658				-- : work more quckly.
5216 --		_3659				-- 100 bytes/sec 3e-3 losses
5217 --		_3660				-- : not loss pacets!!!! 1000  - 994; 25000 - 24994!!!!!!!
5218 100507	_3661				-- : do not print error b but have many errors - maked writing at read 0x7e!!!!!!!	
5219 --		_3662				--: next step.
5220 100510	_3663				-- : point for start
5221 --		_3664				-- : next step.	
5222 --		_3665				-- : start making class modem.	
5223 100512	_3666	_3667	_3668		-- : next step.
5224 --		_3669				-- : remove eth_debug
5225 100513	_3670	_3671	_3672 _3673	-- : any step to make many modems. 
5226 100514	_3674t				-- : fix this point. do not work from file 3668!!!
5227 --		_3675	_3676	77	 78 	-- : start point for restore
5228 --		_3679	_3679			-- : compiled without eth_debug - work!!
5229 --		_3680				-- : added hello7.h and bmdn.cpp from 3674 do NOT work!
5230 100517	_3681				-- : only hello7.h - work!
5231 --		_3682				-- : added api and driver files from 3674 - work!
5232 --		_3683				-- : maked all without pragma many_modems - work!!!!
5234 --		_3684				-- : test - use write and read for one modem.
5235 --		_3685				-- : use readspibm
5236 --		_3686				-- : deleted error at parameters using in calling writespibm
5237 --		_3687				-- : use real writespibm and readspibm
5238 --		_3688				-- : imitate 8 modems
5239 --		_3689				-- : work more shortly!
5240 --		_3690				--: next step
5241 --		_3691				--: 6 errors to 100000
5242 --		_3692				-- : 12errors to 80000
5243 --		_3693				-- : 13 errors to 90000
5244 --		_3694				-- : 26 errors to 140000 fery fast good probability!!!!
5245 --		_3695				-- :  next step.
5246 --		_3696				-- : if make timeout 20 ms 30000 - 5 bad
5247 --		_3697				-- : more fast timeout = 2 ms.
5248 --		_3698				-- : start making loops.
5249 100521	_3699				-- : wopk setting modem digital loop.
5250 --		_3700				PU_M_MUX(PUM155): compiled v 314 for sending
5251 --		_3701				-- : maked restart device if do not receive some at tcpip - if have link
5251 100524	_3702				ACT15501 : in tcp sending check length to little as 1460 (it can be theoretic 1501) 
5252 --		_3703				-- : compiled with pragma dev_eth_can_restart   _____________v316_________________________
5253 100526	_3704				-- : added Check_MAC_BNA	
5254 --		_3705				bmdn : added alarms get and set funktions.	
5255 100527	_3706				-- : maked reading errors for one channel
5256 --		_3707				-- : next step to make reading errors.
5257 --		_3708				-- : maked more correctly setting loop
5258 100528	_3709				-- : stàrt making objekt configfile.
5259 --		_3710				-- : next step to making config file
5260 --		_3711				-- : this variant hangt to tcpip if i try set confir 2 or 3 to snmp!!!!!!!
5261 --		_3712				-- : -- next step of hangt!!!!
5261 --		_3713t				-- : make back leds, enabled restart device if hangt tcpip - work!!!!! maked printing counter. Need try make enover voys to reuse tcpip.
5262 100531	_3714t				-- : can restart counter but ethernet do not work.
5263 100601	_3715				ACT15501 : correctly maked dev_eth can_restart
5264 100602	_3716				PU_M_MUX : maked variable "rnms_was_used".
5265 --		_3717				-- : added tests supported pdc for usarts
5266 --		_3718t				-- : any stap to make rs-125
5267 --		_3719t				--:--.
5268 --		_3720t				--: --.
5269 --		_3721, _3722			-- : next step to use usart2
5270 --		_3723t	_3724			-- : --
5271 --		_3725				-- : next step to make rs125
5272 --		_3726t				-- : for debug on maket plata comment using irq3 pin as irq tuo use it for usart2
5273 --		_3727 28				-- : any next step.
5274 100607	_3729				-- : --.
5275 --		_3730				-- : --.
5276 --		_3731				-- : --.
5277 --		_3732t				-- : --.
5278 --		_3733				BMDN : maked return from main loop
5279 100608 	_3734	_3735 	_3736	_3737	PU_M : next step.
5280 --		_3738				BMDN : any step to make testing error of task
5281 100609	_3739				BMDN : make usart0 rate38400 and load syntezeur from file
5282 --		_3740				ACT15501 : make hot restart _____v317______________________________send!
5283 --		_3741				BMDN : maked loading syntesers.
5284 --		_3742				BMDN1: start making full device n+1.
5285 --		_3743				-- : next step to load syntezers.
5286 100611	_3744 _3745			-- : --.
5287 		_3746				--: succssfully loaded syntezers.
5288 100615	_3747t				-- : for maket plata - make getting pdc off for pragma prog_bmdn1 
5289 --		_3748				-- : for real plata work automatic loading syntesers.
5290 --		_3749				-- : any step to load modems.
5291 --		_3750				-- : next step.
5292 --		_3751				-- : --.
5293 --		_3752				-- : dlete delays from spi exchange and try load modems.
5294 --		_3753				-- : print results of first funktion.
5295 100616	_3754				-- : make more correct readspibm
5296 --		_3755t				--: maket plata - deleted error to not init struct for provingents 9 -15
5297 --		_3756t				-- : make correct addresses for ereads pi and write spi  for devices 0 - 15
5298 --		_3757t				-- : more correct addresses
5299 --		_3758t	59t			-- : --.
5300 --		_3760	61			-- : next step
5301 100617	_3762				PRM_PCH_N_2 : statrt compiled point.
5302 --		_3763 64	65 66 67			-- : next step. 67 - view clk and data cs is olweis in zero
5303 --		_3768t				-- : compiled for maket plata and can view working cs1 on maket plata!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
5304		_3769t	70t			-- : comment init -cs works on work plata 70t - full
5305		_3771				-- : send right data
5306 100618	_3772				-- : start making formula2
5307 --		_3773				-- : finished formula2
5308 --		_3774				-- : corrected operating lines a4 changed to a16
5309 --		_3775t				-- : maket, start making synt deleted any error in data in loading dds
5310 --		_3776t				-- : next step to making loading synt
5311 --		_3777	_78 _79			-- : first version operating dds to set freq
5312 --		_3780				-- : maked setfrq 0 and 0 at start of device.
5313 --		_3781				-- : maked freq = 2000
5314 --		_3782				-- : compiled with pragma: set need write devid
5315 100621	_3783				-- : make delay 1,5 sec to writing freq to flash
5316 --		_3784	85 86 87	88		BMDN1 : make option SYNT_100MHZ	 next step
5317 100622	_3789				-- : at this version loading is succesful!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
5318 --		_3790 91	92 93			-- : next step need make more right reset synts and loading modems if is setted plata in hot mode.
5314 --		_3794p				PRM_PCH_N_2 : changing loading dds : maked in enover directory - changed prm_pch_n_2 
5315 --		_3795	96 			BMDN1 : 	start making loading concrette modem	
5316 --		_3797				-- : work : if is setted modem - it is be loaded need make keep configfiles number for every provingent!!!! 256 	5317 100623	_3798	99			--: any step variants of configfiles - Max	
5317 --		_3800				-- : maked obyekts for 16 provingents for its config file
5318 --		_3801				-- :  maked control the number of the config file
5319 --		_3802				-- : make testmode 0x8b
5320 100624	_3803				PRM_PCH_N_2 : maked get off led3 in funktion operatedds
5321 100625	_3804				maket prm_pch_n_2 : maked debug print to rs232!!!!!
5322 --		_3805t				-- : can keep freq in memory
5323 --		_3806t				-- : frequency can be changed!!!
5324 --		_3807				PRM_PCH_N_2 : changing freq on dds - work!!!
5325 --		_3808				--: changed formula 8.
5326 100626	_3809				-- : getting iff init ssc1 and maked init pins port a and port b.
5327 --		_3810				-- : changed formula8
5328 --		_3811				-- : --
5329 --		_3812				-- : --
5330 100628	_3813				-- : start new day.
5331 --		_3814t				maket - find error to writing without delay + changed f8
5332 --		_3815				PRM_PCH_N_2 : maked delay before writing to flash and changed formula8.
5333 --		_3816t				BMDN1 : start making loading config files for modems.
5334 --		_3817				-- : maked any for loading config files. Tested - ok!!!!!
5335 100702	_3818				-- : maked start address for cfg files 0xc0210000, use files 13k, between files 1k start next prov file point 6500
6336 --		_3819				-- : adderess 0xc02200000
6337 100705	_3820				BMD155 : compiled version to replace ver 308 : it have losses of far modem. 
6338 --		_3821t 22t 23t			PRM_PCH_L_61 : first step to make commands 30 and 31
6339 100706	_3824	_25	_26		-- : added command 30 full 31 full		
6340 --		_3827				BMDN1: more correctly loaded synteser. work stm. commented scanmodems	
6341 --		_3828t	29t	30		PRM_PCH_L_61 :  maked command 32 : getatt
6342 --		_3831t				-- : maled att in formula9 - test values.
6343 100707	_3832tt				-- : + maked test answers to commands 30, 31,32
6344 --		_3833				BMD155 : maked in mod_rem.inc rs485 to end _______________________-v318_______________
6345 --		_3834				ACT15501 : --
6346 --		_3835				PRM_PCH_L_61 : changed answers to commands 31 and 32
6347 --		_3836t				BMD155 : added to cache : isRS485
6348 --		_3837				-- : maked --.
6349 100708	_3838				--  added snmp ________________v319__________________________________
6350 --		_3839				ACT15501 : --
6351 --		_3840				ACT15502 : --.
6352 --		_3841				BMD35 : --.
6353 --		_3842t				BMDN1: start making loading syntesers from flash
6354 --		_3843t	_44t			PRM_PCH_L_61 : start making commands 12 13 14
6355 --		_3845	_46 _47	_48		-- : full maked command 14 12, 13
6356 100709	_3849				BMDN1 : next step
6357 --		_3850				PRM_PCH_L61 : removed pdp for usart0 to can printing exchange with edik.
5358 --		_3851				BMD35: maked tests print by pdc
5359 100726	_3852				PRM_PCH_L61 : packed as is after holiday. 
5360 --		_3853				BMDN1 : maked right address for synt data in config file
5370 --		_3854	55  56			--: next step.
5371 --		_3857	58 59			ACT15501 : start making buffer for rs485 transmit messages.
5372 --		_3860				--:  __________________---v326 : buffer  and timeout for transmit rs485
5373 --		_3861				BMD155 : --.
5374 100727	_3862				PU_M_MUX : --.
5375	--	_3863				PU_M : --.
5376 100728	_3864				BMDN1: step back  - use loadsyntm -firmware is loaded!
5377 --		_3865t				PRM_PCH_L61 :test - without corrections . 
5378 --		_3866	67			BMDN1: load config file!!!!!!!!! and run config file!!!!!! variant is setted as 0
5379 100729	_3868	69 70 71			-- : pointer of synt data is setted right, if write to synt add offset
5380 100730	_3872				PRM_PCH_L61 : changed formula9.__________________________v327
5381 --		_3873	74 7576	77		BMDN1: next step (maket plata)
5382 100802	_3878				PRM_PCH_L61 : changed formula9.
5383 --		_3879				BMDN1 : correctly readed  version by config file.
5384 --		_3880t				-- : start config file from remote diffirent for every modem
5385 100804	_3881				-- : maked for really modem.
5386 --		_3882				PRM_PCH_L61 : changed formula9. ____________________v328 
5387 --		_3883				BMDN1 : really is loaded config file for second provingent on modem individually.
5388 --		_3884				-- : full maked lright loading second provingent
5389 100805	_3885				PRM_PCH_L61 : changed formula9. ____________________v331
5390 1--8-6	_3886				BMDN1 : support flag FILE_WRITE_OK - used for JackC
5391 100809	_3887				start making next steps for bmdn
5392 100810	_3888 89 90			--:
5393 --		_3892				PRM_PCH_L61 : changed formula9. ____________________v332
5394 100819	_3893t				rtcs : can destroy tcpip tasks
5395 100823	_3894t				-- : can start tasks but it are do not work
5396 100824	_3895t				ACT155N: maket deleted error to disabling rs485 as incorrect timer
5397 100824	_3896				-- : -- ____________________________---v333
5398 100825	_3898				--: not using disabling rs485 if have pdc on usart1 _____________v334
5399 100830	_3899	900 901	902		BMDN1 : start making modem channel
5400 100901	_3903	04			-- : start moking modforss.
5401 100902	_3905	_06	07 08 09	10 11 12	-- : next step in reading errors. need init stuct statepump
5402 100906	_3912	_13			-- :--
5403 100907	_3914				BMD35 : maked delaybuffer for rs485
5404 --		_3915				BMD34 : --.
5405 --		_3916				BMD2 : --.
5406 100908	_3917				tcpip : can read status and set status
5407 --		_3918				PRM_PCH_L61 : changed formula9.
5408 100909	_3919t				PU_M - test : disabled interrupts and ready.
5409 --		_3920t				--: only interrupts are disabled
5410 100909	_3921t				PUM: maked xilinx size 350k
5411 --		_3922t				PUM100 : first projekt for pum100; for test interrupts are disabled.
5412 --		_3923t				tcpip : changing task error state do not get something.
5413 --		_3924				-- : next step
5414 100915 	_3925				PRM_PCH_L61 : disabling keep parameters and using dalay in answer where long timeout when keys lockad - 							need make after. ________________________v335
5415 100916	_3926				-- : maked LONG_RUN_TIME for keys. 
5416 --		_3927				-- : maked delayed writing________________v337
5417 100917	_3928t				 tcpip : after restart two times maked interript to receive 
5417 100920	_3929t				 tcpip : after restart two times maked interript to receive 
5418 100921	_3930				PRM_PCH_L61 : changed formula9 ___________v338
5419 --		_3931t	_3932t			bmdn1 : start making test mode 0x8e : restart only rtcs
5420 100922	_3933t	_3934t	_3935t	36t	-- : -- : start making writing to xilinx flash
5421 100923	_3937				PRM_PCH_L61 : changed formula9 ___________v339
5422 --		_3938t	39t 40t	41t	42t	bmdn1 : -- : start making writing to xilinx flash
5423 100927	_3943t				-- : with empty loop.
5424 100928	_3944t				-- : start making reading 
5425 --		_3945t	46t 47t			-- : making classes for read config need finish for all plats.
5426 100929	_3948	49			-- : --.
5427 100930	_3950	51 52 53			-- : start making loading config data. - view setted mode in config file for  modem number 7 (0....7)
5428 101001	_3954t				--: for maket - maked config file size 15k
5429 --		_3955				-- : maked 15 k config files empty loop wor work modem	
5430 --		_3956				PRM_PCH changed form 9 - moved to include file ____________________v340__________________ 
5431 --		_3957t				PU_M_MUX : test version without nwait
5432 --		_3958				-- :NOT!!!!! work version xilinx size 350k
5433 --		_3959t				-- : first step maked from version 314 to changing hello7.h - work!!!!	
5434 --		_3960t				-- : not hangt if do not use pdc on usart2 and rs125	
5435 101004	_3961				-- : commentet using pdc on usart2 andexchange with rs125	 ________v341_______________	
5436 --		_3962t				-- : for maket plata try add init : enableTxPdcUsart2(); - need uncomment pdcusart2; using rs125 and view : hangt or not
5437 101005	_3963				BMDN1: maked provingent files size 40k
5438 --		_3964				-- : maked files size 7261 and synt freq 100 MHz
5439 --		_3965				-- : maked back 200 Mhz for synt, for internal parameter and for config file. files : w.bin;  synt1 txt; cfgfile0_100159size7301_200 FILE is loaded and work!!!!
5440 --		_3966				-- : try 104 MHz use size of file!!!
5441 --		_3967 68 69			-- : make view in structs state of modems.
5442 --		_3970				PRM_PCH_N2 : changed formula2.
5443 101008	_3971				BMDN1 : removed xil_flash
5444 101011	_3972t				BMD35 : fer test test of tlf maked without pdc - work!!!!
5445	--	_3973				-- : work telephone test _____v343___________
5446	--	_3974	75 76 77 78 79 80		BMDN1 : start making remote structs.
5447 101012	_3981	82			BMDN1 : make some counters and added request of accuirestats.
5448 --		_3983				-- : maked full reloading in changing config file; - need add init structs.
5449 101013	_3984t 85t 86t			-- : start making 9 modems (pragma N_MOD)
5450 101014	_3987	88			-- : maked 9 modems!!!! tested!!!	
5451 101015	_3989				-- : maked return from loadSyt if do not answer
5452 --		_3990				-- : maked 1/2 returns from messagesend.
5453 --		_3991				-- : full maked returns if return from spi to timeout.
5454 --		_3992				-- : maked some to read steps for filesstep  from files need compare its to zero and if not zero use to loading files
5455 101018	_3993	94, 95  96 97 98		-- : start making reading file size and provingent step
5456 --		_3999	_4000			-- : work wersion
5457 --		_4001				-- :  deleted error of bad reading configfiledata
5458 101020	_4002				-- : start making mode a5
5459 101020	_4003				-- : next step
5460 101021	_4004	4005			-- : temporary disable scen modems and restart by loss tcpip
5460 --		_4006	_4007	_4008		-- : try send some to modem channel.
5461 --		_4009				-- : start making modem prioritys
5462 101022	_4010				-- : make sending tcpip data to my commands protokol _________v344________
5463 --		_4011				PU_M : do not use pdc on usart2 - need check this pdc for rs125
5464 101025	_4012				PRM_PCH_L61 : prm_pch - changed formula8.
5465 --		_4013	4014 4015		BMDN1 : next step.
5466 101026	_4016				BMDN1 : maked class StatRez.
5467 101026	_4017				-- : maked init of class statistics
5468 --		_4018				-- : repaired loading synts : make more lines and having last symbol
5469 --		_4019				-- : any step to use noises to rezerv
5470 --		_4020				-- : maked more short delays to operating spi
5471 101027	_4021				-- : removed some delays
5472 --		_4022				PRM_PCH_L61 : prm_pch - changed formula9.
5473 101027	_4023	24t 25			BMDN1 : next step to use priority
5474 101028	_4026	27			-- : maked good restart if have bad tcpip
5475 101029	_4028	29 30			PRM_PCH_N2 : changed formula2.
5476 101101	_4031t				BMDN1 : next step make opreating rezerv
5477 101102	_4032				PRM_PCH_L61 : prm_pch - changed formula9. ___v346_____
5478 101108	_4033t				PU_M_V : first step to make pu_M_V.
5479 --		_4034t				-- : next step
5480 --		_4035t				-- : --.
5481 --		_4036				-- : work version.
5482 --		_4037	_38			PRM_PCH_L61 : maked command 0x21; test_shift_mode; and changed f9 ___v347___
5483 101109	_4039				PU_M_V : added commands 0x49 0x4a 0x4b
5484 --		_4040				-- : start making command	4c
5485 --		_4041	42 43 44	45 46 47	48 49 50	51  52 -- : maked keeping in flash structure of requested devices on rs485
5486 --		_4053				-- : first release.
5487 --		_4054	55			-- : maked test function settestconfig called to teastmode 0x8f - have answers!!!!!!
5488 101110	_4056ttt				tcpip : from test directories : can view that word is changed
5489 101111	_4057				PU_M_V : removed debug print and maked more high delay between requests
5490 --		_4058				-- : maked full himself pragmas for pu_M_V
5491 --		_4059				-- : make print totestmode 50 io data and print if restart to tcpip
5492 --		_4060				-- : --
5493 --		_4061	62			PRM_PCH_DEM : first step to make demodulator next step
5494 101112	_4063				-- : compiled without pragme prm_pch.
5495 --		_4064t	65 66 67 68t 69 70t	 71t 72t 73t	-- : maked for maket plata - not hangt.
5496 --		_4074 - is try load one synteser.
5497 --		_4075				-- : stted to zero two cs-s
5498 101113	_4076				--: clear some in init 
5499 101113	_4077	78 79	80 81 82		--: start making default values of variables and keep to flash
5500 --		_4083	84 85			-- : dds loaded!!!!
5501 --		_4086	87 88			-- : start making loaddds3 try load xilinx
5502 101115	_4089t				PU_M_V : go more more back to find working tranzit channel
5503 --		_4090t				-- : compiled with pragma _MUX : will have mux!!!!
5504 --		_4091				PRM_PCH_DEM : maked xilinx size 550 K - xilinx is loaded.
5505 --		_4092t				PU_M_V : if write pragma PU_M_MUX in start of file pu_m_v.cpp and add old remot - then can view correctly muxes!!! and have tranzit!!!!
5506 --		_4093t				-- : make using  checkremotemodv.inc and answerpumv.inc
5507 --		_4094t				-- : added to remote working with rs485
5508 --		_4095				-- : added commands 49 ...4b to answerpumv.inc
5509 --		_4096				-- : removed rs485e _______________v348_______________
5510 --		_4097				PRM_PCH_DEM : changed init of ddses
5511 --		_4098				BMD_35 : make writing protokol to xilinx port 4 new / old   1/0 to correct setting tranzit
5512 --		_4099	5000			PRM_PCH_L61 :  changed f9 ___v349___
5513 --		_5001				PU_M_V : changed some in remote commands
5514 --		_5002	5001			PRM_PCH_L61 :  changed f9 ___v350___
5515 101116	5003				-- : --
5516 --		5004				PRM_PCH_DEM : maked init of ddses before loading xilinxes
5517 --		5005				PU_M_V : maked test print for channel up -down		
5518 --		5006				PUM : --
5519 --		5007				PRM_PCH_L61 : test version without corrections  ___v351___
5520 101117	5008				PU_M_V : do not keep in flash lockmode _______v352___________	
5521 --		5009				-- : -- do not restart if hangt tcpip _________v353____________
5522 --		5010				PRM_PCH_DEM : maked upper symbolrate 200 Msymbols
5523 --		5011				PU_M_V : in udevconfig are changed addr and type_________v354
5524 --		5012				PU_M_V : keep 34 ubeconfig bytes _________v355
5525 101118	5013t 14  15			PRM_PCH_DEM : start making io pins.
5526 --		_16t				-- : maked funktion m_load_xilinx4().
5527 --		5017				-- : maked multipling symbol rate to 4 and getting back limit 50 MHz
5528 101119	5018				-- : maked periodikal scan state and keep in bit 0 of ssoftw9 lock and in bit 1 freq
5529 --		5019				-- : getted on print to can view modulation
5530 101122	5020	21			PRM_PCH_DEM_XIL : start version, can reading xilinx versions
5531 --		5022t				PRM_PCH_L61 : test version without corrections  ___v356___
5532 --		5023 24	25 26 27 28 29		PRM_PCH_DEM_XIL : next step
5533 101123	5030t				test tcpip : restart without hanging
5534 --		5031t				-- : starting reload in test mode 70
5535 --		5032				PRM_PCH_DEM : remove print from loadmosk - do not hangt
5536 --		5033				PRM_PCH_DEM_XIL : --.
5537 101124	5034t				test tcpip : !!!!!!!can view to hangt rtcs after clearing hash registers!!!!!!!!!!!!!! in enet initialize!!!!!
5538 --		5035				PRM_PCH_N_2 : maked answers  to attenuators not zero.
5539 101125	5036t				test tcpip : next step to reinit enet
5540 --		5037t				-- : maked buffers for udp pakets rceive and answer
5541 --		5038t				-- : have test answer
5542 101126	5039t				-- : have answer to port 10000
5543 --		5040t				-- : make first two lines of answer
5544 --		5041				PRM_PCH_L61 :  changed f9 ___v357___
5545 --		5042t				tcpip : get full test answe to udp request. request do not parsed
5546 101129	5043				PRM_PCH_L61 :  changed f9 ___v360___
5547 --		5044				-- : maked udp ansver id and soft ver ____v361_________
5548 101130	5045t				testtcpip : correct answer version to udp request
5549 --		5046t				PRM_PCH_DEM_XIL : support read data and programming xilinx4.
5550 --		5047t				-- : more repaired work1.
5551 --		5048t				-- : maked test filldata
5552 --		5049t				-- correctly work fillxilfiledata
5553 --		5050				-- : compiled for non-maket variant
5554 101201	5051				PRM_PCH_L61 :  changed f9 ___v362___
5555 101201	5052t				PRM_PCH_N_2 : start making usart2.#define USE_USART2
5556 --		5053t				-- : if comment pragma  #define DISABLE_ETHERNET can debug prm_pch_n_2 with ethernet without ios
5557 101202	5054t 55t 56t			-- : maked some for usart2.
5558 101202	5057				PRM_PCH_DEM : change loading dds
5559 --		5058t				PRM_PCH_N_2 : deleted error in using transmit buffers of usart2
5560 --		5059				PRM_PCH_N_2 : maked with USART2 and work tak time
5561 101203	5060				PRM_PCH_DEM : changed init of dds-es - tested -ok.
5562 --		5061				PRM_PCH_DEM_XIL : compiled with new init - tested - ok
5563 --		5062				PU_M_V : maked priod request edik 40 ms and chaneged channels from one timer
5564 --		5063				-- : test version - use counters of receive up down channel errors.
5565 101206	5064t				-- : test version  - request of Edig every 6 ms
5566 --		5065t				-- : -- maked printing counters  
5567 --		5066				PRM_PCH_DEM_XIL : compiled with new init and base freq	
5568 --		5067t				tcpip : next try not hangt if set testmode70 hangt if have before block	tcpip	
5569 101207	5068t				-- : any step max maked not loss tcpip if set test mode 70 in normal state can try rtcs_create 	
5570 --		5069t				-- : after hangeng tcp can restart!!!!! half - work
5571 --		5070t				-- : for restart rtcs used old address
5572 --		5071t				-- : if use task_destroy - have only one tcpiptask after restart - but handle is changed
5573 101208	5072tst				PRM_PCH_L61 : test version without
5574 --		5073t	74t	75t    76t		tcpip : keep pool id keep socket go to debug tcpip task;  msg counter is going
5575 --		5077t				tcpip : if init snmp and rdn_server - have full work!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! need try destroy 						snmp rdn_server and enover before new init to loss minimum memory and try check tcpip to state - unhandled interrupt as example
5576 --		5078t				-- : destroy all tsks before reinit - can restart 30 times before hanging and watch dog restart
5577 101209	5079t				PU_M_V - test 1 ms request period
5578 --		5080				-- : disable interrupts in addmodem addtransit addpum1 addpum2 
5579 101210	5081				PU_M_V : make for irq0 - lowest interrupt
5580 --		5082				-- : maked to function fullsize return length zero if length is bigger as 256
5583 --		5083				-- : maked init embmsgwest and embmsgeast - do not resend message many times!!!!!!! - need make this in all 							devices!!!!!!!!!!!!!!!!!!!!!!!!!!!__________________v363____________________
5584 --		5084				PU_M : --.
5585 --		5085				PU_M_MUX : --
5586 --		5086				PU_M_100 : --
5587 --		5087				BMD35: --
5588 --		5088				BMD34 : --
5589 --		5089				BMD2 : --
5590 --		5090				MPC35 : --.
5591 --		5091				BMD155 : --
5592 --		5092				ACT15501 --
5593 --		5093				ACT155n:--
5594 101212	5094				PUM_V : add check crc of modem and tranzit channels  - do not go!!!!
5595 --		5095t				BMDN2 : start version to  modem bmdn2.
5596 --		5096t				-- :  maked writespibm for new addr space
5597 --		5097t				-- : readspibm
5598 --		5098				-- : maked reset funktions.
5599 --		5099t	100 101			PUM_V : test!!!!!!!!!!!!!!! changed 1 and 2 channels in struct staterrl -for test changed back, make 
5600 101214	5102				-- : make counter of answers to end of message.
5601 --		5103				-- : finish find error of "not have rezerv"
5602 101215	5104t				tcpip : temporary comment in hello c many try unblock to do not hangt
5603 --		5105t				-- : maked getting off PDC for bmdn2 - do not hangt
5604 --		5106				-- : work using mem_free
5605 --		5107t				-- : use keephandle for do not reallocate memory for ipif. why ihandle is changed?
5606 --		5108t				-- : if do not restart tftp server it work after reload rtcs
5607 101216	5109t				-- : maked back rtcsifadd1 
5608 --		5110t				-- : this version do not hangt 
5609 101217	5111t				-- : ant try using task state unhandled_int - but kan view that tcpip do not work but state is ok!!!
5610 --		5112t				-- : without RTCS_if_add1 - do not hangt!!!!!! one restart loss 3k
5611 --		5113t	5114t			-- : do not hangt with rtcs_add1 rtcs_bdd1 need use enaver tcpip1 task for restart to kan free used before memory blocks need make tcpip without time and hier can wiev errors
5612 --		5115				 PUM_V: celling errors updown _____---v365_________
5613 101220	5116				tcpip : use msg_cleanup to try do not loss memory
5614 --		5117t				-- : any stps to make ipif_bdd1 - use keephandle	
5615 101221	518t 19t	20			BMDN2 : maked some tests .... work!
5616 --		5121				-- : added reading flash at startting loading config files
5617 --		5122				-- : maked open reading errors 
5617 101222	5123				--: maked tlf.
5618 --		5124				PRM_PCH->BMDN->TCPIP - test : maked subnet mask RTCS_if_bind(ihandle0, GetIP(), 0xFFFF0000); and in 							tcpip make  IN_CLASSA_NET, IN_CLASSB_NET
5619 101223	5125				PRM_PCH_L61: maled answer to broadcast udp request with subnet mask 0xFFFFFF00
5620 --		5126t				maket : maked in rtcs back classA_net - all work!!! 
5621 --		5127				BMDN2 : maked property reset of provingent with new addresses 						with cfgfile101027_20_1,bin 27_10_2010 12:46 work!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
5622 101224	5128t				BMDN2 : start making class for operating modems and transit channels of provingent; maked first version of irq funktion	
5623 --		5129t				-- : next step to make modem and transit channels
5624 101227 	5130t	31t			-- : --
5625 101228	5132t	33t	34t		-- : --.
5626 --		5135				-- : sucsesful compiled; need make messages ....R - indivindually[modem_quantity] and interrupt owner for test
5627 --		5136				-- : maked self requests for rezerv messages for every modem
5628 --		5137	38 39	40		-- : comment testpu37 interrupt ovner - have lock!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
5629 101229	5141  5142 5143			-- : work modem test and test tranzit work slowly
5630 101230	5144 45				-- : added struct for protection and any test modes. need make objekt and 							commands for operate pritection
5631 --		5146				-- : make correct lengh for loading 17
5632 110111	5147				-- : start of Year 2011!
5633 --		5148 49				-- : added some delays without modem 4
5634 --		5150				-- : next step work nearest to controller modem
5635 --		5151				-- : maked function to get and set protection structures
5636 110112	5152	5153	54 55 56	57 58 59 60 61 62	-- : start making objekts for protection
5637 110113	5163	64 65 66			-- : maked init protection structures in test mode 0xA3, printing messages tested on two modems 8 and 4
5638 110114	5167 68				-- : start removing "printf" to use pdc in bmdn2
5639 110117	5169 70	71 72			--  : next step to do not use pdc
5640 110118	5173 74				-- : maked to maked do not answer "all ok" - in maket not are provingents.
5641 110119	5175 76	77 78 79			-- : start to next steps.
5642 110119	5180				-- : maked work pdc with maket
5643 110120	5181 82	83			-- : better print
5644 110121	5184				-- : make function to set and get mask for interrupts - alarmenableget and alarmenableset
5645 --		5185				-- : compiled without pdc - work
5646 --		5186t	87			-- : for test try using pdc - do not wok on real plata? why? try read alarmstatus
5647 110124	5188t	89 			-- : next step to use pdc
5648 --		5190				-- : make tenths as signed int. need make request all used modems to to tenths in one moment - all - request and all receive
5649 110125	5191	92 			-- : start making only request and only receive
5650 --		5193				-- : print time only
5651 --		5194 95				-- : remove delay 50 mcs in read procedure
5652 --		5196				PRM_PCH_DEM_XIL :  maked back freq 100 MHz but NEED REPAIR hello7.h - it used old version! _______v364_______________________
5653 --		5197				-- : repaired hello7.h
5654 110126	5198				bmdn2 : start on new comp.
5655 --		5199 200 201 202 203 204 205 206 207 208		-- : next step to make n+1
5656 110127	5209				-- : make requesting any modem and reading previons in one cyckle
5657 110131	5210				-- : make timeout 1 ìñ - have period 2 ms
5658 --		5211 12	13 			-- : make some for periodic control
5659 110201	5214 15				-- : make rezerv modem num 4 and change koeff loadinged to addr 0xE ;right offset
5660 110201	5216				-- : on far end commutate only xilixses - provingents on tx shoud be all in working mode.
5661 110202	5217 5218			-- : maked mre best print
5662 --		5219 20	21			-- : maked operating modem leds.	
5663 --		5222				-- : temporary operating rezerv in periodic control - off to go out	
5664 110203	5223 5224 25 26	27 28			-- : next step to make n+1
5665 --		5229				-- : view parserequestrezerv responses	
5666 --		5230 31				-- : full n+1
5667 110204	5232				-- : removing operating provingents on rezerving - it loading only at start and next commutate on xilinx - maked in future receive side. all provingents in n+1 mode are loading undependenly saved states need init objekts in real states. need make getting channel for messages with two steps. why need reinit transmit of protected modem?
5668 --		5233				-- : more property init - can not init second provingents in future
5669 --		5234				-- : maked protokol byte to receive
5670 --		5235 36 37 38				-- : next steps, need make init objekts
5671 100207	5239 40	`			-- : send pareserequests to periodiccontrol for debug
5672 --		5241 42				-- : do not get currentrezerv for sugebny channel - it do not work!!!
5673 100208	5243 44 45 46			-- : start making measuring time have 16 - 17 ms
5674 --		5247				-- : remove some printing set high priority - have 13 - 14 ms
5675 --		5248				-- : use funktion modemisused in operating interrupts
5676 100209	5249				-- : at start do not set currentgetrezerv to curremtrezerv, can get from rezerv with hogh priority without noises. need make funktion setting to rezerv modem with highest priority if all noises are good.
5677 --		5250				-- : make setting modem with highest priority to rezerv without noises
5678 --		5251				-- : start making hotrezerv
5679 --		5252				-- : if currenthaverezerv getted off rezerev is setting to enover modem
5680 --		5253				-- : commented printing in interrupt time_all is 14 - 16 ms
5681 --		5254				-- : maked getting off currentgetrezerv if plata of modem getted off
5682 --		5255				-- : currentgetrezerv is set nomodem if plata getted off. need make 2 points if plata getted on : init reseive of sl channel and right init num of provingent   TESTED for rezerving
5683 110211	5256				-- : if channel is not in lock - modem do not try use this channel for send messages wok 14 -15 ms
5684 --		5257				-- : next step to try make hot rezerv
5685 --		5258				-- : can one modem get off and getoff; if two modems getted off - hanging, one modem back - rwezerv modem do not lock 
5686 --		5259`				-- : more right if plata getted off; if two plats getted off - one oh off, next on off - all xilinx in work mode and rezerw modem do not lock
5687 --		5260				-- : next step
5688 --		5261				-- : do not hangt if do not have channel modems
5689 --		5262				-- : do not try set some to zero modem without channel modems
5690 --		5263				-- : if modem is getted to rezerv to xilinx is init as WORK_ON
5691 --		5264				-- : remove print to have good time
5692 --		5265				-- : set SetModemXILNPL1m before loading provingents
5693 110214	5266				-- : maked funktion setprotobj
5694 --		5267				-- : set parseflags tio bmdn_init
5695 --		5268				-- : make parsing buffer in moment receive some after 								"A5"; can if work with sending request disable loss time to scanstate modems - exchanging with provingents!!!! 	
5696 110214	5269				-- : make disabling requests time = 8 ms!!! need make disabling on far place?	- not
5697 110215	5270				-- : make low priority 8-9ms
5698 --		5271				-- : start make test mode 0x8e
5699 --		5272				-- : in test mode 0xA7 set test mode 0x8e and restart without errors to testers!!!!
5700 --		5273				-- : remove any print - this should be restart without errors if do not work tcp ip
5701 --		5274				-- : any step to try make mode 1+0
5702 --		5275t 76t 77t	78t 79t		-- : compiled no protection version work after power on/off make getting xilinx made 1+0
5703 --		5280 81 82 83			-- : start make gateway and netmask
5704 110217	5284t 85t 			pum_v : for maket  maked gateway and netmask without remote for maks
5705 --		5286t				-- : for maket, have remote
5706 --		5287				-- : ____________________________v_366 for working - errors
5707 110218	5288t				-- : delete some errors with remote.
5708 --		5289				-- : for working send
5709 --		5290				bmdn2 : if xilinx is loaded do not reinit modems!!!
5710 --		5291t 92t			BMD-35	: maked network mask and pdc - not hangt at init
5711 110222	93t				 --: --.
5712 --		94t				-- : checkdoneshort return zero - xilinx loaded and device init olwais
5713 110224	95				-- : if test mode is 0x8e - it changed to 1 and writed to flash!!!! - 
5714 110225	5296				prm_pch_n_3 : next step
5715 --		5297t				-- : any step to debug usart2
5716 --		5298				-- : answer for protokol to usart2.
5717 110228	5299t				-- : for test use usart2 without pdc on 38400
5718 --		5300t				-- : maked init of emb232s
5719 110301	5303				-- : ___________________v367 work usart2
5720 110302	5304	05			prm_pch_n3_nov : new formula  right print version
5721 --		5306				prm_pch_n3_fsb : --
5722 --		5307				pum100 : enable interrupts -- NOT WORK - compiled with maket options
5723 --		5308	5309	5310 5311	prm_pch_n3_nov : change operating of pins
5724 --		5312	13			-- : --__________________________v370 v371
5725 110304	5314t				pum100 : next step to make test modem
5726 --		5315				prm_pch_3_fsb : maked first version
5727 --		5316	17			pum100 : more property work test tranzit
5728 110309	5318				prm_pch_l61 ____________v372 - change formula 9
5729 --		5319				-- : __v373 - maked subnet mask only 0xffffff
5730 --		5320				pum100 : added test up0
5731 110310	5321				prm_pch_l61 : _________v373 : change answer udp
5732 110311	5322				prm_pch_dem_xil_chn : first step without maked status
5733 --		5323 24	25			-- : maked command status, changed struct DmuStatusu
5734 110314	5326				bmdn2 : start using yournal.
5735 --		5327	28			prm_pch_l61 : _________v375 _v376
5736 110315	5329				pum100 : next step of test -fixed by edik
5737 110317	5330 31	32			-- : -- next step
5738 110321	5333t	5334t			mx155 : maked for maket
5739 110322	5335t	5336t	5337		bmdn2 : print if setted test mode == 0x5a
5740 110323	5338				prm_pch_l61 : changed formula9 ___v377
5741 --		5339 40 41 42				ups : first step.
5742 110325	5343	5344 5345 5346			bmdn2 : maked start of reading phy id on receive
5743 110328	5347				pu_m_v : v378 : ip_forward = true
5744 110329	5348t				-- : maket!!! correct add gateway!!!!!!!!!!!!!!!!!!!!!!!!!!!!
5745 --		5349				-- : v379 -gateway work -- checked by ping comp through gateway
5746 --		5350t 51t 52t 			ups : maket : maked using usart2
5747 --		53t 54t				-- : usart2 is setted as rs485	moved rs485 algoritm edik
5748 --		55t				-- : maked on usart2 full algoritm edik; need make enover interfases as tuts, but add commands for reading edik.
5749 110330	56t				ups : maked remote from tuts need add commands from pum_v
5750 --		57t 58t	59t 60			-- : added stack commands from pum_v
5751 110331	61				-- : view answers from edik!!!
5752 --		62 63				-- : maked chacking priznak in command 0x22(set ip address) to not crash it from rnms
5753 110401	64t				maket : pum_v with printing commands
5754 --		65t				ups: remove checksum from receive of rs485 - have test print
5755 --		5366				-- : work to rs485 as tuts.
5756 -		5367				-- : not need crc - remove checking it
5757 --		5368	69			bmd155: maked testmode 6 - send 232 to rs485 and rs 485 to 232
5758 --		5370t				ups : can be rewrited from rs485!!!!; have test printing from remote
5759 --		5371t 72t				-- : --?
5760 --		5373				-- : is rewrited.
5761 --		5374				tuts : do not answer for requests with addri == selfid
5762 110408	5375 76 77				bmdn : next step
5763 110411	5378t				dmu3 : start make restoring
5764 --		5379t				-- : make some for setting symbolrate
5765 --		5380				ups : remove commands of setting config - set in init one config set type of device 0x403
5766 110412	5382t 83t			dmu3 : next step for maket.
5767 --		5384				dmu3 : first work version
5768 110413	5385t 86t	87		bmdn : start making using one provingent on plata
5769 110414	5388t				prm_pch_dem_xil_chn : maked test print	
5770 --		5389				-- : last work version		
5771 110415	5390				bmdn : deleted error in parsing flags
5772 --		5391				--   : can use for messages currentrezerv 
5773 --		5392				-- : some steps; rezerving work - tested
5774 --		5393	94	95 96 97 98	dmu3 : changed protokol
5775 110418	5399				prm_pch_n3_nov : changed formula3 to formula4
5776 --		5400				dmu3 : invert reading lock and have pch and read modul from plata
5777 --		5401 5402			dmu3 : loadddss maked after loading xilinxes
5778 --		5403				-- : xilinx in channel2 is loaded and do not reseted
5779 --		5404				-- : print if only test mode is 0x5a
5780 --		5405 5406 			-- : if xilinx are loadedd -returned from init and if not 0xaa
5781 110420	5407				-- : removed hot restart _____________v382
5782 --		5408				pum100 : maked reading all registers from command 0x50
5783 --		5409 5410 5411	5412 5413t			-- : next step.
5784 110421	5414				-- : added command 0x18
5785 --		5415 16				-- : change counters writte zero in port 21;
5786 110422	5417				-- : maked test print
5787 --		5418				-- : maked reset on addr 0x39
5788 110425	5419				bmdn : next step
5789 --		5420				pum100 : write at start 1 in port 21
5790 --		5421				-- : check parameters better before write to nvram
5791 --		5422				bmdn : do not return from set protection to can set rx if answer is 0x11
5792 110426	5423				bmdn : maked set protection for transmit on currentrezerv provingent : so have real rezerv 
5793 --		5424				prm_pch_n3_nov : changed formula4
5794 110427	5425				-- : go back to formula3	
5795 --		5426				bmdn : maked init of receive of currentrezerv if make protection - really rezerved					
5796 --		5427				-- : two time load synt at start. why time will be 18 ms?
5797 110428	5428				prm_pch_n3_nov : changed formula4.
5798 --		5429t				buk - puma : optimize remot - need repair.
5799 --		5430				--  : next work version _______________385
5800 --		5431				pum : -- 
5801 --		5432				bmdn : make every 30 sec runcommandfile if it is not in lock
5802 --		5433				mpc35 : some changes in remote for new protokol
5803 --		5434				mpc34 : --
5804 --		5435				mx155 : --
5805 110506	5436				pum_v : v _385 :  correctly work command 4d
5806 110513	5437				bmdn : enable second loaring transmit side, enable loading reserved 						provingent every time of setting rezerv
5807 --		5438				-- : enable validate rezerv every time to not seal.
5808 110516	5439				-- : remowe any loop why hangt without dewices.
5809 110518	5440				-- : get red led only if two times one provingent do not answer
5810 --		5441				-- : bad modem will be blinked - try
5811 --		5442				prm_pch_n3_nov : added formula5.________v386
5812 --		5443				bmdn : blinked not answered modem
5813 --		5444				bmd155 : make cashe size 2.
5814 --		5445				-- : maked cashe full off. _______________v387
5815 --		5446				bmdn : add event : EV_ALARM
5816 110523	5447				act155 : maked cashe full off. _______________v387
5817 --		5448				act155n : --.
5818 --		5449				tuts : --
5819 --		5450				bmd35 : --.
5820 --		5451				mpc35 : --.
5821 --		5452				bmdn2 : --.
5822 110524	5453				-- : next step.
5823 --		5454				-- : fixing all reseults for mode n+ 1 before start makeing bmdn3 : 1+1.
5824 --		5455				bmdn3 : start projekt 1+1 mode with using current xilinx protokol.
5825 --		5456				-- : next step : make modem quantity  = 1.
5826 110526	5457				-- : -- maked loading to xilinx mode 1+1
5827 --		5458				-- : maked loading protection.
5828 --		5459				-- : fixing before changing readstateeasy to check seconds provingents.
5829 --		5460				-- : maked readstateeasyd.
5830 --		5461				-- : nexte step; need make get rx phy id for all first devices.
5831 110527	5462				-- : maked self GetRxPhyIdD()
5832 --		5463 64	65			-- : next step.
5833 110530	5466 				-- : add to modemp protectionrxstate
5834 --		5467				-- : remove directories to self - catalog, 
5835 --		5468 69				-- : make funktion GetProvData to can read state of provingents.
5836 110531	5470				-- : make start using acm parameters
5837 110601	5471 72	73 74			-- : make counters  - need make command to read it, added commands to read
5838 110602	5475 76				-- : added to commande reading current tx and rx acm modes
5839 --		5477				-- : timeout changed from 5 to 1 ms --NEED CHECK!!!!!!
5840 110606	5478				-- : maked reading asmodem[0].modulation modulation[0] in acmconfig 
5841 --		5479				-- : start making getrxphyid.
5842 --		5480, 81			-- : use getrxphyid of needupdate
5843 110607	5482, 83, 84 85 86			-- : uce acmcountersget.
5844 110608	5687				-- : acmswitch
5845 --		5688 89	90 91			-- : maked pragma DO_NOT_LOAD_PROVINGENTS_PROTECTION
5846 --		5692				-- : maked printing current noises and acm state to com port olwais
5847 --		5693				-- : variant with empty loop, work modem.
5848 --		5694				-- : commented pragma big config file
5849 --		5695				-- : maked modem quantity 9 to work on  9- modems sektion last modem.
5850 110609	5696				-- : make using config file 40k
5851 --		5697				-- : changed error in loading modes n+1 and 1+1
5852 --		5698				-- : add to class modemp two massiwes
5853 --		5699				-- : add reading modulation
5854 --		5700				-- : maked command to set tresholds
5855 --		5701				-- : added to command reading status and noises. 
5856 --		5702				-- : add to remote command to get acmstatus propertis as need update, need 							make all commands foe acm to remote
5857 --		5703				-- : add to remote commands operating with acmprofileenable; need make 							operiting with acmengineenable
5858 --		5704				-- : add to remote command to acm engineenable. need make some for protection
5859 --		5705				-- : add command to ModemAcmProfileMaskGet
5860 --		5706				-- : add command to PVG610_API_ModemAcmSwitch
5861 --		5707				-- : make funktion protectionoff
5862 --		5708				-- : make using protektion off and protection on.
5863 --		5709 				-- : make command to change protektion
5864 --		5710				-- : maked for maket
5865 --		5711				-- : start making protektionstatusget
586.6 --		5712				-- : no maket, no empty need finish commands prottstatus het and 							modemstatusget - all counters add
5867 110614	5713				-- : changed command 0x60; need check sizes
5868 --		5714				-- : maked sizes for command 0x60
5869 --		5715				-- : corrected any commands
5870 --		5716				-- : maked command 0x68
5871 --		5717				-- : --.
5872 110615	5718				-- : start making remote command act counters get
5873 --		5719				-- : maked command 0x69
5874 --		5720 21				-- : remove some printf
5875 110616	5722				bmdn3 : empty loop
5876 --		5723				-- : deleted error in SetNeedInitAllProti - was (mod+1) << 1
5877 110617	5724		       prm_pch_spi : start version
5878 110620	5725 26	27 28			-- : next step to make init	
5879 --		5729				act155n : maked more long testmode2 _____v 288	
5880 --		5730 31	32 33 34	       prm_pch_spi : start init receive pdc	
5881 110622	5735				-- : --	
5882 --		5736				-- : deleted error to setting ssc0_base; need ssc2_base in init pdc
5883 --		5737				-- : can view continius transmit clocks
5884 --		5738				-- : add enabling tx and rx - view this in status register and view pdc counter is zero!!!! con be viewed on oscilloscope td and tf
5885 --		5739				-- : set loop bit and rx clock source from tk
5886 --		5740				-- : view readdata ssc2!!!!!!
5887 --		5741				-- : print received data
5888 110623	5742				prm_pch_l61 : maked delay 100 ms for all 
5889 --		5743				prm_pch_spi : try make interrupt
5890 --		5744				-- : view interrupt handler
5891 --		5745 46	47			-- : next step.
5892 110624	5748				-- : make operating receive buffers in interrupt and remove printing received data - view two interrupts for one transmittingfirst - after 10 bytes receiving, next - full receiving.
5893 --		5749				-- : make io line pb22 to can make line alarm - view two interrupts to 90 and 75 mcs of receive bytes; - try without print
5894 --		5750				-- : without print interrupte are 40 and 20 mcs 
5895 --		5751				-- : use buffer for received data and start parsing - need try use protokol novomar.
5896 110627	5752				-- : make imitate disabling pin if is not self address.
5897 --		5753				-- : compiled with some operating and parsing from prm -pch -n
5898 --		5754 55	56 57			-- : next steps
5899 110628	5758t				-- : start making embmsgs
5900 --		5759				-- : next step
5901 --		5760t				bmd155 : test version compiled with option "ALL Addr"
5902 --		5761				prm_pch_spi : next step to make ssc2
5903 --		5762 63				-- : add set linedatatozero
5904 110630	5764 65	66 67 68		-- : add operating of line alarms
5905 110701	5769				-- : start making remote for tcpip operating
5906 --		5770				-- : add remote and sending test data
5907 --		5771				-- : comment some in parsecommand to try measure time.
5908 110704	5772				-- : make counter of interrupts
5909 --		5773t				-- : where reding data from pdc buffer - do not use buffer - wery short time!!!
5910 --		5774	75			-- : tru make more quickly working operating commands, use pb19
5911 110705	5776	77 78			-- : deleted any error to set type of command	
5912 --		5779t	80			-- : any step to make test transmit from ssc1, full compiled viev data on pb 8, strobe on pb6 and continuos transmit clocks on pb7
5913 110706	5781 82 83			-- : make recovering hello7.h, 83 loop off
5914 110707	5784				-- : more right configure need make printing!
5915 --		5785				-- : receive some wrong
5916 --		5786				-- : start make telephone in bmdn3
5917 --		5787				bmdn3 : remove addresses 0x5.. for telephone funktions
5918 --		5788 89				-- : remove 0x5.. addresses from test of telephone.
5919 110708	5790				prm_pch_spi : make receive to failing edge - receive ok?
5920 --		5791				-- : send 16 Bytes
5921 --		5792				-- view on pb19 reaction to selfaddress, time to reaction 40 mcs!!!!!! Need make using line and sending answer
5922 --		5793				-- : can make low line  of transmit data ssc2 b14
5923 --		5794	95			-- : make zero sending data
5924 110710	5796 97 98 99			-- : make state waiting command and receve command
5925 --		5800				-- : inverting receive clocks for ssc2 - more stability work.
5926 --		5801	02			-- : all prepared to make answer
5927 110712	5803t				-- : try send some to ssc2
5928 --		5804t				-- : use setting line to zero
5929 --		5805t				-- : make 16 bytes frame to send
5930 --		5806				-- : view full diagramm!!!!
5931 --		5807t				-- : make test of channel and view losses of symbols!!!!
5932 --		5808t				-- : make freq ssc2 low to 10 times 500000 - no errors!!!
5933 --		5809t				-- : make back 5MHz
5934 --		5810t				-- : work irq0!!!!!!? need try starting operatebuffers in irq0
5935 --		5811t				-- : any step to use irq0
5936 110713	5812				-- : with interrupt irq0 do not loss symbols on 5MHz!!!!!!!!
5937 --		5813				-- : do not testing channel.
5938 110714	5814				-- : set to zero current_command_counter in start interrupt.
5939 --		5815				-- : maked setting lines data and alarm off if current state of command is waiting.
5940 --		5816				-- : try and have set pb22 to zero (pb22 is absent in maket never pb18; pb20)
5941 110715	5817 18				-- : add delys t12 t13
5942 --		5819				-- : maked try adding to buffer data of command		
5943 --		5820 21				-- : next step	
5944 --		5822				-- : send three times up 1f
5945 --		5823				-- : next step - use only needed parameters for command
5946 110718	5824 25	26 27 28		commutator : start version from bmd155
5947 --		5829 30			prm_pch_spi: make Init() after operating with message - can correct view parameters 							of message
5948 --		5831				-- : remove printing.
5949 110719	5832 33	34 			bmdn3 : start making reading text file
5950 110720	5835 36 37 38	39		-- : can read length of text file
5951 --		5840 41				-- : start make remote command, make command 0x70
5952 110721	5842 43	44 45 46 47 48	commutator : added files from pu_m; need change remote, add cashe and make exchange channels  1->3
5953 110722	5849t	50 51 52 53 54 55 56 57 58 59	-- : start full - projekt - all added
5954 110725	5860				-- : start next step
5955 --		5861				-- : final
5956 --		5862				-- : removed sending to ethernet data of rs485e without pragme
5957 --		5863				bmdn3 : start making getting info about written files.
5958 --		5864				-- : next step.
5959 --		5865				-- : change sources for statepump
5960 --		5866				-- : add using statepum	
5961 110726	5867				-- : added struct Emb4Md15504Cfg
5962 --		5868 69	70 71 72 73 74 75 76		-- : start scan config files
5963 --		5877				-- : maked test printing
5964 --		5878				-- : v390 right print text file.
5965 --		5879	80			-- : try set config file to command 0x50:3
5966 110728	5881				-- : maked GetStmPhyReg.
5967 --		5882				-- : to statepum.state[4] is writen GetStmPhyReg
5968 --		5883				-- : repaired command 50:1 have troubles if ucorrect config file was setted
5969 --		5884				-- : restored keep locks in state[2]
5979 --		5885				-- : added reading register 12 to state[6]
5980 --		5886				-- : maked loop bits in state[5]
5981 --		5887				-- : maked all without command 0x51
5982 --		5888				-- : make request of Net_E1_alarms_struct
5983 --		5889				-- : make constant E1_LINES_QUANTITY
5984 --		5890				-- : added setoptics
5985 110729 	5891				-- : get laser on olwais
5986 --		5892t 93t				-- : start debug
5987 --		5894				-- : can view far modem to modem channel  !!!! v391
5988 --		5895				-- : more print for test mode 2
5989 --		5896				-- : making set optic
5990 --		5897				-- : set optic olwais.
5991 --		5898				-- : invert lock bits in statepum[2]
5992 --		5899				-- : added normalized mse tenths
5993 --		5900t 5901			-- : start making acm mask
5994 110822	5902			     bmdn3 : first packing up after holiday.
5995 --		5903			commutator : start changing after holiday
5996 --		5904t				-- : test version without interrupts
5997 --		5905			      bmdn3: linked with file link31l.met : added for ram 5M
5998 --		5906			commutator : recompiled.
5999 --		5907			      bmdn3: priodcounter in test mode2 maked from 1000 to 10
6000 --		5908			      -- : make more quickly test
6001 --		5909			      -- : make reading errors olwais and without loock to can read errors under protection
6002 110823	5910				-- : maked view lock correctly 
6003 --		5911				-- : added commands 0xA and 0xB
6004 --		5912				-- : make in test mode 6 test tranzit only
6005 --		5913				-- : more long times with working to cse2
6006 --		5914				-- : add reading status register to test tranzit - test will go!!!!
6007 --		5915				commutator : delete addresses 0x5...
6008 --		5916				bmdn3 : set modem quantity 1 : not view some in tests
6009 --		5917				-- : some of tests go, make modem quantity back 9
6010 --		5918				-- : test modem work but getted off test transit!!!!!
6011 --		5919				-- : if specially enabling rx tranzit before writing - in test mode 2 going receive!!!(now with errors)
6012 --		5920				-- : if do not read masks from xilinx test 2 work as test 6 - rx transit do not stopped
6013 --		5921				-- : start making bus test
6014 --		5922				-- : added to bus test testing zero register modem 0.
6015 --		5923				-- : tests started property
6016 --		5924				-- : next step
6017 --		5925				-- : if fixed byte do not have in status "2" - second reading
6018 --		5926t				-- : without interrupts
6019 --		5927				-- : testmode 2 going without lower bit!!!!!
6020 --		5928t				-- : more long test with olwais setted to one lower bit.
6021 110825	5929				-- : tranzit work with capacitors on wr and rd
6022 --		5930			commutator : can load telephone with xilinx from bmdn
6023 --		5931 32 33 34	              bmdn : changed ulerrout wrted in 5760 some changing in counting errors
6024 --		5935				-- : removed from remote : transec	
6025 --		5936				-- : make protection to remote, reading config files moved from funktion loading config files need make led norma
6026 --		5937				-- : last version	
6027 110826	5938				-- : make printing errors in test mode 0x5a
6028 --		5939				-- : print fecblockcounter
6029 --		5940 41				-- : try operating 	led norma on addr 0x12	
6030 --		5942				-- : make enabling service_channel
6031 110829	5943t 5944			-- : some experiments with slug_tlf
6032 110830	5945				-- : make modem_quantity 1
6033 --		5946				-- : delete error in write ab10
6034 110831	5947				-- : write to signature hardware3 and 4  modem ports 12 and 13 and uncommentared PVG610_API_ModemAcquireStart
6035 --		5948 				prm_pch_l61 : changed formula9
6036 --		5949				bmdn3 : write to signature hardware3 and 4  modem ports 0x12 and 0x13
6037 --		5950				-- : printldpcdecoderstress
6038 --		5951				-- : delete error in init telephonekoeffs
6039 --		5952tt				commutator_debug : many debug changes in projekt commutator need go back to previons
6040 110901	5953				commutator : it do not hangt with enabled interupts on plata act15501 xilinx - from act15501!!!!!(types are enover!!!)
6041 110902	5954 55	56			ups1 : start making ups with ethernet, next step, full
6042 --		5957				commutator : enable rs485e and gateways
6043 --		5958 5959 				-- : make adding from rs485 and 485e to tranzit 
channels south and north - checked hier near end with ups1
6044 --		5960				-- : make number 0x404
6045 --		5961t				-- : for test - without interrupts
6046 --		5962s				commutator1 : start making
6047 --		5963				commutator1 - next step - do not hangt!!!!!!!!!!!!!!!!!!
6048 --		5964				-- : enable rs485e
6049 --		5965				-- : maked new command 0x22
6050 --		5966				bmdn3 : --_______v393_____
6051 --		5967				commutator1 : delete error to not send embmsg485e to all channels 
6052 110905	5968				-- : make sending buffers of messeges to its channel - do not enover channels. add sending 0x55 in end of message
6053 --		5969				-- : remove sending from messagebuffers from while{} of receiwebuffers 
6054 --		5970				bmdn3 : change errors after rs2 to fecuncorrected blockcounter
6055 --		5971	72 			commutator1 : added testud1 and ud2
6056 --		5973				-- : all tranzit go!!!
6057 110906	5974				-- : test maked as more quicklest
6058 --		5975				bmdn3 : change max_num_cfg 32 from 16 delete error in length celling where << 18 used ______________v394________________
6059 110907	5976				-- : 50 configs ________v395_____________
6060 110908	5977e				-- : added rs485e and compiled and compiled with pragma RS485E_ENABLED 							__v396_____	
6061 --		5978			prm_pch_spi: maked calling from setfreq1 setfreqN
6062 --		5979			-- : setatt1 -> setattN
6063 --		5980t			commutator : test wersion : directly send transit answer without buffer - why buffer do not work
6064 --		5981			-- : do not use buffer of answers in all channels
6065 --		5982			-- : delete error to send teastbuffer to modem channel
6066 110909	5983			-- : check messagebuffers enbled only if flagrequest is zero to do not lost messages
6067 110909	5984			bmdn3 : do not use scanmodems() and send command run config file only at start	
6068 --		5985			-- : write cod of symbolrate in port PORT_FILTER _______v397________
6069 110912	5986			bmdn3 : if code > 30 code = 30 _______v398___________
6070 --		5987			prm_pch_spi: start make sending from tcp to ssc
6071 --		5988			commutator : keep that is writed into ports
6072 110913	5989			prm_pch_spi : next_step.
6073 --		5990			-- : --
6074 --		5991			bmdn3 : maked hotstartconfigfile() to con more quickly change configurations 
6075 110914	5992			prm_pch_spi : send 0-15 receive 0-32
6076 --		5993			-- : can receive 0x3f bytes!!!!!!!!!!!!!!! (16*4)!!!! In read data ssc2 -use
6077 --		5994			bmdn3 : maked second request if acqurestatus is zer0 af bad answer return
6078 --		5995			-- : remove second request if not in lock
6079 --		5996			-- : remove readstateeasyd
6080 110915	5997			prm_pch_spi : maked modyfyng symbols 0x55 0xa5 0xaa 0x5a before put it into buffer for sending through spi
6081 --		5998			-- : maked test sending every 5 sec 64 bytes
6082 --		5999t			bmdn3 : make writing to statepum lolcounters
6083 --		6000t			-- : use lolcounters & acquirestatus
6084 --		6001			-- : make keep in treshhold8 timer in sec from last loading config file.
6085 --		6002 6003		prm_pch_spi : next steps
6086 --		6004			-- : is found self address
6087 110919	6005			-- : start making commands
6088 110919	6006 07			-- : next step
6089 --		08 09 10 11 12		bmdn3 : any changes to can view acm - repaired command 0x52
6090 110920	6013 14	15 		prm_pch_spi : next steps
6091 --		6016			-- : can view parsed answer
6092 --		6018			-- : after 10sec usart0 - to 115200 setted
6093 110921	6019			prm_pch_spi_stend : try receive on ssc1
6094 --		6020			prm_pch_spi : try make transmit ssc2 from external clocks and from failing edge rf pin
6095 --		6021			-- : use as clock input rk pin - stend receive some data
6096 --		6022			-- : get off inverting clock - have stability data on receive
6097 --		6023			-- : view correct data to receiving request and receiveing answer
6098 --		6024			bmdn3 : temporary ignore if checkdoneshort get positive result and reading config files olwais if set confgfile
6099 --		6025			prm_pch_spi : use tk pin for clock
6100 --		6026			bmdn3 : temporary do not used counters losses of lock; for acm mades getting use receive counters
6101 --		6027			-- : making loading to specregs 0x5c3f specvalues 0x2
6201 110922	6028			prm_pch_spi : start making operating line alarm : portc : 10
6202 --		6029 30			prm_pch_spi_stend : send 16 bytes to prm_pch can proprty transmit answer; have any errors
6203 110923	6031 			prm_pch_spi: use 1 byte for send
6204 --		6032 33			-- : not make setting line data off
6205 --		6034			prm_pch_spi_stend : send one time
6206 --		6035			-- : send two time but have period 40 ms
6207 --		6036			prm_pch_spi : added formula6
6208 --		6037			-- : changed formula6
6209 --		6038 39 			-- : remove operating ssc1
		40					: try send to ssc2 up 64 bytes
		41			stend : mke test receive data
		42			-- : make some for parsing answers
		43t			-- : try send answers to tcp hangt!!!!!!!!!!!!!!!!!!
		44 45			-- : next step
6210 110926	6046			prm_pch_spi : start after holiday
6211 --		6047			-- : make some for init -----get to Jura
6212 --		6048 49	50 51		-- : any changes in formula6 and att b[2]
6213 110927	6052			prm_pch_cpi_stend : make 50 ms
6214 --		6053			prm_pch_spi : use so as n5
6215 --		6054			-- : try set transmit to self clocks between sending
6216 --		6055			-- : can receive some
6217 --		6056			-- : use getiprem() as my address
6218 --		6057			prm_pch_cpi_stend : use as MY_ADDR address 0xff - real addr is 0x7f
6219 --		6058			prm_pch_spi : make broadkast addr 0x7f
6220 --		6059			-- : some changes in formula
6221 --		6060			-- : try set address back
6222 --		6061			-- : next try set addr back
6223 --		6062			stend : --.
6224 --		6063			prm_pch_spi : try change setatt1n and setlinedatassc2tossc22data
6225 --		6064t			-- : set a5 b5 a6 b6 direct
6226 110928	6065	66 67 68 69 70	-- : changed setting atts
6227 --		6071 72			-- : try use remote of usart2
6228 110929	6073			BMDN3 : start  disabling interrupts before reading flash
6229 --		6074			-- : disable and enable interrupts directly in readdataflash()
6230 110930 	6075t			stend : rewritting - ok
6231 --		6076t			-- : used link31n.met : ram1 maked back to addr 20500000 - to servecepack work!!!!
6232 --		6077			rm_pch_spi : can be rewrited from servicepack	
6233 111003	6078			stend : start new day ok.
6234 --		6079			prm_pch_spi : without test print; time for standard protokol temporary maked 0xffffffff	
6235 111004	6080			-- : try use internal clock to start pdc
6236 --		6081			-- : can use enable tx
6237 --		6082			-- : can use disable tx
6238 --		6083			-- : set int clocks to 1 mcs
6239 --		6084			-- make disable and enable pdc tx
6240 --		6085			-- : for test send only 6 symbols of answer
6241 --		6086			BMD-34-IP : start version 
6242 --		6087			stend : next step
6243 --		6088			-- : added numbers of packets
6244 --		6089			prm_pch_spi : print numbers of packets 
6245 111005	6090			-- : without printing for test of hanging
6246 --		6091			-- : maked function add for embmsgssc2n
6247 --		6092 93			-- : start try making crc
6248 --		6094			BMD-34-IP : make soft ver 111		
6249 --		6095 			stend : make comm2_len1 = 3 
6250 --		6096 97	98		prm_pch_spi: added check crc.
6251 --		6099			prm_pch : changed formula9  v416
6252 --		6100			-- : test version vithout corections
6253 --		6101 02			stend : litle prints
6254 111006	6103			stend : period of send 10 ms.
6255 --		6104			prm_pch_spi : do not have interrupt of spi receiver ready - not hangt!
6256 --		6105			-- : next step
6257 --		6106			-- : make using run_time_n 1ms for command2  to can quickly send requyests
6258 --		6107			stend : send request every 3ms - have answers!
6259 --		6108			prm_pch_spi : start make address
6260 --		6109			-- : define my_addr (Getusartrem)
6261 --		6110			-- : make file embmsgn
6262 --		6111			-- : make all in prm_pch_spi.cpp mery shortly
6263 --		6112			-- : do not use embmsgs
6264 --		6113 14			-- : use for all functions time_rin_n
6265 --		6115			prm_pch_dmu3 : added modul 0x90 = 0x30
6266 --		6116			prm_pch_spi : do not used at start funktion loadddsn2
6267 111011	6117	18		-- : test wersion for maket without ssc1 
6268 --		6119	20		prm_pch_l61: changef formula9 v417
6269 --		6121t			stend prmpchl61 : without corrections
6270 111012	6122			prm_pch_spi : add scaning buffers ssc2 in not in interrupts time
6271 --		6123 24			-- : use receive clocks; at start have some answers and dann fall
6272 --		6125 6126			-- : get to standard state to start make corrections to att3
6273 --		6127			-- : added to formula7 table for att3 - maked in b16
6274 --		6128			-- : maked more right formula7.
6275 --		6130ttt			-- : go back to keeped  hello7_6072 and make from it version need restore all enover projekts
6276 --		6131ttt			-- : use for linll link31mn.met 
6277 --		6132			-- : change achh for pm1
6278 --		6133			-- :  -- for pm2	
6279 --		6134			-- :  -- for pm1
6280 --		6135			-- : -- for pm1; pm2 - is changed but not arhived
6281 --		6136			-- : -- for pm2
6282 111013 	6137t			bmdn3 : compiled for maket plata
6283 --		6138			prm_pch_spi: any step
6284 111014	6139			-- : --
6285 --		6140`	`		-- : --;
6286 --		6141	42		-- : --;
6287 --		6143			commutator1 : make rate of usart1 9600
6288 --		6144			-- : remove protokol radian from interface rs485
6289 --		6145   	46	47	prm_pch_spi : next step     
6290 111017	6148			-- : view receive on spi!!!!!   
6291 --		6149 50			-- : try receive some
6292 --		6151			prm_pch_spi_stend : send data 0 .. 256 
6293 --		6152			-- : send high byte first - view receive!!!! 
6294 --		6153	4		prm_pch_spi : if print counters - every bit two times is received
6295 --		6155 56			-- : any step
6296 111018	6157			prm_pch_dmu3 : maked loadbaud()
6297 --		6158			commutator : not make print in testmode 4.
6298 --		6159			prm_pch_spi : view increable values with losses
6299 --		6160 61			-- : work printing to usart1!!!!!
6300 --		6162			prm_pch_spi_stend : inverted transmit clocks on ssc1 : view good clocks without not needed picks - view receive zeros ok
6301 --		6164			-- : try send continuos data
6302 --		6165			prm_pch_spi : invert clocks and  view receive 0x5a!!! - that i send!!! 
6363 --		6166 67	68 69 		prm_pch_spi_stend : try send to spi
6364 211011	6170 71	`		-- : make return and opreatebuffers to have print
6365 241011	6172			-- : next step
6366 --		6173			prm_pch_spi : make cntt1 type unsigned to have print
6367 --		6174  5 6 7			-- : next step
6368 251011	6178			prm_pch_spi_stend : view receiving answer. 
6369 --		6179 80			prm_pch_spi : remove sending cammand data back!
6370 --		6181			stend : start making operating with tcp
6371 261011	6182`83		`	prm_pch_spi : start making spi_write_n2_io
6372 271011	6184 85			stend : next step
6373 --		6186			stend : hangt
6374 --		6187 88	89 90 91	commutator1 : start making ustir.
6375 111028	6192t	93t	94t	stend : comment many calls to do not hangt.
6376 111031	6195			stend : print only answer of prm_ch
6377 --		6196			prm_pch_spi : start making changing formula7.
6378 --		6197			-- : changed formula7 : 170 -> 158; temporary remove external spi and io load dds
6379 111101	6198			-- : for serial number 1
6380 --		6199t			-- : do not hangt with pragma use_spi
6381 --		6200			-- : maked set linedataoff() in interrupt handler delay 200 mcs with print
6382 --	`	6201 02	03		-- : temporary commented to do not hangt loadddsn2
6383 111102	6204			-- : deleted error in spi write n2 io - pointer was do not setted, declared only.
6384 --		6205 06			-- : maked some for polling reading spi time of answer up to 100 ms
6385 --		6207			stend : start making full work with tcp
6386 111103	6208			-- : view answer 0x55
6387 --		6209			-- : next step, called some
6388 --		6210 11			-- : view receive some. maket hangt with right adderess
6389 111107	6212			bmdn3 : maked reading nvram every loop.
6390 --		6213t			prm_pch_spi: for test return from readdataspi - do not hangt
6391 --		6214			--: remove writing devid - do not hangt!
6392 --		6215			stend : view in tcp answer from pm_pch_spi
6393 111108	6216			bmdn3 : print configs
6394 --		6217			--: correctly get all configurations independently of current
6395 111109	6218			bmdn3 : tested correctly start be writing in modems
6396 --		6219 20	21 22 23 24	commutator : change parse
6397 111110	6225`		`	commutator : keep addresses in flash
6398 --		6226			-- : maked test "B2"
6399 --		6227t 28t`		-- : maked printing and maket veersion.
6400 --		6229 30 31		-- : work version _________v428____________
6401 --		6232			prm_pch_l61 : changed formula9
6402 --		6233t			prm_pch_l61_stend : no corrections
6403 111111	6234 35	36 37		dmu4 : start version.
6404 --		6238			prm_pch_l61 : changed formula9 : -2 db for prm 7 
6405 --`	6239 40	41		dmu4 : next step
6406 111114	6242 43	44 45		dmu4  : work wersion
6407 --		6246			dmu4 : decoder and test keept in memory
6408 --		6247			-- : start making parsecommand 6 and 7
6409 111115     6248			-- : full maked paqrsecommand6.
6410 --		6249			-- : -- parsecommand7
6411 -- 	6250 			prm_pch_spi : maked without corrections
6412 --		6251			dmu4 : maked sedecandtest
6413 --		6252 53	54 55 56	-- : start making loadram
6414 111116	6257			-- : make test mode b3: idle mode
6415 --		6258			dmu4 : next step
6416 --		6259t			prm_pch_spi : after 1 min is setted idle mode.
6417 --		6260			dmu3 : changed value of MODUL9.
6418 --		6261			-- : deleted error to do not have getsymbolrate2 v430
6419 --		6262	63		dmu4 : next step
6420 111117	6264			prm_pch_spi : after 1 min is really  setted off mode.
6421 --		6265 66	67 68		dmu4 : next step to write ram.
6422 111122	6270			prm_pch_spi : changed <>in formula7
6423 --		6271			dmu4 : changed addresses
6424 111123	6272			prm_pch_spi : serial #2 changed b16 formula7
6424 --		6273			prm_pch_spi : serial #1 changed b16 formula7
6425 111124`	6274	75 76 77 78 79	dmu4 : next step
6426 --		6280			-- : maked command 6 - write to ram
6427 111125	6281 82 83 84		-- : start make command 7
6428 --		6285			-- : remove channels 3 and 4
6429 --		6286 87 88 89		-- : change files sizes and addresses
6430 --		6290			-- : added to signature_hardvware state of decoder
6431 --		6291			-- : work tests only without 512
6432 --		6292			-- : test work full	
6433 --		6294, 95		-- : any steps to debug, 95 - wiew data!!!!
6434 111126	6296 97			-- : added test b5
6435 --		6298			-- : do not use test mode
6436 --		6299			-- : do not use channels 3 and 4
6437 --		6300			-- : when write to flash use size comm file - full file is writed
6438 --		6301 02			-- : use 4 bytes for sweep in command 6 and for size
6439 --		6303			-- : remove debug print from command 6
6440 --		6304 05			-- : swt frequency 25 MHz when is loaded decoder
6441 111128	6306			-- : changed second try writeramtoram
6442 --		6307 08	09		-- : start making read ram
6443 --		6310	11		-- : maked back using writing addrf1 sizef1 - absolute values need make its read
6444 --		6312 13 14		-- : use mdata port 0xd - but not 0x13
6445 --		6315			-- : in test mode 0x5a - correctly writed to flash!!!!
6446 --		6316			-- : remove from test print increment of pointer to buffer.
6447 --		6317			-- : remove test print if not setted test mode 0x5A
6448 --		6318 19			-- : make equal address for all previons decoders for qam512 use special address; for prev decoder is read ok
6449 --		6320 21			-- : exchange place for low and high bytes only for prew decoder and for diff decoder
6450 --		6322 23			-- : for channel 2 answer modul right, final?
6451 --		6324			-- : changed low and high bytes
6452 --		6325			-- : make for high bytes qam512 direct setting address 0xc0c00
6453 --		6326			-- : automatically load decoder ram if changed modul
6454 --		6327			-- : v_435 delete error in loadbaud rate vas declared as unsigned char
6455 --		6328			-- : v_437 deleted error in loadband() - need use symbolrate
6456 --		6329 30		prm_pch_spi: compiled with USE_SPI, Do_NOT_RUN_COMMANDS - have full answer; need try send requests with enover address 

6457 --		6331			-- : printing command daqta in hex; need in stend make counters
6458 111130	6332			-- : deleted saving to channels 3 and 4 - to property start channel 2
6459 --		6333		 spi_stend : maked counters for transmit and receive spi
6460 --		6334		 --	   : maked celling CRC - ok; need check - why prm_pch_spi send answer to every 								envelope - we are sending only 1/2 commands, 1/2 is "FE" symbols!!!
6461 --		6335		prm_pch_spi: star6 making commands 20 and 21.
6462 111201	6336 37 38 39 40 41 42			-- : make some for afr, prm_pch_spi_work1
6463 --		6343 44 45 46 47		bmdn4	: start projekt with pwg710.
6464 --		6348 49t		prm_pch_spi: repair commands 20 and 21 		
6365 111202	6350		-- : 	remowed test print and not for maket	
6366 --		6351		bmdn4 : any step; need recomment ::add.
6367 --		6352		dmu4  : try make add load dds3 if change symbol rate - to do not loss operating of ddss
6368 --		6353		-- 	: make test for loading symbolrate
6369 111205	6354		bmdn4 : maked addud1, addud2
6370 --		6355		-- : maked transmit for ud1
6371 --		6356 57t 58 59t 60	prm_pch_spi : maked big test and printing
6372 111206	6361 62	63	bmdn4 : maked full in class ...Prov adding UD1 UD2
6373 --		6364		-- : maked adding channel updown.
6374 --		6365 66		-- : start making measuring temperature
6375 111207	6367 68	69 70 71	-- : start making pwg710
6376 111208	6372		spi_stend : compiled.
6377 --		6373 74	75	prm_pch_spi : compiled ; used pragma 'Do not run commands'
6378 --		6376		-- : mewed do not run commands after setfreq - only delay getted off
6479 --		6377 78		-- : do not print "^", use do_not run commands only for delay
6480 --		6379		spi_stend : right send to spi commands and 0xfe symbols - do not commands only!
6481 111209	6380		-- : period 6 ms
6482 --		6381		prm_pch_spi : do not print something 
6483 --		6382		spi_stend : 20 ms
6484 --		6383		prm_pch_spi : print more
6485 111212	6384		-- : command_counter should be set to zero if receiwed 0xaa
6486 --		6385		-- : added back polled receive spi may be for property real work need decrement received length value!!!! -and may be not need add command_length to answer& - answer is shorter as command
6487 --		6386	87 88	-- : maked some for lines data_off and connect; need make some for line alarm
6488 111213	6389 90		bmdn4 : start adding pum remote. and adding leds on controller plata
6489 --		6391 92 93		-- : added led norma on controller, changed address for led norma on modem plata
6490 --		6394t			-- : without init, without main, without interrupts - work loop only 
6491 --		6395t			-- : without interropts only
6492 111214	6396 97	98 		-- : full, use mirror_test for enabling interrupts, added BusTestFar
6493 --		6399	6400		-- : maked reletest
6494 111215	6401			-- : added test up1 and test up2.
6495 --		6402t			-- : for test commented init and main loop
6496 --		6403 04			-- : if do not get mirror test get frm init
6497 --		6405 06	07	   PU_MSAT : start making, all getted off
6498 --		6408		     bmdn4 : commented setneedallprot - in init... do not hangt??? v____442
6499 --		v50_romboot1 		all: romboot can load up to 450k
6500 111220	6409		   PU_MSAT : added loading ddses
6501 --		6410, 11, 12, 13 14 15 bmdn4   : add tests, make some to can view s/n 
6502 111221	6416 17 18 19			-- : can get noises, can set loop, added setmoduli, full can set onetone mode
6503 --		6420 			bmdn4 : add printing datq from updown channel in testmode 0x50
6504 --		6421 22			-- : can view answers to Fg
6505 	v50_romboot2			all : make higher delay load property
6506 		6423 24			bmdn4 : work channel updown, ready fol operateprogramm
6507		6425, 6426 27		-- : can view blink status
6508		6428, 29			-- : stat day, 100 ms delay - work
6509 111222	6430, 31			-- : vco is loaded property, xlo loaded?
6510 --		6432 33	34 35		prm_pch_spi : start making going back to ssc, do not hangt, receive some
6511 111223	6436t			-- : test : do not hangt on continual clocks
6512 --		6437			-- : received all : !!!!!!!!!!!! operatecommand() is temporary commented
6513 --		6438t			prm_pch_spi_stend : test send something wrong to ssc1
6514 --		6439			--		: changed init - can view receiving 01
6515 --		6440			--		: send command.
6516 --		6441			prm_pch_spi :  try use operate command, but receive only 1/2 bytes
6517 --		6442			stend : changed init
6518 --		6443			prm_pch_spi : if do not try operatecommand() - receive ull message
6519 --		6444	45		-- : next step, commented setruncommand, next
6520 --		6446			-- : if returh before LoadDDs() - do not hangt
6521 --		6447			-- : add operatebuffers_ssc2t() - can view answers on stend!!!!
6522 --		6448			-- : remove init_test_spi() - do not hangt!!!!!
6523 111226	6449			-- : maked setting line datassc2 off if bad crc, need make off if bad address and chack commanddatalength for all commands and all commands
6524 --		6450			-- : if bad address line data is off, need check
6525 --		6451			-- : without print -little as 100 mcs to set line data off.
6526 --		6452			-- : set line data to one after run command
6527 --		6453 54			-- : add  polled parsing
6528 --		6455			-- : printing getted back; need check all commands, and enover addresses
6529 --		6456			bmdn4 : property work with operateprog
6530 --		6457 58	59		-- : pripared for bbloop and if loop.
6531 111227	6460			-- : get information about lock
6532 --		6461			-- : tx output make off when make calibration.
6533 --		6462			-- : make some for leds.
6534 --		6463 64			-- : --
6535 111229	6465			-- : add remote command 9 - to can operate updown channel
6536 120110	6466t			-- : maket : changed algoritm calibrate xlo.
6537 --		6467			-- : are changed 5 regs for pvg710 in programregs
6538 --		6468			-- : print maked off
6539 --		6469			-- : can get temperature
6540 --		6470			-- : change algoritm to work without lost lock
6541 120111	6471			-- : in test mode 50 do not print from telephone and interrupts
6542 --		6472			-- : added init max band for pvg710 vco
6543 --		6473			-- : added in alarm led state of pvg710 need make lower delay and status of pvg610 						and 710
6544 --		6474 75t 76			-- : start make status
6545 120112	6477 78			--  : finish status and make shorter time now load 58s with no answer pvg710
6546 --		6479			--  : make alarem if xilinx do not loaded and pvg610 do not answer
6547 --		6480			--  : maked correctly status of pvg610
6548 --		6481			--  : maked correctly status of pvg710 : test answer to 0xff
6549 --		6482			--  : added dev_status to signature_hardware as [12]
6550 120113	6483 84 85 86 87 88		--  : maked reading AGC.
6551 120116	6489			prm_pch_l61  : attenuator fixed on value 30 only for 1 exemplar v458
6552 --		6490			bmdn : maked addresses for stvols : 0 & 1 (was 1 & 2) 
6553 --		6491			-- : maked structure state of trunk - need operate trunks from its states; need make operating gigabit ethernet
6554 120117	6492 93			-- : start making geth
6555 --		6494 95 96 97 98 99	-- : start making operating trunks v460
6556 --		6500 01			-- : more often operatetrunks : every 45ms
6557 --		6502			-- : set back remote addresses 1 and 2
6558 120118	6503 04			-- : maked checking not current trunk need make do not sending if make operating
6559 --		6505			-- : make operating if yhave send requests of stoate to eiher channels
6560 --		6506			-- : get in device status, status bit 6 of syntezer
6561 --		6507			prm_pch_spi : try compile
6562 --		6508			bmdn4 : changed settings of pvg710- more good prcession
6563 --		6509			prm_pch_spi : do not print 
6564 120119	6510			prm_pch_spi_stend : right set couting positions in message : length, command and enover
6565 120120	6511			act15501 : compilled with gateway
6566 120120	6512			prm_pch_spi_stend : make back sending from tcp to ssc1 
6567 --		6513			-- : temporary getted off periodikal sending to can view sending commands from tcp ip
6568 --		6514			-- : !!!! can view answer to tcp ip from ccs!!!!!
6569 --		6515			-- : receive answers olwais!!!!
6570 120123	6516 17			-- : use flag to send to tcp - from ethernet can view answer to sended command, checked 8 commands
6571 --		6518			bmdn4 : temporary get off operating trunks v_466
6572 120124	6519 20	21 22 23t 24	
	-- :  start try using modforss as keeping parameter for state of modem
6573 120125	6525			act15501 : maked with gateway, added sypport of gateway for command 22
6574 120125	6526t		bmdn4 	   : print debug info to eth, commented checking type of last command
6575 --		6527			-- : added test modes 0xc2 and 0xc3
6576 --		6528			-- : --.
5677 --		6529			-- : do not check lock pd
5678 --		6530			-- : more right algoritm operatetrunk
5679 --		6531 32 33			-- : more right check not current trunk, correct have enover, get off power fault
5680 120126	6534			-- : make counter for faults  if counter == 4 - change trunk
5681 --		6535t			-- : print power
5682 --		6536			-- : get in operprog dev_state1 - more correctly for pvg610 -0 - do not crash if dev_state = 0
5683 120127	6537			-- : start new day
5684 --		6538t  39		-- : with print work operateng trunks from JackE_mod
5685 --		6540 41	42		-- : do not change parameter Mod forss at start - property init operprog
5686 --		6543tt			-- : test try init 710 before 610
6587 --		6544	45		-- : make changing for property view pvg610 - 0
6588 --		6546t			-- : try make test of time
6589 120130	6547			-- : try make delay_mcs() to 3 times shorter  load faster at 8s
6590 120131	6549			-- : delete some delay_mcs()
6591 --		6550			prm_pch_spi : compile after work with stend
6592 --		6551 52			-- : remove some printing ....send!!!!!!!!!!!!!
6593 --		6553			bmdn4 : 710 loaded before 610	lock olwais!!!	
6594 --		6554t	55 56 57 58 59 60	-- : try find loading protection
6595 --		6561t	62 63 64		-- : start making get enover errors in rs-mode
6596 --		6565			-- : answer to tcpip!!!!!
6597 --		6566			-- : more easy getchanneltosend
6598 120203	6567			prm_pch_spi_stend : send every 10 ms and address oxff
6599 --		6568			prm_pch_spi : without print time of reaction 50 mcs time of end 					1000mcs
6600 --		6569			bmdn4 : right read gigabit ethernet
6601 120208	6570			pu_msat : make buffer 5 MBit - do not work prog model!!!!
6602 --		6571t			bmdn4t : do not use startmodems()
6603 --		6572t			-- : maked test printing and many commented. for new fwfile need change prov sizeto download!!!!!!!!!!!!!!!!!!!!!!!!!
6604 120210	6573			bmdn4 : work with new config file!!!!
6605 --		6574 75	76 77 78	-- : added some from ver 3.3
6606 --		6579			pu_msat : recompile for xilinx 4,2 mb
6607 --		6580			tuts : compiled with old lnk31o.met ôàéëà
6608 --		6581			-- : right work - compiled with lnk31p.met 
6609 --		6582	83		pu_m_sat : first version without interrupts 
6610 --		6584			bmdn4 : do not work 
6611 --		6585			-- : with buffer size 4 mb work
6611 --		6586 			bmdn4 : make buffer back 1 mb - it is in .bss section not in _buff_sect
6612 --		6587			-- : make right place for tftp buffer - not in bss
6613 --		6588			pu_msat : can write to internal flash xilinx - need rewrite it to another flash 
6614 --		6589			bmdn4 : without checklocks() - may be need make hard reset?
6615 120214	6590			prm_pch_spi_stend : send addr 0x81
6616 --		6591			pu_msat : any try writing flash
6617 --		6592			prm_pch_spi_xil : start version for changes
6618 120215	6593 94	95		-- : next step
6619 --		6596	97 98		-- : make some for interrupts need add setting to one and to zero and make sending data to transmit buffer before setting zero
6620 120216	6599	6600		-- : any step
6621 120216	6601 02	03 04 05  06 07 pu_msat : any step to load ddses, without interrupts
6622 120217	6608 09	10		-- : loaded filters, use pult on usart2
6623 120218	6611			-- : start making bus
6624 120221	6612 13			-- : make writing, reading
6625 --		6614			bmdn4 : more long tlf test more short channel test
6626 --		6615			prm_pch_spi_xil : maked init frequency as min_freq
6627 --		6616 17	18 19t 20 21 22 23 24 25	pu_msat : start making torempult
6628 --		6626 27 28		pu_msat : change command for curdata CH->Ch; satset0 need make menu item
6629 120228	6629 30	31 32 33 34t 35t 36t 37t 38 39 40		prm_pch_l61 : start adding command 10
6630 120229	6641 42	43 44 45 46 47 48 49 50 51 52 53 54	pu_msat : next step to make item SatSet0
6631 120301	6655 56 57			-- : try nake three menu items visible
6632 --		6658			prm_pch_spi_xil : start making in hardware
6633 120302	6659 60	61		-- : any step.
6634 --		6662 63 64 		-- : with xilinx and get_clk1; without interrupts
6635 --		6665			prm_pch_spi : use formula8fsb. - for yura only!!!!!!!!!!!!!!!!!!!!
6636 --		6666			prm_pch_spi_xil : make reading address.
6637 --		6667			-- : maked operating data lines
6638 --		6668			-- : operating alarm lines
6639 120304		6669			-- : maked setatt8N	
6640 --		6670			-- : maked setupr
6641 --		6671			-- : maked setattn	
6642 --		6672			-- : maked setatt7n
6643 -- 	6673			-- : set frequency at init 
6644 --		6674	75		-- : with enabled interrupts and test print	
6645 120305	6676 77			prm_pch_spi : use formula8fsb. - for yura 
6646 --		6678 79	80 81		prm_pch_spi_xil : any more compact
6647 --		6682 83	84 85		prm_pch_spi : change pins n5 to s0 in setsynt + change formula8 - for yura
6648 --		6686			prm_pch_spi_xil : maked setsynt
6649 --		6687 			prm_pch_spi : change freq
6650 --		6688 89			prm_pch_spi_stend : use in maket spi - start
6651 --		6690 91			prm_pch_spi_xil : use att_table, rate for loading xilinx 1000, loaded xilinx
6652 --		6692	93 94 95 96 97		-- : make reading some bytes in one interrupt, maked test print
6653 120311	6698 99 6700 6701	-- : comment some old code, make m_get_clk1 : plla/4
6654 --		6702			-- : use formula8fsb
6655 --		6703 04	05		-- : correct setting a-b-c- regs
6656 120312	6706 07			-- : start new day
6657 --		6707			-- : lines a-b-c - ok!!!!!
6658 --		6708			-- : have test print
6659 --		6709	6710t		prm_pch_spi- maket: for receive spi on spi for maket plata
6660 --		6711			prm_pch_spi_xil : msb first
6661 --		6712			-- : lock olweis returned as 1.
6662 --		6713t			-- : version with checking operatecommand.  - run!!!!
6663 --		6714t 15 16			-- : make printing, every byte read in individual 
interrupt
6664 --		6717			-- : maqked command0 
6665 --		6718t			-- : maked the  counters printing 
6666 120313	6719			-- : maked address for afr table as xildataaddressd2 - (afr_size<<1)
6667 --		6720t			-- : without use_att_table
6668 --		6721t			-- : use printing
6669 --		6722t			-- : work led norma
6670 --		6723 24t			-- : work version - view good receive
6671 --		6725t			stend : send commands to set freq 
6672 --		6726			prm_pch_spi_xil : maked second time changing plase for table afr
6673 --		6727			-- : make reading in interrupt blok symbils - time reaktion 10 mcs!!!!
6674 120314	6728 29	30 31		pu_msat : start next
6675 120315	6732 33			-- : can view value of satget0
6676 --		6734 6735 36		bmdn5 : start making 1+0 act15501, use option LOAD_ONE_PROVINGENT_ON_PLATA
6677 120316	6737 38	39 40 41 42 43	44 45 46 47 48	-- : make ledsreg3.
6678 120318	6749			-- : can reading and writing ports in rrl writeport and readport changed
6679 120318	6750			bmdn4 : --
6680 --		6751			pu_msat : make some for menu.
6681 --		6752 53			-- : add view in menu set variables, and get variables
6682 --		6754 55			bmdn5 : make some for yournal - need check datain events lock and unlock
6683 120322	6756			bmdn4 : can view power off time in journal
6684 --		6757 58	59 60		pu_msat : add names to classes; need add remote and changing in menu
6685 120323	6761 62	63 64		-- : make remote
6686 --		6765			-- : added input lock and search; need make remote, bounds  and runs for all
6687 --		6766 6767 6768	69 70 71 72 73	-- : make remote and start  make detailed all full with diaps and runs
6688 120327	6774 75 76 77 78 79			-- : next step
6689 120328	6780 81 82 83			-- : can view lock in logoitem, set freqs, set bound and tx level
6690 120330	6784			-- : to compiler-preprocesser added di /source/httpd and compiled with httpd.h
6691 --		6785t 86t			-- : next step
6692 120402	6787 88 		-- : --
6693 --		6789 90	91 92t 93 94		-- : use _io_dev_install_ext1 - do not hangt!!!
6694 --		6795 				-- : use_mem_alloc_system_zero - do not hangt!!!!!
9995 --		6796			-- : next step : need remove _lwmem???(in  _io_tfs_install())
9996 --		6797			-- : sock_select_activiy - temporary commented - it have in freescale two arguments (file soselset.c) need check - where are used this new parameter foer property working
9997 120403	6798			-- some work on http!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
9998 --		6799			-- : tfs_data are init in main task
9999 --		6800			-- : polling is commented - without polling - start property
10000 120404	6801			-- : compiled back with polling
10001 120405	6802			-- : proprty start after night under opera, operating system packed to source2 rtcs, source2 mqx, need fix as all work in rtcs; try use internet explorer, and make separate task,
10002 --	6803			-- : make working HTTP server in task mode
10003		6804 05			-- : use more print
10004 120406	6806			-- : start from three times try
10005 120409	6807 08			-- : any next step
10006 120410	6809t 10			-- : add cgi.c, back; maked back timeout
10007 120410	6811			-- : something work!!!!!
10008 120411	6812			-- : work in IE view system run time!!!!!!!! in opera do not work
10009 --	6813			-- : can view tcp statistics and print from cgi functions
10010 120412	6814			-- : added page Modem - to site - need - add to point POST functon post() and print - from it - have data or not
10011 120413	6815 16	17 18 19 20	pu_msat : work without interrupts  try write xilinx
10012 120416	6821			-- : make some for property read xilinx	
10013 --	6822			-- : xilinx is loaded	
10014 --	6823			-- : correctly setted freq from pult
10015 --	6824			-- : make bounds for filters 1---30; load at start parameters from flash
10016 --	6825			-- : make satset0 - pricessing freq, satset1 - system delat satset3 -operating keys
10017 --	6826			-- : maked satget2 as channel delay - added to menu
10018 --	6827			-- : maked formula for procfreq
10019 --	6828			-- : system delay without point
10020 120418	6829			-- : delete error : in operatefile do not use size from command - use xilsizetodownloadD
10021 --	6830 31	32		-- : more right work ::Lastdigit if have digits after point do not hangt to Up
10022 --	6833			-- : view something really without point
10023 --	6834 35 36 37			-- :can view some after point, keep in memory values after point
10024 120419	6838			-- : maked sys delay
10025 --	6839			-- : maked status register
10026 --        6840			-- : maked using write io bus
10027 --	6841 42	43 44 45 46		-- : maked RGstr RGsat, view in remote on usart0 float value
10028 120420	6847			prm_pch_l61 : added constructor to MDataS - compiled succesful
10029 --	6848 49			-- : TEST !!! delays = 0; maked printing
10030 --	6850			pu_msat : change format frequency sweep f6.3 - f4.1
10031 --	6851t			web : more correctly web page : have refresh
10032 --	6852			pu_msat : make programming pult
10033 120424    6853			-- : make some for pult
10034 --	6854t			-- : have any print about POST Method
110035 120425`  6855t			prm_pch_l61 : test version with quickly requests 3 ms
110036 --	6856t			pu_msat: change pins 22 and 23 
110037 --	6857 58			bmdn6(act155052) : start making filters
110038 --	6859			-- : final?
110039 --	6860t			-- : prm+pch_l61 3ms	
110040 --	6861t			pu_msat: make rate for usart2 56700; make print 
110041 --	6862			prm_pch_l61 : blocked commands 30, 31	
110042 120426	6863 64			pu_msat : make 2 stop-bits - view some on indikator!!!!	
110043 --	6865t			-- : added operatebuffersusart2t to have delay between symbols
110044 120427   6866			-- : do not hangt at start
110045 --	6867			-- : can view sended from post data in device side!!!!!
110046 120428	6868			-- : make some for menu.; need that pult using unlock device to test mode 3
110047 --	6869 70	71		-- : key Enter unlock device; to mode 3; 
110048 --	6872t 73t		-- : added httpd_set_device_params()
110049 --	6874 75 76 77 78 79			-- : start making xilblockitem.
110050 --	6880t : web interface : temporary commented using httpd_set_device_params() - do not hangt?
110051 --	6881t	: -- can read two params
110052 --	6882t : added some print
110053 --	6883 84			   : start make IF-Balance 	
110054 120504	6885t 86t			 web intrrface: more right print
110055 --	6887			-- : make two try writing to flash
110056 120505	6888 89	90 91		-- : name of xilinx changed after rewritin and not before to have real name 	
110057 120510  6892 93			bmdn6 : start making fillallconfigfileversion() 
110058 120511	6894			-- : make bind ip after all inits
110059 --	6895			-- : can get names of configfiles
110060 --	6896			-- : if make return from setband()(do not run it) - view property 
behaviour of lock channells
110061 --	6897			-- : configfiles are reading one time
110062 120512	6898			pu_msat : int test mode delay is setted to zero
110063 --	6899 6900 01 02 03 04		-- : can view -12.0 on indicator
110064 --	6905 06			bmdn6 : added delay between reading configfiles to can property read!!!!!!!
110065 --	6907			pu_msat : use 6 lines for operating power
110066 120516	6908			-- : propertu view on indicator
110067 --	6909 10 11 12 13 14 15 16 -- : added objekt sign to class mdatac
110068 120517	6917			-- : setting ip address work property
110069 --	6918, 19		-- : some menu items dileted,step freqs 1 kHz
110070 120518	6920			bmdn6 : compiled after changing class mdatac
110071 --	6921			-- : can print 15 configs in test mode 0x51
110072 120521	6922			-- : added AllConfigFileVersion2 AllConfigFileVersion3
110073 120522   6923			-- : --.
110074 120523	6924 25 26 27		pu_msat : start make cremsattiming
110075 120524   6928			-- : use for satset1 testing min and max values and using nearest
110076 120525	6929			-- : every hour added event 9 with 3ee bytes info
110077 120525	6930 31			-- : added SatSet8
110078 120528	6932 33			-- : next step SatSet8
110079 --	6934			-- :; record_size : 64 -> 16 to have many records
110080 120529	6935			-- : try get record not to address but to number.
110081 --	6936			-- : fix state every 5 min
110082 120530	6937			--:  record with num more as max enabled sended as zero
110083 --	6938			-- : new logo; need make menu item for indikating test mode and try make blinking values
110084 120531	6939			-- : start making sattestmodei
110085 --	6940 41			-- : start making blinkrate
110086 120607	6942			-- : in reading records replace 0 to ' ' to property send to remote
110087 120608	6943 			bmdn6(bmdn4) : in command 0x50 (3) check length of message to == 2
110088 --	6944 45			-- : start add check crc - need check _______v509_________
110089 --	6946 			prm_pch_spi_xil : make test version without att table with working 							command for setatt8N
110090 120609   6947			-- : -- + delete some errors
110091 120614	6948 49			pu_msat : make indikating on logo Master/slave mode
110092 120615	6950 51 52			-- : start making radianversion.
110093 120618	6953			bmdn6-1 : compiled with option "LOAD_ONE_PROVINGENT_ON_PLATA"
110094 --	6954			commutator2 : start adding uart2
110095 120619	6955 56			-- : next step, need programm usart 2 as rs485
110097 --	6957			-- : do not enable rs485e
110098 120620	6958			-- : make and stop make adding three transit channells (now have 						four ), need chang fhysikal using usart1(485) and usart2(485-1);
					in ups.cpp usart2 used as rs485!!!!! 
110099 --	6959			used rs485 from ups1 - work with edik need make changing usart1 <-> usart2
110100 120621	6960 61	62 63		-- : maked half of changing usart1<-> usart2
110101 --	6964 65			-- : embRS232S cn trens from buffer
110102 --	6966 67			-- : add command 0x4d, need add commands to operating of antenna from pu_mv
110103 120622	6968	69		-- : add command 0x4c; operate antenna : command 0x53-> nama, b,c -> calluster-> pdc1
						- DO NOT need move to pdc2!!!!, use ustir2.cpp
110104	--	6970			bmdn6 : reanimate xil_flash
110105  --	6971			-- : maked test mode 0x61 - try write and read xilinx flash
110106	--	6972			-- : print p0 n0 - flash is not init?
110107  --	6973			-- : init in AT91F_DataflashInitx to default values(do not work 					    dataflashprobe), have err2
110108	--	6974			-- :AT91F_DataFlashSendCommandx : pDataFlash->pDataFlashDesc->state) != IDLE
110109 120625	6975			-- : try init only one flash bank
110110 --	6976			-- : check deviceindex : in pvg610HostSpiDataSendx it is 24
110111 --	6977			-- : LOAD ONE PROVINGENT v 512
110112 --	6978 79			-- : load two provingents, next step to write xilinx flash, comment setting state BUSY
110113 120626	6980			-- : LOAD ONE PROVINGENT v 513 enabled interrupts
110114 --	6981			xil_flash : make short AT91C_DATAFLASH_TIMEOUTX to do not work very very long time writnig and reading
110115 --	6982, 83			bmdn3 : test version without interruptsto use modem bmd310 to try rewrite flash of xilinx
110116 --	6984			-- : change writespibmcan view data clocks and cs!!!!!!
110117 --	6985 86			-- : i print what i receive from flash, command d7
110118 --	6987			-- : maked writereadspibm
110119 --	6988			-- cycklyng reading status
110120 --	6989			-- : property readed status!!!!!!!
110121 --	6990			-- : property init flash? - need check or correctly are byte mack and page offset
110122 120628   6991 92			-- : data are sended to flash - not command only
110123 120629   6993 94			-- : any step to make comman buffer
110124 120630	6995			-- : can write and read one byte from flash!!!!!!
110125 120701   6996			-- : can read all fife bytes from flash	
110126	--	6997 98 99			-- : ? write data with spiwritexr???
110127	--	7000			-- : step back : do not use spiwritexW
110128	120703  7001			bmdn6 : without interrupts can write and read two bytes many times?
110129  --	7002			-- : -- three bytes ok - thour - wrong why?
110130  --	7003 4	5 6 7 8		-- : ok four byes : use buffer for receive , fife bytes ok
110131	120704	7009 10			-- : property write two buffers, try make partial write
110132	--	7011 12	13 14		-- : property writed and readed 200 Bytes 500Bytes
110133  120705  7015			pu_msat : any stae to debug not first time writing
110134  120706	7016			-- : chack xilinx flash before tftp loading and writing
110135	--	7017			-- : delete any error in loading ddss : 0x88=> 0x99 - mirror reg0
110136  120709	7018 19			bmdn6, bmdn3: restore making writing to xil_flash
110137 --	7020			-- : include writin to operatefile
110138 --	7021 22			-- : can view in debug print version of file of xil_flash. need make checking full data volume
110139 --	7023			pu_msat : uperate line b12 to property write xilinx
110140 --	7024 7025 26		-- : any next staeps
110141 --	7027 28			bmdn3, 6: make step 6 in operate file to compare xil_flash file
110142 120711	7029			-- : comparing file of 240k (gen 240) is property
110143 --	7030			pu_msat : any changes menu
110144 --	7031 32	33 34		bmdn3,6 : start making SendCurState()
110145 120712	7035			-- : make void SendStatus()
110146 --	7036			bmdn3 : make receive command 0xee from modem channel and print 						results
110147 --	7037			-- : make do not using commands - parse info direct in receive function
110148 --	7038			prm_pch_spi_xil : added command 0 to spi.
110149 --	7039			bmdn6 : parse info about near modem
110150 120713	7040			-- : any step to debug ; do not check body[0] == 0 in IsEnd().
110151 --	7041			-- : remove debug print and make to work  test transit
110152 --	7042 43			prm_pch_sp_xil - testing command 02, and repair
110153 120716	7044t			-- : view answer to command 0
110154 --	7045			-- : without test print	
110155 --	7046			-- : addressreaded from port "0xd"
110156 --	7047t			bmdn6 : use for sending to far end byte about locks : unStatePUM.statePUM.state[2] bits 2 and 8
110157 120717	7048			-- : start making eth status get 
110158 --	7049			-- : can set gigabit in test mode 0x79
110159 --	7050			pu_msat : do not have ring in blink item
110160 120719	7051t			prm_pch_sp_xil : start making checksum
110161 --	7052t			-- : correctly get on checksum
110162 --	7053t 54t 55		-- : try add Modify5a() to operate with input data
110163 120720 	7056			-- : get off checksum
110164 --	7057 58			-- : delete any error with using special symbols
110165 --	7059t			-- : debug print but ignored crc
110166 120723	7060 61			pu_msat : start making remote, make union UPUM100S1 and start make command 0x70
110167 --	7062t			prm_pch_spi_xil : maked test print crc
110168 --	7063 64			pu_msat : any step  making read command SatSet0
110169 120724	7065			prm_pch_spi_xil : any step debug
110170 120725	7066			-- : v525 tested in sofia (on notrbook really)
110171 120725	7067 68	69 70		pu_msat : maked some for reading satset0...8
110172 --	7071			-- : can be setted all parameters from one command
110173 120727	7072 73	74 75		bmdn6:start making ModEth
110174 --	7076 77			-- : manitoring xil and change eth rate in provingent - only for auto - mode maked
110175 --	7078			-- : any step to make enover modes
110176 --	7079			-- : set as default auto mode
110177 --	7080	81		-- : set all modees to setted at start, and use in operating
110178 120730	7082t			commutator2 : test variant for maket.
110179 --	7083			pu_msat : maked reset for ddss pb22 - pin 59 ddss
110180 -- 	7084t			commutator2 : any step to print some  about ustir
110181 --	7085t 86t			-- : print transmit on rs485 data to rs232 in test mode 4
110182 --	7087t 			-- : make mode 0xc6 - print transmit and receive
110183 --	7088t			-- : comment periodical coll transmit requests 
110184 --	7089			-- : compiled for non-maket device
110185 120731	7090			bmdn6 : start making command for setting and reading ethernet config and state
110186 --	7091			-- : can be written modeth through ETH_COMMAND_PORT 
110187 --	7092			-- : can be read ModEth through ETH_COMMAND_PORT
110188 --	7093			-- : can read real eth state to remote max from xilinx STATUS_ETH_PORT
110189 --	7094			pu_msat : check all setted data through common command before try load
110190 --	7095			commutator2 : last my version.
110191 120828	7096 97 		-- : usart1 rate set from 9600 to 38400 remove recvustir
110192 --	7098			-- : start making keeping answers
110193 --	7099			-- : maked receiving answers to embmsg585_1 and to 						unStateRRL.stateRRL.ppu1_bytes
110194 --	7100			-- : maked using embMsg485Request_1 for transmit requests
110195 120829	7101 02			-- : maked test mode 0x104 for testing usart2
110196 --	7103			-- : start making command 0x54 : later answer after answer of antenna
110197 --	7104			-- : make long time for telephone test
110198	--	7105			-- : next step to making command 0x54 : temporary use 3 byte
110199	--	7106			-- : repaired test mode 0x104
110200 120830	7107			-- : make printing channels numbers
110201 --	7108			-- : make sendinganswer to asu after receive answer from antenna - need check length
110202 --	7109			-- : make writing norma bit in led port after mirrortest
110203 --	7110			bmdn6 : start changing bmdn
110204 120831	7111 12			-- : maked writing state of far end ; need make getting off leds if not have lock both channels
110205 --	7113			commutator : remove printing ethernet in testmode 4
110206 120903	7114			md310e : pragma PROG_MD310 start making md310 from bmdn6 : invert 					interrupts active level will be zero
110207 --	7115			-- : maked property answer from modem is used to types 0xa5 and 0xa6
110208 --	7116t 17t			-- : working on maket plata
110209	--	7119			tuts : try make - work on md310
110210 --	7120t	21t		md310 : start wersion wiwout YOURNAL and interrupts, init and main function
110211 --	7122 23			-- : try make full.
110212 120904	7124 25			-- : without start print and phone print xil not used
110213 --	7126 27			--: remove reading from ram
110214 --	7128			-- : remove getethstatus
110215 --	7129			-- : try add far errors
110216 --	7130			-- : indicate eth status to unEmb2TypeVer.emb2TypeVer.signature_hardware[5], remove using RELE_ADDR	(0x12) and  INPUTS_ADDR (0x13)
110217 120905	7131 32	33		pu_m710 : start making PU_M with using pvg710
110218 120906	7134			pu_msat : make checking parameters momentally
110219 --	7135t			-- : work on maket - all temporary getted off Yournal, init and pu_m()
110220 120907 	7136t			-- : Yournal uncommented, commented add_event in hello.c
110221 --	7137t			-- : corrected in add_event using address of event in geteventaddress checked address ti be in correct baund
110222 --	7138t			-- : remove returns from init_pu_m() and pu_m()
110223 120910 	7139			-- : full compiled
110224 120910	7140			md310 : added back Yournal and set default eth mode auto at start
110225 120911	7141t; 42t		pu_msat : for maket maked key_enter_flag; maked checking event address to % record_size	
110226 --	7143 44	45		-- : right indikation with bad xilinx name	
110227 120912	7146t			md310a : removed init run interrupt and start in hello.c to do not hangt	
110228 --	7147			-- : do not hangt if remove pragma xil_flash
110229 --	7148			-- : corecty operate ethernet to 100m and 1G
110230 --	7149			-- : correctly operate leds for far loop
110231 --	7150t			-- : for maket - 
110232 --	7151 52	53		-- : maked test mode 30 31 32 33 def 100 dupl
110233 --	7154			-- : direkt set at start digits - set 100 Mb ok
110234 --	7155			-- : if set four - times - ok
110235 --	7156			-- : at start setted in 100 Mb  - need load four times reset - no reset - reset - no reset
110236 --	7157, 58		-- : reset bit work better, send 3 commands
110237 120913	7159; 60			-- : two command wit reset, delay 100 mcs; no print
110238 120914	7161 7162		md34e=p_m710 : change xilinx size
110239 --	7163			-- : interrupts maked as low levels and are enabled
110240 --	7164			-- : maked new addresses for spi channel and status of pvg710
110241 --	7165			-- : make some for leds
110242 --	7166	67		-- : changed test tranzit, temperature
110243 120917	7168			-- : added supporting operprog
110244 --	7169t 70t		-- : for maket
110245 --	7171			-- : for work device
110246 120918	7172t 73t		commutator: start make test parsing
110247 --	7174			md34e=p_m710 : maked property operating leds ud1 and ud2
110248 --	7175 76			-- : maked test mode 35 : cycklic init pvg710; 0xc0; 0x36
110249 --	7177 78			-- : maked some print in test mode
110250 --	7179t			-- : enabled xil_flash : property init if do not work xilinx external flash
110251 --	7180 81			-- : withouttest print
110252 120920	7182t 83t		pu_msat : start change some in web interface 
110253 --	7184t			-- : view in hyperterminal messages to change any parameters in modem found  0: 20
found 001   1: 10000000 0: 33 found 001  1: 10000000  0: 20 found 001  1: 555 
110254 --	7185t			-- : added insertdynamicvalues; this is second method printing values; need and see to method that print time
110255 120921   7186t			-- : property maked insertdynamic values!!!!!
110256 --	7187t			-- : property can setted and getted back one parameter!!!!! need make to do not restart all
110257 --	7188t			-- : in httpd.c maked check time and session->time before checking timeout and closing session (this closing was second closing after closing!!!)	
110258 120924	7189t			-- : to httpd_ses_poll added _time_delay_ticks to do not lost time - work!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
110259 --	7190t			-- : remove some debug print	
110260 --	7191t 92t		-- : start making satsound and satfactory
110261 --	7193t 94t 95		md310e : try use setband - now have test print
110262 120925	7196			md310e : crc-off to proprty work radview
110263 120925	7197t 198t 199t 200t	pu_msat : for maket any step to make satsound and satfactory
110264 --	7201			md310e: change some in setband()
110265 120926	7202			pu_msat : maked ring if is not in lock.
110266 120926	7203t			md310e: for test do not load band and can loadding band in test modes c2 and c3
110267 --	7204			-- : maked back check crc only for modem and tranzit channels.
110268 --	7205 06	07 08		-- : maked loading filters for second channel, proprty errors and lock for far end
110269 120927	7209t 10t 		pu_msat : next step to make web interface
110270 --	7211t			-- : correctlu use data before . for first parameter in web interface
110271 120928	7212			prm_pch_l61 : start find errors to do not operate att
110272 --	7213			md310e : changed back far1<->far2. v537
110273 --	7214t			pu_msat : property read data with floating point
110274 --	7215t			-- : property work system delay
110275 --	7216t			-- : make factory settings
110276 --	7217 18			-- : finish factory settings
110277 121001	7219t 20t 21t 22t 23t : start making http for transmit and receive freq
110278 --	7224 25			-- : can use 9 digits
110279 121002	7226 27	28 29		-- : start making out level
110280 --	7230			-- : added sattestmode
110281 --	7231			-- : not for maket
110282 --	7232			-- : maked back right function : Control; need recompile for modem and enover devices
110283 121003	7233t			md310e: maket - property work unlock
110284 --	7234t			-- : maket delete bag to is unlocked devdata reset and configfile data
110285 --	7235			-- : not for maket v538
110286 --	7236			bmdn6 : -- + filters used
110287 --	7237			pu_m710 : --
110288 --	7238			-- : use MAX_COMMAND_SIZE v539
110289 --	7239			bmdn6 : --
110290 --	7240			md310e : --.
110291 --	7241			md310e : do not hangt xil_flash : try write to xilinx after getting clocks to xilinx
110292 121004	7242			-- : maked to need key5 to change configfile v540
110293 --	7243			commutator2: used back command 53/2 to send data for antenna to usart1
110294 --	7244			-- : maked deffered answer to command 53/2
110295 --	7245			md310e : make default config file number - max number; do not fill configfile version when write to flash ; make bigger delay to restart
110296 --	7246			-- : make more precession delay to restart v542
110297 --	7247			-- : delete two errors with getnumconfigfile : called with one and do not have break;
110298 121005	7248t			md310e : maket added events for commands to change config; used yournal
110299 121005	7249tt			pu_msat : start adding time and date menu items
110300 121005	7250			commutator2 : send to antenna not string but some bytes with length	
110301 --	7251			-- : send to max second answer from rs485; first is myself 
110302 --	7252 53			-- : added to ans addr and crc, added control of length
110303 --	7254t			pu_msat: do not write at start this value is not allowed
110304 --	7255t			-- : temporary for control maked default value = 1 => can go into menu
110305 --	7256t			-- : make ret = 1 for keydata; and default ret = 0; need make to do not cyckling if have bad parameter in flash
110306 --	7257t			-- : data and time added to menu but are not controlled and are zeroes
110307 121008   7258			prm_pch_l61: change formula9 v543
110308 --	7259			pu_msat : can view som time on indikator.
110309 --	7260			-- : when change mdatac - time is not updatet - can change time
110310 --	7261t 62t		-- : delete error to mot have break in ::control 55, can set date
110311 121009	7263t			-- : better can view time and date
110312 --	7264t	65t 66 67		-- : correctly setted sec(maked timedata1_max and min), no maket, 					http on
110313 --	7268			md310e : correctly read and write ModEth - do not get out of array size
110314 --	7269 70			-- : in work1 use variant = MAX_CFG_FILE_VARIANT - 1; in md310e
110315 --	7271			-- : added some break in work1
110316 --	7272 73	74		pu_msat : start making password; if is not test mode do not find par 8
110317 121011	7275 76t 77t		-- : olweis find parameter 008, have two passwords
110318 --	7278t			-- : can set number of crecord make in ::control to zero ret = 1; can be readed yournal!!!!!!
110319 --	7279t			-- : temporary do not use keep_state; need add UP-Link and Down-Link
110320 --	7280t			-- : added up-ling and down link events; need fink and make final journal event size and all sices to make some size available to keepstate
110321 121012	7281t			-- : start making MdataS::ModifyUp()
110322 --	7282t 83t 		-- : added items logitem and logview item
110323 --	7284t			-- : can view incremented counters in LogStr0 and LogStr1 
110324 --	7285t			-- : can view time and date getrecord(0)
110325 --	7286t			-- : can view many events
110326 121015	7287t 88t			-- : can use key Down, maked init, need do not use zero value of counter
110327  --	7289, 90 		commutartor2 : continue.; no Gateway - work
110328 --	7291			-- : make right ::control for variables network and netmask witch default : ret = 0;
110329 --	7292			pu_msat : any version log on indikator
110330 --	7293t 94t			-- : added crc to events, view only events with right crc
110331 121016	7295			commutartor2 : added to msg from antenna 0xaa, addr, length
110332 --	7296t	97t		pu_msat : start debug checksum
110333 --	7298			md310e : have gateway; indikate sleeps in jacke_mod.
110334 --	7299			-- : use control sleeps and for first channel
110335 --	7300			-- : get off yournal
110336 --	7301			pu_msat : added event lock
110337 --	7302			-- : do not change in geevent 0 to ' '
110338 --	7303			-- : maked not for maket
110339 --	7304			-- : start making logclear
110340 --	7305			-- : make sending zeroes values of mdatas to interfase usart0 and debug usart
110341 --	7306			-- : make some for logclear.
110342 --	7307 08	09		-- : --, --, not for maket
110342 121017	7310 11	12		bmdn6 : compiled with all new changes
110343 --	7313			-- : use file md310e.cpp with support ethernet modes(need new xilinx)
110344 --	7314			md310e: gettet off one trunk mode. v550
110345 --	7315			-- : make ver_offset for xil_flash setted zero; filldata will be work wrong
110346 --	7316_______________>			-- : use for version xil_flash point for xilinx2  _ISPITANIA!!!!!!!!!!!!
110347 --	7317			-- : use for version xil_flash point for xil_flash3
110348 121018	7318			-- : -- : il_flash point for xilinx2 - page size - header_size  - lower as configfiles address and .hv file address
110349		7319			bmdn6 : can write xilinx flash
110350		7320			pu_msat : can print yournal to comport in testmode 0xc7
110351 121022	7321			md310e : start debug read xil_flash version
110352 --	7322t			-- : test wersion can read some from header address!!!!!
110353 --	7323			-- : get xil_flash xilinx version
110354 --	7324 25t 26t 27t 28t	pu_msat : start making webpassword
110355 121023	7329t	30t		-- : --, need use "double" type of parameter to can use value 89999999
110356 --	7331			md310e : make default zero length of answer v555
110357 --	7332t 33t		pu_msat : start making master/slave operating from web page.
110358 121024	7334t			pu_msat : can set from web  master/slave, but now not can view
110359 --	7335t			md310e : start making operating power
110360 --	7336			-- : make test mode 0x66 - reinit pvg710
110361 -- 	7337			-- : start make operating power : send and receive input level information from far end	
110362 --	7338t 39t		-- : any step operating power
110363 121025	7340t 41t 42t 43 44	-- : --	 v558 use modforss bit1
110364 --	7345			-- : add state of operate power to signature_hardware[5]
110365 --  	7346			-- : add command to operate eth 0x57
110366 --	7347			-- : debug operate power
110367 121026	7348 49			-- : start making flag_enable_operate_power2
110368 --	7350			-- : disable operating power if level is ok.
110369 --	7351			-- : after 30 try make level good if it is not good try reenable operating power
110370		7353			-- : do not use power criterium
110371		7354			-- : do not disable operate power
110372		7355			-- : if send command operate power from rnms - disable operate power mode but not disable parameters
110373		7356			-- : use max power criterii
110374 121029	7357			-- : write getted off operate power mode if operate power from rnms to flash
110375 --	7358			-- : make flag_min_max
110376 --	7359			-- : make NormailzePower
110377 --	7360t			prm_pch_spi_xil : start madelling command 4
110378 --	7361t 62t			prm_pch_spi_xil_stend : compiled sending command 4	
110379 --	7363t			prm_pch_spi_xil : test print spi
110380	--	7364t			md310e :any step debug
110381 121030	7365 66			-- : next step of operating
110382 --	7367t			prm_pch_spi_xil : for test use spi parser for receive rs232
110383 --	7368			-- : for answer and reseive to rs232 used spi parser;
110384 --	7369t			-- : print on display, what reseived and answered WORKING!!!!!
110385 --	7370			-- : without test print
110386 121031	7371			md310e : more precession set input level
110387 --	7372			prm_pch_spi_xil : added TEST_DELAY_SPI 5
110388 121031	7373			pu_m710=md34e : correct measuring temperature
110389 121101	7374t 75t		pu_msat : start making indikating master/slave
110390 --	7376 77			-- : property indikating master/slave
110391 121102	7378t			-- : test use two pages
110392 --	7379			prm_pch_spi_xil : make delay betveen send bytes 5 mcs -> 1 mcs
110393 --	7380t			-- : property answer with xilinx ver 11
110394 --	7381			prm_pch_spi_stend : do not hangt - init buffers!!!!!
110395 --	7382			prm_pch_spi_xil : t 9 = 38 mks!!!! need check what print N if use paser cpi for usart
110396 121106	7383			-- : use_parser_spi t zan up 80 mcs - DO NOT USE NOW  N preintee when sended to spi 0x4e 	
110397 --	7384			md310e : indikate operate power mode to setbufferstate and clearbufferstate 									OPERATE_POWER_ON    (0x80000)
110398 121107   7385			md310e : use devid_crc to set default value for operating power im mod for ss 
						 reall work indikating 	OPERATE_POWER_ON
110399 --	7386 87	88		-- : prepared to can set operating power from jacke_mod
110400 --	7389			-- : do not read config_delta
110401 --	7390			-- : more short delay_read
110402 121108	7391			-- : do not operate power in multimode state
110403 121109	7392			-- : added return if operatepower disabledfrom incrementpower decrementpower and normalizepower
110404 121112 	7393			-- : more better operating power
110405  --	7394			-- : do not check crc to not hanging ethernet task
110406 --	7395			-- :" make task time 5 ms
110407 --	7396 97			-- : quick read errors period : 10  100
110408 --	7398			-- : was hangt that have loop to tranzit through kss == 7393 + no check crc
					     need make disabling power
110409 --	7399			-- : maked disabling power
110410 --	7400			-- : maked main task priortiy 4 (was 11)
110411 121114	7401			-- : enable irq0 at start main task and disable before end
110412	--	7402			pu_msat : can change date and month
110413 --	7403t			md310e : for test print interrupts qwantity every 100 ms
110414 --	7404			md34e : maked number .type = 0x14
110415 --	7405			md310e : temporary getting off irq limiting - xilinx is hangt - may be make support watch dog into irq to device will be not restarted????
110416 --	7406t	7407t 08		md34e : maked test print to eth
110417 121115	7409			md34e : not print make test mode 34
110418 --	7410			md310e : maked wd_reset in operating irq0 need check if have loops
110419	--	7411t 12 13			-- : have test print to debug init operating power mode
110420 --	7414			md34e : make counters += for statepum
110421 --	7415 16			-- : make more waitstates for read cs2 - need find minimum, make back not +=
110422 121116	7417 18 19 20 21	-- : do not enable overflow counters
110423 121117	7422t			md310e : make irq_limited limit : 100 irq to 100 ms  do not hangt!!!!!	(304 - hangt)	modem channel sometime lost	
110424	--	7423t			-- : every 50 ms enable 100 irqs
110425 --	7424			-- : enable 150 irqs v 587
110426 --	7425t 26t		-- : make formaket ALL_ADDR
110427 121119	7427			-- : disable irq_limited to going test transit (test mode 2)
110428 --	7428t			-- : makeenabling irq0 in testpu_37(); irq limit 10000 - all ok!!!!
110429 121120   7429t			-- : operating provingent to setting ethernet mode from command 0x57 from rnms
110430 --	7430			-- : set ethernet mode to commands do not have debug print
110431 --	7431			-- : try in irq0 disable all interrupts to check : may be ethernet will be not fall?
110432		7432			-- :  make timing xilinx 48 mhz!!!! do not hangt on new rnms
110433	121121	7433t			-- : use readed code to operate power have test print
110434  --	7434t			-- : use flag command operate power to not disable operate power to get off mode operate power to command
110435  --	7435			-- : added check crc on rs232
110436  --	7436t	37t 38t 39t	-- : start making USE_CALIBR
110437	121122	7440			commutator2(kss) : change init cs2 and cs3 to work without line NWAIT
110438  --	7441_calibr 42_calibr	43_calibr	md310e : use get and set calibr data, added second channel
110439  --	7444t 45t		commutator2(kss) : make test printing counter of receive packets
110440 121123	7446t			-- : make lower delay requests of antenna 250ms -> 50 ms
110441 --	7447t			-- : make delay betveen sending commands, but lasts will be higher because do not have buffer 
110442 --	7448t	49t		-- : do not use keep_ans
110443 --	7450t			-- declared buffer for command to antenna AMsgBuffer
110444 --	7451t	52t		-- insert receive command to antenn to buffer
110445 --	7453t			-- : not get off flagrequest
110446 --	7454 55			-- : get off test print interval 45ms
110447 --	7456			-- : keep flagrequest and addresses
110448 121126	7457t			-- : start making KSS_PRINT_LOG
110449 --	7458 59			md310e: get off tx for channel 2
110450 --	7460			pu_m_710 =md34e : make get off transmit channel2 and set filters
110451 --	7461 62			commutator2(kss) : can send answers from ups to arm.
110452 --	7463t			-- : have test print
110453 121127	7464t			md310e : --
110454 --	7465t			kss : make request as in modem
110455 --	7466t			-- : some print
110456 --	7467t, 68t		-- : good init pin pa31, and data rate of usart2
110457 --	7469t			-- : rnms -view answers!!!!!!
110458 --	7470			-- : without test print, ver 597; need view how work sending answers ups to transit - compare with modem
110459 121128	7471			-- : get off not needed printing ver 598
110460 121129	7472t			md310e : try reset wd in tcpip task ______________________________
110461 --	7473t	 7474t		maket md310e : print current address to getted memory to malloc()
110462 --	7475t			-- : view working ethprint
110463 121130	7476			md310e : right get off second pvg  710 
110464 --	7477t			-- : find tcpip loss : printing transmit status
110465 121203   7478t			-- : make ethernet priority lover as timer
110466 --	7479			-- : make irq0 priority lover as ethernet and timer v601
110467 --	7480t			-- : make enabling mask of interrupt after fill buffer to do not wait sending!!!!
110468 --	7481			-- : without test print v602
110469 --	7482			commutator2(kss) : timer had highest priority!! v602
110470 --	7483			pu_m_710 =md34e : --
110471 --	7484t			md310e : make limit to receive rs232: 16 Bytes/ms
110475 --	7485			-- : no debug print 
110476 --	7486			-- : do not enabling interrupts after fill buffer - 16000 interrupts v603
110477 --	7487			-- : more right fill buffers for modem and transit
110478 --	7488			-- : do not fill buffers
110479 --	7489t			-- : try make limit to transmit some to modem or tranzit - do not send some
110480 --	7490t	91		-- : make limit to transmit - 37 bytes/ ms
110481 --	7492t			-- : start making time limit to using transmit to modem and transit channels
110482 121204	7493t			-- : make channels time 15ms
110483 --	7494t			-- : 15 ms only for answers from buffer
110484 --	7495t			-- : add to 15 ms period to checking remote
110485 --	7496t			-- : channels and remote in 15ms timer
110486 --	7497t			-- : make rs232 limit 100Bytes
110487 --	7498t			-- channels and remote to 30 ms timer - irqs in loop - never 2100 / s
110488 --	7499t 7500t 7501t			-- : make transmit traffic print, get some from timer
110489 --	7502			-- : no limits good stat on 26 modems wrong work - tcp - lost!!!
110490 --	7503			-- : make task period 10 ms
110491 --	7504t			-- : try use buffer for receive in irq0 from modem channel
110492 --	7505t			-- : do not send status far end packets to transit
110493 121205	7506t			-- : test - no wd; maked wd for interrupts, ud1, ud2 - no buffers
110494 --	7507t			-- : make limit to rs232 traffic
110495 --	7508t			-- : any step
110496 --	7509t			-- : do not hangt tranzit while
110497 --	7510t 7511t		-- : disabled common modem interrupt in end of irq!!!!!
110498 --	7512t			-- : maked back clearing modem interrupt to have channel updown
110499 --	7513			-- : without test print
110500 121206   7514t			-- : hanging under rnms2!!!!! uswd while loop in interrupt
110501 --	7515t			-- : while only on receive
110502 --	7516t			-- : try mask transmit in tcp task
110503 --	7517t 18t		-- : no while; try make limit to data, received from ethernet tcpip 
110504 --	7519t			-- : disable interrupts into enet_isr()
110505 --	7520			pu_m710 =  =md34e: start find errors in second channel
110506 --	7521 7522t			md310 : tru set 10 ms to task
110507 --	7523t			-- : ipe_test_counter in ip_e.c get view of point to operating.	
110508 --	7524t			-- : try disable and enable interrupts when transmit in echosrv.c
110509 121207	7525t 26t		-- : try make irq0_limit 1000
110510 --	7527t			-- : buffers works!!!!! wiev printing wd! receive to one byte!!!!
110511 --	7528t			-- : try disable receive with period 1ms; need it disable in interrupt
110512 --	7529t 			-- : disable receive in interrupt - lost line
110513 --	7530t			-- : make using transmit buffers for ud1 and ud2
110514 --	7531			-- : no debug print disable receive every 1 ms
110515 --	7532	33		-- : using buffers version; can disable receive later and try limit irqs
110516 --	7534			-- : tested 1000 interrupts, proprty statistics
110517 121209   7535			-- : make operating mask transmit for channells ud1 and ud2
110518 --	7536t			-- : maked change receive : one time receive transit and ud1, one time receve modem and ud2
110519 --	7537 , 38t		-- : maked test print for check loss transmit
110520 --	7539t			-- : remowed from while checking buffers for transmit
110521 --	7540			-- : without test print v607 NEW XILINX NEED!!!!!
110522 --	7541			-- : do not send channel data to rs232 - to do not use BUS by memory
110523 --	7542			-- : answer to rs232 only if have request
110524 121210	7543			-- : temporary do not get off receive to not use stiopping receive to do not rewrite xilinx dmd 	
110525 --	7544 45t 46t		kss: start making using buffers in interrupt 	
110526 --	7547			kss : make using buffers in irqs
110527 --	7548			md310e : maked back addmod addtransit addud1 addud2
110528 --	7549			kss : --
110529 121211	7550			kss : use short addmod addtransit addud1 addud2
110530 --	7551			kss : get off usart when working with tcp
110531 --	7552			md310e : make using forwardingenabled() v611
110532 --	7553			pu_m710 =  =md34e: used buffers for receive and transmit
110533 --	7554			-- : get off usart when working with tcp
110534 --	7555			-- : use ForwardingEnabled() v 611. can in future use big receive buffers
110535 --	7556t			-- : maked debug print, forwarding disabled
110536 --	7557			-- : forwarding disabled buffering transmit off
110537 121212   7558tt			-- : maked bak ver 582 to work modem test
110539 --	7559tt			-- : used projekt 7557, change only embisr.cpp, embisr.h - test tranzit work!
110540 --	7560			-- : maked pragma #define TEMPORARY_DO_NOT_STOP_RECEIVE test modem work!!!! v612
110541 --	7561			-- : maked from 7555 forwarding disabled added #define TEMPORARY_DO_NOT_STOP_RECEIVE need make working test tranzit
110542 --	7562			-- : make working test tranzit hawe two answers from far end!
110543 --	7563			-- : have one answer from far end
110544 --	7564			-- : forwarding enabled use big buffers, need new xilinx _v613
110545 --	7565 66t		    pu_pm2 : start making this device.
110546 --	7567t			-- : removed thipty channel
110547 --	7568			-- : keep channells 1 and 4
110549 121213   7569			-- : maked init io pins for address
110550 --	7570			-- : maked reading rs485 address
110551 --	7571 72	73 74 75	-- : any step to make protokol
110552 121214   7576			-- : make going command 0x43 without keep and run, do not add 1 to crc 
110553 --	7577			-- : -- command 0x44
110554 --	7578			-- : -- command 0x48  
110555 --	7579 80			-- : make init commanddatalength, sended_ans
110556 --	7581t			-- : start test parsing
110557 --	7582t			-- : next step
110557 --	7583t			-- : property answer to command 0x43 have test print
110558 --	7584t			-- : celling commanddtalength
110559 --	7585t 86t		-- : property answer to command 0x44 one byte have test print, two 
byte
110560 --	7587t	88t		-- : property answer to command 0x48 one byte	
110570 --	7589t			-- : -- two bytes
110571 --	7590t			-- : maked setting freq to command pupm2	
110572 --	7591t			-- : maked setting att to command pupm2	
110573 --	7592t			-- : maked reading freq and att; need make reading type of prm and have prm
110574 --	7593t			-- : make reading have need make reading type
110575 --	7594t			-- : -- make reading type
110576 --	7595			-- : no debug print
110577 121217   7596t, 97		-- : some errors deleted , debug print, no debug print
110578 --	7598t 99t		md310e : check why modem loss tcpip : disabling interrupts?	
110579 121218	7600t	7601		-- : have stopping in loop!!!!
110580 --	7602			-- : make period up down 20 ms and requests of state between commands
110581 121219	7603			-- : check min power as 0 to do not decrement power
110582 --	7604			-- : code for min power 90; check crc of received data in updown channels
110583 --	7605			-- : clear flagformod
110584 --	7606 	07t 08t		-- : not can clear flag to can operating from arm, debug power
110585 --	7609			-- : do not get changing code ppd from zero
110586 --	7610t			-- : more print
110587 --	7611			-- : change table of input levels
110588 121220	7612			-- : make min power -5 for auto mode
110589 121221	7613t			-- : if rx buffer is not available rastart enabling receive and transmit!!! in interrupt
110590 --	7614			-- : make minimem enabled power with operate power +3 dBm
110591 121224	7615			-- : make enet interrupt idividual - not from timer in eninit.c
110592 121225	7616t			-- : maked setting pointer to buffer in tx catchup
110593 --	7617t			-- : maked underrun interrupt
110594 --	7618		     pupm2 : added 0x80 to number of type pm 
110595 --	7619			-- : maked mask 0xC3
110596 --	7620t 21t			md310e : try init rings if have underrun
110597 --	7622			pupm2 : use formula1L
110598 --	7623t			md310e : do not loss tx address loss rx
110599 121226	7624 25			pupm2 : change formula1L
110600 --	7626t			md310e : property go from underrun!!!!!!!!!!!!!!!!!!!
110601 --	7627			pupm2 : change formula1L
110602 --	7628t 29t			md310e : printtwo underruns state
110603 121227	7630t			md310e : any step to try do not hangt if have underrun
110604 121228	7631t			-- : do not hangt
110605 --	7632t			-- : do not receive something
110606 130109   7633t			-- : any step
110607 --	7634t	35t 36t		-- : make testmode 0x8c : txunderrun()
110608 --	7637t 38t		-- : view as hanging after discard packet
110609 130110	7639t 40t		-- : make rx ring length 1 (change 2 -> 1)
110610 --	7641t			-- : do not disable interrupts in enet_isr 
110611 --	7642t			-- : maked delay 50 mcs after start ethernet transmit pdc 7000000 irq0s!!!
110612 --	7643t			-- : try waiting to eth packet is sended to pdc before enabling interrupts
110613 --	7644			-- : one receive buffer,wait until is transmitted ethernet packet!!!! keep rnms2 
110614 130111	7645t			-- : make back delay 50 mcs - 89000000 do nat hangt after - hangt
110615 --	7646t	47t		-- : make back two buffers - do not fall from ping
110616 --	7648t			-- : fall from two starts rnms
110617 --	7649t			-- : delay 1 mcs 10000000 -ok with ping and three rnms 17 mln - fall
110618 --	7650t			-- : delay 3mcs
110619 130114	7651			-- : di not print from rtcs v625
110620 --	7652			kss : delay 75mcs in eth transmit
110621 --	7653			pu_m710 : --
110622 --	7654t			md310e : make delay 100 mcs after transmit eth
110623 --	7655t			--: print receive and transmit dete for transit
110624 --	7656t			kss : print requests for modem
110625 --	7657			kss : remove "else" from parser for flagrequest == 3;  
110626 --	7658			kss : make buffer for messages from rs232; cashe on
110627 --	7659			kss : cashe off best statistic
110628 --	7660			kss : cashe on
110629 --	7661			kss : cashe off
110630 --	7662t			md310e : test work with 100mcs
110631 130115	7663t			-- : more as 70000000 25 + 25 + waiting - task get off after swcond underrun
110632 --	7664t			-- : more as 93000000 30 + 30 + waiting 200 + check errors 
110633 --	7665			-- : compile without print v627
110634 --	7666			kss : --
110635 130116	7667			pu_m710 : --
110636 --	7668t			md310e: make more delay after start send packet
110637 --	7669t			-- : 200 mcs delay + 40 before - not hangt!!!!
110638 --	7670			-- : 175 mcs not hangt
110639 --	7671t			-- : 200 + 30 before
110640 130117	7672t			pupm2 : test version with using accumulator from command 0xc
110641 --	7673t			md310e : compiled with option temporary do not stop receive
110642 --	7674			-- : without debug options
110643 --	7675			kss : --
110644 --	7676			pu_m710 : --;
110645 --	7677t			pupm2 : changed formula1l
110646 130122	7678t			md310e : try get on mmu to work data cashe
110647 --	7679t			pupm2 : changed formula1l
110648 --	7680t			md310e : enable icashe, mmu disabled
110649 --	7681t			md310e : mmu enabled - do not work ethernet and not olweis answer usart
110650 --	7682t			-- : uncomment init_bmdn() - time1 - go!!!
110651 --	7683t			-- : uncomment bmdn() without interrupts - go!
110652 --	7684t			-- : if I do not cashe xilinx area - interrupts work!!!
110653 --	7685t			pupm2 : not used!!!! changed formula1l - not used!!!!
110654 --	7686t			md310e : dcashe getting off work quickly
110655 --	7687t			-- : cashes and mmu enabled - do not work dma operations - programm do not can be rewrited
110656 130125   7688t			-- : enabled only mmu and icashe; dcashe disabled
110657 --	7689			-- : work version with icashe v630 
110658 130128	7690			pupm2 : changed formula1l
110659 --	7691t 92t 93t		md310e : start making hot restart, now to 5s loss of lock
110660 130129	7694t	95t 96		-- : do not loss lock if restarted, v630
110661 --	7697			pu_m710 : --
110662 130130	7698			kss : get test 2 v631
110663 --	7699			kss : do not reload xilinx if work mirrortest v632
110664 130201	7700			md310e : work test transit v632
110665 --	7701			pum_710 = md34e : --
110666 --	7702			bmdn6 : compiled with all new changes
110667 130204	7703			pupm2 : changed formula1l
110668 130207   7704			md310e : mmu get off - better sttistics
110669 --	7705			pupm2 : changed formula1l
110670 --	7706			kss :  mmu get off
110671 --	7707			md34e: --
110672 --	7708			pupm2 : set zero freq if do not have prm; need add ret code0x4 if prm is 					off
110673 --	7709	10 11 12t	-- : can be print to test mode 50; ulock commands 30 and 31
110674 --	7713			-- : added CODE_NOT_CONNECT
110675 --	7715			-- : init Bufferanswer
110676 --	7716			-- : call prm_pch() before answer
110677 --	7717			-- : writing to channel 2 is correct - need use index 4
110678 130208	7718	19 20	21 22t	-- : any step  to parse command 0x44
110679 --	7723			-- : without test print and test att - for postavka
110680 --	7724t			-- : more correct write length
110681 --	7725			-- : no print
110682 130209   7726t			--: answer zeros if pm is off
110683 --	7727t			-- : correct write length to command 0x44
110684 --	7728t			-- : correct write addr for command 0x44
110685 --	7729t			-- : correct check command 0x43
110686 --	7730t			-- : any step to debug command 0x48
110687 --	7731t			-- : good crc in command 0x48 bu data[0] is not ok (used data[1])
110688 --	7732t			-- : correct testing command 0x48
110689 --	7733t			-- : without test parsing but with test att
110690 --	7734			-- : no test
110691 --	7735			-- : changed formula1 v 634
110692 --	7736t			-- : remove setting breakflag to 1 at start command 30 and 31
110693 --	7737			-- : witout test print
110694 130211	7738t			-- : have test print for set two bytes of freq
110695 --	7739t			-- : try use flags to set freqs to one step
110696 --	7740			-- : set freq to one step if shenged not one byte in freq value
110697 --       7741			-- : more good frint in test mode 0x50
110698 --	7742			-- : make some for brakflag4
110699 --	7743			-- : maked waiting one time if set channel 1 and 4
110700 --	7744 45t		-- : maked reading with lower delay do not setting to zero if prm 
				absend
110701 --	7746t			-- : maked setting to zero if do not have connected prm
110702 --	7747t			-- : maked do not set freq back if prm is connected
110703 --	7748t			-- : anverted alarm of prm and right set prm type
110704 --	7749t			-- : get type of prm not at start only
110705 --	7750			-- : maked checking addresses if was readed data
110706 130212	7751			-- : better maked runreading to do not set all data to zero 
110707 --	7752t			-- : correctly work command 0x44(write many bytes)
110708 --	7753			-- : without test print
110709 --	7754t			-- : make havefirstaddr as static
110710 --	7755			-- : no doing test print
110711 --	7756			bmdn6 : do not use mmu
110712 --	7757			-- : irq0 inverted!!!! zero - is active!!! v639
110713 130218	7758t			pupm2 : inverted having prm
110714 --	7759			 -- : correct set to command 0x43	
110715 --	7760			 -- : no test print v640
110716 --	7761			 -- : change att to << 3 v641
110717 130221	7762			 pu_msat : find server address
110718 --	7763			bmdn6 :  calibrate
110719 --	7764			md310e : --
110720 --	7765			-- : no calibr
110721 --	7766			pu_msat : now print ip address of call computer!!!! can be call tftp downloading from this ip addr
110722 --	7767, 68t		-- : can set parb
110723 130225   7769t			-- : add function to write files through web
110724 --	7770t 71t 72t		-- : can change program through web-interface!!!!!
110725 --	7773			bmdn6 : no calibr v643
110726 --	7774t			pu_msat : start try make reset of device to http
110727 130226	7775t			-- : added try rewriting xilinx
110728 --	7776t			-- : maked reset and rewriting xilinx - need check!
110729 --	7777t			bmdn6 : test printing
110730 130227	7778			pu_msat : changingxilinx and restart added to web interface and reset is checked
110731 --	7779			pupm2 : changed formula1l; v643
110732 130228	7780t 81t 82t		bmdn6: correctly print to usart names of config files and fv files
110733 130304	7783			prm_pch_l61 : are recovered commands 30 and 31 (with flash) 
110734 130305 	7784			-- : changed formula9
110735 --	7785			bmdn6 : print .fv file to view  v 644
110736 --	7786			md310e : --
110737 130315	7787			bmdn6 : work rezerving with no lock syntezer pd
110738 --	7788 89			prm_pch_l61 : new formula9
110739 130318	7790			bmdn6 : if readed code Pd byte[1] lower as 85<<1 - rezerving channel
110740 --	7791			prm_pch_l61 :  new formula9
110741 130319	7792			-- : remove printf
110743 --	7793			-- : make printing from first channel in test mode 0x50
110744 --	7794			-- : do not return from parsetcp in testmode50 to max have property answer
110745 --	7795			-- : changed formula9
110746 130405   7796t			prm_pch_spi_xil : compiled after some tome MAX_DATA_SIZE1 changed 10 to 20 why it is readed in two places ?
110747 130406   7797t			prm_pch_spi_xil : compiled for maket	
110748 --	7798t			prm_pch_spi_xil_eth : working with file prm_pch_spi_xil_eth	
110749 --	7799t			-- : find using tcp	
110750 --	7800t			-- : view in usart0 on rate 115200!!!! printing time and message about TCP 					when programm prmp4gt is connected
110751 --	7801t			-- : calling Operatebufeer() to deta from tcp; need make adding answer
110752 --	7802t			-- : sending answer to tcp buffer
110753 130408	7803t			pu_msat : start adding menu items
110754 --	7804t 05t 06t 07t 08t 09t 10t	-- : maked some for items SatDF and SatTF
110755 --	7811t make test print
110756 --	7812t			-- : right init remote command for sattf	
110757 130409	7813t			-- : maked full indikating time frame
110758 --	7814t			-- : correct satset3 - debug keys
110759 --	7815t	16t		-- : maked run loading wehen setted sattf or sattf
110760 --	7817t			-- : getted off item receive bound; transmit bound changed to Analog filter
110761 --	7818t			-- : more right load satdf to table : 9->a 10->c ...
110762 --	7819t			-- : modifyd http page
110763 --	7820			-- : no maket
110764 --	7821			prm_pch_spi_xil_eth : maked pragma for test print.
110765 --	7822			-- : no maket
110766 130410	7823			pu_msat : remove test mode 0x21 to not hangt on jackX3
110767 130412	7824t			-- : removed menu item debug mode
110768 --	7825t			-- : counted to rgstw bit 0x100 processing freq
110769 --	7826			-- : no maket
110770 130415	7827t			-- : removed menu item debug keys
110771 --	7828t			-- : debug keys setted in system menu group
110772 --	7829t			-- : no block menu ? - need do not blinked "B"
110773 --	7830t			-- : SatXilBlock.Value = 0 olwais
110774 130416	7831t 32t 33t		-- : removed item df	, placed to new place	
110775 --	7834t			-- : processing offset moved to processing freq
110776 --	7835			-- : no maket
110777 --	7836t			md310e : maked maket variant 
110778 --	7837t 38t 39t		pu_msat : start making SatRate.
110779 130422	7840t 41t 42t 43t 44t	-- : maked menu item SatRate
110780 130423	7845t			-- : maked item CusDet
110781 --	7846t 47t 48t		-- : analog filter moved, digital filter; 
110782 --	7849			-- : no maket
110783 130424	7850 51	52		pupm_3 : start making new device prm_pch + relay station  
110784 130425	7853 54			pu_msat : delete any error
110785 130516	7855t			mf20 : maked for maket; irq0 maked for can compile
110786 --	7856t 57t 58 59		pu_msat : start making Unlock Timer
110787 --	7860			-- : right celling to new rules
110788 --	7861	62		-- : new table, make version 656
110789 --	7863			-- : deleted some errors
110790 --	7864			-- : no use pragme maket_plata v657
110791 --	7865t			md310e : maket plata 
110792 130521	7866t 67t 68t		pu_m_V_A : start
110793 --	7869			-- : no maket
110794 --	7870 71 72		-- : many many delete
110795 130523	7873			-- : remove ful phone
110796 --	7874t			pupm3 : for maket, use checkparsingcommands use command 0x48, address 0
110797 --	7875t			-- : more property print
110798 --	7876t			-- : all commands checked; maked with pragme "Test Print SPI"
110799 130527   7877t			prm_pch_spi_xil_eth : maked zero address, it do not read from xilinx, for maket, test parsing commands usart rate 115200
110800	--	7878t			-- : no test parsing commands ; only test print spi; print time olwais
110801	--	7879t			-- : receive command 4 from ethernet; need check answer
110802 --	7880t 			-- : maked setting timerun - view any answer; need add breakflag
110803 --	7881t			-- : added breakflag maked for maket
110804 --	7882t			-- : no maket, used test_print_spi
110805 --	7883			-- : no maket full version
110806 130531	7884			prm_pch_l61 : mask for devices 0x3=> 0xC3 v657 	
110807 --	7885			prm_pch_spi_xil_eth : cleared functions set line to one, setline to zero...v658
110808 130620	7886t 87t		-- : start debug as working prm20_70000MHz.exe
110809 --	7888			-- : use address 0xf
110810 --	7889			md310 : start find of do not change frequensys af pd and pm
110811 --	7890			-- : get off send_keeper1 and 2
110812 --	7891			-- : commands to freq get off power mode
110813 130624	7892t			-- : start making buffer embmsg485 for updown channel 
110814 --	7893t			-- : maked adding commands for updown to buffer
110815 --	7894t			-- : maked getting from buffer to first channel
110816 --	7895			-- : make operating power using buffer v661
110817 --	7896			-- : get back send_keeper1,2 v662
110818 130625	7897t			prm_pch_spi_xil_eth : try make low rate for loading xilinx
110819 --	7898t			-- : print time
110820 --	7899			-- : load 100000 bytes of xilinx - finish load before restart of watch dog v663
110821 130626   7900			bmdn6 : make operating power using buffer
110822 --	7901t			pu_m710 : declared EmbMsg485Buffer
110823 130627   7902t			--: add to buffer commands to updown
110824 --	7903			-- : get from buffer commands to up down v663
110825 --	7904			-- : use send keepers v664
110826 130628	7905			prm_pch_spi_xil_eth : pack before holiday
110827 130712	7906			-- : pack after holiday
110828 --	7907 			-- : disabled irq0
110829 --	7908			-- : packed with have in direktories full file work1
110830 --	7909t			-- : use address 0x8f - ok selftesting
110831 --	7910t			-- : chenge setruncommand to runcommand - many commands runned momentally
110832 --	7911			-- : without test print v665
110833 --	7912			pu_m_V_A : make working with mask bit in interrupt to transmit
110834 130729	7913t	14t		-- : start making operating io pins 96 output 97 to input for test mode
110835 --	7915 16			-- : maked operating pin96 from reading state of pin 97
110836 130730	7917			-- : test_ustir can be setted if programm write low bit 1 to port 					     50 protokol use embedded protokol
110837 --	7918			-- : can view testing ustir in signature_hardware[0] bit 0
110838 --	7919			-- : can be setted testing ustir in test mode 22
110839 --	7920			pu_m_v : maked xilinx size up to 550k
110840 130801	7921			pu_m_Mux : maked xilinx size up to 650k v667
110841 130802	7922			pu_m_e : recompile with big xilinx size v667
110842 --	7923			pu_m_mux : make property addmod addtransit addud1 addud2
110843 --	7924			pu_m=pu_m_e : --
110844 130804	7925			pu_m_mux : do not disable receive in modem channel v669
110845 --	7926			pu_m : --.
110846 --	7927			pu_m_mux :" rnms do not broke ip. v670
110847 --	7928			pu_m : --
110848 --	7929 			-- : have gateway v671
110849 --	7930			pu_m_mux : --
110850 130805	7931t 32t 33t 34t 35	pu_m_V_A : make init pins for att operating att in port 51
110851 --	7936			-- : maked bit2 in signature hardware0 if setted programmly test ustir 
110852 --	7937			-- : maked different working for pd and pm att -for pm; gen for pd
110853 130807	7938 39 40		-- : delete some errors
110854 --	7941			-- : make types 903 and 904
110855 130808	7942			-- : change operatingg att 0->3 to 3->0 v673
110856 130809   7943t			-- : start making buffer for messages to edik
110857 --	7944 45			-- : maked buffer for mesages to edik
110858 130826	7946t			commutator_kss : add check crc to messages ost west north and south
110859 --	7947t			-- : to rs232
110860 --	7948t			-- : to rs232s
110861 --	7949			-- : make right celling and check crc
110862 --	7950			-- : added three times reading config 
110863 --	7951			-- : more right init transit messages
110864 --	7952			-- : do not use pragma witout xilinx => work transit v674
110864 130827	7953			md310 : added three times reading config 
110865 --	7954t 55t 56t 57	pu_m710=md34e : -- + start making checking crc correct command 0x22
110866 --	7958			prm_pch_spi_xil_eth : maked init Filtr
110867 130829	7959t			maket_kss : kan print points.
110868 130903	7960			prm_pch_spi_xil : maked init Filtr
110869 130912	7962			prm_pch_spi_xil_eth : meked resed_wd() before runcommandssc2; DELAY_TIME_TO_WRITE maked 					10 sec v 675
110870 --	7963			-- : make delay 5 sek
110871 --	7964t 65t 66t	67 prm_pch_l61 : start making second byte for type of prm
110872 130913	7968			prm_pch_spi_xil_eth : delete error to do not work usart0
110873 130916	7969			prm_pch_l61 : changed formula9
110874 130917	7970			commutator2 : maked init needwritedevid. v677
110875 --	7972			-- : disable test mode 0; return from write dev id if do not start main loop
110876 --	7973			-- : do not write two times
110877 130918	7974			-- :olwais do not run my commands on usart1, usart3
110878  --	7975			-- : writing to flash maked with checking 3 times if not sucsessful
110879 --	7976t	77		-- : maked read_flag for indikating reading parameters
110880 --	7978			md310e : without interrupts - not need
110881 --	7979 			bmdn6 : -- used for satellite modem
110882 --	7980			commutator2 : do not check data when write into flash
110883 130919	7981			-- : make check writing into flash
110884 --	7982			prm_pch_l61 : changed formula9
110885 130920	7983 84			md310e : make testmode 0xc9 - destroy configfile 0 + make check writing into flash
110886 130923	7985			-- : if have bad crc default set netmask only v681
110887	--	7986			commutator2 : --
110888 130925	7987			pu_m710=md34e : --
110889 130927	7988			prm_pch_l61 : changed formula9 up to 72 MHz + some changes
110890 --	7989			-- : changed f9.
110891 130930	7990			-- : used formula 25
110892 131004	7991t 92t 93t		-- : maket : try to use checksum
110893 131007	7994			-- : write parameters one time
110894 --	7995t			pum_v_a : maket  - start add crc
110895 --	7996			-- : used crc in msg232
110896 --	7997			-- : get off from embisr all about tranzit and modem
110897 --	7998			-- : getted off channel ud2
110898 --	7999			-- : maked interval 75ms
110899 131011	8000			prm_pch_l61 : formula 29
110900 131014	8001    		--	    : formula 30
110901 131016	8002			-- : formula33
110902 131017	8003 4			-- : formula35 36
110903 131018	8005			md310e : get off lock if device did not answer
110904 131021	8006t			-- : start make restart if pvg610 do not answer
110905 131021	8007t			-- : maked test mode 0xcc
110906 --	8008			-- : do not test print restart after 1 min not answers
110907 --	8009			-- : check syntezer
110908 --	8010 11			-- : check pvg710
110909 --	8012			-- : print to usart if restart
110910 131028	8013 14			pum_v_a : do not use generator, pin96 olwais zero
110911 131106	8015t			-- : start try crash input channel by random data
110912 131111	8016			prm_pch__l61 : maked writedevid2
110913 --	8017t 18t 19t 20			-- : start make readdevid2; maked writedewid2
110914 131113	8021			-- : proprty keep freq in self place
110915 --	8022t			prm_pch_spi_xil_eth : start making keep freq in self place
110916 --	8023t	24 25 26 27		-- : modified writedevid2
110917 131114	8028			-- : keep freq in self place
110918 131121	8029			prm_pch_spi_xil : maked check seted freqs
110919 --	8030			-- : inverted answrs flags of attenuators and of alarm
110920 131122	8031			prm_pch_spi_xil_eth : --
110921 131125	8032			prm_pch_spi_xil : if wrong freq - do not set and make flag
110922 --	8033			prm_pch_spi_xil_eth : --
110923 131127	8034 35			prm_pch_spi_xil : maked checking attenuators; filter and rejektor
110924 --	8036			prm_pch_spi_xil_eth : --
110925 --	8037			prm_pch_spi_xil : delete error to use for att3 bound of att2
110926 131202   8038			prm_pch_spi_xil_eth : delay time maked zero TIME_WAIT_SPI_ETH; filtr correct values 0 and 1
110927 --	8039			prm_pch_spi_xil :filtr correct values 0 and 2
110928 131205	8040			bmdn6(act15505) : recompiled.
110929 131206	8041t			-- : maked test printin in operate eth
110930 131209	8042t	43t		prm_pch_spi_xil : do not ansver to addr 0xf, answer to addr 0x8f
110931 131211	8044t			pupm2 : maket : imitate three commands to set freq and request it
110932 --	8045t			-- : imitate command 44
110933 131212	8046t			-- : make i - lokally declared to property work imitating some commans
110934 131213	8047t			prm_pch_spi_xil_eth : start make TWO_RECEIVERS
110935 --	8048 49			-- : maked  TWO_RECEIVERS added using command 22 = 20 for second receiver
110936 131217	8050			-- : start making options generator
110937 --	8051			-- : adding generator to command 4
110938 --	8052			-- : adding command 9 - setting on generator	
110939 --	8053			-- : added command 23
110940 --	8054			-- : invert attenuator bits
110941 -- 	8055			-- : added command 9 to protokol rs485
110942 --	8056			bmdn6 : try use 1 freq mode
110943 131224	8057			prm_pch_spi_xil_eth : recompiled to property work to ethernet - v707
110944 --	8058t			-- : maket maked init commanddatalengt for command 9
110945 --	8059t			-- : maket : work command 9
110946 --	8060			-- : not for maket ver 708
110947	--      8062			-- : disable massive CommandDataLength - need check
110948 131226	8063			bmdn6 : getted on tx 1 in pvg710
110949 --	8064			prm_pch_spi_xil_eth : get off command 8 if used add table
110950 131227	8065			bmdn6 : start changing rezerv mode for channel 2
		_66 _67			-- : enable phone in init
		_68			-- : load two times second channel
110951 140117	8069			pu_msat : start changing
110952 --	8070			-- : delete error to group set sattimer (unlock timer)
110953 140122	8071			-- : all prepared to receive from rs485 byte 0x71 - informatin about lock
110954 --	8072			md310e : start making state of modem lock to rs485
110955 --	8073			md310e_sat : start without interrupts and send mod lock to rs485
110956 --	8074			-- : make sending every 20ms 0x71 if lock and 0x44 if unlock
110957 --	8075			pu_msat : next step to make receivelock from modem need only add writing to xilinx
110958 --	8076t 77t			-- : maket any step to make new menu items
		78t			-- : added keep in flash
		79t 80t			-- : making checking values SatExtLock
		81t			-- : all prepared : need only maked menu items and make finish funktion
		82t			-- : maked operatig with bit 4
		83t			-- maked some for menu items
		84t 85t	86t 87t		-- --
		88t			-- do not hangt if set write size not + 100
		89 90			-- not maket; can keep data
110959		91 92	93t 94t 95	-- start making satlowp
110960		96			md310_sat : do not restart if have error


110961		97 98 99 100 8101	-- : as bmdn6; work changing eth rate; load one prowingent
110962 140203	8102t			pu_msat : start make menu item "serial number"
110963 --	8103t			-- : serial number : next step
		8104t 05t 06t			-- : start making satalev
		07t			-- : satalev operates satrate
		08t 09t 10t 11t	12t	-- start making access code demo mode and access cnt
		13t 14t 15t 16t
110964		8117			- not maket
110965 140212	8118 19	20 21 22 23 24		- start adding to modem operating of acm modes
110966 --	8125t			pu_msat : maket make debug print for sat_lock
110967 140213	8126			--: maked soma for property works menu item setextlock
110968 140214	8127			md310_sat : maked delay 4 seconsto set acm
110969 140226	8128			pu_msat : is corrected table of unlock-timer
		8129	30		-- : if not in lock printed n/a if balance
110970 140227	8131 32	33 34		-- : any step to make slave level
110971 140228	8135			-- : try to keep satacode
		8136			-- : not need keep satcode; to do not reset satalev need do not callsatdemo at start
		8137	38		-- : remove some prints
110972 140303	8139	40		-- : if change data rate - it really checked
110973 --	8141t	42t 43t 44t 45t	46t 47 48-- : start making pu_m_mux with operating trunks
110974 140311	8149			prm_pch_spi_noxil_eth : start projekt
110975 --	8150 51	52 53 54 55	-- : maked io set att3, all atts, all ios
110976 140326	8156 8157		-- : start making init_ios_noxil()
110977 140409	8158			md310e : maked do not alarm restarting if pok is not 0x1000.
110978 --	8159			bmdn6 (act15505) : --
1109   140414	8160 61			bmdn6m (gybrid) : start	
		8162 63	64		-- : not can set one trunk mode and do not use phone
1110  140416	8165			prm_pch_spi_xil_eth : added gateways
		8166			prm_pch_spi_noxil_eth : --
1111  140417	8167			prm_pch_spi_xil_eth : do not keep params to do not lost flash
1112  --	8168			prm_pch_spi_noxil_eth : --
1113  140418	8169			pu_m710=md34e : maked bigger xilinx size
		8170			prm_pch_spi_xil_eth : disable ints when write dds and make back keep params
		8171			prm_pch_spi_noxil_eth :  --
1114 140421	8172			-- : keep attenuators
		8173			prm_pch_spi_xil_eth : --
1115 140424	8174			prm_pch_spi_xil_eth :soft res dds
		8175			prm_pch_spi_noxil_eth : --
		8176			prm_pch_spi_xil : try make keep params and reset dds
		8177			-- : delete some error v 731
1116 140425	8178			prm_pch_spi_xil_eth : version with no gateway
1117 140428	8179			prm_pch_spi_noxil_eth : invert registers
		  80			-- : start - some work
		  81			-- : atts - ok
1118 140429	8182			-- : do not have pb0 as multidrive; no xilinx no ints v737
		  83			-- : att3 maked invert - calibrating ok v738
1119 140507	8184 85			-- : maked test mode 0xce : check all io pins v 739
1120 140507	8186			pu_m_v_a : maked pin 89(PB9) inverted to pin 96
1121 140513	8187			prm_pch_spi_noxil_eth : maked full loading dds every setting freq v740
1122 140514	8188			prm_pch_spi_xil_eth : version with gateway
1123 140520	8189t			pu_msat : start making changing web interface
1124 140521	8190t			-- : temporary get off web password
		91t			 : maked file web_pum_sat.cpp
		92 93			 : view that file is writed
1125 140522	8194			: tested changing programm
1126 140523	8195 96			: add some items and second page
1127 140526	8197 98			: added css do not work in explorer work in opera
1128 140528	8199			: start making class web_prm
1129 --		8200			: maked void target
1130 --		8201			: do not work indikating slave and writing xilinx
1131 --		8202t			: with old one page master/slave radio butoons work!
1132 --		8203			: master/slave changed; 
1133 140529	8204 05			: can select page number
1134 --		8206			: start making parse page update
1135 140530	8207			: page update - working!
1136 --		8208			prm_pch_spi_xil_eth : added reset to register 12
1137 --		8209			pu_msat : makes slave level, but on page view some wrong data if ping "set"
1138 140601	8210			prm_pch_spi_xil_eth : maked right check loock for ipaddress0, ip1, ip2, ip3
1139 --		8211			-- : changed place for keep freq : 0xc0500000  wrong load!!!!!
1140 --		8212t			-- : no keep freq
1141 140602	8213			-- : LONG_ETH, keep frq, no gateway
1142 --		8214			-- : check programm address in operating file - lawer addresses are wrong
1143 --		8215			-- : network mask keep property if version with no gateway to get version with gateway
1144 --		8216			-- : do not write something at start. this keep projekt is as before max tray do something
1145 --		8217			-- : need key5 for ip address changing and remove rs232 protokol for servicepack - to do not can changing ip v_749
1146 --		8218t			-- compiled file without pragmas
1147 --		8219			prm_pch_spi_noxil_eth : remove rs232 stack commands
1148 140603		8220			-- : maked return from Remote_PRM_PCHS
1149 --		8221			-- : remove keeping frequency
1150 --		8222 -			wrong do not loaded xilinx			-- : clear some text
1151 --		8223			-- :  get off all testmodes
1152 140604	8224			prm_pch_spi_noxil_eth : --
1153 140605	8225			prm_pch_spi_xil_eth : keep params in c0300000 v752
1154 140606	8226			prm_pch_spi_noxil_eth : add delay before load all
		8227t	28 29		-- : prepared for test reading
1155 140609	8230 31	32		-- : this version can some read - after any time work!
1156 --		8233			-- : if read in testmode 0x30 get some 0xff
1157 140610	8234			prm_pch_spi_xil_eth : : prm pch restart if do not have net activity
1158 --		8235			-- : try send trap
1159 --		8236			-- : try send ping - ok!!!!!!!!
1160 --		8237			-- : ping self address after half timeout for restart
1161 --		8238			-- : if restart tio rtcs do not reload freq
1162 --		8239			-- : maked control of tcp task with restart in mode 0x8e
1163 140611	8240			-- : for non -maket plata v753	
		8241			prm_pch_spi_noxil_eth : -- 	
1164 140616	8242			-- : wait while pdc counter will be zero v754	
1165 --		8243			pu_msat : any step - view that nothere is setpar00a
1166 --		8244			-- : work setpar00a
1167 --		8245			-- : slave level work
1168 --		8246			-- : try make external lock
1169 140617	8247			-- : work external lock and enover items 
		  48			-- : any step to make normal / invert
		  49			-- : work external lock polarity normal / invert
		  50			-- : work menu item alarm
		  51			-- : can view some on time frame
1170 140618	  52			-- : any step with time frame
		  53			-- : time frame is controlled
		  54 55			-- : any step to try use select input type in form of web page
		  56			-- : property parse page for insert data values
		  57			-- : time frame work!!!!!
1171 140619	8258			-- : work item low power
		8259			-- : maked satrate
1172 --		8260			-- : make index page as login page
		8261			-- : removed setting password from configuration page
1173 140620	8262 63			-- : start making analog filter
		64			-- : digital filter
		65			-- : unlock timer
		66			-- : processing frequency; started processing offset
1174 140623	8267			-- : work processing offset
		8268			-- : maked frequency offset on page indication
		8269 70			-- : make some for indication
1175 140624	8271			-- : temporary finished page indikcation without n/a
		8272t 73		prm_pch_l61: start making command for pin121, maked command 0x0f (15)
		8274			pu_msat : start making page system
		8275			prm_pch_l61: start making command for pin121, maked command 0x0f (15) and keep
		8276			-- : maked control of ethernet
		8277			-- : really keep SourcePCH
		8278			pu_msat : maked xilinx file name in page system
1176 140625	8279			-- : maked serial number in page system	
		8280			-- : access level
		8281			-- : access code
		8282			prm_pch_l61: inverted bit of command for pin121
		8283			pu_msat : demo mode
		8284			-- : demo mode timeout
		8285			-- : start making page log
1177 140626	8286			-- : maked start event
		8287			-- : clear log
		8288t 89 90		-- : some results in printing log
1178 140627	8291			-- : print page
		8292			-- : print two events
		8293 			-- : work page log
		8294			-- : addeded time to page system
1179 140630	8295			-- : can view ip address
		96			-- : any step to make web password lost wiew of serial number
		97			   : web password is setted
		98			   : can set ip address
		99			   : maked page index
		8300			   : page log
		8301			   : page update
		8302			   : page indication
		8303			   : page custom details
		8304			   : not maket ; password - on
1180 140701	8305 06			-- : right maked getting password in web; minimize print
1181 --		8307			bmdn6mi - wrong : start make sat modem with indikator and web interface	
		8308t 09t 10t 11t 12t 13t 14t	...27		-- : reduction size; maked from WRONG PROJEKT!!!!
1182 140702	8328t			PROG_MD310_SATI : start from rigt sources md310 sat
		8329			-- : minimize size
		8330			-- : first step to add indikator
		8331t			-- : first step to add http - do not compiled full
		8332t			-- : start making http : 398k bin file!!!!!!!
1183	140703	8333t			-- : change some in modem web page
1184	140704	8334t 35t 36t		-- : change place for xilinx to 0xC0700020
1185   --	8337t 38t 39t 40t 41t 42t 43t 44t	-- : modify web page to clear from pum variables
1186 140707	8345t			-- : next step
		8346t			-- start working with file menu_310s.cpp
		8347t			-- : if getted off using test mode 0x20 - rempult work and full work system menu
		8348t			-- : proprty init variables for checkcod; need finf :why they arent init before work page system
1187 140708	8349t 50		-- : make some for new items
1188 140709	8351t 52t			-- : --
		8353			-- : maked modulator conf and demodulator conf
		  54			-- : common, interface modtest
		  55			-- : maked some for config file
		  56			-- : can view number of config file
1189 140710	  57			-- : can change value of config file on indikator
		  58			-- : can change config file
		  59			-- : start working with namesconfigfiles
1190 140711	8360			-- : use NAMES_LEN.
		8361			-- : start making fillmenu -names of config files for indikator need set quantity of items in funktion
		8363			-- : right set quantity; - need init at start programm and keep it to indikation
		  64t			-- : at start menu of file names is setted to property state
		  65t			-- : can set some of configfiles from menu but it do not keept!!!!
1191 140714	8366			-- : cinfig file keeped but why first is zero?
		  67			-- : add item rf output
		  68 69			-- : add some items for tx
1192 140715	8370			-- : --
		8371 72 73		-- : add some items for rx
1193 --		8374 75			-- : add some for interface
		8376			-- : -- for monitoring
		8377			-- : --
		8378			-- : --
		8379 80			-- : start making monitoring ethernet
		8381			-- : maked some for firmware ver; need remowe address for uaret and make save/load
1194 140717	8382			-- : maked menu item saveload
		8383			-- : maked some for variables save load
1195 140718	8384 85			-- : can set params save and load
1196 --		8386			prm_pch_l61 : software[12] - do not <<1 
		8387			-- : fill sofware[0] ... answers for command edik20 - max command 3
1196 140721	8388			PROG_MD310_SATI : are removed some functions
		8389 90			-- : start with fillconfig
		8391			-- : all prepared to debug writing and loading configs
		8392			-- : viev property printing of two params.
1197 140722	8393			-- : all prepared to working with reading anyconfigs
		8394			-- : view in anyconfigfileaut answer in window!!!
		8395			-- : in test mode 0x75 - printed that anyconfigs are filled property!; answers to remote commands - ok to usart
		8396			-- : if save - fill anyconfi to it full value symbols '.' - to if read then have full file
		8397			-- : from this version are readed four configs
1198 140818	8398			pum_mux : use mirrortest for enabling interrupts!
1199 140819	8399			-- : do not break from loading xilinx if have done
1200 --		8400			-- : set testmode = 1 before enabling interrupts
1201 140820	8401			-- : get back test mode 0x36 - it used in jackx3
1202 --		8402			pu_msat: make reset of pult
1203 --		8403			-- : ring two times at start
1204 140821	8404			PROG_MD310_SATI : start after holiday
1205		8405			-- : start making firmfiledata
1206 140822	8406 07			-- : next step, can view firmware ver
1206 --		8408			-- : added some variables to will be us they in menu
1207 140825	8409			-- : started making mrfoutput
		10 11			-- : some for outlev
		8412			-- : mtdrate
		8413			-- : mrdrate
		8414			-- : txfreq and rxfreq
		8415			-- : all for modulator and demodulator
		8416			-- : some for eth
		8417			pum_mux : really write to flash testmode  = 1 - remowed checking start_main_loop 
1208 140826	8418			-- : more seldom operate updown and read static ram
1209 --		8419 20			PROG_MD310_SATI : add two data objekts for ethernet
1210		8421 22			-- : start making indikation
1211 140828	8423t			-- : add two items - do not work key "esc"!!!!!!
		8424			-- : work all? - change jacke prog size and direktive prog1 maked
		8425			-- : property indikated ber in format "e"
		8426			-- : start adding last menu objekts
		8427			-- : all menu items fulled
		8428			-- : make some for html interface
1212 140829 	8429			-- : --	
1213 140901	8430			-- : work page login
		8431			-- : make property names in web pages and parsing pages to first name in page 
1214 140902	8432			pu_msat: maked init_alarms_pins
		8433 33t 34t		-- : maked setting line norma and getting line lock
1215 --		8435			-- : maked getting lock to line OLOCK and added commands number 0x60 - read dev1 and number 0x61 - write dev1
		8436			-- : add new memmbers to struct dev1
		8437			-- : add some to fillclasses()
		8438			-- : finish remote
1216 140903	8439			-- : webpassword in dev1 is inited from flash at start
		8440			-- : property indikation
		8441			-- : delete wrong symbol from indikator
		8442			PROG_MD310_SATI : maked indication MEthModeI on web
		8443			-- : maked indikation sended and received packets on web
		8444			-- : time frame work property
1217 140904	8445			pu_msat: repaired some in web interface
		8446	8447		-- : start making indication of external lock
		8448			-- : delete error with lockstate
		8449			-- : olwais is default netmask!
		8450		PROG_MD310_SATI : try add support at45641e
1218	140905	8451		-- : web indilation ebn0 and tebn0
1219	--	8452		pu_msat:  deleted some web error' add indikation of program version	
1220	140909	8453		PROG_MD310_SATI : pack before adding adesto
1221	--	8454		-- : added pragma ADESTO - non-maket plata
1222	140910	8455		-- : added web indication of modem configfile
		56 57 58 59		-- : modulator	
		8460 61		-- : can view modulation
1223	140911	8462t		-- :  without adesto - load syntezer
		8463		-- : property maked modulato code rate
1224 	140912	8464t		-- : add reset of pult. - do not writed ?
		8465		-- : maked modulator freq
		8466		-- : maked some for demodulator page
1225	140915	8467		-- : maked indicatiion of test page
1226	--	8468		-- : added item acm mode
1227	--	8469		-- : acm mode added to web page
1228	--	8470		-- : any step to load xilinx property address and size
1229	140916	8471t		-- : any test version for try loading xilinx
1230	--	8472		-- : option "without xilinx" need remove pvg 710
		8473		-- : removed pvg710 : init; temperature and filters
		8474		-- : maked some for modulator and demodulator menu items
		8475		-- : make littles delay in loading xilinx to do not hangt if wrong xilinx
		8476		-- : and maked ethernet conf
		8477		-- : add type of plata 0xC1
		8478		-- : can be rewrited typical jacke - make size self!!!!
		8479		-- : start changing menu momitoring modem
1231  140918	8480 81	82	-- : --
		8483 84	85	-- : moving tber and tebn0 to demodulator config
1232 140919	8486		pu_msat:  access level is do not lost if was setted demo mode 	
		8487			: reremoved test item and address485 item
		8488		-- : right web interface
		8489		-- : network mask olwais set as default
1233 140922	8490		PROG_MD310_SATI : any step in web interface
		8491 92		-- : --
		8493 94		-- : ethernet config7uratiom works
1234 140923	8495		-- : monitoring modem works
		8496		-- : can set tx freq
		8497		-- : can set rx freq
		8498		-- : make some for test conf; do not can get off all params
		8499		-- : page test works
		8500		-- : start making page modem needmake view acm mode
		8501		-- : can set acm mode
		8502		-- : can set eth mode
		8503		-- : up to vlan priority
		8504		-- : ethernet config can be set i web to pult
		8505 06		-- : start making page save_load
1235	140925  8507		-- : save_load working
		8508		-- : cler log working
1236	--	8509		pu_msat: work web clearing log; netmask operated but do not used 
		8510		PROG_MD310_SATI : some better in web pages
		8511		-- : add firmware and if module versions to web
		8512		-- : if module to menu
1237	--	8513		-- : get off items test and rs485
1238	140926	8514		-- : start making bits to setting parameters
		8515 16		-- : maked some for unmodul and ifloop
		8517		-- : maked setting config file
		8518		-- : maked setting bits from web page
		8519		-- : maked templates for future operating funktions; need make keep parameters; load xilinx, 				    	-- : write - read if module and some operating funktions
1239	140929	8520		-- : all prepared to keep parameters in flash
		8521		-- : property compiled
		8522		-- : maked struct for remote
		8523		-- : added commands 0x71 and 0x72
		8524		-- : make some for this commands
		8525		-- : maked setting modeth
1240	140930	8526		-- : some parameters getted from remote	
		8527		-- : make som in "set functions"
1241		8528		-- : start continue save/config	
1242	141001	8529		-- : keep and restore config
		8530		-- : -- modeth
		8531t		-- : hangt if enable writing params!!!!!
		8532		-- : not hangt
		8533		-- : any step load/save
		8534		-- : ethmode->control do not work, keep in flash work
		8535		-- : control af value ethmode work property
		8536 37		-- : mrfout: save/load + control
1243	141002	8538		-- : outlevel keeped
		8539		-- : transmit freq keeped
		8540		-- : receive --
		8541		-- : make some for init strukts
		8542 43	44	-- : -- for check parameters
		8545 46		-- : maked saving to anyconfig and reading from
1244	141003	8547		-- : remove ip address from config
		8548		-- : remove '=' from configs - full config is keep! property work with anyconfigfileauto
		8549		-- : maked keeping up to 10 configs
1245	141006	8550		-- : if save all - readded all configs; full file size 2000 bytes!
		8551		-- : maked factory settings
		8552 53		pu_msat: netmask and ip address can be changed with key 5
		8554		PROG_MD310_SATI : set params of ethernet
		8555		-- : added carrieroffset or sweep
		8556		-- : maked MAGC
		8557		-- : maked MEbN0
1246	141008	8558 59		-- : first step to make ber
		8560 61	62	-- : start making request ethernet statistics
		8563		-- : added api for net pause and vlan
1247	141009	8564		-- : maked setting from menu eth pause and vlan priority
		8565		-- : maked setting max frame and inband control
		8566t		-- : if use draws : view journal; but first time journal do not viewed
		8567t		-- : view inited at start strings of journal
		8568t		-- : log can be cleared and property operated up down
		8569		-- : maked maket of new struct of config file - in future need change REAL_SIZE!!!!
		8570		-- : acm_status keept in global variable
		8571 72		-- : try use acm_status
		73		--: fillclasses changed
1248 141013	8574		-- : use celling dones for send and received frames
		8575		-- : maked some for objects receivedcrc and sendu
		8576		-- : maked menu items--	
		8577		-- : maked send and received packets
		8578		-- : all prepared to get ifmoduledata to request
1249 141014	8579		-- : can read ifmoduledata from common flash
		8580		-- : try make ifmoduleheader
		8581		-- : can view ifmoduleheader
		8582		pu_msat:  more right work with log
		8583 84	85	PROG_MD310_SATI : start making mtcode mtmodul....
1250 141015	8586 87 88 89	-- : --;
		8590t		-- : try make CdType
		8591		prm_pch_l61 : new formula9 : formula37 - wrong
		8592 93		PROG_MD310_SATI : any step to make MTCdType
		8594 95		prm_pch_l61 : new formula9 : formula37_1 - wrong
1251 141016	8596		PROG_MD310_SATI : get back on supporting commans operating ip address netmask and network on 					parser s3 - to can operate it to ethernet
		8597		prm_pch_l61 :  --  
		8598		pu_msat: --
		8599		PROG_MD310_SATI : property web view code type
		8600		-- : indicator work!!!!
		8601		-- : add channel to write if in  WriteReadSpiBm
1252 141017	8602		-- : start making mtmode, mrmode
		8603		-- : mtmode and mrmode added to pult menu.
		8604 05 06	-- : -- to web menu
1253 141020	8607		-- : out level -3,0 is viewed in web page property
		8608 09	10	pupm2 : new formula 1L
		8611		PROG_MD310_SATI : print saving events - wrong addresses
1254	141021	8612t		-- : comment update1 : have manu events but event pover off do not keept
		8613t		-- : make power on ewent first and only it update address before writed to keep event power 
on

21255	--	8614		mf20 : try recompile
		8615 16	17 18 19 baco : first step
		8620		-- : start for remote commands
		8621		-- : maked strukt baco
		8626		-- : support load start bits
		8627		-- : work version
		8628		-- : use indirects addresses
		8629		-- : start making tcp commands	
		8630		-- : work first command
		8631		-- : support command 2
		8632		-- : support command 3
		8633		-- : support command 4
		8634		-- : set device type of BACO
21256	141022	8635		PROG_MD310_SATI : remove unused test print
		8636		-- : property cleared yournal
		8637		-- : can acm enable/disable
		8638		-- : set acm mask on transmit or receive
		8639		-- : some params are readed to api commands and set to menu
		8640		-- : can viev current acm mode
		8641 42		pu_msat: property cleared yournal
		8643		PROG_MD310_SATI : without xilinx loaded provingent!
21257		8644		-- : mrmode do not setted from menu : view only
		8645		-- : make led indikation without second provingent, 
		8646 47		baco : maked synchro start for all slots
21258		8648		PROG_MD310_SATI : operating led_fa maked only for test settings
		8649		-- : make open rf out
		8650		-- : make if loop in ifmodule
21259	141024	8651		-- : maked reset of if module
		8652		-- : any step to load DDS
		8653		-- : -- need make init ddses and have sending to dds
		8654		-- : next step to load dds
		8655		-- : any step to load filters
		8656		-- : more right celling freq
		8657		-- : full start init of dds
		8658		-- : finished init of if module
21260	141027	8659		-- : maked some for operating of output level
		8660t		prm_pch_l61 : answer to commands of ip address test print
		8661		-- : maked for all channels right type of prm
		8662 		baco : more right start
		8663		 -- : property load start
		8664		PROG_MD310_SATI : start mking mrcntl
		8665		-- : next step
		8666 67	68 69 70	-- : --
		8671 72	73	-- : maked gt on led stor_al
		8674		-- ebn0
21261	141029	8675		-- : right setted freq on indicator
		8676		-- : mtdrate 29 MBit
		8677		-- : interrupts enabled
		8678		-- : maked indicating BER - hangt!
		8679		-- : not hangt
		8680		-- : more property celling
		8681		-- : added new struct for modes _________________________________<<<<<<
		8682		-- : rfoutput keeped in memory
		8683		-- : property positions for set output level
		8684 85		-- : start making MoutLev0
21262	141030	8686		-- : mout lev offset positive only
		8687		pu_msat: can be setted ip address from indikator
		8688		-- : after 10 seconds device locked automatically
		8689		PROG_MD310_SATI : maked sign for out level offset
		8690		-- : any step to read config from file
		8691		-- : last step to 30102014
21263	141031	8692		-- : start making full check params before set tmode
		8693 94	95 96	-- : start making messages and rings
		8697		-- : config file readed property!
		8698		-- : do not wrong check rdata
		8699 8700	-- : start making checknetmask
		8701		pu_msat: maked check netmask 
		8702		PROG_MD310_SATI : more right operating of power of transmitter
		8703		-- : maked some to do not have stored alarms at start
		8704		-- : not have stored alarms
		8705		-- : do not hae wrong print
		8706		-- : property loaded filters
		8707		-- : try make acmswitch
		8708		-- : do not have ring in monitoring
21254	141102	8709t 8710	-- : send commands to provingent after loading config file not before
		8711		-- : rdrate and acm are loaded after setting config
		8712		-- : rf output clased before changing and unlock time is 1 s
		8713 14		-- : any step to property indikating ber
		8715		-- : can be property view for agc 
		8716		-- : remove debug print
		8717		-- : maked web password on remove set optics
		8718		-- remove not needed commands in setmtmode
		8719		-- : any step to property operating
		8720		-- : use command acmengine enable before acmswitch
		8721		-- : male print in pok 1100 - 1120 - to view start acm moe profile
		8722		-- : make all params setting before load provingent, only acm and rf output - after
		8723		-- : property view sweep
		8724		-- two times setted rx params
21255	141103	8725		-- : property view mtcode
		8726		-- : mrcode
		8728		-- : receiver freq keep correctly
		8729		-- : transmit freq keep correctly
		8730		-- : demodulator operate modes after start! use needupdete dor set acm from rfoutput on
		8731		-- : after start acm engine enabled
		8732		-- : remove not needed print
		8733		-- : can view temperature
		8734		-- : working if loop
		8735		-- : more property ebn0
		8736		-- : property view ebn
		8737		-- : if loop stored  get on after restart
21256	141104	8738		-- : can make setting if lopp from jacke-mod as pvg710 if loop
		8739		-- : add commands for dds to do not wrong generated
		8740		-- : setting freqs AFTER init if module - not before!
		8741		-- : do not set parameterstx from cfg in reading errors: do not blinks leds in ethernet!
		8742		-- : if modem is not in lock set errors = 1
		8743		-- : if rx profile do not changed - do not rewrite it
		8744		-- : remove not needed print
21257	141105	8745		-- : all prepared to fill modul type in mtmode
		8746 47		-- : --;
		8748		-- : munmodul startted with delay
		8749 50	51t 52t	53t 54-- : start making moutlev1 moutlev2
		8755 56		-- : steart making mratee and mkout
		8757		-- : can view ethernet rate
		8758 8759		-- : any step to get it to remote
		8760		-- : mkout keeped in memory
		8761		-- : added mkout to formula
		8762		-- : maked offset as koefficient
		8763		-- : more right keep moutlevo 
21258		8764		-- : make koef 0,6 for filters
		8765		-- : can view eth rate
		8766		-- : changed ldpc <-> RS
		8767		-- : recompiled v790 -> send
		8768		-- : is controlled quantityin modes in configfile
21259	141107	8769		-- : loadable without writedataflashx
		8770		-- : loadable with writedataflashx why?
		8771		-- : added readdataflashx
		8772		-- : maked for address CFG_DATAFLASH_LOGIC_ADDR_CS1X deviceindex 45 -hangt in test mode d1!
		8773		-- : loadable version
		8774t		-- : temporary comment AT91F_DataflashInitx(); in hello.c
		8775t		-- : address valid
		8776		-- : loadable
		8777		-- : going test "d1" : can write and read to if module!
21260	141110	8778t		pupm3_1 : first generation
		8779 80	81 82 83	-- : compiled some for sicks channel	
		8784		-- : work roulette4 only
		8785		-- : make debug print	
21261	141111	8786		-- : make right mask for CH_PW_MASK_RD
		8787 88		-- : compiled without prints
		8789		PROG_MD310_SATI :  can make rf out on from web interface
21262	141112	8790		-- : property view on web out level
		8791		-- : can set out level
		8792		pupm3_1 :  wait 7sec with key5
		8793		PROG_MD310_SATI :  rx freq om web is printed ok, rx data rate printed wrong
		8794		-- : symbol rate demodulator can view property
		8795		-- : save/load indikating up to 9 - do not indicate max values!
		8796		-- : better indicate save/load fact...
		8797		-- : finish truing make better load/save now  
21263	141113	8798		-- : receiver mode can view property
		8799 8800	-- : checked from web rx freq and configfile number, after set acm mode indikated wrong!
		8801		-- : property indicated and operated from web acm mode
		8802		-- : property setted unmodulated mode
		8803		-- : is checked ethernet max frame size
		8804		-- : ethernet mode is setted property
21264	141114	8805		-- : test mode 7 getted to test mode 1 after restart
		8806		-- : start making indikate input level to formula
		8807		-- : try use external agc register for indicate input level
		8808		-- : next stepto indicate linput level
		8809t 8810	-- : make  offset items in system
		8811t	8812 8813	-- : start making netmask in menu
		8814 8815	-- : correct input level
		8816		-- : next step to make netmask
		8817		-- : make <45 if low level on input
21265		8818		-- : recalibrate input level
21266	141117	8819 20		-- : next step to make netmask in menu	
		8821 22	23	-- : first step to ad gateway to menu
		8824		pu_msat: try add netmask and network to menu
21267	141118	8825		PROG_MD310_SATI : prepared operation 7 to write to if module
		8826		-- : some time property write to if module
		8827		-- : print writed and readed filters values
		8828t		-- : debug of writing to flash on if module
21268	141119  8829		-- : more right celling filters
		8830t		-- : changesize of receive data
		8831		-- : if set directly type of chip - all works
		8832		-- : 100 % property read and write to if flash if directly set type of flash
		8833		-- : some prepared to read data from if module to program anyconfig
21269	141120	8834		-- : read data from flash after init
		8835		-- : property read ifmoduledata at start
		8836 37	38 39 40 41-- : start keep params
		8842 43		-- : tx params are restored from if module	
21270	141121	8844		-- : better web page ;wrong freq sweep
		8845		-- : property prited rx freq offset
		8846		-- more property web
		8847		-- remove debug print
		8848		-- : right can view rx modul
		8849		-- : do not reset ethernet
21271	141124	8850		pu_msat: better web interface 
		8851		-- : property can be set from web digital filter
		8852 53	54	PROG_MD310_SATI : start making koefs add 1 for transmit and three for receive 
21272	141125	8855		-- : property keeping calibration params
		8856		-- : key5 getted off if pok is 1000 only
		8857t 58t	-- : property work without if module
21273	141126	8859t		-- : real find if module flash
		8560t		-- : try make tx command len = 1 (D7) and rx data len 4
		8561t		-- :" add some debug prints
		8562		-- : temporary finish of trying make property dataflachprobex
		8563		-- : more precession make working without if module 
21274	141127	8564 65	66	PROG_MD310_SATI2 : first step
		8567		-- : restoring using configfile1
		8568 69	70 71	-- : is controlled value of configs
21275	141128	8572		-- : any step to use second configfile
		8573 74		-- : can view second config in menu
		8575		-- : automatially repaired configfile number if it is setted wrong!
		8576		-- : start making load second provingent
		8577		-- : make reading slf config file for second provingent. need different set parameters and monitoring for symmetrical and asymmetrical modes - for symmetrical all is ok - for asymmetr : new config dm new monitoring, new remotemonitoring
		8578		-- : try make setparamsfromcfg1 - only rx; need modify setparamsrx fromcfg
		8579		-- : modify setparamsrxfromcfg  need modify control of cheep -read both provingents
21276	141201	8580		-- : madify some in init
		8581		-- : make reading errors from second provingent 
		8582		-- : remeve pragma load one provingent on plata
		8583		-- : start check symmetric / asymmetric mode in readerrors
		8584		-- : any step to indikation in non - symmetric mode
		8585		-- : next step; need check acm mode; change web interface
		8586		pupm3_1 : ADESTO
		8587		PROG_MD310_SATI2 : try view config file of prov2 on web
		8588		-- : can set config file for second provingent from web
		8589		-- : try make right indikation in opreateleds3 for second provingent
21277	--	8590 91		baco : new struct of baco
21278	141202	8592 93t 94t		-- : compiled woth pragma "clock_enabled"
		8595		-- : load mac addresses
		8596		-- : first try checking crc
21279	--	8597		PROG_MD310_SATI2 : change celling ebn0
		8598		PROG_MD310_SATI : --
21280	141203	8599		baco : correct celling checksum
		8600		-- : new values for lengths
		8601		PROG_MD310_SATI : start making satsound
		8602t		baco : loaded test values
	141204	8603		-- : xilinx is loaded olwais!!!!
21281	--	8604		PROG_MD310_SATI : next step making satsound
		8605		baco : make any changes in loaded params
		8606		-- : --
		8607		-- : do not invert checksum - some geet from pimenov
21282	141205	8608		-- : invert checksum; some params -loadable
		8609		-- : property get big packets
		8610 11		-- some changet to right
		8612		PROG_MD310_SATI : start changing in formuls
		8613		-- : added sign to menu
		8614		prm_pch_spi_noxil_eth : led norma get on
21283	141208	8615		PROG_MD310_SATI : make some to have two digits after point in motlevo
		8616 17 18	--
		8619		-- : maked new calculating output power
		8620		baco : add loading date and time in command 4
		8621		PROG_MD310_SATI : try use formulas for input level and output level
		8622t		-- : maked printing ebn0
		8623		PROG_MD310_SATI : property in level and out level
21284	141209	8624t		-- : try make logarifm function for celling ebn0
		8625t 26t 27	-- : --
		8628		PROG_MD310_SATI : change view of modem monitoring item
		8629		-- : make indication if lock off errors 0.5
		8630		-- : change formula for ebn
21285	141210	8631		-- : added item satsound
		8632		-- : work alarm to treshold ebn need make trshold ber
		8633		PROG_MD310_SATI2 : compiled with all changes
		8634		baco : make using reset bit
		8635 36 37	pu_msat : new formulas
		8638		PROG_MD310_SATI : maked alarm to ber 
21286	141211	8639 40		pu_msat : replace <<2 to *4 for negative vlues
21287	141212	8641		pu_msat : do not make conversion for for satget2 dop code is default for signed char! 
21288	141215	8642t		PROG_MD310_SATI :  try operate flash
21289	141216	8643t		-- : find error : before init flash need set right address in if module
		8644t		-- : clean some not needed operations
		8645		-- : remove printfp
		8646		-- : property web page
		8647		pu_msat : property load system delay at start!
21290	141217	8648t		-- : test can view time to http use cgi script!!!!!!!	
		8649t		-- : print from cgi every 10 sec
21292	141218	8650t		-- : --	
21293	141219	8651t 52t		-- : --
21294	--	8653		PROG_MD310_SATI :  more right indikating input level
21295	141220	8654t		pu_msat : was maked cgi_pu_msat.c
		8657t		-- : view some value one time by java! 
		8658t		-- : value is changed periodically!!!!
		8659t		-- : any next step
21296	141222	8660t		-- : value medved is printed!!!!!!
		8661t 62t	-- : value of secs is dynamically printed!!!!
21297	141223	8663t		-- : web do not stopped buttoms of display operating
		8664		-- : property print format!
		8665		-- : channel delay is indicated by script
		8666		-- : added if balance
		8667		-- :  -- if down link
		8668		-- :  -- if up link
		8669		-- : -- demo timeout
		8670		PROG_MD310_SATI : more right celling input level keep two variants of configs
		8671		prm_pch_l61: keep two variants of configs v815
		8672		pu_msat : property view page if maked login (delete names)
21298	141225	8673 74		-- : delete screen and smake chetdwn safety - work on notebok!!!!
	--	8675		PROG_MD310_SATI : new web page
		8676		PROG_MD310_SATI2 : --
21299	141226	8677		PROG_MD310_SATI2 : start making indicating thgrough cgi
		8678t		-- : print sec as eb/n0
		8679		pupm3_1 : answer olwais -if do not start some plats
		8680		PROG_MD310_SATI2 : print real ebn0 make number of chip xilinx
		8681		-- : added to web ber and bere
21300	141229	8682		PROG_MD310_SATI2 : loaded syntezer
		8683		--: if copy init_bmdn from previons - are loaded some provingents!
		8684		-- : use back init_bmdn_start with sine corrections do not view agc!
		8685		-- : remove some from start_print : view is property!!!!!!!!!
		8686		-- : any step to make property monitoring
		8687		-- : maked bit DUALMOD in registr STATUS_610
		8688		-- : property indicated inp level - use "double"
		8689 doubled operating ethernet for second provinent need get off flow control and pause if rates are different!
		8690		-- : make parrallel loading ethernet params
		8691		-- : meking set off eth control and pause if different data rates
21301	141230	8692		-- : can property view ber
		8693		-- : maked modulation and code rate
		8694 		-- : mrcode somtime is zero!
		8695		-- : monitoring modem maked property!
21302	150112	8696		-- : first version compiled in 2015
		8697		-- : more right write status in operateleds - keep
		8698		-- : start making cgi for ethernet statistics
		8699		-- : can view ethernet mode
		8700		-- : meked web monitoring ethernet
		8701		-- : startethtimed maked off
21303	150113	8702		tmp : any copie before start tryinc compile sati with 1 core
		8703		PROG_MD310_SATI : start adding cgi web pages
		8704		-- : was added cgi web pages
		8705		-- : property view cgi pages
		8706		-- : without debug print
		8707t		-- : start making cgi log page
21304	150114	8708t		-- : get two strings of log
		8709t		-- : ten strings to log!!!
		8710 8711	-- : property log with 20 lines
		8712		PROG_MD310_SATI2 : -- 
		8713		-- : --
		8714 15		pu_msat :  --
21305		8716		-- : is removed debug print
21306		8717		prm_pch_l61 : use tftpbuff1 for debug
		8718t		PROG_MD310_SATI : added getloopi
		8719		-- : if loop work often
		8720		-- : get on led alarm when restarting
		8721		-- : more property setted if loop
21307		8722 8723	-- : --
		8724		-- : --
		8725		PROG_MD310_SATI2 : --
21308	150120	8726		-- : make property remote control
		8727		-- : remove some print
		8728		PROG_MD310_SATI :  --
		8729		prm_pch_l61 : more carefully read id from two adresses : use first address if second is wrong to better upgrade
21309		8730		PROG_MD310_SATI :  set max frame ethernet after loading config file
21310		8731		PROG_MD310_SATI2 : -- 
		8732		PROG_MD310_SATI : max frame 9600 + pause vlan and ethctl seteed realy after restart only
		8733		PROG_MD310_SATI2 : --
		8734	8735	pu_msat :  new constant for sat delay need use it in this version only maked lated one
		8736		PROG_MD310_SATI : ethernet mode is setted
		8737t		-- : start operating and indikating all variants of interface
21311 150123	8738t		-- : maked setting all modes of ethernet interface from state of xilinx to provingent
		8739 8740	-- : make idikation - in what mode is connected ethernet interface  
		8741		PROG_MD310_SATI2 : --
		8742		-- : make tx calibration as in md310s
		8743		PROG_PU_M_V_AI : start making in file pumvai
		8744		-- : compiled with rs485e protokol
		8745t		-- : compiled for maket - tested - ok
		8746		PROG_MD310_SATI2 : keep second parameter for tx in if module
		8747		-- : keep sign of first parameter in if module
		8748		PROG_MD310_SATI : --
21312 150126	8749		PROG_MD310_SATI : maked cummulative statistics
		8750		-- make init global struct of statistics
		8751		pu_msat :  new constant for sat delay need use it in this version only property readdevid
		8752		-- : go back for old min_satset1 property readdevid
		8753		PROG_MD310_SATI : maked cgi eth_state1 - full statistics
		8754		PROG_PU_M_V_AI : used stack of commands from pumva - property operated
		8755		pupm3_1 : No ADESTO
21313 150127	8756		PROG_MD310_SATI : maked full view of ethernet params in monitoring_e
		8757		PROG_MD310_SATI : collect byteshigh and low  in structs of ethernet statistic
		8758		PROG_MD310_SATI2 : --
21314 150128	8759		pu_msat1 : celling dsat without dd
		8760 61		-- : maked satget8
		8762		-- : new indikation time frame
21315 150129	8763		prm_pch_spi_noxil_eth : compied for ADESTO
		8764t 		PROG_MD310_SATI : use md310s_work1 from version 824 : property work ethernet if change modulator mode
		8765		PROG_MD310_SATI : remove function InitEthStat - property work ethernet
		8766		PROG_MD310_SATI2 : --
		8767		PROG_MD310_SATI :  remose SetMEthPause1 to setting all params - not tx to work ethernet
		8768		PROG_MD310_SATI2 : --
21316 150130	8769t		PROG_MD310_SATI : try make universal driver
		8770		-- : view tail of adesto id
		8771		-- : view one in dataflashprobe
		8772t		-- : maked universal driver for flash atmel and adesto!!!!
		8773		PROG_MD310_SATI2 : used universal driver for flash adesto / atmel
		8774		-- : make indicating  eth rate of demodulator - need add it to max struct; need ,ake send eth type to second provingent if it is changed, get eth sttistics from two chips and blinking leds
21317	150202	8775t 8776	-- : any next step to make mrateed
		8777		-- if changed eth rate operated two chips to commands
		8778		-- write to two chips vlanpriority max frame ethctl vlan priority and pause
		8779		-- try use full ethernet statstics
		8780		-- add to cgi full struct of ethernet statistics
		8781		-- is added to web full eth statistics
		8782		-- : right celling gfp statistics
		8783		-- : right monitored current ethernet mode
		8784		-- : can be view ethernet rate for demodulator on web
		8785		-- : change used in menu ethernet statistics
		8786t 8787	-- : start making methrcvD
21318	150203	8788		PROG_MD310_SATI : -- 
		8789 8790	pu_msat : rgd changed from 8 bits to 9 bits remove item low power
		8791		-- : right driver for 4mB flash
		8792		-- add debug print
		8793		-- : property maked going float -> long. need make it in pu_msat1
21319	150204	8794		pu_msat3 : go back to step 2048 
		8795		pu_msat1 : are deleted errors
		8796		pu_msat3 : right version info ver v836
		8797t 8798	PROG_MD310_SATI2 :  start making Er and Et
		8799		-- : do not ring at start rdrate error
21320	150205	8800		PROG_MD310_SATI : making Er and Et; removed some print maked rezerved1 = 1	
		8801		PROG_MD310_SATI2 : do not get periodical ring if some params rx in config file are wrong
		8802		-- : remove some debug print
		8803t 8804		-- : prepared to indicate tx dones v839
		8805  		PROG_MD310_SATI : -- v 839
		8806 		-- : make clear statistics	
		8807 		PROG_MD310_SATI2 : --	
21321	150206	8808 		PROG_MD310_SATI2 : can read some statistics
21322		8809 		-- : remove updateerrors()
		8810  		PROG_MD310_SATI : --
		8811  		PROG_MD310_SATI2 : can clear statistics
		8812  		PROG_MD310_SATI : --
		8813 8814 	linkdoubler4 pu_msat4 : = linkdouler2(menu) + 1024 = linkdoubler4
		8815  		--: any step
		8816  		--: make min satset1 238,67
		8817  		pu_msat (linkdouler1) : --
		8818  		PROG_MD310_SATI2 : open output only if loaded both provingents 
		8819 		-- : output get to on in finish of all loadings
		8820		-- : indikate mode from chip B
21323	150207	8821		PROG_MD310_SATI2 : right celling eb/n0
		8822		-- : remove debug print
		8823		-- : change some in net statistics
		8824		PROG_MD310_SATI : --
21324	150209	8825		pu_msat : if_alance : float -> signed
		8826		PROG_MD310_SATI2 :  do not indikate out of range if max frame > 1514
		8827		PROG_MD310_SATI2 : easy celling ebno
21325	150210	8828		PROG_MD310_SATI2 : added testmode 0xd3
		8829 8830	-- : maked my_exp
		8832		-- : celling ebn with my_pow my_log
		8833		PROG_MD310_SATI : --
		8834 		pu_msat3 : if_balance : float -> signed
		8835		pu_msat4 : --
		8836		pu_msat1 : --
21326	150212	8837		baco : start adding ubx
		8838		-- : added ubx.h
		8839		-- compiled with ubx.c can try send commands
		8840t		-- : hangt - any step to use usart0
		8841		-- : do not hangt
		8842		-- : send many commands to usart!!!!
		8843		-- : more better printing
		8844		-- : replace '$ to '>' and property print answers from gps
		8845		-- : maked test mode "d5" - init gps
		8846		-- : added cold restart command; need make tp5 command and can be parse time need make self buffer for ethernet commands
		8847		-- : added command ubx cfg tp5
		8848		-- : init types of msgs
21327	150217	8849		-- : start making parser
		8850		-- : full parser
		8851		-- : try view utc time
		8852		-- view property checksum at end of packet
		8853		-- : correctly make length of command tp5
		8854		-- : make checksum is as - property requests and answers!
		8855		-- : request time only
21328		8856t		-- : this version somtime restarted!
		8857		-- : any step to debug
		8858		-- : start correct time
		8859 can correct sec min and hours
		8860		-- : self find time!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! prepared to load filters
21329 150219	8861		-- : in baco disabled all test modes no test_enabled
		8862		-- : if device is loacked  do not run some in ::operate
		8863		-- : more correctly get data from receive buffer - do not hangt!
		8864 		-- : maked loading filters to protokol
		8865		-- : enable back ::operate vithout loock == 2
21330 150220	8866 67		-- : try poll command tp5	
		8869		-- : tested loading filters
21331 150224	8870t		-- : start reanimate modem
		8871		-- : property loaded
		8872		-- : full started
21332 150125	8873		pu_msat1 : make web indikation of lock
		8874t		-- : if balance - maked with  one digit after point 
		8875t		-- : maked keeping 10 values for if balance
		8876		-- : no debug lock
		8877		baco : some changes in protokol :use  mask_bit_4
		8878		pu_msat1 : on page update keep restart only
		8879		pu_msat4 : --
21333 150126	8880		PROG_MD310_SATI2 : to snmp added first node : typever
		8881 8882	baco : add command5 and loading filters from nvram
21334 150227	8883		PROG_MD310_SATI2 : can get test value of ber
		8884		baco : write filters to slots
21335 150302	8885 8886	PROG_MD310_SATI2 : any step to add ebn0
		8887 8888		PROG_MD310_SATI2 : try add modulator_mode and power
		8889		baco : property size
		8890		PROG_MD310_SATI2 :  can set to snmp power -1
		8891		PROG_MD310_SATI2 : can set power -30	
		8892		PROG_MD310_SATI2 : frepared to set modulator freq and modulator tmode	
21336 150304	8893		PROG_MD310_SATI2 : can be setted and requested modulator freq
		8894		-- : -- mtmode
		8895		-- : can operate demodulator freq and modet
		8896		-- : any step to make operating configfiles
		8897		-- : check configfilenumber
21237 150305	8898		-- : prepared to view ber nmse and lock need check and make lock
		8899		-- : can view lock and nmse	
		8900 8901	-- : all prepared to view eth mode
		8905		-- : can read modulator and demodulator  symbol rate modul and code rate
		8907		-- : add nodes for test mode
21238 150310	8908		-- : maked some to add item acm	
		8909		-- : work acm mode
		8910 8911	-- : maked acm mask
		8912		-- : right view ethrated and ethratem
		8913		-- : make up 100 configfiles
		8914		-- : maked msps
		8915		-- : dropped mod droppes dem
		8916		-- : config meni is after eth indication
		8917 18	19 20 21	-- : start making paramsconfigfiles
		8922		-- : finished config items with symbol rate
21239 150311	8923		-- : some positive changes in menu
		8924		-- : more advanced menu	
		8925 26		-- : added macmi
		8927		-- : two times loading freq : property start	
		8928		-- : prepared malfam ans malfad - need init and set to menu ? - what about wrong errors?
21240 150313	8929		-- : can view alpfa
		8930		-- : start making mtmodeI
		8931		-- : can wiew mode of modulator in indikation menu
		8932		baco : added remote command 6 : load freqoffset
		8933 34		-- : add command7
		8935		pu_msat4 : maked in web page enower bounds
		8936		baco : more right load freq offset
		8937		PROG_MD310_SATI2 : add one digit to kin3 divide all koefs to 10
21241 150316	8938		PROG_MD310_SATI2 :  make some for mtmode
		8939		-- : three digits for mkin1
		8940		baco :  after filters olwais loadin freq offset
		8941		PROG_MD310_SATI2 : is printed modulation type to new lengt of tmode
		8942		-- : is printed code type
		8943		-- : print code rate
		8944		-- : finished mtmode
		8945		prm_pch_spi_noxil_eth (prm300) : do not use in command6 filter == 0 or filter == 2 - can use every values
		8946		PROG_MD310_SATI2 :  use LOCK variable to indikate errors
21242	150318	8947		-- : make protektion for divide to zero in celling ber		
		8948		-- : withoutcelling ber	
		8949		-- : maked p property check value of mtbere
21243	150319	8950		-- : moved menu item of ethernet rates
		8951		-- : property write serial number (hex)
		8952		-- : have hex serial number in web page
		8953		pupm3_1 : can work with adesto and non-adesto
		8954		PROG_MD310_SATI2 : get serial to snmp
		8955		PROG_MD310_SATI2 : can view lock from web page
		8956		-- : property keep forth digit for kin3
		8957		-- : any step ... somtime wrong write to flash in if module!!!!
21244	150323	8958		-- : test of writing to if module print ok or wrong
		8959		-- : property write data to if module from anyconfigfile.exe
21245	150324 mib2		-- : mib for modems
21246	150331  8960 8961	baco : maked some for have gps on usart1.
21247	150406	8962		-- : add some test print
		8963		bacod : first version baco-dmu	
		8964 65t 66t 67t 68t	prm_pch_l_8 : first version for 8 - receivers prm_pch
		8969		baco : can be print in test mode 0x50 what is receiveng
		8970		-- : work reading time from gps!!!! usart1
21248	150407	8971		-- : pack before finding error
		8972		-- : this variant get time from gps on usart1
		8973		-- : property init gps : use operatebuffersusart1t - if send data  and have property answers
		8974		-- : somtime work tp5 and tp5_2
		8975		-- : make up to 10 tries for command tp5
		8976		-- : port configured propert : stop bits value should be 1
		8977		-- : remove debug print
21249	150408  8978		-- : property operate with year;
		8979		-- : some prepared to parse commands 8 9 10	
		8980		-- : some maked for command 10	
		8981		-- : have time in ms
		8982		-- : maked struct bsc
		8983 8984	-- : sime changes in time in ms100
		8985		-- : make start command without period
21250	150409	8986 87	88 89	-- : try make pointer for bsc to nwram
		8990t	91t	-- : many errors getting of this is debug variant
21251	150410	8993		-- : more property parse time
		8994		-- : first full work version; can add clearing and signature
		8995		-- : maked signature for init data
		8996t		-- : make tp5_2 10Hz
		8997		-- : change operatin of number slot in commands 8 and 0
		8998		-- : delete some debug code
		8999		-- : deleted error : operate with bcs only if it is init!!!
21252	150413	9000t		-- : make some for can use gpstime command
		9001		md310e : added test mode 0x21 - dev_restart2
		9002t		bmdn6 : OLD!!!!!! compiled for old xilinx with invwerted ints
		9003		-- : for new xilinx property hot restart
		9004		baco : more property programmet freqs after lock
		9005		baco : get off usart1 channel get off interrupts
		9006 07 08	prm_pch8 : maked some
21253	150416	9009		baco : maked some for time gps
		9010		dmu5 : first step
		9011		-- : compiled some more
		9012 9013 14 15	-- : makeed some for command
		9016		-- : make 4 for selector new plata
21254	150417	9017		baco : maked some for gps time 
		9018		dmu5 : make address 400 and selector2 for tge
		9019		-- : more property keep params
		9020		-- : remowe wrong print
21255	150420	9021		-- : property can set data rate
21256	150421	9022		-- : write time to bacoplata
21257	150422	9023		baco : maked writing ms100
		9024		dmu5 :  set maximum rate 50000000
21258	150423	9025		baco : maked more delay to loading slots
21299 150507	9026		PROG_MD310_SATI2 : do not lost duplex ethernet mode
		9027		-- : for 100 duplex = 1
		9028		-- : receive modulation can in web view propeerty
		9029		prm_pch_l61 : support adesto
21300 150514	9030		pd : first version of pd
		9031		pd1 : second version pd on  
		9022t		-- : start making enover parser no_asu
		9023t		pd1 : support parsecommand1 - answer to type of device
		9034		-- : maked command2 => sending to usart2 to edik and send back answer.
21901 150515	9035		PROG_MD310_SATI2 : more debug print
21902 150518	9035		-- : more property hot restart
		9037		pu_m : stort on hanging plata
		9038t		-- : can print devid; without xilinx
		9039t : 	-- do not write dev id; load xilinx before  standard; work.c used from v671
		9040		-- : do not have bag olwais hot restart
		9041		-- : change m_load_xilinx3 to can load st modems
21903 150519	9042		-- : if mirrortest do not go - load xilinx and chenge test mode from 0x8e to 1
		9043 44	45	PROG_MD310_SATI2 : more quickly erase all configfiles 
		9046		-- : make timer for web programming
		9047		-- : print all config files filenames to comport
		9048 49		-- : start making class MdataSB - up to 1500 Bytes of data  in remote comaand
		9050 51		-- : added two mdatasb objekts to read all nomes of configfiles
21904 150521	9052		-- : maked command I2
		9053t		-- : get only 246 bytes to ethernet answer!
		9054		pupm3 : change formula
		9055		pupm2 : --
		9056t		PROG_MD310_SATI2 : can be get big pakets to ethernet radian protokol!!!!! Can be readed 70 canfigfiles!!!
		9057 58 : 		-- : without debug print  
21905	150525	9059		pu_msat : start making snmp
		snmp_8060	rtcs : any step with snmp of linkdoubler
		9061		pu_msat : any step to snmp
		9082		-- : can get serialnumber!
		9063		-- : --
21906	150526	9064		-- : can read symbol rate and set symbol rate
		9065		-- : can read ifuplink and if downlink
21907	150527	9066		-- : system delay out level tfreq rfreq
		9067		-- : really work system delay; need unlock before!!!
21908	150528	9068		--: can set out level
		9089 70		-- : can read to snmp freq offset channel delay if balance
21909	150529	9071		prm_pch_spi_xil : enable filter 1 and 3 
		1213_9072	pu_msat : start add snmp for enover config parameters
		9073		-- : --
21910	150601	9074		-- : -- can set tframe if device is unlocked
		9075		-- : can operate slave level 
		9076		-- : added some parameters
21911	150602	9077		-- : tested many in config
		9078 79		-- : added custom parameters
21912	150603  9080		-- : start operating some parameters from system menu
21913	150604	9081		-- : can set accesscode
		9082		-- : can set demo mode
		9083		-- : can get prog ver and fpga version
		9084		-- : linkdoubler1 full maked for postavka
		9085		-- : linkdoubler4 --
		9086		pd2 : make for spi on cs1 10 MHz
21914	150605  9087 88		pd3 : can print on rate 115200 maked from prm_pch spi_noxil_eth
		9089		--  : try send some from tcp to spi cs2
		9090		--  : try send some answer
		9091		-- : try make 10 Mhz to spi cs2 and get clock to xilinx
		9092		-- : remove some not needed funktions
21915	150608	9093		-- : make d request of answer and prining in test mode 50
		9094		-- : maked ans_ok and ans_wrong
		9095		-- : maked Req_flag : if request - send answer  if set - check and send ok or wrong
21916	150609	9096		-- : right operate with address of buffer to sending through spi
		9097		-- : do not request setted parameter
		9098		-- : send to one byte 
		9099 100		-- : more right get ans
21917	150610	9101		-- : little delay
		9102t		-- : start make parser command
		9103t		-- : make setting freq
		9104t		-- : can set att and pd
		9105t		-- maked struct to answer to command1
		9106t		-- : start maked answer to command1
		9107t		-- make some command without power
		9108t		-- : maked all without power
		9109 10		-- : more property answer to max
21918	150611	9111		-- : delay 100 mcs property answers from edik
		9112		-- : delay 75 mcs added some printing in test mode
		9113 14		-- : maked keep attenuator and freq
		9115t		-- : keep off; try operate with long packets with many commands in one packet 
		9116 17		-- : do not hangt if have wrong number of command 
21919	150615	9118		prm_pch_spi_noxil_eth : DELETE ERROR!!!! secand devid address do not go to  afr table address!!! was c01fc000 => c01f0000 ( ID_ADDRESS3 )
		9119		-- : parameters are property keeped for devid3
21920	150616	9120		PROG_MD310_SATI2 : mkin1 keeped property for -114
		9121		-- : more fast indikate 
		9122		-- : fast and more easy indikate
		9123		-- : mkin2 can be have minus
21921	150617	9124		prm_pch_dmu5 : can be used 512 offset (code 0x91)
		9125		PROG_MD310_SATI2 : property link to ethernet data interface v894
21922	150619	9126		pd3 : make spi freq 5 MHz
		9127		--  :	-- 2 MHz
21923	150624  9128t		PROG_MD310_SATI2 :  test version with freq up 180 MHz #define UP_140
21294	150629	9129		prm_pch_spi_xil : v895 maked very high freq of core
21295	150630	9130		PROG_MD310_SATI2 : uncommented loading at start ethernet mode!!! removed printing		
21296	150701	9131		prm_pch_spi_noxil_eth :  return to command 1 hardvare version 1
21297		9132		prm_pch_l61 : changed formila9
		9133 34 35	PROG_MD310_SATI2 : period requests set 1s and default timeout change 1 to 10`
21298	150703	9137		PROG_MD310_SATI2 : period requests set back 3s; have button "Clear" in page monioring_e
		9138		PROG_MD310_SATI2 : remove not needed loading provingent if "No link"
21299	150708	9139		pu_pm2 : support atmel and adesto
		9140		ups : --
21299	150708	9141		PROG_MD310_SATI2 : repair snmp indikation of send and received packets
		9143		PROG_MD310_SATI2 : property web indikate ethernet
		9144		-- : better web interface : hex modulator modes
21300	150713	9145		prm_pch_l61 : new formula9
		9146		prm_pch_l81 : --
		9147		PROG_MD310_SATI2 : maked not setted params in web page of modulator page 
		9148		PROG_MD310_SATI2 :  demodulator --
21301	150714	9149		-- : property set treshold Ebn0.
		9150		-- : property set value mtber
		9151		-- : -- mtbere
		9152		-- : maked property web month and remove seconds
		9153		prm_pch_l81 : make indikating power on channels 7 and 8
21302	150715	9154 55 56	prm_pch_l81 : more right start
21303	150803	9157		prm_pch_l61 : some maked of Max in time of 20 - 30 07 2015
		9158		linkdoubler1 : transmit and receive freqs up to 200 MHz
		9159		linkdoubler4 : --
		9160		linkdoubler1 : property view version
		9161		linkdoubler4 : --
		9162		linkdoubler4 : make freqs up 145 MHz
		9163 		linkdoubler1 : make freqs up 145 MHz
21304	150817	9164t		maket : maked cheking writed devid and rewrite it if it is wrong and disabling interrupts
		9165t		-- : maked 1 MHz for spi flash (on 10 MHz crashed uboot!)
		9166t		maket - prm_pch : restart device if wrong selekt flash 
21305	150818	9167t		maket : print some about flash
		9168t		PROG_MD310_SATI2 : added new flash operating
		9169		PROG_MD310_SATI2 : maked new address for config files
		9170		-- : go back to one flash make up 120 config files
21306	150825	9171		-- : make in web interface 3 digits for number of config file
21307	150831	9172		PROG_MD310_SATI2 : really work two storages.
		9173		bmdn6(kazax) : --
		9174 		-- : do not print dataflashinfo - not hangt
21308	150902	9175		-- : restarts will be if pok = 1000 only
21309	150907	9176		prm_pch_spi_noxil_eth : use two storages
21310	150908	9177		prm_pch_l61 :  really work two storages.
		9178		prm_pch_l81 : --
		9179		prm_pch_spi_xil : --
		9180		md310e : use two storages v914
		9181		-- : right get on two trunks ! - delete error!
21311	150917  9182		prm_pch_l81 : make command3 for attenuators of channel 6
		9183		-- : maked hardware[13] = hardware[12] to right indikate atts
21312	150918	9184		linkdoubler1 : start making do not reload values of parimetes if they arent changed from web interface
		9185		prm_pch_l61 :  new formula9
		9186		linkdoubler1 : do not reload not changed parameters tgrough web interface
		9187		linkdoubler4 : --
21313	150921	9188		bmdn6(act155052) : recompile
		9189		-- : load one provingent - indikation - ok
21314	150923	9190		linkdoubler1 : property working timeframe from web interface if alarm is on
21315		9191		linkdoubler4 : --
21316	150925  9192		prm_pch_l81 : use writedevid2 for attenuators
21317   150928  9193		prm_pch_l61 : --
21318	150929	9194		bmdn6 (two provingents) : use operating ethernet rate from sat modem
21319	151001	9195		bmdn6 (one provingent) : property erase config files 	
21320	151002  9196		bmdn6 (two provingents) : --
		9197		md310e : --
		my_dir_9198	web : start sending file; but send two packets only
21320	151005	9199 9203		bmdn6 (two provingents) : operate ethernet from rnms	
		9104 		bmdn6 (one provingent) :  --
		9106t		commutator debug!
21330	151007	9107t		bmdn6 (two provingents) : some debug version
		9108t		commutator debug print!
		9210		bmdn6 (two provingents) : remove stopping transmit in embisr.c
		9211		bmdn6 (one provingent) : --
		9212		md310e : --
		9213		commutator : restored after debug print
		9214t 15t		commutator :  add ready for channel 1 2
		9216		commutator : maked ready for transmit in all commands
21331	151009	9217		prm_pch_spi_xil : compiled with high core frequency
		9218t		 -- : maked test print
		9219t		-- : used test parsing command	
		9220		md310 : can revrite xilinx from ethernet
21332	151012	9221 22		prm_pch_spi_xil : added delay before transmit and Ready_Reseive
21333	151013	9223		prm_pch_spi_xil : can view stability of main loop
21334		9224		-- : maked polling transmit
		9225		-- : maked command 0xA
		9226		-- : add command A to usart parser
		9227		-- : maked funktion ClearSpi()
21335	151014	9228		-- : get back blinking
		9229t		-- : compiled with prm_pch_spi_xil.cpp from 930 version. do not hangt!
		9230		-- : remove polling_transmit -do not hangt
21336	151019	9231ttt		-- : TEST using old version to try do not hanging to "DISABLE_ETHERNET"
		9232ttt		-- : TEST --; property init cs2 - work mirrortest
		9233 9234	-- : more full disabling ethernet -  hangt v937; not hangt in 9234
		9235		-- : polling transmit v938
21337	151020	9236t 37t 38t		-- : testing bus
21338	151021	9239		PROG_MD310_SATI2 : pack before try compress config files
		9240t		-- : can celling in operatefile() number of congfig file
		9241		-- : first version of PACK_CFG
21339	151022	9242		-- : PACC_CFG : property load syntezer
		9243 44	45	-- : property loaded provingent2
21340	151026	9246		pum_v: more big xilinx size : can load xilinx
21341	151027	9247 48		prm_pch_l61 : new formula9
		9249t 50t	PROG_MD310_SATI2 : new formula for ebn0
21342	151028	9251		bmdn6 (two provingents) : set for rx PHyid = 0; (for tx  phyid = 1)
21343	151029	9252		-- : set for th phyid = devver1; devver1 can be changed with key3
21344	151030	9253		-- : really set PhyId
21345	--	9254		prm_pch_l81 : new formula9
21346	151102	9255 56		PROG_MD310_SATI2 : new formula for ebn0 without debug print
21347	151103	9257		PROG_MD310_SATI2 : can be writed config files with numbers more as 127
		9258		-- : can ber readed more file names
21348	151105	9259		prm_pch_l61 : add delay 2 ms to answer to freq
		9260		PROG_MD310_SATI2 : can read flash to tftp buffer (tm42) and write flash from tftp buffer (tm43)
		9261		prm_pch_l81 : make up to 500 trying to set command
		9262		-- : make run_time 500	
21349	151109	9263		PROG_MD310_SATI2 : make reading and writing to flash minus two header size
21350	151111	9264		PRM_PCH_SPI_NOXIL_ETH : nev formula8fsb
		9265		PRM_PCH_SPI_XIL_ETH : --
		9266		PRM_PCH_SPI_XIL : --
		9267		md310 :  can be setted PhyId	from devver1
21351	151112	9268		PRM_PCH_SPI_NOXIL_ETH : nev formula8fsb
		9269		pum_mux : two storages
21352	151116  9270 71		PRM_PCH_SPI_NOXIL_ETH : go to old formula8fsb
21353	151118	9272		PRM_PCH_SPI_NOXIL_ETH :  add command A - get dev id
21354	151123	9273		TUTS : maked for new flash
21355	151202	9274t           PROG_MD310_SATI2 :  maket variant
21356	151207	9275		 PROG_MD310_SATI2 : calculate BER from fec uncoreected blocks
		9276		 PROG_MD310_SATI2 : more really indicate BER
		9277			-- : more property for best and worse ber
		9278			-- : use koef 40 to property ber
		9279			-- : if do not lock 5e-1 ; without errors 0e-0
21357  151210	9280t	       prm_pch_l61 : modescan1 do not get off by enover commands scan property!!!!	
		9281		-- : scan_delay 7ms; modescan do not get off from enover commans (only command2); resend pakets in scan mode
		9282		prm_pch_l81 : -- without resending pakets
		9283		-- : resending packets
		9284 85		 PROG_MD310_SATI2 : more quickly indicate BER
21358	151218	9286           pum_mux : is working operating pd
21359	160122	9287		odu : start making outdoor unit programm
21360	160126	9288t 89 90	odu : next step : need make four funks; are added empty funks.
21361	160129	9291		odu : maked some inits.
21362	160201  9292		pum_mux : working radstart (command B)
		9293t		odu : maked some inits.
21363	160202	9294t		odu : maked parsing of commands . Now wrong struct without union for t1 and t2
		9295t		odu : try read some base from flash
		9296t		odu : frozen this projekt
		9297 98t 99	dmu6 : start projekt
21364	160210	9200		-- : not hangt; maked return from prm_pch(	
21365	160211	9201		-- : maked some loads	
21366	160212	9202		-- : started making operatefile for dmu6
21367	160216	9203		-- : can be writed and compared flash on cs1 spi
21368	160218	9204		-- : can be read version on second xilinx
		9205		-- : compiled for new linker file : size for tftp buffer maked bigger from 5MB to 8 MB link31s.met
21369	160220	9206t		-- : try to make 280 config files but it cyckled that in many funcs variant is of unsigned char type
		9207t		PROG_MD310_SATI2 : maket 250 configfiles; tftp buffer size 6160000 starting; writing
21370	--	9208t		-- : maked class mdataVL
		9209t		-- : class mdatv maked as mdatavl; class mdatavl is not used
		9210t		-- : changed unsigned char to unsigned long
		9211t		-- 255 configfiles support
		9212t		-- settet return into operatefile : programms are writed property! 256 configfiles now
		9213t		-- 280 configfiles !!!!
		9214t		-- : repair scantxtfiles : property writing programm without returns!!!!
21371 160224	9215t		-- : found some unsigned char and replaced to long
		9216		-- : maked indikation dfe on indikator
		9217		-- : -- on web interface
		9218		-- : -- on snmp
		9219		-- : sources for snmp
		9220		-- : new mib

		9221t		-- : can read flash with buffer 7 mb
		9222		-- : new . met file; read flash to halfs
		9223		-- : new formula for ebn0
		9224		-- : if no lock ebn0 n/a
21372	160229	9225		-- : ebn0 = 0 for snmp and in web
21373	160301	9226t 27t 28t 29t		dmu6 : any next step
21374	160309	9230		dmu6 : first release
21375	160310	9231 32		PROG_MD310_SATI2 : maked try sending racm and receiving racm_far
		9233		-- : are working mailboxes!!!!
		9334		PROG_MD310_SATI2 : maked struct for acm init it to default; need make going up and down
21376	160315	9335		PROG_MD310_SATI2 : operating structs for acm on receive side	
		9336		-- : working acm!
		9337		-- : make timers for acm
21377	160316	9338t		-- : commented readstateeasyd
		9339		-- : can get on acm from menu
		9340		-- : acmonoff can be keeped in flash
21378	160317	9341t	42	-- : acm params keeped in flash ; need set righyt size
21379	160318	9343		-- : is loaded without check params
		9344		-- : more property menu
		9345		-- : maked acm without using timemse
		9346		-- : timeouts are keeped correctly
		9347		-- : in test mode 0xac are setted default acm parameters
		9348		-- : maked trye init of up and down steps 
		9349		-- : more often request params 333->222
		9350            -- : remove some prints
		9351		-- make integrated mse
21380	160319	9352		-- : deleted error divide to zeroin celling integrated mse
		9353		-- : maked fast reading errors in every step acm; do not read errors from not used channels
		9355		-- : maked indikating mse
		9356		-- : maked protection from set very different timestep in acm
		9357		-- : more really protection; added timemse to protection
		9358		-- : logical error is removed
21381	160323	9359		-- : acm on off get off acm on modulator
		9360		-- : some prepared to make different on/off items for modulator and demodulator
		9361		-- : maked item in modulator menu acm recovery on/off
		9362		-- : in test mode 0xac are setted default parameters by Tukaev
21381	160325	9363		-- : maked ACM offset
21382	160329	9364		-- : maked indikating mse in monitoring modem
		9365		-- : maked acm events
		9366		-- : maked new default table in test mode 0xca
		9367		-- : maked printing in log getted acm modes
21383	160330  9368		-- : maked printing in log config files numbers
		9369		-- : in test mode 0xca devault set offset 0 and acm off for demodulator and modulator
21383	160331	9370		-- : correctly setted  configs by names ; can read to snmp some acm params
21384	160401	9371		-- : can be setted and readed acm on/off and acm offset
		source_rtcs_9372 rtcs : added some for snmp set and read acm
21385	160404	9373		-- : levels for acm can be setted to snmp 
		9374		-- : is getted off acm from web interface
		9375		-- : add snmp operating for en inc dec acmparams
21386	160406	9376		-- : are working configfiles with numbers more as 257
		9377		-- : maked snmp operating of acm times
21387	160407	9378		-- : timestep can be readed by snmp
		9379t		odu2 : start making comport for up-down channel
		9380t		-- : some prepared to parse protokol on rs485 with edik
		9381		-- : maked modemchannel;  rs485e channel; need full get off tranzit and seconfd provingent
21388	160411	9382		-- : added some for using 232 channel updown; need get off second provingent
		9383		-- : use for timechangemode time for send modulator to change mode
21389	160517	9384t 85	DMU6 : start try compile dmu6
21390	160518	9386t		-- : can write and read little file!!!!
21391	160519	9387		-- : flash is found at start
		9388		-- : xilinx dmu is property writed!!!!
		9389t	9390	-- : can write to spi cs2
21392	160524	9291		-- : make start reading temperature and operating xilinxspi to loading ddss and filters
		9392		-- : empty main loop
21393		9393		-- : maked loading ddss thgrouh xilinx spi
		9394		-- : freqif ad fsymb are loading at start
		9395		-- : can read type
21394	160530	9396t		-- : can back write xilinx in slot2
		9397t		-- : hello7.h added from 9392
21395	160531	9398		-- : recovered writing to slot0. Tested.
		9399		-- : loadds_symb_start - ok
		9400		-- : try make LoadDDS_IF_Start
21396	160601	9401		-- : property maked loading filters
		9402		-- : can read temperature test mode 37
		9403		-- : new version 984
		9404		odu2 = rmb : compile for test; start checking
		9405t		-- : pack before get off rs232; neet check using buffers for commands
21397	160603  9406t 07t 08t		-- : make near end for rs485e many changes in remote
21398	160606	9409t		-- : get off racm
21399	160608	9410t		-- : maked operateleds4
21400	160609	9411		-- : tested on maket : provingent and xilinx synt are loaded!!!!!
21401	160610	9412		-- : not hangt if use writing devvid
		9413		-- : maked temperature
		9414		-- : some getted off
21402	160614	9415		-- : can write ".fw" file
		9416t		-- : maked odu3.cpp from modem - synt loaded property
		9417		-- : can load syntezer and provingent
21403	160615	9418		-- : maked ETH_TRANSIT
21404	160616	9419		odu4=rmba : start version getted off modem loading
		9420		-- : usart1 rate 115200
		9421		-- : maked some to have answers on rs485e
		9422		odu2=rmb : some changes in remote; tuts can view!!! - use file odu4 - this is wrong!
		9423		odu4=rmba : is view on RNMS!!!!!!!!!!!!!!!!!!!!!!!
		9424		-- : get off debug print
21405  160617	9425		-- : get off modem and transit operations
		9426t		odu2_maket : can read configs to rnms
		9427 9428       odu2 : make nev variants for modulation
		9429		-- : make printing in test mode 0x50 data from updown channel
		9430t		odu2_maket : make configfiletext2 and 50 configfiles -loaded
		9431		-- : sucsess in load modes from rnms
		9432		odu2 : more loaded if module
21406	160619	9433		-- : can be viewed UPP!!!!!! (length()+3 => Length()+ 2)
		9434		-- : do not restarted xilinx at start programm
		9435		-- : have lock of demodulator
		9436		-- : make setting filters to symbolrate
		9437		-- : work modem channel!
21407	160620	9438t		-- : can be read manufecturer of flash!!!!!
		9439t		-- : property read status of flash
		9440t		-- : property read data from flash
21408	160621  9441		-- : maked some for debug
		9442		-- : compare 300 bites to flash  - ok!!!!!!	
		9443		pum_v_b   : start version - not used
21409	160622	9444		odu4=rmba : maked some for operating pins	
		9445		odu2 : can read flach of xilinx
		9446		odu4=rmba : disabled interrupts
		9447		odu2 : can write xilinx : need set "mod0"
21410	160623	9448		odu2 : send commands to types 0x9 and 0xa  from max to edik
		9449		-- : can read version of xilinx mod0
21411	160624 9450t		odu2 : test compilation without interrupts and without xilinx : property 					working with edik as rmb-a
		9451		odu2 :" do not writed id at start; acm olwais enabled
		9452		odu4 : can be operated to edik
		9453		-- : removed debug print to eth
21412	160625	9454		-- : maked test mode22: set tesgen140
		9455		-- : property init pins pb100 and pb101
		9456		odu2 : can view pum-v in far end
21413	160627	9457		-- : maked some to eth_tranzit will can working
		9458		-- : do not changed self freq where changed freq in analog relay
21413	160628	9459		-- : maked some to have modem channel
		9460t		-- : added remote from pu_m - do not get some
		9461		-- : view modem channel
		9462		-- : second try remove running self stack for 485 commands
		9463		-- : can view modem line
		9464		-- : maked some for do not run commans of enover modem
		9465		-- : can view two ends!
		9466t		-- : try make eth_transit
		9467		-- : some little changes
		9468		-- : added inits embmsg232 v 1016
21414	160629	9469		-- : maked buffer size to 4 messages
		9470		-- : maked MAC address for rs485E : 0xff ff ff ff ff - property work in rnms!!!! 
21415	160630	9471		-- : support snmp
		9472		-- : maked keep and operate ten_mhz
		9473t		-- : on send with maket plata work eth_transit from rs232 (imput from comp - to debug!)stack
		9474		-- : any step to make eth_tranzit
		9475		-- : next step view two ends if writed to first modem; try full stack
		9476 		-- : maked from 9473 : work eth_tranzit from near end
21416	160701	9477		-- : if restart near modem with working rnms : can wiew far modem and eth_tranzit moodem!!!!!!
		9478t		-- : if remove sendstatus() - start momentally!
		9479		-- : without ethernet debug print!
		9480		-- : ucomment UpdateErrors and comment  #define DEBUG_ETH_TRANZIT
		9481		-- : maked port for change ten_mhz : 0x7D
		9482		-- : make operating function for 10 MHz 
21417	160704	9483		-- : change counting errors -olwais fec errors
		9484		-- : --
		9485		odu4 : make big brogramm size for writing
		9486		odu2 : keep command asu of state of ethernet in rom!
21418	160705	9487		-- : v1026 : really tested on line - somtime do not working!
		9488		-- : send to debugger length of transmitted packet - working!
21419	160706	9489		-- : added sending every 10 s 0x55 to modem channel
21420	160708	9490		-- : maked protection mode = 0 (none) 
		9491		-- : maked celling koef for 10 mhz output
21421	160711	9492		odu2 : maked send status about ten_mhz
		9493		-- : load disabling 10 MHz out; maked can setting mtmode from rnms (port 0x7C)
21422	160712	9494		-- : make portfor reading temp
		9495		-- : delete one error and getted on DEBUG_ETH_TRANSIT
		9496		-- : added check_crc in 485E
21423	160713	9497		-- : add debug_transit : statistics better!
21424	160714	9498		-- : read reset_register before read version api : if is in zero - do not read
		9499		-- : add delay 1s after reset provingent
		9500		-- : remove debug print
21425	160719	9501t		-- : is found bug!!!! in parsing data from stream to 0xAA do not setted to zero any flag!!!!
		9502		-- : maked right init to 0xaa to all streams.
		9503		-- : in hardware[7] can be viewed temperature
21426	160721	9504		odu4 :  maked right init to 0xaa to all streams.
21427	160729	9505		odu2 : get off printEthLongHex(embMsgA.FullSize()); 
		9506		prm_pch_spi_eth_uart : start this projekt
		9507t		prm_pch_spi_eth_uart : can view data on usart1 output
		9508t		prm_pch_spi_eth_uart : can set freq without filters
		9509		prm_pch_spi_eth_uart : can set all; inputs state not keeped
		9510		prm_pch_spi_eth_uart : keeped prm_inp
		9511		-- : set freq olwais
		9512		--: some changing in delays
		9513 9514	-- : --
21428	160730	9515		-- : -- 
		9516		-- : DELETE ALL INITS : ALL CAN BE OPERATED!!!!
		9517		-- : make ver 1050
		9518		-- : are changed delays
21429	160822	9519		odu2 : send to 485e not broadcast pakets
		9520		odu4 : --
21430	160823	9521		odu2 : start making udp
		9522t		--: maked many sokets for datagramm
		9523t		-- : can be write prog to tftp - comment declaring buffer
		9524		-- : maked ehoserver for udp in hello.c
		9525		-- : udp pakets are sended
		9526		-- : compiled for time to live = 2
21431	160824	9527t		-- : maked try send abu data one time in one sec
		9528t		-- : if set inddress to 0 - can receive far modem!!!!!
		9529t		-- : can send broadcast and receive from far modem udp pakets
		9530t		-- : receive on port 2010 transmit on 2011
		9531		-- : view two modems on asu!!!!! need get off send to transit buffer from 232 channel!!!!
21432	160825	9532t		-- : do not hangt if try send socket : maked control of length!!!
		9533		-- : removed debug data
		9534		-- : maked setting back big TTL
		9535		-- : pragmas were more right writed 
		9536		-- : full maked release for rs485E on udp pakets : #define USE_SOCKETSD_485; need make commands 0x60 and 0x61	
21433	160826	9537t		-- : maked commands 0x60 0x61 and setting ipaddressudp for socket
		9538		-- : get off maket pragma - this for real using
		9539		-- : maked use ipaddr as mac address of local device
		9540		-- : changed commands 60 and 61
		9541		-- : compiled as not maket_plata
21434	160831	9542		prm_pch_spi_eth_uart : maked reading version soft and serial number -command "D"
		9543		-- : maked checking frequency
21435	160901	9544		-- : maked Gateway
21436	160906	9545		odu2 : chacked lungth from updown channel : 32 byte!!! - do not read from message
		9546		-- : maked len 34 bytes
		9547t		-- : do not clean updown
21437	160907	9548t		-- : ignore 0xAA in updown answer in 5 position
		9549t		-- : -- in 5 and 3 positions
		9550		-- : maked at start default set MEthMaxF.Value and MEthVlanP.Value
21438	160908  9551		-- : makeed setting default ethernet parameters in case variant == variant1
		9552		-- : disable 1000Bit rate for autoneg mod to have 100 full duplex : in  SetEthPhyParams();
21439	160912	9553		odu4 : all prepared to debug to ethernet : what is received
		9554t		-- : test version : imitate edik answer
21440	160914	9555		dmu6 : operate with max programm
		9556		--  : makew waiting until loadded xilinx and  dds is loaded after this
		9557		-- : are property loaded ddses
		9558		-- : prorirty writed xilinx
		
				
	


 		
	
		







		







		



		
	

		











 


		

































			




						












 













	
	
		







		
	











	
			




















