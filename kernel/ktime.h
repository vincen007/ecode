#ifndef __KTIME_H__
#define __KTIME_H__
#include "../global/include.h"

#ifdef __cplusplus
extern "C"{
#endif
    

#if CONFIG_USING_RTOS==1
#define KERNEL_HZ       configTICK_RATE_HZ
#else
#ifndef KERNEL_HZ
#define KERNEL_HZ       200
#endif
#endif



#define kernel_time_after(unknow, known)    ((long)(know)-(long)(unknow)<0)
#define kernel_time_before(unknow, know)    ((long)(unknow)-(long)(know)<0)
#define kernel_time_after_eq(unknow, know)  ((long)(unknow)-(long)(know)>=0)
#define kernel_time_before_eq(unknow, know) ((long)(know)-(long)(unknow)>=0)
    
/**
  * @brief This function is used to update wall jiffies.
  * @retval None
  */
void kernel_update_wall_jiffies(void);

/**
  * @brief This function is used to get kernel timeval.
  * @param tv_val: destination to save timeval.
  * @retval 0: ok, -1: failed.
  */
int kernel_gettime(kernel_timeval_t *tv_val);

/**
  * @brief This function is used to get kernel kernel millisecond time.
  * @retval milliseconds of kernel.
  */
kernel_msec_t kernel_get_millis(void);

/**
  * @brief This function is used to get kernel kernel second time.
  * @retval seconds of kernel.
  */
kernel_sec_t kernel_get_second(void);

/**
  * @brief This function is used to delay milliseconds.
  * @param milliseconds to delay.
  * @retval None.
  */
void kernel_delay_ms(kernel_msec_t millis);

/**
  * @brief This function is used to sleep milliseconds.
  * @param millis milliseconds to sleep.
  * @retval None.
  */
void kernel_sleep_ms(kernel_msec_t millis);

/**
  * @brief This function is used to sleep seconds.
  * @param seconds to sleep.
  * @retval None.
  */
void kernel_sleep(kernel_sec_t sec);
#ifdef __cplusplus
}
#endif

#endif