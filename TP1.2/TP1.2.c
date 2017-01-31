/**
 * @file TP1.2.c
 *
 * @section desc File description
 *
 *
 * @section copyright Copyright
 *
 *
 * @section infos File informations
 *
 * $Date$ mar. janv. 31 18:06:43 CET 2017
 * $Rev$
 * $Author$ 17000416
 * $URL$ /private/student/6/16/17000416/Documents/STR/git/TP1.2
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

DeclareTask(task0);
DeclareTask(task1);

TASK(task0)
{
    ecrobot_status_monitor("NXT task0!");

    while(1){
    };

    ChainTask(task1);
}


TASK(task1)
{
    ecrobot_status_monitor("NXT task1!");

    while(1){
    };

    ChainTask(task1);
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

/* End of file TP1.2.c */
