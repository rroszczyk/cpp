#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 30; // Liczba węzłów

// Typ węzłów drzewa RBT

struct RBTNode
{
  RBTNode* up;
  RBTNode* left;
  RBTNode* right;
  int key;
  char color;
};

// Definicja typu obiektowego TRBTree
class TRBTree
{
  private:
    RBTNode S;             // Węzeł strażnika
    RBTNode* root;         // Korzeń drzewa czerwono-czarnego
    string cr, cl, cp;     // Łańcuchy do znaków ramek

    void printRBT(string sp, string sn, RBTNode* p); // Wypisuje drzewo

  public:
    TRBTree();                      // Konstruktor klasy
    ~TRBTree();                     // Destruktor klasy
    void DFSRelease(RBTNode* p);    // Usuwa rekurencyjnie drzewo
    void print();                   // Wypisuje drzewo
    RBTNode* findRBT(int k);        // Wyszukuje węzeł o kluczu k
    RBTNode* minRBT(RBTNode* p);    // Wyszukuje najmniejszy węzeł w p
    RBTNode* succRBT(RBTNode* p);   // Wyszukuje następnik p
    void rot_L(RBTNode* A);         // Rotacja w lewo względem A
    void rot_R(RBTNode* A);         // Rotacja w prawo względem A
    void insertRBT(int k);          // Wstawia węzeł o kluczu k
    void removeRBT(RBTNode* X);     // Usuwa węzeł X
};

// Konstruktor drzewa
//-------------------
TRBTree::TRBTree()
{
  cr = cl = cp = "  ";
  cr[0] = '/'; cr[1] = '-';
  cl[0] = '\''; cl[1] = '-';
  cp[0] = '|';
  S.color = 'B';             // Inicjujemy pierwszy element
  S.up    = &S;
  S.left  = &S;
  S.right = &S;
  root    = &S;              // Korzeń wskazuje pierwszy element
}

// Destruktor drzewa
//------------------
TRBTree::~TRBTree()
{
  DFSRelease(root);          // Rekurencyjnie usuwamy węzły
}

// Usuwa rekurencyjnie drzewo czerwono-czarne
//-------------------------------------------
void TRBTree::DFSRelease(RBTNode* p)
{
  if (p != &S)
  {
    DFSRelease(p->left);    // usuwamy lewe poddrzewo
    DFSRelease(p->right);   // usuwamy prawe poddrzewo
    delete p;               // usuwamy sam węzeł
  }
}

// Wypisuje zawartość drzewa
//--------------------------
void TRBTree::printRBT(string sp, string sn, RBTNode* p)
{
  string t;

  if (p != &S)
  {
    t = sp;
    if (sn == cr) t[t.length() - 2] = ' ';
    printRBT(t+cp, cr, p->right);

    t = t.substr(0, sp.length() - 2);
    cout << t << sn << p->color << ":" << p->key << endl;

    t = sp;
    if (sn == cl) t[t.length() - 2] = ' ';
    printRBT(t+cp, cl, p->left);
  }
}

// Wypisuje zawartość drzewa
//--------------------------
void TRBTree::print()
{
  printRBT("", "", root);
}

// Wyszukuje węzeł o kluczu k
// Jeśli węzeł nie zostanie znaleziony, to zwraca
// wskazanie puste NULL
//-----------------------------------------------
RBTNode* TRBTree::findRBT(int k)
{
  RBTNode* p;

  p = root;
  while((p != &S) &&(p->key != k))
    if (k < p->key) p = p->left;
    else           p = p->right;
  if (p == &S) return NULL;
  return p;
}

// Wyszukuje najmniejszy węzeł w poddrzewie
// o korzeniu p
//-----------------------------------------
RBTNode* TRBTree::minRBT(RBTNode* p)
{
  if (p != &S)
    while(p->left != &S) p = p->left;
  return p;
}

// Zwraca następnik p
//-------------------
RBTNode* TRBTree::succRBT(RBTNode* p)
{
  RBTNode* r;

  if (p != &S)
  {
    if (p->right != &S) return minRBT(p->right);
    else
    {
      r = p->up;
      while((r != &S) &&(p == r->right))
      {
        p = r;
        r = r->up;
      }
      return r;
    }
  }
  return &S;
}

// Wykonuje rotację w lewo względem A
//-----------------------------------
void TRBTree::rot_L(RBTNode* A)
{
  RBTNode* B,* p;

  B = A->right;
  if (B != &S)
  {
    p = A->up;
    A->right = B->left;
    if (A->right != &S) A->right->up = A;

    B->left = A;
    B->up = p;
    A->up = B;

    if (p != &S)
    {
      if (p->left == A) p->left = B; else p->right = B;
    }
    else root = B;
  }
}

// Wykonuje rotację w prawo względem A
//------------------------------------
void TRBTree::rot_R(RBTNode* A)
{
  RBTNode* B,* p;

  B = A->left;
  if (B != &S)
  {
    p = A->up;
    A->left = B->right;
    if (A->left != &S) A->left->up = A;

    B->right = A;
    B->up = p;
    A->up = B;

    if (p != &S)
    {
      if (p->left == A) p->left = B; else p->right = B;
    }
    else root = B;
  }
}

