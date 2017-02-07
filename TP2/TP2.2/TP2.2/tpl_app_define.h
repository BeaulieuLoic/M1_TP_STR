/**
 * @file tpl_app_define.h
 *
 * @section desc File description
 *
 * Header of the automatic generated defines usable
 * by the application test
 * Automatically generated by goil on Tue Feb  7 17:58:16 2017
 * from root OIL file TP2.2.oil
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2010
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_APP_DEFINE_H
#define TPL_APP_DEFINE_H

#include "tpl_config_def.h"

/*=============================================================================
 * Configuration flags
 */
#define TARGET_ARCH                      ARCH_ARM
#define WITH_OS_EXTENDED                 YES
#define WITH_STARTUP_HOOK                NO
#define WITH_SHUTDOWN_HOOK               NO
#define WITH_ERROR_HOOK                  NO
#define WITH_PRE_TASK_HOOK               NO
#define WITH_POST_TASK_HOOK              NO
#define WITH_USEGETSERVICEID             NO
#define WITH_USEPARAMETERACCESS          NO
#define WITH_USERESSCHEDULER             NO
#define WITH_SYSTEM_CALL                 YES
#define WITH_MEMORY_PROTECTION           NO
#define WITH_MEMMAP                      YES
#define WITH_COMPILER_SETTINGS           YES
#define TRAMPOLINE_BASE_PATH             "/private/student/6/16/17000416/Documents/STR/git/../osek_env/trampoline/"
#define WITH_AUTOSAR                     NO
#define WITH_PROTECTION_HOOK             NO
#define WITH_STACK_MONITORING            NO
/* #define WITH_AUTOSAR_TIMING_PROTECTION NO */
#define AUTOSAR_SC                       0
#define WITH_OSAPPLICATION               NO
#define WITH_OSAPPLICATION_STARTUP_HOOK  NO
#define WITH_OSAPPLICATION_SHUTDOWN_HOOK NO
#define WITH_TRACE                       NO
#define WITH_IT_TABLE                    YES
#define WITH_COM                         NO

/*=============================================================================
 * Number of objects used by the application
 * These informations are used by Trampoline to avoid to
 * alloc structures when some os objects are not present.
 */

/*-----------------------------------------------------------------------------
 * Number of priority levels
 */
#define PRIO_LEVEL_COUNT       3

/*-----------------------------------------------------------------------------
 * Number of tasks
 */
#define TASK_COUNT             3

/*-----------------------------------------------------------------------------
 * Number of extended tasks
 */
#define EXTENDED_TASK_COUNT    0

/*-----------------------------------------------------------------------------
 * Number of ISR2
 */
#define ISR_COUNT              4

/*-----------------------------------------------------------------------------
 * Number of alarms
 */
#define ALARM_COUNT            3

/*-----------------------------------------------------------------------------
 * Number of regular resources (standard and linked) plus RES_SCHEDULER
 */
#define RESOURCE_COUNT         1

/*-----------------------------------------------------------------------------
 * Number of messages
 */
#define MESSAGE_COUNT          0

/*-----------------------------------------------------------------------------
 * Number of send messages
 */
#define SEND_MESSAGE_COUNT     0

/*-----------------------------------------------------------------------------
 * Number of receive messages
 */
#define RECEIVE_MESSAGE_COUNT  0



/*-----------------------------------------------------------------------------
 * Priority of RES_SCHEDULER
 */
#define RES_SCHEDULER_PRIORITY 1

#endif

#include "tpl_config_check.h"

/* End of file TPL_APP_DEFINE_H */

