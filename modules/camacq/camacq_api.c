  /*
 *
 * sensor api file
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

#if !defined(_CAMACQ_API_C_)
#define _CAMACQ_API_C_

/* Include */
#include "camacq_api.h"


S32 g_iIsx012Addr = 0;

//////////////////////////////////////////////////////////////////////////////////
// 
// Init Global variable
//

//////////////////////////////////////////////////////////
//
//  g_stCamacqFmts
// 
struct stCamacqFmt_t g_stCamacqFmts[] =
{
    // 0
    {
        .pucDesc			        = "YUYV422 planar",
        .uiPixelFormat	            = V4L2_PIX_FMT_YUV422P,
        .iBPP			            = 16,
        .pvRegs[CAMACQ_SENSOR_MAIN]	= (const void*)CAMACQ_MAIN_REG_FMT_YUV422,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]	= (const void*)CAMACQ_SUB_REG_FMT_YUV422,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 1
    {
        .pucDesc                    = "YUYV 4:2:0",
        .uiPixelFormat              = V4L2_PIX_FMT_YUV420,
        .iBPP                       = 12,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_FMT_YUV422,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_FMT_YUV422,
#endif /* CAMACQ_SENSOR_MAX==2 */        
    },

    // 2
    {
        .pucDesc                    = "JFIF JPEG",
        .uiPixelFormat              = V4L2_PIX_FMT_JPEG,
        .iBPP                       = 16,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_FMT_JPG,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_FMT_JPG,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 3
    {
        .pucDesc                    = "FULL_YUV422",
        .uiPixelFormat              = V4L2_PIX_FMT_UYVY,
        .iBPP			            = 16,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_FMT_YUV422,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_FMT_YUV422,
#endif /* CAMACQ_SENSOR_MAX==2 */
    }
};
#define N_CAMACQ_FMTS (ARRAY_SIZE(g_stCamacqFmts))



//////////////////////////////////////////////////////////
//
//  g_stCamacqWinSizes
//
struct stCamacqSize_t g_stCamacqWinSizes[] = {

    // 0
    /* QCIF */
    {
        .uiWidth		            = 176,
        .uiHeight		            = 144,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_QVGA,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_QVGA,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },
    
    // 1
    /* QVGA */
    {
        .uiWidth		            = 320,
        .uiHeight		            = 240,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_QVGA,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_QVGA,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 2
    /* VGA */
    {
        .uiWidth		            = 640,
        .uiHeight 	                = 480,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_VGA,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_VGA,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 3
    /* 720x480*/
    {
        .uiWidth		            = 720,
        .uiHeight 	                = 480,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_720_480,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_720_480,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 4
    /* 800x480*/
    {
        .uiWidth		            = 800,
        .uiHeight 	                = 480,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_800_480,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_800_480,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 5
    /* 1280x720*/
    {
        .uiWidth		            = 1280,
        .uiHeight 	                = 720, 
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_720P,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_720P,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 6
    /* 1280x1080*/
    {
        .uiWidth		            = 1280,
        .uiHeight 	                = 1080, 
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_1080P,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)CAMACQ_SUB_REG_1080P,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },


};
#define N_CAMACQ_WIN_SIZES (ARRAY_SIZE(g_stCamacqWinSizes))



//////////////////////////////////////////////////////////
//
//  g_stCamacqJpegSizes
//
struct stCamacqSize_t g_stCamacqJpegSizes[] = {
    // 0
    /* QVGA 320x240 */
    {
        .uiWidth		            = 320,
        .uiHeight		            = 240,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_QVGA,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 1
    /* WQVGA 400x240 */
    {
        .uiWidth		            = 400,
        .uiHeight 	                = 240,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_WQVGA,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 2
    /* WQVGA 400x240 */
    {
        .uiWidth		            = 640,
        .uiHeight 	                = 480,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_VGA,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 3
    /* SXGA 1280x960 */
    {
        .uiWidth		            = 1280,
        .uiHeight		            = 960,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_1M,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 4
    /* w1.5M */
    {
        .uiWidth		            = 1600,
        .uiHeight		            = 960,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_W1_5M,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 5
    /* UXGA 1600x1200*/
    {
        .uiWidth		            = 1600,
        .uiHeight		            = 1200,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_2M,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },
    
    // 6
    /* QXGA */
    {
        .uiWidth		            = 2048,
        .uiHeight		            = 1536,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_3M,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 6
    /* W4M */
    {
        .uiWidth		            = 2560,
        .uiHeight		            = 1536,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_W4M,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 7
    /* 5M 2560x1920*/
    {
        .uiWidth		            = 2560,
        .uiHeight 	                = 1920,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_5M,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },

    // 8
    /*5M 2592x1944*/
    {
        .uiWidth		            = 2592,
        .uiHeight 	                = 1944,
        .pvRegs[CAMACQ_SENSOR_MAIN] = (const void*)CAMACQ_MAIN_REG_JPEG_5M_2,
#if (CAMACQ_SENSOR_MAX==2)
        .pvRegs[CAMACQ_SENSOR_SUB]  = (const void*)NULL,
#endif /* CAMACQ_SENSOR_MAX==2 */
    },
};
#define N_CAMACQ_JPEG_SIZES (ARRAY_SIZE(g_stCamacqJpegSizes))

struct stCamacqControl_t g_stCamacqControls[] = {
    // 0
    {
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_FOCUS_AUTO,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Autofocus",
			.minimum = V4L2_ATFCS_CTRL_OFF,
			.maximum = V4L2_ATFSC_CTRL_MAX, 
			.step = 1,
			.default_value = CAMACQ_EXT_DEF_AUTO_FCS,
		},
		.iCurVal = CAMACQ_EXT_DEF_AUTO_FCS,
	},
	// 1
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_AUTO_WHITE_BALANCE,
			.type = V4L2_CTRL_TYPE_BOOLEAN,
			.name = "AutoWhiteBalance",
			.minimum = 0,
			.maximum = 1,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 2
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_EXPOSURE_AUTO,
			.type = V4L2_CTRL_TYPE_BOOLEAN,
			.name = "AutoExposure",
			.minimum = 0,
			.maximum = 1,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 3
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_HFLIP,
			.type = V4L2_CTRL_TYPE_BOOLEAN,
			.name = "Mirror Image",
			.minimum = 0,
			.maximum = 1,
			.step = 0,
			.default_value = CAMACQ_EXT_DEF_HFLIP,
		},
		.iCurVal = CAMACQ_EXT_DEF_HFLIP,
	},
	// 4
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_VFLIP,
			.type = V4L2_CTRL_TYPE_BOOLEAN,
			.name = "Vertical Flip",
			.minimum = 0,
			.maximum = 1,
			.step = 0,
			.default_value = CAMACQ_EXT_DEF_VFLIP,
		},
		.iCurVal = CAMACQ_EXT_DEF_VFLIP,
	},
	// 5
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_MET_EXP,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Metering exposure",
			.minimum = V4L2_CTRL_MET_EXP_MATRIX,
			.maximum = V4L2_CTRL_MET_EXP_SPOT,
			.step = 0,
			.default_value = CAMACQ_EXT_DEF_MET_EXP,
		},
		.iCurVal = CAMACQ_EXT_DEF_MET_EXP,
	},
	// 6
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_SENSITIVITY,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Sensitivity",
			.minimum = V4L2_CTRL_ISO_AUTO,
			.maximum = V4L2_CTRL_ISO_HJR,
			.step = 0,
			.default_value = CAMACQ_EXT_DEF_SENS,
		},
		.iCurVal = CAMACQ_EXT_DEF_SENS,
	},
	// 7
    {
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_BRIGHTNESS,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Brightness",
			.minimum = -50,
			.maximum = 50,
			.step = 5,
			.default_value = CAMACQ_EXT_DEF_BRIGHT,
		},
		.iCurVal = CAMACQ_EXT_DEF_BRIGHT,
	},
	// 8
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_CONTRAST,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Contrast",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 9
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_SATURATION,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Saturaion",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 10
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_SCENE,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Scene",
			.minimum = V4L2_CTRL_SCENE_AUTO,
			.maximum = V4L2_CTRL_SCENE_AQUA,
			.step = 0,
			.default_value = CAMACQ_EXT_DEF_SCENE,
		},
		.iCurVal = CAMACQ_EXT_DEF_SCENE,
	},
	// 11
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_POWER_LINE_FREQUENCY,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Antibanding",
			.minimum = V4L2_CID_POWER_LINE_FREQUENCY_DISABLED,
			.maximum = V4L2_CID_POWER_LINE_FREQUENCY_AUTO,
			.step = 0,
			.default_value = V4L2_CID_POWER_LINE_FREQUENCY_DISABLED,
		},
		.iCurVal = V4L2_CID_POWER_LINE_FREQUENCY_DISABLED,
	},
	// 12
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_SHARPNESS,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Sharpness",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 13
	{
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_ATFCS_MODE,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "AutofocusMode",
			.minimum = V4L2_ATFCS_MODE_AUTO,
			.maximum = V4L2_ATFCS_MODE_RET_MACRO,
			.step = 1,
			.default_value = V4L2_ATFCS_MODE_AUTO,
		},
		.iCurVal = V4L2_ATFCS_MODE_AUTO,
	},
	// 14
    {
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_EXP_COMPENSATION,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "ExposureCompensation",
			.minimum = -50,
			.maximum = 50,
			.step = 5,
			.default_value = CAMACQ_EXT_DEF_EXP_COMPENSATION,
		},
		.iCurVal = CAMACQ_EXT_DEF_EXP_COMPENSATION,
	},
	// 15
    {
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_PRIVATE_CTRL_MODE,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Private camera control",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 16
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_CHECK_LUX,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Check Lux",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 17
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_INIT_CAMCORDER,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "init camcorder",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 18
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_SET_CAMCORDER_SIZE,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "init camcorder",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 19   
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_FPS,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "fps", 
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 20
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_INIT_VT,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "init vt",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 21
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_SET_VT_SIZE,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "vt size",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 22
    {
		.stV4l2QueryCtrl = {
			.id = V4L2_CID_ZOOM,
			.type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Zoom",
			.minimum = -50,
			.maximum = 50,
			.step = 5,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 23  //denis_exif
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_CHECK_EXPOSURETIME,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Check Exposure Time",
			.minimum = -50,
			.maximum = 1000,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},	
	// 24  //denis_exif
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_CHECK_ISO,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Check ISO",
			.minimum = 50,
			.maximum = 1600,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},		
    // 25  //denis_esd
    {
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_CHECK_ESD,
            .type = V4L2_CTRL_TYPE_INTEGER,
            .name = "Check ESD",
            .minimum = 50,
            .maximum = 1600,
            .step = 1,
            .default_value = 0,
        },
        .iCurVal = 0,
    },
    // 26
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_SET_PREVIEW_SIZE,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "set preview",
			.minimum = -50,
			.maximum = 50,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},
	// 27  //denis_ae
	{
        .stV4l2QueryCtrl = { 
            .id = V4L2_CID_CHECK_AESTABILITY,
            .type = V4L2_CTRL_TYPE_INTEGER,
			.name = "Check Exposure Time",
			.minimum = 0,
			.maximum = 2,
			.step = 1,
			.default_value = 0,
		},
		.iCurVal = 0,
	},	
	
};
#define N_CAMACQ_CONTROLS (ARRAY_SIZE(g_stCamacqControls))

