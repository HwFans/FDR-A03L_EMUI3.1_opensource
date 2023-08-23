#ifndef __LINUX_MSM_CAM_SENSOR_H
#define __LINUX_MSM_CAM_SENSOR_H

#ifdef MSM_CAMERA_BIONIC
#include <sys/types.h>
#endif

#include <media/msm_camsensor_sdk.h>

#include <linux/types.h>
#include <linux/i2c.h>
#ifdef CONFIG_COMPAT
#include <linux/compat.h>
#endif

#define I2C_SEQ_REG_SETTING_MAX   5

#define MSM_SENSOR_MCLK_8HZ   8000000
#define MSM_SENSOR_MCLK_16HZ  16000000
#define MSM_SENSOR_MCLK_24HZ  24000000

#define MAX_SENSOR_NAME 32
#define MAX_ACTUATOR_AF_TOTAL_STEPS 1024

#define MAX_OIS_MOD_NAME_SIZE 32
#define MAX_OIS_NAME_SIZE 32
#define MAX_OIS_REG_SETTINGS 800

#define MOVE_NEAR 0
#define MOVE_FAR  1

#define MSM_ACTUATOR_MOVE_SIGNED_FAR -1
#define MSM_ACTUATOR_MOVE_SIGNED_NEAR  1

#define MAX_EEPROM_NAME 32

#define MAX_AF_ITERATIONS 3
#define MAX_NUMBER_OF_STEPS 47

#define MAX_LED_TRIGGERS 3

enum flash_type {
	LED_FLASH = 1,
	STROBE_FLASH,
	GPIO_FLASH

};

enum msm_sensor_resolution_t {
	MSM_SENSOR_RES_FULL,
	MSM_SENSOR_RES_QTR,
	MSM_SENSOR_RES_2,
	MSM_SENSOR_RES_3,
	MSM_SENSOR_RES_4,
	MSM_SENSOR_RES_5,
	MSM_SENSOR_RES_6,
	MSM_SENSOR_RES_7,
	MSM_SENSOR_INVALID_RES,
};

enum msm_camera_stream_type_t {
	MSM_CAMERA_STREAM_PREVIEW,
	MSM_CAMERA_STREAM_SNAPSHOT,
	MSM_CAMERA_STREAM_VIDEO,
	MSM_CAMERA_STREAM_INVALID,
};

enum sensor_sub_module_t {
	SUB_MODULE_SENSOR,
	SUB_MODULE_CHROMATIX,
	SUB_MODULE_ACTUATOR,
	SUB_MODULE_EEPROM,
	SUB_MODULE_LED_FLASH,
	SUB_MODULE_STROBE_FLASH,
	SUB_MODULE_CSID,
	SUB_MODULE_CSID_3D,
	SUB_MODULE_CSIPHY,
	SUB_MODULE_CSIPHY_3D,
	SUB_MODULE_OIS,
	SUB_MODULE_MAX,
};

enum {
	MSM_CAMERA_EFFECT_MODE_OFF,
	MSM_CAMERA_EFFECT_MODE_MONO,
	MSM_CAMERA_EFFECT_MODE_NEGATIVE,
	MSM_CAMERA_EFFECT_MODE_SOLARIZE,
	MSM_CAMERA_EFFECT_MODE_SEPIA,
	MSM_CAMERA_EFFECT_MODE_POSTERIZE,
	MSM_CAMERA_EFFECT_MODE_WHITEBOARD,
	MSM_CAMERA_EFFECT_MODE_BLACKBOARD,
	MSM_CAMERA_EFFECT_MODE_AQUA,
	MSM_CAMERA_EFFECT_MODE_EMBOSS,
	MSM_CAMERA_EFFECT_MODE_SKETCH,
	MSM_CAMERA_EFFECT_MODE_NEON,
	MSM_CAMERA_EFFECT_MODE_MAX
};

enum {
	MSM_CAMERA_WB_MODE_AUTO,
	MSM_CAMERA_WB_MODE_CUSTOM,
	MSM_CAMERA_WB_MODE_INCANDESCENT,
	MSM_CAMERA_WB_MODE_FLUORESCENT,
	MSM_CAMERA_WB_MODE_WARM_FLUORESCENT,
	MSM_CAMERA_WB_MODE_DAYLIGHT,
	MSM_CAMERA_WB_MODE_CLOUDY_DAYLIGHT,
	MSM_CAMERA_WB_MODE_TWILIGHT,
	MSM_CAMERA_WB_MODE_SHADE,
	MSM_CAMERA_WB_MODE_OFF,
	MSM_CAMERA_WB_MODE_MAX
};

