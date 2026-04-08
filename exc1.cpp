#include <iostream>
#include <string>

class Canal {
public:
    virtual ~Canal() = default;
    virtual void enviar(const std::string& mensagem) = 0;
};

class EmailCanal: public Canal {
    void enviar(const std::string& mensagem) override {
        std::cout << "Email: " << "\n";
    }
};

class SMSCanal: public Canal {
    void enviar(const std::string& mensagem) override {
        std::cout << "SMS: " << "\n";
    }
};

class PushCanal: public Canal {
    void enviar(const std::string& mensagem) override {
        std::cout << "Push Notification: " << "\n";
    }
};

class CanalFactory { 
public:
    static std::unique_ptr<Canal> create(const std::string& tipo) {
        if(tipo == "email") return std::make_unique<EmailCanal> ();
        if(tipo == "sms") return std::make_unique<SMSCanal> ();
        if(tipo == "push") return std::make_unique<PushCanal> ();
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

    Global(): 
        nomeAplicacao("NotificaApp"), tentativasEnvio(3) {}
    Global() = default;
    ~Global() = default;
    Global(const Global&) = delete;
    Global& operator=(const Global&) = delete;

public:
    static Global& instance() {
        static Global instance;
        return instance;
    }

    std::string getNomeAplicacao() const {return nomeAplicacao;}
    int getNumeroTentativas() const {return tentativasEnvio;}
    const Servidor& getServidor() const {return servidorEnvio;}


    void println(std::string mensagem) const { std::cout << mensagem; }
};

