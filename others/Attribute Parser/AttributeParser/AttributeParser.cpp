#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


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
	int N, Q;
	map<string, string> tags;
	cin >> N >> Q;

	string tagName;
	while (N--) {
		string name;
		cin >> name;

		if (name[1] != '/') {	//Opening tag
			//Remove the opening and closing triangle brackets
			/*name.erase(std::remove(name.begin(), name.end(), '<'),
				name.end());
			name.erase(std::remove(name.begin(), name.end(), '>'),
				name.end());*/
			name.erase(0, 1);
			bool emptyTag = false;
			if (name.back() == '>') {
				emptyTag = true;
				name.pop_back();
			}

			if (tagName.empty()) {
				//Root tag
				tagName = name;
			}
			else {
				//Child tag
				tagName.append(".").append(name);
			}
			//cout << "Tagname is: " << tagName << endl;

			if (!emptyTag) {
				string attr, eq, rawVal;
				do {
					cin >> attr;
					string val;
					if (attr.compare(">") == 0) {
						// No attributes
						// Add empty attr
						//cout << "Empty tag\n";
						//cout << "Added attr: " << tagName << "=" << val << endl;
						tags.insert(make_pair(tagName, ""));
					}
					else {
						tagName.append("~").append(attr);
						cin >> eq >> rawVal;
						val = rawVal;
						/*val.erase(std::remove(val.begin(), val.end(), '"'),
							val.end());
						val.erase(std::remove(val.begin(), val.end(), '>'),
							val.end());*/
						val.erase(0, 1);
						while (val.back() == '>' || val.back() == '"')
							val.pop_back();

						//cout << "Added attr: " << tagName << "=" << val << endl;
						tags.insert(make_pair(tagName, val));
						//eraseSubStr(tagName, "~" + attr);
						tagName.erase(tagName.end() - (attr.length() + 1), tagName.end());
						//cout << "Tag name is back to: " << tagName << endl;
					}

				} while (attr.compare(">") != 0 && rawVal.back() != '>');
			}
			else {
				tags.insert(make_pair(tagName, ""));
			}
		}
		else {	//Closing tag
			//Remove the opening and closing triangle brackets and /
			/*name.erase(std::remove(name.begin(), name.end(), '<'),
				name.end());
			name.erase(std::remove(name.begin(), name.end(), '>'),
				name.end());
			name.erase(std::remove(name.begin(), name.end(), '/'),
				name.end());*/
			name.erase(0, 2);
			name.pop_back();

			if (tagName.compare(name) == 0) {
				tagName = "";
			}
			else {
				//name.insert(name.begin(), '.');
				//name.insert(0, ".");
				//eraseSubStr(tagName, name);
				tagName.erase(tagName.end() - (name.length() + 1), tagName.end());
				//cout << "Tag name is back to: " << tagName << endl;
			}
		}
	}

	while (Q--) {
		cin >> tagName;
		map<string, string>::iterator it = tags.find(tagName);
		if (it == tags.end())
			cout << "Not Found!";
		else
			cout << it->second;
		cout << endl;
	}
	return 0;
}