enum {
	MSM_CAMERA_SCENE_MODE_OFF,
	MSM_CAMERA_SCENE_MODE_AUTO,
	MSM_CAMERA_SCENE_MODE_LANDSCAPE,
	MSM_CAMERA_SCENE_MODE_SNOW,
	MSM_CAMERA_SCENE_MODE_BEACH,
	MSM_CAMERA_SCENE_MODE_SUNSET,
	MSM_CAMERA_SCENE_MODE_NIGHT,
	MSM_CAMERA_SCENE_MODE_PORTRAIT,
	MSM_CAMERA_SCENE_MODE_BACKLIGHT,
	MSM_CAMERA_SCENE_MODE_SPORTS,
	MSM_CAMERA_SCENE_MODE_ANTISHAKE,
	MSM_CAMERA_SCENE_MODE_FLOWERS,
	MSM_CAMERA_SCENE_MODE_CANDLELIGHT,
	MSM_CAMERA_SCENE_MODE_FIREWORKS,
	MSM_CAMERA_SCENE_MODE_PARTY,
	MSM_CAMERA_SCENE_MODE_NIGHT_PORTRAIT,
	MSM_CAMERA_SCENE_MODE_THEATRE,
	MSM_CAMERA_SCENE_MODE_ACTION,
	MSM_CAMERA_SCENE_MODE_AR,
	MSM_CAMERA_SCENE_MODE_FACE_PRIORITY,
	MSM_CAMERA_SCENE_MODE_BARCODE,
	MSM_CAMERA_SCENE_MODE_HDR,
	MSM_CAMERA_SCENE_MODE_MAX
};

enum csid_cfg_type_t {
	CSID_INIT,
	CSID_CFG,
	CSID_RELEASE,
};

enum csiphy_cfg_type_t {
	CSIPHY_INIT,
	CSIPHY_CFG,
	CSIPHY_RELEASE,
};

enum camera_vreg_type {
	VREG_TYPE_DEFAULT,
	VREG_TYPE_CUSTOM,
};

enum sensor_af_t {
	SENSOR_AF_FOCUSSED,
	SENSOR_AF_NOT_FOCUSSED,
};

enum cci_i2c_master_t {
	MASTER_0,
	MASTER_1,
	MASTER_MAX,
};

struct msm_camera_i2c_array_write_config {
	struct msm_camera_i2c_reg_setting conf_array;
	uint16_t slave_addr;
};

struct msm_camera_i2c_read_config {
	uint16_t slave_addr;
	uint16_t reg_addr;
	enum msm_camera_i2c_data_type data_type;
	uint16_t data;
};

struct msm_camera_csi2_params {
	struct msm_camera_csid_params csid_params;
	struct msm_camera_csiphy_params csiphy_params;
	uint8_t csi_clk_scale_enable;
};

struct msm_camera_csi_lane_params {
	uint16_t csi_lane_assign;
	uint16_t csi_lane_mask;
};

struct csi_lane_params_t {
	uint16_t csi_lane_assign;
	uint8_t csi_lane_mask;
	uint8_t csi_if;
	int8_t csid_core[2];
	uint8_t csi_phy_sel;
};

struct msm_sensor_info_t {
	char     sensor_name[MAX_SENSOR_NAME];
	uint32_t session_id;
	int32_t  subdev_id[SUB_MODULE_MAX];
	int32_t  subdev_intf[SUB_MODULE_MAX];
	uint8_t  is_mount_angle_valid;
	uint32_t sensor_mount_angle;
	int modes_supported;
	enum camb_position_t position;
};

struct camera_vreg_t {
	const char *reg_name;
	int min_voltage;
	int max_voltage;
	int op_mode;
	uint32_t delay;
	const char *custom_vreg_name;
	enum camera_vreg_type type;
};

/* < DTS2015020904827 yuguangcai 20150209 begin */
/* < DTS2015042401049 xurenjie/xwx208548 20150424 begin */
struct msm_sensor_af_otp {
	uint32_t index_start;
	uint16_t af_size;
	uint16_t start_code;
	uint16_t max_code;
/* < DTS2015050710345 Zhangbo 20150507 begin */
	uint16_t start_dist;//cm
	uint16_t end_dist;//cm
	uint32_t axis_angle;//0:Horizon  1:vertical
	uint32_t pose_offset;
/* DTS2015050710345 Zhangbo 201500507 end > */
};

#define ALTEK_MAX_COMMON_OTP_LEN 5
#define ALTEK_MAX_AWB_OTP_LEN 8
#define ALTEK_MAX_OIS_OTP_LEN 53

struct msm_sensor_common_otp {
	uint8_t common_size;
	uint8_t common_info[ALTEK_MAX_COMMON_OTP_LEN];
};
struct msm_sensor_awb_otp {
	uint32_t index_start;
	uint32_t awb_size;
	uint8_t aucISO_AWBCalib[ALTEK_MAX_AWB_OTP_LEN];
};
struct msm_sensor_ois_otp {
	uint32_t index_start;
	uint32_t ois_size;
	/*IMX278: liteon&sunny size is 43bytes, lg size is 53bytes*/
	uint8_t aucOIS[ALTEK_MAX_OIS_OTP_LEN];
};
struct msm_sensor_otp_info {
	uint32_t otp_size;
	struct msm_sensor_common_otp common_otp;
	struct msm_sensor_awb_otp awb_otp;
	struct msm_sensor_af_otp af_otp;
	struct msm_sensor_ois_otp ois_otp;
	uint8_t otp_vaild;
};
/* DTS2015042401049 xurenjie/xwx208548 20150424 end > */
/* DTS2015020904827 yuguangcai 20150209 end > */

