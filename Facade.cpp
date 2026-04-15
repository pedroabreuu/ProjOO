#include <iostream>
#include <string>

class TV {
public:
    void ligar() {
        std::cout << "TV ligada.\n";
    }

    void desligar() {
        std::cout << "TV desligada.\n";
    }

    void ajustarCanal(const std::string& canal) {
        std::cout << "TV ajustada para o canal: " << canal << "\n";
    }
};

class Projetor {
public:
    void ligar() {
        std::cout << "Projetor ligado.\n";
    }

    void desligar() {
        std::cout << "Projetor desligado.\n";
    }
};

class Receiver {
public:
    void ligar() {
        std::cout << "Receiver ligado.\n";
    }

    void desligar() {
        std::cout << "Receiver desligado.\n";
    }

    void configurarEntrada(const std::string& entrada) {
        std::cout << "Entrada configurada para: " << entrada << "\n";
    }
};

class PlayerMidia {
public:
    void ligar() {
        std::cout << "Player de mídia ligado.\n";
    }

    void desligar() {
        std::cout << "Player de mídia desligado.\n";
    }

    void reproduzirFilme() {
        std::cout << "Filme reproduzindo.\n";
    }

    void reproduzirMusica() {
        std::cout << "Música tocando.\n";
    }

    void parar() {
        std::cout << "Mídia pausada.\n";
    }
};

class SistemaSom {
public:
    void ligar() {
        std::cout << "Sistema de som ligado.\n";
    }

    void desligar() {
        std::cout << "Sistema de som desligado.\n";
    }

    void ajustarVolume(int volume) {
        std::cout << "Volume ajustado para: " << volume << "\n";
    }
};

class Luz {
public:
    void ligar() {
        std::cout << "Luz ligada.\n";
    }

    void desligar() {
        std::cout << "Luz desligada.\n";
    }

    void diminuir() {
        std::cout << "Luz diminuída.\n";
    }

    void aumentar() {
        std::cout << "Luz aumentada.\n";
    }
};

class HomeTheaterFacade {
private:
    TV tv;
    Luz luz;
    Projetor projetor;
    SistemaSom som;
    PlayerMidia player;
    Receiver receiver;

public:
    void assistirFilme() {
        luz.diminuir();
        projetor.ligar();
        receiver.ligar();
        receiver.configurarEntrada("Player de mídia");
        som.ligar();
        som.ajustarVolume(60);
        player.ligar();
        player.reproduzirFilme();
        std::cout << "Sistema pronto para assistir ao filme.\n";
    }

    void ouvirMusica() {
        luz.diminuir();
        receiver.ligar();
        receiver.configurarEntrada("Modo música");
        som.ligar();
        som.ajustarVolume(40);
        player.ligar();
        player.reproduzirMusica();
        std::cout << "Sistema pronto para ouvir música.\n";
    }

    void desligarTudo() {
        player.parar();
        player.desligar();
        som.desligar();
        receiver.desligar();
        projetor.desligar();
        tv.desligar();
        luz.aumentar();
        std::cout << "Home Theater desligado.\n";
    }
};

int main() {
    HomeTheaterFacade homeTheater;

    std::cout << "Assistir Filme\n";
    homeTheater.assistirFilme();

    std::cout << "\nDesligar Tudo\n";
    homeTheater.desligarTudo();

    std::cout << "\nOuvir Musica\n";
    homeTheater.ouvirMusica();

    std::cout << "\nDesligar Tudo\n";
    homeTheater.desligarTudo();

    return 0;
}