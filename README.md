# 2526_ESE_AAA_DEL_RIO_CISNEROS_CONTION


## 6. Commande MCC basique

On a écrit les fonctions pour le moteur.

### 6.1 Génération de 4 PWM

On a vérifé qu'on peut générer les 4 PWM.

**IMAGE DES 4 PWM ET TEMPS MORT**

### 6.3 Premiers tests

On a testé le code avec le moteur.

## 7. Commande en boucle ouverte, mesure de Vitesse et de courant

### 7.2. Mesure de courant

Les currents à mésurer sont à la sortie des capteurs GO 10-SME.

Définir les fonctions de transfert des capteurs de mesure de courant: I = 1,65 + 0,05xImes.

Les pin du stm32 utilisés pour faire ces mesures de courant sont: PA1 -> ADC1_IN2, PB1 -> ADC1_IN12.