//////////////////////////////////////////////////////////////////////////////////
// 
// Functions
// 
void CreateCamacqSensorManager( struct stCamacqSensorManager_t **ppstSensorManager )
{
    int i;
    struct stCamacqSensorManager_t* pstSensorManager = NULL;
    CamacqTraceIN();

    *ppstSensorManager = CamacqMalloc( sizeof(struct stCamacqSensorManager_t) );
    
    pstSensorManager = *ppstSensorManager;
    
    /* Cam block */
    pstSensorManager->m_stCamBlock.CamPowerSet = CamPowerSet;

    /* Member Function */
    pstSensorManager->SensorSwitch = SensorSwitch;
    pstSensorManager->SensorPowerOn = SensorPowerOn;
    pstSensorManager->SensorPowerOff = SensorPowerOff;
    pstSensorManager->SensorReset = SensorReset;

    pstSensorManager->SetSensor = SetSensor;
    pstSensorManager->GetSensor = GetSensor;

    /* Alloc _stCamacqSensor */
    pstSensorManager->m_pstSensors = CamacqMalloc( sizeof( struct stCamacqSensor_t ) * CAMACQ_SENSOR_MAX );
    for( i = 0; i < CAMACQ_SENSOR_MAX; i++ )
    {
        CreateCamacqSensor( &(pstSensorManager->m_pstSensors[i]), i );
    }

    /* select default Sensor */
    pstSensorManager->m_uiSelectedSensor = CAMACQ_SENSOR_MAIN;
   
    CamacqTraceOUT();
}

void DeleteCamacqSensorManager( struct stCamacqSensorManager_t* pstSensorManager )
{

}

void CreateCamacqSensor( struct stCamacqSensor_t* pstSensor, int uiResType )
{
    CamacqTraceIN();

    /* init memeber variable */
    pstSensor->m_uiResType = uiResType;
    
    if( uiResType == CAMACQ_SENSOR_MAIN )
    {
        strcpy( pstSensor->m_szName, CAMACQ_MAIN_NAME );
        pstSensor->m_iYuvOrder = CAMACQ_MAIN_YUVORDER;
        pstSensor->m_iVsyncPol = CAMACQ_MAIN_V_SYNCPOL;
        pstSensor->m_iHsyncPol = CAMACQ_MAIN_H_SYNCPOL;
        pstSensor->m_iSampleEdge = CAMACQ_MAIN_SAMPLE_EDGE;
        pstSensor->m_bFullrange = CAMACQ_MAIN_FULL_RANGE;
        pstSensor->m_bCanAF = CAMACQ_MAIN_AF;
    }
#if (CAMACQ_SENSOR_MAX==2)
    else if( uiResType == CAMACQ_SENSOR_SUB )
    {
        strcpy( pstSensor->m_szName, CAMACQ_SUB_NAME );
        pstSensor->m_iYuvOrder = CAMACQ_SUB_YUVORDER;
        pstSensor->m_iVsyncPol = CAMACQ_SUB_V_SYNCPOL;
        pstSensor->m_iHsyncPol = CAMACQ_SUB_H_SYNCPOL;
        pstSensor->m_iSampleEdge = CAMACQ_SUB_SAMPLE_EDGE;
        pstSensor->m_bFullrange = CAMACQ_SUB_FULL_RANGE;
        pstSensor->m_bCanAF = CAMACQ_SUB_AF;
    }
#endif /* CAMACQ_SENSOR_MAX==2 */
    else
    {
        CamacqTraceErr( "Unsupported ResType : %d", uiResType );
    }

    pstSensor->m_pI2cClient = NULL;
    pstSensor->m_bIsPowerOn = false;

    /* init info  */
    InitCamacqSensorInfo( &(pstSensor->m_pstCamacqInfo) );

    /* init settings  */
    InitCamacqSensorSettings( &(pstSensor->m_pstCamacqSettings) );

    /* init controls  */
    InitCamacqSensorControls( &(pstSensor->m_pstCamacqCtrls), g_stCamacqControls );

    /* init APIs */
    InitCamacqAPIs( &(pstSensor->m_pstAPIs) );

    /* init Ext APIs */
    InitCamacqExtAPIs( &(pstSensor->m_pstExtAPIs), pstSensor );
   
    CamacqTraceOUT();
}

void DeleteCamacqSensor( struct stCamacqSensor_t* pstSensor )
{
    CamacqTraceIN();
    CamacqTraceOUT();
}

void InitCamacqSensorInfo( struct stCamacqInfo_t **ppstCamacqInfo )
{
    CamacqTraceIN();

    *ppstCamacqInfo = CamacqMalloc( sizeof(struct stCamacqInfo_t) );
    memset( *ppstCamacqInfo, 0, sizeof(struct stCamacqInfo_t) );

    (*ppstCamacqInfo)->eState = CAMACQ_STATE_UNINITIALISED;
    
    CamacqTraceOUT();
}

void InitCamacqSensorSettings( struct stCamacqSettings_t **ppstCamacqSettings )
{
    CamacqTraceIN();

    *ppstCamacqSettings = CamacqMalloc( sizeof(struct stCamacqSettings_t) );
    memset( *ppstCamacqSettings, 0, sizeof(struct stCamacqSettings_t) );

    (*ppstCamacqSettings)->stV4l2CurFlashMode = V4L2_FLASH_DISABLED;
    strncpy((*ppstCamacqSettings)->stV4l2CurEffect.efx_name, "NO_EFX", MAX_EFX_NAME_LENGTH );
    strncpy((*ppstCamacqSettings)->stV4l2CurWbMode.wb_mode_name, "AUTO", MAX_WB_NAME_LENGTH);

    (*ppstCamacqSettings)->stV4l2CurJpegcomp.quality = 100;
    (*ppstCamacqSettings)->stV4l2CurAutoFocusMode = V4L2_ATFCS_MODE_AUTO;

    
    CamacqTraceOUT();
}

void InitCamacqSensorControls( struct stCamacqControl_t **ppstCamacqCtrls, struct stCamacqControl_t *pstDefaultCtrls )
{
    CamacqTraceIN();

    *ppstCamacqCtrls = CamacqMalloc( sizeof(struct stCamacqControl_t) * N_CAMACQ_CONTROLS );
    memcpy( *ppstCamacqCtrls, pstDefaultCtrls, sizeof(struct stCamacqControl_t) * N_CAMACQ_CONTROLS );

    CamacqTraceOUT();
}

void InitCamacqAPIs( struct stCamacqAPIs_t **ppstAPIs )
{
    struct stCamacqAPIs_t *pstAPIs = NULL;
    CamacqTraceIN();
    
    *ppstAPIs = CamacqMalloc( sizeof(struct stCamacqAPIs_t) );
    memset( *ppstAPIs, 0, sizeof(struct stCamacqAPIs_t) );

    pstAPIs = *ppstAPIs;

    /* APIs */
    pstAPIs->Detect = CamacqAPIDetect;
    pstAPIs->Init = CamacqAPIInit;
    pstAPIs->CleanUp = CamacqAPICleanUp;
    pstAPIs->Open = CamacqAPIOpen;
    pstAPIs->Close = CamacqAPIClose;

    pstAPIs->IntInit = CamacqAPIIntInit;
    pstAPIs->EnumPixFmt = CamacqAPIEnumPixFmt;
    pstAPIs->EnumFrameSizes= CamacqAPIEnumFrameSizes;
    pstAPIs->TryFmt = CamacqAPITryFmt;
    pstAPIs->SetFmt = CamacqAPISetFmt;

    pstAPIs->StopSensor = CamacqAPIStopSensor;
    pstAPIs->StartSensor = CamacqAPIStartSensor;

    pstAPIs->QueryControl = CamacqAPIQueryControl;
    pstAPIs->SetControl = CamacqAPISetControl;
    pstAPIs->GetControl = CamacqAPIGetControl;

    pstAPIs->CropCap = CamacqAPICropCap;
    pstAPIs->SetCrop = CamacqAPISetCrop;
    pstAPIs->GetCrop = CamacqAPIGetCrop;

    pstAPIs->SetStrobe = CamacqAPISetStrobe;
    pstAPIs->GetStrobe = CamacqAPIGetStrobe;

    pstAPIs->QueryMenu = CamacqAPIQueryMenu;

    pstAPIs->SetJpegQuality = CamacqAPISetJpegQuality;
    pstAPIs->GetJpegQuality = CamacqAPIGetJpegQuality;
    
    pstAPIs->SetJpegHeader = CamacqAPISetJpegHeader;
    pstAPIs->SetJpegFooter = CamacqAPISetJpegFooter;

    pstAPIs->GetCamCap = CamacqAPIGetCamCap;
    pstAPIs->GetActiveCam = CamacqAPIGetActiveCam;
    pstAPIs->SetActiveCam = CamacqAPISetActiveCam;

    pstAPIs->SetEfx = CamacqAPISetEfx;
    pstAPIs->GetEfx = CamacqAPIGetEfx;
    pstAPIs->QueryEfx = CamacqAPIQueryEfx;
    
    pstAPIs->SetWB = CamacqAPISetWbMode;
    pstAPIs->GetWB = CamacqAPIGetWbMode;
    pstAPIs->QueryWB = CamacqAPIQueryWbMode;
    
    pstAPIs->GetParm = CamacqAPIGetParm;
    pstAPIs->SetParm = CamacqAPISetParm;
    
    pstAPIs->SetInput = CamacqAPISetInput;
    
    pstAPIs->StreamOn = CamacqAPIStreamOn;
    pstAPIs->StreamOff = CamacqAPIStreamOff;

    pstAPIs->SetFlash = CamacqAPISetFlash;
        
    CamacqTraceOUT();
}

