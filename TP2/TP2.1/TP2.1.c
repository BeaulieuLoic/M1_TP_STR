/**
 * @file TP2.1.c
 *
 * @section desc File description
 *
 *
 * @section copyright Copyright
 *
 *
 * @section infos File informations
 *
 * $Date$ mar. févr.  7 16:22:22 CET 2017
 * $Rev$
 * $Author$ 17000416
 * $URL$ /private/student/6/16/17000416/Documents/STR/git/TP2/TP2.1
 */

#include "tpl_os.h"
#include "nxt_motors.h"
#include "ecrobot_interface.h"
#include "ecrobot_private.h"

FUNC(int, OS_APPL_CODE) main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    ShutdownOS(E_OK);
    return 0;
}

//DeclareTask(task0); // Q1.1
//DeclareTask(task1); // Q1.1 et 1.2
DeclareTask(task2); // Q1.3
DeclareAlarm(alarm1); // Q1.1 et 1.3
//DeclareAlarm(alarm1_2); //question 1.2

//question 1.1
/*TASK(task0)
{
  //SetAbsAlarm(alarm1,0,1000);
  TerminateTask();
}*/

//question 1.1 et 1.2
/*TASK(task1)
{
  TaskType callingTask;
  GetTaskID(&callingTask);

  display_clear(0);
  display_goto_xy(0,0);
  display_string("tache ");
  display_int(callingTask,1);
  display_goto_xy(0,1);
  display_int(systick_get_ms(),15);

  display_update();
  TerminateTask();
}*/

//question 1.3
TASK(task2)
{
  SetRelAlarm(alarm1,1000,0);
  TaskType callingTask;
  GetTaskID(&callingTask);

  display_clear(0);
  display_goto_xy(0,0);
  display_string("tache ");
  display_int(callingTask,1);
  display_goto_xy(0,1);
  display_int(systick_get_ms(),15);

  display_update();

  TerminateTask();
}



ISR(isr_button_start)
{
    ecrobot_status_monitor("isr_button_start");

}

ISR(isr_button_stop)
{
    ShutdownOS(E_OK);
}

ISR(isr_button_left)
{
    ecrobot_status_monitor("isr_button_left");

}

ISR(isr_button_right)
{
    ecrobot_status_monitor("isr_button_right");

}

/* End of file TP2.1.c */
