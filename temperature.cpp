/* This program converts a Fahrenheit temperature to a Celsius temperature and decides 
   if the temperature is above the boiling point or below the freezing point */
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

bool operator<(const Car& a, const Car& b){
    if (a.getMaker() < b.getMaker()){
        return true;
    }else if (a.getMaker() == b.getMaker()){
        if(a.getColor() < b.getColor()){
            return true;
        }
    }
    return false;
}

void print_cars(const std::map<int, std::vector<std::string> >& cars){
    std::map<int, std::vector<std::string> >::iterator itr;
    for(itr = cars.begin(); itr != cars.end(); itr++){
        std::cout<<"people who drive a " itr->first.getColor() + " " + itr->first.getMaker() ":"<<std::endl;
        for(int i = 0; i < itr->second.size(); i++){
            std::cout<<"  "+itr->second[i]<<std::endl;
        }
    }
}

bool remove_car(std::map<int, std::vector<std::string> >& cars, const std::string& name,
                const std::string& color, const std::string& maker){
    std::map<int, std::vector<std::string> >::iterator itr;
    for(itr = cars.begin(); itr != cars.end(); itr++){
        if(itr->first.getColor() == color && itr->first.getMaker() == maker){
            std::vector<std::string>::iterator itr2;
            for(itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++){
                if(*itr2 == name){
                    itr->second.erase(itr2);
                    return true;
                }
            }
        }
    }
    return false;
}

void insert_in_order(double x, std::queue<double>& q){
    if(q.empty()){
        q.push(x);
    }else {
        std::queue<double> temp;
        int count = 0;
        while (!q.empty()) {
            if (q.front() > x && count == 0) {
                temp.push(x);
                count++;
            }
            temp.push(q.front());
            q.pop();
        }
        q = temp;
    }
}


int main() {

}
