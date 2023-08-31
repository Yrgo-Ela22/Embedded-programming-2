# 2023-08-31 - Flertrådning med pthread
Demonstration av flertrådning via pthread i C samt C++. 
Även exempel på ett program innehållande utility-funktioner för libgpiod i C.

Katalogen "event_detection" innehåller ett program där insignalen från en tryckknapp detekteras, där nedtryckning medför toggling av en
lysdiod. Lysdiodens respektive tryckknappens pin-nummer är som default satta till pin 17 och 27 vid körning:

    $ ./run_event_detection

Pin-numren kan också matas in in från terminalen efter körkommandot:

    $ ./run_event_detection <LED_PIN> <BUTTON_PIN>

Som exempel, för att köra programmet med lysdioden ansluten till pin 22 och tryckknappen till pin 25, skriv

    $ ./run_event_detection 22 25

Katalogen "thread_example" innehåller exempel på flertrådande program i C samt C++, 
där varje tråds ID skrivs ut med en viss frekvens.
