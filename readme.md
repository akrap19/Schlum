Instalacija i pokretanje nana biblioteke

1. Preuzeti biblioteku sa slijedeće web lokacije:
   https://sourceforge.net/projects/nanapro/

2. Nakon preuzimanja je otvoriti folder od "%UserProfile%/AppData/Local/Microsoft/MSBuild/v4.0"
   gdje je %UserProfile% varijabla koja ovisi o računalnom okruženju.
   Unutar toga foldera potrebno je locirati i otvoriti datoteku imena poput 
   "Microsoft.CPP.XXX.user.props" nako čega je potrebno je izmjeniti na slijedeći način:

    - umetnuti "NanaPath/include"
	- umetnuti "NanaPath/build/bin/IDEName(e.g. vc2013)" i "NanaPath/extrlib"
	  te ih razdvojiti sa ";"

3. Otvoriti "NanaPath/build/IDEName(e.g. vc2013)/Nana.sln" te u izborniku odabrati Build->Rebuild All.
   Nakon izvođenja Nana static (e.g. nana_debug.lib, nana_release.lib) datoteka će se izgenerirati
   u "NanaPath/build/bin/IDEName".

4. Izgeneriranu datoteku je potrebno umetnuti u folder %UserProfile%os\Schlum\Dependencies\bin i iz 
   preuzete nana datoteke potrebno je kopirati include folder u %UserProfile%os\Schlum\Dependencies.

5. Kada se otvori projekt na kojemu se radi potrebno je postaviti putanje do biblioteke. Prva putanja se 
   postavalja tako da desnim klikom pritisne ime projekta u Solution Exploreru odabere se Propeties iz
   izbornika te u General od C/C++ pod redom Aditional include directories kopirati 
   $(SolutionDir)Dependencies\include. Drugu putanju potrebno u propeties namjestiti u Linker-u pod 
   Input tako da u Additional Dependecies kopiramo putanju  
   $(SolutionDir)Dependencies\bin\nana_v142_Debug_x64.lib; koja vodi do izgenerirane datoteke.

6. Potrebno je još za kraj prilagoditi izvođenje porgrama za statičke datoteke tako da se u 
   properties pod C/C++ u Code Generation namjesti Runtime Libary na Multi-threaded Debug (/MTd).
   