// Wstawia do drzewa węzeł o kluczu k
//-----------------------------------
void TRBTree::insertRBT(int k)
{
  RBTNode* X,* Y;

  X = new RBTNode;        // Tworzymy nowy węzeł
  X->left  = &S;          // Inicjujemy pola
  X->right = &S;
  X->up    = root;
  X->key   = k;
  if (X->up == &S) root = X; // X staje się korzeniem
  else
  while(true)           // Szukamy liścia do zastąpienia przez X
  {
    if (k < X->up->key)
    {
      if (X->up->left == &S)
      {
        X->up->left = X;  // X zastępuje lewy liść
        break;
      }
      X->up = X->up->left;
    }
    else
    {
      if (X->up->right == &S)
      {
        X->up->right = X; // X zastępuje prawy liść
        break;
      }
      X->up = X->up->right;
    }
  }
  X->color = 'R';         // Węzeł kolorujemy na czerwono
  while((X != root) &&(X->up->color == 'R'))
  {
    if (X->up == X->up->up->left)
    {
      Y = X->up->up->right; // Y -> wujek X

      if (Y->color == 'R') // Przypadek 1
      {
        X->up->color = 'B';
        Y->color = 'B';
        X->up->up->color = 'R';
        X = X->up->up;
        continue;
      }

      if (X == X->up->right) // Przypadek 2
      {
        X = X->up;
        rot_L(X);
      }

      X->up->color = 'B'; // Przypadek 3
      X->up->up->color = 'R';
      rot_R(X->up->up);
      break;
    }
    else
    {                  // Przypadki lustrzane
      Y = X->up->up->left;

      if (Y->color == 'R') // Przypadek 1
      {
        X->up->color = 'B';
        Y->color = 'B';
        X->up->up->color = 'R';
        X = X->up->up;
        continue;
      }

      if (X == X->up->left) // Przypadek 2
      {
        X = X->up;
        rot_R(X);
      }

      X->up->color = 'B'; // Przypadek 3
      X->up->up->color = 'R';
      rot_L(X->up->up);
      break;
    }
  }
  root->color = 'B';
}

// Usuwa z drzewa węzeł X
//-----------------------
void TRBTree::removeRBT(RBTNode* X)
{
  RBTNode* W,* Y,* Z;

  if ((X->left == &S) ||(X->right == &S)) Y = X;
  else Y = succRBT(X);

  if (Y->left != &S) Z = Y->left;
  else Z = Y->right;

  Z->up = Y->up;

  if (Y->up == &S) root = Z;
  else if (Y == Y->up->left) Y->up->left  = Z;
  else Y->up->right = Z;

  if (Y != X) X->key = Y->key;

  if (Y->color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
    while((Z != root) &&(Z->color == 'B'))
      if (Z == Z->up->left)
      {
        W = Z->up->right;

        if (W->color == 'R')
        {              // Przypadek 1
          W->color = 'B';
          Z->up->color = 'R';
          rot_L(Z->up);
          W = Z->up->right;
        }

        if ((W->left->color == 'B') &&(W->right->color == 'B'))
        {              // Przypadek 2
          W->color = 'R';
          Z = Z->up;
          continue;
        }

        if (W->right->color == 'B')
        {              // Przypadek 3
          W->left->color = 'B';
          W->color = 'R';
          rot_R(W);
          W = Z->up->right;
        }

        W->color = Z->up->color; // Przypadek 4
        Z->up->color = 'B';
        W->right->color = 'B';
        rot_L(Z->up);
        Z = root;      // To spowoduje zakończenie pętli
      }
      else
      {                // Przypadki lustrzane
        W = Z->up->left;

        if (W->color == 'R')
        {              // Przypadek 1
          W->color = 'B';
          Z->up->color = 'R';
          rot_R(Z->up);
          W = Z->up->left;
        }

        if ((W->left->color == 'B') &&(W->right->color == 'B'))
        {              // Przypadek 2
          W->color = 'R';
          Z = Z->up;
          continue;
        }

        if (W->left->color == 'B')
        {              // Przypadek 3
          W->right->color = 'B';
          W->color = 'R';
          rot_L(W);
          W = Z->up->left;
        }

        W->color = Z->up->color;  // Przypadek 4
        Z->up->color = 'B';
        W->left->color = 'B';
        rot_R(Z->up);
        Z = root;      // To spowoduje zakończenie pętli
      }

  Z->color = 'B';

  delete Y;
}

//**********************
//*** PROGRAM GŁÓWNY***
//**********************

int main()
{
  int Tk[MAXN];       // Tablica kluczy węzłów
  int i, x, i1, i2;
  TRBTree* RBT;         // Obiekt drzewa czerwono-czarnego

  srand(time(NULL)); // Inicjujemy generator pseudolosowy

  RBT = new TRBTree;     // Tworzymy puste drzewo

  for(i = 0; i < MAXN; i++) // Tablicę wypełniamy wartościami kluczy
    Tk[i] = i + 1;

  for(i = 0; i < 300; i++)  // Mieszamy tablicę
  {
    i1 = rand() % MAXN; // Losujemy 2 indeksy
    i2 = rand() % MAXN;

    x = Tk[i1];       // Wymieniamy Tk[i1] <-->. Tk[i2] 
    Tk[i1] = Tk[i2];
    Tk[i2] = x;
  }

  for(i = 0; i < MAXN; i++) // Na podstawie tablicy tworzymy drzewo czerwono-czarne
  {
    cout << Tk[i] << " ";
    RBT->insertRBT(Tk[i]);
  }

  cout << endl << endl;

  RBT->print();         // Wyświetlamy zawartość drzewa

  cout << endl << endl;

  for(i = 0; i < 300; i++) // Ponownie mieszamy tablicę
  {
    i1 = rand() % MAXN; i2 = rand() % MAXN;
    x = Tk[i1]; Tk[i1] = Tk[i2]; Tk[i2] = x;
  }

  for(i = 0; i < MAXN >> 1; i++) // Usuwamy połowę węzłów
  {
    cout << Tk[i] << " ";
    RBT->removeRBT(RBT->findRBT(Tk[i]));
  }

  cout << endl << endl;

  RBT->print();         // Wyświetlamy zawartość drzewa

  delete RBT;            // Usuwamy drzewo z pamięci

  return 0;
}