void InitCamacqExtAPIs( struct stCamacqExtAPIs_t **ppstExtAPIs, struct stCamacqSensor_t *pstSensor )
{
    struct stCamacqExtAPIs_t *pstExtAPIs = NULL;
    CamacqTraceIN();

    *ppstExtAPIs = CamacqMalloc( sizeof(struct stCamacqExtAPIs_t) );
    memset( *ppstExtAPIs, 0, sizeof(struct stCamacqExtAPIs_t) );

    pstExtAPIs = *ppstExtAPIs;
    pstExtAPIs->m_pstSensor = pstSensor;

    if( pstSensor->m_uiResType == CAMACQ_SENSOR_MAIN )
    {
        pstExtAPIs->m_pstSensorRegs = &g_stCamacqMainSensorRegs;
        pstExtAPIs->PowerOn = PowerOn_MAIN;
        pstExtAPIs->PowerOff = PowerOff_MAIN;
        pstExtAPIs->Switch = Switch_MAIN;
        pstExtAPIs->Reset = Reset_MAIN;
        pstExtAPIs->Standby = Standby_MAIN;
        pstExtAPIs->Wakeup = Wakeup_MAIN;
    }
#if (CAMACQ_SENSOR_MAX==2)
    else if( pstSensor->m_uiResType == CAMACQ_SENSOR_SUB )
    {
        pstExtAPIs->m_pstSensorRegs = &g_stCamacqSubSensorRegs;
        pstExtAPIs->PowerOn = PowerOn_SUB;
        pstExtAPIs->PowerOff = PowerOff_SUB;
        pstExtAPIs->Switch = Switch_SUB;
        pstExtAPIs->Reset = Reset_SUB;
        pstExtAPIs->Standby = Standby_SUB;
        pstExtAPIs->Wakeup = Wakeup_SUB;
    }
#endif /* CAMACQ_SENSOR_MAX==2 */

    pstExtAPIs->Boot = CamacqExtBoot;
    pstExtAPIs->Hflip = CamacqExtHflip;
    pstExtAPIs->Vflip = CamacqExtVflip;
    pstExtAPIs->SetFlip = CamacqExtSetFlip;
    pstExtAPIs->Exposure = CamacqExtExposure;
    pstExtAPIs->Sensitivity = CamacqExtSensitivity;
    pstExtAPIs->Scene = CamacqExtScene;
    pstExtAPIs->Brightness = CamacqExtBrightness;
    pstExtAPIs->ExposureCompensation = CamacqExtExposureCompensation;
    pstExtAPIs->Zoom = CamacqExtZoom;
    pstExtAPIs->Contrast = CamacqExtContrast;
    pstExtAPIs->Saturation = CamacqExtSaturation;
    pstExtAPIs->Sharpness = CamacqExtSharpness;
    pstExtAPIs->Autofocus = CamacqExtAutofocus;
    pstExtAPIs->Whitebalance = CamacqExtWhitebalance;
    pstExtAPIs->AntiBanding = CamacqExtAntiBanding;
    pstExtAPIs->FlashControl = CamacqExtFlashControl;
    pstExtAPIs->AutofocusMode = CamacqExtAutofocusMode;
    pstExtAPIs->CameraPrivateControl = CamacqExtCameraPrivateControl;
    pstExtAPIs->InitCamcorder = CamacqExtInitCamcorder;
    pstExtAPIs->SetCamcorderSize = CamacqExtSetCamcorderSize;
    pstExtAPIs->InitVT = CamacqExtInitVT;
    pstExtAPIs->SetVTSize = CamacqExtSetVTSize;
    pstExtAPIs->SetPreviewSize = CamacqExtSetPreviewSize;
    pstExtAPIs->SetFps = CamacqExtSetFps;
 
    CamacqTraceOUT();
}

struct stCamacqControl_t* CamacqFindControl( struct stCamacqSensor_t *pstSensor, S32 iId ) 
{
    int i;
    _stCamacqControl* pstControls = pstSensor->m_pstCamacqCtrls;
    _stCamacqControl* pstRet = NULL;
    CamacqTraceIN();

    for( i = 0; i < N_CAMACQ_CONTROLS; i++ )
    {   
        if( pstControls[ i ].stV4l2QueryCtrl.id == iId )
        {      
            pstRet = pstControls + i;
            CamacqTraceDbg( " i = %d", i );
            break;
        }
    }

    CamacqTraceOUT();
    return pstRet;
}

