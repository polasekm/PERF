/*
 * perf.c
 *
 *  Created on: 13. 3. 2021
 *      Author: polasekm
 */
//------------------------------------------------------------------------------
#include "perf.h"

#include "tim.h"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void perf_init(perf_t *perf)
{
  perf->cnt = 0;
  perf->cnt_int = 0;

  perf->time_start = PERF_GET_TICK();//htim2.Instance->CNT;

  perf->time_diff = 0;
  perf->time_min = 0;
  perf->time_max = 0;
  perf->time_avg = 0;

  perf->time_min_int = 0;
  perf->time_max_int = 0;
}
//------------------------------------------------------------------------------
void perf_start(perf_t *perf)
{
  perf->time_start = PERF_GET_TICK();//htim2.Instance->CNT;
  perf->cnt++;
}
//------------------------------------------------------------------------------
void perf_end_start(perf_t *perf)
{
  perf_end(perf);
  perf_start(perf);
}
//------------------------------------------------------------------------------
void perf_end(perf_t *perf)
{
  perf->time_diff = PERF_GET_TICK() - perf->time_start;

  if(perf->time_diff < perf->time_min) perf->time_min = perf->time_diff;
  if(perf->time_diff > perf->time_max) perf->time_max = perf->time_diff;

  perf->time_avg += (float)perf->time_diff * 0.001 - perf->time_avg * 0.001;
}
//------------------------------------------------------------------------------
void perf_int_proc(perf_t *perf)
{
  perf->cnt_int = perf->cnt;
  perf->cnt = 0;

  perf->time_min_int = perf->time_min;
  perf->time_min = perf->time_avg;

  perf->time_max_int = perf->time_max;
  perf->time_max = perf->time_avg;
}
//------------------------------------------------------------------------------
