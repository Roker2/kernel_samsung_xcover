#ifndef _D1981_USECASE1_REG_H
#define _D1981_USECASE1_REG_H
#if 1 //no SRC

const u8 Lynx_UC1_MICL_MIC1_trans_13MHz_SR16k_SlaveMode[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
//bsw 0x54, 0x55,
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x01, //Offset 1
//OE (enable tristate as required)
0x6a, 0xc1,
//************************************			
//Enable charge pump (fixed VDD mode)		
0x37, 0x01,
0x41, 0x81,//0x89,
0x42, 0x00,
0x43, 0x3c,
0x49, 0x19,
0x4a, 0x13,
0x4b, 0x10,
0x4c, 0x0c,
0x4d, 0x08,
0x5c, 0x04,
0x3b, 0x0b,
0x40, 0x8e,
//***************************************			
//Enable DAC to HP path			
0x7d, 0x0c,
0x5b, 0x0f,
0x5e, 0x11,
//DAC E (receiver)
0x5f, 0x01,
//***************************************
0x2e, 0x1f,
//Enable DAC to SPKR (OUT3) NB NOT Aux out
0xb3, 0xdd,
//0xb3, 0x99,
0xb4, 0x40,
0xb1, 0x09,
0x2c, 0xfe,
0x2c, 0xbe,
//Enable Receiver
0xc3, 0x0c,
0xc1, 0x10,
0xc3, 0x09,
0x2b, 0xff,
0x2b, 0xbf,
0xc4, 0x40,
//Enable HP (DAC1)
0xa3, 0xdd,
0x25, 0x0f,
0x2a, 0x0f,
0x24, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0x29, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0xa3, 0x99,
0xa4, 0x40,
//enable mic and ADC2 path
0x5b, 0x0f,
0x0f, 0x82,
0x5d, 0x10,
0x1b, 0x3f,
// Seb's ADC startup sequence
0x1a, 0x00,
0x13, 0x80,
0x1d, 0x10, //ADC2L->MIC1 0x50,
//E0  8B  0
//93  88  0   // enable voice filters and HPF on the ADC1 (AUX)
0x9b, 0x88,
0x90, 0x0c,
0x94, 0x88,
0x98, 0x0c,
0x9c, 0x88,
0x90, 0x3f,
0x98, 0x3f,
0x12, 0x00,
0x13, 0x9f,
0xa0, 0x88,
0xb0, 0x88,
0xc0, 0x88,
0x66, 0x8f, //I2SB activate
0x63, 0x88, //I2SA activate
//Now remove the PC auto sync
0x6a, 0x01,
};
const u16 Lynx_UC1_MICL_MIC1_trans_13MHz_SR16k_SlaveMode_SIZE = 67;

