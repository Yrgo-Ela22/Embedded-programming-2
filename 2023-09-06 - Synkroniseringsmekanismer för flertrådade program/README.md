# 2023-09-06 - Synkroniseringsmekanismer för flertrådade program
Demonstration av semaforer och mutex i C och C++ för att skydda resurser som delas mellan trådar,
så att endast en tråd har åtkomst till resursen åt gången.

Både semaforer och mutex fungerar på så sätt att trådarna får turas om att reservera de delade resurserna.
Om en given tråd försöker reservera en resurs som redan är reserverad får tråden vänta på att den blir
ledig innan den får åtkomst till resursen. Därmed bromsas tråden upp tills resursen blir ledig. Både semaforer
och mutex arbetar efter denna princip, men de skiljer sig åt något:

    - Semaforer utgörs av heltal så kallade semafor-ID, exempelvis 0 för terminalen, 1 för delat minne, 2 för annat.
      En semafor är antingen reserverad (låst) eller tillgänglig (olåst). Vilken tråd som helst kan låsa upp en 
      reserverad semafor, dvs. inte bara tråden som reserverade semaforen.
      
      Semaforer är oftast binära, där 0 = tillgänglig och 1 = reserverad. Det finns också uppräknande semaforer,
      som kan användas om exempelvis fem resurser finns tillgängliga. Först när alla fem semaforer är reserverade
      och en tråd försöker reservera en sjätte semaforer sker väntan på att en av de fem reserverade semaforerna
      blir tillgänglig.

    - Mutex utgörs av ett objekt, där mutexen antingen är låst eller olåst. Endast den tråd som reserverade resursen
      har möjlighet att låsa upp den, vilket gör den något säkrare än en semafor. Mutex kan inte vara uppräknande, 
      utan antingen är den låst eller olåst. Om flera resurser finns är uppräknande semaforer att föredra.

Katalogen "thread_sync_examples" innehåller exempel på användning av semaforer i C och C++.
Katalogen "thread_sync_lib" innehåller semaforer och mutex i C, C++ och Python. I C++ demonstreras både binära och räknande semaforer.
Katalogen "thread_sync_gpio" utgör ett inbyggt system, där två tryckknappar används för att blinka var sin lysdiod via var sin tråd.
Varje gång respektive lysdiod byter tillstånd sker en utskrift om detta i terminalen (pin-numret samt det nya tillståndet skrivs ut).
Binära semaforer används för att se till att enbart en av trådarna har tillgång till terminalen vid ett givet tillfälle.