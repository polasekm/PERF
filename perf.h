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

/* Exported types ------------------------------------------------------------*/
/**
 * @brief  Ring buffer structure definition
 */
typedef struct
{
  uint32_t cnt;
  uint32_t cnt_int;

  uint32_t time_start;

  uint32_t time_diff;
  uint32_t time_min;
  uint32_t time_max;
  float time_avg;

  uint32_t time_min_int;
  uint32_t time_max_int;

} perf_t;

/* Exported functions ------------------------------------------------------- */

/* Defines -------------------------------------------------------------------*/
#define PERF_GET_TICK() (htim2.Instance->CNT)
// Functions -------------------------------------------------------------------

void perf_init(perf_t *perf);

void perf_start(perf_t *perf);
void perf_end_start(perf_t *perf);
void perf_end(perf_t *perf);

void perf_int_proc(perf_t *perf);

   //------------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* PERF_PERF_H_ */
