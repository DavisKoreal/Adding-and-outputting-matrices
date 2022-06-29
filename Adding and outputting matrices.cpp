// Adding and outputting matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Color.h"
#include <iomanip>
#include <string>

//function to print out the values of the three arrays when displaying the matrices
void printmatrice(double printarray[100][100], double printarray2[100][100], double printarray3[100][100], int rows,int collumns, int maxwidth) {
	double max = 10;
	for (int i = 0; i < rows; i++) {
		std::cout << "|";
		for (int j = 0; j < collumns; j++) {
			std::cout << std::setw(maxwidth) << std::left << dye::red(printarray[i][j]);
		}
		std::cout << "|" <<std::setw(max) << std::right<< " " << std::right << "|";
		for (int j = 0; j < collumns; j++) {
			std::cout << std::setw(maxwidth) << std::left << dye::green(printarray2[i][j]);
		}
		std::cout << "|" << std::setw(max) << std::right << " " << std::right << "|";
		for (int j = 0; j < collumns; j++) {
			std::cout << std::setw(maxwidth) << std::left << dye::yellow(printarray3[i][j]);
		}
		std::cout << "|" << std::endl;
	}

}

int main()
{
	std::string reply;
	do {
		double  arrayone[100][100];
		double  arraytwo[100][100];
		double arraythree[100][100];
		// Get the number of rows and collumns from the user then get data for the two matrices 
		int coltwo; int rowtwo; int row; int col;
		do {
			std::cout << "We are now inputting the size of your matrices. Please ensure that the sizes of your matrices match. " << std::endl;
			std::cout << dye::blue("Please input the number of rows that your first matrice has. ") << std::endl;
			std::cin >> row;
			std::cout << dye::blue("Please input the number of collumns that your second matrice has. ") << std::endl;
			std::cin >> col;
			std::cout << dye::blue("Please input the number of rows that your second matrice has. ") << std::endl;
			std::cin >> rowtwo;
			std::cout << dye::blue("Please input the number of collumns that your second matrice has. ") << std::endl;
			std::cin >> coltwo;

			if ((row != rowtwo) || (col != coltwo)) {
				std::cout << dye::red("Your two matrices cannnot be added. Please match input again, taking care to match the sizes of your matrices. ") << std::endl;
			}
		} while ((row != rowtwo) || (col != coltwo));
		//initialize the max width of a value
		int maxwidth(1);
		//inputting data to the first matrice
		std::cout << dye::blue("Input the data to your first matrice ") << std::endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int b = i;
				int c = j;
				std::cout << "Input value for row " << ++b << " and collumn " << ++c << " of your first matrice" << std::endl;
				double a; 
				std::cin >> a;

				while (a >= (pow(10, maxwidth))) {
					maxwidth++;
				}
				arrayone[i][j] = a;
			}
		}

		//inputting data to the second matrice
		std::cout << dye::blue("Input the data to your second matrice ") << std::endl;
		for (int i = 0; i < rowtwo; i++) {
			for (int j = 0; j < coltwo; j++) {
				int b = i;
				int c = j;
				std::cout << "Input value for row " << ++b << " and collumn " << ++c << " of your second matrice" << std::endl;
				double a; // = rand() % 100;
				std::cin >> a;
				while (a >= (pow(10, maxwidth))) {
					maxwidth++;
				}
				arraytwo[i][j] = a;
			}
		}

		maxwidth += 2;

		//Add the two matrices and store them in a two dimensional array
		std::cout << dye::blue("We are now adding your matrices...Please wait ") << std::endl;
		for (int i = 0; i < rowtwo; i++) {
			for (int j = 0; j < coltwo; j++) {
				arraythree[i][j] = arraytwo[i][j] + arrayone[i][j];
			}
		}

		//output the 2d array and the two arrays inputted  
		double max = (double)col * maxwidth;
		std::cout.precision(maxwidth);
		double diff = 10;
		std::cout << dye::blue("Here is the output for your matrices addition... ") << std::endl;
		std::cout <<
			std::setw(max) << std::left << " _" << std::right << "_"
			<< "          " <<
			std::setw(max) << std::left << "  _" << std::right << " _"
			<< "          " <<
			std::setw(max) << std::left << "  _" << std::right << " _" << std::endl;
		std::cout <<
			std::setw(max) << std::left << "| " << std::right << " |"
			<< "    +     " <<
			std::setw(max) << std::left << "| " << std::right << " |"
			<< "    =     " <<
			std::setw(max) << std::left << "| " << std::right << " |" << std::endl;
		printmatrice(arrayone, arraytwo, arraythree, row, col, maxwidth);
		std::cout <<
			std::setw(max) << std::left << "|_" << std::right << "_|"
			<< "          " <<
			std::setw(max) << std::left << "|_" << std::right << "_|"
			<< "          " <<
			std::setw(max) << std::left << "|_" << std::right << "_|" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "Do you have other matrices that you would like to add?	Reply yes if so. " << std::endl;
		std::cin >> reply;
	} 	while ((reply == "yes") || (reply == "Yes") || (reply == "YES"));
}
