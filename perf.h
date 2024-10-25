/*
 * perf.h
 *
 *  Created on: 13. 3. 2021
 *      Author: polasekm
 */
/*-----------------------------------------------------------------------------*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PERF_PERF_H_
#define PERF_PERF_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdint.h>

#include "tim.h"

/* Exported types ------------------------------------------------------------*/
/**
 * @brief  Performance structure definition
 */
typedef struct
{
  uint32_t time_last;

  uint32_t time_min;
  uint32_t time_max;

  uint64_t time_tot;
  uint64_t time_int;

  uint64_t cnt;

} perf_t;

/**
 * @brief  Performance statistics structure definition
 */
typedef struct
{
  float time_min;
  float time_max;
  float time_avg;
  float time_tot;

  float time_int;

  uint64_t loop_cnt;

} perf_stat_t;

/* Exported functions ------------------------------------------------------- */

/* Defines -------------------------------------------------------------------*/
#define PERF_GET_TICK() __HAL_TIM_GET_COUNTER(&htim5)
#define PERF_SRC_CLK    84000000
// Functions -------------------------------------------------------------------

void perf_init(perf_t *perf);

void perf_start(perf_t *perf);
void perf_end(perf_t *perf);

void perf_eval(perf_t *perf, perf_stat_t *stat);

   //------------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* PERF_PERF_H_ */
