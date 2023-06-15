Návod k použití.

Chcete-li jej použít, musíte vytvořit soubor .txt, do kterého budou data zapsána ve tvaru:
1. První řádek je vyhrazen skupinám, jejichž název obsahuje pouze čísla zaznamenaná mezerou.
2. Další výstupní řádky pro předměty jsou ve formě: název předmětu, mezera, závorka, počet přednášek týdně, mezera, počet cvičení týdně, závorka,
    poté, za mezerou, uveďte skupiny, které patří k tomuto kurzu.
Musíte zapsat název souboru do main.CPP, kde je definován #define FILE "název souboru".
Pozor!  Pokud je v názvu kurzu mezera, musí být nahrazena podtržením.
        U názvů skupin doporučuji používat pouze třímístná čísla, jinak to bude fungovat, ale hranice tabulky budou posunuty.
        Pro název kurzu doporučuji používat nejvýše 23 znaků (předpokládám, že to stačí), jinak to bude fungovat, ale hranice tabulky budou posunuty.

Program má několik omezení:
a) Počet přednášek na jeden kurz (0, 1, 2).
B) Počet cvičení pro jeden kurz je 1 nebo 0.
C) Celkový počet přednášek je nejvýše 15 týdně.
d) Celkový počet cvičení je nejvýše 30 (Celkový počet cvičení = suma (cvičení pro každý kurz * počet skupin patřících k tomuto kurzu)).
d) Celkový počet skupin (4, 5, 6).
Předpokládám, že tato omezení téměř odpovídají skutečnosti.

Když spustíte program, můžete přinést argumenty:
1) --group "Nazvy skupin" - uvádí rozvrh pro každou skupinu.
2) --subject "Nazvy kurzů" - uvádí rozvrh pro každý kurz.
3) --statistics - vypíše některé statistiky jen tak pro zajimavost.
4)   Prazdný - Výpiše výsledný rozvrh.

Můj program je schopen zachytit některé chyby:
Chyba 100: Program nemůže najít nebo otevřít soubor.
Chyba 101: Nesprávný počet přednášek pro jeden kurz
Chyba 102: Nesprávné množství cvičení pro jeden kurz
Chyba 103: Skupiny, které nejsou uvedeny v prvním řádku, byly zapsány do kurzu
Chyba 104: Existují skupiny, které nejsou zaznamenány v žádném kurzu
Chyba 105: Chyby ve formě souboru
Chyba 106: Nesprávný argument při spuštění
Chyba 107: Nesprávný celkový počet přednášek
Chyba 108: Nesprávný celkový počet cvičení
Chyba 109: Prázdný soubor
Chyba 110: Prázdný seznam kurzů v souboru
