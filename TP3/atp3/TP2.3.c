/**
 * @file TP2.3.c
 *
 * @section desc File description
 *
 *
 * @section copyright Copyright
 *
 *
 * @section infos File informations
 *
 * $Date$ mar. févr.  7 18:01:31 CET 2017
 * $Rev$
 * $Author$ 17000416
 * $URL$ /private/student/6/16/17000416/Documents/STR/git/TP2/TP2.3
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
// a copier ---------------------------------------------------------------------------------------------------------------------
int periode = 0;//periode
int distance = 0;

DeclareTask(task_detection_contact);
DeclareTask(task_detection_distance);
DeclareTask(task_navigation);

DeclareAlarm(alarm_contact);
DeclareAlarm(alarm_distance);
DeclareAlarm(alarm_navigation);

DeclareResource(res_distance);

TASK(task_detection_contact)
{



  TerminateTask();
}

TASK(task_detection_distance)
{
  

  TerminateTask();
}

TASK(task_navigation)
{
  GetResource(res_distance);
  if(){// distance  = 0
    ReleaseResource(res_distance);

  }else if(){// distance  < 50
    ReleaseResource(res_distance);

  }else{
    ReleaseResource(res_distance);
    if (periode == 10){
      periode = 0;



    }
  }


  if (periode == 10){
    periode = 0;
  }else{
    periode++;
  }
  TerminateTask();
}
//---------------------------------------------------------------------------------------------------------------------




DeclareTask(task_systime);
DeclareTask(task_pression);
DeclareTask(task_distance);
DeclareTask(task_boutondroit);

DeclareAlarm(alarm_systime);
DeclareAlarm(alarm_pression);
DeclareAlarm(alarm_distance);

DeclareEvent(EvOff);

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

TASK(task_boutondroit)
{

  //SetEvent(task_boutondroit,1);
  WaitEvent(EvOff);

  ShutdownOS(0);


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

    //ecrobot_status_monitor("isr_button_right");
    SetEvent(task_boutondroit, EvOff);

}

/* End of file TP2.3.c */
