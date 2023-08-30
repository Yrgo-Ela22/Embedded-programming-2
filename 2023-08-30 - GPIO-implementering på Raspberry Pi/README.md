# 2023-08-30 - GPIO-implementering på Raspberry Pi
Demonstration av GPIO-implementering på Raspberry Pi via biblioteket libgpiod.

Katalogen "electrical" innehåller ett program för att lagra och beräkna elektriska storheter via en struktur,
där strukturens medlemmar hålls privata genom att deklarera strukten i en källkodsfil och bara deklarera associerade
funktioner i motsvarande headerfil (det användaren ser). Därmed kan vi göra medlemmar helt eller delvis privata;
i detta fall gjordes de läsbara, men inte skrivbara, via get-funktioner. Struktens funktionalitet verifierades med GTest.
Detta program implementerades som en repetition av innehållet från föregående lektion (samt demonstration hur privata medlemmar
kan implementeras i C, vilket exempelvis görs för de struktar som används i libgpiod).

Katalogen "gpiod_example" utgör ett exempelprogram där en lysdiod blinkar var 100:e millisekund vid nedtryckning
av en tryckknapp. Drivrutiner från libgpiod används för att realisera systemet.
