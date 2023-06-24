#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("usb_ps2.in" , "r" , stdin);

    long long totalCost = 0, totalPorts = 0;
    int usbPorts, ps2Ports, bothPorts, m;
    cin >> usbPorts >> ps2Ports >> bothPorts >> m;
    vector<int> usbMice, ps2Mice;
    int cost; string type;
    for(int i=0; i<m; i++){
        cin >> cost >> type;
        if(type == "USB") usbMice.push_back(cost);
        else ps2Mice.push_back(cost);
    }
    sort(usbMice.begin() , usbMice.end());
    sort(ps2Mice.begin() , ps2Mice.end());

    int curUSB = 0;
    while(curUSB != usbMice.size() && usbPorts != 0){
        totalCost += usbMice[curUSB];
        usbPorts--; curUSB++; totalPorts++;
    }

    int curPS2 = 0;
    while(curPS2 != ps2Mice.size() && ps2Ports != 0){
        totalCost += ps2Mice[curPS2];
        ps2Ports--; curPS2++; totalPorts++;
    }

    while(bothPorts != 0 && (curUSB != usbMice.size() || curPS2 != ps2Mice.size())){
        if(curPS2 == ps2Mice.size()){
            totalCost += usbMice[curUSB]; curUSB++;
        }
        else if(curUSB == usbMice.size()){
            totalCost += ps2Mice[curPS2]; curPS2++;
        }
        else if(usbMice[curUSB] <= ps2Mice[curPS2]){
            totalCost += usbMice[curUSB]; curUSB++;
        }
        else{
            totalCost += ps2Mice[curPS2]; curPS2++;
        }
        bothPorts--; totalPorts++;
    }

    cout << totalPorts << " " << totalCost << endl;
}