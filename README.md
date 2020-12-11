# Projektas

1. [V0.1 dalis](https://github.com/evmon6463/Projektas/releases/tag/v0.1) 
2. [V0.2 dalis](https://github.com/evmon6463/Projektas/releases/tag/v0.2)
3. [V0.3 dalis](https://github.com/evmon6463/Projektas/releases/tag/v0.3)
4. [V0.4 dalis](https://github.com/evmon6463/Projektas/releases/tag/v0.4)
5. [V0.5 dalis](https://github.com/evmon6463/Projektas/releases/tag/v0.5)
5. [V1.0 dalis](https://github.com/evmon6463/Projektas/releases/tag/v1.0)

# Programos veikimas

Tik paleidus programą Jūsų bus paprašyta pasirinkti kokį studentų įvedimo būdą norite pasirinkti. Iš viso yra 3 būdai. I, kuris leidžia programos vartotojui pačiam įvesti studento duomenis (vardą, pavardę, namų darbų rezultatai, egzamino rezultatai). S, kuris pats sukurs 5 studentų failus (1000, 10000, 100000, 1000000, 10000000 dydžio). N, kuris nuskaitys studentų failus iš tekstinio failo pavadinimu "kursiokai.txt".

**I,** ***kai vartotojui leidžiama pačiam įvesti duomenis***

Įvedus I iššoks kitas klausimas `Ar ivesti nauja studenta? Iveskite taip arba ne` Kiekvieną kartą, kai bus įvedama `taip` jūs galėsite pridėti vis naują studentą, o įvedus `ne` jūsų programa sustos prieš tai išvedusi visus jūsų įvestus studentus.
Panagrinėkime atvejį, kai įvedamas atsakymas `taip`. Kita iškylanti žinutė paprašys Jūsų įvesti studento vardą ir pavardę. Įvedus vardą ir pavardę ir paspaudus `Enter`.
Kitas iškilęs klausimas paklaus Jūsų `Ar norite, kad pazymiai ir egzamino rezultatas butu sugeneruotas atsitiktinai? (Iveskite taip arba ne)`. Taigi jūs turite pasirinkimą patys įvesti studento pažymius arba leisti tai padaryti programai. Pasirinkus `taip` Jūsų bus paklausta `Kiek pazymiu sugeneruoti?` Jūs turite įvesti skaičių tačiau ne didesnį nei 100. Įvedus daugiau Jums bus išmesta klaidą ir paprašyta pasirinkti skaičių iš naujo. Jeigu į atsitiktinių pažymių generavimo klausimą atsakysite `ne` programa paprašys `Iveskite studento namu darbu rezultatus:` Juos reikia vesti į vieną eilutę ir pabaigus įvedinėti visus namų darbų pažymius, paspausti `Enter`. 
Vėliau programa parašys `Iveskite egzamino rezultata:` tai turėtų būti tiesiog vienas skaičius. 
Po visų duomenų įvedimų Jūsų ir vėl bus paklaustą ar norite įvesti naują studentą. Kai galiausiai įvesite `ne` ekrane pasirodys lentelė su studentų vardais, pavardėmis ir jau apskaičiuotais galutiniais vidurkiai (pagal formulę 0,4 × (namų darbų vidurkis)+0,6 × egzaminas) bei namų darbų pažymių mediana.

**S,** ***kai programa sugeneruoja 5 studentų failus***

Kad būtų galima sugeneruoti failus iš pradžių programa paklaus `Kiek pazymiu sugeneruoti?` to reikia norint vėliau apskaičiuoti galutinį pažymį ir medianą. Įvedus skaičių programa pradės kurti failus. Kadangi šioje dalyje mes taip pat žiūrime ir programos veikimo spartą pagal skirtingus failų išrušiavimų būdus, todėl iš viso bus sukurta 45 failai, po 9 kiekvieno dydžio failui. Panagrinėsime kiekvieną iš jų. Kad būtų lengviau aprašysiu visą procesą su 1000 dydžio failu, kadangi visi kiti yra analogiški tik su vis daugiau duomenų. 
Visų pirma programa sugeneruoja 1000 skirtingų studentų duomenų ir juos surūšiuos bei surūšiuotą failą išves į tekstinį failas `rezutatai1` kuris vėliau bus naudojamas visoje programoje, tam kad skaičiuojant laiką visada failai būtų tie patys. Vėliau `rezultatai` yra išrūšiujami į du failus `gudruciai`, jeigu jų galutinis rezultatas yra 5 arba daugiau arba `vargseliai`, jeigu jų rezultatas yra mažiau nei 5. Iš viso yra 4 `gudruciu` failai ir 4 `vargseliu` failai, priklausomai nuo išrūšiavimo tipo ir ar buvo naudojami listai ar vektoriai. 
Taigi pradedant skaidyti iš pradžių sukuriami failai `gudručiai_v` ir `vargseliai_v` tai reiškia, kad faile yra naudojami vektoriai ir rūšiavimo būdas yra pirmasis, kai turime vieną bendra failą `rezultatai` ir iš jo perkeliame studentus į `gudručiai` arba `vargšeliai` failus ir galiausiai turime 3 failus su studentais. Toks pats rūšiavimo būdas tik su listais yra failuose `gudruciai_l` ir `vargseliai_l`. Vėliau kuriami failai `vargseliai_vektorius` ir `gudruciai_vektorius` yra rūšiuojami vektoriai pagal antąjį būdą, kai paimamas bendras failas `rezultatai` ir atrinkus visus studentus, kurių galutinis pažymys mažesnis už 5 ir sudėjus į failą iš bendro failo jie yra išrinami ir bendras failas tiesiog tampa nauju failu kuriame yra tik tie studentai, kurių galutinis rezultatas didesnis arba lygus 5. Tas pats rūšiavimo būdas tik su listais yra `vargseliai_list` ir `gudručiai_list` failuose tik naudojant listus, o ne vektorius.
Programos veikimo spartą galima pasižiūrėti atitinkamų dalių realeas'uose.

CPU Intel(R) Core(TM) i3-6100U CPU @ 2.30GHz
RAM 4.00 GB
SSD 264GB

Programa skaičiuoja kiek laiko trunka tam tikros funkcijos. Paleidus Run

|1 strategija vektorius	|1 strategija listas	|2 strategija vektorius	|2 strategija listas|
|----------------------|---------------------|-----------------------|---------------------------|
|1000 dydžio failas|	0.0029952|	0.0009982|	0.0009977|	0.0009974|
|10000 dydžio failas|	0.0099705|	0.0099758|	0.0089787|	0.0060106|
|100000 dydžio failas|	0.107711|	0.0987361|	0.108112|	0.0717757|
|1000000 dydžio failas|	1.36796|	0.940186|	1.23005|	0.726541|

Programa skaičiuoja kiek laiko trunka tam tikros funkcijos. Paleidus Debug

|1 strategija vektorius	|1 strategija listas	|2 strategija vektorius|	2 strategija listas|
|-----------------------|---------------------|------------------------|-------------------------|
|1000 dydžio failas|	0.0069522|	0.0019949|	0.0039917|	0.0239039|
|10000 dydžio failas|	0.975389|	0.0240433|	0.105512|	0.58096|
|100000 dydžio failas|	0.247875|	0.235368|	0,645892|	0,486957|
|1000000 dydžio failas|	2.72944|	2.26807|	3.75137|	3.52349|

**N,** ***kai programa nuskaitys studentų failus***

Viską ką programa padarys tai išves studento vardą, pavardę nuskaityta iš failo `kursiokai.txt` ir taip pat pasiėmusi iš to paties failo studentų namų darbų pažymius ir egzamino pažymi, kaip ir studentų įvedimo atveju, apskaičiuos galutinį pažymi ir medianą bei išves šiuos skaičius į ekraną.
