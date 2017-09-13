#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <ctime>
#include <random>
#include "Sort.h"
#include "Movie.h" 

int main(){
	freopen("movie_titles2.txt", "r", stdin);
	freopen("results5.txt", "w", stdout);
	
	int n = 17770; //number of movies in the file
	int s, year;
	std::string title;
	char tr;
	int i, j, k;
	Movie * A = new Movie [n];

	int testValues[8] = {100, 250, 500, 750, 1000, 2500, 5000, 10000};

	for(i = 0; i < n; i++){
		std::cin >> s >> tr >> year >> tr;
		std::getline(std::cin, title);
		A[i] = Movie(s, year, title);
	}

	//different arrays to be sorted
	int t = 8;
	Movie ** testArrays = new Movie * [8];
	for(i = 0; i < t; i++){
		testArrays[i] = new Movie[testValues[i]];
		k = 0;
		for(j = 0; j < testValues[i]; j++){
			testArrays[i][j] = A[k++];
			if(k > n)
				k = 0;
		}
	}


	Movie * aux = new Movie[100000];
	clock_t tm;

	//---------------------data already sorted
	std::cout << "\n----In order----\n";
	for(i = 0; i < t; i++)
		std::sort(testArrays[i], testArrays[i] + testValues[i]);

		//selection sort
	//std::cout << "\nselection sort:\n\n";
	//for(i = 0; i < t; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::selectionSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0 << "\n";
	//}

	//	//insertion sort
	//std::cout << "\ninsertion sort:\n\n";
	//for(i = 0; i < 7; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::insertionSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0<< "\n";
	//}

	//	//bubble sort
	//std::cout << "\nbubble sort:\n\n";
	//for(i = 0; i < t; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::bubbleSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0<< "\n";
	//}

	////	//quick sort

	//std::cout << "\nquick sort:\n\n";
	//for(i = 0; i < t; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::quickSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0<< "\n";
	//}

	//	//merge sort
	//std::cout << "\nmerge sort:\n\n";
	//for(i = 0; i < t; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::mergeSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0<< "\n";
	//}

	//------------------data in inverse order
	std::cout << "\n----IverseOrder----\n";
	for(i = 0; i < t; i++)
		std::reverse(testArrays[i], testArrays[i] + testValues[i]);

	/*for(i = 0; i < 100; i++)
		std::cout << testArrays[0][i].title << "\n";
	std::cout << "\n";*/

	//	selection sort
	//std::cout << "\nselection sort:\n\n";
	//for(i = 0; i < t; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::selectionSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0<< "\n";
	//}

	//	//insertion sort
	//std::cout << "\ninsertion sort:\n\n";
	//for(i = 0; i < t; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::insertionSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0<< "\n";
	//}

	//	//bubble sort
	//std::cout << "\nbubble sort:\n\n";
	//for(i = 0; i < t; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::bubbleSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0<< "\n";
	//}

	//	//quick sort
	//std::cout << "\nquick sort:\n\n";
	//for(i = 0; i < t; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::quickSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0<< "\n";
	//}

	//	//merge sort
	//std::cout << "\nmerge sort:\n\n";
	//for(i = 0; i < t; i++){
	//	for(j = 0; j < testValues[i]; j++)
	//		aux[j] = testArrays[i][j];

	//	std::cout << "for n = " << testValues[i] << "\n";
	//	tm = clock();
	//	std::cout << "Comparisons: " << Sort<Movie>::mergeSortCount(aux, aux + testValues[i]) << "\n";
	//	tm = clock() - tm;
	//	std::cout << "time: " << ((float)tm)/CLOCKS_PER_SEC * 1000.0<< "\n";
	//}

	//-----------------data in random order
	std::cout << "\n-----randomorder----\n";
	Movie *** randomOrder = new Movie ** [30];

	unsigned seed = clock();

	for(k = 0; k < 30; k++){
		randomOrder[k] = new Movie * [t];
		for(i = 0; i < t; i++){
			randomOrder[k][i] = new Movie [testValues[i]];
			for(j = 0; j < testValues[i]; j++)
				randomOrder[k][i][j] = testArrays[i][j];
			//std::cout << "hola " << randomOrder[k][i][0].title << "\n";
		
			std::random_shuffle(randomOrder[k][i], randomOrder[k][i] + testValues[i]);

			//std::cout << "hola " << randomOrder[k][i][0].title << "\n";
		}
	}
	
	//selection sort
	/*std::cout << "selection sort:\n\n";

	for(i = 0; i < t; i++){
		float comparisons = 0.0;
		float ptm = 0.0;
		
		for(k = 0; k < 30; k++){
			for(j = 0; j < testValues[i]; j++)
				aux[j] = randomOrder[k][i][j];
			
			tm = clock();
			comparisons += Sort<Movie>::selectionSortCount(aux, aux + testValues[i]);
			tm = clock() - tm;
			ptm += ((float)tm)/CLOCKS_PER_SEC;
		}

		
		comparisons /= 30.0;
		ptm /= 30.0;

		std::cout << "Comparisons " << comparisons << "\n Time: " << ptm * 1000.0 << "\n";
	}
*/
		//insertion sort
	std::cout << "insertion sort:\n\n";
	for(i = 0; i < t; i++){
		float comparisons = 0.0;
		float ptm = 0.0;
		
		for(k = 0; k < 30; k++){
			for(j = 0; j < testValues[i]; j++)
				aux[j] = randomOrder[k][i][j];
			
			tm = clock();
			comparisons += Sort<Movie>::insertionSortCount(aux, aux + testValues[i]);
			tm = clock() - tm;
			ptm += ((float)tm)/CLOCKS_PER_SEC;
		}

		
		comparisons /= 30.0;
		ptm /= 30.0;

		std::cout << "Comparisons " << comparisons << "\n Time: " << ptm * 1000.0<< "\n";
	}

	//	//bubble sort
	//std::cout << "bubble sort:\n\n";
	//for(i = 0; i < t; i++){
	//	float comparisons = 0.0;
	//	float ptm = 0.0;
	//	
	//	for(k = 0; k < 30; k++){
	//		for(j = 0; j < testValues[i]; j++)
	//			aux[j] = randomOrder[k][i][j];
	//		
	//		tm = clock();
	//		comparisons += Sort<Movie>::bubbleSortCount(aux, aux + testValues[i]);
	//		tm = clock() - tm;
	//		ptm += ((float)tm)/CLOCKS_PER_SEC;
	//	}

	//	
	//	comparisons /= 30.0;
	//	ptm /= 30.0;

	//	std::cout << "Comparisons " << comparisons << "\n Time: " << ptm * 1000.0<< "\n";
	//}

	//	//quick sort
	//std::cout << "quick sort:\n\n";
	//for(i = 0; i < t; i++){
	//	float comparisons = 0.0;
	//	float ptm = 0.0;
	//	
	//	for(k = 0; k < 30; k++){
	//		for(j = 0; j < testValues[i]; j++)
	//			aux[j] = randomOrder[k][i][j];
	//		
	//		tm = clock();
	//		comparisons += Sort<Movie>::quickSortCount(aux, aux + testValues[i]);
	//		tm = clock() - tm;
	//		ptm += ((float)tm)/CLOCKS_PER_SEC;
	//	}

	//	
	//	comparisons /= 30.0;
	//	ptm /= 30.0;

	//	std::cout << "Comparisons " << comparisons << "\n Time: " << ptm * 1000.0 << "\n";
	//}

	//	//merge sort
	//std::cout << "merge sort:\n\n";
	//for(i = 0; i < t; i++){
	//	float comparisons = 0.0;
	//	float ptm = 0.0;
	//	
	//	for(k = 0; k < 30; k++){
	//		for(j = 0; j < testValues[i]; j++)
	//			aux[j] = randomOrder[k][i][j];
	//		
	//		tm = clock();
	//		comparisons += Sort<Movie>::mergeSortCount(aux, aux + testValues[i]);
	//		tm = clock() - tm;
	//		ptm += ((float)tm)/CLOCKS_PER_SEC;
	//	}

	//	
	//	comparisons /= 30.0;
	//	ptm /= 30.0;

	//	std::cout << "Comparisons " << comparisons << "\n Time: " << ptm * 1000.0 << "\n";
	//}
	

	return 0;
}