/*< DTS2014111305646 tangying/205982 20141113 begin*/
/*use dtsi get sensor name instead of board id string*/
#define MAX_SENSOR_CODE_LENGTH 12 //ex: 23060156
#define MAX_SUPPORT_SENSOR_CODE_COUNT 2
/* < DTS2015011603233 houzhipeng 20150119 begin */
/* <DTS2015042303156 jwx206032 20150423 begin */
#define MAX_PRODUCT_NAME_LENGTH 32
 /* DTS2015042303156 jwx206032 20150423 end> */
struct msm_support_sensor_codes_info {
	char sensor_code_list[MAX_SUPPORT_SENSOR_CODE_COUNT][MAX_SENSOR_CODE_LENGTH];
	char product_name[MAX_PRODUCT_NAME_LENGTH];
};
/* DTS2015011603233 houzhipeng 20150119 end > */
/*DTS2014111305646 tangying/205982 20141113 end >*/

/* <DTS2015042303156 jwx206032 20150423 begin */
/* use dtsi get product name instead of board id string */
struct msm_hw_product_name {
	char product_name[MAX_PRODUCT_NAME_LENGTH];
};
 /* DTS2015042303156 jwx206032 20150423 end> */

struct sensorb_cfg_data {
	int cfgtype;
	union {
		struct msm_sensor_info_t      sensor_info;
		struct msm_sensor_init_params sensor_init_params;
		/* < DTS2015020904827 yuguangcai 20150209 begin */
		struct msm_sensor_otp_info otp_info;
		/* DTS2015020904827 yuguangcai 20150209 end > */
		void                         *setting;
	} cfg;
};

struct csid_cfg_data {
	enum csid_cfg_type_t cfgtype;
	union {
		uint32_t csid_version;
		struct msm_camera_csid_params *csid_params;
	} cfg;
};

struct csiphy_cfg_data {
	enum csiphy_cfg_type_t cfgtype;
	union {
		struct msm_camera_csiphy_params *csiphy_params;
		struct msm_camera_csi_lane_params *csi_lane_params;
	} cfg;
};

enum eeprom_cfg_type_t {
	CFG_EEPROM_GET_INFO,
	CFG_EEPROM_GET_CAL_DATA,
	CFG_EEPROM_READ_CAL_DATA,
	CFG_EEPROM_WRITE_DATA,
	CFG_EEPROM_GET_MM_INFO,
};

struct eeprom_get_t {
	uint32_t num_bytes;
};

struct eeprom_read_t {
	uint8_t *dbuffer;
	uint32_t num_bytes;
};

struct eeprom_write_t {
	uint8_t *dbuffer;
	uint32_t num_bytes;
};

struct eeprom_get_cmm_t {
	uint32_t cmm_support;
	uint32_t cmm_compression;
	uint32_t cmm_size;
};

struct msm_eeprom_cfg_data {
	enum eeprom_cfg_type_t cfgtype;
	uint8_t is_supported;
	union {
		char eeprom_name[MAX_SENSOR_NAME];
		struct eeprom_get_t get_data;
		struct eeprom_read_t read_data;
		struct eeprom_write_t write_data;
		struct eeprom_get_cmm_t get_cmm_data;
	} cfg;
};

#ifdef CONFIG_COMPAT
struct msm_sensor_power_setting32 {
	enum msm_sensor_power_seq_type_t seq_type;
	uint16_t seq_val;
	compat_uint_t config_val;
	uint16_t delay;
	compat_uptr_t data[10];
};

struct msm_sensor_power_setting_array32 {
	struct msm_sensor_power_setting32 power_setting_a[MAX_POWER_CONFIG];
	compat_uptr_t power_setting;
	uint16_t size;
	struct msm_sensor_power_setting32
		power_down_setting_a[MAX_POWER_CONFIG];
	compat_uptr_t power_down_setting;
	uint16_t size_down;
};

/* <DTS2014061204421 yangzhenxi/WX221546 20140612 begin */
struct msm_camera_sensor_slave_info32 {
	char sensor_name[32];
	char eeprom_name[32];
	char actuator_name[32];
	char ois_name[32];
	char flash_name[32];
	enum msm_sensor_camera_id_t camera_id;
	uint16_t slave_addr;
	enum i2c_freq_mode_t i2c_freq_mode;
	enum msm_camera_i2c_reg_addr_type addr_type;
	struct msm_sensor_id_info_t sensor_id_info;
	struct msm_sensor_power_setting_array32 power_setting_array;
	uint8_t  is_init_params_valid;
	struct msm_sensor_init_params sensor_init_params;
	uint8_t is_flash_supported;
	compat_uptr_t sensor_cam_id;
	/* < DTS2015052000188 y00294389 20150515 begin */
	compat_uptr_t dump_reg_info;
	uint16_t dump_reg_num;
	/* DTS2015052000188 y00294389 20150515 end > */
	/*<DTS2015073008870 wangqiaoli/w00345499 20150730 begin*/
	compat_uptr_t otp_vendor_info;
	/*DTS2015073008870 wangqiaoli/w00345499 20150730 end>*/
};
/* <DTS2014061204421 yangzhenxi/WX221546 20140612 end */

