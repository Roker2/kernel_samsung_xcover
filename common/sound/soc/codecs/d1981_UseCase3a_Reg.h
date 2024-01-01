// /home/dchen/lynx_utils/dsp_releases/070311_trunk/scripts/UseCase3a/LynxRegSetupFiles

/*
    //Setup codec registers for use case 3a
    d1981_soc_write(codec, 0x50, 0x45); //PLL setup for 13M ref clock
	d1981_soc_write(codec, 0x51, 0x19);
	d1981_soc_write(codec, 0x52, 0x1B);
    d1981_soc_write(codec, 0x53, 0x81);
	d1981_soc_write(codec, 0x54, 0xAA); //DACs and ADCs at 44.1K
	d1981_soc_write(codec, 0x60, 0x14); //AIFA for master and 64bit clock    
	d1981_soc_write(codec, 0x61, 0x83); //master mode pcm word length 32bit    

*/
const u8 Lynx_UC3A_Trans_13MHz_SR44_1k_MasterMode[] = {
//***********************************			
//System clock & DAI config			
0x50, 0x45,
0x51, 0x19,
0x52, 0x1b,
0x53, 0x82, //13->26M 0x81,
0x54, 0xaa,
0x60, 0x10, //bsw 0x14,
0x61, 0x80, //bsw 0x83,
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
//***************************************			
//Enable DAC to SPKR (OUT3) and to AUX_OUT (OUT4) path			
//B4	C0	0   //DAC 3 softmute enable
0xb3, 0xdd,
0xb3, 0x99,
0x2c, 0xff,
0x2c, 0xbe,
0x2d, 0xff,
0x2d, 0xbf,

0x2e, 0x1f,
0xa4, 0xc0,
0xa3, 0xdd,
0x25, 0x0f,
0x2a, 0x0f,
0x24, 0x90,
0x29, 0x90,
0xa3, 0x99,
0xa4, 0x40,
0x63, 0x88,	 //I2SA active
0x6a, 0x00,
};
#define Lynx_UC3A_Trans_13MHz_SR44_1k_MasterMode_SIZE	(sizeof(Lynx_UC3A_Trans_13MHz_SR44_1k_MasterMode)/2)

