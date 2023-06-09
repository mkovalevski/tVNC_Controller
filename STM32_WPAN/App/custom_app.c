/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    App/custom_app.c
  * @author  MCD Application Team
  * @brief   Custom Example Application (Server)
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_common.h"
#include "dbg_trace.h"
#include "ble.h"
#include "custom_app.h"
#include "custom_stm.h"
#include "stm32_seq.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  /* BLE_RX */
  /* BLE_TX */
  uint8_t               Spo2_Notification_Status;
  uint8_t               Heart_rate_Notification_Status;
  uint8_t               Cnap_Notification_Status;
  /* USER CODE BEGIN CUSTOM_APP_Context_t */

  /* USER CODE END CUSTOM_APP_Context_t */

  uint16_t              ConnectionHandle;
} Custom_App_Context_t;

/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private defines ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macros -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/**
 * START of Section BLE_APP_CONTEXT
 */

PLACE_IN_SECTION("BLE_APP_CONTEXT") static Custom_App_Context_t Custom_App_Context;

/**
 * END of Section BLE_APP_CONTEXT
 */

uint8_t UpdateCharData[247];
uint8_t NotifyCharData[247];

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* BLE_RX */
/* BLE_TX */
static void Custom_Spo2_Update_Char(void);
static void Custom_Spo2_Send_Notification(void);
static void Custom_Heart_rate_Update_Char(void);
static void Custom_Heart_rate_Send_Notification(void);
static void Custom_Cnap_Update_Char(void);
static void Custom_Cnap_Send_Notification(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Functions Definition ------------------------------------------------------*/
void Custom_STM_App_Notification(Custom_STM_App_Notification_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_1 */

  /* USER CODE END CUSTOM_STM_App_Notification_1 */
  switch (pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

    /* USER CODE END CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

    /* BLE_RX */
    case CUSTOM_STM_CURRENT_MA_WRITE_EVT:
      /* USER CODE BEGIN CUSTOM_STM_CURRENT_MA_WRITE_EVT */

      /* USER CODE END CUSTOM_STM_CURRENT_MA_WRITE_EVT */
      break;

    case CUSTOM_STM_FREQUENCY_HZ_WRITE_EVT:
      /* USER CODE BEGIN CUSTOM_STM_FREQUENCY_HZ_WRITE_EVT */

      /* USER CODE END CUSTOM_STM_FREQUENCY_HZ_WRITE_EVT */
      break;

    case CUSTOM_STM_PULSE_DUR_US_WRITE_EVT:
      /* USER CODE BEGIN CUSTOM_STM_PULSE_DUR_US_WRITE_EVT */

      /* USER CODE END CUSTOM_STM_PULSE_DUR_US_WRITE_EVT */
      break;

    case CUSTOM_STM_DUR_PER_ON_S_WRITE_EVT:
      /* USER CODE BEGIN CUSTOM_STM_DUR_PER_ON_S_WRITE_EVT */

      /* USER CODE END CUSTOM_STM_DUR_PER_ON_S_WRITE_EVT */
      break;

    case CUSTOM_STM_DUR_PER_OFF_S_WRITE_EVT:
      /* USER CODE BEGIN CUSTOM_STM_DUR_PER_OFF_S_WRITE_EVT */

      /* USER CODE END CUSTOM_STM_DUR_PER_OFF_S_WRITE_EVT */
      break;

    /* BLE_TX */
    case CUSTOM_STM_SPO2_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_SPO2_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_SPO2_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_SPO2_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_SPO2_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_SPO2_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_HEART_RATE_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_HEART_RATE_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_HEART_RATE_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_HEART_RATE_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_HEART_RATE_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_HEART_RATE_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_CNAP_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_CNAP_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_CNAP_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_CNAP_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_CNAP_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_CNAP_NOTIFY_DISABLED_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_STM_App_Notification_default */

      /* USER CODE END CUSTOM_STM_App_Notification_default */
      break;
  }
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_2 */

  /* USER CODE END CUSTOM_STM_App_Notification_2 */
  return;
}

void Custom_APP_Notification(Custom_App_ConnHandle_Not_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_APP_Notification_1 */

  /* USER CODE END CUSTOM_APP_Notification_1 */

  switch (pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_APP_Notification_Custom_Evt_Opcode */

    /* USER CODE END P2PS_CUSTOM_Notification_Custom_Evt_Opcode */
    case CUSTOM_CONN_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_CONN_HANDLE_EVT */

      /* USER CODE END CUSTOM_CONN_HANDLE_EVT */
      break;

    case CUSTOM_DISCON_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_DISCON_HANDLE_EVT */

      /* USER CODE END CUSTOM_DISCON_HANDLE_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_APP_Notification_default */

      /* USER CODE END CUSTOM_APP_Notification_default */
      break;
  }

  /* USER CODE BEGIN CUSTOM_APP_Notification_2 */

  /* USER CODE END CUSTOM_APP_Notification_2 */

  return;
}

void Custom_APP_Init(void)
{
  /* USER CODE BEGIN CUSTOM_APP_Init */

  /* USER CODE END CUSTOM_APP_Init */
  return;
}

/* USER CODE BEGIN FD */

/* USER CODE END FD */

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/

/* BLE_RX */
/* BLE_TX */
void Custom_Spo2_Update_Char(void) /* Property Read */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Spo2_UC_1*/

  /* USER CODE END Spo2_UC_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_SPO2, (uint8_t *)UpdateCharData);
  }

  /* USER CODE BEGIN Spo2_UC_Last*/

  /* USER CODE END Spo2_UC_Last*/
  return;
}

void Custom_Spo2_Send_Notification(void) /* Property Notification */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Spo2_NS_1*/

  /* USER CODE END Spo2_NS_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_SPO2, (uint8_t *)NotifyCharData);
  }

  /* USER CODE BEGIN Spo2_NS_Last*/

  /* USER CODE END Spo2_NS_Last*/

  return;
}

void Custom_Heart_rate_Update_Char(void) /* Property Read */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Heart_rate_UC_1*/

  /* USER CODE END Heart_rate_UC_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_HEART_RATE, (uint8_t *)UpdateCharData);
  }

  /* USER CODE BEGIN Heart_rate_UC_Last*/

  /* USER CODE END Heart_rate_UC_Last*/
  return;
}

void Custom_Heart_rate_Send_Notification(void) /* Property Notification */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Heart_rate_NS_1*/

  /* USER CODE END Heart_rate_NS_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_HEART_RATE, (uint8_t *)NotifyCharData);
  }

  /* USER CODE BEGIN Heart_rate_NS_Last*/

  /* USER CODE END Heart_rate_NS_Last*/

  return;
}

void Custom_Cnap_Update_Char(void) /* Property Read */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Cnap_UC_1*/

  /* USER CODE END Cnap_UC_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_CNAP, (uint8_t *)UpdateCharData);
  }

  /* USER CODE BEGIN Cnap_UC_Last*/

  /* USER CODE END Cnap_UC_Last*/
  return;
}

void Custom_Cnap_Send_Notification(void) /* Property Notification */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Cnap_NS_1*/

  /* USER CODE END Cnap_NS_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_CNAP, (uint8_t *)NotifyCharData);
  }

  /* USER CODE BEGIN Cnap_NS_Last*/

  /* USER CODE END Cnap_NS_Last*/

  return;
}

/* USER CODE BEGIN FD_LOCAL_FUNCTIONS*/

/* USER CODE END FD_LOCAL_FUNCTIONS*/
