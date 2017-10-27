#include <cstdio>
using namespace std;

struct Node {
  long my_pos;
  int valores[19] = {0};
  long filhos[20];
  bool folha() { return filhos[0] == -1; }
  Node() {
    for(int i = 0; i < 20; ++i) filhos[i] = -1;
  }
};

void write_node(Node * n, FILE * f) {
  fseek(f, n->my_pos, SEEK_SET);
  fwrite(n, sizeof(Node), 1, f);
}

int main() {
  Node n1, n2;
  n1.valores[0] = 5;

  FILE * f = fopen("teste.xxx", "wb");

  n1.my_pos = ftell(f);
  write_node(&n1, f);

  n2.my_pos = ftell(f);
  write_node(&n2, f);

  n1.filhos[0] = n2.my_pos;

  write_node(&n1, f);

  fclose(f);
}
