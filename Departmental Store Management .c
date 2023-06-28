d //Departmental Store Management
 // including header files 
    #include <stdio.h> // for printf & scanf
    #include <string.h> // for string & its functions (strcpy,strcmp,strcat)
    #include <stdlib.h> // for the system("cls") which literally clears the console to make it cleaner
    #define C "cls" // this is instead of system("cls") it will be system(c);

    typedef struct { // goods struct
        int quantity;
        float price;
        char name[50];
    } goods;


    typedef struct { // store struct
        int quantity;
        goods Goods[100];
    } Store;
    
    typedef struct { // customer struct
    int id;
    char name[50];
    char address[100];
    char phone[15];
} customer;

    
    typedef struct { // customerList struct
    int quantity;
    customer Customers[100];
} CustomerList;

// global struct variables initialized to 0 in order to be modified by all functionas
    CustomerList myCustomers = { 0 }; 
    customer myCustomer;

    Store myStores = { 0 };
    goods myGoods;

    //Function to add goods or product to store
    void AddGood(Store* Stores, int storeNo, goods* Goods);
    // Function to list the quantities of sold goods
    void ListSoldGoodQuantities(Store* stores, int storeNo);
    // Function to display user options and handle their choices
    void userOptions(int storeNo);
    // Function to search for goods in the store
    void searchGoods(Store* Stores, int storeNo);
    // Function to mark goods as sold
    void Sold(Store* Stores, int storeNo);
    // Function to list sold-out goods
    void ListSoldOutGood(Store* stores, int storeNo);
    //  Function to save file
    void saveToFile(Store* myStores, int storeNo);
    // Function to load from file
    void loadFromFile(Store* stores, int storeNo);
    // Function to add customer to file
    void AddCustomer(CustomerList* Customers, customer* Customer);
    // Function to edit customer info
    void EditCustomer(CustomerList* Customers, int customerID);
    // Function to display customers
    void DisplayCustomers(customer* customers, int numCustomers);
    // Function to delete a customer from the customer list
    void DeleteCustomer(CustomerList* Customers, int customerID);

  int main() {
    int storeNo = 0;
    loadFromFile(&myStores, storeNo);//load data from file
    userOptions(storeNo);//start user interaction
    return 0;
        } 

