#include "DefVal.hpp"

#include "Parcour.hpp"
#include "Runner.hpp"

using namespace std;

#ifndef NB_NAME
# define NB_NAME 679
#endif

string Name[NB_NAME] = { "Nathalie","Megumin","Martin","Adel","Ines","Emma",
"Louis","Pierre","Chloé","Antoine","Colin","Maxence","Pascal","Vivien"
,"Lyes","Valentin","Quentin", "Ivan" ,"Nikolai", "Boris", "Vladimir",
"Pyotr", "Alexei", "Dmitri", "Sergei", "Viktor", "Roman", "Igor","Mikhail",
"Vasily", "Pavel", "Fyodor", "Nikita", "Valery","Vladislav", "Leonid", "Maxim",
"Yuri","Oleg", "Andrei", "Konstantin" ,"Vyacheslav" ,"Aleksandr", "Stanislav",
"Anatoli" ,"Miroslav" ,"Artyom" ,"Bogdan", "Branislav", "Ilya", "Jaroslav",
"Radomir", "Kirill", "Radoslav" ,"Lubomir", "Ratimir","Yegor", "Faraji", "Imamu"
, "Jelani", "Jengo", "Jumaane", "Khamisi", "Kibwe", "Mosi", "Mwenye", "Sefu",
"Simba", "Tendaji", "Zuberi", "Abasi", "Annan", "Azizi","Badru","Bakari","Bwana"
, "Chane", "Chuma", "Enzi", "Faraji", "Hanisi", "Idi", "Issa", "Jabari", "Akani"
, "Aluwanip", "Ayanda", "Bambanani", "Bheka", "Bhekithemba", "Bhekizizwe",
"Butholezwe", "Dikotsi", "Dzingai", "Esaia", "Hangwani", "Humbe", "Kabelo",
"Khathu", "Khumbu", "Kutlwano", "Kwanele", "Lentswe", "Lesebo", "Letswalo",
"Lutendo", "Mahlubandile", "Makalo", "Mareka", "Masingita", "Moeketsi", "Molapo"
, "Mosemotsane", "Motlalentwa", "Mothusi", "Msizi", "Mzwamadoda", "Nthofeela",
"Oagile", "Paseka", "Phahamo", "Poloko", "Qukeza", "Refilwe", "Sanele", "S'bu",
"Sehlolo", "Sekgolokhane", "Sibusiso", "Sizwe", "Teboho", "Thabiso", "Themba",
"Thuso", "Tsebo", "T'sehla", "Tshawe", "Unathi", "Wandile", "Mbutu", "Kofi",
"Asha", "Abla", "Adhra", "Adila", "Aeeshah", "Afiya", "Chausiku", "Eshe",
"Furaha", "Imani", "Kamaria", "Marjani", "Mchumba", "Mwanajuma", "Nia", "Nuru",
"Sanaa", "Sauda", "Subira", "Zuri", "Aizivaishe", "Anatswanashe", "Anodiwa",
"Anokosha", "Awande", "Bokang", "Bongani", "Dikeledi", "Edzai", "Fikile", "Gugu"
, "Kagiso", "Keneuwe", "Koketso", "Langalibalele", "Lerato", "Lindidwe",
"Litsoanelo", "Lulama", "Majobo", "Maletsatsi", "Matshediso", "Mbali", "Mmaabo",
"Mncedisi", "Mohau", "Moratuoa", "Muambiwa", "Nnyadzeni", "Nofoto", "Nthati",
"Ntsebo", "Ntswaki", "Phathu", "Reneilwe", "Rudzani", "Shandu", "Sinethemba",
"Sizani", "Thanduxolo", "Tshanduko", "Tungu", "Zinhle", "Anna", "Yelena",
"Olga", "Oksana", "Tatyana", "Svetlana", "Nadya", "Yekaterina", "Irina",
"Galina", "Miroslava", "Anastasia", "Vera", "Polina", "Lyudmila", "Elena",
"Marina", "Darya", "Irma", "Ksenia", "Alexandra", "Nadesja", "Valentina",
"Arina", "Alya", "Galenka", "Katya", "Ljuba", "Radmila", "Natacha", "Vlada",
"Nadezhda", "Tatiana", "Sonia", "Mira", "Philippe", "Jean-Marie",
"Marcel", "Francois", "Hubert", "Paul", "Michel", "Henri", "Marc",
"Jean", "Maurice", "René", "Claude", "Yves", "Jacques", "Simon", "Olivier",
"Joseph", "Robert", "Georges", "André", "Raymond", "Gaston", "Charles",
"Thierry", "Guy", "Patrice", "Mathieu", "Jean-Francois", "Lucien", "Jean-Paul",
"Daniel", "Thibault", "Luc", "Dominic", "Sébastien", "Hugo", "Manon",
"Camille", "Clara", "Juliette", "Clémence", "Jeanne", "Charlotte",
"Marie", "Nina", "Julia", "Elise", "Justine", "Yasmine", "Elina", "Andrea",
"Eleonore", "Clarisse", "Fanny", "Selma", "Leila", "Veronique", "Sophie",
"Helena", "Daphne", "Suzanne", "Melanie", "Bernadette", "Maud", "Angeline",
"Celine", "Jessica", "Pauline", "Viviane", "Jeanette", "Bernard",
"Dubois", "Durand", "Leroy", "Moreau", "Lambert", "Dupont", "Leclerc",
"Laurent", "Renard", "Tremblay", "Gagnon", "Roy", "Bouchard", "Gauthier",
"Morin", "Lavoie", "Fortin", "Gagne", "Duval", "Hébert", "Deville", "Gerard",
"Duchaine", "Jauvin", "Gilbert", "Bergeron", "Paquette", "Pelletier", "Rémy"
,"Giroud", "Bosquet", "Lebouef", "Péllissier", "Deveraux", "Le Gall", "Le Roux",
"de Castelnau", "de Montaignac", "John", "Brian", "Peter", "Adam", "James",
"William", "Jacob", "Christopher", "Joshua", "Michael", "Ethan", "Joseph",
"Matthew", "Anthony", "Daniel", "Ryan", "Samuel", "Kevin", "David", "Logan",
"Carter", "Benjamin", "Andrew", "Henry", "Nicholas", "Gavin", "Owen", "Jack",
"Wyatt", "Wayne", "Walter", "Charles", "Merritt", "Earl", "Alfred",
"Vernon", "Edward", "Donald", "George", "Greg", "Thomas", "Robert",
"Gene", "Glen", "Hugh", "Ronald", "Francis", "Stephen", "Jon", "Richard",
"Mark", "Marcus", "Scott", "Duncan", "Douglas", "Keith", "Howard", "Russell",
"Clayton", "Lee", "Steve", "Tom", "Clay", "Oliver", "Kenneth", "Ralph", "Andy"
, "Tony", "Tyrone", "Lawrence", "Patrick", "Harry", "Alan", "Eugene", "Frank"
, "Craig", "Jason", "Jonathan", "Harrison", "Connor", "Gaylord",
"Sean", "Cooper", "Stanley", "Calhoun", "Neil", "Jeffrey", "Harold", "Raymond"
, "Fred", "Marshall", "Silas", "Roy", "Jesse", "Ken", "Bruce", "Norris",
"Horatio", "Clarence", "Lloyd", "Duane", "Mortimer", "Ben", "Ernest",
"Warren", "Graham", "Marvin", "Orson", "Dennis", "Jackson", "Dwight", "Harlan",
"Arthur", "Percival", "Montgomery", "Clyde", "Rodney", "Gerald",
"Franklin", "Jake", "Horace", "Irving", "Seth", "Randolph", "Floyd", "Carl",
"Brent", "Cliff", "Malcolm", "Timothy", "Wallace", "Pierce", "Edmund",
"Gary", "Tony", "Nathan", "Eric", "Albert", "Robin", "Geoffrey", "Larry",
"Ian", "Leonard", "Gordon", "Derek", "Maxwell", "Alec", "Bernard", "Stuart",
"Rupert", "Dean", "Philip", "Ross", "Darren", "Melvin", "Justin",
"Zack", "Elliot", "Simon", "Morgan", "Clark", "Xavier", "Jared", "Edgar",
"Crispin", "Nelson", "Emmett", "Trevor", "Travis", "Lance", "Adrian",
"Desmond", "Brendan", "Brett", "Ambrose", "Basil", "Kieran", "Conan",
"Dermot", "Dudley", "Felix", "Finn", "Oscar", "Sidney", "Aaron", "Vincent",
"Angus", "Grant", "Luke", "Miles", "Morton", "Randall", "Reginald",
"Herbert", "Wesley", "Nigel", "Alexander", "Dominic", "Bradley", "Olivia",
"Emily", "Sophie", "Jessica", "Alice", "Scarlett", "Daisy", "Eve"
, "Phoebe", "Sienna", "Anna", "Mary", "Megan", "Elizabeth", "Amy", "Darcy",
"Matilda", "Erin", "Lucy", "Grace", "Evelyn", "Amber", "Harriet", "Caitlyn",
"Jasmine", "Madison", "Kate", "Eleanor", "Alexandra", "Sarah", "Martha",
"Bethany", "Rebecca", "Victoria", "Gabriella", "Naomi", "Lauren", "Clara",
"Laura", "Kayla", "Nicole", "Skye", "Eliza", "Patricia", "Linda", "Barbara",
"Jennifer", "Maria","Susan", "Margaret", "Dorothy", "Lisa", "Nancy", "Helen",
"Sandra","Donna", "Carol", "Ruth", "Sharon", "Michelle", "Kimberly", "Deborah",
"Amelia", "Charlotte", "Isabella", "Ruby", "Addison", "Alyssa", "Abigail",
"Julia", "Samantha", "Brooklyn", "Ashley", "Natalie", "Brianna", "Hailey",
"Lillian", "Judith", "Alison", "Amanda", "Angela","Audrey","Beatrice",
"Brenda", "Bridget", "Caroline", "Cassandra", "Charity", "Cecilia", "Anne",
"Clarissa", "Christabel", "Cheryl", "Cynthia", "Cadence", "Cordelia", "Daphne",
"Deanna", "Denise", "Dolores", "Doreen", "Drusilia", "Edith", "Edna",
"Eleonor", "Eileen", "Edwina", "Ellen", "Estelle", "Ethel", "Felicity",
"Fiona", "Genevieve", "Gertie", "Gwen", "Gwendolyn", "Henrietta", "Imogen",
"Iris", "Imelda", "Jacqueline", "Jane", "Jenna", "Joanna", "Josephine",
"Julianne", "Kathleen", "Kierra", "Kaylee", "Leah", "Lois"};

