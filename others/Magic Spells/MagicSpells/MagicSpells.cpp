#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
private:
	string scrollName;
public:
	Spell() : scrollName("") { }
	Spell(string name) : scrollName(name) { }
	virtual ~Spell() { }
	string revealScrollName() {
		return scrollName;
	}
};

class Fireball : public Spell {
private: int power;
public:
	Fireball(int power) : power(power) { }
	void revealFirepower() {
		cout << "Fireball: " << power << endl;
	}
};

class Frostbite : public Spell {
private: int power;
public:
	Frostbite(int power) : power(power) { }
	void revealFrostpower() {
		cout << "Frostbite: " << power << endl;
	}
};

class Thunderstorm : public Spell {
private: int power;
public:
	Thunderstorm(int power) : power(power) { }
	void revealThunderpower() {
		cout << "Thunderstorm: " << power << endl;
	}
};

class Waterbolt : public Spell {
private: int power;
public:
	Waterbolt(int power) : power(power) { }
	void revealWaterpower() {
		cout << "Waterbolt: " << power << endl;
	}
};

class SpellJournal {
public:
	static string journal;
	static string read() {
		return journal;
	}
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

	/* Enter your code here */
	if (Fireball *casted = dynamic_cast<Fireball *>(spell))
		casted->revealFirepower();
	else if (Frostbite *casted = dynamic_cast<Frostbite *>(spell))
		casted->revealFrostpower();
	else if (Thunderstorm *casted = dynamic_cast<Thunderstorm *>(spell))
		casted->revealThunderpower();
	else if (Waterbolt *casted = dynamic_cast<Waterbolt *>(spell))
		casted->revealWaterpower();
	else {
		//cout<<spell->revealScrollName()<<" "<<SpellJournal::read()<<endl;
		/*for (string::iterator it = spell->revealScrollName().begin(); it != spell->revealScrollName().end(); it++)
			cout<<*it;
		cout<<1<<endl;*/
		/*string::iterator scrollPos = spell->revealScrollName().begin(), journalPos = SpellJournal::journal.begin();

		string str = "123";
		cout<<str.npos<<endl;
		cout<<str.find('a')<<endl;
		while (scrollPos != spell->revealScrollName().end() && journalPos != SpellJournal::journal.end()) {

		}*/

		//string s = "123";
		//cout<<s.substr(4);

		string scrollName = spell->revealScrollName(), journal = SpellJournal::journal;
		int scrollPos = 0, jPos = 0, count = 0;
		while (scrollPos < scrollName.length() && !journal.empty()) {
			int firstOccurPos = journal.find(scrollName[scrollPos]);

			if (firstOccurPos < journal.length()) {
				count++;
				journal = journal.substr(firstOccurPos + 1);
			}

			scrollPos++;
		}
		cout << count << endl;
	}
}

class Wizard {
public:
	Spell *cast() {
		Spell *spell;
		string s; cin >> s;
		int power; cin >> power;
		if (s == "fire") {
			spell = new Fireball(power);
		}
		else if (s == "frost") {
			spell = new Frostbite(power);
		}
		else if (s == "water") {
			spell = new Waterbolt(power);
		}
		else if (s == "thunder") {
			spell = new Thunderstorm(power);
		}
		else {
			spell = new Spell(s);
			cin >> SpellJournal::journal;
		}
		return spell;
	}
};

int main() {
	int T;
	cin >> T;
	Wizard Arawn;
	while (T--) {
		Spell *spell = Arawn.cast();
		counterspell(spell);
	}
	return 0;
}
