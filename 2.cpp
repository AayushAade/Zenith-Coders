#include <iostream>
#include <string>
#include <algorithm> // For std::swap

using namespace std;

const int n = 30;

// ---------- Product Class ----------
class Product {
public:
    int id;
    int price;
    int rating;
    int popularity;
    int reviews;

    // Default constructor (needed for arrays & copy)
    Product() : id(0), price(0), rating(0), popularity(0), reviews(0) {}

    // Parameterized constructor
    Product(int id, int price, int rating, int popularity, int reviews)
        : id(id), price(price), rating(rating), popularity(popularity), reviews(reviews) {}

    // Method to display a single product's details
    void display() const {
        cout << id << "\t\t" << price << "\t" << rating << "\t"
             << popularity << "\t\t" << reviews << endl;
    }
};

// ---------- Insertion Sort (Sorts by Price) ----------
void insertionSort(Product arr[], int size) {
    for (int i = 1; i < size; i++) {
        Product key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].price > key.price) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------- Bubble Sort (Sorts by Rating) ----------
void bubbleSort(Product arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].rating > arr[j + 1].rating) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// ---------- Selection Sort (Sorts by Popularity) ----------
void selectionSort(Product arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].popularity < arr[minIndex].popularity) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// ---------- Quick Sort (Sorts by Reviews) ----------
int partition(Product arr[], int low, int high) {
    int pivot = arr[high].reviews;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].reviews < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------- Binary Search (Searches for a product by Price) ----------
Product* binarySearchByPrice(Product arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].price == key) {
            return &arr[mid];
        }
        if (arr[mid].price < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return nullptr; // Return a null pointer if the key is not found
}

// ---------- Display All Products ----------
void displayAllProducts(const string& name, const Product arr[], int size) {
    cout << name << endl;
    cout << "------------------------------------------" << endl;
    cout << "ID\t\tPrice\tRating\tPopularity\tReviews\n";
    for (int i = 0; i < size; i++) {
        arr[i].display();
    }
    cout << endl;
}

int main() {
    Product products[n] = {
        Product(1, 100, 4, 11, 3503), Product(2, 150, 4, 7, 2048), Product(3, 200, 5, 43, 4426),
        Product(4, 250, 5, 89, 2352), Product(5, 300, 5, 79, 9414), Product(6, 350, 4, 52, 7325),
        Product(7, 400, 5, 31, 6128), Product(8, 450, 4, 68, 8390), Product(9, 500, 5, 25, 1294),
        Product(10, 550, 5, 96, 9901), Product(11, 600, 4, 14, 7854), Product(12, 650, 5, 88, 4561),
        Product(13, 700, 5, 40, 3749), Product(14, 750, 5, 63, 8123), Product(15, 800, 4, 21, 2098),
        Product(16, 850, 5, 75, 6547), Product(17, 900, 4, 53, 7432), Product(18, 950, 5, 18, 5789),
        Product(19, 1000, 5, 92, 8120), Product(20, 1050, 5, 34, 9234), Product(21, 1100, 4, 28, 4156),
        Product(22, 1150, 5, 60, 6347), Product(23, 1200, 5, 72, 8923), Product(24, 1250, 4, 49, 5210),
        Product(25, 1300, 5, 85, 7890), Product(26, 1350, 5, 10, 4321), Product(27, 1400, 4, 37, 6789),
        Product(28, 1450, 5, 55, 3456), Product(29, 1500, 5, 66, 9876), Product(30, 1550, 5, 30, 2543)
    };

    // --- Display Initial Data ---
    cout << "Original Product Data\n";
    cout << "------------------------------------------" << endl;
    cout << "ID\t\tPrice\tRating\tPopularity\tReviews\n";
    for (int i = 0; i < n; i++) {
        products[i].display();
    }
    cout << endl;

    // --- Sorting by different criteria ---

    Product productsByPrice[n];
    for (int i = 0; i < n; i++) productsByPrice[i] = products[i];
    insertionSort(productsByPrice, n);
    displayAllProducts("Products Sorted by Price (Insertion Sort)", productsByPrice, n);

    Product productsByRating[n];
    for (int i = 0; i < n; i++) productsByRating[i] = products[i];
    bubbleSort(productsByRating, n);
    displayAllProducts("Products Sorted by Rating (Bubble Sort)", productsByRating, n);

    Product productsByPopularity[n];
    for (int i = 0; i < n; i++) productsByPopularity[i] = products[i];
    selectionSort(productsByPopularity, n);
    displayAllProducts("Products Sorted by Popularity (Selection Sort)", productsByPopularity, n);

    Product productsByReviews[n];
    for (int i = 0; i < n; i++) productsByReviews[i] = products[i];
    quickSort(productsByReviews, 0, n - 1);
    displayAllProducts("Products Sorted by Reviews (Quick Sort)", productsByReviews, n);

    // --- Search functionality ---
    // cout << "--- Search by Price ---" << endl;
    
    // int searchPrice = 850;
    // Product* foundProduct = binarySearchByPrice(productsByPrice, 0, n - 1, searchPrice);
    // if (foundProduct != nullptr) {
    //     cout << "Found product with price " << searchPrice << ":" << endl;
    //     cout << "ID\t\tPrice\tRating\tPopularity\tReviews\n";
    //     foundProduct->display();
    // } else {
    //     cout << "Product with price " << searchPrice << " not found." << endl;
    // }

    return 0;
}
