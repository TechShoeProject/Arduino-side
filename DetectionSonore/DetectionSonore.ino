// Déclaration et initialisation des broches d'entrées
int Analog_Eingang = A0; // Entrée analogique
int Digital_Eingang = 3; // Entrée digitale
  
void setup ()
{
  pinMode (Analog_Eingang, INPUT);
  pinMode (Digital_Eingang, INPUT);
       
  Serial.begin (9600); // Sortie série à 9600 bauds
}
  
// Le programme lit les valeurs des broches d'entrée et les envoie à la sortie série
void loop ()
{
  float Analog;
  int Digital;
    
  //Les valeurs sont lues, sont converties en tension...
  Analog = analogRead (Analog_Eingang) ; 
  Digital = digitalRead (Digital_Eingang);
    
  //... et envoyées à la sortie série.
  Serial.print ("Tension analogique:"); Serial.print (Analog, 4);  Serial.print ("V, ");
  Serial.print ("Limite:");
  
  if(Digital==1)
  {
      Serial.println (" atteinte");
  }
  else
  {
      Serial.println (" pas encore atteinte");
  }
//delay(200);
}
