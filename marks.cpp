#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

void display(vector<vector<double>>&marks){
    for(vector<double>ele:marks){
        cout<<endl;
        for(int val:ele){
            cout<<val<<" ";
        }
    }
}
int main(){
    
    vector<vector<int>>credits={{4,4,4,4,4,3,1,1,1,2},
                                {4,4,4,4,3,3,1,1,1,1,2},
                                {4,4,4,4,4,1,2,1,1},
                                {4,4,4,4,4,1,2,1,1},
                                {4,4,4,4,4,3,2,1,1,1},
                                {4,4,4,4,4,3,1,1,1,1,1}};

    int n=6;
    vector<double> swc(6,0);
    vector<double> swoc(6,0);
    vector<double> credit={28,28,25,25,28,28};
    double sumwc=0;
    double sumwoc=0;
    vector<vector<double>>marks(n,vector<double>());
    for(int i=0;i<6;i++){
        // cout<<"\nEnter marks of semester : "<<i+1<<endl;
        for(int j=0;j<credits[i].size();j++){
            double mark;
            cin>>mark;
            marks[i].push_back(mark);
            swc[i]+=(marks[i][j]*credits[i][j]);
            swoc[i]+=marks[i][j];
        }
        sumwc+=(double)swc[i]/credit[i];
        swc[i]=(double)swc[i]/credit[i];
        sumwoc+=(double)swoc[i]/(credits[i].size());
        swoc[i]=(double)swoc[i]/(credits[i].size());
    }
    display(marks);

    cout<<"\n===========================================\n";
    cout<<"\nIndividual percentage without credit: ";
    for(double ele:swoc){
        cout<<ele<<"   ";
    }

    cout<<"\n==========================================\n";
    cout<<"\nIndividual percentage with credits: ";
    for(double ele:swc){
        cout<<ele<<"    ";
    }

    cout<<"\n============================================\n";

    cout<<"\nTotal sum without credit: "<<sumwoc<<" and percentage without credit: "<<(double)sumwoc/6;
    cout<<"\nTotal sum with credit : "<<sumwc<<" and percentage with credit : "<<(double)sumwc/6;

    cout<<"\n============================================\n";
    return 0;
}