vector<int> PickedName;

Runner::Runner() {
  // for random names, Shapes & Colors
  int sizeVec;
  int RandNamed;
  int tmp;
  do {
		tmp = 1;
		RandNamed = rand()%NB_NAME;
		sizeVec = PickedName.size();
		for (int i = 0; i < sizeVec; i++) {
			if (RandNamed == PickedName[i]) {
				tmp = 0;
				break;
			}
		}
	}while (tmp == 0);

	NumDoss = RandNamed + 1;
	Nom = Name[RandNamed];
	PickedName.push_back(RandNamed);

  Col = sf::Color(NumDoss%10*25%256, NumDoss%100/10*25%256, NumDoss/67*25%256);

  // for random apptitudes
  size = rand() % 80 + 120;
  if (size < 150) {size += rand() % 40;}
  mass = (rand() % 65)*size/180 + 45;
  poids_chauss = rand() % 200 + 101;
  speed = TIME_MOD*((float)(rand() % 36) + 19.444f)/10.f; // En m/s <=> entre 7 et 20 Km/h
  prep = rand() % 9 + 8;
  hydr = 6.02f/(speed*3.6f/5.f); //Valeurs un peu modifié juste pour que statistiquement les abandons soient en dessous de 3%
  dehydrPos = PARC_SIZE*2;
  WPtMax = (speed*mass*0.98f) + (0.5f*1.225f*0.137*(size/100)*pow(speed, 3));
}

