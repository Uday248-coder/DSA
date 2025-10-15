#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int exp;
    float coef;
    struct Node* link;
}Node;

Node* create(int e, float c){
    Node* a=(Node*)malloc(sizeof(Node));
    a->exp=e;
    a->coef=c;
    a->link=NULL;
    return a;
}

Node* append(Node* head, int exp, float a){
    Node* new=create(exp,a);
    if(head==NULL)
        return new;
    Node* temp=head;
    while(temp->link!=NULL)
        temp=temp->link;
    temp->link=new;
    return head;
}

Node* Sort(Node* a){
    if(a==NULL || a->link==NULL)
        return a;

    Node* i=a;
    while(i!=NULL){
        Node* j=i->link;
        while(j!=NULL){
            if(j->exp > i->exp){
                //exp swap
                int t= i->exp;
                i->exp=j->exp;
                j->exp=t;
                //ceof swap
                t= i->coef;
                i->coef=j->coef;
                j->coef=t;
            }
            j=j->link;
        }
        i=i->link;
    }
    return a;
}

Node* add(Node* p1, Node* p2){
    Node* res = NULL;
    Node* head = res;
    while(p1!=NULL || p2!=NULL){
        if(p1->exp > p2->exp){
            res=p1;
            p1=p1->link;
        }
        else if(p2->exp > p1->exp){
            res=p2;
            p2=p2->link;
        }
        else{
            res=p1;
            res->coef+=p2->coef;
        }
        res=res->link;
    }
    while(p1!=NULL){
        res=p1;
        res=res->link;
        p1->link;
    }
    
    while(p2!=NULL){
        res=p2;
        res=res->link;
        p2->link;
    }
    return head;
}

Node* multiply(Node* p1, Node* p2){
    Node* res=NULL;
    for(Node* a=p1; a!=NULL;a=a->link){
        for(Node* b=p2; b!=NULL;b=b->link){
            int e = a->exp + b->exp;
            float c = a->coef * b->coef;
            
            Node* temp = res;
            while(temp!=NULL){
                if(temp->exp==e){
                    temp->coef=c;
                    break;
                }
                temp=temp->link;
            }
            if(temp==NULL){
                res=append(res,e,c);
            }
        }
    }
    return Sort(res);
}

Node* differentiate(Node* p){
    Node* t=p;
    while(t!=NULL){
        t->coef=t->coef * t->exp;
        t->exp -=1;
        t=t->link;
    }
    return p;
}

void evaluate(Node* head, float x){
    double sum=0.0;
    while(head!=NULL){
        sum += (head->coef)*(pow(x,head->exp));
        head=head->link;
    }
    printf("Solution of Polynomial at x=%.2f is :: %.4f",x,sum);
}

int main() {
    Node* poly = NULL;
    // for f(x)=2x^2 + 3x + 4 at x=2 
    poly = append(poly, 2.0, 2);  // 2x^2
    poly = append(poly, 3.0, 1);  // + 3x
    poly = append(poly, 4.0, 0);  // + 4

    evaluate(poly, 2); // Evaluate at x=2
    
    return 0;
}
