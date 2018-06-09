# LabASD
Raccolta di soluzioni ad esercizi di laboratorio che nel tempo si trasformerà in libreria di funzioni di base per manipolare strutture dati.

## Utilizzo
#### 1. con un IDE
  * Il file .h della libreria che si intende utilizzare deve essere incluso nel file main del progetto con l'istruzione #include "esempio.h" e si può spostare nella stessa directory di questo.
  
  * Il file .c della stessa libreria deve essere incluso nel progetto attraverso le modalità previste dall'IDE. Non è importante la sua posizione purché questa non cambi dopo l'inclusione.
#### 2. da linea di comando
  * Il file .h deve essere incluso in ognuno dei source files che utilizzano funzioni al suo interno. La posizione del file deve essere o una di quelle di deafult (all'interno della directory include del compilatore o nella directory corrente quando si lancia il comando di compilazione) oppure si può specificare. Con compilatore GNU la flag -I <directory> specifica le directory dove cercare i file header. <directory> deve essere unò o più path assoluti o relativi verso directory all'interno del file system.

  * Il file .c deve essere mandato in compilazione insieme a ogni altro source file necessario utilizzando il suo path assoluto o relativo rispetto alla directory da dove viene lanciato il comando di compilazione.
