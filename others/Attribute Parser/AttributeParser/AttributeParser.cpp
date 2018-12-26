#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Tag {
public:
	string name;
	map<string, string> attr;
	vector<Tag*> children;
};

void createTagTree(vector<pair<string, string>> &tags, int N, string tagName) {
	if (N == 0)
		return;

	string name;
	cin >> name;

	if (name[1] != '/') {
		//Opening tag

		//Remove the opening and closing triangle brackets
		name.erase(std::remove(name.begin(), name.end(), '<'),
			name.end());
		name.erase(std::remove(name.begin(), name.end(), '>'),
			name.end());

		if (tagName.empty()) {
			tagName = name;
		}
		else {
			tagName.append(".").append(name);
		}

		string attr, eq, val;
		do {
			cin >> attr;
			if (attr.compare(">") == 0)
				// No attributes
				
				break;
		} while (val.back() != '>');
	}
}

void eraseSubStr(std::string & mainStr, const std::string & toErase)
{
	// Search for the substring in string
	size_t pos = mainStr.find(toErase);

	if (pos != std::string::npos)
	{
		// If found then erase it from string
		mainStr.erase(pos, toErase.length());
	}
}

int main() {
	cout << "Hello attr\n";
	int N, Q;
	map<string, string> tags;
	cin >> N >> Q;

	string tagName;
	while (N--) {
		string name;
		cin >> name;

		if (name[1] != '/') {	//Opening tag
			//Remove the opening and closing triangle brackets
			name.erase(std::remove(name.begin(), name.end(), '<'),
				name.end());
			name.erase(std::remove(name.begin(), name.end(), '>'),
				name.end());

			if (tagName.empty()) {
				//Root tag
				tagName = name;
			}
			else {
				//Child tag
				tagName.append(".").append(name);
			}
			cout << "Tagname is: " << tagName << endl;

			string attr, eq, rawVal;
			do {
				cin >> attr;
				string val;
				if (attr.compare(">") == 0) {
					// No attributes
					// Add empty attr
					cout << "Empty tag\n";
					cout << "Added attr: " << tagName << "=" << val << endl;
					tags.insert(make_pair(tagName, ""));
				}
				else {
					tagName.append("~").append(attr);
					cin >> eq >> rawVal;
					val = rawVal;
					val.erase(std::remove(val.begin(), val.end(), '"'),
						val.end());
					val.erase(std::remove(val.begin(), val.end(), '>'),
						val.end());

					cout << "Added attr: " << tagName << "=" << val << endl;
					tags.insert(make_pair(tagName, val));
					eraseSubStr(tagName, "~" + attr);
				}
				
			} while (attr.compare(">") != 0 && rawVal.back() != '>');
		}
		else {	//Closing tag
			//Remove the opening and closing triangle brackets and /
			name.erase(std::remove(name.begin(), name.end(), '<'),
				name.end());
			name.erase(std::remove(name.begin(), name.end(), '>'),
				name.end());
			name.erase(std::remove(name.begin(), name.end(), '/'),
				name.end());

			if (tagName.compare(name) == 0) {
				tagName = "";
			}
			else {
				//name.insert(name.begin(), '.');
				name.insert(0, ".");
				eraseSubStr(tagName, name);
			}
		}
	}

	while (Q--) {
		cin >> tagName;
		cout << tags[tagName] << endl;
	}
	return 0;
}