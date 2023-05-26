#include <iostream>
#include <unordered_map>
#include <iterator>
using namespace std;

int main()
{
    // Step 1: Define mapOfWords
    unordered_map<string, int> mapOfWords;

    // Step 2: Insert elements in mapOfWords
    mapOfWords["earth"] = 4;
    mapOfWords["moon"] = 2;
    mapOfWords["sun"] = 3;

    // Step 3: Try adding an element that was added to mapOfWords before and check the result
    pair<unordered_map<string, int>::iterator, bool> result = mapOfWords.insert({"earth", 4});
    if (!result.second)
    {
        cout << "Element with key 'earth' not inserted because already existed." << endl;
    }

    // Step 4: Find an element in mapOfWords
    if (mapOfWords.find("sun") != mapOfWords.end())
    {
        cout << "word 'sun' found." << endl;
    }
    if (mapOfWords.find("mars") == mapOfWords.end())
    {
        cout << "word 'mars' not found." << endl;
    }

    // Step 5: Show outputs
    for (auto i : mapOfWords)
    {
        cout << i.first << " :: " << i.second << endl;
    }

    return 0;
}