const u8 Lynx_UC1_MICR_MIC2_trans_13MHz_SR16k_SlaveMode[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
//bsw 0x54, 0x55,
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x01, //Offset 1
//OE (enable tristate as required)
0x6a, 0xc1,
//************************************			
//Enable charge pump (fixed VDD mode)		
0x37, 0x01,
0x41, 0x81,//0x89,
0x42, 0x00,
0x43, 0x3c,
0x49, 0x19,
0x4a, 0x13,
0x4b, 0x10,
0x4c, 0x0c,
0x4d, 0x08,
0x5c, 0x04,
0x3b, 0x0b,
0x40, 0x8e,
//***************************************			
//Enable DAC to HP path			
0x7d, 0x0c,
0x5b, 0x0f,
0x5e, 0x11,
//DAC E (receiver)
0x5f, 0x01, 
//***************************************
0x2e, 0x1f,
//Enable DAC to SPKR (OUT3) NB NOT Aux out
0xb3, 0xdd,
0xb4, 0x40,
0x2c, 0xbf,
0x2c, 0x9f,
//Enable Receiver
0xc3, 0x0c,
0xc3, 0x09,
0x2b, 0xbf,
0x2b, 0x9f,
0xc4, 0x40,
//Enable HP (DAC1)
0xa3, 0xdd,
0x25, 0x0f,
0x2a, 0x0f,
0x24, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0x29, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0xa3, 0x99,
0xa4, 0x40,
//enable mic and ADC2 path
0x5b, 0x0f,
D1981_REG_MICBIAS1, 0x82,
0x5d, 0x10,
0x1b, 0x3f,
//NB MICL needs to be enabled due to bug in LYNX HW wereby right channel ADC
//doesnt work without the left channel enabled
0x1a, 0x00,
0x13, 0xc0,
0x15, 0x80, 
0x1d, 0x40, //ADC2R->MIC2 0x50,
0x9b, 0x88,
0x90, 0x0c,
0x94, 0x88,
0x98, 0x0c,
0x9c, 0x88,
0x90, 0x3f,
0x98, 0x3f,
0x14, 0x07,
0x15, 0x80, 
0xa0, 0x88,
0xb0, 0x88,
0xc0, 0x88,
0x66, 0x8f, //I2SB activate
0x63, 0x80, //I2SA unactive
//Now remove the PC auto sync
0x6a, 0x01,
};
const u16 Lynx_UC1_MICR_MIC2_trans_13MHz_SR16k_SlaveMode_SIZE = 66;

const u8 Lynx_UC1_MICR_MIC3_trans_13MHz_SR16k_SlaveMode[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82,
//bsw 0x54, 0x55,
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x01, //Offset 1
//OE (enable tristate as required)
0x6a, 0xc1,
//************************************			
//Enable charge pump (fixed VDD mode)		
0x37, 0x01,
0x41, 0x81,//0x89,
0x42, 0x00,
0x43, 0x3c,
0x49, 0x19,
0x4a, 0x13,
0x4b, 0x10,
0x4c, 0x0c,
0x4d, 0x08,
0x5c, 0x04,
0x3b, 0x0b,
0x40, 0x8e,
//***************************************			
//Enable DAC to HP path			
0x7d, 0x0c,
0x5b, 0x0f,
0x5e, 0x11,
//DAC E (receiver)
0x5f, 0x01, 
//***************************************
0x2e, 0x1f,
//Enable DAC to SPKR (OUT3) NB NOT Aux out
0xb3, 0xdd,
0xb4, 0x40,
0x2c, 0xbf,
0x2c, 0x9f,
//Enable Receiver
0xc3, 0x0c,
0xc3, 0x09,
0x2b, 0xbf,
0x2b, 0x9f,
0xc4, 0x40,
//Enable HP (DAC1)
0xa3, 0xdd,
0x25, 0x0f,
0x2a, 0x0f,
0x24, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0x29, 0x90,	// 0xb0,	// Keep output undriven utill HP DC offset stabilizes
0xa3, 0x99,
0xa4, 0x40,
//enable mic3 and ADC2 path
0x5b, 0x0f,
0x0f, 0x8a, //0x82, //0x80, //micbias 2
0x5d, 0x10,
0x1b, 0xff, //Adding MIC3 settings
//NB MICL needs to be enabled due to bug in LYNX HW wereby right channel ADC
//doesnt work without the left channel enabled
0x1a, 0x00,
0x13, 0xc0,
0x19, 0x80, 
0x1d, 0x80,//ADC2R->MIC3 0x90, //muxing mic3 with ADC2
0x9b, 0x88,
0x90, 0x0c,
0x94, 0x88,
0x98, 0x0c,
0x9c, 0x88,
0x90, 0x3f,
0x98, 0x3f,
0x18, 0x07,
0x19, 0x80, 
0xa0, 0x88,
0xb0, 0x88,
0xc0, 0x88,
0x66, 0x8f, //I2SB activate
0x63, 0x88, //I2SA activate
//Now remove the PC auto sync
0x6a, 0x01,
};


