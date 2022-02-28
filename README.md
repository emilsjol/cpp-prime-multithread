# cpp-prime-multithread
Finner primtal, multithreadad, c++

WSL(Ubuntu)-instruktioner

1. Klona repo och navigera till det med cd /path/to/repo
2. Kompilera med ```make```
3. Exekvera med ./main

Det finns flera argument som tar följande form:
./main arg1 arg2 arg3 arg4 arg5
arg1 = målsiffra, hittar alla primtal under arg1. 100000 med 1 tråd tar ungefär 47 sekunder för mig, så håll under det eller öka antal trådar, se arg2

arg2 = antal trådar, kräver närvaro av arg1, startar arg2 antal trådar, där optimala siffran sannolikt är (antal trådar din dator stödjer - 1) då mainprogrammet upptar en tråd också

arg3 arg4 arg5 har obetydlig ordning, är antingen

```-v``` printar alla primtal

```-t``` printar mer detaljerad tidsåtgång

```-b``` "benchmarkar" genom att köra 10 gånger istället för 1, kan ge mer förutsägbar tidsåtgång
