/*******************************************************************************
 * Dating App with profile photos
 * project by Elijah Baptiste
/******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>


using namespace std;



//Global arrays that will host the choices users will select when they create an account.
char *interests[] = {"Volleyball", "Table Tennis", "Roller Skating", "Cycling", "Guitar", "Piano", "Bowling", "Golfing", 
"BasketBall", "Skateboarding", "Gymnastics", "Piano", "Sky Diving", "Fencing", "Hiking", "Surfing", "Rowing/Sailing"};

char *pref[] = { "Straight", "Gay", "Bisexual", "Other"};

char* origin[] = { "Boston", "New York", "Los Angeles", "Miami", "Chicago", "Houston", "San Antonio", "Philadelphia", "Jacksonvile", 
"Dallas", "San Francisco", "Seattle", "Nashville", "Denver", "Portland", "Atlanta"}; 

char * gend[] = { "Male", "Female", "Non-Binary", "Other", "Prefer Not to Say"};

char * randnames[] = {"Jane", "John", "Mike", "Susan", "Taylor", "Gino", "Andy", "Kimberly", "Liam", "Noah", "Oliver", "James", "Olivia", "Emma", "Charlotte",
"Amelia", "Sophia", "Mia", "Isabella", "Ava", "Evelyn", "Luna", "William", "Lucas", "Henry", "Ben", "Adrian", "Aidan", "Annalise", "Bella", "Chandler",
"Haley", "Jasper", "Amaya", "Idris", "Kiana", "Violet", "Kira", "Rima", "Soren"};   

class Profile{
   
   public:

    int age;
    string name;
    string city;
    int height;
    string gender;
    string orientation;
    char *personalInterests[3];


    Profile(){
        age = (rand() % 53) + 18;
        height = (rand() % 45) + 40;
        city = origin[rand() % 16];
        name = randnames[rand() % 40];
        gender = gend[rand() % 5];
        orientation = pref[rand() % 4];

        int a = rand() % 17;
        int b = rand() % 17;
        while ( b == a){
            b = rand() % 17;
        }
        int c = rand() % 17;
        while (c == b || c == a)
        {
        c = rand() % 17;
        }

        personalInterests[0] = interests[a];
        personalInterests[1] = interests[b];
        personalInterests[2] = interests[c];
    }

//int a is age. string b is name. Int c will be the index of the city chosen. int d is height in inches. int e and f will 
//be the gender and orientation chosen from the global arrays. int g-k will be the 5 personal interests chosen from the global arrays.
    Profile(int a, char B[20], int c, int d, int e, int f, int g, int h, int i){
        age = a;
        height = d;
        city = origin[c];
        name = B;
        gender = gend[e];
        orientation = pref[f];
        personalInterests[0] = interests[g];
        personalInterests[1] = interests[h];
        personalInterests[2] = interests[i];
    }

    void PrintInfo(){
       cout << name << " (" << gender << "), Age: " << age << " years old, From " << city<<endl;
       cout << "Interested in : " << personalInterests[0]  << ", " << personalInterests[1]  << ", and "<< personalInterests[2] << endl;
    }

    int getAge(){
        return age;
    }
    
    string getCity(){
    return city;
    }
    string getGender(){
        return gender;
}

    };


int main(){
    // int NumProfiles = 200;
    int a;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int k;
    char i[20];

    cout << "Hello! Welcome to Dream Matchmaker.io"<<endl;
    _sleep(750);
    cout << "First, we're gonna have to ask you some questions to complete your Profile"<<endl;
    _sleep(750);
    cout <<"What is your name (First Name)?"<<endl;
    cin >> i;
    _sleep(750);
    cout <<"How old are you" <<endl;
    cin >> a;

    if( a < 18){
        cout << "Sorry, Our App is only for Users age 18 and Older!"<<endl;
        return 1;
    }
    _sleep(750);
    cout <<"Which City are you from? (Type Number that corresponds)" <<endl;
    for(int r = 0; r < 16; r++){  
        cout << r+1 << ". " << origin[r]<<endl;
        _sleep(100);
    }
    cin >> c;
    c = c-1;
    _sleep(750);

    cout <<"What is your gender?" <<endl;
    for(int t = 0; t <5; t++){
        cout << t+1 << ". " << gend[t]<<endl;
        _sleep(500);  
    }
    cin >> e;
    e = e-1;
    _sleep(750);
    cout <<"What is your Sexual Preference" <<endl;
     for(int t = 0; t <4; t++){
        cout << t+1 << ". " << pref[t]<<endl;
        _sleep(500);  
    }
    cin >> f;
    f = f-1;
    _sleep(750);
    cout <<"How tall are you (inches)" <<endl;
    cin >> d;
    d = d-1;
    _sleep(750);
    cout <<"Ok your gonna pick three of these activities that you are most intersted in" <<endl;
         for(int t = 0; t <17; t++){
        cout << t+1 << ". " << interests[t]<<endl;
        _sleep(100);  
    }
    _sleep(750);
    cin >> g;
    cin >> h; 
    cin >> k;
 
    g = g-1;
    h = h-1;
    k = k-1;

    cout << "Ok give us a moment while we finalize your account and add you to the database."<<endl;
    Profile people[1000] = {Profile(a,i,c,d,e,f,g,h,k)};

    _sleep(2000); 
    cout << "Done!"<<endl;
    _sleep(1500);
    cout << "Here is a look at your profile: "<<endl;
    _sleep(1000);
 
    people[0].PrintInfo();
    _sleep(2000);
    cout << "Looking Good!"<<endl;
    _sleep(750);

    int pref1;
    int pref2;

    cout << "Ok with that out of the way, lets move on!"<<endl;
    _sleep(750);
    cout << "What kind of qualities do you look for in a partner?"<<endl;
    _sleep(750);
    cout << "Do they have to be from the same city (1), same age (2)?"<<endl;
    _sleep(750);
    cout << "Are you interested in a specific gender (3),or should they share the same interests (4)?"<<endl;
    cout << "Feel free to select any two!"<<endl;

    cin >> pref1 >> pref2;
    
    _sleep(200);
    cout << "Ok awesome! Let me search through the database and find all the potential partners that meet your criteria."<<endl;
    _sleep(2000);
    cout << "Ok i got a list of potential matches. Let me know which one peaks your interest by typing the number next to their name."<<endl;


    vector<Profile> p1;
    vector<Profile> p2;
      
        if(pref1 == 2){
            for(int v =1; v < 200; v++){
                if(people[v].age == people[0].age){
                   p1.push_back(people[v]);
                }
            }
        }else if(pref1 == 1){
            for(int v =1; v < 200; v++){
                if(people[v].city == people[0].city){
                    p1.push_back(people[v]);
                }
            }
        }else if(pref1 == 3){
            for(int v =1; v < 200; v++){
                if(people[v].gender == people[0].gender){
                    p1.push_back(people[v]);
                }
            }
        }else if(pref1 == 4){
            for(int v =1; v < 200; v++){
                int q = 0;
                for(int a = 0; a < 3; a++){
                    for(int b= 0; b <3; b++){
                        if(people[v].personalInterests[a] == people[0].personalInterests[b]){
                        q++;
                        }
                    } 
                }
                if( q >= 1){
                    p1.push_back(people[v]);
                }
            }
        }

        // for(int a =0; a < p1.size();a++){
        //     p1.at(a).PrintInfo();
        // }

        if(pref2 == 2){
            for(int v =0; v < p1.size(); v++){
                Profile temp = p1.at(v);
                if(temp.age == people[0].age){
                   p2.push_back(p1.at(v)); 
                }
            }
        }else if(pref2 == 1){
            for(int v =0; v < p1.size(); v++){
                Profile temp = p1.at(v);
                if(temp.city == people[0].city){
                   p2.push_back(p1.at(v)); 
                }
            }
        }else if(pref2 == 3){
            for(int v =0; v < p1.size(); v++){
                Profile temp = p1.at(v);
                if(temp.gender == people[0].gender){
                   p2.push_back(p1.at(v)); 
                }
            }
        }else if(pref2 == 4){
            for(int v =0; v < p1.size(); v++){
                Profile temp = p1.at(v);
                int q = 0;
                for(int a = 0; a < 3; a++){
                    for(int b =0; b < 3; b++){
                    if(p1.at(v).personalInterests[a] == people[0].personalInterests[b]){
                     q++;
                    }
                    }
                    }
                if( q >= 1){
                p2.push_back(p1.at(v));
                }
            }  
        }

     for(int o = 0; o < p2.size(); o++){
        cout << (o+1) << ". ";
        p2.at(o).PrintInfo();
        cout <<endl;
     }
return 0;
}