#else
const u8 Lynx_UC1_MICL_MIC1_trans_13MHz_SR16k_SlaveMode[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
//0x54, 0x5B, //ADCAB & DACS @ 48k, ADCCD @ 16k
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x00, //bsw 0x01, //Offset 1
//OE (enable tristate as required)
0x6a, 0xc0,
//************************************			
//Enable charge pump (fixed VDD mode)		
0x37, 0x01,
0x41, 0x81,//0x89,
0x42, 0x00,
0x43, 0x3c,
0x49, 0x19,
0x4a, 0x13,
0x4b, 0x10,
0x4c, 0x0c,
0x4d, 0x08,
0x5c, 0x04,
0x3b, 0x0b,
0x40, 0x8e,
//***************************************			
//Enable DAC to HP path			
0x7d, 0x0c,
0x5b, 0x0f,
0x5e, 0x11,
//DAC E (receiver)
0x5f, 0x01,
//***************************************
0x2e, 0x1f,
//Enable DAC to SPKR (OUT3) NB NOT Aux out
0xb3, 0xdd,
//0xb3, 0x99,
0xb4, 0x40,
0xb1, 0x09,
0x2c, 0xfe,
0x2c, 0xbe,
//Enable Receiver
0xc3, 0x0c,
0xc1, 0x10,
0xc3, 0x09,
0x2b, 0xff,
0x2b, 0xbf,
0xc4, 0x40,
//Enable HP (DAC1)
0xa3, 0xdd,
0x25, 0x0f,
0x2a, 0x0f,
0x24, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0x29, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0xa3, 0x99,
0xa4, 0x40,
//enable mic and ADC2 path
0x5b, 0x0f,
D1981_REG_MICBIAS2, 0x82,
0x5d, 0x10,
0x1b, 0x3f,
// Seb's ADC startup sequence
0x1a, 0x00,
0x13, 0x80,
0x1d, 0x10, //ADC2L->MIC1 0x50,
//E0  8B  0
//93  88  0   // enable voice filters and HPF on the ADC1 (AUX)
0x9b, 0x88,
0x90, 0x0c,
0x94, 0x88,
0x98, 0x0c,
0x9c, 0x88,
0x90, 0x3f,
0x98, 0x3f,
0x12, 0x00,
0x13, 0x9f,
0xa0, 0x08, //enable HiFi Filters
0xb0, 0x08, //enable HiFi Filters
0xc0, 0x08, //enable HiFi Filters
0x66, 0x8f, //I2SB activate
0x63, 0x88, //I2SA activate
//Now remove the PC auto sync
0x6a, 0x00,
};
const u16 Lynx_UC1_MICL_MIC1_trans_13MHz_SR16k_SlaveMode_SIZE = 67;

const u8 Lynx_UC1_MICR_MIC2_trans_13MHz_SR16k_SlaveMode[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
//0x54, 0x5B, //ADCAB & DACS @ 48k, ADCCD @ 16k
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x00, //bsw 0x01, //Offset 1
//OE (enable tristate as required)
0x6a, 0xc0,
//************************************			
//Enable charge pump (fixed VDD mode)		
0x37, 0x01,
0x41, 0x81,//0x89,
0x42, 0x00,
0x43, 0x3c,
0x49, 0x19,
0x4a, 0x13,
0x4b, 0x10,
0x4c, 0x0c,
0x4d, 0x08,
0x5c, 0x04,
0x3b, 0x0b,
0x40, 0x8e,
//***************************************			
//Enable DAC to HP path			
0x7d, 0x0c,
0x5b, 0x0f,
0x5e, 0x11,
//DAC E (receiver)
0x5f, 0x01, 
//***************************************
0x2e, 0x1f,
//Enable DAC to SPKR (OUT3) NB NOT Aux out
0xb3, 0xdd,
0xb4, 0x40,
0x2c, 0xbf,
0x2c, 0x9f,
//Enable Receiver
0xc3, 0x0c,
0xc3, 0x09,
0x2b, 0xbf,
0x2b, 0x9f,
0xc4, 0x40,
//Enable HP (DAC1)
0xa3, 0xdd,
0x25, 0x0f,
0x2a, 0x0f,
0x24, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0x29, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0xa3, 0x99,
0xa4, 0x40,
//enable mic and ADC2 path
0x5b, 0x0f,
D1981_REG_MICBIAS1, 0x82,
0x5d, 0x10,
0x1b, 0x3f,
//NB MICL needs to be enabled due to bug in LYNX HW wereby right channel ADC
//doesnt work without the left channel enabled
0x1a, 0x00,
0x13, 0xc0,
0x15, 0x80, 
0x1d, 0x40, //ADC2R->MIC2 0x50,
0x9b, 0x88,
0x90, 0x0c,
0x94, 0x88,
0x98, 0x0c,
0x9c, 0x88,
0x90, 0x3f,
0x98, 0x3f,
0x14, 0x07,
0x15, 0x80, 
0xa0, 0x08, //enable HiFi Filters
0xb0, 0x08, //enable HiFi Filters
0xc0, 0x08, //enable HiFi Filters
0x66, 0x8f, //I2SB activate
0x63, 0x80, //I2SA unactive
//Now remove the PC auto sync
0x6a, 0x00,
};
const u16 Lynx_UC1_MICR_MIC2_trans_13MHz_SR16k_SlaveMode_SIZE = 66;

