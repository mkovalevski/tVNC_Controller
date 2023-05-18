/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    App/custom_stm.h
  * @author  MCD Application Team
  * @brief   Header for custom_stm.c module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CUSTOM_STM_H
#define __CUSTOM_STM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
typedef enum
{
  /* BLE_RX */
  CUSTOM_STM_CURRENT_MA,
  CUSTOM_STM_FREQUENCY_HZ,
  CUSTOM_STM_PULSE_DUR_US,
  CUSTOM_STM_DUR_PER_ON_S,
  CUSTOM_STM_DUR_PER_OFF_S,
  /* BLE_TX */
  CUSTOM_STM_SPO2,
  CUSTOM_STM_HEART_RATE,
  CUSTOM_STM_CNAP,
} Custom_STM_Char_Opcode_t;

typedef enum
{
  /* CURRENT_mA */
  CUSTOM_STM_CURRENT_MA_WRITE_EVT,
  /* FREQUENCY_Hz */
  CUSTOM_STM_FREQUENCY_HZ_WRITE_EVT,
  /* PULSE_DUR_uS */
  CUSTOM_STM_PULSE_DUR_US_WRITE_EVT,
  /* DUR_PER_ON_S */
  CUSTOM_STM_DUR_PER_ON_S_WRITE_EVT,
  /* DUR_PER_OFF_S */
  CUSTOM_STM_DUR_PER_OFF_S_WRITE_EVT,
  /* SpO2 */
  CUSTOM_STM_SPO2_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_SPO2_NOTIFY_DISABLED_EVT,
  /* HEART_RATE */
  CUSTOM_STM_HEART_RATE_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_HEART_RATE_NOTIFY_DISABLED_EVT,
  /* CNAP */
  CUSTOM_STM_CNAP_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_CNAP_NOTIFY_DISABLED_EVT,

  CUSTOM_STM_BOOT_REQUEST_EVT
} Custom_STM_Opcode_evt_t;

typedef struct
{
  uint8_t * pPayload;
  uint8_t   Length;
} Custom_STM_Data_t;

typedef struct
{
  Custom_STM_Opcode_evt_t       Custom_Evt_Opcode;
  Custom_STM_Data_t             DataTransfered;
  uint16_t                      ConnectionHandle;
  uint8_t                       ServiceInstance;
} Custom_STM_App_Notification_evt_t;

/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
extern uint8_t SizeCurrent_Ma;
extern uint8_t SizeFrequency_Hz;
extern uint8_t SizePulse_Dur_Us;
extern uint8_t SizeDur_Per_On_S;
extern uint8_t SizeDur_Per_Off_S;
extern uint8_t SizeSpo2;
extern uint8_t SizeHeart_Rate;
extern uint8_t SizeCnap;

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macros -----------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions ------------------------------------------------------- */
void SVCCTL_InitCustomSvc(void);
void Custom_STM_App_Notification(Custom_STM_App_Notification_evt_t *pNotification);
tBleStatus Custom_STM_App_Update_Char(Custom_STM_Char_Opcode_t CharOpcode,  uint8_t *pPayload);
/* USER CODE BEGIN EF */

/* USER CODE END EF */

#ifdef __cplusplus
}
#endif

#endif /*__CUSTOM_STM_H */
