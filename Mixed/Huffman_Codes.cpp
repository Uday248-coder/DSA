#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f): ch(c), freq(f), left(NULL), right(NULL){}
    Node(Node* a, Node* b): ch('#'), freq(a->freq+b->freq), left(a), right(b){}
};

void sorter(vector<Node*>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int minind=i;
        for(int j=i+1;j<n;j++){
            if(arr[i]->freq > arr[j]->freq)
                minind = j;
        }
        swap(arr[i],arr[minind]);
    }
}

void printCodes(Node* a, string code){
    if(!a) return;
    if(!a->left && !a->right){
        cout << a->ch << " : " << code << endl;
        return;
    }
    printCodes(a->left, code+"0");
    printCodes(a->right, code+"1");
}

int main(void){
    cout << "Enter number of elements" << endl;
    int n;
    cin >> n;
    if(n<=0){
        cout<<"No characters.";
        return 0;
    }
    vector<Node*> arr;
    for(int i=0;i<n;i++){
        char c;
        int f;
        cin >> c >> f;
        arr.push_back(new Node(c,f));
    }
    while(arr.size() >1){
        sorter(arr);
        Node* smallest = arr[0];
        Node* secondsmallest = arr[1];
        Node* root=new Node(smallest,secondsmallest);
        arr.erase(arr.begin()); 
        arr.erase(arr.begin()); 
        arr.push_back(root); 
    }
    cout << "HuffMan Codes: " << endl;
    printCodes(arr[0],"");
    return 0;
}
