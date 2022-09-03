class ParkingSystem {
public:
    int a=0, b=0 ,c=0;
    ParkingSystem(int big, int medium, int small) {
        a=big;
        b=medium;
        c=small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && a==0) return false;
        else  if(carType==2 && b==0) return false;
        else  if(carType==3 && c==0) return false;
        else if(carType==1){
            a--;
            return true;
        }
        else if(carType==2){
            b--;
            return true;
        }
        c--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */