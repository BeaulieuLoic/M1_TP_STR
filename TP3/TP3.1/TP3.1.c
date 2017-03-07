/**
 * @file TP3.1.c
 *
 * @section desc File description
 *
 *
 * @section copyright Copyright
 *
 *
 * @section infos File informations
 *
 * $Date$ mar. févr. 28 16:26:51 CET 2017
 * $Rev$
 * $Author$ 16009989
 * $URL$ /private/student/9/89/16009989/cours/m1/STR/M1_TP_STR/TP3/TP3.1
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
#define port_pare_choc_gauche NXT_PORT_S2
#define port_pare_choc_droite NXT_PORT_S3
#define port_moteur_gauche NXT_PORT_A
#define port_moteur_droite NXT_PORT_B
#define marcheAvant 35
#define marcheArriere -marcheAvant
#define activer_moteur 1

/*
question
Que se passe-t-il si les pare-chocs détectent un obstacle à ras de terre mais que le capteur ultrason est interrogé avant que la tâche de navigation ne s’exécute ?

la variable distance n'est plus égal à 0 
car la distance capter par l'ultrason n'est pas tous à fait 0 
alors que les capteur du par choc son activé


solution :
interdire la tache task_detection_distance d'écrire tant que la tache 
task_detection_contact n'à pas de nouveau été executer

*/

int periode = 0; //periode
int distance = 200; // Distance : c'est la variable partagée
int contacteCapteur = 0; // Activer (1) ou désactive (0) les capteurs pressions

DeclareTask(task_detection_contact);
DeclareTask(task_detection_distance);
DeclareTask(task_navigation);

DeclareAlarm(alarm_contact);
DeclareAlarm(alarm_distance);
DeclareAlarm(alarm_navigation);

DeclareResource(res_distance);
DeclareResource(res_correction);

int rand_0_100(){
  return systick_get_ms() % 101;
}

// Fonction pour activer les moteurs à l'identique
void definirVitesse(int vitesse){
  if (activer_moteur)
  {
    ecrobot_set_motor_speed(port_moteur_gauche, vitesse);
    ecrobot_set_motor_speed(port_moteur_droite, vitesse);
  }
}

// Fonction pour tourner à droite
void tournerRobotDroite(int vitesse){
  if (activer_moteur)
  {
    ecrobot_set_motor_speed(port_moteur_gauche, -vitesse);
    ecrobot_set_motor_speed(port_moteur_droite, vitesse);
  }
}

// Fonction pour tourner à gauche
void tournerRobotGauche(int vitesse){
  if (activer_moteur)
  {
    ecrobot_set_motor_speed(port_moteur_gauche, vitesse);
    ecrobot_set_motor_speed(port_moteur_droite, -vitesse);
  }
}

// Tâche pour gérer la détection d'un contact
// avec gestion des ressources partagées
TASK(task_detection_contact)
{
  if(ecrobot_get_touch_sensor(port_pare_choc_gauche) 
    || ecrobot_get_touch_sensor(port_pare_choc_droite)) {
    
    GetResource(res_correction);
    contacteCapteur = 1;
    ReleaseResource(res_correction);

    GetResource(res_distance);
    distance = 0;
    ReleaseResource(res_distance);
  }else{
    GetResource(res_correction);
    contacteCapteur = 0;
    ReleaseResource(res_correction);
  }
  TerminateTask();
}

// Tâche pour mettre à jour la variable distance en fonction des capte
// Seulement si le capteur ne détecte aucun obstacle
TASK(task_detection_distance)
{
  int distCapteur = ecrobot_get_sonar_sensor(port_ultrason);

  GetResource(res_correction);
  //distance 
  if(!contacteCapteur){
    ReleaseResource(res_correction);
    GetResource(res_distance);
    distance = distCapteur;
    ReleaseResource(res_distance);
  }else{
    ReleaseResource(res_correction);
  }


  TerminateTask();
}

// Tâche qui commande les moteurs en fonction de la distance
// ET du capteur de pression
TASK(task_navigation)
{
  display_clear(0);
  display_goto_xy(0,1);
  display_string("distance : ");
  display_goto_xy(0,2);

  GetResource(res_distance);

  display_int(distance,3);
  display_update();

  
  if(distance == 0){
    ReleaseResource(res_distance);

    display_goto_xy(0,3);
    display_string("distance = 0");
    display_update();
    definirVitesse(marcheArriere);


  }else if(distance < 50){
    ReleaseResource(res_distance);

    tournerRobotGauche(marcheAvant);

    display_goto_xy(0,3);
    display_string("distance < 50");
    display_update();

  }else{
    ReleaseResource(res_distance);
    definirVitesse(marcheAvant);
    if (periode >= 10){
      periode = -1;
      int vitesseRand = (rand_0_100() + 20) % 100;
      int gauche = rand_0_100() % 2;

      display_goto_xy(0,3);
      display_string("periode à 10");
      display_goto_xy(0,4);
      display_int(vitesseRand,3);
      display_update();

      if (gauche){
        tournerRobotGauche(vitesseRand);
      }else{
        tournerRobotDroite(vitesseRand);
      }
    }
  }


  if (periode == 10){
    periode = 0;
  }else{
    periode++;
  }
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

/* End of file TP3.1.c */
