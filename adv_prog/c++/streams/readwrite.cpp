#include <iostream>
#include <fstream>
#include <string>


int main() {

    /* ofstream = output file stream, ifstream = input file stream
    (sono a tutti gli effetti variabili); se il file non esiste viene
    creato automaticamente con ofstream */
    std::ofstream fo("file.txt");
    fo << "hello world, fool!" << std::endl;
    fo.close();

    /* il separatore tra le singole variabili all'interno del file
    dipende dal formato del file; ad es. per .txt sono separatori
    spazi e newline */
    std::string stuff1, stuff2;
    std::ifstream fi("file.txt");
    fi >> stuff1 >> stuff2;
    fi.close();
    std::cout << stuff1 << " " << stuff2 << std::endl;

    /* l'opzione std::ios_base::app permette di aggiungere l'input
    al file senza sovrascrivere ciò che il file già contiene */
    fo.open("file.txt", std::ios_base::app);
    fo << "aggiunta" << std::endl;
    fo.close();

    return 0;
}
