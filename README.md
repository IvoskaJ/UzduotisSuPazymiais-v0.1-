# UzduotisSuPazymiais-v0.1-

    Pagal aprašytus užduoties reikalavimus realizuokite programą, kuri nuskaito vartotojų įvedamus reikiamus duomenis:
        studento vardą ir pavardę;
        namų darbų ir egzamino rezultatą;
    Baigus duomenų įvedimą, suskaičiuoja galutinį balą ir juos pateikia į ekraną tokiu ar panašiu pavidalu (kur galutinis apskaičiuotas balas pateikiamas dviejų skaičių po kablelio tikslumu):


    Papildykite programą, kad vietoj vidurkio galutinio balo skaičiavimui būtų galima naudoti ir medianą. Tuomet išvedimas (output’as) turėtų atrodyti panašiai į šį, kur tik vienas pasirinktas Galutinis (Vid.) arba Galutinis (Med.) yra išvedamas:


    Papildykite programą taip, kad ji veiktų ir tokiu atveju, kai namų darbų skaičius (n) yra nežinomas iš anksto, t.y. tik įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų darbų rezultatus. Šią dalį realizuoti reiktų dviem būdais, kur namų darbų rezultatus saugant į:
        C  masyvą.
        std::vector  tipo konteinerį.

    Atliekant šią užduotį galite sukurti du atskirus (*.cpp) failus (arba du projektus), tačiau nuo versijos v0.2 naudosime tik realizaciją su vector'iais.

    Papildykite programą taip, kad būtų galimybė, jog mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai.
    
        Atlikite versijos (v0.2) kodo reorganizavimą (refactoring'ą):
        Kur tikslinga, programoje naudokite (jeigu dar nenaudojote) struct'ūras;
        Funkcijas, naujus duomenų tipus (struct’ūras) perkelkite į antraštinius (angl. header (*.h)) failus, t.y. tokiu būdu turėtumete sukurtame projekte turėti kelis *.cpp failus, kaip ir kelis *.h failus.

    Kur tikslinga, bent minimaliai panaudokite išimčių valdymą (angl. Exception Handling)

    Programa paleidziama per source.cpp faila
