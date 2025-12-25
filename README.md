# 2526_ESE_AAA_DEL_RIO_CISNEROS_CONTION


## 6. Commande MCC basique

### 6.1 Génération de 4 PWM

On a fait les configurations pour générer les 4 PWM:

<img width="689" height="467" alt="image" src="https://github.com/user-attachments/assets/a462f734-ae4f-4fae-b417-bb7d95b5421e" />

Temps mort de 150 ns:

<img width="557" height="230" alt="image" src="https://github.com/user-attachments/assets/88581902-c15d-451c-a694-af7a31db25ba" />


On a vérifé qu'on peut générer les 4 PWM.

<img width="800" height="480" alt="tek00000" src="https://github.com/user-attachments/assets/f1ddcc43-1583-480d-ba69-bc4602745b76" />

### 6.2 Commande de vitesse

On a écrit la function pour la commande de vitesse : 

```
void motor_set_ccr(int duty_cycle)
{
	CCR1 = (htim1.Init.Period * duty_cycle)/PERCENTAGE_DIVIDER;
	CCR2 = htim1.Init.Period - CCR1;

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, CCR1);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, CCR2);
}
```

### 6.3 Premiers tests

On a testé le code avec le moteur.

## 7. Commande en boucle ouverte, mesure de Vitesse et de courant

### 7.2. Mesure de courant

Les currents à mésurer sont à la sortie des capteurs GO 10-SME.

Définir les fonctions de transfert des capteurs de mesure de courant: I = 1,65 + 0,05xImes.

Les pin du stm32 utilisés pour faire ces mesures de courant sont: PA1 -> ADC1_IN2, PB1 -> ADC1_IN12.

Pour la mesure ADC en Polling mode, nous avons eu des problèmes avec la carte : nous avons mésuré 4095 comme la valeur du ADC avec la carte que nous avons travaillé : 

<img width="220" height="270" alt="image" src="https://github.com/user-attachments/assets/327f1fa8-6dd2-462f-9874-e5ef74468157" />

Par contre, nous avons testé notre code avec d'autre carte et la valeur a été 1850.
