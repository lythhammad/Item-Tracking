#ifndef ITEMTRACKER_H  // Header guard: 

#include <iostream>
#include <string>
#include <map>

class ItemTracker {
private:
	std::map<std::string, int> counts; // Item and frequency data
	std::string inputFilePath; // Path to the input file

public:
	ItemTracker(const std::string& inputFilePath); // Constructor

	void load(); // Loads data from file

	void writeBackup(const std::string& outputFilePath = "frequency.dat"); // Writes a backup file

	int countOf(const std::string& item) const; // Finds the count for an item

	void printAllFrequencies() const; // Prints all frequencies

	void printHistogram(char barChar = '*') const; // Prints a histogram
};


#endif // End of protected area 