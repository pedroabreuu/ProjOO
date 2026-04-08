#include <iostream>
#include <string>
#include <memory>

class Canal {
public:
    virtual ~Canal() = default;
    virtual void enviar(const std::string& mensagem) = 0;
};

class EmailCanal: public Canal {
    void enviar(const std::string& mensagem) override {
        std::cout << "Email: " << mensagem << "\n";
    }
};

class SMSCanal: public Canal {
    void enviar(const std::string& mensagem) override {
        std::cout << "SMS: " << mensagem << "\n";
    }
};

class PushCanal: public Canal {
    void enviar(const std::string& mensagem) override {
        std::cout << "Push Notification: " << mensagem << "\n";
    }
};

class CanalFactory { //factory
public:
    static std::unique_ptr<Canal> create(const std::string& tipo) {
        if(tipo == "email") return std::make_unique<EmailCanal> ();
        if(tipo == "sms") return std::make_unique<SMSCanal> ();
        if(tipo == "push") return std::make_unique<PushCanal> ();
        throw std::invalid_argument("Tipo de canal desconhecido: " + tipo);
    }
};

class Servidor {
private:
    std::string endereco = "unifesp.app.br";

public:
    std::string getEndereco() const {
        return endereco;
    }
};

class Global { //singleton
private:
    int tentativasEnvio;
    std::string nomeAplicacao;
    Servidor servidorEnvio;

    Global(): nomeAplicacao("NotificaApp"), tentativasEnvio(3) {}
    ~Global() = default;

    Global(const Global&) = delete;
    Global& operator=(const Global&) = delete;
    Global(Global&&) = delete;
    Global& operator=(Global&&) = delete;

public:
    static Global& instance() {
        static Global instance;
        return instance;
    }

    std::string getNomeAplicacao() const {return nomeAplicacao;}
    int getNumeroTentativas() const {return tentativasEnvio;}
    const Servidor& getServidor() const {return servidorEnvio;}
};

int main() {
    auto canal = CanalFactory::create("email");
    canal->enviar("Iniciando Canal de Mensagens...");

    auto& g = Global::instance();
    std::cout << "App: " << g.getNomeAplicacao() << "\n";
    std::cout << "Tentativas: " << g.getNumeroTentativas() << "\n";
    std::cout << "Servidor: " << g.getServidor().getEndereco() << "\n";

    return 0;
}