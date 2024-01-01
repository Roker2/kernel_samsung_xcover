
const u8 Lynx_UC4a_trans_26MHz_SR8k_SlaveI2S2_MasterI2S1[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
0x54, 0x1B, //ADCAB & DACS @ 48k, ADCCD @ 8k
0x6a, 0x00, //remove auto_sync
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x00, //Offset 0
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
0x24, 0xb0,
0x29, 0xb0,
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
0x1d, 0x10,//0x50,
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
0xa0, 0x08,
0xb0, 0x08,
0xc0, 0x08,
0x66, 0x8f, //I2SB activate
0x63, 0x88, //I2SA activate
};

const u8 Lynx_UC4b_trans_26MHz_SR8k_SlaveI2S2_MasterI2S1[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
0x54, 0x1B, //ADCAB & DACS @ 48k, ADCCD @ 8k
0x6a, 0x00, //remove auto_sync
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x00, //Offset 0
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
0x24, 0xb0, 
0x29, 0xb0,
0xa3, 0x99,
0xa4, 0x40,
//enable mic and ADC2 path
0x5b, 0x0f,
0x10, 0x80,
0x5d, 0x10,
0x1b, 0x3f,
//NB MICL needs to be enabled due to bug in LYNX HW wereby right channel ADC
//doesnt work without the left channel enabled
0x1a, 0x00,
0x13, 0xc0,
0x15, 0x80, 
0x1d, 0x50,
0x9b, 0x88,
0x90, 0x0c,
0x94, 0x88,
0x98, 0x0c,
0x9c, 0x88,
0x90, 0x3f,
0x98, 0x3f,
0x14, 0x07,
0x15, 0x80, 
0xa0, 0x08,
0xb0, 0x08,
0xc0, 0x08,
0x66, 0x8f, //I2SB activate
0x63, 0x88,//0x80, //I2SA unactive
};


const u8 Lynx_UC4a_trans_26MHz_SR16k_SlaveI2S2_MasterI2S1[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
0x54, 0x5B, //ADCAB & DACS @ 48k, ADCCD @ 16k
0x6a, 0x00, //remove auto_sync
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x00, //Offset 0
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
0x24, 0xb0,
0x29, 0xb0,
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
0x1d, 0x10,//0x50,
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
0xa0, 0x08,
0xb0, 0x08,
0xc0, 0x08,
0x66, 0x8f, //I2SB activate
0x63, 0x88, //I2SA activate
};

const u8 Lynx_UC4b_trans_26MHz_SR16k_SlaveI2S2_MasterI2S1[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
0x54, 0x5B, //ADCAB & DACS @ 48k, ADCCD @ 16k
0x6a, 0x00, //remove auto_sync
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x00, //Offset 0
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
0x24, 0xb0, 
0x29, 0xb0,
0xa3, 0x99,
0xa4, 0x40,
//enable mic and ADC2 path
0x5b, 0x0f,
0x10, 0x80,
0x5d, 0x10,
0x1b, 0x3f,
//NB MICL needs to be enabled due to bug in LYNX HW wereby right channel ADC
//doesnt work without the left channel enabled
0x1a, 0x00,
0x13, 0xc0,
0x15, 0x80, 
0x1d, 0x50,
0x9b, 0x88,
0x90, 0x0c,
0x94, 0x88,
0x98, 0x0c,
0x9c, 0x88,
0x90, 0x3f,
0x98, 0x3f,
0x14, 0x07,
0x15, 0x80, 
0xa0, 0x08,
0xb0, 0x08,
0xc0, 0x08,
0x66, 0x8f, //I2SB activate
0x63, 0x88,//0x80, //I2SA unactive
};

const u8 Lynx_UC4a_trans_26MHz_SR48k_SlaveI2S2_MasterI2S1[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
0x54, 0xBB, //ADCAB & DACS @ 48k, ADCCD @ 48k
0x6a, 0x80, //remove auto_sync
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x00, //Offset 0
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
0x24, 0xb0,
0x29, 0xb0,
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
0x1d, 0x10,//0x50,
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
0xa0, 0x08,
0xb0, 0x08,
0xc0, 0x08,
0x66, 0x8f, //I2SB activate
0x63, 0x88, //I2SA activate
};

const u8 Lynx_UC4b_trans_26MHz_SR48k_SlaveI2S2_MasterI2S1[] = {
//System clock & DAI config			
0x50, 0xea,
0x51, 0x07,
0x52, 0x1e,
0x53, 0x82, //13->26M 0x81,
0x54, 0xBB, //ADCAB & DACS @ 48k, ADCCD @ 48k
0x6a, 0x80, //remove auto_sync
0x60, 0x10, //I2SA in master mode
0x61, 0x80, //I2SA 16bit stereo
0x64, 0x10, //I2SB 16bit mono
0x65, 0x00, //Offset 0
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
0x24, 0xb0, 
0x29, 0xb0,
0xa3, 0x99,
0xa4, 0x40,
//enable mic and ADC2 path
0x5b, 0x0f,
0x10, 0x80,
0x5d, 0x10,
0x1b, 0x3f,
//NB MICL needs to be enabled due to bug in LYNX HW wereby right channel ADC
//doesnt work without the left channel enabled
0x1a, 0x00,
0x13, 0xc0,
0x15, 0x80, 
0x1d, 0x50,
0x9b, 0x88,
0x90, 0x0c,
0x94, 0x88,
0x98, 0x0c,
0x9c, 0x88,
0x90, 0x3f,
0x98, 0x3f,
0x14, 0x07,
0x15, 0x80, 
0xa0, 0x08,
0xb0, 0x08,
0xc0, 0x08,
0x66, 0x8f, //I2SB activate
0x63, 0x88,//0x80, //I2SA unactive
};


