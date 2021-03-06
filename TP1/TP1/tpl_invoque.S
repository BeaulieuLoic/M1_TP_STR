/**
 * @file tpl_invoque.S
 *
 * @section descr File description
 *
 * System call user level invoque API.
 *
 * @warning this file is generated by gen_invoque.sh based on the 
 * tpl_os_service_ids.h header file.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $$Date$$
 * $$Rev$$
 * $$Author$$
 * $$URL$$
 */
#include "tpl_os_application_def.h"
#include "tpl_service_ids.h"

#if WITH_SYSTEM_CALL == NO
#error "This file should not be part of your project since WITH_SYSTEM_CALL is not defined"
#endif


#if WITH_MEMMAP == NO
.text
.code 32
.align 2

#endif /* WITH_MEMMAP == NO */

#define API_START_SEC_CODE
#include "tpl_as_memmap.h"

  .global ActivateTask
ActivateTask:
  push {lr}
  mov r3,#OSServiceId_ActivateTask
  swi #OSServiceId_ActivateTask
  pop {lr}
  mov pc,lr

  .global TerminateTask
TerminateTask:
  push {lr}
  mov r3,#OSServiceId_TerminateTask
  swi #OSServiceId_TerminateTask
  pop {lr}
  mov pc,lr

  .global ChainTask
ChainTask:
  push {lr}
  mov r3,#OSServiceId_ChainTask
  swi #OSServiceId_ChainTask
  pop {lr}
  mov pc,lr

  .global Schedule
Schedule:
  push {lr}
  mov r3,#OSServiceId_Schedule
  swi #OSServiceId_Schedule
  pop {lr}
  mov pc,lr

  .global GetTaskID
GetTaskID:
  push {lr}
  mov r3,#OSServiceId_GetTaskID
  swi #OSServiceId_GetTaskID
  pop {lr}
  mov pc,lr

  .global GetTaskState
GetTaskState:
  push {lr}
  mov r3,#OSServiceId_GetTaskState
  swi #OSServiceId_GetTaskState
  pop {lr}
  mov pc,lr

  .global EnableAllInterrupts
EnableAllInterrupts:
  push {lr}
  mov r3,#OSServiceId_EnableAllInterrupts
  swi #OSServiceId_EnableAllInterrupts
  pop {lr}
  mov pc,lr

  .global DisableAllInterrupts
DisableAllInterrupts:
  push {lr}
  mov r3,#OSServiceId_DisableAllInterrupts
  swi #OSServiceId_DisableAllInterrupts
  pop {lr}
  mov pc,lr

  .global ResumeAllInterrupts
ResumeAllInterrupts:
  push {lr}
  mov r3,#OSServiceId_ResumeAllInterrupts
  swi #OSServiceId_ResumeAllInterrupts
  pop {lr}
  mov pc,lr

  .global SuspendAllInterrupts
SuspendAllInterrupts:
  push {lr}
  mov r3,#OSServiceId_SuspendAllInterrupts
  swi #OSServiceId_SuspendAllInterrupts
  pop {lr}
  mov pc,lr

  .global ResumeOSInterrupts
ResumeOSInterrupts:
  push {lr}
  mov r3,#OSServiceId_ResumeOSInterrupts
  swi #OSServiceId_ResumeOSInterrupts
  pop {lr}
  mov pc,lr

  .global SuspendOSInterrupts
SuspendOSInterrupts:
  push {lr}
  mov r3,#OSServiceId_SuspendOSInterrupts
  swi #OSServiceId_SuspendOSInterrupts
  pop {lr}
  mov pc,lr

  .global GetResource
GetResource:
  push {lr}
  mov r3,#OSServiceId_GetResource
  swi #OSServiceId_GetResource
  pop {lr}
  mov pc,lr

  .global ReleaseResource
ReleaseResource:
  push {lr}
  mov r3,#OSServiceId_ReleaseResource
  swi #OSServiceId_ReleaseResource
  pop {lr}
  mov pc,lr

  .global SetEvent
SetEvent:
  push {lr}
  mov r3,#OSServiceId_SetEvent
  swi #OSServiceId_SetEvent
  pop {lr}
  mov pc,lr

  .global ClearEvent
ClearEvent:
  push {lr}
  mov r3,#OSServiceId_ClearEvent
  swi #OSServiceId_ClearEvent
  pop {lr}
  mov pc,lr

  .global GetEvent
GetEvent:
  push {lr}
  mov r3,#OSServiceId_GetEvent
  swi #OSServiceId_GetEvent
  pop {lr}
  mov pc,lr

  .global WaitEvent
WaitEvent:
  push {lr}
  mov r3,#OSServiceId_WaitEvent
  swi #OSServiceId_WaitEvent
  pop {lr}
  mov pc,lr

  .global GetAlarmBase
GetAlarmBase:
  push {lr}
  mov r3,#OSServiceId_GetAlarmBase
  swi #OSServiceId_GetAlarmBase
  pop {lr}
  mov pc,lr

  .global GetAlarm
GetAlarm:
  push {lr}
  mov r3,#OSServiceId_GetAlarm
  swi #OSServiceId_GetAlarm
  pop {lr}
  mov pc,lr

  .global SetRelAlarm
SetRelAlarm:
  push {lr}
  mov r3,#OSServiceId_SetRelAlarm
  swi #OSServiceId_SetRelAlarm
  pop {lr}
  mov pc,lr

  .global SetAbsAlarm
SetAbsAlarm:
  push {lr}
  mov r3,#OSServiceId_SetAbsAlarm
  swi #OSServiceId_SetAbsAlarm
  pop {lr}
  mov pc,lr

  .global CancelAlarm
CancelAlarm:
  push {lr}
  mov r3,#OSServiceId_CancelAlarm
  swi #OSServiceId_CancelAlarm
  pop {lr}
  mov pc,lr

  .global GetActiveApplicationMode
GetActiveApplicationMode:
  push {lr}
  mov r3,#OSServiceId_GetActiveApplicationMode
  swi #OSServiceId_GetActiveApplicationMode
  pop {lr}
  mov pc,lr

  .global tpl_start_os
tpl_start_os:
  push {lr}
  mov r3,#OSServiceId_StartOS
  swi #OSServiceId_StartOS
  pop {lr}
  mov pc,lr

  .global ShutdownOS
ShutdownOS:
  push {lr}
  mov r3,#OSServiceId_ShutdownOS
  swi #OSServiceId_ShutdownOS
  pop {lr}
  mov pc,lr

  .global CallTerminateTask
CallTerminateTask:
  push {lr}
  mov r3,#OSServiceId_CallTerminateTask
  swi #OSServiceId_CallTerminateTask
  pop {lr}
  mov pc,lr

  .global CallTerminateISR2
CallTerminateISR2:
  push {lr}
  mov r3,#OSServiceId_CallTerminateISR2
  swi #OSServiceId_CallTerminateISR2
  pop {lr}
  mov pc,lr



#define API_STOP_SEC_CODE
#include "tpl_as_memmap.h"


/* End of file tpl_invoque. S */

