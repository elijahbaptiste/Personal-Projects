/*******************************************************************************
 * Car Dealership Management Project 
 * project by Elijah Baptiste
/******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Car {
    public:

    int year;
    string model;
    string brand;
    int carID;
    int seatingCapacity;
    bool isAvailable;
    int price;

    Car(int c_year, int c_SC, string c_model, string c_brand,int c_cid, int c_price ){
        year = c_year;
        model = c_model;
        brand = c_brand;
        carID = c_cid;
        seatingCapacity = c_SC;
        isAvailable = true;
        price = c_price;
    }
    Car(){
        year = NULL;
        model = "NULL";
        brand = "NULL";
        carID = NULL;
        seatingCapacity = NULL;
        isAvailable = false;
        price = NULL;
    }
    
    void PrintInfo(){
        cout << "(Car ID: " <<  carID << ") " <<year<< " "<< brand << " "<< model<< endl;
        cout << "it has a seating capacity of " << seatingCapacity;
        cout << " and it starts at a price of $" << price << endl;
        cout <<endl;
        _sleep(1000);
    }

    int getCID(){
        return carID;
    } 
    int getPrice(){
        return price;
    }
    string getBrand(){
        return brand;
    }
};

// int C is the Car ID. The array is just the car inventory array and 
//int E is the total number of cars in inventory
void returnCar(int c, Car d[], int e){
  int a;
  for(int b = 0; b < e; b++){
    if( d[b].getCID() == c)
    a = b;
  }
  if (d[a].isAvailable == true){
    cout << "It seems we already have that car in our inventory. Did you enter the right car ID?";

  }else if (d[a].isAvailable == false){
    d[a].isAvailable = true;
    cout << "Alright, that is all taken care of. Thank you for returning the vehicle."<<endl;
    cout << "Have a great day!";
  }
  else{
    cout << "sorry, that car ID isn't valid!";
  }
}


//int E is the total number of cars in inventory

void BuyCar(int e, Car d[]){
int a;
    int b;
string x;
    string y = "brand";
    string z = "price";

cout <<"OK great! And were you looking to buy at a specific Price point (type 'price') or were you lookin for a spcecific brand (type 'brand')";

                cin >> x;

    if( x == z){
        cout <<" Ok perfect!" <<endl;
         _sleep(500);
        cout <<"What is your budget for today? (type only number)";
        cin >> a;
        _sleep(500);
        cout << "Ok perfect! Here are all the cars we have in stock that is at or below your budget: "<<endl;
        _sleep(1000);
        for(int c =0; c < e; c++ ){
            if( (d[c].getPrice() <= a) && (d[c].isAvailable == true)){
                cout << (c+1) << ". "; 
                d[c].PrintInfo();
            }
        }
        _sleep(500);
        cout << "Which Car would you like to purchase? (type number corresponding to that car)";
        cin >> b;

        d[b-1].isAvailable = false;
        cout << "Ok Perfect!"<<endl;
        cout << "You selected ";
        d[b-1].PrintInfo(); 
        _sleep(1000);
        cout << "Thank you for your purchase today!";

    }else if( x == y){
        cout << "Ok perfect!"<<endl;
        _sleep(500);
        cout << "Which Brand of cars were you looking to buy today? (type brand name)";
        cin >> x;
        cout << "Ok perfect! Here are all the cars we have in stock that are from that manufactuor: "<<endl;
        _sleep(1000);
        for(int c =0; c < e; c++ ){
            if((d[c].getBrand() == x) && (d[c].isAvailable == true)){
                cout << (c+1) << ". "; 
                d[c].PrintInfo();
            }
        }
        _sleep(500);
        cout << "Which Car would you like to purchase? (type number corresponding to that car)";
        cin >> b;

        d[b-1].isAvailable = false;
        cout << "Ok Perfect!"<<endl;
        cout << "You selected ";
        d[b-1].PrintInfo(); 
        _sleep(1000);
        cout << "Thank you for your purchase today!";
    }
    else{
        cout << " Sorry, but that isn't a valid input."<<endl;
        cin.clear();
    }
}

//int E is the total number of cars in inventory
void sellCar(Car d[], int e){
    int x;
    int y; 
    int z; 
    int w;
    string v;
    string n;

    cout <<" Ok I just have to ask you a few questions about your car"<<endl;

    cout << "What Brand is your car? "<<endl;
    cin >> n;
    _sleep(1000);
    cout << "What model is your car? "<<endl;
    cin >> v;
    _sleep(1000);
    cout << "What year is your car? "<<endl;
    cin >> w;
    _sleep(1000);
    cout << "Ok and last question."<<endl;
    _sleep(500);
    cout << "What is the seating capacity for your vehicle?"<<endl;
    cin >> z;

//assinging a new unique car ID
    y = e+1;
//generating a price quote based on year of car
    if((10000 - ((2023 - w)* 750)) > 2000 && ((10000 - ((2023 - w)* 750)) < 10000)){
        x = 10000 - ((2023 - w)* 750);
    } else{
        x = 2000; 
    }
    _sleep(2000);
    cout << "Based on your vehicle's make, model, and year, we can offer you $" << x <<" for the vehicle."<< endl;
    _sleep(1000);
    cout << "Thanks for bringing in your car today. Have a nice day!";
    cout << endl;

    d[e].year = w;
    d[e].model = v;
    d[e].brand =n;
    d[e].carID =y;
    d[e].seatingCapacity =z;
    d[e].isAvailable =true;
    d[e].price = x + 1000;
}


int main(){

//Number of cars curently in Inventory    
int CarInventory = 10;
bool run = true;
string choice;

//initializes an object array with 30 spots. Represents the maximum
//car inventory size. Also initializes the 10 cars originaly in the car inventory
Car inventory[30] = { Car(2020, 4, "XCX", "BMW", 1,5000),
                      Car(2020, 4, "F-150", "Ford", 2,5000),
                      Car(2021, 4, "XCX", "BMW", 3,5000),
                      Car(2021, 6, "XCX", "BMW", 4,5000),
                      Car(2022, 2, "XCX", "Ford", 5, 5000),
                      Car(2022, 4, "XCX", "BMW", 6, 5000),
                      Car(2010, 4, "Altima", "Nissan", 7, 5000),
                      Car(2010, 2, "F-150", "Ford", 8, 5000),
                      Car(2012, 8, "XCX", "BMW", 9, 5000),
                      Car(2015, 6, "Altima Plus", "Nissan", 10, 5000)
};
while(run = true){
cout << "Hello and Welcome to the Car Dealership!"<<endl;
_sleep(500);
cout << "Were you looking to Buy (type buy), Sell (type sell), or Return a car (type return)? "<<endl;
cout << "type X to exit the program."<<endl;
cin >> choice;

if((choice == "buy")){ 
   _sleep(500);
   BuyCar(CarInventory, inventory);
   CarInventory--;
}else if(choice == "sell"){
    _sleep(500);
    sellCar(inventory, CarInventory);
    CarInventory++;

}else if (choice == "return"){
    int l;
    _sleep(500);
    cout << "Ok perfect! What is the Car ID for your vehicle?";
    cin >> l;
    
    returnCar(l,inventory, CarInventory);
}
else if(choice == "X"){
    run = false;
    return 0;
}
else{
    _sleep(500);
cout << "Sorry that wasn't a valid input";
}

cin.clear();
_sleep(10000);
}
return 0;    
}