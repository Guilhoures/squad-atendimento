#include <iostream>
#include <string>
using namespace std;

struct No {
    string nome;
    int    urgencia;   
    No*    prox;
    No(const string& n, int u = 0) : nome(n), urgencia(u), prox(nullptr) {}
};



struct FilaPacientes {
    No* frente = nullptr;
    No* tras   = nullptr;

    void enqueue(const string& nome, int urgencia) {
        No* novo = new No(nome, urgencia);
        if (isEmpty()) {
            frente = novo;
            tras = novo;
        } else {
            tras->prox = novo;
            tras = novo;
        }
    }

 
    string dequeue() {
        if (isEmpty()) return "";
        
        No* temp = frente;
        string nome = temp->nome;
        frente = frente->prox;
        
        if (frente == nullptr) {
            tras = nullptr;
        }
        
        delete temp;
        return nome;
    }

  
    string frente_peek() const {
        if (isEmpty()) return "";
        return frente->nome;
    }

    bool isEmpty() const { return frente == nullptr; }

    
    int tamanho() const {
        int count = 0;
        No* atual = frente;
        while (atual != nullptr) {
            count++;
            atual = atual->prox;
        }
        return count;
    }

    ~FilaPacientes() {
        while (!isEmpty()) dequeue();
    }
};

struct PilhaHistorico {
    No* topo = nullptr;

    
    void push(const string& nome) {
        No* novo = new No(nome);
        novo->prox = topo;
        topo = novo;
    }

    
    string pop() {
        if (isEmpty()) return "";
        
        No* temp = topo;
        string nome = temp->nome;
        topo = topo->prox;
        
        delete temp;
        return nome;
    }

    
    string peek() const {
        if (isEmpty()) return "";
        return topo->nome;
    }

    bool isEmpty() const { return topo == nullptr; }

    ~PilhaHistorico() {
        while (!isEmpty()) pop();
    }
};

struct ListaMedicos {
    No* head = nullptr;

   
    void adicionarMedico(const string& nome) {
        No* novo = new No(nome);
        if (head == nullptr) {
            head = novo;
        } else {
            No* atual = head;
            while (atual->prox != nullptr) {
                atual = atual->prox;
            }
            atual->prox = novo;
        }
    }

    
    string chamarMedico() {
        if (head == nullptr) return "";
        
        No* temp = head;
        string nome = temp->nome;
        head = head->prox;
        
        delete temp;
        return nome;
    }

   
    void percorrer(const string& prefixo = "") const {
        if (!prefixo.empty()) cout << prefixo << ": ";
        
        if (head == nullptr) {
            cout << "(lista vazia)\n";
            return;
        }
        
        No* atual = head;
        while (atual != nullptr) {
            cout << atual->nome;
            if (atual->prox != nullptr) cout << " -> ";
            atual = atual->prox;
        }
        cout << "\n";
    }

    bool temMedico() const { return head != nullptr; }

    ~ListaMedicos() {
        while (head) {
            No* t = head;
            head  = head->prox;
            delete t;
        }
    }
};