S32 CamacqRestoreCurCtrls( struct stCamacqSensor_t *pstSensor )
{   
    S32 iRet = 0, iIdx;
    struct v4l2_control stV4l2Ctrl;
    _stCamacqControl* pstControls = pstSensor->m_pstCamacqCtrls;    
    CamacqTraceIN();

    for( iIdx = 0; iIdx < CAMACQ_EXT_NUM_CTRLS; iIdx++ )
    {
        stV4l2Ctrl.id = pstControls[iIdx].stV4l2QueryCtrl.id;
        stV4l2Ctrl.value = pstControls[iIdx].iCurVal;
        iRet = pstSensor->m_pstAPIs->SetControl( pstSensor, &stV4l2Ctrl);
        if(iRet < 0)
            break;
    }

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqSaveCurCtrls( struct stCamacqSensor_t *pstSensor )
{
    S32 iRet = 0, iIdx;
    struct v4l2_control stV4l2Ctrl;
    _stCamacqControl* pstControls = pstSensor->m_pstCamacqCtrls;    
    CamacqTraceIN();

    for(iIdx = 0; iIdx < CAMACQ_EXT_NUM_CTRLS; iIdx++)
    {
        stV4l2Ctrl.id = pstControls[iIdx].stV4l2QueryCtrl.id;
        iRet = pstSensor->m_pstAPIs->GetControl( pstSensor, &stV4l2Ctrl );
        if(iRet < 0)
            break;
    }

    CamacqTraceOUT();
    return iRet;
}

//////////////////////////////////////////////////////////////////////////////////
//
// -_-;;
//
S32 CamPowerSet( S32 iFlag )
{
    S32 iRet = 0;
    CamacqTraceIN();

    iRet = CAMACQ_CAM_POWER_SET( iFlag );

    CamacqTraceOUT();
    return iRet;
}

//////////////////////////////////////////////////////////////////////////////////
// 
// stCamacqSensorManager_t  member functions
// 
S32 SensorSwitch( struct stCamacqSensorManager_t* this, U32 uiSelectedSensor )
{
    S32 iRet = 0;
    CamacqTraceIN();

   
    CamacqTraceOUT();
    return iRet;
}

S32 SensorPowerOn( struct stCamacqSensorManager_t* this, U32 uiSelectedSensor )
{
    S32 iRet = 0;
    _stCamacqSensor* pstSensor = 0;
    _stCamacqExtAPIs* pstExtAPIs = 0;
    CamacqTraceIN();

    pstSensor = this->GetSensor( this, uiSelectedSensor );
    if( pstSensor != 0 )
    {

#if defined(__ISX012_SONY__)
        // change sony sensor slave id, temp code 
        if( (pstSensor->m_pI2cClient != NULL) && (!strcmp(pstSensor->m_pI2cClient->name, "isx012")) )
        {
            CamacqTraceDbg("====== change slave address XXXX to 0x%x", g_iIsx012Addr);
            pstSensor->m_pI2cClient->addr = g_iIsx012Addr;
        }
#endif
    
        pstExtAPIs = pstSensor->m_pstExtAPIs;
        if( pstExtAPIs != 0 )
        {
            // this->m_stCamBlock.CamPowerSet( CAMACQ_ON ); //Move in PowerOn()
            iRet = pstExtAPIs->PowerOn();
            if( iRet < 0 )
            {
                CamacqTraceErr(": iRet=%d", iRet);
            }

            pstSensor->m_bIsPowerOn = true;
        }
        else
        {
            CamacqTraceErr( " pstExtAPIs[%x], uiSelectedSensor[%d] ", (U32)pstExtAPIs, uiSelectedSensor );
            iRet = -1;
        }
    }
    else
    {
        CamacqTraceErr( " pstSensor[%x], uiSelectedSensor[%d] ", (U32)pstSensor, uiSelectedSensor );
        iRet = -1;
    }
    
    CamacqTraceOUT();
    return iRet;
}

S32 SensorPowerOff( struct stCamacqSensorManager_t* this, U32 uiSelectedSensor )
{
    S32 iRet = 0;
    _stCamacqSensor* pstSensor = 0;
    _stCamacqExtAPIs* pstExtAPIs = 0;
    CamacqTraceIN();

    pstSensor = this->GetSensor( this, uiSelectedSensor );
    if( pstSensor != 0 )
    {
        pstExtAPIs = pstSensor->m_pstExtAPIs;
        if( pstExtAPIs != 0 )
        {
            pstExtAPIs->PowerOff();
            // this->m_stCamBlock.CamPowerSet( CAMACQ_OFF );  //Move in PowerOFF()

            pstSensor->m_bIsPowerOn = false;
        }
        else
        {
            CamacqTraceErr( " pstExtAPIs[%x], uiSelectedSensor[%d] ", (U32)pstExtAPIs, uiSelectedSensor );
            iRet = -1;
        }
    }
    else
    {
        CamacqTraceErr( " pstSensor[%x], uiSelectedSensor[%d] ", (U32)pstSensor, uiSelectedSensor );
        iRet = -1;
    }

#if defined(__ISX006_SONY__) || defined(__ISX012_SONY__)
    // change sony sensor slave id, temp code 
    if( (pstSensor->m_pI2cClient != NULL) && 
        ( (!strcmp(pstSensor->m_pI2cClient->name, "isx006")) || (!strcmp(pstSensor->m_pI2cClient->name, "isx012")))  )
    {
        CamacqTraceDbg("====== change slave address XXXX to 0x%x", g_iIsx012Addr);
        pstSensor->m_pI2cClient->addr = g_iIsx012Addr;
    }
#endif
    
    CamacqTraceOUT();
    return iRet; 
}


S32 SensorReset( struct stCamacqSensorManager_t* this, U32 uiSelectedSensor )
{
    S32 iRet = 0;
    _stCamacqSensor* pstSensor = 0;
    _stCamacqExtAPIs* pstExtAPIs = 0;
    CamacqTraceIN();

    pstSensor = this->GetSensor( this, uiSelectedSensor );
    if( pstSensor != 0 )
    {
        pstExtAPIs = pstSensor->m_pstExtAPIs;
        if( pstExtAPIs != 0 )
        {
            pstExtAPIs->Reset();
        }
        else
        {
            CamacqTraceErr( " pstExtAPIs[%x], uiSelectedSensor[%d] ", (U32)pstExtAPIs, uiSelectedSensor );
            iRet = -1;
        }
    }
    else
    {
        CamacqTraceErr( " pstSensor[%x], uiSelectedSensor[%d] ", (U32)pstSensor, uiSelectedSensor );
        iRet = -1;
    }

    CamacqTraceOUT();
    return iRet;
}

struct stCamacqSensor_t* SetSensor( struct stCamacqSensorManager_t* this, U32 uiSelectedSensor )
{
    struct stCamacqSensor_t* pstRet = NULL;

    CamacqTraceDbg("uiSelectedSensor : %d", uiSelectedSensor );

    pstRet = this->GetSensor( this, uiSelectedSensor );

    if( pstRet !=  NULL )
    {
        this->m_uiSelectedSensor = uiSelectedSensor;
    }
    else // pstRet == NULL
    { 
        CamacqTraceErr(" ERR pstRet is NULL ");
    }
        
    return pstRet;
}    

struct stCamacqSensor_t* GetSensor( struct stCamacqSensorManager_t* this, U32 uiSelectedSensor )
{
    struct stCamacqSensor_t* pstRet = NULL;
 
    if( uiSelectedSensor == CAMACQ_SENSOR_MAIN )
    {
        pstRet = &(this->m_pstSensors[uiSelectedSensor]);
    }
#if (CAMACQ_SENSOR_MAX==2)
    else if( uiSelectedSensor == CAMACQ_SENSOR_SUB )
    {
        pstRet = &(this->m_pstSensors[uiSelectedSensor]);
    }
#endif /* (CAMACQ_SENSOR_MAX==2) */
    else
    {
        CamacqTraceErr("Not supported sensor id : %d", uiSelectedSensor);
    }
       
    return pstRet;
}

//////////////////////////////////////////////////////////////////////////////////
// 
// stCamacqSensor_t Member Functions (APIs)
//
S32 CamacqAPIDetect( struct stCamacqSensor_t* this )
{
    S32 iRet = 0;
	U32 uiResType = this->m_uiResType;
    CamacqTraceIN();

#if 1   /* Temp detect code for marvell */

	// 1. power-on
	g_pstCamacqSensorManager->SensorPowerOn( g_pstCamacqSensorManager, uiResType );
	mdelay(10);
	// 2. check i2c operation correctly (sensor defendency)
    if( !strcmp( this->m_szName, "isx006" ) )
    {   
        U16 usReadAddr = 0x0000;        // ROM VERSION
        U8 rgucReadData[2] = {0, };
		
        CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );
		CamacqTraceDbg( "iRet:%d, isx006 sensor rom version : %x%x", iRet, rgucReadData[1], rgucReadData[0] );
    }
    else if( !strcmp( this->m_szName, "isx012" ) )
    {   
        S32 iRetCheck = 0;
        U16 usReadAddr = 0x0000;        // ROM VERSION
        U8 rgucReadData[2] = {0, };

        this->m_pI2cClient->addr = 0x3C;		
        iRetCheck = CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );
        if( iRetCheck > 0 )
        {
            g_iIsx012Addr = 0x3C;
        }
        else
        {
            g_iIsx012Addr = 0x1A;
        }
        CamacqTraceErr(" g_iIsx012Addr=0x%x", g_iIsx012Addr);
        CamacqTraceErr( "iRet:%d, isx006 sensor rom version : %x%x", iRet, rgucReadData[1], rgucReadData[0] );
    }
    else if( !strcmp( this->m_szName, "s5k6aafx13") )
    {
        U8 rgucSetPage[4] = { 0xFC, 0xFC, 0xD0, 0x00 };
        U16 usReadAddr = 0x1006;
        U8 rgucReadData[2] = { 0, };
        
        CamacqExtWriteI2c( this->m_pI2cClient, rgucSetPage, 4 );
		CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );

		CamacqTraceDbg( "iRet:%d, low sensor id : %x%x", iRet, rgucReadData[0], rgucReadData[1] );
    }
    else if( !strcmp( this->m_szName, "s5k4ecgx") )
    {
        U8 rgucSetPage[4] = { 0xFC, 0xFC, 0xD0, 0x00 };
        U16 usReadAddr = 0x1006;
        U8 rgucReadData[2] = { 0, };
        
        CamacqExtWriteI2c( this->m_pI2cClient, rgucSetPage, 4 );
		CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );

		CamacqTraceDbg( "iRet:%d, sensor : %s, id : %02x -- %02x", iRet, this->m_szName, rgucReadData[0], rgucReadData[1] ); 
    }
    else if( !strcmp( this->m_szName, "s5k5ccgx") )
    {
        CamacqTraceDbg("s5k5ccgx");

        U8 rgucSetPage[4] = { 0xFC, 0xFC, 0xD0, 0x00 };
        U16 usReadAddr = 0x1006;
        U8 rgucReadData[2] = { 0, };

        iRet = CamacqExtWriteI2c( this->m_pI2cClient, rgucSetPage, 4 );
        if( iRet < 0 )
        {
            CamacqTraceDbg( "I2c write fail" );
            iRet = -1;         
        }
        else
        {
            CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );
            CamacqTraceDbg( "iRet:%d, s5k5ccgx sensor id : %x%x", iRet, rgucReadData[0], rgucReadData[1] );
        }
    }
    else if( !strcmp( this->m_szName, "mt9v114") )
    {
       CamacqTraceDbg("mt9v114");

#if 0 // test
        if( this->m_pI2cClient != 0 ) {
            CamacqTraceDbg("WINGI TEST==================");
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvInitRegs, this->m_uiResType );
            CamacqExtDelay(10);
        }
#endif

       
    }
    else if( !strcmp( this->m_szName, "isx012") )
    {
       CamacqTraceDbg("isx012");
    }
	else
	{
		iRet = -1;
		CamacqTraceErr( "Not Supported Sensor !! : %s", this->m_szName );
	}

	// 3. power-off
    g_pstCamacqSensorManager->SensorPowerOff( g_pstCamacqSensorManager, uiResType );
    
#else /* TODO : standard detect routine (reference to STE) */
    this = &camacq_api;
	camacq_trace_dbg();
	camacq_trace_dbg(": name[%s]", this->name);
	camacq_trace_dbg(": vsyncPol[%d]", this->vsyncPol);
	camacq_trace_dbg(": hsyncPol[%d]", this->hsyncPol);

    /* select serial bus module */
    this->sbus = &camacq_sbus_i2c;

    camacq_ext_delay(1);

    camacq_ext_pwr_on();

    siret = this->sbus->init();
    if(siret < 0)
    {
        camacq_trace_err(":I2C access failed");
		goto CAMACQ_API_OUT;
    }

    this->sbus->set_devid(CAMACQ_I2C_ID);

    this->sbus->cleanup();

	CAMACQ_API_OUT:
    camacq_ext_pwr_off();
#endif

    CamacqTraceOUT();
    return iRet;
}

void* CamacqAPIInit( struct stCamacqSensor_t* this )
{
    CamacqTraceIN();

#if 0 /* TODO : standard routine (reference to STE) */
    /* at init , flash strobe is disabled and no visual effects */
    /* size and pixels format can be changed by global init settings */
    camacq_settings.stcur_flash_mode = V4L2_FLASH_DISABLED;
    strncpy(camacq_settings.stcur_efx.efx_name,"NO_EFX", MAX_EFX_NAME_LENGTH);
    strncpy(camacq_settings.stcur_wb_mode.wb_mode_name,"AUTO", MAX_WB_NAME_LENGTH);

    return (void*)&camacq_settings;
#endif

    CamacqTraceOUT();
    return NULL;
}

void CamacqAPICleanUp( struct stCamacqSensor_t *this )
{
    CamacqTraceIN();
    CamacqTraceOUT();
}

S32 CamacqAPIOpen( struct stCamacqSensor_t *this )
{
    S32 iRet = 0;
    CamacqTraceIN();
     
#if 0 /* TODO : standard routine (reference to STE) */
    camacq_ext_pwr_on();

    siret= this->sbus->init();
    if(siret < 0)
    {
        camacq_trace_err(":I2C access failed");
        goto CAMACQ_API_OUT;
    }

    this->sbus->set_devid(CAMACQ_I2C_ID);

    siret= camacq_ext_boot();
    if(siret < 0)
    {
        camacq_trace_err(":boot failed");
    }

CAMACQ_API_OUT:
#endif

    CamacqTraceOUT();
    return iRet;
}

    
S32 CamacqAPIClose( struct stCamacqSensor_t *this )
{
    S32 iRet = 0;
    CamacqTraceIN();

#if 0 /* TODO : standard routine (reference to STE) */
    siret = camacq_api_stop_sensor();
    if(siret < 0)
    {
        camacq_trace_err(":stop sensor failed");
        siret = -EINVAL;
        goto CAMACQ_API_OUT;
    }

    siret = camacq_ext_save_curctrls();
    if(siret < 0)
    {
        camacq_trace_err(":save current control failed");
        siret = -EINVAL;
        goto CAMACQ_API_OUT;
    }

    this->sbus->cleanup();

    camacq_ext_pwr_off();

CAMACQ_API_OUT:
#endif

    CamacqTraceOUT();
    return iRet;
}    

