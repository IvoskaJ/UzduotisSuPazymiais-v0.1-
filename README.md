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
    Patobulinkite (jeigu reikia pagal v0.1 paskutinę užduotį turimą realizaciją) ir sugeneruokite penkis atsitiktinius studentų sąrašų failus, sudarytus iš: 1000, 10000, 100000, 1000000, 10000000 įrašų. Vardus ir Pavardes galite generuoti "šabloninius", kaip pvz. Vardas1 Pavarde1, Vardas2 Pavarde2 ir t.t.
    Sūrušiuokite (padalinkite) studentus į dvi kategorijas:
        Studentai, kurių galutinis balas < 5.0 galėtume vadinti “vargšiukai”, “nuskriaustukai” ir pan.
        Studentai, kurių galutinis balas >= 5.0 galėtume vadinti "kietiakiai", "galvočiai" ir pan.
    Surūšiuotus studentus išveskite į du naujus failus.
    Atlikite programos veikimo greičio (spartos) analizę: t.y. išmatuokite programos spartą išskiriant kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
        failų kūrimą;
        duomenų nuskaitymą iš failų;
        studentų rūšiąvimą į dvi grupes/kategorijas;
        surūšiuotų studentų išvedimą į du naujus failus.
