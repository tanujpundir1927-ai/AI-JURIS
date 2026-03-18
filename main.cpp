#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Case {
public:
    int id;
    string description;
    string summary;
    string section;
    string decision;
};

vector<Case> cases;

// Save data
void saveToFile() {
    ofstream file("cases.txt");
    for (auto &c : cases) {
        file << c.id << "|" << c.description << "|" << c.summary << "|"
             << c.section << "|" << c.decision << endl;
    }
    file.close();
}

// Load data
void loadFromFile() {
    ifstream file("cases.txt");
    if (!file) return;

    Case c;
    while (getline(file, c.description)) {
        // simple skip for demo (basic level)
    }
    file.close();
}

// AI Logic (basic)
string summarize(string desc) {
    if (desc.length() > 60)
        return desc.substr(0, 60) + "...";
    return desc;
}

string getSection(string desc) {
    if (desc.find("theft") != string::npos)
        return "IPC 379";
    else if (desc.find("murder") != string::npos)
        return "IPC 302";
    else if (desc.find("fraud") != string::npos)
        return "IPC 420";
    else
        return "General Section";
}

string getDecision(string desc) {
    if (desc.find("minor") != string::npos)
        return "Bail Granted";
    else if (desc.find("serious") != string::npos)
        return "Bail Rejected";
    else
        return "Needs Review";
}

// Add case
void addCase() {
    Case c;
    c.id = cases.size() + 1;

    cin.ignore();
    cout << "Enter case description: ";
    getline(cin, c.description);

    c.summary = summarize(c.description);
    c.section = getSection(c.description);
    c.decision = getDecision(c.description);

    cases.push_back(c);
    saveToFile();

    cout << "Case Added!\n";
}

// Show cases
void showCases() {
    cout << "\n--- Cases ---\n";
    for (auto &c : cases) {
        cout << "\nID: " << c.id << endl;
        cout << "Summary: " << c.summary << endl;
        cout << "Section: " << c.section << endl;
        cout << "Decision: " << c.decision << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n==== AI-Juris System ====\n";
        cout << "1. Add Case\n";
        cout << "2. Show Cases\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCase(); break;
            case 2: showCases(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid!\n";
        }

    } while (choice != 3);

    return 0;
}

