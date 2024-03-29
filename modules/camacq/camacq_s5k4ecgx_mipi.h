  /*
 *
 * sensor set table for camera
 *
. COPYRIGHT (C)  SAMSUNG Electronics CO., LTD (Suwon, Korea). 2010   
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#if !defined(_CAMACQ_S5K4ECGX_MIPI_H_)
#define _CAMACQ_S5K4ECGX_MIPI_H_

/* Include */
#include "camacq_api.h"

/* Global */
#undef GLOBAL

#if !defined(_CAMACQ_API_C_)
#define GLOBAL extern
#else
#define GLOBAL
#endif /* _CAMACQ_API_C_ */

/* Include */
#if defined(WIN32)
#include "cmmfile.h"
#endif /* WIN32 */

/* Definition */
#define _S5K4ECGX_EVT1_MIPI_    //sensor option

#define CAMACQ_MAIN_NAME         "s5k4ecgx"
#define CAMACQ_MAIN_I2C_ID       0x2D	                // 0x5A
#define CAMACQ_MAIN_RES_TYPE   	 CAMACQ_SENSOR_MAIN   // main sensor

#define CAMACQ_MAIN_ISPROBED     0
#define CAMACQ_MAIN_CLOCK        0               
#define CAMACQ_MAIN_YUVORDER     0
#define CAMACQ_MAIN_V_SYNCPOL    0
#define CAMACQ_MAIN_H_SYNCPOL    0
#define CAMACQ_MAIN_SAMPLE_EDGE  0
#define CAMACQ_MAIN_FULL_RANGE   0

#define CAMACQ_MAIN_RST 
#define CAMACQ_MAIN_RST_MUX 
#define CAMACQ_MAIN_EN 
#define CAMACQ_MAIN_EN_MUX 

#define CAMACQ_MAIN_RST_ON          1
#define CAMACQ_MAIN_RST_OFF         0
#define CAMACQ_MAIN_EN_ON           1
#define CAMACQ_MAIN_EN_OFF          0
#define CAMACQ_MAIN_STANDBY_ON      1
#define CAMACQ_MAIN_STANDBY_OFF	    0

#define CAMACQ_MAIN_POWER_CTRL(onoff)
 
#define CAMACQ_MAIN_2BYTE_SENSOR    0
#define CAMACQ_MAIN_AF              1
#define CAMACQ_MAIN_INT_MODE        1   // 0xAABBCCDD is INT_MODE, 0xAA, 0xBB, 0xCC, 0xDD is ARRAY MODE
#define CAMACQ_MAIN_FS_MODE         0
#define CAMACQ_MAIN_PATH_SET_FILE   "/sdcard/sensor/main/%s.dat"

#if (CAMACQ_MAIN_2BYTE_SENSOR)	
#define CAMACQ_MAIN_BURST_MODE 0
#else
#define CAMACQ_MAIN_BURST_MODE 0
#endif /* CAMACQ_MAIN2BYTE_SENSOR */

#define CAMACQ_MAIN_BURST_I2C_TRACE 0
#define CAMACQ_MAIN_BURST_MAX 100

#define CAMACQ_MAIN_REG_FLAG_CNTS 	0x0F12
#define CAMACQ_MAIN_REG_DELAY 		0xFFFF
#define CAMACQ_MAIN_BTM_OF_DATA 	0xFFFFFFFF
#define CAMACQ_MAIN_END_MARKER 		0xFF
#define CAMACQ_MAIN_REG_SET_SZ 		1	// {0xFFFFFFFF} is 1, {0xFFFF,0xFFFF} is 2, {0xFF,0XFF} is 2, {0xFF,0xFF,0xFF,0xFF} is 4, {0xFFFF} is 1
#define CAMACQ_MAIN_REG_DAT_SZ 		4 // {0xFFFFFFFF} is 4, {0xFFFF,0xFFFF} is 2, {0xFF,0XFF} is 1, {0xFF,0xFF,0xFF,0xFF} is 1, {0xFFFF} is 2

#define CAMACQ_MAIN_FRATE_MIN  5
#define CAMACQ_MAIN_FRATE_MAX  30

// MACRO FUNCTIONS BEGIN //////////////////////////////////////////////////////////// 
#if (CAMACQ_MAIN_2BYTE_SENSOR)
#define CAMACQ_MAIN_EXT_RD_SZ 1
#else
#define CAMACQ_MAIN_EXT_RD_SZ 2
#endif /* CAMACQ_MAIN_2BYTE_SENSOR */

#if CAMACQ_MAIN_2BYTE_SENSOR
#define CAMACQ_MAIN_EXT_REG_IS_BTM_OF_DATA(A)		(((A[0]==CAMACQ_MAIN_END_MARKER) && (A[1]==CAMACQ_MAIN_END_MARKER))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_DELAY(A)				((A[0]==CAMACQ_MAIN_REG_DELAY)? 1:0)

#if (CAMACQ_MAIN_FS_MODE==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)\
memcpy(dest, &(srce[idx*CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ]), CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ);
#elif (CAMACQ_MAIN_REG_DAT_SZ==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0] = (srce[idx][0] & 0xFF); dest[1] = (srce[idx][1] & 0xFF);
#elif (CAMACQ_MAIN_REG_DAT_SZ==2)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0] = ((U8)(srce[idx] >> 8) & 0xFF); dest[1] = ((U8)(srce[idx]) & 0xFF);
#endif

#else // CAMACQ_MAIN_2BYTE_SENSOR

