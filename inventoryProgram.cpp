#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


double calculateAverageStock(int* inventory, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(inventory + i);
    }
    return sum / size;
}

int countCriticalProducts(int* inventory, int size, double averageStock) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (*(inventory + i) < averageStock) {
            ++count;
        }
    }
    return count;
}


void findTopSellingProduct(int* inventory, int size) {
    int maxSales = -1;
    int topProductIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (*(inventory + i) > maxSales) {
            maxSales = *(inventory + i);
            topProductIndex = i;
        }
    }

    cout << "Top Selling Product: Product " << topProductIndex + 1 << " with sales volume " << maxSales << endl;
}


void findSecondBestSeller(int* inventory, int size) {
    int maxSales = -1;
    int secondMaxSales = -1;
    int bestIndex = -1;
    int secondBestIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (*(inventory + i) > maxSales) {
            secondMaxSales = maxSales;
            maxSales = *(inventory + i);
            secondBestIndex = bestIndex;
            bestIndex = i;
        } else if (*(inventory + i) > secondMaxSales) {
            secondMaxSales = *(inventory + i);
            secondBestIndex = i;
        }
    }

    cout << "Second Best-Selling Product: Product " << secondBestIndex + 1 
         << " with sales volume " << secondMaxSales << endl;
}


void sortByPopularity(int* inventory, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (*(inventory + i) < *(inventory + j)) {
                
                int temp = *(inventory + i);
                *(inventory + i) = *(inventory + j);
                *(inventory + j) = temp;
            }
        }
    }
}

int main() {
    srand(time(0));

    int size;
    cout << "Enter the desired size of the inventory array: ";
    cin >> size;

    int* inventory = new int[size];

    
    cout << "Product Quantities: ";
    for (int i = 0; i < size; ++i) {
        *(inventory + i) = rand() % 100; 
        cout << *(inventory + i) << " ";
    }
    cout << endl;

    
    double averageStock = calculateAverageStock(inventory, size);
    cout << "Average Stock Level: " << averageStock << endl;

    
    int criticalCount = countCriticalProducts(inventory, size, averageStock);
    cout << "Number of Critically Low Stock Products: " << criticalCount << endl;

    
    findTopSellingProduct(inventory, size);

    
    findSecondBestSeller(inventory, size);

    
    sortByPopularity(inventory, size);

    
    cout << "Sorted Inventory: ";
    for (int i = 0; i < size; ++i) {
        cout << *(inventory + i) << " ";
    }
    cout << endl;

    
    delete[] inventory;

    return 0;
}
