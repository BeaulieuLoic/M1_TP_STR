/**
 * @file TP1.c
 *
 * @section desc File description
 *
 *
 * @section copyright Copyright
 *
 *
 * @section infos File informations
 *
 * $Date$ mar. janv. 31 17:00:19 CET 2017
 * $Rev$
 * $Author$ 17000416
 * $URL$ /private/student/6/16/17000416/Documents/STR/git/TP1
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

DeclareTask(task1);

TASK(task1)
{
    //ecrobot_status_monitor("NXT task1!");
    TaskType callingTask;
    GetTaskID(&callingTask);

    display_goto_xy(0,2);
    display_string("tache ");
    display_int(callingTask,1);
    display_string(" : bonjour");
    display_update();

    //while(1){
    //};

    //ChainTask(task1);
    TerminateTask();
}

void PreTaskHook() {
  TaskType callingTask;
  GetTaskID(&callingTask);

  display_goto_xy(0,0);
  display_string("tache ");
  display_int(callingTask,1);
  display_string(" : PreTaskHook");
  //display_clear(1);
  display_update();
}

void PostTaskHook() {
  TaskType callingTask;
  GetTaskID(&callingTask);

  display_goto_xy(0,4);
  display_string("tache ");
  display_int(callingTask,1);
  display_string(" : PostTaskHook");
  display_update();
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

/* End of file TP1.c */