S32 CamacqAPIEnumPixFmt( struct stCamacqSensor_t* this, struct v4l2_fmtdesc* pstV4l2FmtDesc )
{
    S32 iRet = 0;
    _stCamacqFmt*  pstFormat;
    CamacqTraceIN( "pstV4l2FmtDesc->index : %d", pstV4l2FmtDesc->index );    

    if ( pstV4l2FmtDesc->index >= N_CAMACQ_FMTS )
    {
        CamacqTraceErr( "index err, index = %d", pstV4l2FmtDesc->index );
        return -EINVAL;
    }

    pstFormat = g_stCamacqFmts + pstV4l2FmtDesc->index;

    // set pstV4l2FmtDesc
    pstV4l2FmtDesc->flags = 0;
    if(sizeof(pstV4l2FmtDesc->description)>sizeof(pstFormat->pucDesc)){
    strcpy( pstV4l2FmtDesc->description, pstFormat->pucDesc );
	  }else{
	  	//LOGE("String Overflow");
	  	iRet=-1;
	  }
    pstV4l2FmtDesc->pixelformat = pstFormat->uiPixelFormat;

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIEnumFrameSizes( struct stCamacqSensor_t *this, struct v4l2_frmsizeenum* pstV4l2FrameSizeEnum )
{
    S32 iRet = 0;
    _stCamacqSize*  pstSize = 0;
    CamacqTraceIN( "pstV4l2FrameSizeEnum->index : %d, pstV4l2FrameSizeEnum->pixel_format : %d", 
                        pstV4l2FrameSizeEnum->index, pstV4l2FrameSizeEnum->pixel_format );

    if( pstV4l2FrameSizeEnum->pixel_format == V4L2_PIX_FMT_YUV422P  || 
        pstV4l2FrameSizeEnum->pixel_format == V4L2_PIX_FMT_YUV420  || 
        pstV4l2FrameSizeEnum->pixel_format == V4L2_PIX_FMT_UYVY  )
    {
        if ( pstV4l2FrameSizeEnum->index >= N_CAMACQ_WIN_SIZES )
        {
            CamacqTraceErr( "index err, index = %d", pstV4l2FrameSizeEnum->index );
            CamacqTraceErr( "=========================================", pstV4l2FrameSizeEnum->index );
            return -EINVAL;
        }
        
        pstSize = g_stCamacqWinSizes + pstV4l2FrameSizeEnum->index;
    }
    else if( pstV4l2FrameSizeEnum->pixel_format == V4L2_PIX_FMT_JPEG )
    {
        if ( pstV4l2FrameSizeEnum->index >= N_CAMACQ_JPEG_SIZES )
        {
            CamacqTraceErr( "index err, index = %d", pstV4l2FrameSizeEnum->index );
            CamacqTraceErr( "=========================================", pstV4l2FrameSizeEnum->index );
            return -EINVAL;
        }

        pstSize = g_stCamacqJpegSizes + pstV4l2FrameSizeEnum->index;
    }    
    

    // set pstV4l2FmtDesc
    pstV4l2FrameSizeEnum->type = V4L2_FRMSIZE_TYPE_DISCRETE;
    pstV4l2FrameSizeEnum->discrete.width = pstSize->uiWidth;
    pstV4l2FrameSizeEnum->discrete.height = pstSize->uiHeight;

    CamacqTraceOUT();
    return iRet;
}

#define JPEG_SIZE 1024*1024*3/2 /* mavell defendency, how to calculate jpeg image size ?? */
S32 CamacqAPITryFmt( struct stCamacqSensor_t* this, struct v4l2_format *pstV4l2Format, 
               _stCamacqFmt **pstRetFormat,  _stCamacqSize **pstRetSize )
{
    S32 iRet = 0;
    int iFmtIndex, iIndex;
    struct v4l2_pix_format *pstV4l2PixFmt = &pstV4l2Format->fmt.pix;
    CamacqTraceIN();

    // FORMAT E //////////////////////////////////////////////////////////////////////////////// 
    for( iFmtIndex = 0; iFmtIndex < N_CAMACQ_FMTS; iFmtIndex++)
    {
        if( g_stCamacqFmts[iFmtIndex].uiPixelFormat == pstV4l2PixFmt->pixelformat )
            break;
    }
    
    if ( iFmtIndex >= N_CAMACQ_FMTS )
    {
        CamacqTraceErr( " : unsupported format!\n" );
        return -EINVAL;
    }

    if( pstRetFormat != NULL )
        *pstRetFormat = &g_stCamacqFmts[ iFmtIndex ];

    CamacqTraceDbg( " : g_stCamacqFormats[ iFmtIndex ] = %d", iFmtIndex );
    // FORMAT X //////////////////////////////////////////////////////////////////////////////// 

    // SIZE  E ////////////////////////////////////////////////////////////////////////////////
    if(pstV4l2PixFmt->pixelformat == V4L2_PIX_FMT_JPEG )
    {
        for( iIndex = 0; iIndex < N_CAMACQ_JPEG_SIZES; iIndex++)
        {
            if ( pstV4l2PixFmt->width == g_stCamacqJpegSizes[iIndex].uiWidth && pstV4l2PixFmt->height == g_stCamacqJpegSizes[iIndex].uiHeight )
                break;
        }
        
        if( iIndex >= N_CAMACQ_JPEG_SIZES )
        {
            CamacqTraceErr( " : size exceeded!\n" );
            return -EINVAL;
        }

        if( pstRetSize != NULL )
            *pstRetSize = g_stCamacqJpegSizes + iIndex;

        CamacqTraceDbg( " : g_stCamacqJpegSizes[ iIndex ] = %d", iIndex );
    }
    else
    {
        for( iIndex = 0; iIndex < N_CAMACQ_WIN_SIZES; iIndex++)
        {
            if ( pstV4l2PixFmt->width == g_stCamacqWinSizes[iIndex].uiWidth && pstV4l2PixFmt->height == g_stCamacqWinSizes[iIndex].uiHeight )
                break;
        }
        
        if( iIndex >= N_CAMACQ_WIN_SIZES )
        {
            CamacqTraceErr( " : size exceeded!\n" );
            return -EINVAL;
        }

        pstV4l2PixFmt->bytesperline = pstV4l2PixFmt->width * g_stCamacqFmts[iFmtIndex].iBPP / 8;
        pstV4l2PixFmt->sizeimage = pstV4l2PixFmt->height * pstV4l2PixFmt->bytesperline;

        if( pstRetSize != NULL )
            *pstRetSize = g_stCamacqWinSizes + iIndex;

        CamacqTraceDbg( " : g_stCamacqWinSizes[ iIndex ] = %d", iIndex );
    }
    // SIZE  X ////////////////////////////////////////////////////////////////////////////////
    
    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetFmt( struct stCamacqSensor_t* this, struct v4l2_format* pstV4l2Format )
{
    S32 iRet = 0;
    _stCamacqFmt* pstCamacqFmt = NULL;
    _stCamacqSize* pstCamacqSize = NULL;
    struct v4l2_pix_format *pstV4l2PixFmt = &pstV4l2Format->fmt.pix;

    CamacqTraceIN();

    iRet = CamacqAPITryFmt( this, pstV4l2Format, &pstCamacqFmt, &pstCamacqSize );
    if( iRet )
        return iRet;

    CamacqTraceDbg( " pstCamacqFormat : pucDesc[%s], uiPixelFormat[%u], bpp[%d], pstV4l2PixFmt->pixelformat[ %d ]",
                pstCamacqFmt->pucDesc, pstCamacqFmt->uiPixelFormat, pstCamacqFmt->iBPP, pstV4l2PixFmt->pixelformat );
    CamacqTraceDbg( " width[%d], height[%d] ", pstCamacqSize->uiWidth, pstCamacqSize->uiHeight);


    // temp code, jpeg is capture
    if( V4L2_PIX_FMT_JPEG == pstCamacqFmt->uiPixelFormat )
    {
        // set sensor jpeg size
        if( pstCamacqSize->uiWidth == 2592 && pstCamacqSize->uiHeight == 1944 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSize5M, this->m_uiResType );
        }
        else if( pstCamacqSize->uiWidth == 2560 && pstCamacqSize->uiHeight == 1920 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSize5M_2, this->m_uiResType );
        }
        else if( pstCamacqSize->uiWidth == 2560 && pstCamacqSize->uiHeight == 1536 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSize4M, this->m_uiResType );
        }
        else if( pstCamacqSize->uiWidth == 2048 && pstCamacqSize->uiHeight == 1536 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSize3M, this->m_uiResType );
        }
        else if( pstCamacqSize->uiWidth == 1600 && pstCamacqSize->uiHeight == 1200 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSize2M, this->m_uiResType );
        }
        else if( pstCamacqSize->uiWidth == 1600 && pstCamacqSize->uiHeight == 960 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSize1_5M, this->m_uiResType );
        }
        else if( pstCamacqSize->uiWidth == 1280 && pstCamacqSize->uiHeight == 960 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSize1M, this->m_uiResType );
        }
        else if( pstCamacqSize->uiWidth == 640 && pstCamacqSize->uiHeight == 480 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSizeVGA, this->m_uiResType );
        }
        else if( pstCamacqSize->uiWidth == 400 && pstCamacqSize->uiHeight == 240 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSizeWQVGA, this->m_uiResType );
        }
        else if( pstCamacqSize->uiWidth == 320 && pstCamacqSize->uiHeight == 240 )
        {
            CamacqExtWriteI2cLists( this->m_pI2cClient, this->m_pstExtAPIs->m_pstSensorRegs->pvJpegOutSizeQVGA, this->m_uiResType );
        }
        else
        {
            CamacqTraceErr(" Not supported Jpeg size!!");
        }  

        // set sensor fmt
        CamacqExtWriteI2cLists( this->m_pI2cClient, pstCamacqFmt->pvRegs[this->m_uiResType], this->m_uiResType );

    }
    else // temp code, yuv is preview
    {
        // set sensor fmt
        CamacqExtWriteI2cLists( this->m_pI2cClient, pstCamacqFmt->pvRegs[this->m_uiResType], this->m_uiResType );
    }    
    
    // update status fields
    memcpy( &(this->m_pstCamacqSettings->stCamacqCurSize), pstCamacqSize, sizeof(pstCamacqSize) ); 
    memcpy( &(this->m_pstCamacqSettings->stCamacqCurFmt), pstCamacqFmt, sizeof(pstCamacqFmt) );
    
    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIStopSensor( struct stCamacqSensor_t *this )
{
    S32 iRet = 0;
    CamacqTraceIN();

    this->m_pstCamacqInfo->eState = CAMACQ_STATE_STOP;

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIStartSensor( struct stCamacqSensor_t *this, struct v4l2_pix_format *pstV4l2Format, 
                            _eCameraMode eNewCameraMode, void *pvpriv)
{
    S32 iRet = 0, iIndex;
    _stCamacqFmt* pstCamacqFmt;
    _eCamacqState eCurState;
    _stCamacqExtAPIs* pExtAPIs = this->m_pstExtAPIs;
    CamacqTraceIN();

    // find fmt
    for( iIndex = 0; iIndex < N_CAMACQ_FMTS; iIndex++)
    {
        if( g_stCamacqFmts[iIndex].uiPixelFormat == pstV4l2Format->pixelformat )
            break;
    }
    if ( iIndex >= N_CAMACQ_FMTS )
    {
        CamacqTraceDbg( " : unsupported format!\n" );
        return -EINVAL;
    }
    pstCamacqFmt = &g_stCamacqFmts[ iIndex ];

    if( eNewCameraMode == CAMACQ_MODE_VIEWFINDER )
    {
        eCurState = this->m_pstCamacqInfo->eState;

        /* acting on the sensor */
        if( eCurState == CAMACQ_STATE_RUN ) /*sensor still running */
        {
            CamacqTraceErr(":already running");
            goto CAMACQ_API_OUT;
        }

        // CAMACQ_REG_PREVIEW
        CamacqExtWriteI2cLists( this->m_pI2cClient, pExtAPIs->m_pstSensorRegs->pvPreviewRegs, this->m_uiResType );   
        
        this->m_pstCamacqInfo->eState = CAMACQ_STATE_RUN;
    }
    else if( eNewCameraMode == CAMACQ_MODE_STILL )
    {
        CamacqExtWriteI2cLists( this->m_pI2cClient, pExtAPIs->m_pstSensorRegs->pvSnapshotRegs, this->m_uiResType );
    }
    else
    {
        CamacqTraceErr(":invalid mode");
        iRet = -EINVAL;
        goto CAMACQ_API_OUT;
    }    

CAMACQ_API_OUT:
    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIQueryControl( struct stCamacqSensor_t* this, struct v4l2_queryctrl *pstV4l2QueryCtrl )
{
    _stCamacqControl* pstCtrl = CamacqFindControl( this, pstV4l2QueryCtrl->id );
    S32 iRet = 0;
    CamacqTraceIN();

	if( pstCtrl == NULL )
    {   
        CamacqTraceErr( ": Invalid Control" );
		iRet = -EINVAL;
    }
    else
    {
        *pstV4l2QueryCtrl = pstCtrl->stV4l2QueryCtrl;
    }

    CamacqTraceOUT( " iRet = %d", iRet );
	return iRet;
}

S32 CamacqAPISetControl( struct stCamacqSensor_t* this, struct v4l2_control *pstV4l2Control )
{
    S32 iRet = 0, iValue = pstV4l2Control->value;
    _stCamacqControl* pstCtrl = NULL;
    _stCamacqExtAPIs* pstExtAPIs = this->m_pstExtAPIs;
    CamacqTraceIN( " iRet = %d, id = %x, value = %d", iRet, pstV4l2Control->id, pstV4l2Control->value );

    pstCtrl = CamacqFindControl( this, pstV4l2Control->id );
	if( pstCtrl == NULL )
    {   
        CamacqTraceErr( ": Invalid Control" );
		iRet = -EINVAL;
    }
    else
    {
        if( iValue < pstCtrl->stV4l2QueryCtrl.minimum || iValue > pstCtrl->stV4l2QueryCtrl.maximum )
        {
            CamacqTraceErr( ":invalid range, iValue[%d]", iValue );
            iRet = -ERANGE;
            goto CAMACQ_API_OUT;
        }
        else
        {
            switch(pstCtrl->stV4l2QueryCtrl.id)
            {
                case V4L2_CID_HFLIP:
                {
                    iRet = pstExtAPIs->Hflip(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":hflip failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;
                
                case V4L2_CID_VFLIP:
                {
                    iRet = pstExtAPIs->Vflip(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":vflip failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;
                
                case V4L2_CID_MET_EXP:
                {
                    iRet = pstExtAPIs->Exposure(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":exposure failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;
                
                case V4L2_CID_SENSITIVITY:
                {
                    iRet = pstExtAPIs->Sensitivity(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":sensitivity failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;
                
                case V4L2_CID_SCENE:
                {
                    iRet = pstExtAPIs->Scene(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":scene failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;
                
                case V4L2_CID_BRIGHTNESS:
                {
                    iRet = pstExtAPIs->Brightness(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":brightness failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;

                case V4L2_CID_EXP_COMPENSATION:
                {
                    iRet = pstExtAPIs->ExposureCompensation(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":exposure compensation failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;

                case V4L2_CID_ZOOM:
                {
                    iRet = pstExtAPIs->Zoom(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":zoom failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;

                case V4L2_CID_FOCUS_AUTO:
                {
                    iRet = pstExtAPIs->Autofocus(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":autofocus failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;

                }
                break;

                case V4L2_CID_ATFCS_MODE:
                {
                    iRet = pstExtAPIs->AutofocusMode(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":autofocus mode failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;

                    // Save Current AF mode
                    this->m_pstCamacqSettings->stV4l2CurAutoFocusMode = iValue;
                }
                break;

                case V4L2_CID_CONTRAST:
                {
                    iRet = pstExtAPIs->Contrast(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":Contrast failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;
                    
                case V4L2_CID_SATURATION:
                {
                    iRet = pstExtAPIs->Saturation(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":Saturation failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;

                case V4L2_CID_SHARPNESS:
                {
                    iRet = pstExtAPIs->Sharpness(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":Sharpness failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;

                case V4L2_CID_POWER_LINE_FREQUENCY:
                {
                    iRet = pstExtAPIs->AntiBanding(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":antibanding failed");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;
                }
                break;

                case V4L2_CID_INIT_CAMCORDER:
                {
                    iRet = pstExtAPIs->InitCamcorder(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":init camcorder err");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;       
                }
                break;

                case V4L2_CID_SET_CAMCORDER_SIZE:
                {
                    iRet = pstExtAPIs->SetCamcorderSize(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":set camcorder size err");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;       
                }
                break;

                case V4L2_CID_INIT_VT:
                {
                    iRet = pstExtAPIs->InitVT(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":init camcorder err");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;       
                }
                break;

                case V4L2_CID_SET_VT_SIZE:
                {
                    iRet = pstExtAPIs->SetVTSize(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":set vt size err");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;       
                }
                break;
                case V4L2_CID_SET_PREVIEW_SIZE:
                {
                    iRet = pstExtAPIs->SetPreviewSize(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":set preview size err");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;       
                }
                break;

                case V4L2_CID_FPS:
                {
                    iRet = pstExtAPIs->SetFps(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                    if(iRet < 0)
                    {
                        CamacqTraceErr(":fps err");
                        iRet = -EINVAL;
                        goto CAMACQ_API_OUT;
                    }
                    pstCtrl->iCurVal = iValue;       
                }
                break;


                case V4L2_CID_PRIVATE_CTRL_MODE:
                {
                    iRet = pstExtAPIs->CameraPrivateControl(pstExtAPIs, CAMACQ_EXT_MODE_SET, &iValue);
                }
                break;

                default:
                {
                    CamacqTraceErr(":not supported");
                    iRet = -EINVAL;
                }
                break;
            }
        }
    }   
    
CAMACQ_API_OUT:
    CamacqTraceOUT( " iRet = %d, id = %d, value = %d", iRet, pstV4l2Control->id, pstV4l2Control->value );
	return iRet;
}

S32 CamacqAPIGetControl( struct stCamacqSensor_t* this, struct v4l2_control *pstV4l2Control )
{
    S32 iRet = 0;
    _stCamacqControl* pstCtrl = NULL;
    CamacqTraceIN( " iRet = %d, id = %d, value = %d", iRet, pstV4l2Control->id, pstV4l2Control->value );
   
    pstCtrl = CamacqFindControl( this, pstV4l2Control->id );
	if( pstCtrl == NULL )
    {   
        CamacqTraceErr( ": Invalid Control" );
		iRet = -EINVAL;
    }
    else
    {
        switch( pstCtrl->stV4l2QueryCtrl.id )
        {
            case V4L2_CID_FOCUS_AUTO:
            {
                iRet = this->m_pstExtAPIs->Autofocus( this->m_pstExtAPIs, CAMACQ_EXT_MODE_GET, &(pstCtrl->iCurVal) );
                if( iRet < 0 )
                {
                    CamacqTraceErr( " failed" );
                    iRet = -EINVAL;
                }
                pstV4l2Control->value = pstCtrl->iCurVal;
            }
            break;

            case V4L2_CID_CHECK_LUX:
            {
                pstCtrl->iCurVal = CamacqExtCheckLux( this->m_pstExtAPIs );
                CamacqTraceDbg("Lux value : %d", pstCtrl->iCurVal);

                pstV4l2Control->value = pstCtrl->iCurVal;
            }
            break;
           

            case V4L2_CID_PRIVATE_CTRL_MODE:
            {
                iRet = this->m_pstExtAPIs->CameraPrivateControl( this->m_pstExtAPIs, CAMACQ_EXT_MODE_GET, &(pstCtrl->iCurVal) );
                if( iRet < 0 )
                {
                    CamacqTraceErr( " failed" );
                    iRet = -EINVAL;
                }
                pstV4l2Control->value = pstCtrl->iCurVal;
            }
            break;

            case  V4L2_CID_AUTO_WHITE_BALANCE:
            case  V4L2_CID_EXPOSURE_AUTO:     
            case  V4L2_CID_HFLIP:
            case  V4L2_CID_VFLIP:
            case  V4L2_CID_MET_EXP:
            case  V4L2_CID_SENSITIVITY:       
            case  V4L2_CID_BRIGHTNESS:
            case  V4L2_CID_SCENE:
            {
                pstV4l2Control->value = pstCtrl->iCurVal;
            }
            break;
            
//denis_exif
            case V4L2_CID_CHECK_EXPOSURETIME:
            {
                pstCtrl->iCurVal = CamacqExtCheckExposureTime( this->m_pstExtAPIs );
                CamacqTraceDbg("Denis : Ex value : %d", pstCtrl->iCurVal);

                pstV4l2Control->value = pstCtrl->iCurVal;
            }
            break;

            case V4L2_CID_CHECK_ISO:
            {
                pstCtrl->iCurVal = CamacqExtCheckISO( this->m_pstExtAPIs );
                CamacqTraceDbg("Denis : ISO value : %d", pstCtrl->iCurVal);

                pstV4l2Control->value = pstCtrl->iCurVal;
            }
            break;
            
            case V4L2_CID_CHECK_ESD:        //denis_esd
            {
                pstCtrl->iCurVal = CamacqExtCheckESD( this->m_pstExtAPIs );
                CamacqTraceDbg("Denis : ESD value : %d", pstCtrl->iCurVal);

                pstV4l2Control->value = pstCtrl->iCurVal;
            }
            break;
//denis_ae
            case V4L2_CID_CHECK_AESTABILITY:
            {
                pstCtrl->iCurVal = CamacqExtCheckAEStability( this->m_pstExtAPIs );
                CamacqTraceDbg("Denis : AE value : %d", pstCtrl->iCurVal);

                pstV4l2Control->value = pstCtrl->iCurVal;
            }
            break;            
            
            default:
            {
                CamacqTraceErr( ":not supported" );
                iRet = -EINVAL;
            }
        }
    }
    
    CamacqTraceOUT();
    return iRet;

}

S32 CamacqAPICropCap( struct stCamacqSensor_t *this, struct v4l2_cropcap *pstV4l2CropCap, void *pvpriv )
{
    S32 iRet = 0;
    CamacqTraceIN();
    
    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetCrop( struct stCamacqSensor_t *this, struct v4l2_crop *pstV4l2Crop, void *pvpriv )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIGetCrop( struct stCamacqSensor_t *this, struct v4l2_crop *pstV4l2Crop, void *pvpriv )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetStrobe( struct stCamacqSensor_t *this, struct v4l2_flash *pstV4l2Flash, void *pvpriv )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIGetStrobe( struct stCamacqSensor_t *this, struct v4l2_flash *pstV4l2Flash, void *pvpriv )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIQueryMenu( struct stCamacqSensor_t *this, struct v4l2_querymenu *pstV4l2QueryMenu )
{
    S32 iRet = 0;
    CamacqTraceIN();

    iRet = -EINVAL;

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetJpegQuality( struct stCamacqSensor_t *this, struct v4l2_jpegcompression *pstV4l2Jpegcomp )
{
    S32 iRet = 0, iQuality;
    const void* pvRegs = NULL;

    iQuality = pstV4l2Jpegcomp->quality;
    CamacqTraceIN( " iQuality : %d ", iQuality );

    if( iQuality == CAMACQ_EXT_JPEG_QUALITY_SUPERFINE )
    {
        CamacqTraceDbg(" CAMACQ_EXT_JPEG_QUALITY_SUPERFINE ");
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvJpegQualitySuperfine;
    }
    else if( iQuality == CAMACQ_EXT_JPEG_QUALITY_FINE )
    {
        CamacqTraceDbg(" CAMACQ_EXT_JPEG_QUALITY_FINE ");
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvJpegQualityFine;
    }
    else if( iQuality == CAMACQ_EXT_JPEG_QUALITY_NORMAL )
    {
        CamacqTraceDbg(" CAMACQ_EXT_JPEG_QUALITY_NORMAL ");
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvJpegQualityNormal;
    }
    else
    {
        CamacqTraceErr( " Not Supported Jpeg Quality : %d, Set SUPERFINE", iQuality );
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvJpegQualitySuperfine;        
    }

    if( pvRegs )
    {
        CamacqExtWriteI2cLists( this->m_pI2cClient, pvRegs, this->m_uiResType );
    }
   
    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIGetJpegQuality( struct stCamacqSensor_t *this, struct v4l2_jpegcompression *pstV4l2Jpegcomp )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetJpegHeader( struct stCamacqSensor_t *this, U8 **ppcBuf )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetJpegFooter( struct stCamacqSensor_t *this, U8 *pcBuf )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIGetCamCap( struct stCamacqSensor_t *this, struct v4l2_camcap *pstV4l2CamCap, void *pvpriv )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIGetActiveCam( struct stCamacqSensor_t *this, struct v4l2_camera_status *pstV4l2CamStatus, void *pvpriv )
{
    S32 iRet = 0;
    CamacqTraceIN();
    
    pstV4l2CamStatus->running_camera = 0;
    pstV4l2CamStatus->nb_camera = 1; /* let's pipoting multimedia */

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetActiveCam( struct stCamacqSensor_t *this, struct v4l2_camera_status *pstV4l2CamStatus, void *pvpriv )
{
    S32 iRet = 0;
    CamacqTraceIN();

    iRet = -EEXIST;

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetEfx( struct stCamacqSensor_t* this, struct v4l2_efx *pstV4l2Efx )
{
    S32 iRet = 0;
    const void* pvRegs = NULL;
    CamacqTraceIN( " effect : %s", pstV4l2Efx->efx_name );

    if( !strcmp(pstV4l2Efx->efx_name, "none") )
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectNoneRegs; 
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "mono") )
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectGrayRegs;
    }    
    else if( !strcmp(pstV4l2Efx->efx_name, "negative") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectNegativeRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "solarize") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectSolarizeRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "sepia") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectSepiaRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "posterize") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectPosterizeRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "whiteboard") )
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectWhiteBoardRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "blackboard") )
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectBlackBoardRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "aqua") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectAquaRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "sharpen") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectSharpenRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "vivid") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectVividRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "green") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectGreenRegs;
    }
    else if( !strcmp(pstV4l2Efx->efx_name, "sketch") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvEffectSketchRegs;
    }
    else
    {
        CamacqTraceErr(  ":invalid wb[%s] ", pstV4l2Efx->efx_name );
        pvRegs = NULL;
        iRet = -EINVAL;
    }
   
    if( pvRegs )
    {
        CamacqExtWriteI2cLists( this->m_pI2cClient, pvRegs, this->m_uiResType );
        
        // save
        memset( this->m_pstCamacqSettings->stV4l2CurEffect.efx_name, 0, sizeof(this->m_pstCamacqSettings->stV4l2CurEffect.efx_name) );
        strcpy( this->m_pstCamacqSettings->stV4l2CurEffect.efx_name, pstV4l2Efx->efx_name );
        CamacqTraceDbg( "cur effect : %s", this->m_pstCamacqSettings->stV4l2CurEffect.efx_name );
    }
  
    CamacqTraceOUT();
	return iRet;
}

S32 CamacqAPIGetEfx( struct stCamacqSensor_t* this, struct v4l2_efx *pstV4l2Efx )
{
    S32 iRet = 0;
    CamacqTraceIN();

    strcpy( pstV4l2Efx->efx_name, this->m_pstCamacqSettings->stV4l2CurEffect.efx_name );

    CamacqTraceOUT();
	return iRet;
}

S32 CamacqAPIQueryEfx( struct stCamacqSensor_t* this, struct v4l2_query_efx *pstV4l2QueryEfx )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetWbMode( struct stCamacqSensor_t* this, struct v4l2_wb_mode *pstV4l2WbMode )
{
    S32 iRet = 0;
    const void* pvRegs = NULL;
    
#if defined(_S5K4ECGX_EVT1_MIPI_)
    /* READ 0x04E6 */
    int iRegTcDbgAutoAlgEnBits = 0;
    U8	rgucWriteRegs_1[4] = {0x00,0x2C,0x70,0x00};
    U8	rgucWriteRegs_2[4] = {0x00,0x2E,0x04,0xE6};
    U8	rgucWriteRegs_3[4] = {0x00,0x28,0x70,0x00};
    U8	rgucWriteRegs_4[4] = {0x00,0x2A,0x04,0xE6};
    U8  rgucWriteRegs[4] = {0x00, };
    U8  rgucReadData[2] = {0, };
    U16 usReadAddr = 0x0F12;

    CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs_1, 4 );
    CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs_2, 4 );
    CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );

    iRegTcDbgAutoAlgEnBits = ( rgucReadData[0] << 8 );
    iRegTcDbgAutoAlgEnBits |= rgucReadData[1];

    CamacqTraceDbg( "iRegTcDbgAutoAlgEnBits : 0x%x, rgucReadData[0] : 0x%x, rgucReadData[1] : 0x%x",
            iRegTcDbgAutoAlgEnBits, rgucReadData[0], rgucReadData[1] );

    if( !strcmp(pstV4l2WbMode->wb_mode_name, "auto") )
    {
        iRegTcDbgAutoAlgEnBits = iRegTcDbgAutoAlgEnBits | 0x8;
    }
    else
    {
        iRegTcDbgAutoAlgEnBits = iRegTcDbgAutoAlgEnBits & 0xFFF7;
    }

    CamacqTraceDbg("iRegTcDbgAutoAlgEnBits : 0x%X", iRegTcDbgAutoAlgEnBits);

    rgucWriteRegs[0] = 0x0F; rgucWriteRegs[1] = 0x12;
    rgucWriteRegs[2] = (U8)(iRegTcDbgAutoAlgEnBits >> 8);
    rgucWriteRegs[3] = (U8)iRegTcDbgAutoAlgEnBits;

    CamacqTraceDbg("rgucWriteRegs: 0x%02X%02X%02X%02X" , rgucWriteRegs[0] , rgucWriteRegs[1], rgucWriteRegs[2] , rgucWriteRegs[3]);
    CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs_3, 4);
    CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs_4, 4);
    CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs, 4 );
#endif /* _S5K4ECGX_EVT1_MIPI_ */

    CamacqTraceIN( " WB : %s", pstV4l2WbMode->wb_mode_name );
    if( !strcmp(pstV4l2WbMode->wb_mode_name, "auto") )
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbAutoRegs;
    }
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "incandescent") )
    { 
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbIncandescentRegs;
    }    
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "fluorescent") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbFluorescentRegs;
    }
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "warm-fluorescent") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbFluorescentRegs;
    }
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "daylight") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbDaylightRegs;
    }
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "cloudy-daylight") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbCloudyRegs;
    }
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "twilight") )
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbTwilightRegs;
    }
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "shade") )
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbShadeRegs;
    }
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "tungsten") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbTungstenRegs;
    }    
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "off") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbOffRegs;
    }
    else if( !strcmp(pstV4l2WbMode->wb_mode_name, "horizon") ) 
    {
        pvRegs = this->m_pstExtAPIs->m_pstSensorRegs->pvWbHorizonRegs;
        
    }
    else
    {
        CamacqTraceErr(  ":invalid wb[%s] ", pstV4l2WbMode->wb_mode_name );
        pvRegs = NULL;
        iRet = -EINVAL;
    }
   
    if( pvRegs )
    {
        CamacqExtWriteI2cLists( this->m_pI2cClient, pvRegs, this->m_uiResType );
        
        // save
        memset( this->m_pstCamacqSettings->stV4l2CurWbMode.wb_mode_name, 0, 
                                        sizeof(this->m_pstCamacqSettings->stV4l2CurWbMode.wb_mode_name) );
        strcpy( this->m_pstCamacqSettings->stV4l2CurWbMode.wb_mode_name, pstV4l2WbMode->wb_mode_name );
        CamacqTraceDbg( "cur WB : %s", this->m_pstCamacqSettings->stV4l2CurWbMode.wb_mode_name );
    }
  
    CamacqTraceOUT();
	return iRet;
}