void Runner::RuShow() {
	cout << "Nom :" << setw(3) << Nom << endl;
	cout << "Numéro de dossard :" << setw(3) << NumDoss << endl;
	cout << "Taille :" << setw(3) << size << " cm" << endl;
	cout << "Masse :" << setw(3) << mass << " kg" << endl;
	cout << "Poids de la chaussure :" << setw(3) << poids_chauss << " g" << endl;
	cout << "Vitesse moyenne :" << setw(3) << speed << " Km/h" << endl;
	cout << "Semaines de préparations :" << setw(3) << prep << endl << endl;
  }

  void Runner::RunDeHydr(){
    //cout << "Xpos : " << Xpos << endl;
    //cout << "Dpos : " << dehydrPos << endl;
    if (dehydrPos < (Xpos - 2000)){
      abandon = 1;
      speed = 0;
      //cout << NumDoss << " abandone !!!" << endl;
    }
  }

  void Runner::RunHydr(Parcour Par, double Timer){
    if (Xpos >= Par.WaterSup[WRavPas]) {
      WRavPas += 1;
      hydr += (float)rand()/((float)RAND_MAX*2.f);
    }
    hydrImp = TIME_MOD*hydr/(TIME_MOD*Timer/3600.f);
    //cout << "Tim : " << (Timer/3600.f) << endl;
    //cout << "HyI : " << hydrImp << endl;
    //cout << "Hyd : " << hydr << endl;
  }