#define CAMACQ_MAIN_EXT_REG_IS_BTM_OF_DATA(A)		(((A[0]==CAMACQ_MAIN_END_MARKER) && (A[1]==CAMACQ_MAIN_END_MARKER) && \
(A[2]==CAMACQ_MAIN_END_MARKER) && (A[3]==CAMACQ_MAIN_END_MARKER))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_DELAY(A)				(((A[0]==((CAMACQ_MAIN_REG_DELAY>>8) & 0xFF)) && (A[1]==(CAMACQ_MAIN_REG_DELAY & 0xFF)))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_CNTS(A)				(((A[0]==((CAMACQ_MAIN_REG_FLAG_CNTS>>8) & 0xFF)) && (A[1]==(CAMACQ_MAIN_REG_FLAG_CNTS & 0xFF)))? 1:0)

#if (CAMACQ_MAIN_FS_MODE==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)\
memcpy(dest, &(srce[idx*CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ]), CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ);
#elif (CAMACQ_MAIN_REG_DAT_SZ==2)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0]=((srce[idx][0] >> 8) & 0xFF); dest[1]=(srce[idx][0] & 0xFF); \
dest[2]=((srce[idx][1] >> 8) & 0xFF); dest[3]=(srce[idx][1] & 0xFF);
#elif (CAMACQ_MAIN_REG_DAT_SZ==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0]=srce[idx][0]; dest[1]=srce[idx][1]; \
dest[2]=srce[idx][2]; dest[3]=srce[idx][3];
#elif (CAMACQ_MAIN_REG_DAT_SZ==4)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0] = ((U8)(srce[idx] >> 24) & 0xFF); dest[1] = ((U8)(srce[idx] >> 16) & 0xFF); \
dest[2] = ((U8)(srce[idx] >> 8) & 0xFF); dest[3] = ((U8)(srce[idx]) & 0xFF);			
#endif
#endif /* CAMACQ_2BYTE_SENSOR */
// MACRO FUNCTIONS END /////////////////////////////////////////////////////////// 


/* DEFINE for sensor regs*/
#if( CAMACQ_MAIN_FS_MODE )
#define CAMACQ_MAIN_REG_INIT     "reg_main_init"
#define CAMACQ_MAIN_REG_PLL      "reg_main_pll"
#else
#define CAMACQ_MAIN_REG_INIT     reg_main_init
#define CAMACQ_MAIN_REG_PLL      reg_main_pll
#endif

#define CAMACQ_MAIN_REG_PREVIEW                 reg_main_preview
#define CAMACQ_MAIN_REG_SNAPSHOT                reg_main_snapshot
#define CAMACQ_MAIN_REG_MIDLIGHT                reg_main_midlight
#define CAMACQ_MAIN_REG_HIGHLIGHT               reg_main_highlight
#define CAMACQ_MAIN_REG_LOWLIGHT                reg_main_lowlight
#define CAMACQ_MAIN_REG_NIGHTSHOT_ON            reg_main_nightshot_on
#define CAMACQ_MAIN_REG_NIGHTSHOT_OFF           reg_main_nightshot_off
#define CAMACQ_MAIN_REG_NIGHTSHOT               reg_main_nightshot

#define CAMACQ_MAIN_REG_WB_AUTO                 reg_main_wb_auto
#define CAMACQ_MAIN_REG_WB_DAYLIGHT             reg_main_wb_daylight
#define CAMACQ_MAIN_REG_WB_CLOUDY               reg_main_wb_cloudy
#define CAMACQ_MAIN_REG_WB_INCANDESCENT         reg_main_wb_incandescent
#define CAMACQ_MAIN_REG_WB_FLUORESCENT          reg_main_wb_fluorescent
#define CAMACQ_MAIN_REG_WB_TWILIGHT             reg_main_wb_twilight
#define CAMACQ_MAIN_REG_WB_TUNGSTEN             reg_main_wb_tungsten
#define CAMACQ_MAIN_REG_WB_OFF                  reg_main_wb_off
#define CAMACQ_MAIN_REG_WB_HORIZON              reg_main_wb_horizon
#define CAMACQ_MAIN_REG_WB_SHADE                reg_main_wb_shade

#define CAMACQ_MAIN_REG_EFFECT_NONE             reg_main_effect_none
#define CAMACQ_MAIN_REG_EFFECT_GRAY             reg_main_effect_gray // mono, blackwhite
#define CAMACQ_MAIN_REG_EFFECT_NEGATIVE         reg_main_effect_negative
#define CAMACQ_MAIN_REG_EFFECT_SOLARIZE         reg_main_effect_solarize
#define CAMACQ_MAIN_REG_EFFECT_SEPIA            reg_main_effect_sepia
#define CAMACQ_MAIN_REG_EFFECT_POSTERIZE        reg_main_effect_posterize
#define CAMACQ_MAIN_REG_EFFECT_WHITEBOARD       reg_main_effect_whiteboard
#define CAMACQ_MAIN_REG_EFFECT_BLACKBOARD       reg_main_effect_blackboard
#define CAMACQ_MAIN_REG_EFFECT_AQUA             reg_main_effect_aqua
#define CAMACQ_MAIN_REG_EFFECT_SHARPEN          reg_main_effect_sharpen
#define CAMACQ_MAIN_REG_EFFECT_VIVID            reg_main_effect_vivid
#define CAMACQ_MAIN_REG_EFFECT_GREEN            reg_main_effect_green
#define CAMACQ_MAIN_REG_EFFECT_SKETCH           reg_main_effect_sketch

#define CAMACQ_MAIN_REG_METER_MATRIX            reg_main_meter_matrix
#define CAMACQ_MAIN_REG_METER_CW                reg_main_meter_cw
#define CAMACQ_MAIN_REG_METER_SPOT              reg_main_meter_spot

#define CAMACQ_MAIN_REG_FLIP_NONE               reg_main_flip_none
#define CAMACQ_MAIN_REG_FLIP_WATER              reg_main_flip_water
#define CAMACQ_MAIN_REG_FLIP_MIRROR             reg_main_flip_mirror
#define CAMACQ_MAIN_REG_FLIP_WATER_MIRROR       reg_main_flip_water_mirror


#define CAMACQ_MAIN_REG_FPS_FIXED_5             reg_main_fps_fixed_5
#define CAMACQ_MAIN_REG_FPS_FIXED_7             reg_main_fps_fixed_7
#define CAMACQ_MAIN_REG_FPS_FIXED_10            reg_main_fps_fixed_10
#define CAMACQ_MAIN_REG_FPS_FIXED_15            reg_main_fps_fixed_15
#define CAMACQ_MAIN_REG_FPS_FIXED_20            reg_main_fps_fixed_20
#define CAMACQ_MAIN_REG_FPS_FIXED_25            reg_main_fps_fixed_25
#define CAMACQ_MAIN_REG_FPS_FIXED_30            reg_main_fps_fixed_30
#define CAMACQ_MAIN_REG_FPS_VAR_15              reg_main_fps_var_15

#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_0      reg_main_brightness_level_0
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_1      reg_main_brightness_level_1
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_2      reg_main_brightness_level_2
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_3      reg_main_brightness_level_3
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_4      reg_main_brightness_level_4
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_5      reg_main_brightness_level_5
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_6      reg_main_brightness_level_6
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_7      reg_main_brightness_level_7
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_8      reg_main_brightness_level_8

#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_0 reg_main_expcompensation_level_0
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_1 reg_main_expcompensation_level_1
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_2 reg_main_expcompensation_level_2
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_3 reg_main_expcompensation_level_3
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_4 reg_main_expcompensation_level_4
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_5 reg_main_expcompensation_level_5
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_6 reg_main_expcompensation_level_6
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_7 reg_main_expcompensation_level_7
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_8 reg_main_expcompensation_level_8

#define CAMACQ_MAIN_REG_SET_AF                  reg_main_set_af  // start af
#define CAMACQ_MAIN_REG_OFF_AF                  reg_main_off_af
#define CAMACQ_MAIN_REG_CHECK_AF                reg_main_check_af
#define CAMACQ_MAIN_REG_RESET_AF                reg_main_reset_af
#define CAMACQ_MAIN_REG_MANUAL_AF               reg_main_manual_af    // normal_af
#define CAMACQ_MAIN_REG_MACRO_AF                reg_main_macro_af
#define CAMACQ_MAIN_REG_RETURN_MANUAL_AF        reg_main_return_manual_af
#define CAMACQ_MAIN_REG_RETURN_MACRO_AF         reg_main_return_macro_af
#define CAMACQ_MAIN_REG_SET_AF_NLUX             reg_main_set_af_nlux
#define CAMACQ_MAIN_REG_SET_AF_LLUX             reg_main_set_af_llux
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_1    reg_main_set_af_normal_mode_1
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_2    reg_main_set_af_normal_mode_2
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_3    reg_main_set_af_normal_mode_3
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_1     reg_main_set_af_macro_mode_1
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_2     reg_main_set_af_macro_mode_2
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_3     reg_main_set_af_macro_mode_3

#define CAMACQ_MAIN_REG_ISO_AUTO                reg_main_iso_auto
#define CAMACQ_MAIN_REG_ISO_50                  reg_main_iso_50
#define CAMACQ_MAIN_REG_ISO_100                 reg_main_iso_100
#define CAMACQ_MAIN_REG_ISO_200                 reg_main_iso_200
#define CAMACQ_MAIN_REG_ISO_400                 reg_main_iso_400
#define CAMACQ_MAIN_REG_ISO_800                 reg_main_iso_800
#define CAMACQ_MAIN_REG_ISO_1600                reg_main_iso_1600
#define CAMACQ_MAIN_REG_ISO_3200                reg_main_iso_3200

#define CAMACQ_MAIN_REG_SCENE_AUTO              reg_main_scene_auto  // auto, off
#define CAMACQ_MAIN_REG_SCENE_NIGHT             reg_main_scene_night
#define CAMACQ_MAIN_REG_SCENE_LANDSCAPE         reg_main_scene_landscape
#define CAMACQ_MAIN_REG_SCENE_SUNSET            reg_main_scene_sunset
#define CAMACQ_MAIN_REG_SCENE_PORTRAIT          reg_main_scene_portrait
#define CAMACQ_MAIN_REG_SCENE_SUNRISE           reg_main_scene_sunrise    // dawn
#define CAMACQ_MAIN_REG_SCENE_INDOOR            reg_main_scene_indoor
#define CAMACQ_MAIN_REG_SCENE_PARTY             reg_main_scene_party
#define CAMACQ_MAIN_REG_SCENE_SPORTS            reg_main_scene_sports
#define CAMACQ_MAIN_REG_SCENE_BEACH             reg_main_scene_beach
#define CAMACQ_MAIN_REG_SCENE_SNOW              reg_main_scene_snow
#define CAMACQ_MAIN_REG_SCENE_FALLCOLOR         reg_main_scene_fallcolor
#define CAMACQ_MAIN_REG_SCENE_FIREWORKS         reg_main_scene_fireworks
#define CAMACQ_MAIN_REG_SCENE_CANDLELIGHT       reg_main_scene_candlelight
#define CAMACQ_MAIN_REG_SCENE_AGAINSTLIGHT      reg_main_scene_againstlight  // backlight
#define CAMACQ_MAIN_REG_SCENE_TEXT              reg_main_scene_text

#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M2              reg_main_adjust_contrast_m2
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M1              reg_main_adjust_contrast_m1
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_DEFAULT         reg_main_adjust_contrast_default
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P1              reg_main_adjust_contrast_p1
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P2              reg_main_adjust_contrast_p2

#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M2             reg_main_adjust_sharpness_m2
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M1             reg_main_adjust_sharpness_m1
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_DEFAULT        reg_main_adjust_sharpness_default
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P1             reg_main_adjust_sharpness_p1
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P2             reg_main_adjust_sharpness_p2

#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M2            reg_main_adjust_saturation_m2
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M1            reg_main_adjust_saturation_m1
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_DEFAULT       reg_main_adjust_saturation_default
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P1            reg_main_adjust_saturation_p1
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P2            reg_main_adjust_saturation_p2

#define CAMACQ_MAIN_REG_QCIF                    reg_main_qcif
#define CAMACQ_MAIN_REG_QVGA                    reg_main_qvga
#define CAMACQ_MAIN_REG_CIF                     reg_main_cif
#define CAMACQ_MAIN_REG_VGA                     reg_main_vga
#define CAMACQ_MAIN_REG_1080P		            reg_main_1080P
#define CAMACQ_MAIN_REG_720P			        reg_main_720P
#define CAMACQ_MAIN_REG_800_480			        reg_main_800_480
#define CAMACQ_MAIN_REG_720_480			        reg_main_720_480
#define CAMACQ_MAIN_REG_NOT                     reg_main_not

#define CAMACQ_MAIN_REG_JPEG_5M                 reg_main_jpeg_5m        //2560X1920
#define CAMACQ_MAIN_REG_JPEG_5M_2               reg_main_jpeg_5m_2      // 2592X1944
#define CAMACQ_MAIN_REG_JPEG_W4M                 reg_main_jpeg_w4m      // 2560x1536
#define CAMACQ_MAIN_REG_JPEG_3M                 reg_main_jpeg_3m        // QXGA 2048X1536
#define CAMACQ_MAIN_REG_JPEG_2M                 reg_main_jpeg_2m        // UXGA 1600x1200
#define CAMACQ_MAIN_REG_JPEG_W1_5M               reg_main_jpeg_w1_5m    // 1280x960
#define CAMACQ_MAIN_REG_JPEG_1M                 reg_main_jpeg_1m
#define CAMACQ_MAIN_REG_JPEG_VGA                reg_main_jpeg_vga   //640x480
#define CAMACQ_MAIN_REG_JPEG_WQVGA              reg_main_jpeg_wqvga //420x240
#define CAMACQ_MAIN_REG_JPEG_QVGA               reg_main_jpeg_qvga  //320x240

#define CAMACQ_MAIN_REG_FLICKER_DISABLED        reg_main_flicker_disabled
#define CAMACQ_MAIN_REG_FLICKER_50HZ            reg_main_flicker_50hz
#define CAMACQ_MAIN_REG_FLICKER_60HZ            reg_main_flicker_60hz
#define CAMACQ_MAIN_REG_FLICKER_AUTO            reg_main_flicker_auto

#define CAMACQ_MAIN_REG_AE_LOCK                 reg_main_ae_lock
#define CAMACQ_MAIN_REG_AE_UNLOCK               reg_main_ae_unlock               
#define CAMACQ_MAIN_REG_AWB_LOCK                reg_main_awb_lock
#define CAMACQ_MAIN_REG_AWB_UNLOCK              reg_main_awb_unlock

#define CAMACQ_MAIN_REG_PRE_FLASH_START         reg_main_pre_flash_start
#define CAMACQ_MAIN_REG_PRE_FLASH_END           reg_main_pre_flash_end
#define CAMACQ_MAIN_REG_MAIN_FLASH_START        reg_main_main_flash_start
#define CAMACQ_MAIN_REG_MAIN_FLASH_END          reg_main_main_flash_end

#define CAMACQ_MAIN_REG_FLASH_AE_SET            reg_main_flash_ae_set
#define CAMACQ_MAIN_REG_FLASH_AE_CLEAR          reg_main_flash_ae_clear

//denis_flash_2
#define CAMACQ_MAIN_REG_FLASH_ON_SET            reg_main_flash_on_set        


// image quality
#define CAMACQ_MAIN_REG_JPEG_QUALITY_SUPERFINE reg_main_jpeg_quality_superfine
#define CAMACQ_MAIN_REG_JPEG_QUALITY_FINE      reg_main_jpeg_quality_fine
#define CAMACQ_MAIN_REG_JPEG_QUALITY_NORMAL    reg_main_jpeg_quality_normal

// Format
#define CAMACQ_MAIN_REG_FMT_YUV422 	            reg_main_fmt_yuv422
#define CAMACQ_MAIN_REG_FMT_JPG		            reg_main_fmt_jpg


// NEW
#define CAMACQ_MAIN_REG_SLEEP                   reg_main_sleep
#define CAMACQ_MAIN_REG_WAKEUP                  reg_main_wakeup

#define CAMACQ_MAIN_REG_DTP_ON                   reg_main_dtp_on
#define CAMACQ_MAIN_REG_DTP_OFF                  reg_main_dtp_off


/* Enumeration */

/* Global Value */

GLOBAL const U32 reg_main_sleep[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_wakeup[] 
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_pll[] 
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_dtp_on[] 
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_dtp_off[] 
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;



#if 1 /* 2-LANE */

GLOBAL const U32 reg_main_init[]
#if defined(_CAMACQ_API_C_)
={
/******************************/
0xFCFCD000,          
0x00100001,          
0x10300000,                
0x00140001,

// p100	// W,ait100mSec
0xFFFF0064,
/******************************/

                
0x0028D000,
0x002A1082,   //Driving current Setting     
0x0F120155,	  //d0_d4_cd10 d0_d4_cd10 9:0
0x0F120155,	  //d5_d9_cd10 d5_d9_cd10 9:0
0x0F120055,	  //gpio_cd10 gpio_cd10
0x0F120555,	  //clks_output_cd10 clks_output_cd10 11:0
0x002A100E,
0x0F120000,	  //pclk_delay_r

0x002A007A,
0x0F120000,

              // This register is for FACTORY ONLY. If you change it without prior notification
              // YOU are RESPONSIBLE for the FAILURE that will happen in the future.

              // ISP FE(ADLC)
0x002AE406,
0x0F120092,
0x002AE410,
0x0F123804,
0x002AE41A,
0x0F120010,   //101022 ADD adlcptune_total
0x002AE420,
0x0F120003,
0x0F120060,
0x002AE42E,
0x0F120004,
0x002AF400,
0x0F125A3C,
0x0F120023,
0x0F128080,
0x0F1203AF,
0x0F12000A,
0x0F12AA54,
0x0F120040,
0x0F12464E,
0x0F120240,
0x0F120240,
0x0F120040,
0x0F121000,
0x0F1255FF,   //555C -> 55FF
0x0F12D000,
0x0F120010,
0x0F120202,
0x0F120401,
0x0F120022,
0x0F120088,
0x0F12009F,
0x0F120000,
0x0F121800,
0x0F120088,
0x0F120000,
0x0F122428,
0x0F120000,
0x0F1203EE,
0x0F120000,
0x0F120000,
0x0F120000,
0x002AF552,
0x0F120708,
0x0F12080C,

              //For subsampling Size
0x00287000,
0x002A18BC,
0x0F120004,
0x0F1205B6,
0x0F120000,
0x0F120000,
0x0F120001,
0x0F1205BA,
0x0F120000,
0x0F120000,
0x0F120007,
0x0F1205BA,
0x0F120000,
0x0F120000,
0x0F1201F4,
0x0F12024E,
0x0F120000,
0x0F120000,
0x0F1201F4,
0x0F1205B6,
0x0F120000,
0x0F120000,
0x0F1201F4,
0x0F1205BA,
0x0F120000,
0x0F120000,
0x0F1201F4,
0x0F12024F,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120075,
0x0F1200CF,
0x0F120000,
0x0F120000,
0x0F120075,
0x0F1200D6,
0x0F120000,
0x0F120000,
0x0F120004,
0x0F1201F4,
0x0F120000,
0x0F120000,
0x0F1200F0,
0x0F1201F4,
0x0F12029E,
0x0F1205B2,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1201F8,
0x0F120228,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120208,
0x0F120238,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120218,
0x0F120238,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120001,
0x0F120009,
0x0F1200DE,
0x0F1205C0,
0x0F120000,
0x0F120000,
0x0F1200DF,
0x0F1200E4,
0x0F1201F8,
0x0F1201FD,
0x0F1205B6,
0x0F1205BB,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1201F8,
0x0F120000,
0x0F120000,
0x0F120077,
0x0F12007E,
0x0F12024F,
0x0F12025E,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,

              // For Capture 
0x0F120004,
0x0F1209D1,
0x0F120000,
0x0F120000,
0x0F120001,
0x0F1209D5,
0x0F120000,
0x0F120000,
0x0F120008,
0x0F1209D5,
0x0F120000,
0x0F120000,
0x0F1202AA,
0x0F120326,
0x0F120000,
0x0F120000,
0x0F1202AA,
0x0F1209D1,
0x0F120000,
0x0F120000,
0x0F1202AA,
0x0F1209D5,
0x0F120000,
0x0F120000,
0x0F1202AA,
0x0F120327,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120008,
0x0F120084,
0x0F120000,
0x0F120000,
0x0F120008,
0x0F12008D,
0x0F120000,
0x0F120000,
0x0F120008,
0x0F1202AA,
0x0F120000,
0x0F120000,
0x0F1200AA,
0x0F1202AA,
0x0F1203AD,
0x0F1209CD,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1202AE,
0x0F1202DE,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1202BE,
0x0F1202EE,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1202CE,
0x0F1202EE,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120001,
0x0F120009,
0x0F120095,
0x0F1209DB,
0x0F120000,
0x0F120000,
0x0F120096,
0x0F12009B,
0x0F1202AE,
0x0F1202B3,
0x0F1209D1,
0x0F1209D6,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1202AE,
0x0F120000,
0x0F120000,
0x0F120009,
0x0F120010,
0x0F120327,
0x0F120336,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,

0x002A1AF8,
0x0F125A3C,   //senHal_TuneStr_AngTuneData1_2_D000F400 register at subsampling

0x002A1896,
0x0F120002,   //senHal_SamplingType	0002 03EE: PLA setting
0x0F120000,   //senHal_SamplingMode 0 : 2 PLA / 1 : 4PLA
0x0F120003,   //senHal_PLAOption	[0] VPLA enable  [1] HPLA enable

0x002A189E,
0x0F120FB0,   //senHal_ExpMinPixels

0x002A18AC,
0x0F120060,   //senHal_uAddColsBin
0x0F120060,   //senHal_uAddColsNoBin
0x0F1205C0,   //senHal_uMinColsBin
0x0F1205C0,   //senHal_uMinColsNoBin

0x002A1AEA,
0x0F128080,   //senHal_SubF404Tune
0x0F120080,   //senHal_FullF404Tune
0x002A1AE0,
0x0F120000,   //senHal_bSenAAC

0x002A1A72,
0x0F120000,   //senHal_bSRX	SRX off
0x002A18A2,
0x0F120004,   //senHal_NExpLinesCheckFine extend Forbidden area line
0x002A1A6A,
0x0F12009A,   //senHal_usForbiddenRightOfs extend right Forbidden area line
0x002A385E,
0x0F12024C,   //Mon_Sen_uExpPixelsOfs

0x002A0EE6,
0x0F120000,   //setot_bUseDigitalHbin
0x002A1B2A,
0x0F120300,   //senHal_TuneStr2_usAngTuneGainTh  2   70001B2A
0x0F1200D6,   //senHal_TuneStr2_AngTuneF4CA_0_   2   70001B2C
0x0F12008D,   //senHal_TuneStr2_AngTuneF4CA_1_   2   70001B2E
0x0F1200CF,   //senHal_TuneStr2_AngTuneF4C2_0_   2   70001B30
0x0F120084,   //senHal_TuneStr2_AngTuneF4C2_1_   2   70001B32

              // OTP setting 
0x002A0722,
0x0F120100,   //skl_OTP_usWaitTime This register should be positioned in fornt of D0001000
0x002A0726,
0x0F120001,   //skl_bUseOTPfunc This is OTP on/off function
0x002A08D6,
0x0F120001,   //ash_bUseOTPData
0x002A146E,
0x0F120000,   //awbb_otp_disable
0x002A08DC,
0x0F120001,   //ash_bUseGasAlphaOTP

              // TnP setting 
              // Start of Patch data
0x00287000,
0x002A3AF8,
0x0F12B570,   // 70003AF8 
0x0F124B33,   // 70003AFA 
0x0F12216F,   // 70003AFC 
0x0F124833,   // 70003AFE 
0x0F128C80,   // 70003B00 
0x0F122200,   // 70003B02 
0x0F12C008,   // 70003B04 
0x0F126001,   // 70003B06 
0x0F124931,   // 70003B08 
0x0F124832,   // 70003B0A 
0x0F122401,   // 70003B0C 
0x0F12F000,   // 70003B0E 
0x0F12FB1F,   // 70003B10 
0x0F124931,   // 70003B12 
0x0F124831,   // 70003B14 
0x0F122502,   // 70003B16 
0x0F120022,   // 70003B18 
0x0F12F000,   // 70003B1A 
0x0F12FB19,   // 70003B1C 
0x0F124830,   // 70003B1E 
0x0F120261,   // 70003B20 
0x0F128001,   // 70003B22 
0x0F122100,   // 70003B24 
0x0F128041,   // 70003B26 
0x0F12492E,   // 70003B28 
0x0F12482F,   // 70003B2A 
0x0F126041,   // 70003B2C 
0x0F12492F,   // 70003B2E 
0x0F12482F,   // 70003B30 
0x0F12002A,   // 70003B32 
0x0F122403,   // 70003B34 
0x0F12F000,   // 70003B36 
0x0F12FB0B,   // 70003B38 
0x0F12482B,   // 70003B3A 
0x0F12492D,   // 70003B3C 
0x0F1230C0,   // 70003B3E 
0x0F1263C1,   // 70003B40 
0x0F124929,   // 70003B42 
0x0F12482C,   // 70003B44 
0x0F123980,   // 70003B46 
0x0F126408,   // 70003B48 
0x0F12482C,   // 70003B4A 
0x0F12492C,   // 70003B4C 
0x0F126388,   // 70003B4E 
0x0F12492C,   // 70003B50 
0x0F12482D,   // 70003B52 
0x0F122504,   // 70003B54 
0x0F120022,   // 70003B56 
0x0F12F000,   // 70003B58 
0x0F12FAFA,   // 70003B5A 
0x0F12492B,   // 70003B5C 
0x0F12482C,   // 70003B5E 
0x0F122405,   // 70003B60 
0x0F12002A,   // 70003B62 
0x0F12F000,   // 70003B64 
0x0F12F86C,   // 70003B66 
0x0F124829,   // 70003B68 
0x0F12492A,   // 70003B6A 
0x0F120022,   // 70003B6C 
0x0F122506,   // 70003B6E 
0x0F121D80,   // 70003B70 
0x0F12F000,   // 70003B72 
0x0F12F865,   // 70003B74 
0x0F124826,   // 70003B76 
0x0F124927,   // 70003B78 
0x0F122407,   // 70003B7A 
0x0F12002A,   // 70003B7C 
0x0F12300C,   // 70003B7E 
0x0F12F000,   // 70003B80 
0x0F12F85E,   // 70003B82 
0x0F124822,   // 70003B84 
0x0F124925,   // 70003B86 
0x0F120022,   // 70003B88 
0x0F122508,   // 70003B8A 
0x0F123010,   // 70003B8C 
0x0F12F000,   // 70003B8E 
0x0F12F857,   // 70003B90 
0x0F124923,   // 70003B92 
0x0F124823,   // 70003B94 
0x0F122409,   // 70003B96 
0x0F12002A,   // 70003B98 
0x0F12F000,   // 70003B9A 
0x0F12FAD9,   // 70003B9C 
0x0F124922,   // 70003B9E 
0x0F124822,   // 70003BA0 
0x0F120022,   // 70003BA2 
0x0F12250A,   // 70003BA4 
0x0F12F000,   // 70003BA6 
0x0F12FAD3,   // 70003BA8 
0x0F124921,   // 70003BAA 
0x0F124821,   // 70003BAC 
0x0F12240B,   // 70003BAE 
0x0F12002A,   // 70003BB0 
0x0F12F000,   // 70003BB2 
0x0F12FACD,   // 70003BB4 
0x0F124920,   // 70003BB6 
0x0F124820,   // 70003BB8 
0x0F120022,   // 70003BBA 
0x0F12F000,   // 70003BBC 
0x0F12FAC8,   // 70003BBE 
0x0F12BC70,   // 70003BC0 
0x0F12BC08,   // 70003BC2 
0x0F124718,   // 70003BC4 
0x0F120000,   // 70003BC6 
0x0F12017B,   // 70003BC8 
0x0F124EC2,   // 70003BCA 
0x0F121F6C,   // 70003BCC 
0x0F127000,   // 70003BCE 
0x0F123C59,   // 70003BD0 
0x0F127000,   // 70003BD2 
0x0F12E38B,   // 70003BD4 
0x0F120000,   // 70003BD6 
0x0F123C91,   // 70003BD8 
0x0F127000,   // 70003BDA 
0x0F12C3B1,   // 70003BDC 
0x0F120000,   // 70003BDE 
0x0F124780,   // 70003BE0 
0x0F127000,   // 70003BE2 
0x0F123CEF,   // 70003BE4 
0x0F127000,   // 70003BE6 
0x0F120080,   // 70003BE8 
0x0F127000,   // 70003BEA 
0x0F123D2B,   // 70003BEC 
0x0F127000,   // 70003BEE 
0x0F12B49D,   // 70003BF0 
0x0F120000,   // 70003BF2 
0x0F123DD7,   // 70003BF4 
0x0F127000,   // 70003BF6 
0x0F123D8B,   // 70003BF8 
0x0F127000,   // 70003BFA 
0x0F12FFFF,   // 70003BFC 
0x0F1200FF,   // 70003BFE 
0x0F1217E0,   // 70003C00 
0x0F127000,   // 70003C02 
0x0F123F53,   // 70003C04 
0x0F127000,   // 70003C06 
0x0F12053D,   // 70003C08 
0x0F120000,   // 70003C0A 
0x0F120000,   // 70003C0C 
0x0F120A89,   // 70003C0E 
0x0F126CD2,   // 70003C10 
0x0F120000,   // 70003C12 
0x0F1202C9,   // 70003C14 
0x0F120000,   // 70003C16 
0x0F120000,   // 70003C18 
0x0F120A9A,   // 70003C1A 
0x0F120000,   // 70003C1C 
0x0F1202D2,   // 70003C1E 
0x0F123FA1,   // 70003C20 
0x0F127000,   // 70003C22 
0x0F129E65,   // 70003C24 
0x0F120000,   // 70003C26 
0x0F124015,   // 70003C28 
0x0F127000,   // 70003C2A 
0x0F127C49,   // 70003C2C 
0x0F120000,   // 70003C2E 
0x0F124089,   // 70003C30 
0x0F127000,   // 70003C32 
0x0F127C63,   // 70003C34 
0x0F120000,   // 70003C36 
0x0F1240A5,   // 70003C38 
0x0F127000,   // 70003C3A 
0x0F128F01,   // 70003C3C 
0x0F120000,   // 70003C3E 
0x0F12B570,   // 70003C40 
0x0F12000C,   // 70003C42 
0x0F120015,   // 70003C44 
0x0F120029,   // 70003C46 
0x0F12F000,   // 70003C48 
0x0F12FA8A,   // 70003C4A 
0x0F1249F8,   // 70003C4C 
0x0F1200A8,   // 70003C4E 
0x0F12500C,   // 70003C50 
0x0F12BC70,   // 70003C52 
0x0F12BC08,   // 70003C54 
0x0F124718,   // 70003C56 
0x0F126808,   // 70003C58 
0x0F120400,   // 70003C5A 
0x0F120C00,   // 70003C5C 
0x0F126849,   // 70003C5E 
0x0F120409,   // 70003C60 
0x0F120C09,   // 70003C62 
0x0F124AF3,   // 70003C64 
0x0F128992,   // 70003C66 
0x0F122A00,   // 70003C68 
0x0F12D00D,   // 70003C6A 
0x0F122300,   // 70003C6C 
0x0F121A89,   // 70003C6E 
0x0F12D400,   // 70003C70 
0x0F12000B,   // 70003C72 
0x0F120419,   // 70003C74 
0x0F120C09,   // 70003C76 
0x0F1223FF,   // 70003C78 
0x0F1233C1,   // 70003C7A 
0x0F121810,   // 70003C7C 
0x0F124298,   // 70003C7E 
0x0F12D800,   // 70003C80 
0x0F120003,   // 70003C82 
0x0F120418,   // 70003C84 
0x0F120C00,   // 70003C86 
0x0F124AEB,   // 70003C88 
0x0F128150,   // 70003C8A 
0x0F128191,   // 70003C8C 
0x0F124770,   // 70003C8E 
0x0F12B5F3,   // 70003C90 
0x0F120004,   // 70003C92 
0x0F12B081,   // 70003C94 
0x0F129802,   // 70003C96 
0x0F126800,   // 70003C98 
0x0F120600,   // 70003C9A 
0x0F120E00,   // 70003C9C 
0x0F122201,   // 70003C9E 
0x0F120015,   // 70003CA0 
0x0F120021,   // 70003CA2 
0x0F123910,   // 70003CA4 
0x0F12408A,   // 70003CA6 
0x0F1240A5,   // 70003CA8 
0x0F124FE4,   // 70003CAA 
0x0F120016,   // 70003CAC 
0x0F122C10,   // 70003CAE 
0x0F12DA03,   // 70003CB0 
0x0F128839,   // 70003CB2 
0x0F1243A9,   // 70003CB4 
0x0F128039,   // 70003CB6 
0x0F12E002,   // 70003CB8 
0x0F128879,   // 70003CBA 
0x0F1243B1,   // 70003CBC 
0x0F128079,   // 70003CBE 
0x0F12F000,   // 70003CC0 
0x0F12FA56,   // 70003CC2 
0x0F122C10,   // 70003CC4 
0x0F12DA03,   // 70003CC6 
0x0F128839,   // 70003CC8 
0x0F124329,   // 70003CCA 
0x0F128039,   // 70003CCC 
0x0F12E002,   // 70003CCE 
0x0F128879,   // 70003CD0 
0x0F124331,   // 70003CD2 
0x0F128079,   // 70003CD4 
0x0F1249DA,   // 70003CD6 
0x0F128809,   // 70003CD8 
0x0F122900,   // 70003CDA 
0x0F12D102,   // 70003CDC 
0x0F12F000,   // 70003CDE 
0x0F12FA4F,   // 70003CE0 
0x0F122000,   // 70003CE2 
0x0F129902,   // 70003CE4 
0x0F126008,   // 70003CE6 
0x0F12BCFE,   // 70003CE8 
0x0F12BC08,   // 70003CEA 
0x0F124718,   // 70003CEC 
0x0F12B538,   // 70003CEE 
0x0F129C04,   // 70003CF0 
0x0F120015,   // 70003CF2 
0x0F12002A,   // 70003CF4 
0x0F129400,   // 70003CF6 
0x0F12F000,   // 70003CF8 
0x0F12FA4A,   // 70003CFA 
0x0F124AD1,   // 70003CFC 
0x0F128811,   // 70003CFE 
0x0F122900,   // 70003D00 
0x0F12D00F,   // 70003D02 
0x0F128820,   // 70003D04 
0x0F124281,   // 70003D06 
0x0F12D20C,   // 70003D08 
0x0F128861,   // 70003D0A 
0x0F128853,   // 70003D0C 
0x0F124299,   // 70003D0E 
0x0F12D200,   // 70003D10 
0x0F121E40,   // 70003D12 
0x0F120400,   // 70003D14 
0x0F120C00,   // 70003D16 
0x0F128020,   // 70003D18 
0x0F128851,   // 70003D1A 
0x0F128061,   // 70003D1C 
0x0F124368,   // 70003D1E 
0x0F121840,   // 70003D20 
0x0F126060,   // 70003D22 
0x0F12BC38,   // 70003D24 
0x0F12BC08,   // 70003D26 
0x0F124718,   // 70003D28 
0x0F12B5F8,   // 70003D2A 
0x0F120004,   // 70003D2C 
0x0F126808,   // 70003D2E 
0x0F120400,   // 70003D30 
0x0F120C00,   // 70003D32 
0x0F122201,   // 70003D34 
0x0F120015,   // 70003D36 
0x0F120021,   // 70003D38 
0x0F123910,   // 70003D3A 
0x0F12408A,   // 70003D3C 
0x0F1240A5,   // 70003D3E 
0x0F124FBE,   // 70003D40 
0x0F120016,   // 70003D42 
0x0F122C10,   // 70003D44 
0x0F12DA03,   // 70003D46 
0x0F128839,   // 70003D48 
0x0F1243A9,   // 70003D4A 
0x0F128039,   // 70003D4C 
0x0F12E002,   // 70003D4E 
0x0F128879,   // 70003D50 
0x0F1243B1,   // 70003D52 
0x0F128079,   // 70003D54 
0x0F12F000,   // 70003D56 
0x0F12FA23,   // 70003D58 
0x0F122C10,   // 70003D5A 
0x0F12DA03,   // 70003D5C 
0x0F128838,   // 70003D5E 
0x0F124328,   // 70003D60 
0x0F128038,   // 70003D62 
0x0F12E002,   // 70003D64 
0x0F128878,   // 70003D66 
0x0F124330,   // 70003D68 
0x0F128078,   // 70003D6A 
0x0F1248B6,   // 70003D6C 
0x0F128800,   // 70003D6E 
0x0F120400,   // 70003D70 
0x0F12D507,   // 70003D72 
0x0F124BB5,   // 70003D74 
0x0F127819,   // 70003D76 
0x0F124AB5,   // 70003D78 
0x0F127810,   // 70003D7A 
0x0F127018,   // 70003D7C 
0x0F127011,   // 70003D7E 
0x0F1249B4,   // 70003D80 
0x0F128188,   // 70003D82 
0x0F12BCF8,   // 70003D84 
0x0F12BC08,   // 70003D86 
0x0F124718,   // 70003D88 
0x0F12B538,   // 70003D8A 
0x0F1248B2,   // 70003D8C 
0x0F124669,   // 70003D8E 
0x0F12F000,   // 70003D90 
0x0F12FA0E,   // 70003D92 
0x0F1248B1,   // 70003D94 
0x0F1249B0,   // 70003D96 
0x0F1269C2,   // 70003D98 
0x0F122400,   // 70003D9A 
0x0F1231A8,   // 70003D9C 
0x0F122A00,   // 70003D9E 
0x0F12D008,   // 70003DA0 
0x0F1261C4,   // 70003DA2 
0x0F12684A,   // 70003DA4 
0x0F126242,   // 70003DA6 
0x0F126282,   // 70003DA8 
0x0F12466B,   // 70003DAA 
0x0F12881A,   // 70003DAC 
0x0F126302,   // 70003DAE 
0x0F12885A,   // 70003DB0 
0x0F126342,   // 70003DB2 
0x0F126A02,   // 70003DB4 
0x0F122A00,   // 70003DB6 
0x0F12D00A,   // 70003DB8 
0x0F126204,   // 70003DBA 
0x0F126849,   // 70003DBC 
0x0F126281,   // 70003DBE 
0x0F12466B,   // 70003DC0 
0x0F128819,   // 70003DC2 
0x0F126301,   // 70003DC4 
0x0F128859,   // 70003DC6 
0x0F126341,   // 70003DC8 
0x0F1249A5,   // 70003DCA 
0x0F1288C9,   // 70003DCC 
0x0F1263C1,   // 70003DCE 
0x0F12F000,   // 70003DD0 
0x0F12F9F6,   // 70003DD2 
0x0F12E7A6,   // 70003DD4 
0x0F12B5F0,   // 70003DD6 
0x0F12B08B,   // 70003DD8 
0x0F1220FF,   // 70003DDA 
0x0F121C40,   // 70003DDC 
0x0F1249A1,   // 70003DDE 
0x0F1289CC,   // 70003DE0 
0x0F124E9E,   // 70003DE2 
0x0F126AB1,   // 70003DE4 
0x0F124284,   // 70003DE6 
0x0F12D101,   // 70003DE8 
0x0F12489F,   // 70003DEA 
0x0F126081,   // 70003DEC 
0x0F126A70,   // 70003DEE 
0x0F120200,   // 70003DF0 
0x0F12F000,   // 70003DF2 
0x0F12F9ED,   // 70003DF4 
0x0F120400,   // 70003DF6 
0x0F120C00,   // 70003DF8 
0x0F124A96,   // 70003DFA 
0x0F128A11,   // 70003DFC 
0x0F129109,   // 70003DFE 
0x0F122101,   // 70003E00 
0x0F120349,   // 70003E02 
0x0F124288,   // 70003E04 
0x0F12D200,   // 70003E06 
0x0F120001,   // 70003E08 
0x0F124A92,   // 70003E0A 
0x0F128211,   // 70003E0C 
0x0F124D97,   // 70003E0E 
0x0F128829,   // 70003E10 
0x0F129108,   // 70003E12 
0x0F124A8B,   // 70003E14 
0x0F122303,   // 70003E16 
0x0F123222,   // 70003E18 
0x0F121F91,   // 70003E1A 
0x0F12F000,   // 70003E1C 
0x0F12F9DE,   // 70003E1E 
0x0F128028,   // 70003E20 
0x0F12488E,   // 70003E22 
0x0F124987,   // 70003E24 
0x0F126BC2,   // 70003E26 
0x0F126AC0,   // 70003E28 
0x0F124282,   // 70003E2A 
0x0F12D201,   // 70003E2C 
0x0F128CC8,   // 70003E2E 
0x0F128028,   // 70003E30 
0x0F1288E8,   // 70003E32 
0x0F129007,   // 70003E34 
0x0F122240,   // 70003E36 
0x0F124310,   // 70003E38 
0x0F1280E8,   // 70003E3A 
0x0F122000,   // 70003E3C 
0x0F120041,   // 70003E3E 
0x0F12194B,   // 70003E40 
0x0F12001E,   // 70003E42 
0x0F123680,   // 70003E44 
0x0F128BB2,   // 70003E46 
0x0F12AF04,   // 70003E48 
0x0F12527A,   // 70003E4A 
0x0F124A7D,   // 70003E4C 
0x0F12188A,   // 70003E4E 
0x0F128897,   // 70003E50 
0x0F1283B7,   // 70003E52 
0x0F1233A0,   // 70003E54 
0x0F12891F,   // 70003E56 
0x0F12AE01,   // 70003E58 
0x0F125277,   // 70003E5A 
0x0F128A11,   // 70003E5C 
0x0F128119,   // 70003E5E 
0x0F121C40,   // 70003E60 
0x0F120400,   // 70003E62 
0x0F120C00,   // 70003E64 
0x0F122806,   // 70003E66 
0x0F12D3E9,   // 70003E68 
0x0F12F000,   // 70003E6A 
0x0F12F9BF,   // 70003E6C 
0x0F12F000,   // 70003E6E 
0x0F12F9C5,   // 70003E70 
0x0F124F79,   // 70003E72 
0x0F1237A8,   // 70003E74 
0x0F122800,   // 70003E76 
0x0F12D10A,   // 70003E78 
0x0F121FE0,   // 70003E7A 
0x0F1238FD,   // 70003E7C 
0x0F12D001,   // 70003E7E 
0x0F121CC0,   // 70003E80 
0x0F12D105,   // 70003E82 
0x0F124874,   // 70003E84 
0x0F128829,   // 70003E86 
0x0F123818,   // 70003E88 
0x0F126840,   // 70003E8A 
0x0F124348,   // 70003E8C 
0x0F126078,   // 70003E8E 
0x0F124972,   // 70003E90 
0x0F126878,   // 70003E92 
0x0F126B89,   // 70003E94 
0x0F124288,   // 70003E96 
0x0F12D300,   // 70003E98 
0x0F120008,   // 70003E9A 
0x0F126078,   // 70003E9C 
0x0F122000,   // 70003E9E 
0x0F120041,   // 70003EA0 
0x0F12AA04,   // 70003EA2 
0x0F125A53,   // 70003EA4 
0x0F12194A,   // 70003EA6 
0x0F12269C,   // 70003EA8 
0x0F1252B3,   // 70003EAA 
0x0F12AB01,   // 70003EAC 
0x0F125A59,   // 70003EAE 
0x0F1232A0,   // 70003EB0 
0x0F128111,   // 70003EB2 
0x0F121C40,   // 70003EB4 
0x0F120400,   // 70003EB6 
0x0F120C00,   // 70003EB8 
0x0F122806,   // 70003EBA 
0x0F12D3F0,   // 70003EBC 
0x0F124965,   // 70003EBE 
0x0F129809,   // 70003EC0 
0x0F128208,   // 70003EC2 
0x0F129808,   // 70003EC4 
0x0F128028,   // 70003EC6 
0x0F129807,   // 70003EC8 
0x0F1280E8,   // 70003ECA 
0x0F121FE0,   // 70003ECC 
0x0F1238FD,   // 70003ECE 
0x0F12D13B,   // 70003ED0 
0x0F124D64,   // 70003ED2 
0x0F1289E8,   // 70003ED4 
0x0F121FC1,   // 70003ED6 
0x0F1239FF,   // 70003ED8 
0x0F12D136,   // 70003EDA 
0x0F124C5F,   // 70003EDC 
0x0F128AE0,   // 70003EDE 
0x0F12F000,   // 70003EE0 
0x0F12F994,   // 70003EE2 
0x0F120006,   // 70003EE4 
0x0F128B20,   // 70003EE6 
0x0F12F000,   // 70003EE8 
0x0F12F998,   // 70003EEA 
0x0F129000,   // 70003EEC 
0x0F126AA1,   // 70003EEE 
0x0F126878,   // 70003EF0 
0x0F121809,   // 70003EF2 
0x0F120200,   // 70003EF4 
0x0F12F000,   // 70003EF6 
0x0F12F96B,   // 70003EF8 
0x0F120400,   // 70003EFA 
0x0F120C00,   // 70003EFC 
0x0F120022,   // 70003EFE 
0x0F123246,   // 70003F00 
0x0F120011,   // 70003F02 
0x0F12310A,   // 70003F04 
0x0F122305,   // 70003F06 
0x0F12F000,   // 70003F08 
0x0F12F968,   // 70003F0A 
0x0F1266E8,   // 70003F0C 
0x0F126B23,   // 70003F0E 
0x0F120002,   // 70003F10 
0x0F120031,   // 70003F12 
0x0F120018,   // 70003F14 
0x0F12F000,   // 70003F16 
0x0F12F989,   // 70003F18 
0x0F12466B,   // 70003F1A 
0x0F128518,   // 70003F1C 
0x0F126EEA,   // 70003F1E 
0x0F126B60,   // 70003F20 
0x0F129900,   // 70003F22 
0x0F12F000,   // 70003F24 
0x0F12F982,   // 70003F26 
0x0F12466B,   // 70003F28 
0x0F128558,   // 70003F2A 
0x0F120029,   // 70003F2C 
0x0F12980A,   // 70003F2E 
0x0F123170,   // 70003F30 
0x0F12F000,   // 70003F32 
0x0F12F983,   // 70003F34 
0x0F120028,   // 70003F36 
0x0F123060,   // 70003F38 
0x0F128A02,   // 70003F3A 
0x0F124946,   // 70003F3C 
0x0F123128,   // 70003F3E 
0x0F12808A,   // 70003F40 
0x0F128A42,   // 70003F42 
0x0F1280CA,   // 70003F44 
0x0F128A80,   // 70003F46 
0x0F128108,   // 70003F48 
0x0F12B00B,   // 70003F4A 
0x0F12BCF0,   // 70003F4C 
0x0F12BC08,   // 70003F4E 
0x0F124718,   // 70003F50 
0x0F12B570,   // 70003F52 
0x0F122400,   // 70003F54 
0x0F124D46,   // 70003F56 
0x0F124846,   // 70003F58 
0x0F128881,   // 70003F5A 
0x0F124846,   // 70003F5C 
0x0F128041,   // 70003F5E 
0x0F122101,   // 70003F60 
0x0F128001,   // 70003F62 
0x0F12F000,   // 70003F64 
0x0F12F972,   // 70003F66 
0x0F124842,   // 70003F68 
0x0F123820,   // 70003F6A 
0x0F128BC0,   // 70003F6C 
0x0F12F000,   // 70003F6E 
0x0F12F975,   // 70003F70 
0x0F124B42,   // 70003F72 
0x0F12220D,   // 70003F74 
0x0F120712,   // 70003F76 
0x0F1218A8,   // 70003F78 
0x0F128806,   // 70003F7A 
0x0F1200E1,   // 70003F7C 
0x0F1218C9,   // 70003F7E 
0x0F1281CE,   // 70003F80 
0x0F128846,   // 70003F82 
0x0F12818E,   // 70003F84 
0x0F128886,   // 70003F86 
0x0F12824E,   // 70003F88 
0x0F1288C0,   // 70003F8A 
0x0F128208,   // 70003F8C 
0x0F123508,   // 70003F8E 
0x0F12042D,   // 70003F90 
0x0F120C2D,   // 70003F92 
0x0F121C64,   // 70003F94 
0x0F120424,   // 70003F96 
0x0F120C24,   // 70003F98 
0x0F122C07,   // 70003F9A 
0x0F12D3EC,   // 70003F9C 
0x0F12E658,   // 70003F9E 
0x0F12B510,   // 70003FA0 
0x0F124834,   // 70003FA2 
0x0F124C34,   // 70003FA4 
0x0F1288C0,   // 70003FA6 
0x0F128060,   // 70003FA8 
0x0F122001,   // 70003FAA 
0x0F128020,   // 70003FAC 
0x0F124831,   // 70003FAE 
0x0F123820,   // 70003FB0 
0x0F128BC0,   // 70003FB2 
0x0F12F000,   // 70003FB4 
0x0F12F952,   // 70003FB6 
0x0F1288E0,   // 70003FB8 
0x0F124A31,   // 70003FBA 
0x0F122800,   // 70003FBC 
0x0F12D003,   // 70003FBE 
0x0F124930,   // 70003FC0 
0x0F128849,   // 70003FC2 
0x0F122900,   // 70003FC4 
0x0F12D009,   // 70003FC6 
0x0F122001,   // 70003FC8 
0x0F1203C0,   // 70003FCA 
0x0F128050,   // 70003FCC 
0x0F1280D0,   // 70003FCE 
0x0F122000,   // 70003FD0 
0x0F128090,   // 70003FD2 
0x0F128110,   // 70003FD4 
0x0F12BC10,   // 70003FD6 
0x0F12BC08,   // 70003FD8 
0x0F124718,   // 70003FDA 
0x0F128050,   // 70003FDC 
0x0F128920,   // 70003FDE 
0x0F1280D0,   // 70003FE0 
0x0F128960,   // 70003FE2 
0x0F120400,   // 70003FE4 
0x0F121400,   // 70003FE6 
0x0F128090,   // 70003FE8 
0x0F1289A1,   // 70003FEA 
0x0F120409,   // 70003FEC 
0x0F121409,   // 70003FEE 
0x0F128111,   // 70003FF0 
0x0F1289E3,   // 70003FF2 
0x0F128A24,   // 70003FF4 
0x0F122B00,   // 70003FF6 
0x0F12D104,   // 70003FF8 
0x0F1217C3,   // 70003FFA 
0x0F120F5B,   // 70003FFC 
0x0F121818,   // 70003FFE 
0x0F1210C0,   // 70004000 
0x0F128090,   // 70004002 
0x0F122C00,   // 70004004 
0x0F12D1E6,   // 70004006 
0x0F1217C8,   // 70004008 
0x0F120F40,   // 7000400A 
0x0F121840,   // 7000400C 
0x0F1210C0,   // 7000400E 
0x0F128110,   // 70004010 
0x0F12E7E0,   // 70004012 
0x0F12B510,   // 70004014 
0x0F12000C,   // 70004016 
0x0F124919,   // 70004018 
0x0F122204,   // 7000401A 
0x0F126820,   // 7000401C 
0x0F125E8A,   // 7000401E 
0x0F120140,   // 70004020 
0x0F121A80,   // 70004022 
0x0F120280,   // 70004024 
0x0F128849,   // 70004026 
0x0F12F000,   // 70004028 
0x0F12F920,   // 7000402A 
0x0F126020,   // 7000402C 
0x0F12E7D2,   // 7000402E 
0x0F1238D4,   // 70004030 
0x0F127000,   // 70004032 
0x0F1217D0,   // 70004034 
0x0F127000,   // 70004036 
0x0F125000,   // 70004038 
0x0F12D000,   // 7000403A 
0x0F121100,   // 7000403C 
0x0F12D000,   // 7000403E 
0x0F12171A,   // 70004040 
0x0F127000,   // 70004042 
0x0F124780,   // 70004044 
0x0F127000,   // 70004046 
0x0F122FCA,   // 70004048 
0x0F127000,   // 7000404A 
0x0F122FC5,   // 7000404C 
0x0F127000,   // 7000404E 
0x0F122FC6,   // 70004050 
0x0F127000,   // 70004052 
0x0F122ED8,   // 70004054 
0x0F127000,   // 70004056 
0x0F122BD0,   // 70004058 
0x0F127000,   // 7000405A 
0x0F1217E0,   // 7000405C 
0x0F127000,   // 7000405E 
0x0F122DE8,   // 70004060 
0x0F127000,   // 70004062 
0x0F1237E0,   // 70004064 
0x0F127000,   // 70004066 
0x0F12210C,   // 70004068 
0x0F127000,   // 7000406A 
0x0F121484,   // 7000406C 
0x0F127000,   // 7000406E 
0x0F12A006,   // 70004070 
0x0F120000,   // 70004072 
0x0F120724,   // 70004074 
0x0F127000,   // 70004076 
0x0F12A000,   // 70004078 
0x0F12D000,   // 7000407A 
0x0F122270,   // 7000407C 
0x0F127000,   // 7000407E 
0x0F122558,   // 70004080 
0x0F127000,   // 70004082 
0x0F12146C,   // 70004084 
0x0F127000,   // 70004086 
0x0F12B510,   // 70004088 
0x0F12000C,   // 7000408A 
0x0F12492E,   // 7000408C 
0x0F122208,   // 7000408E 
0x0F126820,   // 70004090 
0x0F125E8A,   // 70004092 
0x0F120140,   // 70004094 
0x0F121A80,   // 70004096 
0x0F120280,   // 70004098 
0x0F1288C9,   // 7000409A 
0x0F12F000,   // 7000409C 
0x0F12F8E6,   // 7000409E 
0x0F126020,   // 700040A0 
0x0F12E798,   // 700040A2 
0x0F12B5FE,   // 700040A4 
0x0F12000C,   // 700040A6 
0x0F126825,   // 700040A8 
0x0F126866,   // 700040AA 
0x0F1268A0,   // 700040AC 
0x0F129001,   // 700040AE 
0x0F1268E7,   // 700040B0 
0x0F121BA8,   // 700040B2 
0x0F1242B5,   // 700040B4 
0x0F12DA00,   // 700040B6 
0x0F121B70,   // 700040B8 
0x0F129000,   // 700040BA 
0x0F124922,   // 700040BC 
0x0F124823,   // 700040BE 
0x0F12884A,   // 700040C0 
0x0F128843,   // 700040C2 
0x0F12435A,   // 700040C4 
0x0F122304,   // 700040C6 
0x0F125ECB,   // 700040C8 
0x0F120A92,   // 700040CA 
0x0F1218D2,   // 700040CC 
0x0F1202D2,   // 700040CE 
0x0F120C12,   // 700040D0 
0x0F1288CB,   // 700040D2 
0x0F128880,   // 700040D4 
0x0F124343,   // 700040D6 
0x0F120A98,   // 700040D8 
0x0F122308,   // 700040DA 
0x0F125ECB,   // 700040DC 
0x0F1218C0,   // 700040DE 
0x0F1202C0,   // 700040E0 
0x0F120C00,   // 700040E2 
0x0F120411,   // 700040E4 
0x0F120400,   // 700040E6 
0x0F121409,   // 700040E8 
0x0F121400,   // 700040EA 
0x0F121A08,   // 700040EC 
0x0F124917,   // 700040EE 
0x0F1239E0,   // 700040F0 
0x0F126148,   // 700040F2 
0x0F129801,   // 700040F4 
0x0F123040,   // 700040F6 
0x0F127880,   // 700040F8 
0x0F122800,   // 700040FA 
0x0F12D103,   // 700040FC 
0x0F129801,   // 700040FE 
0x0F120029,   // 70004100 
0x0F12F000,   // 70004102 
0x0F12F8B9,   // 70004104 
0x0F128839,   // 70004106 
0x0F129800,   // 70004108 
0x0F124281,   // 7000410A 
0x0F12D814,   // 7000410C 
0x0F128879,   // 7000410E 
0x0F129800,   // 70004110 
0x0F124281,   // 70004112 
0x0F12D20C,   // 70004114 
0x0F129801,   // 70004116 
0x0F120029,   // 70004118 
0x0F12F000,   // 7000411A 
0x0F12F8B5,   // 7000411C 
0x0F129801,   // 7000411E 
0x0F120029,   // 70004120 
0x0F12F000,   // 70004122 
0x0F12F8B1,   // 70004124 
0x0F129801,   // 70004126 
0x0F120029,   // 70004128 
0x0F12F000,   // 7000412A 
0x0F12F8AD,   // 7000412C 
0x0F12E003,   // 7000412E 
0x0F129801,   // 70004130 
0x0F120029,   // 70004132 
0x0F12F000,   // 70004134 
0x0F12F8A8,   // 70004136 
0x0F129801,   // 70004138 
0x0F120032,   // 7000413A 
0x0F120039,   // 7000413C 
0x0F12F000,   // 7000413E 
0x0F12F8AB,   // 70004140 
0x0F126020,   // 70004142 
0x0F12E5D0,   // 70004144 
0x0F120000,   // 70004146 
0x0F122558,   // 70004148 
0x0F127000,   // 7000414A 
0x0F122AB8,   // 7000414C 
0x0F127000,   // 7000414E 
0x0F124778,   // 70004150 
0x0F1246C0,   // 70004152 
0x0F12C000,   // 70004154 
0x0F12E59F,   // 70004156 
0x0F12FF1C,   // 70004158 
0x0F12E12F,   // 7000415A 
0x0F121789,   // 7000415C 
0x0F120001,   // 7000415E 
0x0F124778,   // 70004160 
0x0F1246C0,   // 70004162 
0x0F12C000,   // 70004164 
0x0F12E59F,   // 70004166 
0x0F12FF1C,   // 70004168 
0x0F12E12F,   // 7000416A 
0x0F1216F1,   // 7000416C 
0x0F120001,   // 7000416E 
0x0F124778,   // 70004170 
0x0F1246C0,   // 70004172 
0x0F12C000,   // 70004174 
0x0F12E59F,   // 70004176 
0x0F12FF1C,   // 70004178 
0x0F12E12F,   // 7000417A 
0x0F12C3B1,   // 7000417C 
0x0F120000,   // 7000417E 
0x0F124778,   // 70004180 
0x0F1246C0,   // 70004182 
0x0F12C000,   // 70004184 
0x0F12E59F,   // 70004186 
0x0F12FF1C,   // 70004188 
0x0F12E12F,   // 7000418A 
0x0F12C36D,   // 7000418C 
0x0F120000,   // 7000418E 
0x0F124778,   // 70004190 
0x0F1246C0,   // 70004192 
0x0F12C000,   // 70004194 
0x0F12E59F,   // 70004196 
0x0F12FF1C,   // 70004198 
0x0F12E12F,   // 7000419A 
0x0F12F6D7,   // 7000419C 
0x0F120000,   // 7000419E 
0x0F124778,   // 700041A0 
0x0F1246C0,   // 700041A2 
0x0F12C000,   // 700041A4 
0x0F12E59F,   // 700041A6 
0x0F12FF1C,   // 700041A8 
0x0F12E12F,   // 700041AA 
0x0F12B49D,   // 700041AC 
0x0F120000,   // 700041AE 
0x0F124778,   // 700041B0 
0x0F1246C0,   // 700041B2 
0x0F12C000,   // 700041B4 
0x0F12E59F,   // 700041B6 
0x0F12FF1C,   // 700041B8 
0x0F12E12F,   // 700041BA 
0x0F127EDF,   // 700041BC 
0x0F120000,   // 700041BE 
0x0F124778,   // 700041C0 
0x0F1246C0,   // 700041C2 
0x0F12C000,   // 700041C4 
0x0F12E59F,   // 700041C6 
0x0F12FF1C,   // 700041C8 
0x0F12E12F,   // 700041CA 
0x0F12448D,   // 700041CC 
0x0F120000,   // 700041CE 
0x0F124778,   // 700041D0 
0x0F1246C0,   // 700041D2 
0x0F12F004,   // 700041D4 
0x0F12E51F,   // 700041D6 
0x0F1229EC,   // 700041D8 
0x0F120001,   // 700041DA 
0x0F124778,   // 700041DC 
0x0F1246C0,   // 700041DE 
0x0F12C000,   // 700041E0 
0x0F12E59F,   // 700041E2 
0x0F12FF1C,   // 700041E4 
0x0F12E12F,   // 700041E6 
0x0F122EF1,   // 700041E8 
0x0F120000,   // 700041EA 
0x0F124778,   // 700041EC 
0x0F1246C0,   // 700041EE 
0x0F12C000,   // 700041F0 
0x0F12E59F,   // 700041F2 
0x0F12FF1C,   // 700041F4 
0x0F12E12F,   // 700041F6 
0x0F12EE03,   // 700041F8 
0x0F120000,   // 700041FA 
0x0F124778,   // 700041FC 
0x0F1246C0,   // 700041FE 
0x0F12C000,   // 70004200 
0x0F12E59F,   // 70004202 
0x0F12FF1C,   // 70004204 
0x0F12E12F,   // 70004206 
0x0F12A58B,   // 70004208 
0x0F120000,   // 7000420A 
0x0F124778,   // 7000420C 
0x0F1246C0,   // 7000420E 
0x0F12C000,   // 70004210 
0x0F12E59F,   // 70004212 
0x0F12FF1C,   // 70004214 
0x0F12E12F,   // 70004216 
0x0F127C49,   // 70004218 
0x0F120000,   // 7000421A 
0x0F124778,   // 7000421C 
0x0F1246C0,   // 7000421E 
0x0F12C000,   // 70004220 
0x0F12E59F,   // 70004222 
0x0F12FF1C,   // 70004224 
0x0F12E12F,   // 70004226 
0x0F127C63,   // 70004228 
0x0F120000,   // 7000422A 
0x0F124778,   // 7000422C 
0x0F1246C0,   // 7000422E 
0x0F12C000,   // 70004230 
0x0F12E59F,   // 70004232 
0x0F12FF1C,   // 70004234 
0x0F12E12F,   // 70004236 
0x0F122DB7,   // 70004238 
0x0F120000,   // 7000423A 
0x0F124778,   // 7000423C 
0x0F1246C0,   // 7000423E 
0x0F12C000,   // 70004240 
0x0F12E59F,   // 70004242 
0x0F12FF1C,   // 70004244 
0x0F12E12F,   // 70004246 
0x0F12EB3D,   // 70004248 
0x0F120000,   // 7000424A 
0x0F124778,   // 7000424C 
0x0F1246C0,   // 7000424E 
0x0F12C000,   // 70004250 
0x0F12E59F,   // 70004252 
0x0F12FF1C,   // 70004254 
0x0F12E12F,   // 70004256 
0x0F12F061,   // 70004258 
0x0F120000,   // 7000425A 
0x0F124778,   // 7000425C 
0x0F1246C0,   // 7000425E 
0x0F12C000,   // 70004260 
0x0F12E59F,   // 70004262 
0x0F12FF1C,   // 70004264 
0x0F12E12F,   // 70004266 
0x0F12F0EF,   // 70004268 
0x0F120000,   // 7000426A 
0x0F124778,   // 7000426C 
0x0F1246C0,   // 7000426E 
0x0F12F004,   // 70004270 
0x0F12E51F,   // 70004272 
0x0F122824,   // 70004274 
0x0F120001,   // 70004276 
0x0F124778,   // 70004278 
0x0F1246C0,   // 7000427A 
0x0F12C000,   // 7000427C 
0x0F12E59F,   // 7000427E 
0x0F12FF1C,   // 70004280 
0x0F12E12F,   // 70004282 
0x0F128EDD,   // 70004284 
0x0F120000,   // 70004286 
0x0F124778,   // 70004288 
0x0F1246C0,   // 7000428A 
0x0F12C000,   // 7000428C 
0x0F12E59F,   // 7000428E 
0x0F12FF1C,   // 70004290 
0x0F12E12F,   // 70004292 
0x0F128DCB,   // 70004294 
0x0F120000,   // 70004296 
0x0F124778,   // 70004298 
0x0F1246C0,   // 7000429A 
0x0F12C000,   // 7000429C 
0x0F12E59F,   // 7000429E 
0x0F12FF1C,   // 700042A0 
0x0F12E12F,   // 700042A2 
0x0F128E17,   // 700042A4 
0x0F120000,   // 700042A6 
              // End of Patch Data(Last : 700042A6h)
              // Total Size 1968 
              // Addr : 3AF8  Size : 1966(7AEh)
              // #define	TNP_USER_MBCV_CONTROL		 If the user want to control MBCV manually	
              // #define TNP_4EC_MBR_TUNE			 MBR ON / OFF	
              // #define TNP_4EC_FORBIDDEN_TUNE		 FORBIDDEN TUNING : fix cintc.
              // #define TNP_AF_FINESEARCH_DRIVEBACK		 Fine search option to search on Driveback mode.
              // #define TNP_FLASH_ALG		 for support Flash alg support.	

              //TNP_Regs_usCintrTh         2   70004780	
              //TNP_Regs_usFixedCintc      2   70004782	
              //TNP_Regs_FlsWeightRIn_0_   2   70004784	
              //TNP_Regs_FlsWeightRIn_1_   2   70004786	
              //TNP_Regs_FlsWeightRIn_2_   2   70004788	
              //TNP_Regs_FlsWeightRIn_3_   2   7000478A	
              //TNP_Regs_FlsWeightRIn_4_   2   7000478C	
              //TNP_Regs_FlsWeightRIn_5_   2   7000478E	
              //TNP_Regs_FlsWeightROut_0_  2   70004790	
              //TNP_Regs_FlsWeightROut_1_  2   70004792	
              //TNP_Regs_FlsWeightROut_2_  2   70004794	
              //TNP_Regs_FlsWeightROut_3_  2   70004796	
              //TNP_Regs_FlsWeightROut_4_  2   70004798	
              //TNP_Regs_FlsWeightROut_5_  2   7000479A	

0x0028D000,
0x002A1000,
0x0F120001,
              // End of FACTORY ONLY. 

              // AF setting 
0x00287000,
0x002A01FC,
0x0F120001,   // REG_TC_IPRM_LedGpio	
             // 70001720 0100 Only STW Use IT
0x002A01FE,
0x0F120003,
0x0F120000,
0x002A0204,
0x0F120061,
0x002A020C,
0x0F122F0C,
0x0F120190,
0x002A0294,
0x0F120100,
0x0F1200E3,
0x0F120200,
0x0F120238,
0x0F1201C6,
0x0F120166,
0x0F120074,
0x0F120132,
0x0F120001,

0x002A070E,
0x0F1200FF,
0x002A071E,
0x0F120001,
0x002A163C,
0x0F120000,

0x002A1648,
0x0F129002,   // 2nd search on when 2nd search lens oppsite direction moving
0x002A1652,
0x0F120002,
0x0F120000,
0x002A15E0,
0x0F120801,   // when 2nd search 1code distance 6+1 position move

0x002A164C,
0x0F120003,
0x002A163E,
0x0F1200E5,
0x0F1200CC,   //98(60%) -> CC(80%)
0x002A15D4,
0x0F120000,
0x0F12D000,
0x002A169A,
0x0F12FF95,
0x002A166A,
0x0F120280,
0x002A1676,
0x0F1203A0,
0x0F120320,
0x002A16BC,
0x0F120030,
0x002A16E0,
0x0F120060,
0x002A16D4,
0x0F120010,
0x002A1656,
0x0F120000,
0x002A15E6,
0x0F12003C,

0x0F120015,   //af_pos_usTableLastInd
0x0F120032,
0x0F120038,
0x0F12003E,
0x0F120044,
0x0F12004A,
0x0F120050,
0x0F120056,
0x0F12005C,
0x0F120062,
0x0F120068,
0x0F12006E,
0x0F120074,
0x0F12007A,
0x0F120080,
0x0F120086,
0x0F12008C,
0x0F120092,
0x0F120098,
0x0F12009E,
0x0F1200A4,
0x0F1200AA,
0x0F1200B0,

0x002A1722,
0x0F128000,
0x0F120006,
0x0F123FF0,
0x0F1203E8,
0x0F120000,
0x0F120080,   //delay2 when threshold upper lens moving when moving distance 9 delay 80h 12.8ms delay
0x0F120009,   //threshold
0x0F120020,   //delay1 when threshold lower lens moving when moving lower then 9(1st search position table distance lower then 9) delay 20h 3.2ms delay 
0x0F120040,
0x0F120080,
0x0F1200C0,
0x0F1200E0,

0x002A028C,
0x0F120003,   //REG_TC_AF_AfCmd

              // GAS TBL setting 
0x002A08B4,
0x0F120001,   //wbt_bUseOutdoorASH

              //TVAR_ash_AwbAshCord Refer Mon_AWB_RotGain
0x002A08BC,
0x0F1200C0,   //TVAR_ash_AwbAshCord_0_ 2300K
0x0F1200DF,   //TVAR_ash_AwbAshCord_1_ 2750K
0x0F120100,   //TVAR_ash_AwbAshCord_2_ 3300K
0x0F120125,   //TVAR_ash_AwbAshCord_3_ 4150K
0x0F12015F,   //TVAR_ash_AwbAshCord_4_ 5250K
0x0F12017C,   //TVAR_ash_AwbAshCord_5_ 6400K
0x0F120194,   //TVAR_ash_AwbAshCord_6_ 7500K

0x002A08F6,
0x0F124000,
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124000,
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124000,
0x0F124000,
0x0F124000,
0x0F124000,

0x0F123800,   //4000
0x0F124000,
0x0F124000,
0x0F124000,

0x0F123B00,   //5000 
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124300,   //6500
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124300,   //7400
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124500,   //4500
0x0F124000,
0x0F124000,
0x0F124000,

0x002A08F4,
0x0F120001,   //ash_bUseGasAlpha

              //AE START 
              //AE WEIGHT 
0x002A1492,
0x0F120100,
0x0F120101,
0x0F120101,
0x0F120001,
0x0F120101,
0x0F120201,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120201,
0x0F120302,
0x0F120203,
0x0F120102,
0x0F120201,
0x0F120302,
0x0F120203,
0x0F120102,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120101,
0x0F120201,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,

0x002A1484,
0x0F12003C,   //TVAR_ae_BrAve
0x002A148A,
0x0F12000F,   //ae_StatMode
0x002A058C,
0x0F123520,
0x0F120000,   //lt_uMaxExp1
0x0F12C350,
0x0F120000,   //lt_uMaxExp2
0x0F123520,
0x0F120000,   //lt_uCapMaxExp1
0x0F12C350,
0x0F120000,   //lt_uCapMaxExp2
0x002A059C,
0x0F120470,   //lt_uMaxAnGain1
0x0F120C00,   //lt_uMaxAnGain2
0x0F120100,   //lt_uMaxDigGain
0x0F121000,   //lt_uMaxTotGain

0x002A0544,
0x0F120111,   //lt_uLimitHigh
0x0F1200EF,   //lt_uLimitLow

0x002A04E6,
0x0F12077F,   //REG_TC_DBG

0x002A04D6,
0x0F120000,
0x0F120001,

0x002A0F2A,
0x0F120000,   //AFC_Default60Hz 0001:60Hz 0000h:50Hz
0x002A0F30,
0x0F120001,   //AFC_D_ConvAccelerPower

0x002A0608,
0x0F120001,   //lt_ExpGain_uSubsamplingmode
0x0F120001,   //lt_ExpGain_uNonSubsampling
0x0F120800,   //lt_ExpGain_ExpCurveGainMaxStr
0x0F120100,   //lt_ExpGain_ExpCurveGainMaxStr_0__uMaxDigGain
0x0F120001, 
0x0F120000,   //lt_ExpGain_ExpCurveGainMaxStr_0__ulExpIn_0_
0x0F120A3C,  
0x0F120000,  
0x0F120D05,  
0x0F120000,  
0x0F124008,  
0x0F120000,  
0x0F127400,  
0x0F120000,  
0x0F12C000,   //9C00->9F->A5 //400Lux
0x0F120000,  
0x0F12AD00,  
0x0F120001,  
0x0F12F1D4,  
0x0F120002,  
0x0F12DC00,  
0x0F120005,  
0x0F12DC00,  
0x0F120005,  
             
0x002A0638,
0x0F120001,
0x0F120000,   //lt_ExpGain_ExpCurveGainMaxStr_0__ulExpOut_0_
0x0F120A3C,
0x0F120000,
0x0F120D05,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F126810,
0x0F120000,
0x0F128214,
0x0F120000,
0x0F12C350,
0x0F120000,
0x0F12C350,
0x0F120000,
0x0F12C350,
0x0F120000,

0x002A0660,
0x0F120650,   //lt_ExpGain_ExpCurveGainMaxStr_1_
0x0F120100,   //lt_ExpGain_ExpCurveGainMaxStr_1__uMaxDigGain

0x002A06B8,
0x0F12452C,
0x0F120005,   //lt_uMaxLei

0x002A05D0,
0x0F120000,   //lt_mbr_Peak_behind 

              //AWB init Start point 
0x002A145E,
0x0F120580,
0x0F120428,
0x0F1207B0,

              //AWB Init 
              //White Locus 
0x002A11F0,
0x0F120120,   //awbb_IntcR
0x0F120121,   //awbb_IntcB

              //IndoorZone
0x002A101C,
0x0F12037C,   
0x0F12038E,   
0x0F12033C,   
0x0F120384,   
0x0F1202FE,   
0x0F12036C,   
0x0F1202BA,   
0x0F120352,   
0x0F12028E,   
0x0F120300,   
0x0F12026A,   
0x0F1202C8,   
0x0F120254,   
0x0F1202A8,   
0x0F120242,   
0x0F1202A0,   
0x0F12021A,   
0x0F1202A0,   
0x0F1201F4,   
0x0F120298,   
0x0F1201D4,   
0x0F120290,   
0x0F1201CC,   
0x0F120276,   
0x0F1201D2,   
0x0F120260,   
0x0F1201F6,   
0x0F12023A,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   

0x0F120005,   //awbb_IndoorGrZones_m_GridStep
0x002A1070,
0x0F12000E,   //awbb_IndoorGrZones_ZInfo_m_GridSz
0x002A1074,
0x0F120126,   //awbb_IndoorGrZones_m_Boffs

             //Outdoor Zone                       
0x002A1078,                                       
0x0F120272,                                       
0x0F1202A0,                                       
0x0F12025A,                                       
0x0F1202BC,                                       
0x0F12024A,                                       
0x0F1202C0,                                       
0x0F12023C,                                       
0x0F1202BE,                                       
0x0F12022E,                                       
0x0F1202BC,                                       
0x0F120224,                                       
0x0F1202B6,                                       
0x0F120218,                                       
0x0F1202AA,                                       
0x0F120210,                                       
0x0F1202A0,                                       
0x0F12020C,                                       
0x0F120296,                                       
0x0F12020A,                                       
0x0F12028C,                                       
0x0F120212,                                       
0x0F12027E,                                       
0x0F120234,                                       
0x0F120256,                                       
                                                  
0x0F120004,   //awbb_OutdoorGrZones_m_GridStep    
0x002A10AC,                                       
0x0F12000C,   //awbb_OutdoorGrZones_ZInfo_m_GridSz
0x002A10B0,                                       
0x0F1201D8,   //awbb_OutdoorGrZones_m_Boffs     
                         
              //LowBR Zone
0x002A10B4,              
0x0F120350,              
0x0F120422,              
0x0F1202C4,              
0x0F120452,              
0x0F120278,              
0x0F12041C,              
0x0F120230,              
0x0F1203EE,              
0x0F1201F0,              
0x0F120392,              
0x0F1201C0,
0x0F120340,
0x0F120194,
0x0F120302,
0x0F12016E,
0x0F1202C2,
0x0F120148,
0x0F120286,
0x0F12018A,
0x0F120242,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,

0x0F120006,   //awbb_LowBrGrZones_m_GridStep
0x002A10E8,
0x0F12000A,   //awbb_LowBrGrZones_ZInfo_m_GridSz
0x002A10EC,
0x0F120106,   //awbb_LowBrGrZones_m_Boffs

              //LowTemp Zone
0x002A10F0,
0x0F120380,
0x0F120000,   //awbb_CrclLowT_R_c
0x0F120168,
0x0F120000,   //awbb_CrclLowT_B_c
0x0F122D90,
0x0F120000,   //awbb_CrclLowT_Rad_c

              //AWB Convergence Speed
0x002A1464,
0x0F120008,
0x0F120190,
0x0F1200A0,

0x002A1228,
0x0F1200C0,
0x002A122C,
0x0F120010,
0x002A122A,
0x0F120010,

0x002A120A,
0x0F1205D5,   //awbb_MvEq_RBthresh
0x002A120E,
0x0F120000,

0x0F120771,
0x0F1203A4,
0x0F120036,
0x0F12002A,

0x002A1278,
0x0F12FEF7,
0x0F120021,
0x0F120AF0,   //0E74
0x0F120AF0,   //0E74
0x0F12018F,
0x0F120096,
0x0F12000E,
0x002A1224,
0x0F120032,
0x0F12001E,
0x0F1200C0,
0x0F120010,
0x0F120002,   //awbb_YThreshLow_Low 
0x002A2BA4,
0x0F120006,   //Mon_AWB_ByPassMode

0x002A146C,
0x0F120002,   //awbb_GridEnable

              //Grid
0x002A1434,
0x0F1202CE,   // awbb_GridConst_1			
0x0F120347,   // awbb_GridConst_1_1_  
0x0F1203C2,   // awbb_GridConst_1_2_  
0x0F1210A0,   // awbb_GridConst_2     
0x0F1210A1,   // awbb_GridConst_2_1_  
0x0F121129,   // awbb_GridConst_2_2_  
0x0F12118C,   // awbb_GridConst_2_3_  
0x0F1211BB,   // awbb_GridConst_2_4_  
0x0F12123B,   // awbb_GridConst_2_5_  
0x0F1200AB,   // awbb_GridCoeff_R_1   
0x0F1200BF,   // awbb_GridCoeff_B_1   
0x0F1200D2,   // awbb_GridCoeff_R_2   
0x0F120093,   // awbb_GridCoeff_B_2   

              //Indoor Grid Offset
0x002A13A4,
0x0F120000, 
0x0F12FFF6, 
0x0F12FFD8, 
0x0F12FFF8, 
0x0F12FFE0, 
0x0F12FFD0,
          
0x0F120000, 
0x0F12FFF6, 
0x0F12FFD8, 
0x0F12FFF8, 
0x0F12FFE0, 
0x0F12FFD0, 
          
0x0F120000, 
0x0F12FFF6, 
0x0F12FFD8, 
0x0F12FFF8, 
0x0F12FFE0, 
0x0F12FFD0, 
          
0x0F12FFEC, 
0x0F12000A, 
0x0F12000A, 
0x0F120000, 
0x0F120000, 
0x0F12FEE0, 
          
0x0F12FFEC, 
0x0F12000A, 
0x0F12000A, 
0x0F120000, 
0x0F120000, 
0x0F12FEE0, 
          
0x0F12FFEC, 
0x0F12000A, 
0x0F12000A, 
0x0F120000, 
0x0F120000, 
0x0F12FEE0, 

              //Outdoor Grid Offset
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 

0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 

0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 

0x0F12FFC0, 
0x0F12FFC0, 
0x0F12FFC0, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
          
0x0F12FFC0, 
0x0F12FFC0, 
0x0F12FFC0, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
          
0x0F12FFC0, 
0x0F12FFC0, 
0x0F12FFC0, 
0x0F120000, 
0x0F120000, 
0x0F120000, 

0x002A1208,
0x0F120020,

0x002A144E,
0x0F120000,   //awbb_RGainOff
0x0F12FFE0,   //awbb_BGainOff
0x0F120000,   //awbb_GGainOff

              //RGB Indoor Gamma
0x002A0734,
0x0F120000,
0x0F12000A,
0x0F120016,
0x0F120030,
0x0F120066,
0x0F1200D5,
0x0F120138,
0x0F120163,
0x0F120189,
0x0F1201C6,
0x0F1201F8,
0x0F120222,
0x0F120247,
0x0F120282,
0x0F1202B5,
0x0F12030F,
0x0F12035F,
0x0F1203A2,
0x0F1203D8,
0x0F1203FF,
0x0F120000,
0x0F12000A,
0x0F120016,
0x0F120030,
0x0F120066,
0x0F1200D5,
0x0F120138,
0x0F120163,
0x0F120189,
0x0F1201C6,
0x0F1201F8,
0x0F120222,
0x0F120247,
0x0F120282,
0x0F1202B5,
0x0F12030F,
0x0F12035F,
0x0F1203A2,
0x0F1203D8,
0x0F1203FF,
0x0F120000,
0x0F12000A,
0x0F120016,
0x0F120030,
0x0F120066,
0x0F1200D5,
0x0F120138,
0x0F120163,
0x0F120189,
0x0F1201C6,
0x0F1201F8,
0x0F120222,
0x0F120247,
0x0F120282,
0x0F1202B5,
0x0F12030F,
0x0F12035F,
0x0F1203A2,
0x0F1203D8,
0x0F1203FF,

              //RGB Outdoor Gamma
0x0F120000,
0x0F12000B,
0x0F120019,
0x0F120036,
0x0F12006F,
0x0F1200D8,
0x0F120135,
0x0F12015F,
0x0F120185,
0x0F1201C1,
0x0F1201F3,
0x0F120220,
0x0F12024A,
0x0F120291,
0x0F1202D0,
0x0F12032A,
0x0F12036A,
0x0F12039F,
0x0F1203CC,
0x0F1203F9,
0x0F120000,
0x0F12000B,
0x0F120019,
0x0F120036,
0x0F12006F,
0x0F1200D8,
0x0F120135,
0x0F12015F,
0x0F120185,
0x0F1201C1,
0x0F1201F3,
0x0F120220,
0x0F12024A,
0x0F120291,
0x0F1202D0,
0x0F12032A,
0x0F12036A,
0x0F12039F,
0x0F1203CC,
0x0F1203F9,
0x0F120000,
0x0F12000B,
0x0F120019,
0x0F120036,
0x0F12006F,
0x0F1200D8,
0x0F120135,
0x0F12015F,
0x0F120185,
0x0F1201C1,
0x0F1201F3,
0x0F120220,
0x0F12024A,
0x0F120291,
0x0F1202D0,
0x0F12032A,
0x0F12036A,
0x0F12039F,
0x0F1203CC,
0x0F1203F9,

              //CCM
0x002A08A6,
0x0F1200C0,
0x0F120100,
0x0F120125,
0x0F12015F,
0x0F12017C,
0x0F120194,

0x0F120001,

0x002A0898,
0x0F124800,
0x0F127000,
0x002A08A0,
0x0F1248D8,
0x0F127000,

0x002A4800,   // Horizon 
0x0F120208,
0x0F12FFB5,
0x0F12FFE8,
0x0F12FF20,
0x0F1201BF,
0x0F12FF53,
0x0F120022,
0x0F12FFEA,
0x0F1201C2,
0x0F1200C6,
0x0F120095,
0x0F12FEFD,
0x0F120206,
0x0F12FF7F,
0x0F120191,
0x0F12FF06,
0x0F1201BA,
0x0F120108,

0x0F120208,   // inca A
0x0F12FFB5, 
0x0F12FFE8, 
0x0F12FF20, 
0x0F1201BF, 
0x0F12FF53, 
0x0F120022, 
0x0F12FFEA, 
0x0F1201C2, 
0x0F1200C6, 
0x0F120095, 
0x0F12FEFD, 
0x0F120206, 
0x0F12FF7F, 
0x0F120191, 
0x0F12FF06, 
0x0F1201BA, 
0x0F120108, 
            
0x0F120208,   // WW
0x0F12FFB5, 
0x0F12FFE8, 
0x0F12FF20, 
0x0F1201BF, 
0x0F12FF53, 
0x0F120022, 
0x0F12FFEA, 
0x0F1201C2, 
0x0F1200C6, 
0x0F120095, 
0x0F12FEFD, 
0x0F120206, 
0x0F12FF7F, 
0x0F120191, 
0x0F12FF06, 
0x0F1201BA, 
0x0F120108, 
            
0x0F120204,   // CW
0x0F12FFB2, 
0x0F12FFF5, 
0x0F12FEF1, 
0x0F12014E, 
0x0F12FF18, 
0x0F12FFE6, 
0x0F12FFDD, 
0x0F1201B2, 
0x0F1200F2, 
0x0F1200CA, 
0x0F12FF48, 
0x0F120151, 
0x0F12FF50, 
0x0F120147, 
0x0F12FF75, 
0x0F120187, 
0x0F1201BF, 
            
0x0F120204,   // D50
0x0F12FFB2, 
0x0F12FFF5, 
0x0F12FEF1, 
0x0F12014E, 
0x0F12FF18, 
0x0F12FFE6, 
0x0F12FFDD, 
0x0F1201B2, 
0x0F1200F2, 
0x0F1200CA, 
0x0F12FF48, 
0x0F120151, 
0x0F12FF50, 
0x0F120147, 
0x0F12FF75, 
0x0F120187, 
0x0F1201BF, 
            
0x0F120204,   // D65
0x0F12FFB2, 
0x0F12FFF5, 
0x0F12FEF1, 
0x0F12014E, 
0x0F12FF18, 
0x0F12FFE6, 
0x0F12FFDD, 
0x0F1201B2, 
0x0F1200F2, 
0x0F1200CA, 
0x0F12FF48, 
0x0F120151, 
0x0F12FF50, 
0x0F120147, 
0x0F12FF75, 
0x0F120187, 
0x0F1201BF, 

0x0F1201E5, //Y hue-5. TVAR_wbt_pOutdoorCcm[0]
0x0F12FFA4,                              
0x0F12FFDC,                              
0x0F12FE90,                              
0x0F12013F,                              
0x0F12FF1B,                              
0x0F12FFD2,                              
0x0F12FFDF,                              
0x0F120236,                              
0x0F1200EC,                              
0x0F1200F8,                              
0x0F12FF34,                              
0x0F1201CE,                              
0x0F12FF83,                              
0x0F120195,                              
0x0F12FEF3,                              
0x0F120126,                              
0x0F120162,                              
             
              //AFIT
0x002A0944,
0x0F120050,   //afit_uNoiseIndInDoor_0_
0x0F1200B0,   //afit_uNoiseIndInDoor_1_
0x0F120196,   //afit_uNoiseIndInDoor_2_
0x0F120245,   //afit_uNoiseIndInDoor_3_
0x0F120300,   //afit_uNoiseIndInDoor_4_

0x002A097A,
0x0F120001,   //afit_bUseSenBpr
0x0F1201CC,   //afit_usBprThr_0_
0x0F1201CC,   //afit_usBprThr_1_
0x0F1201CC,   //afit_usBprThr_2_
0x0F1201CC,   //afit_usBprThr_3_
0x0F1201CC,   //afit_usBprThr_4_
0x0F120180,   //afit_NIContrastAFITValue
0x0F120196,   //afit_NIContrastTh

0x002A0976,
0x0F120070,
0x0F120005,

0x002A0938,
0x0F120000,
0x0F120014,   //SARR_uNormBrInDoor_0_
0x0F1200D2,   //SARR_uNormBrInDoor_1_
0x0F120384,   //SARR_uNormBrInDoor_2_
0x0F1207D0,   //SARR_uNormBrInDoor_3_
0x0F121388,   //SARR_uNormBrInDoor_4_

0x002A098C,

              //AFIT 0
0x0F120000,   //7000098C AFIT16_BRIGHTNESS           	
0x0F120000,   //7000098E AFIT16_CONTRAST                                                              	
0x0F120000,   //70000990 AFIT16_SATURATION                                                            	
0x0F120000,   //70000992 AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000994 AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000996 AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000998 AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //7000099A AFIT16_postdmsc_iHighBright                                                  	
0x0F12005F,   //7000099C AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //7000099E AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //700009A0 AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //700009A2 AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //700009A4 AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //700009A6 AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //700009A8 AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120040,   //700009AA AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F1200A0,   //700009AC AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //700009AE AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //700009B0 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //700009B2 AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F123604,   //700009B4 AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F12032A,   //700009B6 AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120403,   //700009B8 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F121B06,   //700009BA AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F126015,   //700009BC AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F1200C0,   //700009BE AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F126080,   //700009C0 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F124080,   //700009C2 AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120640,   //700009C4 AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //700009C6 AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //700009C8 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //700009CA AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120000,   //700009CC AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120400,   //700009CE AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12365A,   //700009D0 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F12102A,   //700009D2 AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //700009D4 AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F120600,   //700009D6 AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //700009D8 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120505,   //700009DA AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //700009DC AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //700009DE AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //700009E0 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F123028,   //700009E2 AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F120418,   //700009E4 AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //700009E6 AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F120800,   //700009E8 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F121804,   //700009EA AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //700009EC AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //700009EE AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //700009F0 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //700009F2 AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //700009F4 AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //700009F6 AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //700009F8 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //700009FA AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //700009FC AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //700009FE AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000A00 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000A02 AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000A04 AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120205,   //70000A06 AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000A08 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000A0A AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120306,   //70000A0C AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120407,   //70000A0E AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F121C04,   //70000A10 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F120214,   //70000A12 AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121002,   //70000A14 AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120610,   //70000A16 AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000A18 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F124A18,   //70000A1A AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000A1C AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120348,   //70000A1E AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000A20 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000A22 AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000A24 AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F122A36,   //70000A26 AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000A28 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F122A36,   //70000A2A AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000A2C AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000A2E AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000A30 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000A32 AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F123601,   //70000A34 AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F12242A,   //70000A36 AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F123660,   //70000A38 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF2A,   //70000A3A AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000A3C AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000A3E AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000A40 AFITB_bnr_nClustLevel_C      [0] 
              
              //AFIT 1
0x0F120000,   //70000A42 AFIT16_BRIGHTNESS
0x0F120000,   //70000A44 AFIT16_CONTRAST                                                              	
0x0F120000,   //70000A46 AFIT16_SATURATION                                                            	
0x0F120000,   //70000A48 AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000A4A AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000A4C AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000A4E AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //70000A50 AFIT16_postdmsc_iHighBright                                                  	
0x0F120051,   //70000A52 AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //70000A54 AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //70000A56 AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //70000A58 AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //70000A5A AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //70000A5C AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //70000A5E AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120060,   //70000A60 AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F120100,   //70000A62 AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //70000A64 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //70000A66 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //70000A68 AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F122404,   //70000A6A AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F12031B,   //70000A6C AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120103,   //70000A6E AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F121205,   //70000A70 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F12400D,   //70000A72 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F120080,   //70000A74 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F122080,   //70000A76 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F123040,   //70000A78 AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120630,   //70000A7A AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //70000A7C AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //70000A7E AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //70000A80 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120404,   //70000A82 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120300,   //70000A84 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12245A,   //70000A86 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F121018,   //70000A88 AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //70000A8A AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F120B00,   //70000A8C AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //70000A8E AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120505,   //70000A90 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //70000A92 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //70000A94 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //70000A96 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F123428,   //70000A98 AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F12041C,   //70000A9A AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //70000A9C AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F120800,   //70000A9E AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F121004,   //70000AA0 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //70000AA2 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //70000AA4 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //70000AA6 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //70000AA8 AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //70000AAA AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //70000AAC AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //70000AAE AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //70000AB0 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //70000AB2 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //70000AB4 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000AB6 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000AB8 AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000ABA AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120205,   //70000ABC AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000ABE AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000AC0 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120306,   //70000AC2 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120407,   //70000AC4 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F121F04,   //70000AC6 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F120218,   //70000AC8 AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121102,   //70000ACA AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120611,   //70000ACC AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000ACE AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F128018,   //70000AD0 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000AD2 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120380,   //70000AD4 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000AD6 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000AD8 AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000ADA AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F121B24,   //70000ADC AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000ADE AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F121D22,   //70000AE0 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000AE2 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000AE4 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000AE6 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000AE8 AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F122401,   //70000AEA AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F12241B,   //70000AEC AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F121E60,   //70000AEE AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF18,   //70000AF0 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000AF2 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000AF4 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000AF6 AFITB_bnr_nClustLevel_C      [0]   
              
              //AFIT 2                                            	
0x0F120000,   //70000AF8 AFIT16_BRIGHTNESS                   
0x0F120000,   //70000AFA AFIT16_CONTRAST                                                              	
0x0F120000,   //70000AFC AFIT16_SATURATION                                                            	
0x0F120000,   //70000AFE AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000B00 AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000B02 AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000B04 AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //70000B06 AFIT16_postdmsc_iHighBright                                                  	
0x0F120043,   //70000B08 AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //70000B0A AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //70000B0C AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //70000B0E AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //70000B10 AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //70000B12 AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //70000B14 AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120060,   //70000B16 AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F120100,   //70000B18 AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //70000B1A AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //70000B1C AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //70000B1E AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F121B04,   //70000B20 AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F120312,   //70000B22 AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120003,   //70000B24 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F120C03,   //70000B26 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F122806,   //70000B28 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F120060,   //70000B2A AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F121580,   //70000B2C AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F122020,   //70000B2E AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120620,   //70000B30 AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //70000B32 AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //70000B34 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //70000B36 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120404,   //70000B38 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120300,   //70000B3A AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12145A,   //70000B3C AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F121010,   //70000B3E AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //70000B40 AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F120E00,   //70000B42 AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //70000B44 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120504,   //70000B46 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //70000B48 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //70000B4A AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //70000B4C AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F123828,   //70000B4E AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F120428,   //70000B50 AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //70000B52 AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F128000,   //70000B54 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F120A04,   //70000B56 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //70000B58 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //70000B5A AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //70000B5C AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //70000B5E AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //70000B60 AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //70000B62 AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //70000B64 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //70000B66 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //70000B68 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //70000B6A AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000B6C AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000B6E AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000B70 AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120207,   //70000B72 AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000B74 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000B76 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120306,   //70000B78 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120407,   //70000B7A AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F122404,   //70000B7C AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F120221,   //70000B7E AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121202,   //70000B80 AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120613,   //70000B82 AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000B84 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F128018,   //70000B86 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000B88 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120080,   //70000B8A AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000B8C AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000B8E AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000B90 AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F12141D,   //70000B92 AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000B94 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F120C0C,   //70000B96 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000B98 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000B9A AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000B9C AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000B9E AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F121B01,   //70000BA0 AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F122412,   //70000BA2 AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F120C60,   //70000BA4 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF0C,   //70000BA6 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000BA8 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000BAA AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000BAC AFITB_bnr_nClustLevel_C      [0] 
              
              //AFIT 3                                               	
0x0F120000,   //70000BAE AFIT16_BRIGHTNESS 
0x0F120000,   //70000BB0 AFIT16_CONTRAST                                                              	
0x0F120000,   //70000BB2 AFIT16_SATURATION                                                            	
0x0F120000,   //70000BB4 AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000BB6 AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000BB8 AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000BBA AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //70000BBC AFIT16_postdmsc_iHighBright                                                  	
0x0F120032,   //70000BBE AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //70000BC0 AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //70000BC2 AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //70000BC4 AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //70000BC6 AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //70000BC8 AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //70000BCA AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120060,   //70000BCC AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F120100,   //70000BCE AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //70000BD0 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //70000BD2 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //70000BD4 AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F121504,   //70000BD6 AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F12030F,   //70000BD8 AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120003,   //70000BDA AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F120902,   //70000BDC AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F122004,   //70000BDE AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F120050,   //70000BE0 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F121140,   //70000BE2 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F12201C,   //70000BE4 AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120620,   //70000BE6 AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //70000BE8 AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //70000BEA AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //70000BEC AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120404,   //70000BEE AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120300,   //70000BF0 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12145A,   //70000BF2 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F121010,   //70000BF4 AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //70000BF6 AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F121000,   //70000BF8 AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //70000BFA AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120503,   //70000BFC AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //70000BFE AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //70000C00 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //70000C02 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F123C28,   //70000C04 AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F12042C,   //70000C06 AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //70000C08 AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F12FF00,   //70000C0A AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F120904,   //70000C0C AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //70000C0E AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //70000C10 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //70000C12 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //70000C14 AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //70000C16 AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //70000C18 AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //70000C1A AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //70000C1C AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //70000C1E AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //70000C20 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000C22 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000C24 AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000C26 AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120206,   //70000C28 AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000C2A AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000C2C AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120305,   //70000C2E AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120406,   //70000C30 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F122804,   //70000C32 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F120228,   //70000C34 AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121402,   //70000C36 AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120618,   //70000C38 AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000C3A AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F128018,   //70000C3C AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000C3E AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120080,   //70000C40 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000C42 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000C44 AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000C46 AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F121117,   //70000C48 AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000C4A AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F120A0A,   //70000C4C AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000C4E AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000C50 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000C52 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000C54 AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F121501,   //70000C56 AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F12240F,   //70000C58 AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F120A60,   //70000C5A AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF0A,   //70000C5C AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000C5E AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000C60 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000C62 AFITB_bnr_nClustLevel_C      [0] 
              
              //AFIT 4                                                   	
0x0F120000,   //70000C64 AFIT16_BRIGHTNESS    
0x0F120000,   //70000C66 AFIT16_CONTRAST                                                              	
0x0F120000,   //70000C68 AFIT16_SATURATION                                                            	
0x0F120000,   //70000C6A AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000C6C AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000C6E AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000C70 AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //70000C72 AFIT16_postdmsc_iHighBright                                                  	
0x0F120032,   //70000C74 AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //70000C76 AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //70000C78 AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //70000C7A AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //70000C7C AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //70000C7E AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //70000C80 AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120060,   //70000C82 AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F120100,   //70000C84 AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //70000C86 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //70000C88 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //70000C8A AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F120F04,   //70000C8C AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F12030C,   //70000C8E AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120003,   //70000C90 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F120602,   //70000C92 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F121803,   //70000C94 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F120040,   //70000C96 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F120E20,   //70000C98 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F122018,   //70000C9A AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120620,   //70000C9C AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //70000C9E AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //70000CA0 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //70000CA2 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120404,   //70000CA4 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120200,   //70000CA6 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12145A,   //70000CA8 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F121010,   //70000CAA AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //70000CAC AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F121200,   //70000CAE AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //70000CB0 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120502,   //70000CB2 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //70000CB4 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //70000CB6 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //70000CB8 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F124028,   //70000CBA AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F120430,   //70000CBC AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //70000CBE AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F12FF00,   //70000CC0 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F120804,   //70000CC2 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //70000CC4 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //70000CC6 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //70000CC8 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //70000CCA AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //70000CCC AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //70000CCE AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //70000CD0 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //70000CD2 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //70000CD4 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //70000CD6 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000CD8 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000CDA AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000CDC AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120205,   //70000CDE AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000CE0 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000CE2 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120306,   //70000CE4 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120407,   //70000CE6 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F122C04,   //70000CE8 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F12022C,   //70000CEA AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121402,   //70000CEC AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120618,   //70000CEE AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000CF0 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F128018,   //70000CF2 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000CF4 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120080,   //70000CF6 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000CF8 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000CFA AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000CFC AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F120C0F,   //70000CFE AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000D00 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F120808,   //70000D02 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000D04 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000D06 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000D08 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000D0A AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F120F01,   //70000D0C AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F12240C,   //70000D0E AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F120860,   //70000D10 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF08,   //70000D12 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000D14 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000D16 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000D18 AFITB_bnr_nClustLevel_C      [0]   bWideWide[1]  
                          	
0x0F1223CE,
0x0F12FDC8,
0x0F12112E,
0x0F1293A5,  
0x0F12FE67,
0x0F120000,

              //System Setting
0x002A01F8,
0x0F126590,   //REG_TC_IPRM_InClockLSBs MCLK: 26Mhz
0x002A0212,
0x0F120000,   //REG_TC_IPRM_UseNPviClocks
0x0F120002,   //REG_TC_IPRM_UseNMipiClocks
0x0F120002,   //REG_TC_IPRM_NumberOfMipiLanes
0x002A021A,
0x0F123A98,   //REG_TC_IPRM_OpClk4KHz_0 SCLK: 60Mhz
0x0F12275D,   //REG_TC_IPRM_MinOutRate4KHz_0	PCLK Min : 81Mhz
0x0F1227BD,   //REG_TC_IPRM_MaxOutRate4KHz_0	PCLK Max : 81Mhz
0x0F124F1A,   //REG_TC_IPRM_OpClk4KHz_1	SCLK 	 : 81Mhz
0x0F12275D,   //REG_TC_IPRM_MinOutRate4KHz_1	PCLK Min : 81Mhz
0x0F1227BD,   //REG_TC_IPRM_MaxOutRate4KHz_1 PCLK Max : 81Mhz
0x002A022C,
0x0F120001,   //REG_TC_IPRM_InitParamsUpdated

              //ETC Setting
0x002A0478,
0x0F12005F,   //REG_TC_BRC_usPrevQuality
0x0F12005F,   //REG_TC_BRC_usCaptureQuality

0x0F120000,   //REG_TC_THUMB_Thumb_bActive
0x0F120280,   //REG_TC_THUMB_Thumb_uWidth
0x0F1201E0,   //REG_TC_THUMB_Thumb_uHeight
0x0F120005,   //REG_TC_THUMB_Thumb_Format

0x002A17DC,
0x0F120054,   //jpeg_ManualMBCV
0x002A1AE4,
0x0F12001C,   //senHal_bExtraAddLine
0x002A0284,
0x0F120001,   //REG_TC_GP_bBypassScalerJpg
0x002A028A,
0x0F120000,   //REG_TC_GP_bUse1FrameCaptureMode 0 Continuous mode 1 Single frame mode

              //Configuration Setting
0x002A02A6,
0x0F120280,   //REG_0TC_PCFG_usWidth    // Preview Width 640
0x0F1201E0,   //REG_0TC_PCFG_usHeight   // Preview Height 480
//0x0F120140,   //REG_0TC_PCFG_usWidth    // Preview Width 320
//0x0F1200F0,   //REG_0TC_PCFG_usHeight   // Preview Height 240
0x0F120005,   //REG_0TC_PCFG_Format	5 YUV	7 Raw	9 JPG
0x0F1227BD,   //REG_0TC_PCFG_usMaxOut4KHzRate
0x0F12275D,   //REG_0TC_PCFG_usMinOut4KHzRate
0x0F120100,   //REG_0TC_PCFG_OutClkPerPix88
0x0F120300,   //REG_0TC_PCFG_uBpp88
0x0F120012,   //REG_0TC_PCFG_PVIMask
0x0F120000,   //REG_0TC_PCFG_OIFMask
0x0F1201E0,   //REG_0TC_PCFG_usJpegPacketSize
0x0F120000,   //REG_0TC_PCFG_usJpegTotalPackets
0x0F120000,   //REG_0TC_PCFG_uClockInd
0x0F120000,   //REG_0TC_PCFG_usFrTimeType
0x0F120001,   //REG_0TC_PCFG_FrRateQualityType

/* FPS e */
// 0x0F1203E8,   //REG_0TC_PCFG_usMaxFrTimeMsecMult10 // auto 15~30
// 0x0F12014A,   //REG_0TC_PCFG_usMinFrTimeMsecMult10 // auto 15~30
0x0F12014D,   //REG_0TC_PCFG_usMaxFrTimeMsecMult10  // fix 30fps
0x0F12014D,   //REG_0TC_PCFG_usMinFrTimeMsecMult10  // fix 30fps
/* FPS x */

0x002A02D0,
0x0F120000,   //REG_0TC_PCFG_uPrevMirror
0x0F120000,   //REG_0TC_PCFG_uCaptureMirror
0x0F120000,   //REG_0TC_PCFG_uRotation

0x002A0396,
0x0F120000,   //REG_0TC_CCFG_uCaptureMode
0x0F120A00,   //REG_0TC_CCFG_usWidth
0x0F120780,   //REG_0TC_CCFG_usHeight
0x0F120009,   //REG_0TC_CCFG_Format
0x0F12279D,   //REG_0TC_CCFG_usMaxOut4KHzRate
0x0F12277D,   //REG_0TC_CCFG_usMinOut4KHzRate
0x0F120100,   //REG_0TC_CCFG_OutClkPerPix88
0x0F120300,   //REG_0TC_CCFG_uBpp88
0x0F120012,   //REG_0TC_CCFG_PVIMask
0x0F120020,   //REG_0TC_CCFG_OIFMask
0x0F120810,   //REG_0TC_CCFG_usJpegPacketSize
0x0F120000,   //REG_0TC_CCFG_usJpegTotalPackets
0x0F120001,   //REG_0TC_CCFG_uClockInd
0x0F120000,   //REG_0TC_CCFG_usFrTimeType
0x0F120002,   //REG_0TC_CCFG_FrRateQualityType
0x0F120535,   //REG_0TC_CCFG_usMaxFrTimeMsecMult10
0x0F12029A,   //REG_0TC_CCFG_usMinFrTimeMsecMult10

0x002A0250,
0x0F120A00,
0x0F120780,
0x0F120010,
0x0F12000C,
0x0F120A00,
0x0F120780,
0x0F120010,
0x0F12000C,
0x002A0494,
0x0F120A00,
0x0F120780,
0x0F120000,
0x0F120000,
0x0F120A00,
0x0F120780,
0x0F120000,
0x0F120000,

0x002A0262,
0x0F120001,
0x0F120001,

0x002A1CC2,   //DRx_uDRxWeight for AutoCont function
0x0F120100, 
0x0F120100, 
0x0F120100, 
0x0F120100, 

0x002A01A8,   //ESD Check
0x0F120A0A,    

0x002A147C,   //bp_uMaxBrightnessFactor
0x0F120170,
0x002A1482,   //bp_uMinBrightnessFactor
0x0F1201E0,

0x002A0266,
0x0F120000,   //REG_TC_GP_ActivePrevConfig
0x002A026A,
0x0F120001,   //REG_TC_GP_PrevOpenAfterChange
0x002A024E,
0x0F120001,   //REG_TC_GP_NewConfigSync
0x002A0268,
0x0F120001,   //REG_TC_GP_PrevConfigChanged
0x002A0270,
0x0F120001,   //REG_TC_GP_CapConfigChanged
0x002A023E,
0x0F120001,   //REG_TC_GP_EnablePreview
0x0F120001,   //REG_TC_GP_EnablePreviewChanged


// p500 //   ,
0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

#else /* 1 - LANE */

GLOBAL const U32 reg_main_init[]
#if defined(_CAMACQ_API_C_)
={
/******************************/
0xFCFCD000,          
0x00100001,          
0x10300000,                
0x00140001,

// p100	// W,ait100mSec
0xFFFF0066,
/******************************/

                
0x0028D000,
0x002A1082,   //Driving current Setting     
0x0F120155,	  //d0_d4_cd10 d0_d4_cd10 9:0
0x0F120155,	  //d5_d9_cd10 d5_d9_cd10 9:0
0x0F120055,	  //gpio_cd10 gpio_cd10
0x0F120555,	  //clks_output_cd10 clks_output_cd10 11:0
0x002A100E,
0x0F120000,	  //pclk_delay_r

0x002A007A,
0x0F120000,

              // This register is for FACTORY ONLY. If you change it without prior notification
              // YOU are RESPONSIBLE for the FAILURE that will happen in the future.

              // ISP FE(ADLC)
0x002AE406,
0x0F120092,
0x002AE410,
0x0F123804,
0x002AE41A,
0x0F120010,   //101022 ADD adlcptune_total
0x002AE420,
0x0F120003,
0x0F120060,
0x002AE42E,
0x0F120004,
0x002AF400,
0x0F125A3C,
0x0F120023,
0x0F128080,
0x0F1203AF,
0x0F12000A,
0x0F12AA54,
0x0F120040,
0x0F12464E,
0x0F120240,
0x0F120240,
0x0F120040,
0x0F121000,
0x0F1255FF,   //555C -> 55FF
0x0F12D000,
0x0F120010,
0x0F120202,
0x0F120401,
0x0F120022,
0x0F120088,
0x0F12009F,
0x0F120000,
0x0F121800,
0x0F120088,
0x0F120000,
0x0F122428,
0x0F120000,
0x0F1203EE,
0x0F120000,
0x0F120000,
0x0F120000,
0x002AF552,
0x0F120708,
0x0F12080C,

              //For subsampling Size
0x00287000,
0x002A18BC,
0x0F120004,
0x0F1205B6,
0x0F120000,
0x0F120000,
0x0F120001,
0x0F1205BA,
0x0F120000,
0x0F120000,
0x0F120007,
0x0F1205BA,
0x0F120000,
0x0F120000,
0x0F1201F4,
0x0F12024E,
0x0F120000,
0x0F120000,
0x0F1201F4,
0x0F1205B6,
0x0F120000,
0x0F120000,
0x0F1201F4,
0x0F1205BA,
0x0F120000,
0x0F120000,
0x0F1201F4,
0x0F12024F,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120075,
0x0F1200CF,
0x0F120000,
0x0F120000,
0x0F120075,
0x0F1200D6,
0x0F120000,
0x0F120000,
0x0F120004,
0x0F1201F4,
0x0F120000,
0x0F120000,
0x0F1200F0,
0x0F1201F4,
0x0F12029E,
0x0F1205B2,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1201F8,
0x0F120228,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120208,
0x0F120238,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120218,
0x0F120238,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120001,
0x0F120009,
0x0F1200DE,
0x0F1205C0,
0x0F120000,
0x0F120000,
0x0F1200DF,
0x0F1200E4,
0x0F1201F8,
0x0F1201FD,
0x0F1205B6,
0x0F1205BB,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1201F8,
0x0F120000,
0x0F120000,
0x0F120077,
0x0F12007E,
0x0F12024F,
0x0F12025E,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,

              // For Capture 
0x0F120004,
0x0F1209D1,
0x0F120000,
0x0F120000,
0x0F120001,
0x0F1209D5,
0x0F120000,
0x0F120000,
0x0F120008,
0x0F1209D5,
0x0F120000,
0x0F120000,
0x0F1202AA,
0x0F120326,
0x0F120000,
0x0F120000,
0x0F1202AA,
0x0F1209D1,
0x0F120000,
0x0F120000,
0x0F1202AA,
0x0F1209D5,
0x0F120000,
0x0F120000,
0x0F1202AA,
0x0F120327,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120008,
0x0F120084,
0x0F120000,
0x0F120000,
0x0F120008,
0x0F12008D,
0x0F120000,
0x0F120000,
0x0F120008,
0x0F1202AA,
0x0F120000,
0x0F120000,
0x0F1200AA,
0x0F1202AA,
0x0F1203AD,
0x0F1209CD,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1202AE,
0x0F1202DE,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1202BE,
0x0F1202EE,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1202CE,
0x0F1202EE,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120001,
0x0F120009,
0x0F120095,
0x0F1209DB,
0x0F120000,
0x0F120000,
0x0F120096,
0x0F12009B,
0x0F1202AE,
0x0F1202B3,
0x0F1209D1,
0x0F1209D6,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F1202AE,
0x0F120000,
0x0F120000,
0x0F120009,
0x0F120010,
0x0F120327,
0x0F120336,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,

0x002A1AF8,
0x0F125A3C,   //senHal_TuneStr_AngTuneData1_2_D000F400 register at subsampling

0x002A1896,
0x0F120002,   //senHal_SamplingType	0002 03EE: PLA setting
0x0F120000,   //senHal_SamplingMode 0 : 2 PLA / 1 : 4PLA
0x0F120003,   //senHal_PLAOption	[0] VPLA enable  [1] HPLA enable

0x002A189E,
0x0F120FB0,   //senHal_ExpMinPixels

0x002A18AC,
0x0F120060,   //senHal_uAddColsBin
0x0F120060,   //senHal_uAddColsNoBin
0x0F1205C0,   //senHal_uMinColsBin
0x0F1205C0,   //senHal_uMinColsNoBin

0x002A1AEA,
0x0F128080,   //senHal_SubF404Tune
0x0F120080,   //senHal_FullF404Tune
0x002A1AE0,
0x0F120000,   //senHal_bSenAAC

0x002A1A72,
0x0F120000,   //senHal_bSRX	SRX off
0x002A18A2,
0x0F120004,   //senHal_NExpLinesCheckFine extend Forbidden area line
0x002A1A6A,
0x0F12009A,   //senHal_usForbiddenRightOfs extend right Forbidden area line
0x002A385E,
0x0F12024C,   //Mon_Sen_uExpPixelsOfs

0x002A0EE6,
0x0F120000,   //setot_bUseDigitalHbin
0x002A1B2A,
0x0F120300,   //senHal_TuneStr2_usAngTuneGainTh  2   70001B2A
0x0F1200D6,   //senHal_TuneStr2_AngTuneF4CA_0_   2   70001B2C
0x0F12008D,   //senHal_TuneStr2_AngTuneF4CA_1_   2   70001B2E
0x0F1200CF,   //senHal_TuneStr2_AngTuneF4C2_0_   2   70001B30
0x0F120084,   //senHal_TuneStr2_AngTuneF4C2_1_   2   70001B32

              // OTP setting 
0x002A0722,
0x0F120100,   //skl_OTP_usWaitTime This register should be positioned in fornt of D0001000
0x002A0726,
0x0F120001,   //skl_bUseOTPfunc This is OTP on/off function
0x002A08D6,
0x0F120001,   //ash_bUseOTPData
0x002A146E,
0x0F120000,   //awbb_otp_disable
0x002A08DC,
0x0F120001,   //ash_bUseGasAlphaOTP

              // TnP setting 
              // Start of Patch data
0x00287000,
0x002A3AF8,
0x0F12B570,   // 70003AF8 
0x0F124B33,   // 70003AFA 
0x0F12216F,   // 70003AFC 
0x0F124833,   // 70003AFE 
0x0F128C80,   // 70003B00 
0x0F122200,   // 70003B02 
0x0F12C008,   // 70003B04 
0x0F126001,   // 70003B06 
0x0F124931,   // 70003B08 
0x0F124832,   // 70003B0A 
0x0F122401,   // 70003B0C 
0x0F12F000,   // 70003B0E 
0x0F12FB1F,   // 70003B10 
0x0F124931,   // 70003B12 
0x0F124831,   // 70003B14 
0x0F122502,   // 70003B16 
0x0F120022,   // 70003B18 
0x0F12F000,   // 70003B1A 
0x0F12FB19,   // 70003B1C 
0x0F124830,   // 70003B1E 
0x0F120261,   // 70003B20 
0x0F128001,   // 70003B22 
0x0F122100,   // 70003B24 
0x0F128041,   // 70003B26 
0x0F12492E,   // 70003B28 
0x0F12482F,   // 70003B2A 
0x0F126041,   // 70003B2C 
0x0F12492F,   // 70003B2E 
0x0F12482F,   // 70003B30 
0x0F12002A,   // 70003B32 
0x0F122403,   // 70003B34 
0x0F12F000,   // 70003B36 
0x0F12FB0B,   // 70003B38 
0x0F12482B,   // 70003B3A 
0x0F12492D,   // 70003B3C 
0x0F1230C0,   // 70003B3E 
0x0F1263C1,   // 70003B40 
0x0F124929,   // 70003B42 
0x0F12482C,   // 70003B44 
0x0F123980,   // 70003B46 
0x0F126408,   // 70003B48 
0x0F12482C,   // 70003B4A 
0x0F12492C,   // 70003B4C 
0x0F126388,   // 70003B4E 
0x0F12492C,   // 70003B50 
0x0F12482D,   // 70003B52 
0x0F122504,   // 70003B54 
0x0F120022,   // 70003B56 
0x0F12F000,   // 70003B58 
0x0F12FAFA,   // 70003B5A 
0x0F12492B,   // 70003B5C 
0x0F12482C,   // 70003B5E 
0x0F122405,   // 70003B60 
0x0F12002A,   // 70003B62 
0x0F12F000,   // 70003B64 
0x0F12F86C,   // 70003B66 
0x0F124829,   // 70003B68 
0x0F12492A,   // 70003B6A 
0x0F120022,   // 70003B6C 
0x0F122506,   // 70003B6E 
0x0F121D80,   // 70003B70 
0x0F12F000,   // 70003B72 
0x0F12F865,   // 70003B74 
0x0F124826,   // 70003B76 
0x0F124927,   // 70003B78 
0x0F122407,   // 70003B7A 
0x0F12002A,   // 70003B7C 
0x0F12300C,   // 70003B7E 
0x0F12F000,   // 70003B80 
0x0F12F85E,   // 70003B82 
0x0F124822,   // 70003B84 
0x0F124925,   // 70003B86 
0x0F120022,   // 70003B88 
0x0F122508,   // 70003B8A 
0x0F123010,   // 70003B8C 
0x0F12F000,   // 70003B8E 
0x0F12F857,   // 70003B90 
0x0F124923,   // 70003B92 
0x0F124823,   // 70003B94 
0x0F122409,   // 70003B96 
0x0F12002A,   // 70003B98 
0x0F12F000,   // 70003B9A 
0x0F12FAD9,   // 70003B9C 
0x0F124922,   // 70003B9E 
0x0F124822,   // 70003BA0 
0x0F120022,   // 70003BA2 
0x0F12250A,   // 70003BA4 
0x0F12F000,   // 70003BA6 
0x0F12FAD3,   // 70003BA8 
0x0F124921,   // 70003BAA 
0x0F124821,   // 70003BAC 
0x0F12240B,   // 70003BAE 
0x0F12002A,   // 70003BB0 
0x0F12F000,   // 70003BB2 
0x0F12FACD,   // 70003BB4 
0x0F124920,   // 70003BB6 
0x0F124820,   // 70003BB8 
0x0F120022,   // 70003BBA 
0x0F12F000,   // 70003BBC 
0x0F12FAC8,   // 70003BBE 
0x0F12BC70,   // 70003BC0 
0x0F12BC08,   // 70003BC2 
0x0F124718,   // 70003BC4 
0x0F120000,   // 70003BC6 
0x0F12017B,   // 70003BC8 
0x0F124EC2,   // 70003BCA 
0x0F121F6C,   // 70003BCC 
0x0F127000,   // 70003BCE 
0x0F123C59,   // 70003BD0 
0x0F127000,   // 70003BD2 
0x0F12E38B,   // 70003BD4 
0x0F120000,   // 70003BD6 
0x0F123C91,   // 70003BD8 
0x0F127000,   // 70003BDA 
0x0F12C3B1,   // 70003BDC 
0x0F120000,   // 70003BDE 
0x0F124780,   // 70003BE0 
0x0F127000,   // 70003BE2 
0x0F123CEF,   // 70003BE4 
0x0F127000,   // 70003BE6 
0x0F120080,   // 70003BE8 
0x0F127000,   // 70003BEA 
0x0F123D2B,   // 70003BEC 
0x0F127000,   // 70003BEE 
0x0F12B49D,   // 70003BF0 
0x0F120000,   // 70003BF2 
0x0F123DD7,   // 70003BF4 
0x0F127000,   // 70003BF6 
0x0F123D8B,   // 70003BF8 
0x0F127000,   // 70003BFA 
0x0F12FFFF,   // 70003BFC 
0x0F1200FF,   // 70003BFE 
0x0F1217E0,   // 70003C00 
0x0F127000,   // 70003C02 
0x0F123F53,   // 70003C04 
0x0F127000,   // 70003C06 
0x0F12053D,   // 70003C08 
0x0F120000,   // 70003C0A 
0x0F120000,   // 70003C0C 
0x0F120A89,   // 70003C0E 
0x0F126CD2,   // 70003C10 
0x0F120000,   // 70003C12 
0x0F1202C9,   // 70003C14 
0x0F120000,   // 70003C16 
0x0F120000,   // 70003C18 
0x0F120A9A,   // 70003C1A 
0x0F120000,   // 70003C1C 
0x0F1202D2,   // 70003C1E 
0x0F123FA1,   // 70003C20 
0x0F127000,   // 70003C22 
0x0F129E65,   // 70003C24 
0x0F120000,   // 70003C26 
0x0F124015,   // 70003C28 
0x0F127000,   // 70003C2A 
0x0F127C49,   // 70003C2C 
0x0F120000,   // 70003C2E 
0x0F124089,   // 70003C30 
0x0F127000,   // 70003C32 
0x0F127C63,   // 70003C34 
0x0F120000,   // 70003C36 
0x0F1240A5,   // 70003C38 
0x0F127000,   // 70003C3A 
0x0F128F01,   // 70003C3C 
0x0F120000,   // 70003C3E 
0x0F12B570,   // 70003C40 
0x0F12000C,   // 70003C42 
0x0F120015,   // 70003C44 
0x0F120029,   // 70003C46 
0x0F12F000,   // 70003C48 
0x0F12FA8A,   // 70003C4A 
0x0F1249F8,   // 70003C4C 
0x0F1200A8,   // 70003C4E 
0x0F12500C,   // 70003C50 
0x0F12BC70,   // 70003C52 
0x0F12BC08,   // 70003C54 
0x0F124718,   // 70003C56 
0x0F126808,   // 70003C58 
0x0F120400,   // 70003C5A 
0x0F120C00,   // 70003C5C 
0x0F126849,   // 70003C5E 
0x0F120409,   // 70003C60 
0x0F120C09,   // 70003C62 
0x0F124AF3,   // 70003C64 
0x0F128992,   // 70003C66 
0x0F122A00,   // 70003C68 
0x0F12D00D,   // 70003C6A 
0x0F122300,   // 70003C6C 
0x0F121A89,   // 70003C6E 
0x0F12D400,   // 70003C70 
0x0F12000B,   // 70003C72 
0x0F120419,   // 70003C74 
0x0F120C09,   // 70003C76 
0x0F1223FF,   // 70003C78 
0x0F1233C1,   // 70003C7A 
0x0F121810,   // 70003C7C 
0x0F124298,   // 70003C7E 
0x0F12D800,   // 70003C80 
0x0F120003,   // 70003C82 
0x0F120418,   // 70003C84 
0x0F120C00,   // 70003C86 
0x0F124AEB,   // 70003C88 
0x0F128150,   // 70003C8A 
0x0F128191,   // 70003C8C 
0x0F124770,   // 70003C8E 
0x0F12B5F3,   // 70003C90 
0x0F120004,   // 70003C92 
0x0F12B081,   // 70003C94 
0x0F129802,   // 70003C96 
0x0F126800,   // 70003C98 
0x0F120600,   // 70003C9A 
0x0F120E00,   // 70003C9C 
0x0F122201,   // 70003C9E 
0x0F120015,   // 70003CA0 
0x0F120021,   // 70003CA2 
0x0F123910,   // 70003CA4 
0x0F12408A,   // 70003CA6 
0x0F1240A5,   // 70003CA8 
0x0F124FE4,   // 70003CAA 
0x0F120016,   // 70003CAC 
0x0F122C10,   // 70003CAE 
0x0F12DA03,   // 70003CB0 
0x0F128839,   // 70003CB2 
0x0F1243A9,   // 70003CB4 
0x0F128039,   // 70003CB6 
0x0F12E002,   // 70003CB8 
0x0F128879,   // 70003CBA 
0x0F1243B1,   // 70003CBC 
0x0F128079,   // 70003CBE 
0x0F12F000,   // 70003CC0 
0x0F12FA56,   // 70003CC2 
0x0F122C10,   // 70003CC4 
0x0F12DA03,   // 70003CC6 
0x0F128839,   // 70003CC8 
0x0F124329,   // 70003CCA 
0x0F128039,   // 70003CCC 
0x0F12E002,   // 70003CCE 
0x0F128879,   // 70003CD0 
0x0F124331,   // 70003CD2 
0x0F128079,   // 70003CD4 
0x0F1249DA,   // 70003CD6 
0x0F128809,   // 70003CD8 
0x0F122900,   // 70003CDA 
0x0F12D102,   // 70003CDC 
0x0F12F000,   // 70003CDE 
0x0F12FA4F,   // 70003CE0 
0x0F122000,   // 70003CE2 
0x0F129902,   // 70003CE4 
0x0F126008,   // 70003CE6 
0x0F12BCFE,   // 70003CE8 
0x0F12BC08,   // 70003CEA 
0x0F124718,   // 70003CEC 
0x0F12B538,   // 70003CEE 
0x0F129C04,   // 70003CF0 
0x0F120015,   // 70003CF2 
0x0F12002A,   // 70003CF4 
0x0F129400,   // 70003CF6 
0x0F12F000,   // 70003CF8 
0x0F12FA4A,   // 70003CFA 
0x0F124AD1,   // 70003CFC 
0x0F128811,   // 70003CFE 
0x0F122900,   // 70003D00 
0x0F12D00F,   // 70003D02 
0x0F128820,   // 70003D04 
0x0F124281,   // 70003D06 
0x0F12D20C,   // 70003D08 
0x0F128861,   // 70003D0A 
0x0F128853,   // 70003D0C 
0x0F124299,   // 70003D0E 
0x0F12D200,   // 70003D10 
0x0F121E40,   // 70003D12 
0x0F120400,   // 70003D14 
0x0F120C00,   // 70003D16 
0x0F128020,   // 70003D18 
0x0F128851,   // 70003D1A 
0x0F128061,   // 70003D1C 
0x0F124368,   // 70003D1E 
0x0F121840,   // 70003D20 
0x0F126060,   // 70003D22 
0x0F12BC38,   // 70003D24 
0x0F12BC08,   // 70003D26 
0x0F124718,   // 70003D28 
0x0F12B5F8,   // 70003D2A 
0x0F120004,   // 70003D2C 
0x0F126808,   // 70003D2E 
0x0F120400,   // 70003D30 
0x0F120C00,   // 70003D32 
0x0F122201,   // 70003D34 
0x0F120015,   // 70003D36 
0x0F120021,   // 70003D38 
0x0F123910,   // 70003D3A 
0x0F12408A,   // 70003D3C 
0x0F1240A5,   // 70003D3E 
0x0F124FBE,   // 70003D40 
0x0F120016,   // 70003D42 
0x0F122C10,   // 70003D44 
0x0F12DA03,   // 70003D46 
0x0F128839,   // 70003D48 
0x0F1243A9,   // 70003D4A 
0x0F128039,   // 70003D4C 
0x0F12E002,   // 70003D4E 
0x0F128879,   // 70003D50 
0x0F1243B1,   // 70003D52 
0x0F128079,   // 70003D54 
0x0F12F000,   // 70003D56 
0x0F12FA23,   // 70003D58 
0x0F122C10,   // 70003D5A 
0x0F12DA03,   // 70003D5C 
0x0F128838,   // 70003D5E 
0x0F124328,   // 70003D60 
0x0F128038,   // 70003D62 
0x0F12E002,   // 70003D64 
0x0F128878,   // 70003D66 
0x0F124330,   // 70003D68 
0x0F128078,   // 70003D6A 
0x0F1248B6,   // 70003D6C 
0x0F128800,   // 70003D6E 
0x0F120400,   // 70003D70 
0x0F12D507,   // 70003D72 
0x0F124BB5,   // 70003D74 
0x0F127819,   // 70003D76 
0x0F124AB5,   // 70003D78 
0x0F127810,   // 70003D7A 
0x0F127018,   // 70003D7C 
0x0F127011,   // 70003D7E 
0x0F1249B4,   // 70003D80 
0x0F128188,   // 70003D82 
0x0F12BCF8,   // 70003D84 
0x0F12BC08,   // 70003D86 
0x0F124718,   // 70003D88 
0x0F12B538,   // 70003D8A 
0x0F1248B2,   // 70003D8C 
0x0F124669,   // 70003D8E 
0x0F12F000,   // 70003D90 
0x0F12FA0E,   // 70003D92 
0x0F1248B1,   // 70003D94 
0x0F1249B0,   // 70003D96 
0x0F1269C2,   // 70003D98 
0x0F122400,   // 70003D9A 
0x0F1231A8,   // 70003D9C 
0x0F122A00,   // 70003D9E 
0x0F12D008,   // 70003DA0 
0x0F1261C4,   // 70003DA2 
0x0F12684A,   // 70003DA4 
0x0F126242,   // 70003DA6 
0x0F126282,   // 70003DA8 
0x0F12466B,   // 70003DAA 
0x0F12881A,   // 70003DAC 
0x0F126302,   // 70003DAE 
0x0F12885A,   // 70003DB0 
0x0F126342,   // 70003DB2 
0x0F126A02,   // 70003DB4 
0x0F122A00,   // 70003DB6 
0x0F12D00A,   // 70003DB8 
0x0F126204,   // 70003DBA 
0x0F126849,   // 70003DBC 
0x0F126281,   // 70003DBE 
0x0F12466B,   // 70003DC0 
0x0F128819,   // 70003DC2 
0x0F126301,   // 70003DC4 
0x0F128859,   // 70003DC6 
0x0F126341,   // 70003DC8 
0x0F1249A5,   // 70003DCA 
0x0F1288C9,   // 70003DCC 
0x0F1263C1,   // 70003DCE 
0x0F12F000,   // 70003DD0 
0x0F12F9F6,   // 70003DD2 
0x0F12E7A6,   // 70003DD4 
0x0F12B5F0,   // 70003DD6 
0x0F12B08B,   // 70003DD8 
0x0F1220FF,   // 70003DDA 
0x0F121C40,   // 70003DDC 
0x0F1249A1,   // 70003DDE 
0x0F1289CC,   // 70003DE0 
0x0F124E9E,   // 70003DE2 
0x0F126AB1,   // 70003DE4 
0x0F124284,   // 70003DE6 
0x0F12D101,   // 70003DE8 
0x0F12489F,   // 70003DEA 
0x0F126081,   // 70003DEC 
0x0F126A70,   // 70003DEE 
0x0F120200,   // 70003DF0 
0x0F12F000,   // 70003DF2 
0x0F12F9ED,   // 70003DF4 
0x0F120400,   // 70003DF6 
0x0F120C00,   // 70003DF8 
0x0F124A96,   // 70003DFA 
0x0F128A11,   // 70003DFC 
0x0F129109,   // 70003DFE 
0x0F122101,   // 70003E00 
0x0F120349,   // 70003E02 
0x0F124288,   // 70003E04 
0x0F12D200,   // 70003E06 
0x0F120001,   // 70003E08 
0x0F124A92,   // 70003E0A 
0x0F128211,   // 70003E0C 
0x0F124D97,   // 70003E0E 
0x0F128829,   // 70003E10 
0x0F129108,   // 70003E12 
0x0F124A8B,   // 70003E14 
0x0F122303,   // 70003E16 
0x0F123222,   // 70003E18 
0x0F121F91,   // 70003E1A 
0x0F12F000,   // 70003E1C 
0x0F12F9DE,   // 70003E1E 
0x0F128028,   // 70003E20 
0x0F12488E,   // 70003E22 
0x0F124987,   // 70003E24 
0x0F126BC2,   // 70003E26 
0x0F126AC0,   // 70003E28 
0x0F124282,   // 70003E2A 
0x0F12D201,   // 70003E2C 
0x0F128CC8,   // 70003E2E 
0x0F128028,   // 70003E30 
0x0F1288E8,   // 70003E32 
0x0F129007,   // 70003E34 
0x0F122240,   // 70003E36 
0x0F124310,   // 70003E38 
0x0F1280E8,   // 70003E3A 
0x0F122000,   // 70003E3C 
0x0F120041,   // 70003E3E 
0x0F12194B,   // 70003E40 
0x0F12001E,   // 70003E42 
0x0F123680,   // 70003E44 
0x0F128BB2,   // 70003E46 
0x0F12AF04,   // 70003E48 
0x0F12527A,   // 70003E4A 
0x0F124A7D,   // 70003E4C 
0x0F12188A,   // 70003E4E 
0x0F128897,   // 70003E50 
0x0F1283B7,   // 70003E52 
0x0F1233A0,   // 70003E54 
0x0F12891F,   // 70003E56 
0x0F12AE01,   // 70003E58 
0x0F125277,   // 70003E5A 
0x0F128A11,   // 70003E5C 
0x0F128119,   // 70003E5E 
0x0F121C40,   // 70003E60 
0x0F120400,   // 70003E62 
0x0F120C00,   // 70003E64 
0x0F122806,   // 70003E66 
0x0F12D3E9,   // 70003E68 
0x0F12F000,   // 70003E6A 
0x0F12F9BF,   // 70003E6C 
0x0F12F000,   // 70003E6E 
0x0F12F9C5,   // 70003E70 
0x0F124F79,   // 70003E72 
0x0F1237A8,   // 70003E74 
0x0F122800,   // 70003E76 
0x0F12D10A,   // 70003E78 
0x0F121FE0,   // 70003E7A 
0x0F1238FD,   // 70003E7C 
0x0F12D001,   // 70003E7E 
0x0F121CC0,   // 70003E80 
0x0F12D105,   // 70003E82 
0x0F124874,   // 70003E84 
0x0F128829,   // 70003E86 
0x0F123818,   // 70003E88 
0x0F126840,   // 70003E8A 
0x0F124348,   // 70003E8C 
0x0F126078,   // 70003E8E 
0x0F124972,   // 70003E90 
0x0F126878,   // 70003E92 
0x0F126B89,   // 70003E94 
0x0F124288,   // 70003E96 
0x0F12D300,   // 70003E98 
0x0F120008,   // 70003E9A 
0x0F126078,   // 70003E9C 
0x0F122000,   // 70003E9E 
0x0F120041,   // 70003EA0 
0x0F12AA04,   // 70003EA2 
0x0F125A53,   // 70003EA4 
0x0F12194A,   // 70003EA6 
0x0F12269C,   // 70003EA8 
0x0F1252B3,   // 70003EAA 
0x0F12AB01,   // 70003EAC 
0x0F125A59,   // 70003EAE 
0x0F1232A0,   // 70003EB0 
0x0F128111,   // 70003EB2 
0x0F121C40,   // 70003EB4 
0x0F120400,   // 70003EB6 
0x0F120C00,   // 70003EB8 
0x0F122806,   // 70003EBA 
0x0F12D3F0,   // 70003EBC 
0x0F124965,   // 70003EBE 
0x0F129809,   // 70003EC0 
0x0F128208,   // 70003EC2 
0x0F129808,   // 70003EC4 
0x0F128028,   // 70003EC6 
0x0F129807,   // 70003EC8 
0x0F1280E8,   // 70003ECA 
0x0F121FE0,   // 70003ECC 
0x0F1238FD,   // 70003ECE 
0x0F12D13B,   // 70003ED0 
0x0F124D64,   // 70003ED2 
0x0F1289E8,   // 70003ED4 
0x0F121FC1,   // 70003ED6 
0x0F1239FF,   // 70003ED8 
0x0F12D136,   // 70003EDA 
0x0F124C5F,   // 70003EDC 
0x0F128AE0,   // 70003EDE 
0x0F12F000,   // 70003EE0 
0x0F12F994,   // 70003EE2 
0x0F120006,   // 70003EE4 
0x0F128B20,   // 70003EE6 
0x0F12F000,   // 70003EE8 
0x0F12F998,   // 70003EEA 
0x0F129000,   // 70003EEC 
0x0F126AA1,   // 70003EEE 
0x0F126878,   // 70003EF0 
0x0F121809,   // 70003EF2 
0x0F120200,   // 70003EF4 
0x0F12F000,   // 70003EF6 
0x0F12F96B,   // 70003EF8 
0x0F120400,   // 70003EFA 
0x0F120C00,   // 70003EFC 
0x0F120022,   // 70003EFE 
0x0F123246,   // 70003F00 
0x0F120011,   // 70003F02 
0x0F12310A,   // 70003F04 
0x0F122305,   // 70003F06 
0x0F12F000,   // 70003F08 
0x0F12F968,   // 70003F0A 
0x0F1266E8,   // 70003F0C 
0x0F126B23,   // 70003F0E 
0x0F120002,   // 70003F10 
0x0F120031,   // 70003F12 
0x0F120018,   // 70003F14 
0x0F12F000,   // 70003F16 
0x0F12F989,   // 70003F18 
0x0F12466B,   // 70003F1A 
0x0F128518,   // 70003F1C 
0x0F126EEA,   // 70003F1E 
0x0F126B60,   // 70003F20 
0x0F129900,   // 70003F22 
0x0F12F000,   // 70003F24 
0x0F12F982,   // 70003F26 
0x0F12466B,   // 70003F28 
0x0F128558,   // 70003F2A 
0x0F120029,   // 70003F2C 
0x0F12980A,   // 70003F2E 
0x0F123170,   // 70003F30 
0x0F12F000,   // 70003F32 
0x0F12F983,   // 70003F34 
0x0F120028,   // 70003F36 
0x0F123060,   // 70003F38 
0x0F128A02,   // 70003F3A 
0x0F124946,   // 70003F3C 
0x0F123128,   // 70003F3E 
0x0F12808A,   // 70003F40 
0x0F128A42,   // 70003F42 
0x0F1280CA,   // 70003F44 
0x0F128A80,   // 70003F46 
0x0F128108,   // 70003F48 
0x0F12B00B,   // 70003F4A 
0x0F12BCF0,   // 70003F4C 
0x0F12BC08,   // 70003F4E 
0x0F124718,   // 70003F50 
0x0F12B570,   // 70003F52 
0x0F122400,   // 70003F54 
0x0F124D46,   // 70003F56 
0x0F124846,   // 70003F58 
0x0F128881,   // 70003F5A 
0x0F124846,   // 70003F5C 
0x0F128041,   // 70003F5E 
0x0F122101,   // 70003F60 
0x0F128001,   // 70003F62 
0x0F12F000,   // 70003F64 
0x0F12F972,   // 70003F66 
0x0F124842,   // 70003F68 
0x0F123820,   // 70003F6A 
0x0F128BC0,   // 70003F6C 
0x0F12F000,   // 70003F6E 
0x0F12F975,   // 70003F70 
0x0F124B42,   // 70003F72 
0x0F12220D,   // 70003F74 
0x0F120712,   // 70003F76 
0x0F1218A8,   // 70003F78 
0x0F128806,   // 70003F7A 
0x0F1200E1,   // 70003F7C 
0x0F1218C9,   // 70003F7E 
0x0F1281CE,   // 70003F80 
0x0F128846,   // 70003F82 
0x0F12818E,   // 70003F84 
0x0F128886,   // 70003F86 
0x0F12824E,   // 70003F88 
0x0F1288C0,   // 70003F8A 
0x0F128208,   // 70003F8C 
0x0F123508,   // 70003F8E 
0x0F12042D,   // 70003F90 
0x0F120C2D,   // 70003F92 
0x0F121C64,   // 70003F94 
0x0F120424,   // 70003F96 
0x0F120C24,   // 70003F98 
0x0F122C07,   // 70003F9A 
0x0F12D3EC,   // 70003F9C 
0x0F12E658,   // 70003F9E 
0x0F12B510,   // 70003FA0 
0x0F124834,   // 70003FA2 
0x0F124C34,   // 70003FA4 
0x0F1288C0,   // 70003FA6 
0x0F128060,   // 70003FA8 
0x0F122001,   // 70003FAA 
0x0F128020,   // 70003FAC 
0x0F124831,   // 70003FAE 
0x0F123820,   // 70003FB0 
0x0F128BC0,   // 70003FB2 
0x0F12F000,   // 70003FB4 
0x0F12F952,   // 70003FB6 
0x0F1288E0,   // 70003FB8 
0x0F124A31,   // 70003FBA 
0x0F122800,   // 70003FBC 
0x0F12D003,   // 70003FBE 
0x0F124930,   // 70003FC0 
0x0F128849,   // 70003FC2 
0x0F122900,   // 70003FC4 
0x0F12D009,   // 70003FC6 
0x0F122001,   // 70003FC8 
0x0F1203C0,   // 70003FCA 
0x0F128050,   // 70003FCC 
0x0F1280D0,   // 70003FCE 
0x0F122000,   // 70003FD0 
0x0F128090,   // 70003FD2 
0x0F128110,   // 70003FD4 
0x0F12BC10,   // 70003FD6 
0x0F12BC08,   // 70003FD8 
0x0F124718,   // 70003FDA 
0x0F128050,   // 70003FDC 
0x0F128920,   // 70003FDE 
0x0F1280D0,   // 70003FE0 
0x0F128960,   // 70003FE2 
0x0F120400,   // 70003FE4 
0x0F121400,   // 70003FE6 
0x0F128090,   // 70003FE8 
0x0F1289A1,   // 70003FEA 
0x0F120409,   // 70003FEC 
0x0F121409,   // 70003FEE 
0x0F128111,   // 70003FF0 
0x0F1289E3,   // 70003FF2 
0x0F128A24,   // 70003FF4 
0x0F122B00,   // 70003FF6 
0x0F12D104,   // 70003FF8 
0x0F1217C3,   // 70003FFA 
0x0F120F5B,   // 70003FFC 
0x0F121818,   // 70003FFE 
0x0F1210C0,   // 70004000 
0x0F128090,   // 70004002 
0x0F122C00,   // 70004004 
0x0F12D1E6,   // 70004006 
0x0F1217C8,   // 70004008 
0x0F120F40,   // 7000400A 
0x0F121840,   // 7000400C 
0x0F1210C0,   // 7000400E 
0x0F128110,   // 70004010 
0x0F12E7E0,   // 70004012 
0x0F12B510,   // 70004014 
0x0F12000C,   // 70004016 
0x0F124919,   // 70004018 
0x0F122204,   // 7000401A 
0x0F126820,   // 7000401C 
0x0F125E8A,   // 7000401E 
0x0F120140,   // 70004020 
0x0F121A80,   // 70004022 
0x0F120280,   // 70004024 
0x0F128849,   // 70004026 
0x0F12F000,   // 70004028 
0x0F12F920,   // 7000402A 
0x0F126020,   // 7000402C 
0x0F12E7D2,   // 7000402E 
0x0F1238D4,   // 70004030 
0x0F127000,   // 70004032 
0x0F1217D0,   // 70004034 
0x0F127000,   // 70004036 
0x0F125000,   // 70004038 
0x0F12D000,   // 7000403A 
0x0F121100,   // 7000403C 
0x0F12D000,   // 7000403E 
0x0F12171A,   // 70004040 
0x0F127000,   // 70004042 
0x0F124780,   // 70004044 
0x0F127000,   // 70004046 
0x0F122FCA,   // 70004048 
0x0F127000,   // 7000404A 
0x0F122FC5,   // 7000404C 
0x0F127000,   // 7000404E 
0x0F122FC6,   // 70004050 
0x0F127000,   // 70004052 
0x0F122ED8,   // 70004054 
0x0F127000,   // 70004056 
0x0F122BD0,   // 70004058 
0x0F127000,   // 7000405A 
0x0F1217E0,   // 7000405C 
0x0F127000,   // 7000405E 
0x0F122DE8,   // 70004060 
0x0F127000,   // 70004062 
0x0F1237E0,   // 70004064 
0x0F127000,   // 70004066 
0x0F12210C,   // 70004068 
0x0F127000,   // 7000406A 
0x0F121484,   // 7000406C 
0x0F127000,   // 7000406E 
0x0F12A006,   // 70004070 
0x0F120000,   // 70004072 
0x0F120724,   // 70004074 
0x0F127000,   // 70004076 
0x0F12A000,   // 70004078 
0x0F12D000,   // 7000407A 
0x0F122270,   // 7000407C 
0x0F127000,   // 7000407E 
0x0F122558,   // 70004080 
0x0F127000,   // 70004082 
0x0F12146C,   // 70004084 
0x0F127000,   // 70004086 
0x0F12B510,   // 70004088 
0x0F12000C,   // 7000408A 
0x0F12492E,   // 7000408C 
0x0F122208,   // 7000408E 
0x0F126820,   // 70004090 
0x0F125E8A,   // 70004092 
0x0F120140,   // 70004094 
0x0F121A80,   // 70004096 
0x0F120280,   // 70004098 
0x0F1288C9,   // 7000409A 
0x0F12F000,   // 7000409C 
0x0F12F8E6,   // 7000409E 
0x0F126020,   // 700040A0 
0x0F12E798,   // 700040A2 
0x0F12B5FE,   // 700040A4 
0x0F12000C,   // 700040A6 
0x0F126825,   // 700040A8 
0x0F126866,   // 700040AA 
0x0F1268A0,   // 700040AC 
0x0F129001,   // 700040AE 
0x0F1268E7,   // 700040B0 
0x0F121BA8,   // 700040B2 
0x0F1242B5,   // 700040B4 
0x0F12DA00,   // 700040B6 
0x0F121B70,   // 700040B8 
0x0F129000,   // 700040BA 
0x0F124922,   // 700040BC 
0x0F124823,   // 700040BE 
0x0F12884A,   // 700040C0 
0x0F128843,   // 700040C2 
0x0F12435A,   // 700040C4 
0x0F122304,   // 700040C6 
0x0F125ECB,   // 700040C8 
0x0F120A92,   // 700040CA 
0x0F1218D2,   // 700040CC 
0x0F1202D2,   // 700040CE 
0x0F120C12,   // 700040D0 
0x0F1288CB,   // 700040D2 
0x0F128880,   // 700040D4 
0x0F124343,   // 700040D6 
0x0F120A98,   // 700040D8 
0x0F122308,   // 700040DA 
0x0F125ECB,   // 700040DC 
0x0F1218C0,   // 700040DE 
0x0F1202C0,   // 700040E0 
0x0F120C00,   // 700040E2 
0x0F120411,   // 700040E4 
0x0F120400,   // 700040E6 
0x0F121409,   // 700040E8 
0x0F121400,   // 700040EA 
0x0F121A08,   // 700040EC 
0x0F124917,   // 700040EE 
0x0F1239E0,   // 700040F0 
0x0F126148,   // 700040F2 
0x0F129801,   // 700040F4 
0x0F123040,   // 700040F6 
0x0F127880,   // 700040F8 
0x0F122800,   // 700040FA 
0x0F12D103,   // 700040FC 
0x0F129801,   // 700040FE 
0x0F120029,   // 70004100 
0x0F12F000,   // 70004102 
0x0F12F8B9,   // 70004104 
0x0F128839,   // 70004106 
0x0F129800,   // 70004108 
0x0F124281,   // 7000410A 
0x0F12D814,   // 7000410C 
0x0F128879,   // 7000410E 
0x0F129800,   // 70004110 
0x0F124281,   // 70004112 
0x0F12D20C,   // 70004114 
0x0F129801,   // 70004116 
0x0F120029,   // 70004118 
0x0F12F000,   // 7000411A 
0x0F12F8B5,   // 7000411C 
0x0F129801,   // 7000411E 
0x0F120029,   // 70004120 
0x0F12F000,   // 70004122 
0x0F12F8B1,   // 70004124 
0x0F129801,   // 70004126 
0x0F120029,   // 70004128 
0x0F12F000,   // 7000412A 
0x0F12F8AD,   // 7000412C 
0x0F12E003,   // 7000412E 
0x0F129801,   // 70004130 
0x0F120029,   // 70004132 
0x0F12F000,   // 70004134 
0x0F12F8A8,   // 70004136 
0x0F129801,   // 70004138 
0x0F120032,   // 7000413A 
0x0F120039,   // 7000413C 
0x0F12F000,   // 7000413E 
0x0F12F8AB,   // 70004140 
0x0F126020,   // 70004142 
0x0F12E5D0,   // 70004144 
0x0F120000,   // 70004146 
0x0F122558,   // 70004148 
0x0F127000,   // 7000414A 
0x0F122AB8,   // 7000414C 
0x0F127000,   // 7000414E 
0x0F124778,   // 70004150 
0x0F1246C0,   // 70004152 
0x0F12C000,   // 70004154 
0x0F12E59F,   // 70004156 
0x0F12FF1C,   // 70004158 
0x0F12E12F,   // 7000415A 
0x0F121789,   // 7000415C 
0x0F120001,   // 7000415E 
0x0F124778,   // 70004160 
0x0F1246C0,   // 70004162 
0x0F12C000,   // 70004164 
0x0F12E59F,   // 70004166 
0x0F12FF1C,   // 70004168 
0x0F12E12F,   // 7000416A 
0x0F1216F1,   // 7000416C 
0x0F120001,   // 7000416E 
0x0F124778,   // 70004170 
0x0F1246C0,   // 70004172 
0x0F12C000,   // 70004174 
0x0F12E59F,   // 70004176 
0x0F12FF1C,   // 70004178 
0x0F12E12F,   // 7000417A 
0x0F12C3B1,   // 7000417C 
0x0F120000,   // 7000417E 
0x0F124778,   // 70004180 
0x0F1246C0,   // 70004182 
0x0F12C000,   // 70004184 
0x0F12E59F,   // 70004186 
0x0F12FF1C,   // 70004188 
0x0F12E12F,   // 7000418A 
0x0F12C36D,   // 7000418C 
0x0F120000,   // 7000418E 
0x0F124778,   // 70004190 
0x0F1246C0,   // 70004192 
0x0F12C000,   // 70004194 
0x0F12E59F,   // 70004196 
0x0F12FF1C,   // 70004198 
0x0F12E12F,   // 7000419A 
0x0F12F6D7,   // 7000419C 
0x0F120000,   // 7000419E 
0x0F124778,   // 700041A0 
0x0F1246C0,   // 700041A2 
0x0F12C000,   // 700041A4 
0x0F12E59F,   // 700041A6 
0x0F12FF1C,   // 700041A8 
0x0F12E12F,   // 700041AA 
0x0F12B49D,   // 700041AC 
0x0F120000,   // 700041AE 
0x0F124778,   // 700041B0 
0x0F1246C0,   // 700041B2 
0x0F12C000,   // 700041B4 
0x0F12E59F,   // 700041B6 
0x0F12FF1C,   // 700041B8 
0x0F12E12F,   // 700041BA 
0x0F127EDF,   // 700041BC 
0x0F120000,   // 700041BE 
0x0F124778,   // 700041C0 
0x0F1246C0,   // 700041C2 
0x0F12C000,   // 700041C4 
0x0F12E59F,   // 700041C6 
0x0F12FF1C,   // 700041C8 
0x0F12E12F,   // 700041CA 
0x0F12448D,   // 700041CC 
0x0F120000,   // 700041CE 
0x0F124778,   // 700041D0 
0x0F1246C0,   // 700041D2 
0x0F12F004,   // 700041D4 
0x0F12E51F,   // 700041D6 
0x0F1229EC,   // 700041D8 
0x0F120001,   // 700041DA 
0x0F124778,   // 700041DC 
0x0F1246C0,   // 700041DE 
0x0F12C000,   // 700041E0 
0x0F12E59F,   // 700041E2 
0x0F12FF1C,   // 700041E4 
0x0F12E12F,   // 700041E6 
0x0F122EF1,   // 700041E8 
0x0F120000,   // 700041EA 
0x0F124778,   // 700041EC 
0x0F1246C0,   // 700041EE 
0x0F12C000,   // 700041F0 
0x0F12E59F,   // 700041F2 
0x0F12FF1C,   // 700041F4 
0x0F12E12F,   // 700041F6 
0x0F12EE03,   // 700041F8 
0x0F120000,   // 700041FA 
0x0F124778,   // 700041FC 
0x0F1246C0,   // 700041FE 
0x0F12C000,   // 70004200 
0x0F12E59F,   // 70004202 
0x0F12FF1C,   // 70004204 
0x0F12E12F,   // 70004206 
0x0F12A58B,   // 70004208 
0x0F120000,   // 7000420A 
0x0F124778,   // 7000420C 
0x0F1246C0,   // 7000420E 
0x0F12C000,   // 70004210 
0x0F12E59F,   // 70004212 
0x0F12FF1C,   // 70004214 
0x0F12E12F,   // 70004216 
0x0F127C49,   // 70004218 
0x0F120000,   // 7000421A 
0x0F124778,   // 7000421C 
0x0F1246C0,   // 7000421E 
0x0F12C000,   // 70004220 
0x0F12E59F,   // 70004222 
0x0F12FF1C,   // 70004224 
0x0F12E12F,   // 70004226 
0x0F127C63,   // 70004228 
0x0F120000,   // 7000422A 
0x0F124778,   // 7000422C 
0x0F1246C0,   // 7000422E 
0x0F12C000,   // 70004230 
0x0F12E59F,   // 70004232 
0x0F12FF1C,   // 70004234 
0x0F12E12F,   // 70004236 
0x0F122DB7,   // 70004238 
0x0F120000,   // 7000423A 
0x0F124778,   // 7000423C 
0x0F1246C0,   // 7000423E 
0x0F12C000,   // 70004240 
0x0F12E59F,   // 70004242 
0x0F12FF1C,   // 70004244 
0x0F12E12F,   // 70004246 
0x0F12EB3D,   // 70004248 
0x0F120000,   // 7000424A 
0x0F124778,   // 7000424C 
0x0F1246C0,   // 7000424E 
0x0F12C000,   // 70004250 
0x0F12E59F,   // 70004252 
0x0F12FF1C,   // 70004254 
0x0F12E12F,   // 70004256 
0x0F12F061,   // 70004258 
0x0F120000,   // 7000425A 
0x0F124778,   // 7000425C 
0x0F1246C0,   // 7000425E 
0x0F12C000,   // 70004260 
0x0F12E59F,   // 70004262 
0x0F12FF1C,   // 70004264 
0x0F12E12F,   // 70004266 
0x0F12F0EF,   // 70004268 
0x0F120000,   // 7000426A 
0x0F124778,   // 7000426C 
0x0F1246C0,   // 7000426E 
0x0F12F004,   // 70004270 
0x0F12E51F,   // 70004272 
0x0F122824,   // 70004274 
0x0F120001,   // 70004276 
0x0F124778,   // 70004278 
0x0F1246C0,   // 7000427A 
0x0F12C000,   // 7000427C 
0x0F12E59F,   // 7000427E 
0x0F12FF1C,   // 70004280 
0x0F12E12F,   // 70004282 
0x0F128EDD,   // 70004284 
0x0F120000,   // 70004286 
0x0F124778,   // 70004288 
0x0F1246C0,   // 7000428A 
0x0F12C000,   // 7000428C 
0x0F12E59F,   // 7000428E 
0x0F12FF1C,   // 70004290 
0x0F12E12F,   // 70004292 
0x0F128DCB,   // 70004294 
0x0F120000,   // 70004296 
0x0F124778,   // 70004298 
0x0F1246C0,   // 7000429A 
0x0F12C000,   // 7000429C 
0x0F12E59F,   // 7000429E 
0x0F12FF1C,   // 700042A0 
0x0F12E12F,   // 700042A2 
0x0F128E17,   // 700042A4 
0x0F120000,   // 700042A6 
              // End of Patch Data(Last : 700042A6h)
              // Total Size 1968 
              // Addr : 3AF8  Size : 1966(7AEh)
              // #define	TNP_USER_MBCV_CONTROL		 If the user want to control MBCV manually	
              // #define TNP_4EC_MBR_TUNE			 MBR ON / OFF	
              // #define TNP_4EC_FORBIDDEN_TUNE		 FORBIDDEN TUNING : fix cintc.
              // #define TNP_AF_FINESEARCH_DRIVEBACK		 Fine search option to search on Driveback mode.
              // #define TNP_FLASH_ALG		 for support Flash alg support.	

              //TNP_Regs_usCintrTh         2   70004780	
              //TNP_Regs_usFixedCintc      2   70004782	
              //TNP_Regs_FlsWeightRIn_0_   2   70004784	
              //TNP_Regs_FlsWeightRIn_1_   2   70004786	
              //TNP_Regs_FlsWeightRIn_2_   2   70004788	
              //TNP_Regs_FlsWeightRIn_3_   2   7000478A	
              //TNP_Regs_FlsWeightRIn_4_   2   7000478C	
              //TNP_Regs_FlsWeightRIn_5_   2   7000478E	
              //TNP_Regs_FlsWeightROut_0_  2   70004790	
              //TNP_Regs_FlsWeightROut_1_  2   70004792	
              //TNP_Regs_FlsWeightROut_2_  2   70004794	
              //TNP_Regs_FlsWeightROut_3_  2   70004796	
              //TNP_Regs_FlsWeightROut_4_  2   70004798	
              //TNP_Regs_FlsWeightROut_5_  2   7000479A	

0x0028D000,
0x002A1000,
0x0F120001,
              // End of FACTORY ONLY. 

              // AF setting 
0x00287000,
0x002A01FC,
0x0F120001,   // REG_TC_IPRM_LedGpio	
             // 70001720 0100 Only STW Use IT
0x002A01FE,
0x0F120003,
0x0F120000,
0x002A0204,
0x0F120061,
0x002A020C,
0x0F122F0C,
0x0F120190,
0x002A0294,
0x0F120100,
0x0F1200E3,
0x0F120200,
0x0F120238,
0x0F1201C6,
0x0F120166,
0x0F120074,
0x0F120132,
0x0F120001,

0x002A070E,
0x0F1200FF,
0x002A071E,
0x0F120001,
0x002A163C,
0x0F120000,

0x002A1648,
0x0F129002,   // 2nd search on when 2nd search lens oppsite direction moving
0x002A1652,
0x0F120002,
0x0F120000,
0x002A15E0,
0x0F120801,   // when 2nd search 1code distance 6+1 position move

0x002A164C,
0x0F120003,
0x002A163E,
0x0F1200E5,
0x0F1200CC,   //98(60%) -> CC(80%)
0x002A15D4,
0x0F120000,
0x0F12D000,
0x002A169A,
0x0F12FF95,
0x002A166A,
0x0F120280,
0x002A1676,
0x0F1203A0,
0x0F120320,
0x002A16BC,
0x0F120030,
0x002A16E0,
0x0F120060,
0x002A16D4,
0x0F120010,
0x002A1656,
0x0F120000,
0x002A15E6,
0x0F12003C,

0x0F120015,   //af_pos_usTableLastInd
0x0F120032,
0x0F120038,
0x0F12003E,
0x0F120044,
0x0F12004A,
0x0F120050,
0x0F120056,
0x0F12005C,
0x0F120062,
0x0F120068,
0x0F12006E,
0x0F120074,
0x0F12007A,
0x0F120080,
0x0F120086,
0x0F12008C,
0x0F120092,
0x0F120098,
0x0F12009E,
0x0F1200A4,
0x0F1200AA,
0x0F1200B0,

0x002A1722,
0x0F128000,
0x0F120006,
0x0F123FF0,
0x0F1203E8,
0x0F120000,
0x0F120080,   //delay2 when threshold upper lens moving when moving distance 9 delay 80h 12.8ms delay
0x0F120009,   //threshold
0x0F120020,   //delay1 when threshold lower lens moving when moving lower then 9(1st search position table distance lower then 9) delay 20h 3.2ms delay 
0x0F120040,
0x0F120080,
0x0F1200C0,
0x0F1200E0,

0x002A028C,
0x0F120003,   //REG_TC_AF_AfCmd

              // GAS TBL setting 
0x002A08B4,
0x0F120001,   //wbt_bUseOutdoorASH

              //TVAR_ash_AwbAshCord Refer Mon_AWB_RotGain
0x002A08BC,
0x0F1200C0,   //TVAR_ash_AwbAshCord_0_ 2300K
0x0F1200DF,   //TVAR_ash_AwbAshCord_1_ 2750K
0x0F120100,   //TVAR_ash_AwbAshCord_2_ 3300K
0x0F120125,   //TVAR_ash_AwbAshCord_3_ 4150K
0x0F12015F,   //TVAR_ash_AwbAshCord_4_ 5250K
0x0F12017C,   //TVAR_ash_AwbAshCord_5_ 6400K
0x0F120194,   //TVAR_ash_AwbAshCord_6_ 7500K

0x002A08F6,
0x0F124000,
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124000,
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124000,
0x0F124000,
0x0F124000,
0x0F124000,

0x0F123800,   //4000
0x0F124000,
0x0F124000,
0x0F124000,

0x0F123B00,   //5000 
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124300,   //6500
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124300,   //7400
0x0F124000,
0x0F124000,
0x0F124000,

0x0F124500,   //4500
0x0F124000,
0x0F124000,
0x0F124000,

0x002A08F4,
0x0F120001,   //ash_bUseGasAlpha

              //AE START 
              //AE WEIGHT 
0x002A1492,
0x0F120100,
0x0F120101,
0x0F120101,
0x0F120001,
0x0F120101,
0x0F120201,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120201,
0x0F120302,
0x0F120203,
0x0F120102,
0x0F120201,
0x0F120302,
0x0F120203,
0x0F120102,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120101,
0x0F120201,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,

0x002A1484,
0x0F12003C,   //TVAR_ae_BrAve
0x002A148A,
0x0F12000F,   //ae_StatMode
0x002A058C,
0x0F123520,
0x0F120000,   //lt_uMaxExp1
0x0F12C350,
0x0F120000,   //lt_uMaxExp2
0x0F123520,
0x0F120000,   //lt_uCapMaxExp1
0x0F12C350,
0x0F120000,   //lt_uCapMaxExp2
0x002A059C,
0x0F120470,   //lt_uMaxAnGain1
0x0F120C00,   //lt_uMaxAnGain2
0x0F120100,   //lt_uMaxDigGain
0x0F121000,   //lt_uMaxTotGain

0x002A0544,
0x0F120111,   //lt_uLimitHigh
0x0F1200EF,   //lt_uLimitLow

0x002A04E6,
0x0F12077F,   //REG_TC_DBG

0x002A04D6,
0x0F120000,
0x0F120001,

0x002A0F2A,
0x0F120000,   //AFC_Default60Hz 0001:60Hz 0000h:50Hz
0x002A0F30,
0x0F120001,   //AFC_D_ConvAccelerPower

0x002A0608,
0x0F120001,   //lt_ExpGain_uSubsamplingmode
0x0F120001,   //lt_ExpGain_uNonSubsampling
0x0F120800,   //lt_ExpGain_ExpCurveGainMaxStr
0x0F120100,   //lt_ExpGain_ExpCurveGainMaxStr_0__uMaxDigGain
0x0F120001, 
0x0F120000,   //lt_ExpGain_ExpCurveGainMaxStr_0__ulExpIn_0_
0x0F120A3C,  
0x0F120000,  
0x0F120D05,  
0x0F120000,  
0x0F124008,  
0x0F120000,  
0x0F127400,  
0x0F120000,  
0x0F12C000,   //9C00->9F->A5 //400Lux
0x0F120000,  
0x0F12AD00,  
0x0F120001,  
0x0F12F1D4,  
0x0F120002,  
0x0F12DC00,  
0x0F120005,  
0x0F12DC00,  
0x0F120005,  
             
0x002A0638,
0x0F120001,
0x0F120000,   //lt_ExpGain_ExpCurveGainMaxStr_0__ulExpOut_0_
0x0F120A3C,
0x0F120000,
0x0F120D05,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F126810,
0x0F120000,
0x0F128214,
0x0F120000,
0x0F12C350,
0x0F120000,
0x0F12C350,
0x0F120000,
0x0F12C350,
0x0F120000,

0x002A0660,
0x0F120650,   //lt_ExpGain_ExpCurveGainMaxStr_1_
0x0F120100,   //lt_ExpGain_ExpCurveGainMaxStr_1__uMaxDigGain

0x002A06B8,
0x0F12452C,
0x0F120005,   //lt_uMaxLei

0x002A05D0,
0x0F120000,   //lt_mbr_Peak_behind 

              //AWB init Start point 
0x002A145E,
0x0F120580,
0x0F120428,
0x0F1207B0,

              //AWB Init 
              //White Locus 
0x002A11F0,
0x0F120120,   //awbb_IntcR
0x0F120121,   //awbb_IntcB

              //IndoorZone
0x002A101C,
0x0F12037C,   
0x0F12038E,   
0x0F12033C,   
0x0F120384,   
0x0F1202FE,   
0x0F12036C,   
0x0F1202BA,   
0x0F120352,   
0x0F12028E,   
0x0F120300,   
0x0F12026A,   
0x0F1202C8,   
0x0F120254,   
0x0F1202A8,   
0x0F120242,   
0x0F1202A0,   
0x0F12021A,   
0x0F1202A0,   
0x0F1201F4,   
0x0F120298,   
0x0F1201D4,   
0x0F120290,   
0x0F1201CC,   
0x0F120276,   
0x0F1201D2,   
0x0F120260,   
0x0F1201F6,   
0x0F12023A,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   
0x0F120000,   

0x0F120005,   //awbb_IndoorGrZones_m_GridStep
0x002A1070,
0x0F12000E,   //awbb_IndoorGrZones_ZInfo_m_GridSz
0x002A1074,
0x0F120126,   //awbb_IndoorGrZones_m_Boffs

             //Outdoor Zone                       
0x002A1078,                                       
0x0F120272,                                       
0x0F1202A0,                                       
0x0F12025A,                                       
0x0F1202BC,                                       
0x0F12024A,                                       
0x0F1202C0,                                       
0x0F12023C,                                       
0x0F1202BE,                                       
0x0F12022E,                                       
0x0F1202BC,                                       
0x0F120224,                                       
0x0F1202B6,                                       
0x0F120218,                                       
0x0F1202AA,                                       
0x0F120210,                                       
0x0F1202A0,                                       
0x0F12020C,                                       
0x0F120296,                                       
0x0F12020A,                                       
0x0F12028C,                                       
0x0F120212,                                       
0x0F12027E,                                       
0x0F120234,                                       
0x0F120256,                                       
                                                  
0x0F120004,   //awbb_OutdoorGrZones_m_GridStep    
0x002A10AC,                                       
0x0F12000C,   //awbb_OutdoorGrZones_ZInfo_m_GridSz
0x002A10B0,                                       
0x0F1201D8,   //awbb_OutdoorGrZones_m_Boffs     
                         
              //LowBR Zone
0x002A10B4,              
0x0F120350,              
0x0F120422,              
0x0F1202C4,              
0x0F120452,              
0x0F120278,              
0x0F12041C,              
0x0F120230,              
0x0F1203EE,              
0x0F1201F0,              
0x0F120392,              
0x0F1201C0,
0x0F120340,
0x0F120194,
0x0F120302,
0x0F12016E,
0x0F1202C2,
0x0F120148,
0x0F120286,
0x0F12018A,
0x0F120242,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,

0x0F120006,   //awbb_LowBrGrZones_m_GridStep
0x002A10E8,
0x0F12000A,   //awbb_LowBrGrZones_ZInfo_m_GridSz
0x002A10EC,
0x0F120106,   //awbb_LowBrGrZones_m_Boffs

              //LowTemp Zone
0x002A10F0,
0x0F120380,
0x0F120000,   //awbb_CrclLowT_R_c
0x0F120168,
0x0F120000,   //awbb_CrclLowT_B_c
0x0F122D90,
0x0F120000,   //awbb_CrclLowT_Rad_c

              //AWB Convergence Speed
0x002A1464,
0x0F120008,
0x0F120190,
0x0F1200A0,

0x002A1228,
0x0F1200C0,
0x002A122C,
0x0F120010,
0x002A122A,
0x0F120010,

0x002A120A,
0x0F1205D5,   //awbb_MvEq_RBthresh
0x002A120E,
0x0F120000,

0x0F120771,
0x0F1203A4,
0x0F120036,
0x0F12002A,

0x002A1278,
0x0F12FEF7,
0x0F120021,
0x0F120AF0,   //0E74
0x0F120AF0,   //0E74
0x0F12018F,
0x0F120096,
0x0F12000E,
0x002A1224,
0x0F120032,
0x0F12001E,
0x0F1200C0,
0x0F120010,
0x0F120002,   //awbb_YThreshLow_Low 
0x002A2BA4,
0x0F120006,   //Mon_AWB_ByPassMode

0x002A146C,
0x0F120002,   //awbb_GridEnable

              //Grid
0x002A1434,
0x0F1202CE,   // awbb_GridConst_1			
0x0F120347,   // awbb_GridConst_1_1_  
0x0F1203C2,   // awbb_GridConst_1_2_  
0x0F1210A0,   // awbb_GridConst_2     
0x0F1210A1,   // awbb_GridConst_2_1_  
0x0F121129,   // awbb_GridConst_2_2_  
0x0F12118C,   // awbb_GridConst_2_3_  
0x0F1211BB,   // awbb_GridConst_2_4_  
0x0F12123B,   // awbb_GridConst_2_5_  
0x0F1200AB,   // awbb_GridCoeff_R_1   
0x0F1200BF,   // awbb_GridCoeff_B_1   
0x0F1200D2,   // awbb_GridCoeff_R_2   
0x0F120093,   // awbb_GridCoeff_B_2   

              //Indoor Grid Offset
0x002A13A4,
0x0F120000, 
0x0F12FFF6, 
0x0F12FFD8, 
0x0F12FFF8, 
0x0F12FFE0, 
0x0F12FFD0,
          
0x0F120000, 
0x0F12FFF6, 
0x0F12FFD8, 
0x0F12FFF8, 
0x0F12FFE0, 
0x0F12FFD0, 
          
0x0F120000, 
0x0F12FFF6, 
0x0F12FFD8, 
0x0F12FFF8, 
0x0F12FFE0, 
0x0F12FFD0, 
          
0x0F12FFEC, 
0x0F12000A, 
0x0F12000A, 
0x0F120000, 
0x0F120000, 
0x0F12FEE0, 
          
0x0F12FFEC, 
0x0F12000A, 
0x0F12000A, 
0x0F120000, 
0x0F120000, 
0x0F12FEE0, 
          
0x0F12FFEC, 
0x0F12000A, 
0x0F12000A, 
0x0F120000, 
0x0F120000, 
0x0F12FEE0, 

              //Outdoor Grid Offset
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 

0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 

0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
0x0F120000, 

0x0F12FFC0, 
0x0F12FFC0, 
0x0F12FFC0, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
          
0x0F12FFC0, 
0x0F12FFC0, 
0x0F12FFC0, 
0x0F120000, 
0x0F120000, 
0x0F120000, 
          
0x0F12FFC0, 
0x0F12FFC0, 
0x0F12FFC0, 
0x0F120000, 
0x0F120000, 
0x0F120000, 

0x002A1208,
0x0F120020,

0x002A144E,
0x0F120000,   //awbb_RGainOff
0x0F12FFE0,   //awbb_BGainOff
0x0F120000,   //awbb_GGainOff

              //RGB Indoor Gamma
0x002A0734,
0x0F120000,
0x0F12000A,
0x0F120016,
0x0F120030,
0x0F120066,
0x0F1200D5,
0x0F120138,
0x0F120163,
0x0F120189,
0x0F1201C6,
0x0F1201F8,
0x0F120222,
0x0F120247,
0x0F120282,
0x0F1202B5,
0x0F12030F,
0x0F12035F,
0x0F1203A2,
0x0F1203D8,
0x0F1203FF,
0x0F120000,
0x0F12000A,
0x0F120016,
0x0F120030,
0x0F120066,
0x0F1200D5,
0x0F120138,
0x0F120163,
0x0F120189,
0x0F1201C6,
0x0F1201F8,
0x0F120222,
0x0F120247,
0x0F120282,
0x0F1202B5,
0x0F12030F,
0x0F12035F,
0x0F1203A2,
0x0F1203D8,
0x0F1203FF,
0x0F120000,
0x0F12000A,
0x0F120016,
0x0F120030,
0x0F120066,
0x0F1200D5,
0x0F120138,
0x0F120163,
0x0F120189,
0x0F1201C6,
0x0F1201F8,
0x0F120222,
0x0F120247,
0x0F120282,
0x0F1202B5,
0x0F12030F,
0x0F12035F,
0x0F1203A2,
0x0F1203D8,
0x0F1203FF,

              //RGB Outdoor Gamma
0x0F120000,
0x0F12000B,
0x0F120019,
0x0F120036,
0x0F12006F,
0x0F1200D8,
0x0F120135,
0x0F12015F,
0x0F120185,
0x0F1201C1,
0x0F1201F3,
0x0F120220,
0x0F12024A,
0x0F120291,
0x0F1202D0,
0x0F12032A,
0x0F12036A,
0x0F12039F,
0x0F1203CC,
0x0F1203F9,
0x0F120000,
0x0F12000B,
0x0F120019,
0x0F120036,
0x0F12006F,
0x0F1200D8,
0x0F120135,
0x0F12015F,
0x0F120185,
0x0F1201C1,
0x0F1201F3,
0x0F120220,
0x0F12024A,
0x0F120291,
0x0F1202D0,
0x0F12032A,
0x0F12036A,
0x0F12039F,
0x0F1203CC,
0x0F1203F9,
0x0F120000,
0x0F12000B,
0x0F120019,
0x0F120036,
0x0F12006F,
0x0F1200D8,
0x0F120135,
0x0F12015F,
0x0F120185,
0x0F1201C1,
0x0F1201F3,
0x0F120220,
0x0F12024A,
0x0F120291,
0x0F1202D0,
0x0F12032A,
0x0F12036A,
0x0F12039F,
0x0F1203CC,
0x0F1203F9,

              //CCM
0x002A08A6,
0x0F1200C0,
0x0F120100,
0x0F120125,
0x0F12015F,
0x0F12017C,
0x0F120194,

0x0F120001,

0x002A0898,
0x0F124800,
0x0F127000,
0x002A08A0,
0x0F1248D8,
0x0F127000,

0x002A4800,   // Horizon 
0x0F120208,
0x0F12FFB5,
0x0F12FFE8,
0x0F12FF20,
0x0F1201BF,
0x0F12FF53,
0x0F120022,
0x0F12FFEA,
0x0F1201C2,
0x0F1200C6,
0x0F120095,
0x0F12FEFD,
0x0F120206,
0x0F12FF7F,
0x0F120191,
0x0F12FF06,
0x0F1201BA,
0x0F120108,

0x0F120208,   // inca A
0x0F12FFB5, 
0x0F12FFE8, 
0x0F12FF20, 
0x0F1201BF, 
0x0F12FF53, 
0x0F120022, 
0x0F12FFEA, 
0x0F1201C2, 
0x0F1200C6, 
0x0F120095, 
0x0F12FEFD, 
0x0F120206, 
0x0F12FF7F, 
0x0F120191, 
0x0F12FF06, 
0x0F1201BA, 
0x0F120108, 
            
0x0F120208,   // WW
0x0F12FFB5, 
0x0F12FFE8, 
0x0F12FF20, 
0x0F1201BF, 
0x0F12FF53, 
0x0F120022, 
0x0F12FFEA, 
0x0F1201C2, 
0x0F1200C6, 
0x0F120095, 
0x0F12FEFD, 
0x0F120206, 
0x0F12FF7F, 
0x0F120191, 
0x0F12FF06, 
0x0F1201BA, 
0x0F120108, 
            
0x0F120204,   // CW
0x0F12FFB2, 
0x0F12FFF5, 
0x0F12FEF1, 
0x0F12014E, 
0x0F12FF18, 
0x0F12FFE6, 
0x0F12FFDD, 
0x0F1201B2, 
0x0F1200F2, 
0x0F1200CA, 
0x0F12FF48, 
0x0F120151, 
0x0F12FF50, 
0x0F120147, 
0x0F12FF75, 
0x0F120187, 
0x0F1201BF, 
            
0x0F120204,   // D50
0x0F12FFB2, 
0x0F12FFF5, 
0x0F12FEF1, 
0x0F12014E, 
0x0F12FF18, 
0x0F12FFE6, 
0x0F12FFDD, 
0x0F1201B2, 
0x0F1200F2, 
0x0F1200CA, 
0x0F12FF48, 
0x0F120151, 
0x0F12FF50, 
0x0F120147, 
0x0F12FF75, 
0x0F120187, 
0x0F1201BF, 
            
0x0F120204,   // D65
0x0F12FFB2, 
0x0F12FFF5, 
0x0F12FEF1, 
0x0F12014E, 
0x0F12FF18, 
0x0F12FFE6, 
0x0F12FFDD, 
0x0F1201B2, 
0x0F1200F2, 
0x0F1200CA, 
0x0F12FF48, 
0x0F120151, 
0x0F12FF50, 
0x0F120147, 
0x0F12FF75, 
0x0F120187, 
0x0F1201BF, 

0x0F1201E5, //Y hue-5. TVAR_wbt_pOutdoorCcm[0]
0x0F12FFA4,                              
0x0F12FFDC,                              
0x0F12FE90,                              
0x0F12013F,                              
0x0F12FF1B,                              
0x0F12FFD2,                              
0x0F12FFDF,                              
0x0F120236,                              
0x0F1200EC,                              
0x0F1200F8,                              
0x0F12FF34,                              
0x0F1201CE,                              
0x0F12FF83,                              
0x0F120195,                              
0x0F12FEF3,                              
0x0F120126,                              
0x0F120162,                              
             
              //AFIT
0x002A0944,
0x0F120050,   //afit_uNoiseIndInDoor_0_
0x0F1200B0,   //afit_uNoiseIndInDoor_1_
0x0F120196,   //afit_uNoiseIndInDoor_2_
0x0F120245,   //afit_uNoiseIndInDoor_3_
0x0F120300,   //afit_uNoiseIndInDoor_4_

0x002A097A,
0x0F120001,   //afit_bUseSenBpr
0x0F1201CC,   //afit_usBprThr_0_
0x0F1201CC,   //afit_usBprThr_1_
0x0F1201CC,   //afit_usBprThr_2_
0x0F1201CC,   //afit_usBprThr_3_
0x0F1201CC,   //afit_usBprThr_4_
0x0F120180,   //afit_NIContrastAFITValue
0x0F120196,   //afit_NIContrastTh

0x002A0976,
0x0F120070,
0x0F120005,

0x002A0938,
0x0F120000,
0x0F120014,   //SARR_uNormBrInDoor_0_
0x0F1200D2,   //SARR_uNormBrInDoor_1_
0x0F120384,   //SARR_uNormBrInDoor_2_
0x0F1207D0,   //SARR_uNormBrInDoor_3_
0x0F121388,   //SARR_uNormBrInDoor_4_

0x002A098C,

              //AFIT 0
0x0F120000,   //7000098C AFIT16_BRIGHTNESS           	
0x0F120000,   //7000098E AFIT16_CONTRAST                                                              	
0x0F120000,   //70000990 AFIT16_SATURATION                                                            	
0x0F120000,   //70000992 AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000994 AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000996 AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000998 AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //7000099A AFIT16_postdmsc_iHighBright                                                  	
0x0F12005F,   //7000099C AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //7000099E AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //700009A0 AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //700009A2 AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //700009A4 AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //700009A6 AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //700009A8 AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120040,   //700009AA AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F1200A0,   //700009AC AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //700009AE AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //700009B0 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //700009B2 AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F123604,   //700009B4 AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F12032A,   //700009B6 AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120403,   //700009B8 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F121B06,   //700009BA AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F126015,   //700009BC AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F1200C0,   //700009BE AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F126080,   //700009C0 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F124080,   //700009C2 AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120640,   //700009C4 AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //700009C6 AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //700009C8 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //700009CA AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120000,   //700009CC AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120400,   //700009CE AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12365A,   //700009D0 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F12102A,   //700009D2 AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //700009D4 AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F120600,   //700009D6 AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //700009D8 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120505,   //700009DA AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //700009DC AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //700009DE AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //700009E0 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F123028,   //700009E2 AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F120418,   //700009E4 AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //700009E6 AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F120800,   //700009E8 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F121804,   //700009EA AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //700009EC AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //700009EE AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //700009F0 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //700009F2 AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //700009F4 AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //700009F6 AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //700009F8 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //700009FA AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //700009FC AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //700009FE AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000A00 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000A02 AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000A04 AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120205,   //70000A06 AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000A08 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000A0A AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120306,   //70000A0C AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120407,   //70000A0E AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F121C04,   //70000A10 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F120214,   //70000A12 AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121002,   //70000A14 AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120610,   //70000A16 AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000A18 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F124A18,   //70000A1A AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000A1C AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120348,   //70000A1E AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000A20 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000A22 AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000A24 AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F122A36,   //70000A26 AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000A28 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F122A36,   //70000A2A AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000A2C AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000A2E AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000A30 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000A32 AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F123601,   //70000A34 AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F12242A,   //70000A36 AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F123660,   //70000A38 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF2A,   //70000A3A AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000A3C AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000A3E AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000A40 AFITB_bnr_nClustLevel_C      [0] 
              
              //AFIT 1
0x0F120000,   //70000A42 AFIT16_BRIGHTNESS
0x0F120000,   //70000A44 AFIT16_CONTRAST                                                              	
0x0F120000,   //70000A46 AFIT16_SATURATION                                                            	
0x0F120000,   //70000A48 AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000A4A AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000A4C AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000A4E AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //70000A50 AFIT16_postdmsc_iHighBright                                                  	
0x0F120051,   //70000A52 AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //70000A54 AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //70000A56 AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //70000A58 AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //70000A5A AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //70000A5C AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //70000A5E AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120060,   //70000A60 AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F120100,   //70000A62 AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //70000A64 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //70000A66 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //70000A68 AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F122404,   //70000A6A AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F12031B,   //70000A6C AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120103,   //70000A6E AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F121205,   //70000A70 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F12400D,   //70000A72 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F120080,   //70000A74 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F122080,   //70000A76 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F123040,   //70000A78 AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120630,   //70000A7A AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //70000A7C AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //70000A7E AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //70000A80 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120404,   //70000A82 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120300,   //70000A84 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12245A,   //70000A86 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F121018,   //70000A88 AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //70000A8A AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F120B00,   //70000A8C AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //70000A8E AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120505,   //70000A90 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //70000A92 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //70000A94 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //70000A96 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F123428,   //70000A98 AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F12041C,   //70000A9A AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //70000A9C AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F120800,   //70000A9E AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F121004,   //70000AA0 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //70000AA2 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //70000AA4 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //70000AA6 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //70000AA8 AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //70000AAA AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //70000AAC AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //70000AAE AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //70000AB0 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //70000AB2 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //70000AB4 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000AB6 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000AB8 AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000ABA AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120205,   //70000ABC AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000ABE AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000AC0 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120306,   //70000AC2 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120407,   //70000AC4 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F121F04,   //70000AC6 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F120218,   //70000AC8 AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121102,   //70000ACA AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120611,   //70000ACC AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000ACE AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F128018,   //70000AD0 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000AD2 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120380,   //70000AD4 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000AD6 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000AD8 AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000ADA AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F121B24,   //70000ADC AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000ADE AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F121D22,   //70000AE0 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000AE2 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000AE4 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000AE6 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000AE8 AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F122401,   //70000AEA AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F12241B,   //70000AEC AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F121E60,   //70000AEE AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF18,   //70000AF0 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000AF2 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000AF4 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000AF6 AFITB_bnr_nClustLevel_C      [0]   
              
              //AFIT 2                                            	
0x0F120000,   //70000AF8 AFIT16_BRIGHTNESS                   
0x0F120000,   //70000AFA AFIT16_CONTRAST                                                              	
0x0F120000,   //70000AFC AFIT16_SATURATION                                                            	
0x0F120000,   //70000AFE AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000B00 AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000B02 AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000B04 AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //70000B06 AFIT16_postdmsc_iHighBright                                                  	
0x0F120043,   //70000B08 AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //70000B0A AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //70000B0C AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //70000B0E AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //70000B10 AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //70000B12 AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //70000B14 AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120060,   //70000B16 AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F120100,   //70000B18 AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //70000B1A AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //70000B1C AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //70000B1E AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F121B04,   //70000B20 AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F120312,   //70000B22 AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120003,   //70000B24 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F120C03,   //70000B26 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F122806,   //70000B28 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F120060,   //70000B2A AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F121580,   //70000B2C AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F122020,   //70000B2E AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120620,   //70000B30 AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //70000B32 AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //70000B34 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //70000B36 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120404,   //70000B38 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120300,   //70000B3A AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12145A,   //70000B3C AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F121010,   //70000B3E AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //70000B40 AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F120E00,   //70000B42 AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //70000B44 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120504,   //70000B46 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //70000B48 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //70000B4A AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //70000B4C AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F123828,   //70000B4E AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F120428,   //70000B50 AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //70000B52 AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F128000,   //70000B54 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F120A04,   //70000B56 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //70000B58 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //70000B5A AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //70000B5C AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //70000B5E AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //70000B60 AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //70000B62 AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //70000B64 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //70000B66 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //70000B68 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //70000B6A AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000B6C AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000B6E AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000B70 AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120207,   //70000B72 AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000B74 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000B76 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120306,   //70000B78 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120407,   //70000B7A AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F122404,   //70000B7C AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F120221,   //70000B7E AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121202,   //70000B80 AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120613,   //70000B82 AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000B84 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F128018,   //70000B86 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000B88 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120080,   //70000B8A AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000B8C AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000B8E AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000B90 AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F12141D,   //70000B92 AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000B94 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F120C0C,   //70000B96 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000B98 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000B9A AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000B9C AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000B9E AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F121B01,   //70000BA0 AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F122412,   //70000BA2 AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F120C60,   //70000BA4 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF0C,   //70000BA6 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000BA8 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000BAA AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000BAC AFITB_bnr_nClustLevel_C      [0] 
              
              //AFIT 3                                               	
0x0F120000,   //70000BAE AFIT16_BRIGHTNESS 
0x0F120000,   //70000BB0 AFIT16_CONTRAST                                                              	
0x0F120000,   //70000BB2 AFIT16_SATURATION                                                            	
0x0F120000,   //70000BB4 AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000BB6 AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000BB8 AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000BBA AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //70000BBC AFIT16_postdmsc_iHighBright                                                  	
0x0F120032,   //70000BBE AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //70000BC0 AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //70000BC2 AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //70000BC4 AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //70000BC6 AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //70000BC8 AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //70000BCA AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120060,   //70000BCC AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F120100,   //70000BCE AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //70000BD0 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //70000BD2 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //70000BD4 AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F121504,   //70000BD6 AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F12030F,   //70000BD8 AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120003,   //70000BDA AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F120902,   //70000BDC AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F122004,   //70000BDE AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F120050,   //70000BE0 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F121140,   //70000BE2 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F12201C,   //70000BE4 AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120620,   //70000BE6 AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //70000BE8 AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //70000BEA AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //70000BEC AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120404,   //70000BEE AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120300,   //70000BF0 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12145A,   //70000BF2 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F121010,   //70000BF4 AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //70000BF6 AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F121000,   //70000BF8 AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //70000BFA AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120503,   //70000BFC AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //70000BFE AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //70000C00 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //70000C02 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F123C28,   //70000C04 AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F12042C,   //70000C06 AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //70000C08 AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F12FF00,   //70000C0A AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F120904,   //70000C0C AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //70000C0E AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //70000C10 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //70000C12 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //70000C14 AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //70000C16 AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //70000C18 AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //70000C1A AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //70000C1C AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //70000C1E AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //70000C20 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000C22 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000C24 AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000C26 AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120206,   //70000C28 AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000C2A AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000C2C AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120305,   //70000C2E AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120406,   //70000C30 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F122804,   //70000C32 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F120228,   //70000C34 AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121402,   //70000C36 AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120618,   //70000C38 AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000C3A AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F128018,   //70000C3C AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000C3E AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120080,   //70000C40 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000C42 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000C44 AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000C46 AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F121117,   //70000C48 AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000C4A AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F120A0A,   //70000C4C AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000C4E AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000C50 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000C52 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000C54 AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F121501,   //70000C56 AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F12240F,   //70000C58 AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F120A60,   //70000C5A AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF0A,   //70000C5C AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000C5E AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000C60 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000C62 AFITB_bnr_nClustLevel_C      [0] 
              
              //AFIT 4                                                   	
0x0F120000,   //70000C64 AFIT16_BRIGHTNESS    
0x0F120000,   //70000C66 AFIT16_CONTRAST                                                              	
0x0F120000,   //70000C68 AFIT16_SATURATION                                                            	
0x0F120000,   //70000C6A AFIT16_SHARP_BLUR                                                            	
0x0F120000,   //70000C6C AFIT16_GLAMOUR                                                               	
0x0F1200C0,   //70000C6E AFIT16_bnr_edge_high                                                         	
0x0F120064,   //70000C70 AFIT16_postdmsc_iLowBright                                                   	
0x0F120384,   //70000C72 AFIT16_postdmsc_iHighBright                                                  	
0x0F120032,   //70000C74 AFIT16_postdmsc_iLowSat                                                      	
0x0F1201F4,   //70000C76 AFIT16_postdmsc_iHighSat                                                     	
0x0F120070,   //70000C78 AFIT16_postdmsc_iTune                                                        	
0x0F120040,   //70000C7A AFIT16_yuvemix_mNegRanges_0                                                  	
0x0F1200A0,   //70000C7C AFIT16_yuvemix_mNegRanges_1                                                  	
0x0F120100,   //70000C7E AFIT16_yuvemix_mNegRanges_2                                                  	
0x0F120010,   //70000C80 AFIT16_yuvemix_mPosRanges_0                                                  	
0x0F120060,   //70000C82 AFIT16_yuvemix_mPosRanges_1                                                  	
0x0F120100,   //70000C84 AFIT16_yuvemix_mPosRanges_2                                                  	
0x0F121430,   //70000C86 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
0x0F120201,   //70000C88 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
0x0F120204,   //70000C8A AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
0x0F120F04,   //70000C8C AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
0x0F12030C,   //70000C8E AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
0x0F120003,   //70000C90 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
0x0F120602,   //70000C92 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
0x0F121803,   //70000C94 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
0x0F120040,   //70000C96 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
0x0F120E20,   //70000C98 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
0x0F122018,   //70000C9A AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
0x0F120620,   //70000C9C AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
0x0F120306,   //70000C9E AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
0x0F122003,   //70000CA0 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
0x0F12FF01,   //70000CA2 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
0x0F120404,   //70000CA4 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
0x0F120200,   //70000CA6 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
0x0F12145A,   //70000CA8 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
0x0F121010,   //70000CAA AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
0x0F12000B,   //70000CAC AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
0x0F121200,   //70000CAE AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
0x0F125A0F,   //70000CB0 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
0x0F120502,   //70000CB2 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
0x0F121802,   //70000CB4 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
0x0F120000,   //70000CB6 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
0x0F122006,   //70000CB8 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
0x0F124028,   //70000CBA AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
0x0F120430,   //70000CBC AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
0x0F120101,   //70000CBE AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
0x0F12FF00,   //70000CC0 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
0x0F120804,   //70000CC2 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
0x0F124008,   //70000CC4 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
0x0F120540,   //70000CC6 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
0x0F128006,   //70000CC8 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
0x0F120020,   //70000CCA AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
0x0F120000,   //70000CCC AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
0x0F121800,   //70000CCE AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
0x0F120000,   //70000CD0 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
0x0F121E10,   //70000CD2 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
0x0F12000B,   //70000CD4 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
0x0F120607,   //70000CD6 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
0x0F120005,   //70000CD8 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
0x0F120607,   //70000CDA AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
0x0F120405,   //70000CDC AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
0x0F120205,   //70000CDE AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
0x0F120304,   //70000CE0 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
0x0F120409,   //70000CE2 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
0x0F120306,   //70000CE4 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
0x0F120407,   //70000CE6 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
0x0F122C04,   //70000CE8 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
0x0F12022C,   //70000CEA AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
0x0F121402,   //70000CEC AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
0x0F120618,   //70000CEE AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
0x0F121A02,   //70000CF0 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
0x0F128018,   //70000CF2 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
0x0F120080,   //70000CF4 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
0x0F120080,   //70000CF6 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
0x0F120180,   //70000CF8 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
0x0F120A0A,   //70000CFA AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
0x0F120101,   //70000CFC AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
0x0F120C0F,   //70000CFE AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
0x0F126024,   //70000D00 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
0x0F120808,   //70000D02 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
0x0F12FFFF,   //70000D04 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
0x0F120808,   //70000D06 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
0x0F120A01,   //70000D08 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
0x0F12010A,   //70000D0A AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
0x0F120F01,   //70000D0C AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
0x0F12240C,   //70000D0E AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
0x0F120860,   //70000D10 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
0x0F12FF08,   //70000D12 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
0x0F1208FF,   //70000D14 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
0x0F120008,   //70000D16 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
0x0F120001,   //70000D18 AFITB_bnr_nClustLevel_C      [0]   bWideWide[1]  
                          	
0x0F1223CE,
0x0F12FDC8,
0x0F12112E,
0x0F1293A5,  
0x0F12FE67,
0x0F120000,

              //System Setting
0x002A01F8,
0x0F126590,   //REG_TC_IPRM_InClockLSBs MCLK: 26Mhz
0x002A0212,
0x0F120000,   //REG_TC_IPRM_UseNPviClocks
0x0F120002,   //REG_TC_IPRM_UseNMipiClocks
0x0F120001,   //REG_TC_IPRM_NumberOfMipiLanes
0x002A021A,
0x0F123A98,   //REG_TC_IPRM_OpClk4KHz_0 SCLK: 60Mhz
0x0F124EEA,   //REG_TC_IPRM_MinOutRate4KHz_0	PCLK Min : 81Mhz
0x0F124F4A,   //REG_TC_IPRM_MaxOutRate4KHz_0	PCLK Max : 81Mhz
0x0F124F1A,   //REG_TC_IPRM_OpClk4KHz_1	SCLK 	 : 81Mhz
0x0F124EEA,   //REG_TC_IPRM_MinOutRate4KHz_1	PCLK Min : 81Mhz
0x0F124F4A,   //REG_TC_IPRM_MaxOutRate4KHz_1 PCLK Max : 81Mhz
0x002A022C,
0x0F120001,   //REG_TC_IPRM_InitParamsUpdated

              //ETC Setting
0x002A0478,
0x0F12005F,   //REG_TC_BRC_usPrevQuality
0x0F12005F,   //REG_TC_BRC_usCaptureQuality

0x0F120000,   //REG_TC_THUMB_Thumb_bActive
0x0F120280,   //REG_TC_THUMB_Thumb_uWidth
0x0F1201E0,   //REG_TC_THUMB_Thumb_uHeight
0x0F120005,   //REG_TC_THUMB_Thumb_Format

0x002A17DC,
0x0F120054,   //jpeg_ManualMBCV
0x002A1AE4,
0x0F12001C,   //senHal_bExtraAddLine
0x002A0284,
0x0F120001,   //REG_TC_GP_bBypassScalerJpg
0x002A028A,
0x0F120000,   //REG_TC_GP_bUse1FrameCaptureMode 0 Continuous mode 1 Single frame mode

              //Configuration Setting
0x002A02A6,

0x0F120280,   //REG_0TC_PCFG_usWidth    // Preview Width 640
0x0F1201E0,   //REG_0TC_PCFG_usHeight   // Preview Height 480
//0x0F120140,   //REG_0TC_PCFG_usWidth    // Preview Width 320
//0x0F1200F0,   //REG_0TC_PCFG_usHeight   // Preview Height 240

0x0F120005,   //REG_0TC_PCFG_Format	5 YUV	7 Raw	9 JPG
0x0F124F4A,   //REG_0TC_PCFG_usMaxOut4KHzRate
0x0F124EEA,   //REG_0TC_PCFG_usMinOut4KHzRate
0x0F120100,   //REG_0TC_PCFG_OutClkPerPix88
0x0F120300,   //REG_0TC_PCFG_uBpp88
0x0F120012,   //REG_0TC_PCFG_PVIMask
0x0F120000,   //REG_0TC_PCFG_OIFMask
0x0F1201E0,   //REG_0TC_PCFG_usJpegPacketSize
0x0F120000,   //REG_0TC_PCFG_usJpegTotalPackets
0x0F120000,   //REG_0TC_PCFG_uClockInd
0x0F120000,   //REG_0TC_PCFG_usFrTimeType
0x0F120001,   //REG_0TC_PCFG_FrRateQualityType

/* FPS e */
// 0x0F1203E8,   //REG_0TC_PCFG_usMaxFrTimeMsecMult10 // auto 15~30
// 0x0F12014A,   //REG_0TC_PCFG_usMinFrTimeMsecMult10 // auto 15~30
0x0F12014D,   //REG_0TC_PCFG_usMaxFrTimeMsecMult10  // fix 30fps
0x0F12014D,   //REG_0TC_PCFG_usMinFrTimeMsecMult10  // fix 30fps
/* FPS x */

0x002A02D0,
0x0F120000,   //REG_0TC_PCFG_uPrevMirror
0x0F120000,   //REG_0TC_PCFG_uCaptureMirror
0x0F120000,   //REG_0TC_PCFG_uRotation

0x002A0396,
0x0F120000,   //REG_0TC_CCFG_uCaptureMode
0x0F120A00,   //REG_0TC_CCFG_usWidth
0x0F120780,   //REG_0TC_CCFG_usHeight
0x0F120009,   //REG_0TC_CCFG_Format
0x0F124F4A,   //REG_0TC_CCFG_usMaxOut4KHzRate
0x0F124EEA,   //REG_0TC_CCFG_usMinOut4KHzRate
0x0F120100,   //REG_0TC_CCFG_OutClkPerPix88
0x0F120300,   //REG_0TC_CCFG_uBpp88
0x0F120012,   //REG_0TC_CCFG_PVIMask
0x0F120020,   //REG_0TC_CCFG_OIFMask
0x0F120810,   //REG_0TC_CCFG_usJpegPacketSize
0x0F120000,   //REG_0TC_CCFG_usJpegTotalPackets
0x0F120001,   //REG_0TC_CCFG_uClockInd
0x0F120000,   //REG_0TC_CCFG_usFrTimeType
0x0F120002,   //REG_0TC_CCFG_FrRateQualityType
0x0F120535,   //REG_0TC_CCFG_usMaxFrTimeMsecMult10
0x0F12029A,   //REG_0TC_CCFG_usMinFrTimeMsecMult10


0x002A0250,
0x0F120A00,
0x0F120780,
0x0F120010,
0x0F12000C,
0x0F120A00,
0x0F120780,
0x0F120010,
0x0F12000C,
0x002A0494,
0x0F120A00,
0x0F120780,
0x0F120000,
0x0F120000,
0x0F120A00,
0x0F120780,
0x0F120000,
0x0F120000,

0x002A0262,
0x0F120001,
0x0F120001,

0x002A1CC2,   //DRx_uDRxWeight for AutoCont function
0x0F120100, 
0x0F120100, 
0x0F120100, 
0x0F120100, 

0x002A01A8,   //ESD Check
0x0F120A0A,    

0x002A147C,   //bp_uMaxBrightnessFactor
0x0F120170,
0x002A1482,   //bp_uMinBrightnessFactor
0x0F1201E0,

0x002A0266,
0x0F120000,   //REG_TC_GP_ActivePrevConfig
0x002A026A,
0x0F120001,   //REG_TC_GP_PrevOpenAfterChange
0x002A024E,
0x0F120001,   //REG_TC_GP_NewConfigSync
0x002A0268,
0x0F120001,   //REG_TC_GP_PrevConfigChanged
0x002A0270,
0x0F120001,   //REG_TC_GP_CapConfigChanged
0x002A023E,
0x0F120001,   //REG_TC_GP_EnablePreview
0x0F120001,   //REG_TC_GP_EnablePreviewChanged


// p500 //   ,
0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


#endif /* LANE */




GLOBAL const U32 reg_main_fmt_jpg[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_fmt_yuv422[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA PREVIEW(640*480 / FULL)
//==========================================================
GLOBAL const U32 reg_main_preview[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A05D0,
0x0F120000,
0x002A0972,
0x0F120000,
0x002A0242,
0x0F120000,
0x002A024E,
0x0F120001,
0x002A0244,
0x0F120001,

0xFFFF0064,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// SNAPSHOT
//==========================================================

GLOBAL const U32 reg_main_snapshot[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0242,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0244,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// MIDLIGHT SNAPSHOT =======> Flash Low light snapshot
//==========================================================
GLOBAL const U32 reg_main_midlight[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// HIGHLIGHT SNAPSHOT =======> Flash HIGH light snapshot
//==========================================================
GLOBAL const U32 reg_main_highlight[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// LOWLIGHT SNAPSHOT
//==========================================================
GLOBAL const U32 reg_main_lowlight[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;



/*****************************************************************/
/*********************** N I G H T  M O D E **********************/
/*****************************************************************/

//==========================================================
// CAMERA NIGHTMODE ON
//==========================================================
GLOBAL const U32 reg_main_nightshot_on[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA NIGHTMODE OFF
//==========================================================
GLOBAL const U32 reg_main_nightshot_off[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// NIGHT-MODE SNAPSHOT
//==========================================================
GLOBAL const U32 reg_main_nightshot[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_AUTO (1/10)
//==========================================================
GLOBAL const U32 reg_main_wb_auto[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
               // 0x002A04E6 S/W Program
               // 0x0F12077F

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_DAYLIGHT (2/10)
//==========================================================
GLOBAL const U32 reg_main_wb_daylight[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
             // 0x002A04E6 S/W Program
             // 0x0F120777

0x002A04BA,
0x0F120620,
0x0F120001,
0x0F120400,
0x0F120001,
0x0F120580,
0x0F120001,
0x0F120001,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_CLOUDY  (3/10)
//==========================================================
GLOBAL const U32 reg_main_wb_cloudy[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,

          
0x002A04BA,
0x0F120740,
0x0F120001,
0x0F120400,
0x0F120001,
0x0F1204D0,
0x0F120001,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_INCANDESCENT (4/10)
//==========================================================
GLOBAL const U32 reg_main_wb_incandescent[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
             // 0x002A04E6 S/W Program
             // 0x0F120777
0x002A04BA,
0x0F1203B0,
0x0F120001,
0x0F120400,
0x0F120001,
0x0F1209F0,
0x0F120001,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (5/10)
//==========================================================
GLOBAL const U32 reg_main_wb_fluorescent[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
             // 0x002A04E6 S/W Program
             // 0x0F120777
0x002A04BA,
0x0F120600,
0x0F120001,
0x0F120470,
0x0F120001,
0x0F1209E0,
0x0F120001,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (6/10)
//==========================================================
GLOBAL const U32 reg_main_wb_twilight[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (7/10)
//==========================================================
GLOBAL const U32 reg_main_wb_tungsten[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
             // 0x002A04E6 S/W Program
             // 0x0F120777
0x002A04BA,
0x0F1203B0,
0x0F120001,
0x0F120400,
0x0F120001,
0x0F1209F0,
0x0F120001,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (8/10)
//==========================================================
GLOBAL const U32 reg_main_wb_off[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (9/10)
//==========================================================
GLOBAL const U32 reg_main_wb_horizon[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (10/10)
//==========================================================
GLOBAL const U32 reg_main_wb_shade[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_EFFECT_OFF (1/13)
//==========================================================
GLOBAL const U32 reg_main_effect_none[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A023C,
0x0F120000,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_MONO (2/13)
//==========================================================
GLOBAL const U32 reg_main_effect_gray[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A023C,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_NEGATIVE (3/13)
//==========================================================
GLOBAL const U32 reg_main_effect_negative[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A023C,
0x0F120003,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SOLARIZE (4/13)
//==========================================================
GLOBAL const U32 reg_main_effect_solarize[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A023C,
0x0F120002,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SEPIA (5/13)
//==========================================================
GLOBAL const U32 reg_main_effect_sepia[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A023C,
0x0F120004,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_POSTERIZE (6/13)
//==========================================================
GLOBAL const U32 reg_main_effect_posterize[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_WHITEBOARD (7/13)
//==========================================================
GLOBAL const U32 reg_main_effect_whiteboard[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_BLACKBOARD (8/13)
//==========================================================
GLOBAL const U32 reg_main_effect_blackboard[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_AQUA (9/13)
//==========================================================
GLOBAL const U32 reg_main_effect_aqua[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SHARPEN (10/13)
//==========================================================
GLOBAL const U32 reg_main_effect_sharpen[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_AQUA (11/13)
//==========================================================
GLOBAL const U32 reg_main_effect_vivid[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_GREEN (12/13)
//==========================================================
GLOBAL const U32 reg_main_effect_green[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SKETCH (13/13)
//==========================================================
GLOBAL const U32 reg_main_effect_sketch[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_AEC_MATRIX_METERING (2/2)
//==========================================================
GLOBAL const U32 reg_main_meter_matrix[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A1492,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,

0x002A0268,   //REG_TC_GP_PrevConfigChanged
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AEC_CENTERWEIGHTED_METERING (2/2)
//==========================================================
GLOBAL const U32 reg_main_meter_cw[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A1492,
0x0F120100,
0x0F120101,
0x0F120101,
0x0F120001,
0x0F120101,
0x0F120201,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120201,
0x0F120302,
0x0F120203,
0x0F120102,
0x0F120201,
0x0F120302,
0x0F120203,
0x0F120102,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120101,
0x0F120201,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,

0x002A0268,   //REG_TC_GP_PrevConfigChanged
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AEC_SPOT_METERING (1/2)
//==========================================================
GLOBAL const U32 reg_main_meter_spot[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A1492,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120101,
0x0F120101,
0x0F120000,
0x0F120000,
0x0F12010F,
0x0F120F01,
0x0F120000,
0x0F120000,
0x0F12010F,
0x0F120F01,
0x0F120000,
0x0F120000,
0x0F120101,
0x0F120101,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,

0x002A0268,   //REG_TC_GP_PrevConfigChanged
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AEC_FRAME_AVERAGE (2/2)
//==========================================================
GLOBAL const U32 reg_main_meter_frame[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FLIP_NONE (1/4)
//==========================================================
GLOBAL const U32 reg_main_flip_none[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FLIP_VERTICAL (2/4)
//==========================================================
GLOBAL const U32 reg_main_flip_water[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FLIP_HORIZ (3/4)
//==========================================================
GLOBAL const U32 reg_main_flip_mirror[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_FLIP_SYMMETRIC (4/4)
//==========================================================
GLOBAL const U32 reg_main_flip_water_mirror[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_5FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_5[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_FRAMERATE_7FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_7[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A02B4,
0x0F120052,
0x002A02BE,
0x0F120000,
0x0F120001,
0x0F120535,
0x0F120535,
0x002A02D0,
0x0F120000,
0x0F120000,
0x002A0266,
0x0F120000,
0x002A026A,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0268,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_10FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_10[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_15FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_15[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A02B4,
0x0F120052,
0x002A02BE,
0x0F120000,
0x0F120001,
0x0F12029A,
0x0F12029A,
0x002A02D0,
0x0F120000,
0x0F120000,
0x002A0266,
0x0F120000,
0x002A026A,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0268,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_20FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_20[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A02B4,
0x0F120052,
0x002A02BE,
0x0F120000,
0x0F120001,
0x0F1201F4,
0x0F1201F4,
0x002A02D0,
0x0F120000,
0x0F120000,
0x002A0266,
0x0F120000,
0x002A026A,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0268,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_25FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_25[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A02B4,
0x0F120052,
0x002A02BE,
0x0F120000,
0x0F120001,
0x0F120190,
0x0F120190,
0x002A02D0,
0x0F120000,
0x0F120000,
0x002A0266,
0x0F120000,
0x002A026A,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0268,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_30FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_30[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A02B4,
0x0F120052,
0x002A02BE,
0x0F120000,
0x0F120001,
0x0F12014D,
0x0F12014D,
0x002A02D0,
0x0F120000,
0x0F120000,
0x002A0266,
0x0F120000,
0x002A026A,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0268,
0x0F120001,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_AUTO_MAX15(5~15fps)
//==========================================================
GLOBAL const U32 reg_main_fps_var_15[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_BRIGHTNESS_LEVEL1 (1/9) : 
//==========================================================
GLOBAL const U32 reg_main_brightness_level_0[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL2 (2/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_1[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL3 (3/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_2[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL4 (4/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_3[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL5 (5/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_4[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL6 (6/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_5[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL7 (7/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_6[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL8 (8/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_7[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL9 (9/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_8[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL1 (1/9) : 
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_0[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0230,
0x0F12FF80,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL2 (2/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_1[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0230,
0x0F12FFA8,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL3 (3/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_2[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0230,
0x0F12FFD0,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL4 (4/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_3[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0230,
0x0F12FFE8,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL5 (5/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_4[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0230,
0x0F120000,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL6 (6/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_5[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0230,
0x0F120020,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL7 (7/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_6[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0230,
0x0F120040,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL8 (8/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_7[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0230,
0x0F120060,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL9 (9/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_8[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0230,
0x0F12007F,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AF
//==========================================================
GLOBAL const U32 reg_main_reset_af []
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_nlux []
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_llux []
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af[] // start_af
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A028C,
0x0F120005,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_off_af[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_check_af[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_manual_af[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_macro_af[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_return_manual_af[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_return_macro_af[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_normal_mode_1[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A028E,
0x0F120000,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_normal_mode_2[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A028C,
0x0F120004,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_normal_mode_3[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A1648,
0x0F129002,

0x002A15E8,
0x0F120015,   //af_pos_usTableLastInd
0x0F120032,
0x0F120038,
0x0F12003E,
0x0F120044,
0x0F12004A,
0x0F120050,
0x0F120056,
0x0F12005C,
0x0F120062,
0x0F120068,
0x0F12006E,
0x0F120074,
0x0F12007A,
0x0F120080,
0x0F120086,
0x0F12008C,
0x0F120092,
0x0F120098,
0x0F12009E,
0x0F1200A4,
0x0F1200AA,
0x0F1200B0,


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_macro_mode_1[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A028E,
0x0F1200D0,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_macro_mode_2[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A028C,
0x0F120004,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_macro_mode_3[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A1648,
0x0F129042,

0x002A15E8,
0x0F120015,   //af_pos_usTableLastInd
0x0F120032,
0x0F120038,
0x0F12003E,
0x0F120044,
0x0F12004A,
0x0F120050,
0x0F120056,
0x0F12005C,
0x0F120062,
0x0F120068,
0x0F12006E,
0x0F120074,
0x0F12007A,
0x0F120080,
0x0F120086,
0x0F12008C,
0x0F120092,
0x0F120098,
0x0F12009E,
0x0F1200A4,
0x0F1200AA,
0x0F1200B0,

0x002A15DA,
0x0F121500,   // 16 start number of table 00 End number of table

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_AUTO
//==========================================================
GLOBAL const U32 reg_main_iso_auto[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0938,   //afit_bUseNB_Afit
0x0F120000,    
0x0F120014,   //SARR_uNormBrInDoor_0_
0x0F1200D2,   //SARR_uNormBrInDoor_1_
0x0F120384,   //SARR_uNormBrInDoor_2_
0x0F1207D0,   //SARR_uNormBrInDoor_3_
0x0F121388,   //SARR_uNormBrInDoor_4_
              
0x002A0F2A,   //AFC_Default60Hz
0x0F120000,   //00:50Hz 01:60Hz            
                                         
             // 0x002A04E6 S/W Program   
             // 0x0F12077F               
                                         
0x002A04D0,                              
0x0F120000,   //REG_SF_USER_IsoType      
0x0F120000,   //REG_SF_USER_IsoVal       
0x0F120001,   //REG_SF_USER_IsoChanged   
0x002A06C2,                              
0x0F120200,   //lt_bUseSecISODgain       

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_50
//==========================================================
GLOBAL const U32 reg_main_iso_50[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0938,
0x0F120001,   //afit_bUseNB_Afit
0x0F120014,   //SARR_uNormBrInDoor_0_
0x0F1200D2,   //SARR_uNormBrInDoor_1_
0x0F120384,   //SARR_uNormBrInDoor_2_
0x0F1207D0,   //SARR_uNormBrInDoor_3_
0x0F121388,   //SARR_uNormBrInDoor_4_
 
             // 0x002A04E6 S/W Program
             // 0x0F12065F
0x002A04D6,   
0x0F120000,   //REG_SF_USER_FlickerQuant       
0x0F120001,   //REG_SF_USER_FlickerQuantChanged
              
0x002A04D0,   
0x0F120001,   //REG_SF_USER_IsoType    
0x0F120100,   //REG_SF_USER_IsoVal     
0x0F120001,   //REG_SF_USER_IsoChanged 
0x002A06C2,                            
0x0F120100,   //lt_bUseSecISODgain  

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_100
//==========================================================
GLOBAL const U32 reg_main_iso_100[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0938,
0x0F120001,   //afit_bUseNB_Afit
0x0F120014,   //SARR_uNormBrInDoor_0_
0x0F1200D2,   //SARR_uNormBrInDoor_1_
0x0F120384,   //SARR_uNormBrInDoor_2_
0x0F1207D0,   //SARR_uNormBrInDoor_3_
0x0F121388,   //SARR_uNormBrInDoor_4_
              
             // 0x002A04E6 S/W Program
             // 0x0F12065F
0x002A04D6,   
0x0F120000,   //REG_SF_USER_FlickerQuant       
0x0F120001,   //REG_SF_USER_FlickerQuantChanged
              
0x002A04D0,   
0x0F120001,   //REG_SF_USER_IsoType    
0x0F1201DE,   //REG_SF_USER_IsoVal     
0x0F120001,   //REG_SF_USER_IsoChanged 
0x002A06C2,                            
0x0F120100,   //lt_bUseSecISODgain     

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_200
//==========================================================
GLOBAL const U32 reg_main_iso_200[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0938,
0x0F120001,   //afit_bUseNB_Afit
0x0F120014,   //SARR_uNormBrInDoor_0_
0x0F1203A2,   //SARR_uNormBrInDoor_1_
0x0F120484,   //SARR_uNormBrInDoor_2_
0x0F1207D0,   //SARR_uNormBrInDoor_3_
0x0F121388,   //SARR_uNormBrInDoor_4_
              
             // 0x002A04E6 S/W Program
             // 0x0F12065F
0x002A04D6,   
0x0F120000,   //REG_SF_USER_FlickerQuant       
0x0F120001,   //REG_SF_USER_FlickerQuantChanged
              
0x002A04D0,   
0x0F120001,   //REG_SF_USER_IsoType    
0x0F1203BC,   //REG_SF_USER_IsoVal     
0x0F120001,   //REG_SF_USER_IsoChanged 
0x002A06C2,                            
0x0F120100,   //lt_bUseSecISODgain  

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_400
//==========================================================
GLOBAL const U32 reg_main_iso_400[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0938,
0x0F120001,   //afit_bUseNB_Afit
0x0F120214,   //SARR_uNormBrInDoor_0_
0x0F120BD2,   //SARR_uNormBrInDoor_1_
0x0F120C84,   //SARR_uNormBrInDoor_2_
0x0F1210D0,   //SARR_uNormBrInDoor_3_
0x0F121388,   //SARR_uNormBrInDoor_4_
              
             // 0x002A04E6 S/W Program
             // 0x0F12065F
0x002A04D6,   
0x0F120000,   //REG_SF_USER_FlickerQuant       
0x0F120001,   //REG_SF_USER_FlickerQuantChanged
              
0x002A04D0,   
0x0F120001,   //REG_SF_USER_IsoType    
0x0F120778,   //REG_SF_USER_IsoVal     
0x0F120001,   //REG_SF_USER_IsoChanged 
0x002A06C2,                            
0x0F120100,   //lt_bUseSecISODgain  

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_800
//==========================================================
GLOBAL const U32 reg_main_iso_800[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_1600
//==========================================================
GLOBAL const U32 reg_main_iso_1600[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_3200
//==========================================================
GLOBAL const U32 reg_main_iso_3200[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_AUTO (OFF)
//==========================================================
GLOBAL const U32 reg_main_scene_auto[]
#if defined(_CAMACQ_API_C_)
={
                //scene Backlight landscape
0x00287000,
0x002A1492,
0x0F120100,
0x0F120101,
0x0F120101,
0x0F120001,
0x0F120101,
0x0F120201,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120201,
0x0F120302,
0x0F120203,
0x0F120102,
0x0F120201,
0x0F120302,
0x0F120203,
0x0F120102,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120101,
0x0F120201,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
              //scene Backlight landscape end

0x002A0F2A,   //AFC_Default60Hz     
0x0F120000,   //00:50Hz 01:60Hz   

              //Scene_Duskdawn Candle_LightSunset
0x002A04E6,
0x0F12077F,
              //Scene_Duskdawn Candle_LightSunset end

              //Beach_Snow
0x002A1484,
0x0F12003C,
              //Beach_Snow End

              //NightShot
0x002A06B8,
0x0F12452C,
0x0F120005,

0x002A0608,
0x0F120001,
0x0F120001,

0x002A058C,
0x0F123520,
0x0F120000,
0x0F12C350,
0x0F120000,
0x0F123520,
0x0F120000,
0x0F12C350,
0x0F120000,
0x0F120470,
0x0F120C00,
0x0F120100,
0x0F121000,

0x002A02C2, 
0x0F12029A,
0x0F12014A,

0x002A0A1E,
0x0F120340,   //AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset
              //Night End

              //Scene portrait landscape Text default
0x002A0A28,   //Sharpness_Default
0x0F126024,
0x002A0ADE,
0x0F126024,
0x002A0B94,
0x0F126024,
0x002A0C4A,
0x0F126024,
0x002A0D00,
0x0F126024,
              //Scene portrait Text default end

0x002A0234,   //Saturation_Default
0x0F120000,
              //Scene landscape party_indoor Fall_Color default end

              //Fireworks
0x002A03B4,
0x0F120535,
0x0F12029A,

              //Sports mode
0x002A0638, 
0x0F120001, 
0x0F120000,   //lt_ExpGain_ExpCurveGainMaxStr_0__ulExpOut_0_
0x0F120A3C, 
0x0F120000, 
0x0F120D05, 
0x0F120000, 
0x0F123408, 
0x0F120000, 
0x0F123408, 
0x0F120000, 
0x0F126810, 
0x0F120000, 
0x0F128214, 
0x0F120000, 
0x0F12C350,
0x0F120000,
0x0F12C350,
0x0F120000,
0x0F12C350,
0x0F120000,

              //Party_Indoor Beach_Snow
0x002A0938,
0x0F120000,

0x002A04D0,
0x0F120000,
0x0F120000,
0x0F120001,

0x002A06C2,                          
0x0F120200,   //lt_bUseSecISODgain 
              //Party_Indoor Beach_Snow emd
              //Sports mode end


0x002A023C,   //Effect_Normal
0x0F120000,

0x002A0232,   //Contrast_Default
0x0F120000,

0x002A1BEA,
0x0F120001,   //Auto Contrast Off

0x002A0266,
0x0F120000,
0x002A026A,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0268,
0x0F120001,
0x002A0270,
0x0F120001,
0x002A023E,
0x0F120001,
0x0F120001,

0x002A1648,
0x0F129002,   // 2nd search on when 2nd search lens oppsite direction moving

0x002A15E8,
0x0F120015,   //af_pos_usTableLastInd
0x0F120032,
0x0F120038,
0x0F12003E,
0x0F120044,
0x0F12004A,
0x0F120050,
0x0F120056,
0x0F12005C,
0x0F120062,
0x0F120068,
0x0F12006E,
0x0F120074,
0x0F12007A,
0x0F120080,
0x0F120086,
0x0F12008C,
0x0F120092,
0x0F120098,
0x0F12009E,
0x0F1200A4,
0x0F1200AA,
0x0F1200B0,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_NIGHT
//==========================================================
GLOBAL const U32 reg_main_scene_night[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A06B8,
0x0F12FFFF,
0x0F1200FF,

0x002A0608,
0x0F120000,
0x0F120000,

0x002A058C,
0x0F12F424,
0x0F120001,
0x0F12D090,
0x0F120007,
0x0F12F424,
0x0F120001,
0x0F12D090,
0x0F120007,
0x0F120100,
0x0F120800,
0x0F120100,
0x0F122000,

0x002A03B4,
0x0F121388,
0x0F121388,
0x002A02C2,
0x0F1209C4,
0x0F12014A,
0x002A0266,
0x0F120000,
0x002A026A,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0268,
0x0F120001,
0x002A0270,
0x0F120001,
0x002A023E,
0x0F120001,
0x0F120001,

0x002A0A1E,
0x0F121580,

0x002A1648,   //1// 1st scan only
0x0F129000,

0x002A15E8,
0x0F120006,	//#af_pos_usTableLastInd//
0x0F120036,
0x0F12003A,
0x0F120040,
0x0F120048,
0x0F120050,
0x0F120058,
0x0F120060,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_LANDSCAPE
//==========================================================
GLOBAL const U32 reg_main_scene_landscape[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A1492,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x002A0A28,
0x0F12E082,
0x002A0ADE,
0x0F12E082,
0x002A0B94,
0x0F12E082,
0x002A0C4A,
0x0F12E082,
0x002A0D00,
0x0F12E082,
0x002A0234,
0x0F120030,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SUNSET
//==========================================================
GLOBAL const U32 reg_main_scene_sunset[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
             // 0x002A04E6 S/W Program
             // 0x0F120777
0x002A04BA,
0x0F1205E0,
0x0F120001,
0x0F120400,
0x0F120001,
0x0F120530,
0x0F120001,
0x0F120001,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_PORTRAIT
//==========================================================
GLOBAL const U32 reg_main_scene_portrait[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0A28,
0x0F124020,
0x002A0ADE,
0x0F124020,
0x002A0B94,
0x0F124020,
0x002A0C4A,
0x0F124020,
0x002A0D00,
0x0F124020,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SUNRISE
//==========================================================
GLOBAL const U32 reg_main_scene_sunrise[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
             // 0x002A04E6 S/W Program
             // 0x0F120777
0x002A04BA,
0x0F120505,
0x0F120001,
0x0F120400,
0x0F120001,
0x0F120875,
0x0F120001,
0x0F120001,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_INDOOR // == PARTY
//==========================================================
GLOBAL const U32 reg_main_scene_indoor[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0938,
0x0F120001, //afit_bUseNB_Afit

             // 0x002A04E6 S/W Program
             // 0x0F12065F
0x002A04D6,
0x0F120000, //REG_SF_USER_FlickerQuant       
0x0F120001, //REG_SF_USER_FlickerQuantChanged

0x002A04D0,
0x0F120001, //REG_SF_USER_IsoType    
0x0F120340, //REG_SF_USER_IsoVal     
0x0F120001, //REG_SF_USER_IsoChanged 
0x002A06C2,                          
0x0F120100, //lt_bUseSecISODgain  

0x002A0234,
0x0F120030,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_PARTY // == INDOOR
//==========================================================
GLOBAL const U32 reg_main_scene_party[] 
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0938,
0x0F120001, //afit_bUseNB_Afit

             // 0x002A04E6 S/W Program
             // 0x0F12065F
0x002A04D6,
0x0F120000, //REG_SF_USER_FlickerQuant       
0x0F120001, //REG_SF_USER_FlickerQuantChanged

0x002A04D0,
0x0F120001, //REG_SF_USER_IsoType    
0x0F120340, //REG_SF_USER_IsoVal     
0x0F120001, //REG_SF_USER_IsoChanged 
0x002A06C2,                          
0x0F120100, //lt_bUseSecISODgain  

0x002A0234,
0x0F120030,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SPORTS
//==========================================================
GLOBAL const U32 reg_main_scene_sports[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0638,
0x0F120001,
0x0F120000,   //lt_ExpGain_ExpCurveGainMaxStr_0__ulExpOut_0_
0x0F120A3C,
0x0F120000,
0x0F120D05,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F123408,
0x0F120000,
0x0F123408,
0x0F120000,

              //ISO x2
0x002A0938,
0x0F120001,   //NB mode

0x002A04D0,
0x0F120003,
0x0F120200,
0x0F120001,
              //ISO x2

0x002A0266,
0x0F120000,
0x002A026A,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0268,
0x0F120001,
0x002A0270,
0x0F120001,
0x002A023E,
0x0F120001,
0x0F120001,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_BEACH
//==========================================================
GLOBAL const U32 reg_main_scene_beach[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A1484,
0x0F120045,   //TVAR_ae_BrAve

0x002A0938,
0x0F120001, //afit_bUseNB_Afit

             // 0x002A04E6 S/W Program
             // 0x0F12065F
0x002A04D6,
0x0F120000, //REG_SF_USER_FlickerQuant       
0x0F120001, //REG_SF_USER_FlickerQuantChanged

0x002A04D0,
0x0F120001, //REG_SF_USER_IsoType    
0x0F1200D0, //REG_SF_USER_IsoVal     
0x0F120001, //REG_SF_USER_IsoChanged 
0x002A06C2,                          
0x0F120100, //lt_bUseSecISODgain  

0x002A0234,
0x0F120030,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SNOW
//==========================================================
GLOBAL const U32 reg_main_scene_snow[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A1484,
0x0F120045,   //TVAR_ae_BrAve

0x002A0938,
0x0F120001, //afit_bUseNB_Afit

             // 0x002A04E6 S/W Program
             // 0x0F12065F
0x002A04D6,
0x0F120000, //REG_SF_USER_FlickerQuant       
0x0F120001, //REG_SF_USER_FlickerQuantChanged

0x002A04D0,
0x0F120001, //REG_SF_USER_IsoType    
0x0F1200D0, //REG_SF_USER_IsoVal     
0x0F120001, //REG_SF_USER_IsoChanged 
0x002A06C2,                          
0x0F120100, //lt_bUseSecISODgain  

0x002A0234,
0x0F120030,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_FALLCOLOR
//==========================================================
GLOBAL const U32 reg_main_scene_fallcolor[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0234,
0x0F120060,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_FIREWORKS
//==========================================================
GLOBAL const U32 reg_main_scene_fireworks[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0638,
0x0F120001,
0x0F120000,
0x002A063C,
0x0F121478,
0x0F120000,
0x002A0640,
0x0F121A0A,
0x0F120000,
0x002A0644,
0x0F126810,
0x0F120000,
0x002A0648,
0x0F126810,
0x0F120000,
0x002A064C,
0x0F12D020,
0x0F120000,
0x002A0650,
0x0F120428,
0x0F120001,
0x002A0654,
0x0F121A80,
0x0F120006,
0x002A0658,
0x0F121A80,
0x0F120006,
0x002A065C,
0x0F121A80,
0x0F120006,

0x002A03B4,
0x0F122710,
0x0F122710,

0x002A0266,
0x0F120000,
0x002A026A,
0x0F120001,
0x002A024E,
0x0F120001,
0x002A0268,
0x0F120001,
0x002A0270,
0x0F120001,
0x002A023E,
0x0F120001,
0x0F120001,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_CANDLELIGHT
//==========================================================
GLOBAL const U32 reg_main_scene_candlelight[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
             // 0x002A04E6 S/W Program
             // 0x0F120777
0x002A04BA,
0x0F1205E0,
0x0F120001,
0x0F120400,
0x0F120001,
0x0F120530,
0x0F120001,
0x0F120001,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_AGAINSTLIGHT (BACKLight??)
//==========================================================
GLOBAL const U32 reg_main_scene_againstlight[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A1492,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120101,
0x0F120101,
0x0F120000,
0x0F120000,
0x0F12010F,
0x0F120F01,
0x0F120000,
0x0F120000,
0x0F12010F,
0x0F120F01,
0x0F120000,
0x0F120000,
0x0F120101,
0x0F120101,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_TEXT
//==========================================================
GLOBAL const U32 reg_main_scene_text[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0A28,
0x0F12A060,
0x002A0ADE,
0x0F12A060,
0x002A0B94,
0x0F12A060,
0x002A0C4A,
0x0F12A060,
0x002A0D00,
0x0F12A060,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_M2
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_m2[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0232,
0x0F12FFC0,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_M1
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_m1[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0232,
0x0F12FFE0,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_DEFAULT
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_default[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0232,
0x0F120000,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_P1
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_p1[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0232,
0x0F120020,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_P2
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_p2[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0232,
0x0F120040,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SHARPNESS_M2
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_m2[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0A28,
0x0F122010,
0x002A0ADE,
0x0F122010,
0x002A0B94,
0x0F122010,
0x002A0C4A,
0x0F122010,
0x002A0D00,
0x0F122010,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SHARPNESS_M1
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_m1[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0A28,
0x0F124020,
0x002A0ADE,
0x0F124020,
0x002A0B94,
0x0F124020,
0x002A0C4A,
0x0F124020,
0x002A0D00,
0x0F124020,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ADJUST_SHARPNESS_DEFAULT
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_default[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0A28,
0x0F126024,
0x002A0ADE,
0x0F126024,
0x002A0B94,
0x0F126024,
0x002A0C4A,
0x0F126024,
0x002A0D00,
0x0F126024,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ADJUST_SHARPNESS_P1
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_p1[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0A28,
0x0F128040,
0x002A0ADE,
0x0F128040,
0x002A0B94,
0x0F128040,
0x002A0C4A,
0x0F128040,
0x002A0D00,
0x0F128040,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ADJUST_SHARPNESS_P2
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_p2[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0A28,
0x0F12A060,
0x002A0ADE,
0x0F12A060,
0x002A0B94,
0x0F12A060,
0x002A0C4A,
0x0F12A060,
0x002A0D00,
0x0F12A060,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_M2
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_m2[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0234,
0x0F12FF81,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_M1
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_m1[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0234,
0x0F12FFC0,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_DEFAULT
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_default[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0234,
0x0F120000,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_P1
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_p1[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0234,
0x0F120040,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_P2
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_p2[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0234,
0x0F12007F,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_JPEG_output_5M
//==========================================================
GLOBAL const U32 reg_main_jpeg_5m[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120A20,
0x0F120798,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_5M_2
//==========================================================
GLOBAL const U32 reg_main_jpeg_5m_2[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120A00,
0x0F120780,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_4M
//==========================================================
GLOBAL const U32 reg_main_jpeg_w4m[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120A00,
0x0F120600,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_3M
//==========================================================
GLOBAL const U32 reg_main_jpeg_3m[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120800,
0x0F120600,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_2M
//==========================================================
GLOBAL const U32 reg_main_jpeg_2m[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120640,
0x0F1204B0,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_w1_5M
//==========================================================
GLOBAL const U32 reg_main_jpeg_w1_5m[]
#if defined(_CAMACQ_API_C_)
={

0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120640,
0x0F1203C0,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_1M
//==========================================================
GLOBAL const U32 reg_main_jpeg_1m[]
#if defined(_CAMACQ_API_C_)
={

0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120500,
0x0F1203C0,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_VGA
//==========================================================
GLOBAL const U32 reg_main_jpeg_vga[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120280,
0x0F1201E0,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_WQVGA
//==========================================================
GLOBAL const U32 reg_main_jpeg_wqvga[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120190,
0x0F1200F0,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_QVGA
//==========================================================
GLOBAL const U32 reg_main_jpeg_qvga[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A0398,

0x0F120140,
0x0F1200F0,
           
0x002A0270,
0x0F120001,

0xFFFF01F4,

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qcif
//==========================================================
GLOBAL const U32 reg_main_qcif[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qvga
//==========================================================
GLOBAL const U32 reg_main_qvga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_cif
//==========================================================
GLOBAL const U32 reg_main_cif[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_vga
//==========================================================
GLOBAL const U32 reg_main_vga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1080P[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_720P[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_not[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flicker_disabled[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flicker_50hz[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flicker_60hz[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flicker_auto[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_jpeg_quality_superfine[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0478,
0x0F12005F,
0x0F12005F,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_jpeg_quality_fine[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0478,
0x0F120059,
0x0F120059,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_jpeg_quality_normal[]
#if defined(_CAMACQ_API_C_)
={
0x00287000,
0x002A0478,
0x0F120052,
0x0F120052,
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_ae_lock[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_ae_unlock[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_awb_lock[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_awb_unlock[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_pre_flash_start[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_pre_flash_end[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_main_flash_start[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_main_flash_end[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flash_ae_set[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flash_ae_clear[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

#undef GLOBAL

#endif /* _CAMACQ_S5K4ECGX_MIPI_H_ */