struct msm_camera_csid_lut_params32 {
	uint8_t num_cid;
	struct msm_camera_csid_vc_cfg vc_cfg_a[MAX_CID];
	compat_uptr_t vc_cfg[MAX_CID];
};

struct msm_camera_csid_params32 {
	uint8_t lane_cnt;
	uint16_t lane_assign;
	uint8_t phy_sel;
	uint32_t csi_clk;
	struct msm_camera_csid_lut_params32 lut_params;
};

struct msm_camera_csi2_params32 {
	struct msm_camera_csid_params32 csid_params;
	struct msm_camera_csiphy_params csiphy_params;
	uint8_t csi_clk_scale_enable;
};

struct csid_cfg_data32 {
	enum csid_cfg_type_t cfgtype;
	union {
		uint32_t csid_version;
		compat_uptr_t csid_params;
	} cfg;
};

struct eeprom_read_t32 {
	compat_uptr_t dbuffer;
	uint32_t num_bytes;
};

struct eeprom_write_t32 {
	compat_uptr_t dbuffer;
	uint32_t num_bytes;
};

struct msm_eeprom_cfg_data32 {
	enum eeprom_cfg_type_t cfgtype;
	uint8_t is_supported;
	union {
		char eeprom_name[MAX_SENSOR_NAME];
		struct eeprom_get_t get_data;
		struct eeprom_read_t32 read_data;
		struct eeprom_write_t32 write_data;
	} cfg;
};

struct msm_camera_i2c_seq_reg_setting32 {
	compat_uptr_t reg_setting;
	uint16_t size;
	enum msm_camera_i2c_reg_addr_type addr_type;
	uint16_t delay;
};
/* < DTS2014122203451 yangzhenxi 20141223 begin */
struct msm_camera_spi_reg_setting32 {
       compat_uptr_t param;
       uint16_t size;
       uint16_t opcode;
       uint16_t delay;
};
/* DTS2014122203451 yangzhenxi 20141223 end > */
#endif

enum msm_sensor_cfg_type_t {
	CFG_SET_SLAVE_INFO,
	CFG_SLAVE_READ_I2C,
	CFG_WRITE_I2C_ARRAY,
	CFG_SLAVE_WRITE_I2C_ARRAY,
	CFG_WRITE_I2C_SEQ_ARRAY,
	CFG_POWER_UP,
	CFG_POWER_DOWN,
	CFG_SET_STOP_STREAM_SETTING,
	CFG_GET_SENSOR_INFO,
	CFG_GET_SENSOR_INIT_PARAMS,
	CFG_SET_INIT_SETTING,
	CFG_SET_RESOLUTION,
	CFG_SET_STOP_STREAM,
	CFG_SET_START_STREAM,
	CFG_SET_SATURATION,
	CFG_SET_CONTRAST,
	CFG_SET_SHARPNESS,
	CFG_SET_ISO,
	CFG_SET_EXPOSURE_COMPENSATION,
	CFG_SET_ANTIBANDING,
	CFG_SET_BESTSHOT_MODE,
	CFG_SET_EFFECT,
	CFG_SET_WHITE_BALANCE,
	CFG_SET_AUTOFOCUS,
	CFG_CANCEL_AUTOFOCUS,
	CFG_SET_STREAM_TYPE,
	/* <DTS2014051302540 zhuchengming 20140513 begin */
	/* <DTS2015051109283 jiweifeng/jwx206032 20150515 begin */
	CFG_SET_OTP_INFO, 
	CFG_SET_AFC_OTP_INFO,
	/* DTS2015051109283 jiweifeng/jwx206032 20150515 end> */
	/* < DTS2015042906355 y00294389 20150515 begin */
    /* <DTS2015033002251 z00285045 20150413 begin */
	CFG_SET_AWB_OTP_INFO,
	/* DTS2015033002251 z00285045 20150413 end> */
	/* DTS2015042906355 y00294389 20150515 end > */
	/* DTS2014051302540 zhuchengming 20140513 end> */
	/* < DTS2014062602041 xianghao 20140626 begin */
	CFG_WRITE_EXPOSURE_DATA,
	/* DTS2014062602041 xianghao 20140626 end > */
	/*< DTS2014103002530 tangying/2059825 20141030 begin*/
	/* optimize camera print mipi packet and frame count log*/
	CFG_START_FRM_CNT,
	/* < DTS2014122203451 yangzhenxi 20141223 begin */
	CFG_STOP_FRM_CNT,
	/*DTS2014103002530 tangying/2059825 20141030 end >*/
	CFG_MISP_LOAD_FIRMWARE,
	CFG_MISP_STREAMON,
	CFG_MISP_STREAMOFF,
	CFG_WRITE_SPI_ARRAY,
	/* DTS2014122203451 yangzhenxi 20141223 end >*/
	/* < DTS2015020904827 yuguangcai 20150209 begin */
	CFG_GET_OTP,
	/* DTS2015020904827 yuguangcai 20150209 end > */
	/* < DTS2015040802929 yangzhenxi 20150408 begin */
        CFG_SPI_REG_SETTINGS,
	/* DTS2015040802929 yangzhenxi 20150408 end > */
};

