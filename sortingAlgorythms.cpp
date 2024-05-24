#include <iostream>

void bubbleSort(int tab[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(tab[j] > tab[j+1]){
                std::swap(tab[j], tab[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        std::cout << tab[i] << " ";
    }
    std::cout << "\n";

}

void cocktailSort(int tab[], int n) {
    int bottom = 0;
    int top = n - 1;
    bool change = true;
    while (change)
    {
        change = false;
        for(int i = bottom; i < top; i++) {
            if(tab[i] > tab[i + 1]){
                std::swap(tab[i], tab[i + 1]);
                change = true;
            }
        }
        top--;
        for(int i = top; i > bottom; i--) {
            if(tab[i] < tab[i - 1]) {
                std::swap(tab[i], tab[i - 1]);
                change = true;
            }
        }
        bottom++;
    }
    for(int i = 0; i < n; i++){
        std::cout << tab[i] << " ";
    }
    std::cout << "\n";
}

void insertionSort(int tab[], int n) {
    int pom, j;
    for(int i = 1; i < n; i++) {
        pom = tab[i];
        j = i - 1;
        while(j >=0 && tab[j] > pom) {
            tab[j + 1] = tab[j];
            --j;
        }
        tab[j + 1] = pom;
    }
    for(int i = 0; i < n; i++){
        std::cout << tab[i] << " ";
    }
    std::cout << "\n";
}

void merge(int *array, int const left, 
		int const mid, int const right) 
{ 
	auto const subArrayOne = mid - left + 1; 
	auto const subArrayTwo = right - mid;  
	auto *leftArray = new int[subArrayOne], 
		*rightArray = new int[subArrayTwo]; 
	for (auto i = 0; i < subArrayOne; i++) 
		leftArray[i] = array[left + i]; 
	for (auto j = 0; j < subArrayTwo; j++) 
		rightArray[j] = array[mid + 1 + j];  
	auto indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 
	while (indexOfSubArrayOne < subArrayOne && 
		indexOfSubArrayTwo < subArrayTwo) 
	{ 
		if (leftArray[indexOfSubArrayOne] <= 
			rightArray[indexOfSubArrayTwo]) 
		{ 
			array[indexOfMergedArray] = 
			leftArray[indexOfSubArrayOne]; 
			indexOfSubArrayOne++; 
		} 
		else
		{ 
			array[indexOfMergedArray] = 
			rightArray[indexOfSubArrayTwo]; 
			indexOfSubArrayTwo++; 
		} 
		indexOfMergedArray++; 
	} 
	while (indexOfSubArrayOne < subArrayOne) 
	{ 
		array[indexOfMergedArray] = 
		leftArray[indexOfSubArrayOne]; 
		indexOfSubArrayOne++; 
		indexOfMergedArray++; 
	} 
	while (indexOfSubArrayTwo < subArrayTwo) 
	{ 
		array[indexOfMergedArray] = 
		rightArray[indexOfSubArrayTwo]; 
		indexOfSubArrayTwo++; 
		indexOfMergedArray++; 
	} 
} 
void mergeSort(int array[], 
			int const begin, 
			int const end) 
{  
	if (begin >= end) 
		return; 

	auto mid = begin + (end - begin) / 2; 
	mergeSort(array, begin, mid); 
	mergeSort(array, mid + 1, end); 
	merge(array, begin, mid, end);
    for(int i = 0; i < end + 1; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
} 

void quickSort(int tab[], int left, int right) {
    int i, j, pivot;
    i = (right + left) / 2;
    pivot = tab[i];
    tab[i] = tab[right];
    for (j = i = left; i < right; i++) {
        if (tab[i] < pivot) {
            std::swap(tab[i], tab[j]);
            j++;
        }
    }
    tab[right] = tab[j];
    tab[j] = pivot;
    if (left < j - 1) {
        quickSort(tab, left, j - 1);
    }
    if (j + 1 < right) {
        quickSort(tab, j + 1, right);
    }
}