void Runner::SpeedModif(Parcour Par) {
  //Slopes
  if(Par.Slopes[CurrentPhase] > 0) {SpeedMod = (1.f-(Par.Slopes[CurrentPhase]/150.f));}
  else if(Par.Slopes[CurrentPhase] < 0) {SpeedMod = (1.f-(Par.Slopes[CurrentPhase]/(150.f/0.35f)));}
  else{SpeedMod = 1.f;}
  //Chaussures
  SpeedMod = SpeedMod*(1.f-(0.0011f*poids_chauss));
  //Prep
  //cout << "PRE : " << prep << endl;
  if (Xpos >= ((float)PARC_SIZE/2.f*(1.f+(prep-8)/8)) ){
    SpeedMod = SpeedMod * ( (1.f+(0.025f*prep))-(0.0000095238095f*Xpos));
    // donne les réduction de vistesse suivant la préparation comme dans l'énoncé
  }

  // Bits of hydratation code related here because why not ?
  if(0.4f < hydrImp && hydrImp <= 0.9f){
    //cout << "!!!" << endl;
    SpeedMod = SpeedMod * (0.38f*hydrImp + 0.648f); // = *0.99 at hydrImp = 0.9 and = *0.8 at hydrImp = 0.4
    dehydrPos = PARC_SIZE*2;
    dehydr = 0;
  }
  else if (hydrImp <= 0.4f){
    //cout << "Warning : " << NumDoss << " is Dehydrated !" << endl;
    SpeedMod = SpeedMod * 0.8f;
    if (!dehydr){
      dehydr = 1;
      dehydrPos = Xpos;
    }
  }
  float TmpPentToDeg = atan(fmod((Par.Turns[CurrentWPhase]/100), M_PI/2))*180/M_PI;
  WRSp = cos((Par.WdAng+180.f-TmpPentToDeg)*M_PI/180.f)*Par.WdSpeed;
  SpeedMod = SpeedMod * ((WPtMax - (0.5f*1.225f*0.137f*(size/100)*pow((speed + WRSp), 2)*speed))/(mass*0.98f))/speed;
  //cout << "SpMW : " << ((WPtMax - (0.5f*1.225f*0.137f*(size/100)*pow((speed + WRSp), 2)*speed))/(mass*0.98f))/speed << endl;
  CurrentSpeed = speed*SpeedMod;
  }