S32 CamacqAPIGetWbMode( struct stCamacqSensor_t* this, struct v4l2_wb_mode *pstV4l2WbMode )
{
    S32 iRet = 0;
    CamacqTraceIN();

    strcpy( pstV4l2WbMode->wb_mode_name, this->m_pstCamacqSettings->stV4l2CurWbMode.wb_mode_name );

    CamacqTraceOUT();
	return iRet;
}

S32 CamacqAPIQueryWbMode( struct stCamacqSensor_t* this, struct v4l2_query_wb_mode *pstV4l2QueryWbMode )
{
    S32 iRet = 0;
    CamacqTraceIN();

    CamacqTraceOUT();
    return iRet;
}



S32 CamacqAPIGetParm( struct stCamacqSensor_t* this, struct v4l2_streamparm *pstV4l2StreamParm )
{
    S32 iRet = 0;
    CamacqTraceIN();

    
    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetParm( struct stCamacqSensor_t* this, struct v4l2_streamparm *pstV4l2StreamParm )
{
    S32 iRet = 0;
    CamacqTraceIN();

    
    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIIntInit( struct stCamacqSensor_t* this )
{
    S32 iRet = 0;
    _stCamacqExtAPIs* pstExtAPIs = this->m_pstExtAPIs;
    CamacqTraceIN();

    /* boot sensor */ 
    iRet = pstExtAPIs->Boot( pstExtAPIs );
    if( iRet < 0 )
    {
        CamacqTraceErr(": iRet=%d", iRet);
        iRet = -1;
        return iRet;
    }

#if defined(__ISX006_SONY__)
    /* Temp for Sony */
    if( !strcmp(this->m_pI2cClient->name, "isx006") )
    {
        CamacqTraceDbg("Change to 1A to 0x3D");
        this->m_pI2cClient->addr = 0x3D;
    }
#endif /* __ISX006_SONY__ */

#if defined(_S5K4ECGX_EVT1_MIPI_)
    /* Check FIRMWARE */
    {
#if 0
        // m_uiFirmwareVer
        U8 rgucWriteRegs_1[4] = {0x00,0x2C,0x70,0x00};
        U8 rgucWriteRegs_2[4] = {0x00,0x2E,0x1A,0xA6};
        U8 rgucReadData[2] = {0x00, };
        U16 usReadKey = 0x0F12;

        CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs_1, 4 );
        CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs_2, 4 );
        CamacqExtReadI2c( this->m_pI2cClient, usReadKey, 2, rgucReadData, 2);
        CamacqTraceDbg( "rgucReadData[0] : 0x%x, rgucReadData[1] : 0x%x ",
            rgucReadData[0], rgucReadData[1] );

        this->m_uiFirmwareVer = 0;
        this->m_uiFirmwareVer = ( rgucReadData[0] << 8 );
        this->m_uiFirmwareVer |= rgucReadData[1];
        CamacqTraceDbg( "_S5K4ECGX_EVT1_MIPI_ Firmware Ver. : 0x%X ", this->m_uiFirmwareVer );
#endif
        this->m_uiFirmwareVer = 0x11;
        
    }
#endif /*_S5K4ECGX_EVT1_MIPI_*/

    this->m_pstCamacqInfo->eState = CAMACQ_STATE_BOOT;
    
    
    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetFlash( struct stCamacqSensor_t* this, struct v4l2_flash *pstV4l2Flash )
{
    S32 iRet = 0;
    _stCamacqExtAPIs* pstExtAPIs = this->m_pstExtAPIs;
    CamacqTraceIN();
    
    pstExtAPIs->FlashControl( pstExtAPIs, CAMACQ_EXT_MODE_SET, pstV4l2Flash );

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPISetInput( struct stCamacqSensor_t* this, int* pID )
{
    S32 iRet = 0;
    CamacqTraceIN( " pID : %d ", *pID );

    /* sensor selected */ 
    g_pstCamacqSensorManager->SetSensor( g_pstCamacqSensorManager, *pID );
    
    CamacqTraceOUT();
    return iRet;
}


S32 CamacqAPIStreamOn( struct stCamacqSensor_t* this )
{
    S32 iRet = 0;

#if 0 // defined(_S5K5CCGX_EVT1_MIPI_)
    S32 iResult = 0;
    U8	rgucWriteRegs_0[4] = {0xFC,0xFC,0xD0,0x00};
    U8	rgucWriteRegs_1[4] = {0x00,0x2C,0x70,0x00};
    U8	rgucWriteRegs_2[4] = {0x00,0x2E,0x01,0x88};
    U8  rgucReadData[2] = {0, };
    U16 usReadAddr = 0x0F12;
#endif

    CamacqTraceIN();

#if 0 // defined(_S5K5CCGX_EVT1_MIPI_)

    CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs_0, 4 );
    CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs_1, 4 );
    CamacqExtWriteI2c( this->m_pI2cClient, rgucWriteRegs_2, 4 );
    CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );

    iResult = ( rgucReadData[0] << 8 );
    iResult |= rgucReadData[1];

    CamacqTraceDbg(" iResult : 0x%X", iResult);