void userOptions(int storeNo){
    int choice;
   
    while (1) {
        //display the avaliable option that user have
        printf("\n\t\t\t\t\tSelect action:\n");
        printf("\n\t\t\t\t\t1. Add Goods\n");
        printf("\n\t\t\t\t\t2. Display Goods\n");
        printf("\n\t\t\t\t\t3. Sell Goods\n");
        printf("\n\t\t\t\t\t4. Display Sold Out Goods\n");
        printf("\n\t\t\t\t\t5. Search Goods\n");
        printf("\n\t\t\t\t\t6. Add Customer\n");
        printf("\n\t\t\t\t\t7. Edit Customer\n");
        printf("\n\t\t\t\t\t8. Display Customer\n");
        printf("\n\t\t\t\t\t9. Delete Customer\n");
        printf("\n\t\t\t\t\t10. Save Data\n");
        printf("\n\t\t\t\t\t11. Load Data\n");
        printf("\n\t\t\t\t\t12. Terminate :(\n");
        printf("\n\t\t\t\t\t---------------------------------------");
        printf("\n");
        printf("\t\t\t\t\tEnter Action : ");
        scanf("%d", &choice);
        system(C);//clear the console screen
        if(choice==12){
            system(C);
            printf("\n\n\n\t\t\t\t\t    Terminating StoreMasters program.......   \n\n\n");
            printf("\n\n\n\t\t\t\t\t    Thanks for using StoreMasters!   \n\n\n");
            exit(0);
            break;
        }
        else if(choice>12){system(C);printf("\t\t\t\t\t\tINVALID CHOICE!!\n");break;}
        //to keep the user to select a store
        printf("\n\t\t\t\t\tSelect store:\n");
        printf("\n\t\t\t\t\t1. Crafted Curiosities: Handcraft\n");
        printf("\n\t\t\t\t\t2. The Modern Maven: Home Decor\n");
        printf("\n\t\t\t\t\t3. MegaMart Express: Hyper Market\n");
        printf("\n\t\t\t\t\t4. GadgetHub: Technology Gadgets\n");
        printf("\n\t\t\t\t\t5. Bookworm Corner: Book Shop\n");
        printf("\n\t\t\t\t\t6. Terminate:((\n");
        printf("\n\t\t\t\t\t---------------------------------------");
        printf("\n");
        printf("\n\t\t\t\t\tEnter Store : ");
        scanf("%d", &storeNo);
        if (storeNo < 1 || storeNo >6) {
            printf("\t\t\t\t\t\tINVALID STORE NUMBER!!\n"); // validation incase the user enters a store number that doesn't exist
            continue;
        }
        else if(storeNo==6){
            printf("\n\n\n\t\t\t\t\t    Terminating StoreMasters program.......   \n\n\n");
            printf("\n\n\n\t\t\t\t\t    Thanks for using StoreMasters!!!   \n\n\n");
            exit(0);
        }
        // switch cases that call function, it's in infinite loop to trap the user until he basically enters a valid input & to finish his actions
        switch(choice){
        case 1:
            AddGood(&myStores, storeNo, &myGoods);
            break;
        case 2:
            system(C);
            ListSoldGoodQuantities(&myStores, storeNo);
            break;
        case 3:
            system(C);
            Sold(&myStores, storeNo);
            break;
        case 4:
            system(C);
            ListSoldOutGood(&myStores, storeNo);
            break;
        case 5:
            system(C);
            searchGoods(&myStores, storeNo);
            break;
        case 6:
           {
           customer newCustomer;
           AddCustomer(&myCustomers, &newCustomer);
           break;
        }
       case 7:
          {
    // declaring customerId and taking info.
    int customerID;
    printf("\n\t\t\t\t\tEnter customer ID to edit: ");
    scanf("%d", &customerID);
    EditCustomer(&myCustomers, customerID);
    break;
         }
      case 8:
      {
    DisplayCustomers(myCustomers.Customers, myCustomers.quantity);
    break;
       }      
      case 9:
          {
    int customerID;
    printf("\n\t\t\t\t\tEnter customer ID to delete: ");
    scanf("%d", &customerID);
   DeleteCustomer(&myCustomers, customerID);
    break;
            }
        case 10:
            system(C);
            saveToFile(&myStores, storeNo);
            break;
        case 11:
            system(C);
            loadFromFile(&myStores, storeNo);
            break;
        default:
            system(C);
            printf("\n\t\t\t\t\tERROR! INVALID ACTION CHOICE!!!!"); // validation for customer
            continue;

        }
    }
}
void AddGood(Store* Stores, int storeNo, goods* Goods) {
        printf("\n\t\t\t\t\tEnter the name of the goods: ");
        scanf("%s", Goods->name);
        printf("\n\t\t\t\t\tEnter the quantity of the goods: ");
        scanf("%d", &(Goods->quantity));
        printf("\n\t\t\t\t\tEnter the price of the goods: ");
        scanf("%f", &(Goods->price));

        int index = Stores[storeNo - 1].quantity; // Get the current quantity as the index
        strcpy(Stores[storeNo - 1].Goods[index].name, Goods->name);
        Stores[storeNo - 1].Goods[index].quantity = Goods->quantity; // Assign the correct quantity
        Stores[storeNo - 1].Goods[index].price = Goods->price;
        Stores[storeNo - 1].quantity++;
    }
void ListSoldGoodQuantities(Store* stores, int storeNo) {
        printf("\n\t\t\t\t\tGoods in Store #%d:\n", storeNo);
        printf("\n\t\t\t\t\tQuantity:\tPrice:\tName:\n");

        for (int i = 0; i < stores[storeNo - 1].quantity; i++) {
            goods* currentGood = &(stores[storeNo - 1].Goods[i]);
            printf("\n\t\t\t\t\t%d\t\t%.2f\t%s\n", currentGood->quantity, currentGood->price, currentGood->name);
        }
    }
