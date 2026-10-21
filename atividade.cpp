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