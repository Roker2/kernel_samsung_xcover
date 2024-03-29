#ifndef _SAIN_REG_DATA_H
#define	_SAIN_REG_DATA_H

//============================================================================
#define	MAX_REG_COUNT	256

typedef struct
{
	s16 reg_val;
	u8 valid;
}_sain_reg_data;
const _sain_reg_data m_reg_data[MAX_REG_COUNT] = { 
	//{value, valid}
	{0, 0}, // 00, RESERVED
	{0, 0}, // 01, RESERVED
	{0, 0}, // 02, RESERVED
	{0, 0}, // 03, RESERVED
	{0, 0}, // 04, RESERVED
	{0, 0}, // 05, RESERVED
	{0, 0}, // 06, RESERVED
	{0, 0}, // 07, RESERVED
	{0, 0}, // 08, RESERVED
	{0, 0}, // 09, RESERVED
	{0, 0}, // 0A, RESERVED
	{0, 0}, // 0B, RESERVED
	{0, 0}, // 0C, RESERVED
	{0, 0}, // 0D, RESERVED
	{0, 0}, // 0E, RESERVED
	{0, 0}, // 0F, RESERVED
	{0, 1}, // 10, TOUCH MODE
	{150, 1}, // 11, SENSITIVITY TH.
	{4, 1}, // 12, FIR COEFFICIENT
	{11, 0}, // 13, CHIP REVISION
	{79, 1}, // 14, INTERNAL FLAG
	{15, 1}, // 15, CHARGING STEP LIMIT
	{0, 1}, // 16, CHARGING MODE
	{1, 1}, // 17, AUTO CHARGING DETECT MODE
	{528, 1}, // 18, SW_FIR COEFFICIENT
	{16, 1}, // 19, HW_STYLUS MOVING FIR
	{16, 1}, // 1A, HW_FINGER MOVING FIR
	{4, 1}, // 1B, SW WIDTH FIR
	{1000, 1}, // 1C, CHARGING MODE SENSITIVITY TH
	{-20, 1}, // 1D, AUTO CHARING LIMIT VALUE
	{4, 1}, // 1E, AUTO CHARING STRENGTH RATIO
	{14, 1}, // 1F, AUTO CHARGING LIMIT CNT
	{16, 1}, // 20, TOTAL NUM OF X
	{12, 1}, // 21, TOTAL NUM OF Y
	{5, 1}, // 22, SUPPORTED FINGER NUM
	{0, 1}, // 23, AFE FREQUENCY
	{0, 0}, // 24, CURRENT RAW VARIATION
	{0, 0}, // 25, RESERVED
	{0, 0}, // 26, RESERVED
	{0, 0}, // 27, RESERVED
	{320, 1}, // 28, RESOLUTION OF X
	{480, 1}, // 29, RESOLUTION OF Y
	{45, 1}, // 2A, 1st BASELINE VARIATION
	{40, 1}, // 2B, 2nd BASELINE VARIATION
	{20, 1}, // 2C, 1st BASELINE PERIOD
	{1, 1}, // 2D, 2nd BASELINE PERIOD
	{3000, 1}, // 2E, BASELINE FORCE PERIOD
	{0, 0}, // 2F, RESERVED
	{850, 1}, // 30, CALIBRATION REFERENCE
	{0, 0}, // 31, DEFAULT N COUNT
	{0, 0}, // 32, N OF CALIBRATION
	{0, 0}, // 33, CALIBRATION ACCURACY
	{255, 1}, // 34, CALIBRATION MAX N
	{0, 1}, // 35, PERIODICAL INTERRUPT INTERVAL
	{1, 1}, // 36, COORD ORIENTATION
	{0, 0}, // 37, RESERVED
	{80, 1}, // 38, WIDTH(WEIGHT) COEF
	{0, 1}, // 39, AFE MODE
	{0, 0}, // 3A, RESERVED
	{0, 0}, // 3B, RESERVED
	{0, 0}, // 3C, RESERVED
	{0, 0}, // 3D, RESERVED
	{0, 0}, // 3E, RESERVED
	{0, 0}, // 3F, RESERVED
	{256, 1}, // 40, X00_01_DRIVE_NUM
	{770, 1}, // 41, X02_03_DRIVE_NUM
	{1284, 1}, // 42, X04_05_DRIVE_NUM
	{1798, 1}, // 43, X06_07_DRIVE_NUM
	{4625, 1}, // 44, X08_09_DRIVE_NUM
	{2312, 1}, // 45, X10_11_DRIVE_NUM
	{2826, 1}, // 46, X12_13_DRIVE_NUM
	{3340, 1}, // 47, X14_15_DRIVE_NUM
	{3854, 1}, // 48, X16_17_DRIVE_NUM
	{4880, 1}, // 49, X18_19_DRIVE_NUM
	{0, 0}, // 4A, RESERVED
	{0, 0}, // 4B, RESERVED
	{0, 0}, // 4C, RESERVED
	{0, 0}, // 4D, RESERVED
	{0, 0}, // 4E, RESERVED
	{0, 0}, // 4F, RESERVED
	{69, 1}, // 50, FINGER COEF X GAIN
	{150, 1}, // 51, Y0 SENSITIVITY TH
	{150, 1}, // 52, LAST Y SENSITIVITY TH
	{150, 1}, // 53, X0 SENSITIVITY TH
	{150, 1}, // 54, LAST X SENSITIVITY TH
	{2, 1}, // 55, ACTIVE SENSITIVITY COEF
	{500, 1}, // 56, BUTTON SENSITIVITY TH
	{0, 0}, // 57, RESERVED
	{0, 0}, // 58, RESERVED
	{0, 0}, // 59, RESERVED
	{0, 0}, // 5A, RESERVED
	{0, 0}, // 5B, RESERVED
	{0, 0}, // 5C, RESERVED
	{0, 0}, // 5D, RESERVED
	{0, 0}, // 5E, RESERVED
	{0, 0}, // 5F, RESERVED
	{0, 1}, // 60, X POINT SHIFT
	{0, 1}, // 61, Y POINT SHIFT
	{30583, 1}, // 62, BDATA EDGE COEF1
	{17476, 1}, // 63, BDATA EDGE COEF2
	{13107, 1}, // 64, BDATA EDGE COEF3
	{30583, 1}, // 65, BDATA CORNER COEF1
	{21845, 1}, // 66, BDATA CORNER COEF2
	{13107, 1}, // 67, BDATA CORNER COEF3
	{0, 0}, // 68, RESERVED
	{0, 0}, // 69, RESERVED
	{0, 0}, // 6A, RESERVED
	{0, 0}, // 6B, RESERVED
	{0, 0}, // 6C, RESERVED
	{0, 0}, // 6D, RESERVED
	{0, 0}, // 6E, RESERVED
	{0, 0}, // 6F, RESERVED
	{0, 1}, // 70, SUPPORTED BUTTON NUM
	{0, 1}, // 71, BUTTON LINE TYPE
	{16, 1}, // 72, BUTTON LINE NUM
	{5, 1}, // 73, BUTTON RANGE
	{9, 1}, // 74, BUTTON_0 START NODE
	{2, 1}, // 75, BUTTON_1 START NODE
	{0, 1}, // 76, BUTTON_2 START NODE
	{0, 1}, // 77, BUTTON_3 START NODE
	{0, 1}, // 78, BUTTON_4 START NODE
	{0, 1}, // 79, BUTTON_5 START NODE
	{0, 1}, // 7A, BUTTON_6 START NODE
	{0, 1}, // 7B, BUTTON_7 START NODE
	{2, 1}, // 7C, MVAVG_1_VELOCITY
	{1040, 1}, // 7D, MVAVG_1_SW_INC
	{0, 0}, // 7E, RESERVED
	{0, 0}, // 7F, RESERVED
	{0, 0}, // 80, RESERVED
	{0, 0}, // 81, RESERVED
	{0, 0}, // 82, RESERVED
	{0, 0}, // 83, RESERVED
	{0, 0}, // 84, RESERVED
	{0, 0}, // 85, RESERVED
	{0, 0}, // 86, RESERVED
	{0, 0}, // 87, RESERVED
	{0, 0}, // 88, RESERVED
	{0, 0}, // 89, RESERVED
	{0, 0}, // 8A, RESERVED
	{0, 0}, // 8B, RESERVED
	{0, 0}, // 8C, RESERVED
	{0, 0}, // 8D, RESERVED
	{0, 0}, // 8E, RESERVED
	{0, 0}, // 8F, RESERVED
	{0, 0}, // 90, RESERVED
	{0, 0}, // 91, RESERVED
	{0, 0}, // 92, RESERVED
	{0, 0}, // 93, RESERVED
	{0, 0}, // 94, RESERVED
	{0, 0}, // 95, RESERVED
	{0, 0}, // 96, RESERVED
	{0, 0}, // 97, RESERVED
	{0, 0}, // 98, RESERVED
	{0, 0}, // 99, RESERVED
	{0, 0}, // 9A, RESERVED
	{0, 0}, // 9B, RESERVED
	{0, 0}, // 9C, RESERVED
	{0, 0}, // 9D, RESERVED
	{0, 0}, // 9E, RESERVED
	{0, 0}, // 9F, RESERVED
	{2, 1}, // A0, HOLD THRESHOLD
	{2, 1}, // A1, REACTION COUNT
	{80, 1}, // A2, PALM REJECT TRESHHOLD
	{80, 1}, // A3, NOISE REJECT TRESHHOLD
	{2, 1}, // A4, EDGE COEFFICIENT
	{1000, 1}, // A5, STYLUS HW THRESHHOLD
	{170, 1}, // A6, ASSUME UP THRESHHOLD
	{0, 1}, // A7, NOISE REJECT HILO RATIO
	{3, 1}, // A8, CUTOFF NOISE BDATA RATIO
	{4, 1}, // A9, CUTOFF NOISE WIDTH RATIO
	{0, 0}, // AA, EEPROM INFO
	{1, 1}, // AB, REGISTER DATA VERSION
	{0, 1}, // AC, STYLUS HOLD THRESHOLD
	{0, 0}, // AD, RESERVED
	{0, 0}, // AE, RESERVED
	{0, 0}, // AF, RESERVED
	{5, 1}, // B0, BDATA COEF1
	{3, 1}, // B1, BDATA COEF2
	{3, 1}, // B2, BDATA COEF3
	{500, 1}, // B3, FINGER ATTACH VALUE
	{100, 1}, // B4, STYLUS ATTACH VALUE
	{0, 0}, // B5, OPT Q RESOLUTION
	{165, 1}, // B6, EDGE Q BIAS1_1
	{0, 1}, // B7, DELAY FOR HOST
	{165, 1}, // B8, EDGE Q BIAS2_1
	{2, 1}, // B9, BUTTON REACTION CNT
	{165, 1}, // BA, EDGE Q BIAS3_1
	{0, 1}, // BB, INT ASSERT PIN(0=INT PIN)
	{165, 1}, // BC, EDGE Q BIAS4_1
	{0, 0}, // BD, RESERVED
	{145, 1}, // BE, CORNER Q BIAS1_1
	{0, 1}, // BF, VIEW XF OFFSET
	{145, 1}, // C0, CORNER Q BIAS2_1
	{0, 1}, // C1, VIEW XL OFFSET
	{145, 1}, // C2, CORNER Q BIAS3_1
	{0, 1}, // C3, VIEW YF OFFSET
	{145, 1}, // C4, CORNER Q BIAS4_1
	{0, 1}, // C5, VIEW YL OFFSET
	{0, 1}, // C6, I2C VOLT LEVEL(0=3.3V)
	{0, 0}, // C7, RESERVED
	{0, 0}, // C8, RESERVED
	{259, 0}, // C9, FIRMWARE VERSION
	{0, 0}, // CA, RESERVED
	{0, 0}, // CB, RESERVED
	{0, 0}, // CC, RESERVED
	{0, 0}, // CD, RESERVED
	{0, 0}, // CE, RESERVED
	{0, 0}, // CF, RESERVED
	{1284, 1}, // D0, FREQ X NUM 0_1
	{2826, 1}, // D1, FREQ X NUM 2_3
	{3340, 1}, // D2, FREQ X NUM 4_5
	{3854, 1}, // D3, FREQ X NUM 6_7
	{4368, 1}, // D4, FREQ X NUM 8_9
	{4882, 1}, // D5, FREQ X NUM 10_11
	{5396, 1}, // D6, FREQ X NUM 12_13
	{5910, 1}, // D7, FREQ X NUM 14_15
	{10264, 1}, // D8, FREQ X NUM 16_17
	{10280, 1}, // D9, FREQ X NUM 18_19
	{0, 0}, // DA, RESERVED
	{0, 0}, // DB, RESERVED
	{0, 0}, // DC, RESERVED
	{0, 0}, // DD, RESERVED
	{0, 0}, // DE, RESERVED
	{0, 0}, // DF, RESERVED
	{0, 0}, // E0, RESERVED
	{0, 0}, // E1, RESERVED
	{0, 0}, // E2, RESERVED
	{0, 0}, // E3, RESERVED
	{0, 0}, // E4, RESERVED
	{0, 0}, // E5, RESERVED
	{0, 0}, // E6, RESERVED
	{0, 0}, // E7, RESERVED
	{0, 0}, // E8, RESERVED
	{0, 0}, // E9, RESERVED
	{0, 0}, // EA, RESERVED
	{0, 0}, // EB, RESERVED
	{0, 0}, // EC, RESERVED
	{0, 0}, // ED, RESERVED
	{0, 0}, // EE, RESERVED
	{0, 0}, // EF, RESERVED
	{0x080F, 1}, // F0, INT ENABLE FLAG
	{0, 0}, // F1, RESERVED
	{0, 0}, // F2, RESERVED
	{0, 0}, // F3, RESERVED
	{0, 0}, // F4, RESERVED
	{0, 0}, // F5, RESERVED
	{0, 0}, // F6, RESERVED
	{0, 0}, // F7, RESERVED
	{0, 0}, // F8, RESERVED
	{0, 0}, // F9, RESERVED
	{0, 0}, // FA, RESERVED
	{0, 0}, // FB, RESERVED
	{0, 0}, // FC, RESERVED
	{0, 0}, // FD, RESERVED
	{0, 0}, // FE, RESERVED
	{0, 0}, // FF, RESERVED

};
#endif
