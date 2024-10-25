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
  perf->time_last = 0;

  perf->time_min = (uint32_t)-1;
  perf->time_max = 0;

  perf->time_tot = 0;
  perf->time_int = 0;

  perf->cnt = 0;
}
//------------------------------------------------------------------------------
void perf_start(perf_t *perf)
{
  uint32_t time, time_diff;

  time      = PERF_GET_TICK();
  time_diff = time - perf->time_last;

  perf->time_last = time;
  perf->time_int += time_diff;
}
//------------------------------------------------------------------------------
void perf_end(perf_t *perf)
{
  uint32_t time, time_diff;

  time      = PERF_GET_TICK();
  time_diff = time - perf->time_last;

  if(time_diff < perf->time_min) perf->time_min = time_diff;
  if(time_diff > perf->time_max) perf->time_max = time_diff;

  perf->time_last = time;
  perf->time_tot += time_diff;
  perf->time_int += time_diff;

  perf->cnt++;
}
//------------------------------------------------------------------------------
void perf_eval(perf_t *perf, perf_stat_t *stat)
{
  float tick;

  // Statistics
  tick = 1.0 / (float)PERF_SRC_CLK;

  stat->time_min = (float)perf->time_min * tick;
  stat->time_max = (float)perf->time_max * tick;
  stat->time_tot = (float)perf->time_tot * tick;
  stat->time_avg = stat->time_tot / (float)perf->cnt;

  stat->time_int = (float)perf->time_int * tick;

  stat->loop_cnt = perf->cnt;

  // Clear
  perf->time_min = (uint32_t)-1;
  perf->time_max = 0;

  perf->time_tot = 0;
  perf->time_int = 0;

  perf->cnt = 0;
}
//------------------------------------------------------------------------------