/* < DTS2015021107432 yuguangcai 20150211 begin */
enum msm_actuator_cfg_type_t {
	CFG_GET_ACTUATOR_INFO,
	CFG_SET_ACTUATOR_INFO,
	CFG_SET_DEFAULT_FOCUS,
	CFG_MOVE_FOCUS,
	CFG_SET_POSITION,
	CFG_ACTUATOR_POWERDOWN,
	CFG_ACTUATOR_POWERUP,
	CFG_ACTUATOR_INIT,
	CFG_SET_VCM_CODE,
};
/* DTS2015021107432 yuguangcai 20150211 end > */

enum msm_ois_cfg_type_t {
	CFG_OIS_INIT,
	CFG_OIS_POWERDOWN,
	CFG_OIS_POWERUP,
	CFG_OIS_CONTROL,
	CFG_OIS_I2C_WRITE_SEQ_TABLE,

/*< DTS2015012606635 tangying/205982 20150126 begin*/
/*add camera ois driver*/
    CFG_OIS_SETOTP,
    CFG_OIS_TURN_ON,
    /*< DTS2015042909943 ganfan/206212 20150505 begin*/
    CFG_OIS_TURN_ON_LIN,
    /*DTS2015042909943 ganfan/206212 20150505 end >*/
    CFG_OIS_TURN_OFF,
    CFG_OIS_START_RUNNINGTEST,
    CFG_OIS_START_MMI_CHECK,
    /*< DTS2015042007464 ganfan/206212 20150420 begin*/
    CFG_OIS_START_MAG_CHECK,
    /*DTS2015042007464 ganfan/206212 20150420 end >*/
	/* <DTS2015073106553 xurenjie xwx208548 20150731 begin */
    CFG_OIS_GET_GYROGAIN,
    CFG_OIS_SET_GYROGAIN,
	/* DTS2015073106553 xurenjie xwx208548 20150731 end > */
/*DTS2015012606635 tangying/205982 20150126 end >*/
};

enum msm_ois_i2c_operation {
	MSM_OIS_WRITE = 0,
	MSM_OIS_POLL,
};

struct reg_settings_ois_t {
	uint16_t reg_addr;
	enum msm_camera_i2c_reg_addr_type addr_type;
	uint32_t reg_data;
	enum msm_camera_i2c_data_type data_type;
	enum msm_ois_i2c_operation i2c_operation;
	uint32_t delay;
};

struct msm_ois_params_t {
	uint16_t data_size;
	uint16_t setting_size;
	uint32_t i2c_addr;
	enum msm_camera_i2c_reg_addr_type i2c_addr_type;
	enum msm_camera_i2c_data_type i2c_data_type;
	struct reg_settings_ois_t *settings;
};

struct msm_ois_set_info_t {
	struct msm_ois_params_t ois_params;
};
/* <DTS2015073106553 xurenjie xwx208548 20150731 begin */
struct msm_ois_gyrogain_info_t {
	int32_t gyrogainx;//from gyro gain register
	int32_t gyrogainy;
	int32_t towritegyrogainx;// write into gyro gain register
	int32_t towritegyrogainy;
};
/* DTS2015073106553 xurenjie xwx208548 20150731 end > */
/*< DTS2015042007464 ganfan/206212 20150420 begin*/
struct msm_ois_mag_info_t {
    int32_t otpcenX;
    int32_t otpcenY;
    int32_t srvoffX;
    int32_t srvoffY;
};
/*DTS2015042007464 ganfan/206212 20150420 end >*/

struct msm_actuator_move_params_t {
	int8_t dir;
	int8_t sign_dir;
	int16_t dest_step_pos;
	int32_t num_steps;
	uint16_t curr_lens_pos;
	struct damping_params_t *ringing_params;
};

struct msm_actuator_tuning_params_t {
	int16_t initial_code;
	uint16_t pwd_step;
	uint16_t region_size;
	uint32_t total_steps;
	struct region_params_t *region_params;
};

struct park_lens_data_t {
	uint32_t damping_step;
	uint32_t damping_delay;
	uint32_t hw_params;
	uint32_t max_step;
};

struct msm_actuator_params_t {
	enum actuator_type act_type;
	uint8_t reg_tbl_size;
	uint16_t data_size;
	uint16_t init_setting_size;
	uint32_t i2c_addr;
	enum msm_actuator_addr_type i2c_addr_type;
	enum msm_actuator_data_type i2c_data_type;
	struct msm_actuator_reg_params_t *reg_tbl_params;
	struct reg_settings_t *init_settings;
	struct park_lens_data_t park_lens;
};