#endif

#if defined(__ISX006_SONY__)
    /* test code for sony sensor s */
    // change sony i2c addr ... 19
    if( !strcmp(this->m_pI2cClient->name, "isx006") )
    {
        U16 usReadAddr = 0;        
        U8 rgucReadData[2] = {0, };
        U8 ucAfExt = 0;
        U8 ucAfState = 0;
        U32 uiCount = 0;

        usReadAddr = 0x0022;     
        CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );
        CamacqTraceDbg( " HSIZE_MONI : 0x%x -- 0x%x ", rgucReadData[1], rgucReadData[0] );

        usReadAddr = 0x0028;
        CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );
        CamacqTraceDbg( " VSIZE_MONI : 0x%x -- 0x%x ", rgucReadData[1], rgucReadData[0] );

        usReadAddr = 0x0024;
        CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );
        CamacqTraceDbg( " HSIZE_CAP : 0x%x -- 0x%x ", rgucReadData[1], rgucReadData[0] );

        usReadAddr = 0x002A;
        CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, rgucReadData, 2 );
        CamacqTraceDbg( " VSIZE_CAP : 0x%x -- 0x%x ", rgucReadData[1], rgucReadData[0] );

        /* Check to success loading autofocus driver. s */
        do{
            CamacqExtDelay( 1 );
            
            usReadAddr = 0x000A;
            CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, &ucAfExt, 1);
            CamacqTraceDbg( " AF_EXT : 0x%2x", ucAfExt);

            usReadAddr = 0x6D76;
            CamacqExtReadI2c( this->m_pI2cClient, usReadAddr, 2, &ucAfState, 1);
            CamacqTraceDbg( " AF_STATE : 0x%2x", ucAfState);

            uiCount++;
        }while( ((ucAfExt != 0x02) || (ucAfState != 0x03)) && (uiCount < 100) );
        /* Check to success loading autofocus driver. e */
    }    
    /* test code for sony sensor e */
#endif /*__ISX006_SONY__*/ 

    CamacqTraceOUT();
    return iRet;
}

S32 CamacqAPIStreamOff( struct stCamacqSensor_t* this )
{
    S32 iRet = 0;
    CamacqTraceIN();

    
    CamacqTraceOUT();
    return iRet;
}

#undef _CAMACQ_API_C_
#endif /* _CAMACQ_API_C_ */
