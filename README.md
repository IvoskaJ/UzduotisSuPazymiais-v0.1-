# UzduotisSuPazymiais-v0.1-
Reikalavimai versijai (v1.0)

    Optimizuokite studentų rūšiavimo (dalijimo) į dvi kategorijas ("vargšiukų" ir "kietiakų") realizaciją: t.y. visiems trims konteinerių tipams (vector, list ir deque) išmatuokite programos veikimo spartą priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:
        1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai). Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu (įsitikinkite tuo!), tačiau šiame žingsnyje svarbiausia yra patyrinėti, kaip programos veikimo sparta priklauso nuo konteinerio tipo?
        2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai. Atminties atveju tai efektyviau, tačiau dažni trynimai gali būti "skausmingi", ypač tam tikro tipo konteineriams.

    P.s. Jeigu Jūsų šiuo metu realizuota strategija nesutampa nė su viena iš šių dviejų aukščiau aprašytų strategijų, turėsite palyginti tris strategijas: Jūsų ir abi aukščiau aprašytas strategijas.

    Programos efektyvumas stipriai gali priklausyti ne tik nuo naudojamo konteinerio tipo, tačiau ir nuo naudojamų algoritmų. Susipažinkite su žemiau pateiktais algoritmais:
        std::find
        std::find_if
        std::search
        std::copy
        std::remove
        std::remove_if
        std::remove_copy
        std::remove_copy_if
        std::transform
        std::partition
        std::stable_partition

    ir pabandykite iš jų atsirinkti ir pritaikyti tinkamus algoritmus studentų dalijimo procedūrai paspartinti (optimizuoti) ant vieno fiksuoto konteinerio - vektoriaus. Palyginkite programos veikimo spartą po šių pakeitimų.

    Galutinėje versijoje v1.0 turi būti pateikta:
        Tvarkinga github repozicija, kurioje būtų tik Jūsų kurti (source) failai, t.y. jokių naudojamo IDE "šiukšlių".
        README.md faile aprašyti visi releasai, bei pakomentuoti gauti rezultatai.
        Parengta naudojimosi instrukcija, t.y. pagrindiniai žingsniai aprašyti tame pačiame README.md faile.
        Parengta įdiegimo instrukcija, t.y. paruoštas make Makefile (Unix OS atveju) arba cmake CMakeLists.txt (bet kokios OS atveju).
        
        1 strategijoje iš siūlomomi algoritmai nenaudojami.
        2 strategijoje panaudotas std::copy.
        
        Tyrimu rezultatai:
        Deque:
        1 strat:![deque1](https://user-images.githubusercontent.com/78845735/117927486-f19f7d80-b302-11eb-8072-bcd00deaf2dc.png)
        2 strat:![deque2](https://user-images.githubusercontent.com/78845735/117927617-1bf13b00-b303-11eb-816c-acdb38db5619.png)
        
        1 strategija deque'ui daug greitesnė. Kadangi 2 strategija labai lėtai veikia, screenshot'ai kuriuose būtų dirbama su 100000, 1000000, ir 100000 dydžio failais nekeliami.

        
        Vector:
        1 strat:![vector1](https://user-images.githubusercontent.com/78845735/117928205-e436c300-b303-11eb-9abe-6bd22e079000.png)
        2 strat:![vector2](https://user-images.githubusercontent.com/78845735/117928239-ef89ee80-b303-11eb-89bb-3df77cf5caef.png)
        
        1 strategija vektoriui gavosi žymiai greitesnė nei 2. Vėl gi, dėl veikimo greičio 2 strategijai nekeliami didelių failų screenshot'ai.
        
        List:
        1 strat:![list1](https://user-images.githubusercontent.com/78845735/117928561-6921dc80-b304-11eb-9570-1f34d891b12b.png)
        2 strat:![list2](https://user-images.githubusercontent.com/78845735/117928589-7343db00-b304-11eb-939c-7f3f515201fe.png)
        
        2 strategija list'ui gavosi šiek tiek greitesnė.