struct msm_actuator_set_info_t {
	struct msm_actuator_params_t actuator_params;
	struct msm_actuator_tuning_params_t af_tuning_params;
};

struct msm_actuator_get_info_t {
	uint32_t focal_length_num;
	uint32_t focal_length_den;
	uint32_t f_number_num;
	uint32_t f_number_den;
	uint32_t f_pix_num;
	uint32_t f_pix_den;
	uint32_t total_f_dist_num;
	uint32_t total_f_dist_den;
	uint32_t hor_view_angle_num;
	uint32_t hor_view_angle_den;
	uint32_t ver_view_angle_num;
	uint32_t ver_view_angle_den;
};

enum af_camera_name {
	ACTUATOR_MAIN_CAM_0,
	ACTUATOR_MAIN_CAM_1,
	ACTUATOR_MAIN_CAM_2,
	ACTUATOR_MAIN_CAM_3,
	ACTUATOR_MAIN_CAM_4,
	ACTUATOR_MAIN_CAM_5,
	ACTUATOR_WEB_CAM_0,
	ACTUATOR_WEB_CAM_1,
	ACTUATOR_WEB_CAM_2,
};

struct msm_ois_cfg_data {
	int cfgtype;
/*< DTS2015012606635 tangying/205982 20150126 begin*/
/*add camera ois driver*/
    int vendor_id;
/*DTS2015012606635 tangying/205982 20150126 end >*/
	union {
		struct msm_ois_set_info_t set_info;
		struct msm_camera_i2c_seq_reg_setting *settings;
		/*< DTS2015042007464 ganfan/206212 20150420 begin*/
		struct msm_ois_mag_info_t *mag_info;
		/*DTS2015042007464 ganfan/206212 20150420 end >*/
		/* <DTS2015073106553 xurenjie xwx208548 20150731 begin */
		struct msm_ois_gyrogain_info_t *gyro_gain_info;
		/* DTS2015073106553 xurenjie xwx208548 20150731 end > */
	} cfg;
};

struct msm_actuator_set_position_t {
	uint16_t number_of_steps;
	uint16_t pos[MAX_NUMBER_OF_STEPS];
	uint16_t delay[MAX_NUMBER_OF_STEPS];
};

/* < DTS2015021107432 yuguangcai 20150211 begin */
struct msm_actuator_cfg_data {
	int cfgtype;
	uint8_t is_af_supported;
	union {
		struct msm_actuator_move_params_t move;
		struct msm_actuator_set_info_t set_info;
		struct msm_actuator_get_info_t get_info;
		struct msm_actuator_set_position_t setpos;
		enum af_camera_name cam_name;
		uint16_t  vcm_code;
	} cfg;
};
/* DTS2015021107432 yuguangcai 20150211 end > */

enum msm_camera_led_config_t {
	MSM_CAMERA_LED_OFF,
	MSM_CAMERA_LED_LOW,
	MSM_CAMERA_LED_HIGH,
	MSM_CAMERA_LED_INIT,
	MSM_CAMERA_LED_RELEASE,
	/* < DTS2014042700594 yangjiangjun 20140427 begin */
	MSM_CAMERA_LED_TORCH = 16,
	MSM_CAMERA_LED_TORCH_POWER_NORMAL = 32,
	MSM_CAMERA_LED_TORCH_POWER_ABNORMAL,
	/* DTS2014042700594 yangjiangjun 20140427 end > */
	/* < DTS2015071400818 yuguangcai 20150714 begin */
	MSM_CAMERA_LED_CAMERA_ID = 100,
	/* DTS2015071400818 yuguangcai 20150714 end > */
};

/* <DTS2014122607866 zhangbo00166742 20141226 begin */
/*<DTS2015031302796 Zhangbo 20150311 begin*/
typedef enum {
  DUAL_LED_MODE_OFF = 0,
  DUAL_LED_MODE_ON,
  DUAL_LED_MODE_TORCH,
  DUAL_LED_MODE_FLASH,
} dual_flash_led_mode;
/*DTS2015031302796 Zhangbo 20150311 end>*/
/*DTS2014122607866 zhangbo00166742 20141226 end >*/

/* < DTS2015041303206 Zhangbo 20150417 begin */
/*< DTS2015052908526 yanhuiwen 283550 20150529 begin */
typedef enum {
  DUAL_LED_TORCH_DEFAULT = -5, //
  DUAL_LED_TORCH_BOTH,
  DUAL_LED_TORCH_COLD,
  DUAL_LED_TORCH_WARM,
} dual_flash_torch_type_t;
/* DTS2015052908526 yanhuiwen 283550 20150529 end >*/
/* DTS2015041303206 Zhangbo 20150417 end > */

