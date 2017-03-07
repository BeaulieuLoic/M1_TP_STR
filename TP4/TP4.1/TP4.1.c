/**
 * @file TP4.1.c
 *
 * @section desc File description
 *
 *
 * @section copyright Copyright
 *
 *
 * @section infos File informations
 *
 * $Date$ mar. mars  7 15:54:59 CET 2017
 * $Rev$
 * $Author$ 16009989
 * $URL$ /private/student/9/89/16009989/cours/m1/STR/M1_TP_STR/TP4/TP4.1
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

#define port_ultrason NXT_PORT_S1
#define port_moteur_gauche NXT_PORT_A
#define port_moteur_droite NXT_PORT_B

#define distanceVoulu 20 // Distance souhaitée
#define distMax 255
#define activer_moteur 1 // Activer (1) ou désactiver (0) moteurs (pour débuguer)

// Distance : c'est la variable partagée
int distance = distanceVoulu;

DeclareTask(task_detection_distance);
DeclareTask(task_navigation);

DeclareAlarm(alarm_distance);
DeclareAlarm(alarm_navigation);

DeclareResource(res_distance);

// Fonction pour activer les moteurs à l'identique
void definirVitesse(int vitesse){
  if (activer_moteur)
  {
    ecrobot_set_motor_speed(port_moteur_gauche, vitesse);
    ecrobot_set_motor_speed(port_moteur_droite, vitesse);
  }
}

// Tâche pour mettre à jour la variable distance en fonction des capteurs
TASK(task_detection_distance)
{
  int distCapteur = ecrobot_get_sonar_sensor(port_ultrason);
  // Récupération de la ressource pour éviter les conflits
  GetResource(res_distance);
  distance = distCapteur;
  ReleaseResource(res_distance);
  TerminateTask();
}

// Tâche qui commande les moteurs en fonction de la distance
TASK(task_navigation)
{
  display_clear(0);

  display_goto_xy(0,1);
  display_string("distance : ");
  display_goto_xy(0,2);

  GetResource(res_distance);

  display_int(distance,3);
  
  // Calcul d'une vitesse proportionnelle en fonction de la distance
  float vitProp = ((float) (distance-distanceVoulu) / (float) (distMax-distanceVoulu) )*100.0; 

  int vitesse = (int) vitProp ;

  // Laisser une marge de +/- 3 de distance car capteur peu précis
  if (distance <= distanceVoulu+3 && distance >= distanceVoulu-3){
    vitesse = 0;
  }

  // Ne pas autoriser une vitesse entre 15 et -15 sinon pas assez de puissance pour bouger
  if (-15 < vitesse && vitesse < 0){
    vitesse = -15;
  }else if (15 > vitesse && vitesse > 0){
    vitesse = 15;
  }


  display_goto_xy(0,3);
  display_string("vitesse : ");
  display_goto_xy(0,4);

  display_int(vitesse,4);
  display_update();

  definirVitesse(vitesse);

  ReleaseResource(res_distance);
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

/* End of file TP4.1.c */
