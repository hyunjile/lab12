#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

template <typename T>
class BSTree{
private:
  struct node
  {
    T item;
    node* left;
    node* right;
  };
  node* root;
  int length;
public:
  BSTree();
  ~BSTree();
  T* find(T v);
  bool empty() const;
  int size() const;
  void insert(T& v);
  void printInOrder();
  void printPreOrder();
  void inOrderPrintTraversal(struct node* t);
  void preOrderPrintTraversal(struct node* t);
  void inOrderPrintTraversal();
  void preOrderPrintTraversal();
};

template <typename T>
BSTree<T>::BSTree(){
  root = NULL;
  length = 0;
}

//Need to complete
template <typename T>
BSTree<T>::~BSTree(){
}

template <typename T>
T* BSTree<T>::find(T v){
  node *temp;

  if(root == NULL){
    cerr << "The tree is empty! Cannot find: " << v << endl;
    return NULL;
  }
  else{
    temp = root;
    while(temp != NULL){
      if(temp -> item == v){
	cout << "Found " << v <<": " << temp << endl;
	return NULL;
      }
      else{
	if(v > temp -> item)
	  temp = temp -> right;
	else
	  temp = temp -> left;
      }
    }//while
  }
  cout << v << " is not in the list" << endl;
  return NULL;
}

template <typename T>
bool BSTree<T>::empty() const{
  if(root == NULL)
    cout << "The tree is empty" << endl;
  else
    cout << "The tree is not empty" << endl;
  return root == NULL;
}

//Need to complete
template <typename T>
int BSTree<T>::size() const{
  cout << "Size: " << length << endl;
  return length;
}

template <typename T>
void BSTree<T>::insert(T& v){
  node *newNode = new node;
  node *parent;

  newNode -> item = v;
  newNode -> left = NULL;
  newNode -> right = NULL;
  parent = NULL;
  
  if(root == NULL)
    root = newNode;
  else{
    node *temp;
    temp = root;

    while(temp){
      parent = temp;
      if(newNode -> item > temp -> item)
	temp = temp -> right;
      else
	temp = temp -> left;
    } //while    

    if(newNode -> item < parent -> item)
      parent -> left = newNode;
    else
      parent -> right = newNode;
 
  }//else
}

template <typename T>
void BSTree<T>::printInOrder(){
  inOrderPrintTraversal(root);
}

template <typename T>
void BSTree<T>::printPreOrder(){
  preOrderPrintTraversal(root);
}

template <typename T>
void BSTree<T>::inOrderPrintTraversal(struct node *t){
  if(t != NULL){
    if(t -> left)
      inOrderPrintTraversal(t -> left);
    cout << t -> item << endl;
    length++;
    if(t -> right)
      inOrderPrintTraversal(t -> right);
  }
  else
    return;
}

template <typename T>
void BSTree<T>::preOrderPrintTraversal(struct node* t){
  if(t != NULL){
    cout << t -> item << endl;
    if(t -> left)
      preOrderPrintTraversal(t -> left);
    if(t -> right)
      preOrderPrintTraversal(t -> right);
  }
  else
    return;
}

template <typename T>
void BSTree<T>::inOrderPrintTraversal(){
  cerr << "Provide the node/list for in order" << endl;
}

template <typename T>
void BSTree<T>::preOrderPrintTraversal(){
  cerr << "Provide the node/list for pre order" << endl;
}

int main(int argc, char *argv[]){
  ifstream fin;
  BSTree<int>* list = new BSTree<int>;
  int variable;

  //part2  
  list->find(55);
  list->empty();
  list->size();
  list->inOrderPrintTraversal();
  list->preOrderPrintTraversal();
  

  if(argc < 2){
    cerr << "Please supply an input filename as a command line argument" << endl;
    return 1;
  }

  fin.open(argv[1]);
  if(fin.is_open()){
    while(!fin.eof()){
      fin >> variable;
      if(fin.eof())
	break;
      list->insert(variable);
      cout<<endl;
      cout<<"Print Pre Order: "<<endl;
      list->printPreOrder();
    }//while
  }//if
  else{
    cerr << argv[1] << " does not exist"<<endl;
  }
  cout<<endl;
  cout<<"Print In Order: "<<endl;
  list -> printInOrder();
  string input;
  input = argv[1];

  //part 3
  if(input == "btest2.txt"){ 
    cout<<endl;
    list->empty();
    list->size();
    list->find(2);
    list->find(7);
    list->find(20);
    list->find(8);
    list->find(11);
    list->size();
  }
  //part 4
  else if(input == "btest3.txt"){
    cout<<endl;
    list->empty();
    list->size();
    list->find(20);
    list->find(17);
    list->find(22);
    list->find(13);
    list->find(27);
    list->find(10);
    list->size();
  }

  return 0;
}