const u8 Lynx_UC1_MICR_MIC3_trans_13MHz_SR16k_SlaveMode[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82,
//0x54, 0x5B,
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x00, //bsw 0x01, //Offset 1
//OE (enable tristate as required)
0x6a, 0xc0,
//************************************			
//Enable charge pump (fixed VDD mode)		
0x37, 0x01,
0x41, 0x81,//0x89,
0x42, 0x00,
0x43, 0x3c,
0x49, 0x19,
0x4a, 0x13,
0x4b, 0x10,
0x4c, 0x0c,
0x4d, 0x08,
0x5c, 0x04,
0x3b, 0x0b,
0x40, 0x8e,
//***************************************			
//Enable DAC to HP path			
0x7d, 0x0c,
0x5b, 0x0f,
0x5e, 0x11,
//DAC E (receiver)
0x5f, 0x01, 
//***************************************
0x2e, 0x1f,
//Enable DAC to SPKR (OUT3) NB NOT Aux out
0xb3, 0xdd,
0xb4, 0x40,
0x2c, 0xbf,
0x2c, 0x9f,
//Enable Receiver
0xc3, 0x0c,
0xc3, 0x09,
0x2b, 0xbf,
0x2b, 0x9f,
0xc4, 0x40,
//Enable HP (DAC1)
0xa3, 0xdd,
0x25, 0x0f,
0x2a, 0x0f,
0x24, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0x29, 0x90,	// 0xb0, 	// Keep output undriven utill HP DC offset stabilizes
0xa3, 0x99,
0xa4, 0x40,
//enable mic3 and ADC2 path
0x5b, 0x0f,
D1981_REG_MICBIAS2, 0x82, //0x80, //micbias 2
0x5d, 0x10,
0x1b, 0xff, //Adding MIC3 settings
//NB MICL needs to be enabled due to bug in LYNX HW wereby right channel ADC
//doesnt work without the left channel enabled
0x1a, 0x00,
0x13, 0xc0,
0x19, 0x80, 
0x1d, 0x80,//ADC2R->MIC3 0x90, //muxing mic3 with ADC2
0x9b, 0x88,
0x90, 0x0c,
0x94, 0x88,
0x98, 0x0c,
0x9c, 0x88,
0x90, 0x3f,
0x98, 0x3f,
0x18, 0x07,
0x19, 0x80, 
0xa0, 0x08, //enable HiFi Filters
0xb0, 0x08, //enable HiFi Filters
0xc0, 0x08, //enable HiFi Filters
0x66, 0x8f, //I2SB activate
0x63, 0x88, //I2SA activate
//Now remove the PC auto sync
0x6a, 0x00,
};
#endif
#endif
