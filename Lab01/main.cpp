// 1521 2021 1114 - Talha Yılmam
// 1521 2020 1076 - Ahmet Kuddusi Albayrak

// since our main focus is the solution, all the file operations, array-filling
// and other operations will be done in main() function; so the only other function
// only does the important job.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // for setting precision
using namespace std;

// our function will mark the visited blob pixels as "V"
void blobCounter(int r, int c, int rows, int columns, string** array,
                 int &pixelCount,
                 double &CoM_Row, double &CoM_Column){
    // r -> starting row
    // c -> starting column
    // function will terminate if the pixel is not "x"
    // or when the indexes are out of boundaries
    if ((r < 0) || (r >= rows) || (c < 0) || (c >= columns) || (array[r][c] != "x" )){
        return;
    }
    // mark current cell (V)isited, raise the counters:
    array[r][c] = "V";
    pixelCount+= 1;
    CoM_Row += r; //add the current r coordinate
    CoM_Column += c; //add the current c coordinate

    //recursively check the neighbours:
    blobCounter(r + 1, c, rows, columns, array, pixelCount, CoM_Row, CoM_Column);
    blobCounter(r, c + 1, rows, columns, array, pixelCount, CoM_Row, CoM_Column);
    blobCounter(r - 1, c, rows, columns, array, pixelCount, CoM_Row, CoM_Column);
    blobCounter(r, c - 1, rows, columns, array, pixelCount, CoM_Row, CoM_Column);
}

int main(){
    string filename, r, c;
    int rows, columns;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream readfile;
    readfile.open(filename);
    readfile >> r >> c; // get row number and column number
    int width = r.length(); // will be used in table alignment
    rows = stoi(r); //turning the strings into integers
    columns = stoi(c);
    
    // create dynamic array for the taken row and column number:
    // "array of pointers" method will be used to avoid pointer arithmetics,
    // since using [i][j] indexing is way easier:
    string **array = new string*[rows];
    // start filling the rows with pointers with the size of columns:
    for (int i = 0; i < rows; i++){
        array[i] = new string[columns];
    }

    //start reading and fill the array
    string line;
    int stringIndex; // will be used to traverse through the line letters
    for (int i = 0; i < (rows + 1); i++){
        getline(readfile, line);
        if(i == 0){continue;} //pass the first line
        stringIndex = 0; // reset the index for the line letters

        //read the line one by one and fill the array
        // i - 1 is the index of rows (not counting the first row of txt)
        // j is the index of columns:
        for (int j = 0; j < columns; j++){
            array[i - 1][j] = line[stringIndex];
            stringIndex++;
        }
    }

    // printing the input matrix in table:
    int counter = 0;
    // top numbers:
    cout << setw(width + 2);
    for (int i = 0; i < columns; i++){
        cout << i % 10;
        counter++;
    }
    // top line:
    cout << "\n" << setw(width + 1) << "+";
    for (int i = 0; i < counter; i++){
        cout << "-";
    }
    cout << "+" << endl;
    // input matrix:
    for (int i = 0; i < rows; i++){
        cout << setw(2) << i << "|";
        for (int j = 0; j < columns; j++){
            cout << array[i][j];
        }
        cout << "|" << i << endl;
    }
    // bottom line:
    cout << setw(width) << "+";
    for (int i = 0; i < counter; i++){
        cout << "-";
    }
    cout << "+" << endl;
    // bottom numbers:
    cout << setw(width + 1);
    for (int i = 0; i < columns; i++){
        cout << i % 10;
    }
    cout << "\n\n\n";


    // top line of report table:
    cout<< "+------+------------+---------+------------+" << endl
        << "| BLOB | NoOfPixels | CoM Row | CoM Column |" << endl
        << "+------+------------+---------+------------+";

    // initialize counters:
    std::cout << std::setprecision(2) << std::fixed; // set precision
    int blobCount = 0;
    int pixelCount = 0;
    double CoM_Row = 0;
    double CoM_Column = 0;

    // blobCounter() function will mark every pixel of a blob as "V" in one run
    // (since it is a recursive function it won't stop until all pixels of a 
    // single blob has marked.) We look for unvisited pixels in here
    // so if an "x" is found, it means there is an unvisited blob:
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (array[i][j] == "x"){ // if a new blob found
                blobCounter(i, j, rows, columns, array, pixelCount, CoM_Row, CoM_Column);
                blobCount++; // raise the number of blobs
                CoM_Row = CoM_Row / pixelCount; // get the average
                CoM_Column = CoM_Column / pixelCount; // get the average

                // print the middle of the report table:
                cout << "\n|" << setw(6) << blobCount; 
                cout << "|" << setw(12) << pixelCount; 
                cout << "|" << setw(9) << CoM_Row; 
                cout << "|" << setw(12) << CoM_Column << "|";

                // reset counters for next blob:
                pixelCount = 0;
                CoM_Row = 0;
                CoM_Column = 0;
            }
        }
    }
    
    // print the bottom of the report table:
    cout << "\n+------+------------+---------+------------+\n\n";

    //deleting the array requires deleting the inner and outer pointers:
    for (int i = 0; i < rows; i++){
        delete[] array[i];  // delete inner array
    }
    delete[] array; // delete outer array
    
    readfile.close();
    system("pause");
    return 0;
}
