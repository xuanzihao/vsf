/*****************************************************************************
 *   Copyright(C)2009-2019 by VSF Team                                       *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/

#ifndef __VSF_ARCH_ABSTRACTION_H__
#define __VSF_ARCH_ABSTRACTION_H__

/*============================ INCLUDES ======================================*/
#include "hal/vsf_hal_cfg.h"

#if !defined(VSF_ARCH_HEADER)
# if      defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M'
#   define VSF_ARCH_HEADER      "./arm/cortex-m/cortex_m_generic.h"
# elif    defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'A'
#   define VSF_ARCH_HEADER      "./arm/cortex-m/cortex_a_generic.h"
# elif   defined(__CPU_PC__) && __IS_COMPILER_MSVC__
#   define  VSF_ARCH_HEADER     "./pc/win32/win32_generic.h"
# else
#   error no supported architecture found!
# endif
#endif

#include VSF_ARCH_HEADER

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
typedef void vsf_swi_hanler_t(void *p);

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/


/*! \brief initialise SysTick to generate a system timer
 *! \param frequency the target frequency in Hz
 *! \return initialization result in vsf_err_t 
 */
extern vsf_err_t vsf_systimer_init(uint32_t frequency);

/*! \brief initialise a software interrupt
 *! \param idx the index of the software interrupt
 *! \return initialization result in vsf_err_t
 */
extern vsf_err_t vsf_swi_init(uint_fast8_t idx, uint_fast8_t priority,
        vsf_swi_hanler_t *handler, void *p);

/*! \brief trigger a software interrupt
 *! \param idx the index of the software interrupt
 */
extern void vsf_swi_trigger(uint_fast8_t idx);

extern istate_t vsf_set_base_priority(istate_t priority);

extern ALWAYS_INLINE void vsf_arch_set_pc(uint32_t pc);
extern ALWAYS_INLINE uint32_t vsf_arch_get_lr(void);
extern ALWAYS_INLINE void vsf_arch_set_stack(uint32_t stack);

extern istate_t vsf_get_interrupt(void);
extern void vsf_set_interrupt(istate_t level);
extern istate_t vsf_disable_interrupt(void);
extern void vsf_enable_interrupt(void);

extern void vsf_arch_sleep(uint32_t mode);

#endif
/* EOF */