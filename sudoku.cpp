/***********************************************************************
* Program:
*    Sudoku Project, CS124
* Author:
*    Garrett Bond
* Summary: 
*    This project will simulate a sudoku like game and will allow the
*    user to interact with it. This project will also account for rules.
*
*    Estimated:  8.0 hrs   
*    Actual:     11.0 hrs
*      The most difficult part was incorporating the rules.
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**********************************************************************
* This function gets the file name. 
*********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin >> fileName;
}

/**********************************************************************
* This function writes the new file.
*********************************************************************/
void writeFile(char data[][9], char destinationFile[])
{
   ofstream fout(destinationFile);
   if (fout.fail())
   {
      cout << "Error writing file\n";
      return;
   }
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         fout << data[i][j] << " ";
      }
   }
   cout << "Board written successfully\n";
}

/***********************************************************************
*  This function reads the file.
***************************************************************************/
void readFile(char fileName[], char data[][9])
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return;
   }
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         fin >> data[i][j];
      }
   }
   fin.close();
}

/**********************************************************************
* This function displays the board.
**********************************************************************/
void display(char data[][9])
{
   cout << "   A B C D E F G H I\n";
   for (int i = 0; i < 9; i++)
   {
      cout << i + 1 << " ";
      for (int j = 0; j < 9; j++)
      { 
         if (j == 3 || j == 6)
         {        
            cout << "|";
       
         }
         else
         {
            cout << " ";
         }
         if (data[i][j] == '0')
         {
            cout << " ";
         }
         else
         {
            cout << data[i][j];
         }
      }
      cout << "\n";
      if (i == 2 || i == 5)
      {
         cout << "   -----+-----+-----\n";
      }
   }

}

/**********************************************************************
* This function gets the coordinate. 
**********************************************************************/
bool getCoordinate(int &row, int &col)
{
   cout << "Enter coordinates: ";
   string input;
   cin >> input;
   if (input.size() != 2)
   {
      return false;
   }
   return true;
}

/***************************************************************************
* This function determines possible values. 
***************************************************************************/
void possValues(char data[][9], int row, int col, 
   bool possibleValues[], bool display)
{   
   char coord[2];
   if (display == true)
   {
      cout << "What are the coordinates of the square: ";

      cin >> coord;
      if (coord[0] == 'A' || coord[0] == 'a')
      {
         row = 0;
      }
      if (coord[0] == 'B' || coord[0] == 'b')
      {
         row = 1;
      }
      if (coord[0] == 'C' || coord[0] == 'c')
      {
         row = 2;
      }
      if (coord[0] == 'D' || coord[0] == 'd')
      {
         row = 3;
      }
      if (coord[0] == 'E' || coord[0] == 'e')
      {
         row = 4;
      }
      if (coord[0] == 'F' || coord[0] == 'f')
      {
         row = 5;
      }
      if (coord[0] == 'G' || coord[0] == 'g')
      {
         row = 6;
      }
      if (coord[0] == 'H' || coord[0] == 'h')
      {
         row = 7;
      }
      if (coord[0] == 'I' || coord[0] == 'i')
      {
         row = 8;
      }
      col = coord[1] - '0';
      col = col - 1;
   }

   for (int i = 0; i < 9; i++)
   {
      possibleValues[i] = true;
   }
   
   for (int i = 0; i < 9; i++)
   {
      if (data[i][row] != 0)
      {
         // subtracting the character 0 turns the char to an int
         possibleValues[data[i][row] - 1 - '0'] = false;
      }
      if (data[col][i] != 0)
      {
         possibleValues[data[col][i] - 1 - '0'] = false;
      }
      
   }
   if (row < 3)
   {
      row = 0;
   }
   else if (row < 6)
   {
      row = 3;
   }
   else
   {
      row = 6;
   }
   if (col < 3)
   {
      col = 0;
   }
   else if (col < 6)
   {
      col = 3;
   }
   else
   {
      col = 6;
   }

   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (data[i +  col][j + row] != 0)
         {
            possibleValues[data[i + col][j + row]
               - 1 - '0'] = false;            
         }
      }
   }
   if (display == true)
   {
      cout << "The possible values for \'" << coord[0] << coord[1]
           << "\' are: ";
      bool first = true;
      for (int i = 0; i < 9; i++)
      {

         if (possibleValues[i] == true)
         {
            if (first == false)
            {
               cout << ", ";
            }
            cout << i + 1;
            first = false;
         }
      
      }
      cout << endl;
      cout << endl;
   }  
}

/************************************************************************
* This function edits the board.
***********************************************************************/
void edit(char data[][9])
{
   cout << "What are the coordinates of the square: ";
   char coord[2];
   cin >> coord;
   int row = 0;
   int col = 0;
   if (coord[0] == 'A' || coord[0] == 'a')
   {
      row = 0;
   }
   if (coord[0] == 'B' || coord[0] == 'b')
   {
      row = 1;
   }
   if (coord[0] == 'C' || coord[0] == 'c')
   {
      row = 2;
   }
   if (coord[0] == 'D' || coord[0] == 'd')
   {
      row = 3;
   }
   if (coord[0] == 'E' || coord[0] == 'e')
   {
      row = 4;
   }
   if (coord[0] == 'F' || coord[0] == 'f')
   {
      row = 5;
   }
   if (coord[0] == 'G' || coord[0] == 'g')
   {
      row = 6;
   }
   if (coord[0] == 'H' || coord[0] == 'h')
   {
      row = 7;
   }
   if (coord[0] == 'I' || coord[0] == 'i')
   {
      row = 8;
   }
   col = coord[1] - '0';
   col = col - 1;
   if (data[col][row] != '0')
   {
      cout << "ERROR: Square \'" << coord[0] << coord[1] << "\' is filled\n";
      cout << endl;
   }
   else
   {
      cout << "What is the value at \'" << coord[0] << coord[1] << "\': ";

      char value = 0;
      cin >> value;
      bool possibleValues[9];
      possValues(data, row, col, possibleValues, false);

      if (possibleValues[value - '0' - 1] == false)
      {
         cout << "ERROR: Value \'" << value << "\' in square \'"
              << coord[0] << coord[1] << "\' is invalid\n";
         cout << endl;
      }
      else
      {
         data[col][row] = value;
         cout << endl;
      }
   }
}

/***********************************************************************
* This function displays the menu.
***********************************************************************/
void menu(char data[][9])
{
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n";
   cout << endl;
   display(data);
   cout << endl;
   bool values[9];
   int row = 0;
   int col = 0;
   while (true)
   {
      cout << "> ";
   
      char option;
      cin >> option;
      if (option == '?')
      {
         cout << "Options:\n";
         cout << "   ?  Show these instructions\n";
         cout << "   D  Display the board\n";
         cout << "   E  Edit one square\n";
         cout << "   S  Show the possible values for a square\n";
         cout << "   Q  Save and Quit\n";
         cout << endl;
         cout << endl;
      }
      else if (option == 'D')
      {
         display(data);
         cout << endl;
      }
      else if (option == 'E')
      {
         edit(data);
      }
      else if (option == 'S')
      {
         possValues(data, row, col, values, true);
      }
      else if (option == 'Q')
      {
         char destinationFile[256];
         cout << "What file would you like to write your board to: ";
         cin >> destinationFile;
         writeFile(data, destinationFile);
         return;
      }
   }
}

/**********************************************************************
* This function plays the game Sudoku.
***********************************************************************/
int main()
{
   char fileName[256];
   getFileName(fileName);
   char data[9][9];
   readFile(fileName, data);
   menu(data);
   return 0;
}


