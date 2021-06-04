 #include <iostream>
 #include<bits/stdc++.h>
 using namespace std;

 ifstream fin;
 ofstream fout;

 struct node
 {

int data;

vector< vector<node* >* >v;

bool mark;

bool solved;
 };

 int edge_cost=0;

 void insert(node* root)
 {


fin>>root->data;



int or_no;

fin>>or_no;

for(int i=0;i<or_no;i++)

{

vector<node*>* ans=new vector<node*>;


int and_no;

fin>>and_no;

for(int j=0;j<and_no;j++)

{

node* n=new node;

n->solved=false;

n->mark=false;

insert(n);

(*ans).push_back(n);


}

root->v.push_back(ans);

}

 }
 void aostar(node* root)
 {

vector<node*>* min_ans=new vector<node*>;

(*min_ans).push_back(root);49























































while(!root->solved)
{
node* next_node=root;
stack<node*>st;
while(next_node && next_node->mark)
{
if((next_node->v).size()==0)
{
root->solved=true;
return;
}
int cost=INT_MAX;
st.push(next_node);
for(unsigned int i=0;i<next_node->v.size();i++)
{
vector<node*>*ans=(next_node->v)[i];
vector<node*> ans_v=*ans;
int temp_cost=0;
for(unsigned int j=0;j<(ans_v.size());j++)
{
node* n=ans_v[j];
temp_cost+=n->data;
}
if(temp_cost<cost)
{
min_ans=ans;
cost=temp_cost;
}
}
vector<node*> min_ans_v=*min_ans;
next_node=NULL;
for(unsigned int j=0;j<min_ans_v.size();j++)
{
if(min_ans_v[j]->mark)
{
next_node=min_ans_v[j];
break;
}
}
}
vector<node*> min_ans_v=*min_ans;
for(unsigned int j=0;j<min_ans_v.size();j++)
{
node* n=min_ans_v[j];
fout<<"Exploring :"<<n->data<<endl;
int final_cost=INT_MAX;
if(n->v.size()==0)
{
n->mark=true;
}
else{
for(unsigned int i=0;i<n->v.size();i++)
{
vector<node*>*ans=(n->v)[i];105
vector<node*> ans_v=*ans;

int temp_cost=0;

for(unsigned int j=0;j<(ans_v.size());j++)

{

node* n=ans_v[j];

temp_cost+=n->data;

temp_cost+=edge_cost;

}

if(temp_cost<final_cost)

{

final_cost=temp_cost;

}

}

n->data=final_cost;

n->mark=true;

}

fout<<"Marked : "<<n->data<<endl;

}


for(int i=0;i<20;i++) fout<<"=";

fout<<endl;

while(!st.empty())

{

node* n=st.top();

fout<<n->data<<" ";

st.pop();

int final_cost=INT_MAX;

for(unsigned int i=0;i<n->v.size();i++)

{

vector<node*>*ans=(n->v)[i];

vector<node*> ans_v=*ans;

int temp_cost=0;

for(unsigned int j=0;j<(ans_v.size());j++)

{

node* n=ans_v[j];

temp_cost+=n->data;

temp_cost+=edge_cost;

}

if(temp_cost<final_cost)

{

min_ans=ans;

final_cost=temp_cost;

}

}

n->data=final_cost;

}

fout<<endl;

next_node=root;


}
 }
 void print(node* root)
 {

if(root)

{

fout<<root->data<<" ";161
vector<vector<node*>* >vec=root->v;
for(unsigned int i=0;i<(root->v).size();i++)
{
vector<node*>* ans=(root->v)[i];
vector<node*> ans_v=*ans;
for(unsigned int j=0;j<ans_v.size();j++)
{
node* n=ans_v[j];
print(n);
}
}
}
return;
}
int main()
{
fin.open("input.txt");
fout.open("output.txt");
node* root=new node;
root->solved=false;
root->mark=false;
insert(root);
fin>>edge_cost;
fout<<"The tree is as follows :"<<endl;
print(root);
fout<<endl;
aostar(root);
fout<<"The minimum cost is : "<<root->data<<endl;
fin.close();
fout.close();
return 0;
}