struct msm_camera_led_cfg_t {
	enum msm_camera_led_config_t cfgtype;
	uint32_t torch_current[MAX_LED_TRIGGERS];
	uint32_t flash_current[MAX_LED_TRIGGERS];
	uint32_t flash_duration[MAX_LED_TRIGGERS];
	/* <DTS2014122607866 zhangbo00166742 20141226 begin */
	uint32_t DualLedMode;
	uint32_t CurrentIndex;
	/* < DTS2015041303206 Zhangbo 20150417 begin */
	dual_flash_torch_type_t DfTorchIndex;
	/* DTS2015041303206 Zhangbo 20150417 end > */
	/*DTS2014122607866 zhangbo00166742 20141226 end >*/
	/* < DTS2015071400818 yuguangcai 20150714 begin */
	uint8_t camera_id;
	/* DTS2015071400818 yuguangcai 20150714 end > */
	/* < DTS2015072600584 zhangbo 20150812 begin */
	uint32_t flip_id;
	/* DTS2015072600584 Zhangbo 20150812 end  >*/
};

struct msm_flash_init_info_t {
	enum msm_flash_driver_type flash_driver_type;
	struct msm_sensor_power_setting_array *power_setting_array;
	struct msm_camera_i2c_reg_setting_array *settings;
};

struct msm_flash_cfg_data_t {
	enum msm_flash_cfg_type_t cfg_type;
	uint32_t torch_current;
	uint32_t flash_current[MAX_LED_TRIGGERS];
	uint32_t flash_duration[MAX_LED_TRIGGERS];
	union {
		struct msm_flash_init_info_t *flash_init_info;
		struct msm_camera_i2c_reg_setting_array *settings;
		uint32_t flash_current[MAX_LED_TRIGGERS];
	} cfg;
};

/*< DTS2014111305646 tangying/205982 20141113 begin*/
/*use dtsi get sensor name instead of board id string*/
/* sensor init structures and enums */
enum msm_sensor_init_cfg_type_t {
	CFG_SINIT_PROBE,
	CFG_SINIT_PROBE_DONE,
	CFG_SINIT_PROBE_WAIT_DONE,
	CFG_SINIT_GET_SENSOR_CODE_LIST,
	/* <DTS2015012000269 jwx206032 20150124 begin */
	CFG_SINIT_GET_HW_PRODUCT_NAME,
	/* DTS2015012000269 jwx206032 20150124 end> */
};
/*DTS2014111305646 tangying/205982 20141113 end >*/

struct sensor_init_cfg_data {
	enum msm_sensor_init_cfg_type_t cfgtype;
	struct msm_sensor_info_t        probed_info;
	char                            entity_name[MAX_SENSOR_NAME];
	union {
		void *setting;
	} cfg;
};

/* <DTS2015051109283 jiweifeng/jwx206032 20150515 begin */
struct msm_sensor_afc_otp_info
{
    uint16_t starting_dac;
	uint16_t infinity_dac;
	uint16_t macro_dac;
};

/* < DTS2015042906355 y00294389 20150515 begin */
/* <DTS2015033002251 z00285045 20150413 begin */
struct msm_sensor_awb_otp_info
{
	uint16_t RG;
	uint16_t BG;
	uint32_t typical_RG;
	uint32_t typical_BG;
};
/* DTS2015033002251 z00285045 20150413 end> */
/* DTS2015042906355 y00294389 20150515 end > */

struct msm_sensor_mmi_otp_flag
{
	uint16_t mmi_otp_check_flag;
};
/* DTS2015051109283 jiweifeng/jwx206032 20150515 end> */

#define VIDIOC_MSM_SENSOR_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 1, struct sensorb_cfg_data)

#define VIDIOC_MSM_SENSOR_RELEASE \
	_IO('V', BASE_VIDIOC_PRIVATE + 2)

#define VIDIOC_MSM_SENSOR_GET_SUBDEV_ID \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 3, uint32_t)

#define VIDIOC_MSM_CSIPHY_IO_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 4, struct csiphy_cfg_data)

#define VIDIOC_MSM_CSID_IO_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 5, struct csid_cfg_data)

#define VIDIOC_MSM_ACTUATOR_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 6, struct msm_actuator_cfg_data)

#define VIDIOC_MSM_FLASH_LED_DATA_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 7, struct msm_camera_led_cfg_t)

#define VIDIOC_MSM_EEPROM_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 8, struct msm_eeprom_cfg_data)

#define VIDIOC_MSM_SENSOR_GET_AF_STATUS \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 9, uint32_t)

#define VIDIOC_MSM_SENSOR_INIT_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 10, struct sensor_init_cfg_data)

#define VIDIOC_MSM_OIS_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 11, struct msm_ois_cfg_data)

#define VIDIOC_MSM_FLASH_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 13, struct msm_flash_cfg_data_t)

#ifdef CONFIG_COMPAT
struct msm_camera_i2c_reg_setting32 {
	compat_uptr_t reg_setting;
	uint16_t size;
	enum msm_camera_i2c_reg_addr_type addr_type;
	enum msm_camera_i2c_data_type data_type;
	uint16_t delay;
};

struct msm_actuator_tuning_params_t32 {
	int16_t initial_code;
	uint16_t pwd_step;
	uint16_t region_size;
	uint32_t total_steps;
	compat_uptr_t region_params;
};

