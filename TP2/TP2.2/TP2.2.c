/**
 * @file TP2.2.c
 *
 * @section desc File description
 *
 *
 * @section copyright Copyright
 *
 *
 * @section infos File informations
 *
 * $Date$ mar. févr.  7 17:29:09 CET 2017
 * $Rev$
 * $Author$ 17000416
 * $URL$ /private/student/6/16/17000416/Documents/STR/git/TP2/TP2.2
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

DeclareTask(task_systime);
DeclareTask(task_pression);
DeclareTask(task_distance);

DeclareAlarm(alarm_systime);
DeclareAlarm(alarm_pression);
DeclareAlarm(alarm_distance);

TASK(task_systime)
{
  //display_clear(0);
  display_goto_xy(0,0);
  display_int(systick_get_ms(),15);
  display_update();
  TerminateTask();
}

TASK(task_pression)
{
   //
  display_goto_xy(0,1);
  display_string("Pression : ");
  display_int(ecrobot_get_touch_sensor(NXT_PORT_S1),1);
  display_string(" - ");
  display_int(ecrobot_get_touch_sensor(NXT_PORT_S3),1);
  display_update();
  TerminateTask();
}

TASK(task_distance)
{
  display_goto_xy(0,2);
  display_string("Distance : ");
  display_int(ecrobot_get_sonar_sensor(NXT_PORT_S2),3);
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

/* End of file TP2.2.c */
