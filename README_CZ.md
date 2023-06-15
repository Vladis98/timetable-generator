Uživatelská příručka.

Pro použití je třeba vytvořit soubor .txt, do kterého budou data zapsána ve následujícím formátu:
První řádek je vyhrazen pro skupiny, jejichž název se skládá pouze z čísel oddělených mezerami.
Následující výstupní řádky pro předměty mají formu: název předmětu, mezera, závorky, počet přednášek týdně, mezera, počet cvičení týdně, závorky,
poté za mezerou specifikujte skupiny, které patří k tomuto předmětu.
Název souboru je třeba napsat v main.CPP, kde je definováno #define FILE "název souboru".
Pozor! Pokud je ve jménu předmětu mezera, měla by být nahrazena podtržítkem.
Doporučuji používat pouze trojciferná čísla pro názvy skupin; jinak to funguje, ale hranice tabulky budou posunuty.
Pro název předmětu doporučuji použít maximálně 23 znaků (předpokládá se, že to stačí); jinak to funguje, ale hranice tabulky budou posunuty.

Program má několik omezení:
a) Počet přednášek na předmět (0, 1, 2).
b) Počet cvičení na předmět je buď 1 nebo 0.
c) Celkový počet přednášek je maximálně 15 týdně.
d) Celkový počet cvičení je maximálně 30 (Celkový počet cvičení = součet (cvičení pro každý předmět * počet skupin patřících k tomuto předmětu)).
e) Celkový počet skupin (4, 5, 6).
Předpokládám, že tato omezení přibližně odpovídají realitě.

Při spuštění programu lze přinést argumenty:
--group "Názvy skupin" - poskytuje rozvrh pro každou skupinu.
--subject "Názvy předmětů" - poskytuje rozvrh pro každý předmět.
--statistics - vytiskne některé statistiky pouze pro zajímavost.
Prázdné - Vytiskne výsledný rozvrh.

Můj program je schopný zachytit některé chyby:
Chyba 100: Program nemůže najít nebo otevřít soubor.
Chyba 101: Nesprávný počet přednášek pro jeden předmět.
Chyba 102: Nesprávný počet cvičení pro jeden předmět.
Chyba 103: Pro předmět byly zadány skupiny, které nejsou uvedeny v prvním řádku.
Chyba 104: Existují skupiny, které nejsou zaznamenány v žádném předmětu.
Chyba 105: Chyby ve formátu souboru.
Chyba 106: Nesprávný argument při spuštění.
Chyba 107: Nesprávný celkový počet přednášek.
Chyba 108: Nesprávný celkový počet cvičení.
Chyba 109: Prázdný soubor.
Chyba 110: Prázdný seznam předmětů ve souboru.

Nebojte se přispívat svými nápady na optimalizaci a začleňovat můj kód do svých vlastních projektů, přičemž uveďte odkaz na můj repozitář na GitHubu. 
Spolupráce a využívání sdíleného kódu jsou v programátorské komunitě vítány.