void searchGoods(Store* stores, int storeNo) {
    // making user enter the goods name and searching for it with a loop
    char searchName[50];
    printf("\n\t\t\t\t\tEnter the name of the good to search: ");
    scanf("%s", searchName);


    int found = 0;
    goods* currentGood;
    for (int i = 0; i < stores[storeNo - 1].quantity; i++) {
        currentGood = &(stores[storeNo - 1].Goods[i]);
        if (strcmp(currentGood->name, searchName) == 0) { // this is to check whether the user-entered name matches the actual name thats inside the program
            printf("\n\t\t\t\t\tStore: %d\n", storeNo);
            printf("\n\t\t\t\t\tName: %s\n", currentGood->name);
            printf("\n\t\t\t\t\tPrice: %.2f\n", currentGood->price);
            printf("\n\t\t\t\t\tAvailable quantity: %d\n", currentGood->quantity);
            found = 1;
            break;
        }
    }


    if (!found) {
        printf("\t\t\t\t\t\t\t\t\t\tGood not found!\n");
    }
}
void Sold(Store* Stores, int storeNo) {
    //searching for the good name first to sell
    char searchName[50];
    printf("\n\t\t\t\t\tEnter the name of the good to sell: ");
    scanf("%s", searchName);

    int found = 0; // this is like a flag to update once goods are found
    goods* currentGood;
    for (int i = 0; i < Stores[storeNo - 1].quantity; i++) {
        currentGood = &(Stores[storeNo - 1].Goods[i]);
        if (strcmp(currentGood->name, searchName) == 0) {
            found = 1;
            int sellQuantity;
            printf("\n\t\t\t\t\tEnter the quantity to sell: ");
            scanf("%d", &sellQuantity);
            if (sellQuantity > currentGood->quantity) {
                printf("\n\t\t\t\t\tERROR: Not enough quantity available!\n");
                return;
            }
            currentGood->quantity -= sellQuantity;
            printf("\n\t\t\t\t\tQuantity %d of %s sold from Store #%d.\n", sellQuantity, currentGood->name, storeNo);
            break;
        }
    }

    if (!found) {
        printf("\n\t\t\t\t\t Whoops!, good is not found!\n");
    }
}
void ListSoldOutGood(Store* stores, int storeNo) {
    printf("\n\t\t\t\t\tSold out goods in Store #%d:\n", storeNo);
    printf("\n\t\t\t\t\tQuantity:\tPrice:\tName:\n");

    for (int i = 0; i < stores[storeNo - 1].quantity; i++) { // loop to display the sold out good
        goods* currentGood = &(stores[storeNo - 1].Goods[i]);
        if (currentGood->quantity == 0) {
            printf("\n\t\t\t\t\t%d\t\t%.2f\t%s\n", currentGood->quantity, currentGood->price, currentGood->name);
        }
    }
}
void saveToFile(Store* stores, int storeNo) {
    // this is incase the user wants to terminate and he want the data to be saved on his progress
    FILE* fp;
    fp = fopen("store_data.txt", "w");
    fprintf(fp, "%d\n", stores[storeNo - 1].quantity);
    for (int i = 0; i < stores[storeNo - 1].quantity; i++) {
        goods* currentGood = &(stores[storeNo - 1].Goods[i]);
        fprintf(fp, "%d %f %s\n", currentGood->quantity, currentGood->price, currentGood->name);
    }
    fclose(fp);
    printf("\n\t\t\t\t\tData saved to file!\n");
}
void loadFromFile(Store* stores, int storeNo) {
    // this is incase the user wants to terminate and he want the data to be  loaded on his progress
    FILE* fp;
    fp = fopen("store_data.txt", "r");
    if (fp == NULL) {
        printf("\n\t\t\t\t\tERROR: File not found!\n");
        return;
    }
    int quantity;
    fscanf(fp, "%d", &quantity);
    stores[storeNo - 1].quantity = quantity;
    for (int i = 0; i < quantity; i++) {
        goods* currentGood = &(stores[storeNo - 1].Goods[i]);
        fscanf(fp, "%d %f %s", &(currentGood->quantity), &(currentGood->price), currentGood->name);
    }
    fclose(fp);
    printf("\n\t\t\t\t\tData loaded from file!\n");
}
void AddCustomer(CustomerList* Customers, customer* Customer) {
    // making user enter the customer details
    printf("\n\t\t\t\t\tEnter customer details:\n");
    printf("\n\t\t\t\t\tID: ");
    scanf("%d", &Customer->id);
    printf("\n\t\t\t\t\tName: ");
    scanf("%s", Customer->name);
    printf("\n\t\t\t\t\tAddress: ");
    scanf("%s", Customer->address);
    printf("\n\t\t\t\t\tPhone: ");
    scanf("%s", Customer->phone);
    Customers->Customers[Customers->quantity] = *Customer;
    Customers->quantity++;
    printf("\n\t\t\t\t\tCustomer added successfully!\n");
}
void EditCustomer(CustomerList* Customers, int customerID) {
    int i;
    for (i = 0; i < Customers->quantity; i++) { // loop to print all customer infos that were added by user
        if (Customers->Customers[i].id == customerID) {
            printf("\n\t\t\t\t\tEnter new details for customer %d:\n", customerID);
            printf("\n\t\t\t\t\t1. Name: %s\n", Customers->Customers[i].name);
            printf("\t\t\t\t\t2. Address: %s\n", Customers->Customers[i].address);
            printf("\t\t\t\t\t3. Phone: %s\n", Customers->Customers[i].phone);
            printf("\t\t\t\t\t4. Exit\n");
            int choice;
            do {
                printf("\n\t\t\t\t\tEnter your choice (1-4): ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printf("\n\t\t\t\t\tEnter new name: ");
                        scanf("%s", Customers->Customers[i].name);
                        printf("\n\t\t\t\t\tName updated successfully!\n");
                        break;
                    case 2:
                        printf("\n\t\t\t\t\tEnter new address: ");
                        scanf("%s", Customers->Customers[i].address);
                        printf("\n\t\t\t\t\tAddress updated successfully!\n");
                        break;
                    case 3:
                        printf("\n\t\t\t\t\tEnter new phone number: ");
                        scanf("%s", Customers->Customers[i].phone);
                        printf("\n\t\t\t\t\tPhone number updated successfully!\n");
                        break;
                    case 4:
                        return;
                    default:
                        printf("\n\t\t\t\t\tInvalid choice. Please try again.\n"); // validation for customer info choice.
                        break;
                }
            } while (choice < 1 || choice > 4);
        }
          
    else
            {
            printf("\n\t\t\t\t\tCustomer not found!\n");
            }
        }
    }

void DisplayCustomers(customer* customers, int numCustomers){
    printf("\nCustomer ID\tName\t\tPhone Number\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < numCustomers; i++) // Loop to print the customer obv
    {
        printf("%d\t\t%s\t\t%s\n", customers[i].id, customers[i].name, customers[i].phone);
    }
}
void DeleteCustomer(CustomerList* Customers, int customerID) {
    int i, j;
    for (i = 0; i < Customers->quantity; i++) {
        if (Customers->Customers[i].id == customerID) {
            for (j = i; j < Customers->quantity - 1; j++) {
                Customers->Customers[j] = Customers->Customers[j + 1];
            }
            Customers->quantity--;
            printf("\n\t\t\t\t\tCustomer deleted successfully!\n");
            return;
        }
    }
    printf("\n\t\t\t\t\tCustomer with ID %d not found.\n", customerID); // if the customer Id was not found
} 