struct msm_actuator_params_t32 {
	enum actuator_type act_type;
	uint8_t reg_tbl_size;
	uint16_t data_size;
	uint16_t init_setting_size;
	uint32_t i2c_addr;
	enum msm_actuator_addr_type i2c_addr_type;
	enum msm_actuator_data_type i2c_data_type;
	compat_uptr_t reg_tbl_params;
	compat_uptr_t init_settings;
	struct park_lens_data_t park_lens;
};

struct msm_actuator_set_info_t32 {
	struct msm_actuator_params_t32 actuator_params;
	struct msm_actuator_tuning_params_t32 af_tuning_params;
};

struct sensor_init_cfg_data32 {
	enum msm_sensor_init_cfg_type_t cfgtype;
	struct msm_sensor_info_t        probed_info;
	char                            entity_name[MAX_SENSOR_NAME];
	union {
		compat_uptr_t setting;
	} cfg;
};

struct msm_actuator_move_params_t32 {
	int8_t dir;
	int8_t sign_dir;
	int16_t dest_step_pos;
	int32_t num_steps;
	uint16_t curr_lens_pos;
	compat_uptr_t ringing_params;
};

/* < DTS2015021107432 yuguangcai 20150211 begin */
struct msm_actuator_cfg_data32 {
	int cfgtype;
	uint8_t is_af_supported;
	union {
		struct msm_actuator_move_params_t32 move;
		struct msm_actuator_set_info_t32 set_info;
		struct msm_actuator_get_info_t get_info;
		struct msm_actuator_set_position_t setpos;
		enum af_camera_name cam_name;
		uint16_t  vcm_code;
	} cfg;
};
/* DTS2015021107432 yuguangcai 20150211 end > */

struct csiphy_cfg_data32 {
	enum csiphy_cfg_type_t cfgtype;
	union {
		compat_uptr_t csiphy_params;
		compat_uptr_t csi_lane_params;
	} cfg;
};

struct sensorb_cfg_data32 {
	int cfgtype;
	union {
		struct msm_sensor_info_t      sensor_info;
		struct msm_sensor_init_params sensor_init_params;
		/* < DTS2015020904827 yuguangcai 20150209 begin */
		struct msm_sensor_otp_info otp_info;
		/* DTS2015020904827 yuguangcai 20150209 end > */
		compat_uptr_t                 setting;
	} cfg;
};

struct msm_ois_params_t32 {
	uint16_t data_size;
	uint16_t setting_size;
	uint32_t i2c_addr;
	enum msm_camera_i2c_reg_addr_type i2c_addr_type;
	enum msm_camera_i2c_data_type i2c_data_type;
	compat_uptr_t settings;
};

struct msm_ois_set_info_t32 {
	struct msm_ois_params_t32 ois_params;
};

struct msm_ois_cfg_data32 {
	int cfgtype;
/*< DTS2015012606635 tangying/205982 20150126 begin*/
/*add camera ois driver*/
    int vendor_id;
/*DTS2015012606635 tangying/205982 20150126 end >*/
	union {
		struct msm_ois_set_info_t32 set_info;
		compat_uptr_t settings;
		/*< DTS2015042007464 ganfan/206212 20150420 begin*/
		compat_uptr_t mag_info;
		/*DTS2015042007464 ganfan/206212 20150420 end >*/
		/* <DTS2015073106553 xurenjie xwx208548 20150731 begin */
		compat_uptr_t gyro_gain_info;
		/* DTS2015073106553 xurenjie xwx208548 20150731 end > */
	} cfg;
};

struct msm_flash_init_info_t32 {
	enum msm_flash_driver_type flash_driver_type;
	compat_uptr_t power_setting_array;
	compat_uptr_t settings;
};

struct msm_flash_cfg_data_t32 {
	enum msm_flash_cfg_type_t cfg_type;
	uint32_t torch_current;
	uint32_t flash_current[MAX_LED_TRIGGERS];
	uint32_t flash_duration[MAX_LED_TRIGGERS];
	union {
		compat_uptr_t flash_init_info;
		compat_uptr_t settings;
		uint32_t flash_current[MAX_LED_TRIGGERS];
	} cfg;
};

#define VIDIOC_MSM_ACTUATOR_CFG32 \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 6, struct msm_actuator_cfg_data32)

#define VIDIOC_MSM_SENSOR_INIT_CFG32 \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 10, struct sensor_init_cfg_data32)

#define VIDIOC_MSM_CSIPHY_IO_CFG32 \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 4, struct csiphy_cfg_data32)

#define VIDIOC_MSM_SENSOR_CFG32 \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 1, struct sensorb_cfg_data32)

#define VIDIOC_MSM_EEPROM_CFG32 \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 8, struct msm_eeprom_cfg_data32)

#define VIDIOC_MSM_OIS_CFG32 \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 11, struct msm_ois_cfg_data32)

#define VIDIOC_MSM_CSID_IO_CFG32 \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 5, struct csid_cfg_data32)

#define VIDIOC_MSM_FLASH_CFG32 \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 13, struct msm_flash_cfg_data_t32)
#endif

#endif /* __LINUX_MSM_CAM_SENSOR_H */
